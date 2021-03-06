/*****************************************************************************
 *   Copyright(C)2009-2019 by VSF Team                                       *
 *                                                                           *
 *  Licensed under the Apache License, Version 2.0 (the "License");          *
 *  you may not use this file except in compliance with the License.         *
 *  You may obtain a copy of the License at                                  *
 *                                                                           *
 *     http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                           *
 *  Unless required by applicable law or agreed to in writing, software      *
 *  distributed under the License is distributed on an "AS IS" BASIS,        *
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 *  See the License for the specific language governing permissions and      *
 *  limitations under the License.                                           *
 *                                                                           *
 ****************************************************************************/

#ifndef __VSF_USB_UVC_H__
#define __VSF_USB_UVC_H__

/*============================ INCLUDES ======================================*/

#include "component/usb/vsf_usb_cfg.h"

#if VSF_USE_USB_DEVICE == ENABLED && VSF_USE_USB_DEVICE_UVC == ENABLED

#include "utilities/vsf_utilities.h"

#ifdef __cplusplus
extern "C" {
#endif

/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/

enum usb_uvc_req_t {
    USB_UVC_REQ_CUR     = 1,
    USB_UVC_REQ_MIN     = 2,
    USB_UVC_REQ_MAX     = 3,
    USB_UVC_REQ_RES     = 4,
    USB_UVC_REQ_LEN     = 5,
    USB_UVC_REQ_INFO    = 6,
    USB_UVC_REQ_DEF     = 7,
    USB_UVC_REQ_ALL     = 0x10,
    USB_UVC_REQ_SET     = 0x00,
    USB_UVC_REQ_GET     = 0x80,
};
typedef enum usb_uvc_req_t usb_uvc_req_t;

// Stream Controls
struct usb_uvc_vs_t {
    uint16_t bmHint;
    uint8_t bFormatIndex;
    uint8_t bFrameIndex;
    uint32_t dwFrameInterval;
    uint16_t wKeyFrameRate;
    uint16_t wPFrameRate;
    uint16_t wCompQuality;
    uint16_t wCompWindowSize;
    uint16_t wDelay;
    uint32_t dwMaxVideoFrameSize;
    uint32_t dwMaxPayloadTransferSize;
    uint32_t dwClockFrequency;
    uint8_t bmFramingInfo;
    uint8_t bPreferedVersion;
    uint8_t bMinVersion;
    uint8_t bMaxVersion;
    uint8_t bUsage;
    uint8_t bBitDepthLuma;
    uint8_t bmSettings;
    uint8_t bMaxNumberOfFramesPlus1;
    uint16_t bmRateControlModes;
    uint64_t bmLayoutPerStream;
} PACKED;
typedef struct usb_uvc_vs_t usb_uvc_vs_t;

// Camera Terminal
struct usb_uvc_ct_roi_t {
    uint16_t wROI_Top;
    uint16_t wROI_Left;
    uint16_t wROI_Bottom;
    uint16_t wROI_Right;
    uint16_t bmAutoControls;
} PACKED;
typedef struct usb_uvc_ct_roi_t usb_uvc_ct_roi_t;

/*============================ GLOBAL VARIABLES ==============================*/
/*============================ PROTOTYPES ====================================*/

#ifdef __cplusplus
}
#endif

#endif      // VSF_USE_USB_DEVICE && VSF_USE_USB_DEVICE_UVC
#endif      // __VSFUSB_UVC_H__
