/********************************************************************************
 **                                                                             **
 **  FOLDERNAME	  : Port.h         											    **
 **                                                                             **
 **  VERSION      : 1.0.0                                                       **
 **                                                                             **
 **  DATE         : 2019-11-13                                                  **
 **                                                                             **                                                                             **
 **  PLATFORM     : AVR ATmega32                                                **
 **                                                                             **
 **  AUTHOR       : Abdelrahman Hafez.	                                        **
 **                                                                             **
 **  VENDOR       : Abdelrahman Hafez Co.LTD							        **
 **                                                                             **                                                                           **
 **  DESCRIPTION  : Port Driver source file										**
 **                                                                             **
 **  SPECS        : Manuale coded									            **
 **                                                                             **
 **  MAY BE CHANGED BY USER : No                                                **
 **															                    **
 ********************************************************************************/
#ifndef PORT_H
#define PORT_H

#include "Common_Macros.h"
#include "Std_Types.h"
#include "PORT_Cfg.h"

#define PORT_VENDOR_ID    (1996U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (3U)
#define PORT_AR_RELEASE_PATCH_VERSION   (1U)


#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected Module version"
#endif



#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected Module version"
#endif


#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected Module version"
#endif


/***************************************************************
 *               Development Error Codes Macros                *
****************************************************************/

#define PORT_E_PARAM_PIN				(uint8)0x0A
#define PORT_E_PARAM_CONFIG             (uint8)0x0C
#define PORT_E_PARAM_INVALID_MODE	    (uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE	    (uint8)0x0E
#define PORT_E_PARAM_POINTER            (uint8)0x10
#define PORT_E_UNINIT                   (uint8)0xF0


/***************************************************************
 *                    API Service ID Macros                    *
****************************************************************/

#define PORT_INIT_SID 					(uint8)0x00
#define	PORT_SET_PIN_DIRECTION_SID 		(uint8)0x01
#define	PORT_REFRESH_DIRECTION_SID		(uint8)0x02
#define	PORT_GET_VERSION_INFO_SID		(uint8)0x03
#define	PORT_SET_PIN_MODE_SID			(uint8)0x04


#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

#define PORT_A 							(uint8)0
#define PORT_B 							(uint8)1
#define PORT_C 							(uint8)2
#define PORT_D 							(uint8)3
#define PIN_0 							(Port_PinType)0
#define PIN_1 							(Port_PinType)1
#define PIN_2 							(Port_PinType)2
#define PIN_3 							(Port_PinType)3
#define PIN_4 							(Port_PinType)4
#define PIN_5 							(Port_PinType)5
#define PIN_6 							(Port_PinType)6
#define PIN_7 							(Port_PinType)7
#define PIN_8							(Port_PinType)8
#define PIN_9							(Port_PinType)9
#define PIN_10							(Port_PinType)10
#define PIN_11							(Port_PinType)11
#define PIN_12							(Port_PinType)12
#define PIN_13							(Port_PinType)13
#define PIN_14							(Port_PinType)14
#define PIN_15							(Port_PinType)15
#define PIN_16							(Port_PinType)16
#define PIN_17							(Port_PinType)17
#define PIN_18							(Port_PinType)18
#define PIN_19							(Port_PinType)19
#define PIN_20							(Port_PinType)20
#define PIN_21							(Port_PinType)21
#define PIN_22							(Port_PinType)22
#define PIN_23							(Port_PinType)23
#define PIN_24							(Port_PinType)24
#define PIN_25							(Port_PinType)25
#define PIN_26							(Port_PinType)26
#define PIN_27							(Port_PinType)27
#define PIN_28							(Port_PinType)28
#define PIN_29							(Port_PinType)29
#define PIN_30							(Port_PinType)30
#define PIN_31							(Port_PinType)31

/***************************************************************
 *                    Port Module Data Types                   *
****************************************************************/

typedef uint8 Port_PinType;

typedef enum {
	PORT_PIN_LEVEL_HIGH	= 	STD_HIGH,
	PORT_PIN_LEVEL_LOW	=	STD_LOW
}Port_PinLevelValueType;

typedef enum {
	PORT_PIN_IN	 = 	STD_LOW,
	PORT_PIN_OUT =	STD_HIGH
}Port_PinDirectionType;	

typedef enum {
	PORT_PIN_PULL_UP_ACTIV	 = 	STD_HIGH,
	PORT_PIN_PULL_UP_INACTIV =	STD_LOW
}Port_PinPullupStatusType;


typedef enum
{
	PORT_PIN_MODE_ADC,
	PORT_PIN_MODE_CAN,
	PORT_PIN_MODE_DIO,
	PORT_PIN_MODE_DIO_GPT,
	PORT_PIN_MODE_DIO_WDG,
	PORT_PIN_MODE_FLEXRAY,
	PORT_PIN_MODE_ICU,
	PORT_PIN_MODE_LIN,
	PORT_PIN_MODE_MEM,
	PORT_PIN_MODE_PWM,
	PORT_PIN_MODE_SPI
}Port_PinModeType;


typedef struct 
{
	Port_PinType PortId;
	Port_PinType PinId;
	Port_PinDirectionType Direction;
	boolean  PinDirectionChangeable;
	Port_PinModeType  PortPinInitialMode;
	boolean PortPinModeChangeable ;
	Port_PinLevelValueType LevelValue;
	Port_PinPullupStatusType PullupStatus; 
}Port_Pin;

typedef struct
{
	/* The number of pins represented in this PortContainer */
	uint8 NumberOfPortPins;
	/* Configuration of the individual port pins */
	Port_Pin Pins[NUMBER_OF_PORT_PINS];
}Port_Container;

typedef struct
{
	Port_Container Ports[TOTAL_NUMBER_OF_PORTS];
}Port_ConfigType;

/***************************************************************
*                    Functions Prototypes                      *
****************************************************************/

/***************************************************************
* Service Name:       Port_Init
* Service ID:	      0x00
* Sync/Async:         Synchronous
* Re-entrancy:        Non reentrant
* Parameters (in):    ConfigPtr - Pointer to configuration set.
* Return value:       None
* Description:        The function Port_Init shall initialize
*					  ALL ports and port pins with the configuration set
*					  pointed to by the parameter ConfigPtr.
*				      All ports and port pins that are not used to be 
*					  set to a defined state by the PORT configuration.
****************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr );


/***************************************************************
* Service Name:       Port_SetPinDirection
* Service ID:	      0x01
* Sync/Async:         Synchronous
* Reentrancy:         Reentrant
* Parameters (in):    Pin - Port Pin ID number,
                      Direction - Port Pin Direction.
* Return value:       None
* Description:        Sets the port pin direction during runtime.
					  shall only be available to the user if
					  the pre-compile parameter PortSetPinDirectionApi
					  is set to TRUE.
****************************************************************/
#if(PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection (Port_PinType Pin,Port_PinDirectionType Direction );
#endif

/*******************************************************************************
* Service Name:		  Port_RefreshPortDirection
* Service ID:		  0x02
* Sync/Async:		  Synchronous
* Reentrancy:		  Non Reentrant
* Parameters (in):	  None
* Parameters (out):   None
* Return value:		  None
* Description:		  Function to Refresh the port direction.
********************************************************************************/
void Port_RefreshPortDirection( void );


/*******************************************************************************
* Service Name:		 Port_GetVersionInfo
* Service ID[hex]:	 0x03
* Sync/Async:		 Synchronous
* Reentrancy:		 Non Reentrant
* Parameters (in):	 None
* Parameters (out):  versioninfo - Pointer to where to store the version information
*                    of this module
* Return value:		 None
* Description:		 Function to Return the version information of this module.
					 shall only be available to the user if
					 the pre-compile parameter PortVersionInfoApi
					 is set to TRUE.
********************************************************************************/
#if(PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif



extern const Port_ConfigType PortConfigSet;

#endif /* PORT_H */
