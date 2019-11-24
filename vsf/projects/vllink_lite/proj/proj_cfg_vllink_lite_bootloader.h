#ifndef __PROJ_CFG_LVL2_H__
#define __PROJ_CFG_LVL2_H__

#define PROJ_CFG_COMPOSITE_DEVICE
#define PROJ_CFG_CMSIS_DAP_V2_SUPPORT
#define PROJ_CFG_WEBUSB_SUPPORT
//#define PROJ_CFG_CDCEXT_SUPPORT
//#define PROJ_CFG_CDCSHELL_SUPPORT


#define PROJ_CFG_DAP_STANDARD_ENABLE				0
#define PROJ_CFG_DAP_VERDOR_UART_ENABLE				0
#define PROJ_CFG_DAP_VERDOR_BOOTLOADER_ENABLE		1
#define PROJ_CFG_USART_EXT_ENABLE					0
#define PROJ_CFG_USART_TRST_SWO_ENABLE				0

/*
	DAP Config
*/
#define DAP_SWD						1
#define DAP_JTAG					1
#define DAP_JTAG_DEV_CNT			8
#define DAP_DEFAULT_PORT			1
#define DAP_DEFAULT_SWJ_CLOCK		4000000
#define DAP_CTRL_PACKET_SIZE		64
#define DAP_BULK_PACKET_SIZE		64
#ifdef VSFUSBD_CFG_HIGHSPEED
#	define DAP_HID_PACKET_SIZE		512
#else
#	define DAP_HID_PACKET_SIZE		64
#endif
#if DAP_BULK_PACKET_SIZE > DAP_HID_PACKET_SIZE
#	define DAP_PACKET_SIZE			DAP_BULK_PACKET_SIZE
#else
#	define DAP_PACKET_SIZE			DAP_HID_PACKET_SIZE
#endif
#define DAP_PACKET_COUNT			2
#define SWO_UART					1
#define SWO_UART_MAX_BAUDRATE		3200000
#define SWO_UART_MIN_BAUDRATE		16000
#define SWO_MANCHESTER				0
#define SWO_BUFFER_SIZE				128

//#define DAP_VENDOR					"Vllogic.com"
//#define DAP_PRODUCT					"Vllogic Lite"

#define FIRMWARE_AREA_ADDR			0x08003000
#define FIRMWARE_AREA_SIZE_MAX		(64 * 1024 - 12 * 1024)
#define FIRMWARE_SP_ADDR			0x20000000
#define FIRMWARE_SP_SIZE_MAX		(8 * 1024)

#endif // __PROJ_CFG_LVL2_H__