/********************************************************************************
 **                                                                             **
 **  FOLDERNAME	  : DIO.h         											    **
 **                                                                             **
 **  VERSION      : 1.0.0                                                       **
 **                                                                             **
 **  DATE         : 2019-12-12                                                  **
 **                                                                             **                                                                             **
 **  PLATFORM     : AVR ATmega32                                                **
 **                                                                             **
 **  AUTHOR       : Abdelrahman Hafez.	                                        **
 **                                                                             **
 **  VENDOR       : Abdelrahman Hafez Co.LTD							        **
 **                                                                             **                                                                           **
 **  DESCRIPTION  : DIO Driver Header file										**
 **                                                                             **
 **  SPECS        : Manuale coded									            **
 **                                                                             **
 **  MAY BE CHANGED BY USER : No                                                **
 **															                    **
 ********************************************************************************/
#ifndef DIO_H
#define DIO_H

#include "Common_Macros.h"
#include "Std_Types.h"
#include "DIO_Cfg.h"

#define DIO_VENDOR_ID    (1996U)

/* DIO Module Id */
#define DIO_MODULE_ID    (120U)

/* DIO Instance Id */
#define DIO_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define DIO_SW_MAJOR_VERSION           (1U)
#define DIO_SW_MINOR_VERSION           (0U)
#define DIO_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define DIO_AR_RELEASE_MAJOR_VERSION   (4U)
#define DIO_AR_RELEASE_MINOR_VERSION   (3U)
#define DIO_AR_RELEASE_PATCH_VERSION   (1U)


#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected Module version"
#endif



#if ((DIO_CFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of DIO_Cfg.h does not match the expected Module version"
#endif


#if ((DIO_CFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
 ||  (DIO_CFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
 ||  (DIO_CFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
  #error "The SW version of DIO_Cfg.h does not match the expected Module version"
#endif


/***************************************************************
 *               Development Error Codes Macros                *
****************************************************************/

#define DIO_E_PARAM_INVALID_CHANNEL_ID				(uint8)0x0A
#define DIO_E_PARAM_INVALID_PORT_ID                 (uint8)0x14
#define DIO_E_PARAM_INVALID_GROUP	                (uint8)0x1F
#define DIO_E_PARAM_POINTER	                        (uint8)0x20



/***************************************************************
 *                    API Service ID Macros                    *
****************************************************************/

#define DIO_READ_CHANNEL_SID           			(uint8)0x00
#define	DIO_WRITE_CHANNEL_SID           		(uint8)0x01
#define	DIO_READ_PORT_SID              		    (uint8)0x02
#define	DIO_WRITE_PORT_SID             		    (uint8)0x03
#define	DIO_READ_CHANNEL_GROUP_SID     			(uint8)0x04
#define DIO_WRITE_CHANNEL_GROUP_SID             (uint8)0x05
#define DIO_GET_VERSION_INFO_SID                (uint8)0x12
#define DIO_FLIP_CHANNEL_SID                    (uint8)0x11

 
/***************************************************************
 *                    Port Module Data Types                   *
****************************************************************/

typedef uint8 Dio_ChannelType;

typedef uint8 Dio_PortType;

typedef uint8 Dio_LevelType;

typedef uint8 Dio_PortLevelType;

typedef struct
{
	Dio_PortType PortId;
	uint8 DioPortMask;
	uint8 DioPortOffset;
	
} Dio_ChannelGroupType;

typedef struct
{
	Dio_ChannelType Channels[DIO_CONFIGURED_CHANNLES];
	Dio_ChannelGroupType ChannelGroups [DIO_CONFIGURED_GROUPS];
	Dio_PortType Ports[DIO_CONFIGURED_PORTS];	
} Dio_ConfigType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level );

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* Function for DIO flip channel API */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif

/* Function for DIO Get Version Info API */
#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

extern const Dio_ConfigType Dio_Configuration;

#endif /* PORT_H */
