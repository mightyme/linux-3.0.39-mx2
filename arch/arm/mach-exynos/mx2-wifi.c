/* linux/arch/arm/mach-exynos/mach-m03x.c
 *
 * Copyright (C) 2012 Meizu Technology Co.Ltd, Zhuhai, China
 *		http://www.meizu.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
*/

#include <linux/platform_device.h>
#include <linux/skbuff.h>
#include <linux/wlan_plat.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/sysfs.h>

#include <asm/mach-types.h>

#include <plat/devs.h>
#include <plat/irqs.h>
#include <plat/sdhci.h>
#include <plat/gpio-cfg.h>

#ifdef CONFIG_BCMDHD
static int wl_host_wake;
static int bt_rst;
static int wl_power;
static int bt_power;
static int wl_cs;
static DEFINE_MUTEX(wifi_mutex);


#define PREALLOC_WLAN_SEC_NUM		4
#define WLAN_STATIC_SCAN_BUF0		5
#define WLAN_STATIC_SCAN_BUF1		6
#define PREALLOC_WLAN_BUF_NUM		160
#define PREALLOC_WLAN_SECTION_HEADER	24

#define WLAN_SECTION_SIZE_0	(PREALLOC_WLAN_BUF_NUM * 128)
#define WLAN_SECTION_SIZE_1	(PREALLOC_WLAN_BUF_NUM * 128)
#define WLAN_SECTION_SIZE_2	(PREALLOC_WLAN_BUF_NUM * 512)
#define WLAN_SECTION_SIZE_3	(PREALLOC_WLAN_BUF_NUM * 1024)

#define DHD_SKB_HDRSIZE			336
#define DHD_SKB_1PAGE_BUFSIZE	((PAGE_SIZE*1)-DHD_SKB_HDRSIZE)
#define DHD_SKB_2PAGE_BUFSIZE	((PAGE_SIZE*2)-DHD_SKB_HDRSIZE)
#define DHD_SKB_4PAGE_BUFSIZE	((PAGE_SIZE*4)-DHD_SKB_HDRSIZE)

#define WLAN_SKB_BUF_NUM	17
 
static struct sk_buff *wlan_static_skb[WLAN_SKB_BUF_NUM];

struct wlan_mem_prealloc {
	void *mem_ptr;
	unsigned long size;
};

static struct wlan_mem_prealloc wlan_mem_array[PREALLOC_WLAN_SEC_NUM] = {
	{NULL, (WLAN_SECTION_SIZE_0 + PREALLOC_WLAN_SECTION_HEADER)},
	{NULL, (WLAN_SECTION_SIZE_1 + PREALLOC_WLAN_SECTION_HEADER)},
	{NULL, (WLAN_SECTION_SIZE_2 + PREALLOC_WLAN_SECTION_HEADER)},
	{NULL, (WLAN_SECTION_SIZE_3 + PREALLOC_WLAN_SECTION_HEADER)}
};

void *wlan_static_scan_buf0;
void *wlan_static_scan_buf1;

static void *brcm_wlan_mem_prealloc(int section, unsigned long size)
{
	if (section == PREALLOC_WLAN_SEC_NUM)
		return wlan_static_skb;
	if (section == WLAN_STATIC_SCAN_BUF0)
		return wlan_static_scan_buf0;
	if (section == WLAN_STATIC_SCAN_BUF1)
		return wlan_static_scan_buf1;
	if ((section < 0) || (section > PREALLOC_WLAN_SEC_NUM))
		return NULL;
	if (wlan_mem_array[section].size < size)
		return NULL;
	return wlan_mem_array[section].mem_ptr;
}

static int __init brcm_init_wifi_mem(void)
{
	int i;
	int j;

	for (i = 0; i < 8; i++) {
		wlan_static_skb[i] = dev_alloc_skb(DHD_SKB_1PAGE_BUFSIZE);
		if (!wlan_static_skb[i])
			goto err_skb_alloc;
	}

	for (; i < 16; i++) {
		wlan_static_skb[i] = dev_alloc_skb(DHD_SKB_2PAGE_BUFSIZE);
		if (!wlan_static_skb[i])
			goto err_skb_alloc;
	}

	wlan_static_skb[i] = dev_alloc_skb(DHD_SKB_4PAGE_BUFSIZE);
	if (!wlan_static_skb[i])
		goto err_skb_alloc;

	for (i = 0 ; i < PREALLOC_WLAN_SEC_NUM ; i++) {
		wlan_mem_array[i].mem_ptr =
				kmalloc(wlan_mem_array[i].size, GFP_KERNEL);

		if (!wlan_mem_array[i].mem_ptr)
			goto err_mem_alloc;
	}
	wlan_static_scan_buf0 = kmalloc(65536, GFP_KERNEL);
	if (!wlan_static_scan_buf0)
		goto err_mem_alloc;
	wlan_static_scan_buf1 = kmalloc(65536, GFP_KERNEL);
	if (!wlan_static_scan_buf1)
		goto err_mem_alloc;
	printk(KERN_INFO"%s: WIFI MEM Allocated\n", __func__);
	return 0;

 err_mem_alloc:
	pr_err("Failed to mem_alloc for WLAN\n");
	for (j = 0 ; j < i ; j++)
		kfree(wlan_mem_array[j].mem_ptr);

	i = WLAN_SKB_BUF_NUM;

 err_skb_alloc:
	pr_err("Failed to skb_alloc for WLAN\n");
	for (j = 0 ; j < i ; j++)
		dev_kfree_skb(wlan_static_skb[j]);

	return -ENOMEM;
}

extern int dhd_card_insert(void);
extern void dhd_card_remove(void);
extern void need_test_firmware(void);
extern void reset_firmware_type(void);

void wifi_card_set_power(int onoff)
{
	pr_info("## %s: %s power\n", __func__, onoff?"enable":"disable");
	if(onoff) {
		//wlan host wakeup:   int 20, pull down 
		s3c_gpio_cfgpin(wl_host_wake, S3C_GPIO_SPECIAL(15));  
		s3c_gpio_setpull(wl_host_wake, S3C_GPIO_PULL_DOWN);  

		//wlan power:output ,1
		s3c_gpio_cfgpin(wl_power, S3C_GPIO_OUTPUT);
		gpio_set_value(wl_power, 1);		

		//bt power
		s3c_gpio_cfgpin(bt_power, S3C_GPIO_OUTPUT);
		gpio_set_value(bt_power, 1);

	} else {
		gpio_set_value(wl_power, 0);

		if (!gpio_get_value(bt_rst) ) {
			gpio_set_value(bt_power, 0);
		}
	}
}

static int wlan_power_en(int onoff)
{
	if (gpio_get_value(wl_cs)) {
		WARN(1, "WL_WIFICS is HI\n");
	} else {
		//msleep(2 * 1000);
		/* must be mmc card detected pin low */
		if (onoff) {
			wifi_card_set_power(1);
			msleep(200);
		} else {
			wifi_card_set_power(0);
		}
	}
	return 0;
}

static int wlan_reset_en(int onoff)
{
	pr_info("### %s %d\n", __func__, onoff);
	gpio_set_value(wl_power, onoff ? 1 : 0);
	return 0;
}

static int wlan_carddetect_en(int onoff)
{
	pr_info("### %s %d\n", __func__, onoff);
	if(onoff) {
		exynos4_setup_sdhci3_cfg_gpio(NULL, 4);
	} else {
		exynos4_setup_sdhci3_cfg_gpio(NULL, 0);
	}
	msleep(10);

	gpio_set_value(wl_cs, !onoff);	

	msleep(400);
	return 0;
}

/* Customized Locale table : OPTIONAL feature */
#define WLC_CNTRY_BUF_SZ        4
struct cntry_locales_custom {
	char iso_abbrev[WLC_CNTRY_BUF_SZ];
	char custom_locale[WLC_CNTRY_BUF_SZ];
	int  custom_locale_rev;
};

static struct cntry_locales_custom brcm_wlan_translate_custom_table[] = {
	/* Table should be filled out based
 on custom platform regulatory requirement */
	{"",   "XY", 4},  /* universal */
	{"US", "US", 69}, /* input ISO "US" to : US regrev 69 */
	{"CA", "US", 69}, /* input ISO "CA" to : US regrev 69 */
	{"EU", "EU", 5},  /* European union countries */
	{"AT", "EU", 5},
	{"BE", "EU", 5},
	{"BG", "EU", 5},
	{"CY", "EU", 5},
	{"CZ", "EU", 5},
	{"DK", "EU", 5},
	{"EE", "EU", 5},
	{"FI", "EU", 5},
	{"FR", "EU", 5},
	{"DE", "EU", 5},
	{"GR", "EU", 5},
	{"HU", "EU", 5},
	{"IE", "EU", 5},
	{"IT", "EU", 5},
	{"LV", "EU", 5},
	{"LI", "EU", 5},
	{"LT", "EU", 5},
	{"LU", "EU", 5},
	{"MT", "EU", 5},
	{"NL", "EU", 5},
	{"PL", "EU", 5},
	{"PT", "EU", 5},
	{"RO", "EU", 5},
	{"SK", "EU", 5},
	{"SI", "EU", 5},
	{"ES", "EU", 5},
	{"SE", "EU", 5},
	{"GB", "EU", 5},  /* input ISO "GB" to : EU regrev 05 */
	{"IL", "IL", 0},
	{"CH", "CH", 0},
	{"TR", "TR", 0},
	{"NO", "NO", 0},
	{"KR", "XY", 3},
	{"AU", "XY", 3},
	{"CN", "XY", 3},  /* input ISO "CN" to : XY regrev 03 */
	{"TW", "XY", 3},
	{"AR", "XY", 3},
	{"MX", "XY", 3}
};

static void *brcm_wlan_get_country_code(char *ccode)
{
	int size = ARRAY_SIZE(brcm_wlan_translate_custom_table);
	int i;

	if (!ccode)
		return NULL;

	for (i = 0; i < size; i++)
		if (strcmp(ccode,
		brcm_wlan_translate_custom_table[i].iso_abbrev) == 0)
			return &brcm_wlan_translate_custom_table[i];
	return &brcm_wlan_translate_custom_table[0];
}


static struct wifi_platform_data wifi_pdata = {
	.set_power = wlan_power_en,
	.set_reset = wlan_reset_en,
	.set_carddetect = wlan_carddetect_en,
	.mem_prealloc = brcm_wlan_mem_prealloc,
	.get_country_code = brcm_wlan_get_country_code,
};


static struct resource mx2_wifi_resources[] = {
	[0] = {
		.name	= "bcmdhd_wlan_irq",
		.start	= IRQ_EINT(12),
		.end	= IRQ_EINT(12),
		.flags	= IORESOURCE_IRQ | IORESOURCE_IRQ_HIGHLEVEL | IORESOURCE_IRQ_SHAREABLE,
	},
};

static struct platform_device mx2_wifi = {
	.name		= "bcmdhd_wlan",
	.id		= -1,
	.num_resources	= ARRAY_SIZE(mx2_wifi_resources),
	.resource	= mx2_wifi_resources,
	.dev		= {
		.platform_data = &wifi_pdata,
	},
};



#ifdef CONFIG_S3C_DEV_HSMMC3
static void sdhci_wifi_set_power(unsigned int power_mode)
{
	if (!gpio_get_value(wl_cs) && power_mode == 1) {
		wifi_card_set_power(1);
	} else {
		wifi_card_set_power(0);
	}
}

static struct s3c_sdhci_platdata __initdata mx2_hsmmc3_pdata  = {
	.cd_type		= S3C_SDHCI_CD_INTERNAL,
	.clk_type		= S3C_SDHCI_CLK_DIV_EXTERNAL,
	.set_power	= sdhci_wifi_set_power,
};
#endif

static int __init mx2_wifi_init(void)
{
	int ret;


	wl_host_wake= EXYNOS4_GPX1(4);
	bt_rst		= EXYNOS4_GPF0(3);
	wl_power 	= EXYNOS4_GPF1(2);
	bt_power 	= EXYNOS4_GPF3(5);
	wl_cs		= EXYNOS4_GPY0(2);

#ifdef CONFIG_S3C_DEV_HSMMC3
	ret  = platform_device_register(&s3c_device_hsmmc3);
	if (ret)
		return ret;
	s3c_sdhci3_set_platdata(&mx2_hsmmc3_pdata);
#endif

	ret = platform_device_register(&mx2_wifi);
	if (ret)
		goto err1;

	ret = brcm_init_wifi_mem();
	if (ret)
		goto err2;

	return 0;

err2:
	platform_device_unregister(&mx2_wifi);
err1:
#ifdef CONFIG_S3C_DEV_HSMMC3
	platform_device_unregister(&s3c_device_hsmmc3);
#endif	
	return ret;
}

device_initcall(mx2_wifi_init);
#endif