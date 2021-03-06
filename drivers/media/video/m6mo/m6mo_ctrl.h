#ifndef __M6MO_CTRL_H__ 
#define __M6MO_CTRL_H__

/*
  *
  * This file is for our private ioctl command definition and enumeration
  * distinguish from samsung
  *
*/


/* 
  * for panorama capture
*/
#define V4L2_CID_CAMERA_PANO_CAPTURE    					(V4L2_CID_PRIVATE_BASE + 51) 
#define V4L2_CID_CAMERA_PANO_PICTURE_NUM 				(V4L2_CID_PRIVATE_BASE + 251) 
#define V4L2_CID_CAMERA_PANO_STATUS 						(V4L2_CID_PRIVATE_BASE + 252) 
#define V4L2_CID_CAMERA_TERMINATE_PANO 					(V4L2_CID_PRIVATE_BASE + 255)
#define V4L2_CID_CAMERA_PANO_READY 						(V4L2_CID_PRIVATE_BASE + 256)
#define V4L2_CID_CAMERA_PANO_DIRECTION 					(V4L2_CID_PRIVATE_BASE + 257)

/*
  * for face and smile detection
*/
#define V4L2_CID_CAMERA_SMILE_FACE_DETECTION 			(V4L2_CID_PRIVATE_BASE + 253) 
#define V4L2_CID_CAMERA_FACE_DET_NUM 					(V4L2_CID_PRIVATE_BASE + 254) 
#define V4L2_CID_CAMERA_FACE_DET_SELECT 					(V4L2_CID_PRIVATE_BASE + 258) 
#define V4L2_CID_CAMERA_SELECTED_FACE_LOCATION 			(V4L2_CID_PRIVATE_BASE + 259) 
#define V4L2_CID_CAMERA_SELECTED_FACE_SIZE 				(V4L2_CID_PRIVATE_BASE + 260) 
#define V4L2_CID_CAMERA_FACE_DETECTION_DIRECTION (V4L2_CID_PRIVATE_BASE + 299) 

/*
  * for multi capture
*/
#define V4L2_CID_CAMERA_MULTI_CAPTURE 					(V4L2_CID_PRIVATE_BASE + 261) 
#define V4L2_CID_CAMERA_WAIT_MULTI_CAPTURE 				(V4L2_CID_PRIVATE_BASE + 262)
#define V4L2_CID_CAMERA_MULTI_CAPTURE_READY 			(V4L2_CID_PRIVATE_BASE + 263) 
#define V4L2_CID_CAMERA_MULTI_CAPTURE_PICTURE 			(V4L2_CID_PRIVATE_BASE + 264) 

/*
  * for exif information 
*/
#define V4L2_CID_CAMERA_EXIF_EXPTIME_NUMERATOR 		(V4L2_CID_PRIVATE_BASE + 271) 
#define V4L2_CID_CAMERA_EXIF_EXPTIME_DENUMINATOR 		(V4L2_CID_PRIVATE_BASE + 272) 
#define V4L2_CID_CAMERA_EXIF_TV_NUMERATOR 				(V4L2_CID_PRIVATE_BASE + 273) 
#define V4L2_CID_CAMERA_EXIF_TV_DENUMINATOR 			(V4L2_CID_PRIVATE_BASE + 274) 
#define V4L2_CID_CAMERA_EXIF_AV_NUMERATOR 				(V4L2_CID_PRIVATE_BASE + 275) 
#define V4L2_CID_CAMERA_EXIF_AV_DENUMINATOR 			(V4L2_CID_PRIVATE_BASE + 276) 
#define V4L2_CID_CAMERA_EXIF_BV_NUMERATOR 				(V4L2_CID_PRIVATE_BASE + 277) 
#define V4L2_CID_CAMERA_EXIF_BV_DENUMINATOR 			(V4L2_CID_PRIVATE_BASE + 278) 
#define V4L2_CID_CAMERA_EXIF_EBV_NUMERATOR 				(V4L2_CID_PRIVATE_BASE + 279) 
#define V4L2_CID_CAMERA_EXIF_EBV_DENUMINATOR 			(V4L2_CID_PRIVATE_BASE + 280) 
#define V4L2_CID_CAMERA_EXIF_ISOV 							(V4L2_CID_PRIVATE_BASE + 281) 
#define V4L2_CID_CAMERA_EXIF_FLASHV 						(V4L2_CID_PRIVATE_BASE + 282) 
#define V4L2_CID_CAMERA_EXIF_SDRV 						(V4L2_CID_PRIVATE_BASE + 283) 
#define V4L2_CID_CAMERA_EXIF_QV 							(V4L2_CID_PRIVATE_BASE + 284) 

/* 
  * for raw capture control
*/
#define V4L2_CID_CAMERA_RAW_IMAGE_INDEX 				(V4L2_CID_PRIVATE_BASE + 293) 
#define V4L2_CID_CAMERA_RAW_IMAGE_FLAG 					(V4L2_CID_PRIVATE_BASE + 294) 

/*other*/
#define V4L2_CID_CAMERA_CAPTURE_SIZE 					(V4L2_CID_PRIVATE_BASE + 290) 
#define V4L2_CID_CAMERA_ISP_REVERSE 						(V4L2_CID_PRIVATE_BASE + 291) 
#define V4L2_CID_CAMERA_ISP_MIRROR 						(V4L2_CID_PRIVATE_BASE + 292) 
#define V4L2_CID_CAMERA_FOCUS_WINDOW					(V4L2_CID_PRIVATE_BASE+130)
#define V4L2_CID_CAMERA_ROTATION							(V4L2_CID_PRIVATE_BASE+131)

/* 
  * for color bar function, used by factory test mode 
*/
#define V4L2_CID_CAMERA_COLORBAR							(V4L2_CID_PRIVATE_BASE + 295) 

/*
  * for scene exposure, used to determine auto focus
*/
#define V4L2_CID_CAMERA_SCENE_EV 							(V4L2_CID_PRIVATE_BASE + 296) 

/*
  * quick capture, compression
*/
#define V4L2_CID_CAMERA_QUICK_CAPTURE 					(V4L2_CID_PRIVATE_BASE + 297) 
#define V4L2_CID_CAMERA_COMPRESSION		 				(V4L2_CID_PRIVATE_BASE + 298)

#define V4L2_CID_CAMERA_WAKEUP_PREVIEW (V4L2_CID_PRIVATE_BASE + 300)
#define V4L2_CID_CAMERA_CAPTURE_FORMAT (V4L2_CID_PRIVATE_BASE + 301)

/*
* From this we can know whether light on is needed
*/
#define V4L2_CID_CAMERA_LIGHT_INFO (V4L2_CID_PRIVATE_BASE + 302)

/* 
  * for VIDIOC_G_EXT_CTRLS and VIDIOC_S_EXT_CTRLS, from offset 0x9000 
*/
#define V4L2_CTRL_CLASS_CAMERA_BASE 			(V4L2_CTRL_CLASS_CAMERA + 0x9000)

/* 
  * for register 
*/
#define V4L2_CTRL_CLASS_CAMERA_REGISTER 		(V4L2_CTRL_CLASS_CAMERA_BASE + 1)  

/* 
  * for exif 
*/
#define V4L2_CTRL_CLASS_CAMERA_EXPTIME_N 	(V4L2_CTRL_CLASS_CAMERA_BASE + 2)    /* NUMERATOR*/
#define V4L2_CTRL_CLASS_CAMERA_EXPTIME_D 	(V4L2_CTRL_CLASS_CAMERA_BASE + 3)   /* DENUMINATOR */
#define V4L2_CTRL_CLASS_CAMERA_TV_N 			(V4L2_CTRL_CLASS_CAMERA_BASE + 4)
#define V4L2_CTRL_CLASS_CAMERA_TV_D 			(V4L2_CTRL_CLASS_CAMERA_BASE + 5)
#define V4L2_CTRL_CLASS_CAMERA_AV_N 			(V4L2_CTRL_CLASS_CAMERA_BASE + 6)
#define V4L2_CTRL_CLASS_CAMERA_AV_D 			(V4L2_CTRL_CLASS_CAMERA_BASE + 7)
#define V4L2_CTRL_CLASS_CAMERA_BV_N 			(V4L2_CTRL_CLASS_CAMERA_BASE + 8)
#define V4L2_CTRL_CLASS_CAMERA_BV_D 			(V4L2_CTRL_CLASS_CAMERA_BASE + 9)
#define V4L2_CTRL_CLASS_CAMERA_EBV_N 		(V4L2_CTRL_CLASS_CAMERA_BASE + 10)
#define V4L2_CTRL_CLASS_CAMERA_EBV_D 		(V4L2_CTRL_CLASS_CAMERA_BASE + 11)
#define V4L2_CTRL_CLASS_CAMERA_ISO 			(V4L2_CTRL_CLASS_CAMERA_BASE + 12)
#define V4L2_CTRL_CLASS_CAMERA_FLASH 			(V4L2_CTRL_CLASS_CAMERA_BASE + 13)
#define V4L2_CTRL_CLASS_CAMERA_SDR 			(V4L2_CTRL_CLASS_CAMERA_BASE + 14)
#define V4L2_CTRL_CLASS_CAMERA_QV 			(V4L2_CTRL_CLASS_CAMERA_BASE + 15)

/*
  * scane mode
*/
enum m6mo_scene_mode {
	M6MO_SCENE_NONE,
	M6MO_SCENE_AUTO,
	M6MO_SCENE_PORTRAIT,
	M6MO_SCENE_LANDSCAPE,
	M6MO_SCENE_SPORTS,
	M6MO_SCENE_NIGHTSHOT,
	M6MO_SCENE_SUNSET,
	M6MO_SCENE_MICRO,
	M6MO_SCENE_CHARACTER,
	M6MO_SCENE_MAX,
};

/*
  * flash mode
*/
enum m6mo_flash_mode {
	M6MO_FLASH_OFF,
	M6MO_FLASH_AUTO,
	M6MO_FLASH_ON,
	M6MO_FLASH_MAX,
};

/*
  * brightness value
*/
enum m6mo_ev_mode {
	M6MO_EV_MINUS_2	= 0,
	M6MO_EV_MINUS_1_5= 1,
	M6MO_EV_MINUS_1	= 2,
	M6MO_EV_MINUS_0_5 =3,
	M6MO_EV_DEFAULT	= 4,
	M6MO_EV_PLUS_0_5	= 5,
	M6MO_EV_PLUS_1	= 6,
	M6MO_EV_PLUS_1_5	= 7,
	M6MO_EV_PLUS_2	= 8,
	M6MO_EV_MAX,
};

/*
  * white balance
*/
enum m6mo_wb_mode {	
	M6MO_WB_AUTO,
	M6MO_WB_INCANDESCENT,
	M6MO_WB_FLUORESCENT_HIGH,
	M6MO_WB_FLUORESCENT_LOW,
	M6MO_WB_SUNNY,
	M6MO_WB_CLOUDY,
	M6MO_WB_SHADE,
	M6MO_WB_HORIZON,
	M6MO_WB_MAX,
};

/*
  * effect mode
*/
enum m6mo_effect_mode {
	M6MO_IE_NONE,
	M6MO_IE_BNW,
	M6MO_IE_SEPIA,
	M6MO_IE_RED,
	M6MO_IE_GREEN,
	M6MO_IE_BLUE,
	M6MO_IE_PINK,
	M6MO_IE_YELLOW,	
	M6MO_IE_PURPLE,	
	M6MO_IE_ANTIQUE,
	M6MO_IE_MAX,
};

/*
  * iso mode
*/
enum m6mo_iso_mode {
	M6MO_ISO_AUTO,
	M6MO_ISO_50,
	M6MO_ISO_100,
	M6MO_ISO_200,
	M6MO_ISO_400,
	M6MO_ISO_800,
	M6MO_ISO_1600,
	M6MO_ISO_3200,
	M6MO_ISO_MAX,
};

/*
  * contrast mode
*/
enum m6mo_contrast_mode {
	M6MO_CONTRAST_MINUS_4,
	M6MO_CONTRAST_MINUS_3,		
	M6MO_CONTRAST_MINUS_2,
	M6MO_CONTRAST_MINUS_1,
	M6MO_CONTRAST_DEFAULT,
	M6MO_CONTRAST_PLUS_1,
	M6MO_CONTRAST_PLUS_2,
	M6MO_CONTRAST_PLUS_3,
	M6MO_CONTRAST_PLUS_4,
	M6MO_CONTRAST_MAX,
};

/*
  * wdr mode
*/
enum m6mo_wdr_mode {
	M6MO_WDR_OFF,
	M6MO_WDR_LOW,	
	M6MO_WDR_MIDDLE,
	M6MO_WDR_HIGH,
	M6MO_WDR_AUTO,
	M6MO_WDR_MAX,
};

/*
  * zoom level
*/
enum m6mo_zoom_level {
	M6MO_ZL_1 = 0x01,
	M6MO_ZL_70 = 0x46,
	M6MO_ZL_MAX,
};

/*
  * focus mode
*/
enum m6mo_focusmode {
	M6MO_FOCUS_AUTO,
	M6MO_FOCUS_MACRO,
	M6MO_FOCUS_MACRO_CAF,
	M6MO_FOCUS_FD,
	M6MO_FOCUS_FD_CAF,
	M6MO_FOCUS_TOUCH,
	M6MO_FOCUS_TOUCH_CAF,
	M6MO_FOCUS_AUTO_CAF,
	M6MO_FOCUS_MAX,
};

/*
  * frame rate
*/
enum m6mo_frame_rate {
	M6MO_FR_AUTO = 0,
	M6MO_FR_7 = 7,
	M6MO_FR_15 = 15,
	M6MO_FR_30 = 30,
	M6MO_FR_60 = 60,
	M6MO_FR_120 = 120,
	M6MO_FR_MAX,
};


enum m6mo_foucs_window {
	M6MO_MIN_WINDOW = 0,//7X7 array
	M6MO_MAX_WINDOW = 48,//7X7 array
};

/*
  * rotation
*/
enum m6mo_cam_rotation {
	M6MO_ROTATE_0,
	M6MO_ROTATE_90,
	M6MO_ROTATE_180,
	M6MO_ROTATE_270,
	M6MO_ROTATE_MAX,
};

/*
  * mirror mode
*/
enum m6mo_mirror_mode {
	M6MO_NO_MIRROR,
	M6MO_MIRROR,
	M6MO_MIRROR_MAX,
};

/*
  * mirror mode
*/
enum m6mo_reverse_mode {
	M6MO_NO_REVERSE,
	M6MO_REVERSE,
	M6MO_REVERSE_MAX,
};

#endif