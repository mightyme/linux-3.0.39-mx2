/* linux/drivers/video/samsung/s3cfb_ls044k3sx01.h
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 
 *
 */
 
#ifndef S3CFB_LS044K3SX01_H
#define S3CFB_LS044k3SX01_H

#include <video/mipi_display.h>
/*The default value is 200us when esc_clk is 20MHZ, 
  *The value double if esc_clk is 10MHZ
  */
#define BTA_NONE 0
#define BTA_TIMEOUT 500
#define BTA_TIMEOUT_LONG 50000	/* 50ms */

#define lcd_to_master(a)		(a->dsim_dev->master)
#define lcd_to_master_ops(a)	((lcd_to_master(a))->master_ops)

#define write_cmd(lcd, cmd0, cmd1, bta) \
	lcd_to_master_ops(lcd)->cmd_write(lcd_to_master(lcd), \
					MIPI_DSI_DCS_SHORT_WRITE_PARAM, \
					cmd0, cmd1, bta)

#define write_gen_data(lcd, array, size, bta)	\
	lcd_to_master_ops(lcd)->cmd_write(lcd_to_master(lcd),\
					MIPI_DSI_GENERIC_LONG_WRITE, \
					(unsigned int)array, size, bta)

#define write_data(lcd, array, size, bta)	\
	lcd_to_master_ops(lcd)->cmd_write(lcd_to_master(lcd),\
					MIPI_DSI_DCS_LONG_WRITE, \
					(unsigned int)array, size, bta)

#define set_packet_size(lcd, cmd0) \
	lcd_to_master_ops(lcd)->cmd_write(lcd_to_master(lcd), \
					0x37, cmd0, 0, 500)

#define read_data(lcd, cmd) \
	lcd_to_master_ops(lcd)->cmd_read(lcd_to_master(lcd), \
			MIPI_DSI_DCS_READ, cmd, 0)

#define PP_NARG(...) \
    PP_NARG_(__VA_ARGS__,PP_RSEQ_N())
#define PP_NARG_(...) \
    PP_ARG_N(__VA_ARGS__)
#define PP_ARG_N( \
     _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
    _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
    _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
    _31,_32,  N, ...) N
#define PP_RSEQ_N() \
    32,31,30, \
    29,28,27,26,25,24,23,22,21,20, \
    19,18,17,16,15,14,13,12,11,10, \
     9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define LCD_PARAM_DCS_CMD(mdelay, ...) {\
	.param = {__VA_ARGS__},\
	.delay = mdelay,}

#define LCD_PARAM_DEF( ...) {\
	.param = {__VA_ARGS__},\
	.size = PP_NARG(__VA_ARGS__),}

#define LCD_PARAM_DEF_END {.size = -1,}

#define LCD_TEST

struct ls044k3sx01_param {
	char param[24];
	int size;
	int delay;	/* delay time ms */
};

enum lcd_state {
	LCD_DISPLAY_SLEEP_IN,
	LCD_DISPLAY_DEEP_STAND_BY,
	LCD_DISPLAY_POWER_OFF,
};

struct ls044k3sx01_info {
	struct device			*dev;
	struct lcd_device		*ld;

	struct mipi_dsim_lcd_device *dsim_dev;
	struct lcd_platform_data	*ddi_pd;
	enum lcd_state state;
	int ce_mode;
	int id_code;
	int cabc_en;
};

static const struct ls044k3sx01_param ls044k3sx01_slpout_seq[] = {
	LCD_PARAM_DCS_CMD(10, MIPI_DCS_EXIT_SLEEP_MODE, 0x0),
	LCD_PARAM_DEF_END,
};
static const struct ls044k3sx01_param ls044k3sx01_slpin_seq[] = {
	LCD_PARAM_DCS_CMD(120, MIPI_DCS_ENTER_SLEEP_MODE, 0x0),
	LCD_PARAM_DEF_END,
};
static const struct ls044k3sx01_param ls044k3sx01_dspon_seq[] = {
	LCD_PARAM_DCS_CMD(10, MIPI_DCS_SET_DISPLAY_ON, 0x0),
	LCD_PARAM_DCS_CMD(0, MIPI_DCS_BACKLIGHT_ON, 0x4),
	LCD_PARAM_DEF_END,
};
static const struct ls044k3sx01_param ls044k3sx01_dspoff_seq[] = {
	LCD_PARAM_DCS_CMD(0, MIPI_DCS_BACKLIGHT_ON, 0x0),
	LCD_PARAM_DCS_CMD(120, MIPI_DCS_SET_DISPLAY_OFF, 0x0),
	LCD_PARAM_DEF_END,
};
static const struct ls044k3sx01_param ls044k3sx01_cabc_seq[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DEF(0xB5,0x01,0xff,0x02,0x00,0x00,0x08,0x1c,0x00),
	LCD_PARAM_DCS_CMD(0, 0x5E, 0x3C),
	LCD_PARAM_DCS_CMD(0, 0x51, 0xFF),
	LCD_PARAM_DCS_CMD(0, MIPI_DCS_BACKLIGHT_ON, 0x2C),
	LCD_PARAM_DCS_CMD(0, 0x55, 0x02),
	LCD_PARAM_DEF_END,
};
static const struct ls044k3sx01_param ls044k3sx01_cabc_seq_off[] = {
	LCD_PARAM_DCS_CMD(0, MIPI_DCS_BACKLIGHT_ON, 0x04),
	LCD_PARAM_DEF_END,
};
static const struct ls044k3sx01_param ls044k3sx01_cabc_gradient[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08,0x10),
	LCD_PARAM_DEF(0xF7,0x24,0x00,0x3D,0x00),
	LCD_PARAM_DEF_END,
};
#define sat_lit_low  0x0F,0x0F,0x0F,0x0F,0x0F,0x0F
#define sat_lit_med  0x1F,0x1F,0x1F,0x1F,0x1F,0x1F
#define sat_lit_high 0x3F,0x3F,0x3F,0x3F,0x3F,0x3F
#define sat_lit_none 0x00,0x00,0x00,0x00,0x00,0x00

static const struct ls044k3sx01_param ls044k3sx01_sat_low_lit_low[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DCS_CMD(0, 0xB0, 0x01),
	LCD_PARAM_DEF(0x8A,sat_lit_low,sat_lit_low,0x00,0x06),
	LCD_PARAM_DEF(0x8B,0x01,0x21,0x43,0x65,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00),
	LCD_PARAM_DCS_CMD(0, 0x88, 0x01),
	LCD_PARAM_DEF_END,
};

static const struct ls044k3sx01_param ls044k3sx01_sat_low_lit_med[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DCS_CMD(0, 0xB0, 0x01),
	LCD_PARAM_DEF(0x8A,sat_lit_low,sat_lit_med,0x00,0x06),
	LCD_PARAM_DEF(0x8B,0x01,0x21,0x43,0x65,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00),
	LCD_PARAM_DCS_CMD(0, 0x88, 0x01),
	LCD_PARAM_DEF_END,
};

static const struct ls044k3sx01_param ls044k3sx01_sat_low_lit_high[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DCS_CMD(0, 0xB0, 0x01),
	LCD_PARAM_DEF(0x8A,sat_lit_low,sat_lit_high,0x00,0x06),
	LCD_PARAM_DEF(0x8B,0x01,0x21,0x43,0x65,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00),
	LCD_PARAM_DCS_CMD(0, 0x88, 0x01),
	LCD_PARAM_DEF_END,
};
static const struct ls044k3sx01_param ls044k3sx01_sat_med_lit_low[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DCS_CMD(0, 0xB0, 0x01),
	LCD_PARAM_DEF(0x8A,sat_lit_med,sat_lit_low,0x00,0x06),
	LCD_PARAM_DEF(0x8B,0x01,0x21,0x43,0x65,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00),
	LCD_PARAM_DCS_CMD(0, 0x88, 0x01),
	LCD_PARAM_DEF_END,
};

static const struct ls044k3sx01_param ls044k3sx01_sat_med_lit_med[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DCS_CMD(0, 0xB0, 0x01),
	LCD_PARAM_DEF(0x8A,sat_lit_med,sat_lit_med,0x00,0x06),
	LCD_PARAM_DEF(0x8B,0x01,0x21,0x43,0x65,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00),
	LCD_PARAM_DCS_CMD(0, 0x88, 0x01),
	LCD_PARAM_DEF_END,
};

static const struct ls044k3sx01_param ls044k3sx01_sat_med_lit_high[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DCS_CMD(0, 0xB0, 0x01),
	LCD_PARAM_DEF(0x8A,sat_lit_med,sat_lit_high,0x00,0x06),
	LCD_PARAM_DEF(0x8B,0x01,0x21,0x43,0x65,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00),
	LCD_PARAM_DCS_CMD(0, 0x88, 0x01),
	LCD_PARAM_DEF_END,
};
static const struct ls044k3sx01_param ls044k3sx01_sat_high_lit_low[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DCS_CMD(0, 0xB0, 0x01),
	LCD_PARAM_DEF(0x8A,sat_lit_high,sat_lit_low,0x00,0x06),
	LCD_PARAM_DEF(0x8B,0x01,0x21,0x43,0x65,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00),
	LCD_PARAM_DCS_CMD(0, 0x88, 0x01),
	LCD_PARAM_DEF_END,
};

static const struct ls044k3sx01_param ls044k3sx01_sat_high_lit_med[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DCS_CMD(0, 0xB0, 0x01),
	LCD_PARAM_DEF(0x8A,sat_lit_high,sat_lit_med,0x00,0x06),
	LCD_PARAM_DEF(0x8B,0x01,0x21,0x43,0x65,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00),
	LCD_PARAM_DCS_CMD(0, 0x88, 0x01),
	LCD_PARAM_DEF_END,
};

static const struct ls044k3sx01_param ls044k3sx01_sat_high_lit_high[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DCS_CMD(0, 0xB0, 0x01),
	LCD_PARAM_DEF(0x8A,sat_lit_high,sat_lit_high,0x00,0x06),
	LCD_PARAM_DEF(0x8B,0x01,0x21,0x43,0x65,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00),
	LCD_PARAM_DCS_CMD(0, 0x88, 0x01),
	LCD_PARAM_DEF_END,
};

static const struct ls044k3sx01_param ls044k3sx01_sat_low[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DCS_CMD(0, 0xB0, 0x01),
	LCD_PARAM_DEF(0x8A,sat_lit_low,sat_lit_none,0x00,0x06),
	LCD_PARAM_DEF(0x8B,0x01,0x21,0x43,0x65,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00),
	LCD_PARAM_DCS_CMD(0, 0x88, 0x01),
	LCD_PARAM_DEF_END,
};

static const struct ls044k3sx01_param ls044k3sx01_sat_med[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DCS_CMD(0, 0xB0, 0x01),
	LCD_PARAM_DEF(0x8A,sat_lit_med,sat_lit_none,0x00,0x06),
	LCD_PARAM_DEF(0x8B,0x01,0x21,0x43,0x65,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00),
	LCD_PARAM_DCS_CMD(0, 0x88, 0x01),
	LCD_PARAM_DEF_END,
};

static const struct ls044k3sx01_param ls044k3sx01_sat_high[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DCS_CMD(0, 0xB0, 0x01),
	LCD_PARAM_DEF(0x8A,sat_lit_high,sat_lit_none,0x00,0x06),
	LCD_PARAM_DEF(0x8B,0x01,0x21,0x43,0x65,0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00),
	LCD_PARAM_DCS_CMD(0, 0x88, 0x01),
	LCD_PARAM_DEF_END,
};

static const struct ls044k3sx01_param ls044k3sx01_ce_off[] = {
	LCD_PARAM_DCS_CMD(0, 0x88, 0x02),
	LCD_PARAM_DEF_END,
};

static const struct ls044k3sx01_param ls044k3sx01_unlock[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DEF(0xD0,0x66),
	//LCD_PARAM_DCS_CMD(0, 0xD0, 0x66),
	LCD_PARAM_DEF_END,
};

#ifdef LCD_TEST
static const struct ls044k3sx01_param ls044k3sx01_hsync_out_seq[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DEF(0x9B,0x02),
	LCD_PARAM_DEF(0xCD,0x00,0x00,0x55,0x00,0x55,0x00),
	LCD_PARAM_DEF_END,
};
static const struct ls044k3sx01_param ls044k3sx01_vsync_out_seq[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DEF(0x9B,0x04),
	LCD_PARAM_DEF(0xCD,0x00,0x00,0x55,0x00,0x55,0x00),
	LCD_PARAM_DEF_END,
};
#endif
static const struct ls044k3sx01_param ls044k3sx01_init_seq[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DEF(0xB5,0x01,0xff,0x02,0x00,0x00,0x08,0x1c,0x00),
	LCD_PARAM_DEF(0xB8,0x33,0x00,0x27,0x00,0x00,0x06,0xB5,0x0A),
	LCD_PARAM_DEF(0xC0,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF),
	LCD_PARAM_DEF(0xC1,0x1E,0x3D,0x5D,0x8C,0xC8,0xCF,0x9C,0xD1,0x8C,0xB3,0x6F,0x9E,0xB3,0xC6,0xDF,0xFB),
	LCD_PARAM_DEF(0xC2,0x1E,0x3D,0x5D,0x8C,0xC8,0xCF,0x9C,0xD1,0x8C,0xB3,0x6F,0x9E,0xB3,0xC6,0xDF,0xFB),
	LCD_PARAM_DEF(0xC3,0x1E,0x3D,0x5D,0x8C,0xC8,0xCF,0x9C,0xD1,0x8C,0xB3,0x6F,0x9E,0xB3,0xC6,0xDF,0xFB),
	LCD_PARAM_DEF(0xC4,0x1E,0x3D,0x5B,0x86,0xBA,0xBB,0x77,0xAE,0x72,0xA1,0x6B,0x9A,0xB1,0xC4,0xDE,0xFB),
	LCD_PARAM_DEF(0xC5,0x1E,0x3D,0x5B,0x86,0xBA,0xBB,0x77,0xAE,0x72,0xA1,0x6B,0x9A,0xB1,0xC4,0xDE,0xFB),
	LCD_PARAM_DEF(0xC6,0x1E,0x3D,0x5B,0x86,0xBA,0xBB,0x77,0xAE,0x72,0xA1,0x6B,0x9A,0xB1,0xC4,0xDE,0xFB),
	LCD_PARAM_DEF(0xC8,0x11,0x19,0x06,0x0E,0x13,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00),
	LCD_PARAM_DEF_END,
};

static const struct ls044k3sx01_param ls044k3sx01_init_seq_0_4[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DEF(0xB8,0x2D,0x00,0x2D,0x00,0x00,0x06,0xB5),
	LCD_PARAM_DEF(0xC0,0x00,0xFF,0x00,0xFF,0x36,0xFF,0x00,0xFF,0x00,0xFF,0x36,0xFF),
	LCD_PARAM_DEF(0xC1,0x1E,0x3D,0x5C,0x89,0xC1,0xC5,0x8A,0xC0,0x7F,0xAA,0x6D,0x9C,0xB2,0xC5,0xDF,0xFB),
	LCD_PARAM_DEF(0xC2,0x1E,0x3D,0x5C,0x89,0xC1,0xC5,0x8A,0xC0,0x7F,0xAA,0x6D,0x9C,0xB2,0xC5,0xDF,0xFB),
	LCD_PARAM_DEF(0xC3,0x42,0x52,0x6C,0x91,0xC7,0xCD,0x97,0xCB,0x8D,0xB9,0x76,0xA2,0xB3,0xC2,0xD8,0xE9),
	LCD_PARAM_DEF(0xC4,0x1E,0x3D,0x5C,0x89,0xC1,0xC5,0x8A,0xC0,0x7F,0xAA,0x6D,0x9C,0xB2,0xC5,0xDF,0xFB),
	LCD_PARAM_DEF(0xC5,0x1E,0x3D,0x5C,0x89,0xC1,0xC5,0x8A,0xC0,0x7F,0xAA,0x6D,0x9C,0xB2,0xC5,0xDF,0xFB),
	LCD_PARAM_DEF(0xC6,0x42,0x52,0x6C,0x91,0xC7,0xCD,0x97,0xCB,0x8D,0xB9,0x76,0xA2,0xB3,0xC2,0xD8,0xE9),
	LCD_PARAM_DEF_END,
};

static const struct ls044k3sx01_param ls044k3sx01_init_seq_1[] = {
	LCD_PARAM_DEF(0xDF,0x55,0xAA,0x52,0x08),
	LCD_PARAM_DEF(0xB8,0x38,0x00,0x22,0x00,0x00,0x08,0xB5,0x0A),
	LCD_PARAM_DEF(0xC0,0x00,0xFF,0x00,0xFF,0x5B,0xFF,0x00,0xFF,0x00,0xFF,0x61,0xFF),
	LCD_PARAM_DEF(0xC1,0x1E,0x3D,0x5D,0x8C,0xCA,0xD2,0xA2,0xD7,0x90,0xB7,0x71,0x9F,0xB4,0xC7,0xE0,0xFB),
	LCD_PARAM_DEF(0xC2,0x1E,0x3D,0x5D,0x8C,0xCA,0xD2,0xA2,0xD7,0x90,0xB7,0x71,0x9F,0xB4,0xC7,0xE0,0xFB),
	LCD_PARAM_DEF(0xC3,0x64,0x72,0x85,0xA6,0xDA,0xDF,0xB8,0xE9,0xAA,0xD1,0x7C,0xA8,0xAf,0xB7,0xB9,0xDD),
	LCD_PARAM_DEF(0xC4,0x1E,0x3D,0x5B,0x85,0xB7,0xB7,0x70,0xA8,0x6D,0x9C,0x69,0x99,0xB0,0xC3,0xDe,0xFB),
	LCD_PARAM_DEF(0xC5,0x1E,0x3D,0x5B,0x85,0xB7,0xB7,0x70,0xA8,0x6D,0x9C,0x69,0x99,0xB0,0xC3,0xDE,0xFB),
	LCD_PARAM_DEF(0xC6,0x68,0x76,0x85,0xA0,0xC8,0xC4,0x87,0xBB,0x87,0xB8,0x74,0xA2,0xAb,0xB3,0xB5,0xDB),
	LCD_PARAM_DEF_END,
};

#endif /* S3CFB_LS044K3SX01_H */
