/*-----------------------------------------------------------------------------
 *      Name:         cmsis_dv.c
 *      Purpose:      Driver validation test cases entry point
 *----------------------------------------------------------------------------
 *      Copyright(c) KEIL - An ARM Company
 *----------------------------------------------------------------------------*/
#include "cmsis_dv.h"
#include "RTE_Components.h"
#include "DV_Framework.h"
#include "DV_Config.h"

/*-----------------------------------------------------------------------------
 *      Variables declarations
 *----------------------------------------------------------------------------*/
// Buffer list sizes
const uint32_t BUFFER[] =  {
#if (BUFFER_ELEM_1_32!=0)
  1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,
#endif
#if (BUFFER_ELEM_512!=0)
  512,
#endif
#if (BUFFER_ELEM_1024!=0)
  1024,
#endif
#if (BUFFER_ELEM_4096!=0)
  4096,
#endif
#if (BUFFER_ELEM_32768!=0)
  32768,
#endif 
};
const uint32_t BUFFER_NUM = ARRAY_SIZE(BUFFER);

/*-----------------------------------------------------------------------------
 *      Init test suite
 *----------------------------------------------------------------------------*/
static void TS_Init (void) {

}

/*-----------------------------------------------------------------------------
 *      Test cases list
 *----------------------------------------------------------------------------*/
static TEST_CASE TC_LIST[] = {

#ifdef RTE_DV_API_SPI 
  TCD ( SPI_GetCapabilities,            SPI_GETCAPABILITIES_EN          ),           
  TCD ( SPI_Initialization,             SPI_INITIALIZATION_EN           ), 
  TCD ( SPI_PowerControl,               SPI_POWERCONTROL_EN             ),   
  TCD ( SPI_Config_PolarityPhase,       SPI_CONFIG_POLARITYPHASE_EN     ), 
  TCD ( SPI_Config_DataBits,            SPI_CONFIG_DATABITS_EN          ),
  TCD ( SPI_Config_BitOrder,            SPI_CONFIG_BITORDER_EN          ), 
  TCD ( SPI_Config_SSMode,              SPI_CONFIG_SSMODE_EN            ), 
  TCD ( SPI_Config_BusSpeed,            SPI_CONFIG_BUSSPEED_EN          ),
  TCD ( SPI_Config_CommonParams,        SPI_CONFIG_COMMONPARAMS_EN      ), 
  TCD ( SPI_Send,                       SPI_SEND_EN                     ), 
  TCD ( SPI_Receive,                    SPI_RECEIVE_EN                  ),  
  TCD ( SPI_Loopback_CheckBusSpeed,     SPI_LOOPBACK_CHECKBUSSPEED_EN   ),   
  TCD ( SPI_Loopback_Transfer,          SPI_LOOPBACK_TRANSFER_EN        ),
  TCD ( SPI_CheckInvalidInit,           SPI_CHECKINVALIDINIT_EN         ),  
  
#endif
#ifdef RTE_DV_API_USART    
  TCD ( USART_GetCapabilities,          USART_GETCAPABILITIES_EN        ),
  TCD ( USART_Initialization,           USART_INITIALIZATION_EN         ),
  TCD ( USART_PowerControl,             USART_POWERCONTROL_EN           ),
  TCD ( USART_Config_PolarityPhase,     USART_CONFIG_POLARITYPHASE_EN   ),
  TCD ( USART_Config_DataBits,          USART_CONFIG_DATABITS_EN        ),
  TCD ( USART_Config_StopBits,          USART_CONFIG_STOPBITS_EN        ),
  TCD ( USART_Config_Parity,            USART_CONFIG_PARITY_EN          ),  
  TCD ( USART_Config_Baudrate,          USART_CONFIG_BAUDRATE_EN        ),   
  TCD ( USART_Config_CommonParams,      USART_CONFIG_COMMONPARAMS_EN    ),
  TCD ( USART_Send,                     USART_SEND_EN                   ),
  TCD ( USART_Loopback_CheckBaudrate,   USART_LOOPBACK_CHECKBAUDRATE_EN ), 
  TCD ( USART_Loopback_Transfer,        USART_LOOPBACK_TRANSFER_EN      ),
  TCD ( USART_CheckInvalidInit,         USART_CHECKINVALIDINIT_EN       ),
#endif
#ifdef RTE_DV_API_ETH  
  TCD ( ETH_MAC_GetCapabilities,        ETH_MAC_GETCAPABILITIES_EN      ),  
  TCD ( ETH_MAC_Initialization,         ETH_MAC_INITIALIZATION_EN       ),
  TCD ( ETH_MAC_PowerControl,           ETH_MAC_POWERCONTROL_EN         ),
  TCD ( ETH_MAC_SetBusSpeed,            ETH_MAC_SETBUSSPEED_EN          ),
  TCD ( ETH_MAC_Config_Mode,            ETH_MAC_CONFIG_MODE_EN          ),
  TCD ( ETH_MAC_Config_CommonParams,    ETH_MAC_CONFIG_COMMONPARAMS_EN  ),  
  TCD ( ETH_MAC_PTP_ControlTimer,       ETH_MAC_PTP_CONTROLTIMER_EN     ),   
  TCD ( ETH_PHY_Initialization,         ETH_PHY_INITIALIZATION_EN       ),
  TCD ( ETH_PHY_PowerControl,           ETH_PHY_POWERCONTROL_EN         ),
  TCD ( ETH_PHY_Config,                 ETH_PHY_CONFIG_EN               ),    
  TCD ( ETH_Loopback_Transfer,          ETH_LOOPBACK_TRANSFER_EN        ),  
  TCD ( ETH_Loopback_PTP,               ETH_LOOPBACK_PTP_EN             ), 
  TCD ( ETH_PHY_CheckInvalidInit,       ETH_PHY_CHECKINVALIDINIT_EN     ), 
  TCD ( ETH_MAC_CheckInvalidInit,       ETH_MAC_CHECKINVALIDINIT_EN     ), 
#endif
#ifdef RTE_DV_API_I2C  
  TCD ( I2C_GetCapabilities,            I2C_GETCAPABILITIES_EN          ),  
  TCD ( I2C_Initialization,             I2C_INITIALIZATION_EN           ), 
  TCD ( I2C_PowerControl,               I2C_POWERCONTROL_EN             ), 
  TCD ( I2C_SetBusSpeed,                I2C_SETBUSSPEED_EN              ), 
  TCD ( I2C_SetOwnAddress,              I2C_SETOWNADDRESS_EN            ), 
  TCD ( I2C_BusClear,                   I2C_BUSCLEAR_EN                 ), 
  TCD ( I2C_AbortTransfer,              I2C_ABORTTRANSFER_EN            ), 
  TCD ( I2C_CheckInvalidInit,           I2C_CHECKINVALIDINIT_EN         ), 
#endif
#ifdef RTE_DV_API_MCI  
  TCD ( MCI_GetCapabilities,            MCI_GETCAPABILITIES_EN          ), 
  TCD ( MCI_Initialization,             MCI_INITIALIZATION_EN           ), 
  TCD ( MCI_PowerControl,               MCI_POWERCONTROL_EN             ), 
  TCD ( MCI_SetBusSpeedMode,            MCI_SETBUSSPEEDMODE_EN          ),  
  TCD ( MCI_Config_DataWidth,           MCI_CONFIG_DATAWIDTH_EN         ),  
  TCD ( MCI_Config_CmdLineMode,         MCI_CONFIG_CMDLINEMODE_EN       ), 
  TCD ( MCI_Config_DriverStrength,      MCI_CONFIG_DRIVERSTRENGTH_EN    ), 
  TCD ( MCI_CheckInvalidInit,           MCI_CHECKINVALIDINIT_EN         ), 
#endif
#ifdef RTE_DV_API_USBD
  TCD ( USBD_GetCapabilities,           USBD_GETCAPABILITIES_EN         ), 
  TCD ( USBD_Initialization,            USBD_INITIALIZATION_EN          ), 
  TCD ( USBD_PowerControl,              USBD_POWERCONTROL_EN            ), 
  TCD ( USBD_CheckInvalidInit,          USBD_CHECKINVALIDINIT_EN        ), 
#endif  
#ifdef RTE_DV_API_USBH
  TCD ( USBH_GetCapabilities,           USBH_GETCAPABILITIES_EN         ), 
  TCD ( USBH_Initialization,            USBH_INITIALIZATION_EN          ), 
  TCD ( USBH_PowerControl,              USBH_POWERCONTROL_EN            ), 
  TCD ( USBH_CheckInvalidInit,          USBH_CHECKINVALIDINIT_EN        ), 
#endif 
#ifdef RTE_DV_API_CAN
  TCD ( CAN_GetCapabilities,            CAN_GETCAPABILITIES_EN         ), 
  TCD ( CAN_Initialization,             CAN_INITIALIZATION_EN          ), 
  TCD ( CAN_PowerControl,               CAN_POWERCONTROL_EN            ), 
  TCD ( CAN_Loopback_CheckBitrate,      CAN_LOOPBACK_CHECK_BR_EN       ), 
  TCD ( CAN_Loopback_CheckBitrateFD,    CAN_LOOPBACK_CHECK_BR_FD_EN    ), 
  TCD ( CAN_Loopback_Transfer,          CAN_LOOPBACK_TRANSFER_EN       ),
  TCD ( CAN_Loopback_TransferFD,        CAN_LOOPBACK_TRANSFER_FD_EN    ),
#endif 
};

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdate-time"
#endif
/*-----------------------------------------------------------------------------
 *      Test suite description
 *----------------------------------------------------------------------------*/
TEST_SUITE ts = {
  __FILE__, __DATE__, __TIME__,
  "CMSIS-Driver Test Suite",
  TS_Init,  
  1,
  TC_LIST,
  ARRAY_SIZE (TC_LIST),  
};  
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic pop
#endif
