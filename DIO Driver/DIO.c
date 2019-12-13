/********************************************************************************
 **                                                                             **
 **  FOLDERNAME	  : DIO.c         											    **
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
 **  DESCRIPTION  : DIO Driver source file										**
 **                                                                             **
 **  SPECS        : Manuale coded									            **
 **                                                                             **
 **  MAY BE CHANGED BY USER : No                                                **
 **															                    **
 ********************************************************************************/

#include "DIO.h"
#include "Port_MemMap.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*******************************************************************************
 *                           Private Global Variables                          *
 *******************************************************************************/

STATIC Dio_ChannelType *Dio_Channels = Dio_Configuration.Channels;
STATIC Dio_ChannelGroupType *Dio_ChannelGroups  = Dio_Configuration.ChannelGroups;
STATIC Dio_PortType *Dio_Ports = Dio_Configuration.Ports;

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	volatile uint8 * PinRegPtr = NULL_PTR;
	Dio_LevelType ChannelLevel ;
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if the used channel is within the valid range */
	if (ChannelId >= DIO_CONFIGURED_CHANNLES )
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_READ_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	else
#endif
	{
		switch(Dio_Channels[ChannelId] / NUMBER_OF_PORT_PINS)
		{
			case 0:
				PinRegPtr = &PINA_REG;
				break;
			case 1:
				PinRegPtr = &PINB_REG;
				break;
			case 2:
				PinRegPtr = &PINC_REG;
				break;
			case 3:	
				PinRegPtr = &PIND_REG;
				break;
			default:
				break;
		}
		/* Read the required channel */
		if (BIT_IS_SET(*PinRegPtr,Dio_Channels[ChannelId] % NUMBER_OF_PORT_PINS))
		{
			ChannelLevel = STD_HIGH;
		} 
		else if (BIT_IS_CLEAR(*PinRegPtr,Dio_Channels[ChannelId] % NUMBER_OF_PORT_PINS))
		{
			ChannelLevel = STD_LOW;
		}
		else
		{	
		}
		return ChannelLevel ;
	}
}



void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
volatile uint8 * PortRegPtr = NULL_PTR;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	if (ChannelId >= DIO_CONFIGURED_CHANNLES)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	else
#endif
	{
		switch(Dio_Channels[ChannelId] / NUMBER_OF_PORT_PINS)
		{
			case 0:
				PortRegPtr = &PORTA_REG;
				break;
			case 1:
				PortRegPtr = &PORTB_REG;
				break;
			case 2:
				PortRegPtr = &PORTC_REG;
				break;
			case 3:
				PortRegPtr = &PORTD_REG;
				break;
			default:
				break;
		}
		if(Level == STD_HIGH)
		{
			SET_BIT(*PortRegPtr,Dio_Channels[ChannelId] % NUMBER_OF_PORT_PINS);
		}
		else if(Level == STD_LOW)
		{
			CLEAR_BIT(*PortRegPtr,Dio_Channels[ChannelId] % NUMBER_OF_PORT_PINS);
		}
		else
		{
		}
	}
}


Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	volatile uint8 * PinRegPtr = NULL_PTR;
	Dio_PortLevelType PortLevel ;
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	if (PortId >= DIO_CONFIGURED_PORTS)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_READ_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
	}
	else
#endif
	{
		switch (Dio_Ports[PortId]) 
		{
			case 0:
				PinRegPtr = &PINA_REG;
				break;
			case 1:
				PinRegPtr = &PINB_REG;
				break;
			case 2:
				PinRegPtr = &PINC_REG;
				break;
			case 3:
				PinRegPtr = &PIND_REG;
				break;
			default:
				break;
		}
		/*read required port */
		PortLevel = *PinRegPtr;
		return PortLevel;
	}
}


void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	volatile uint8 * PortRegPtr = NULL_PTR;
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	if (PortId >= DIO_CONFIGURED_PORTS)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
	}
	else
#endif
	{
		switch (Dio_Ports[PortId]) 
		{
			case 0:
				PortRegPtr = &PORTA_REG;
				break;
			case 1:
				PortRegPtr = &PORTB_REG;
				break;
			case 2:
				PortRegPtr = &PORTC_REG;
				break;
			case 3:
				PortRegPtr = &PORTD_REG;
				break;
			default:
				break;
		}
		*PortRegPtr = Level;
	}
}


Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr )
{
	volatile uint8 * PinRegPtr = NULL_PTR;
	Dio_PortLevelType GroupLevel ;
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	if (ChannelGroupIdPtr == NULL_PTR)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_READ_CHANNEL_GROUP_SID, DIO_E_PARAM_POINTER);
	}
	else
#endif
	{
		switch (ChannelGroupIdPtr->PortId) {
			case 0:
				PinRegPtr = &PINA_REG;
				break;
			case 1:
				PinRegPtr = &PINB_REG;
				break;
			case 2:
				PinRegPtr = &PINC_REG;
				break;
			case 3:
				PinRegPtr = &PIND_REG;
				break;
			default:
				break;
		}

		GroupLevel = ((*PinRegPtr)&(ChannelGroupIdPtr->DioPortMask))>>ChannelGroupIdPtr->DioPortOffset;
		return GroupLevel;
	}
}


void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level )
{
	volatile uint8 * PortRegPtr = NULL_PTR;
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	if (ChannelGroupIdPtr == NULL_PTR)
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_GROUP_SID, DIO_E_PARAM_POINTER);
	}
	else
#endif
	{
		switch (ChannelGroupIdPtr->PortId) 
		{
			case 0:
				PortRegPtr = &PORTA_REG;
				break;
			case 1:
				PortRegPtr = &PORTB_REG;
				break;
			case 2:
				PortRegPtr = &PORTC_REG;
				break;
			case 3:
				PortRegPtr = &PORTD_REG;
				break;
		}
		*PortRegPtr = ((*PortRegPtr)&(~(ChannelGroupIdPtr->DioPortMask))) | (Level<<ChannelGroupIdPtr->DioPortOffset);
	}
}


#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo)
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_GET_VERSION_INFO_SID, DIO_E_PARAM_POINTER);
	}
	else
#endif 
	{
		versioninfo->vendorID = (uint16)DIO_VENDOR_ID;
		versioninfo->moduleID = (uint16)DIO_MODULE_ID;
		versioninfo->sw_major_version = (uint8)DIO_SW_MAJOR_VERSION;
		versioninfo->sw_minor_version = (uint8)DIO_SW_MINOR_VERSION;
		versioninfo->sw_patch_version = (uint8)DIO_SW_PATCH_VERSION;
	}
}
#endif


#if (DIO_FLIP_CHANNEL_API == STD_ON)
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	Dio_PortLevelType * PortRegPtr = NULL_PTR;
	Dio_PortLevelType * PinRegPtr = NULL_PTR;
	Dio_LevelType ChannelLevel = STD_LOW;

#if (DIO_DEV_ERROR_DETECT == STD_ON)
	if (ChannelId >= DIO_CONFIGURED_CHANNLES)
	{

		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_FLIP_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
	}
	else
#endif
	{
		switch(Dio_Channels[ChannelId]/ NUMBER_OF_PORT_PINS)
		{
			case 0:	
				PortRegPtr = &PORTA_REG;
				PinRegPtr  = &PINA_REG;
				break;
			case 1:	
				PortRegPtr = &PORTB_REG;
				PinRegPtr  = &PINB_REG;
				break;
			case 2:	
				PortRegPtr = &PORTC_REG;
				PinRegPtr  = &PINC_REG;
				break;
			case 3:	
				PortRegPtr = &PORTD_REG;
				PinRegPtr  = &PIND_REG;
				break;
		}
		if(BIT_IS_SET(*PinRegPtr,Dio_Channels[ChannelId] % NUMBER_OF_PORT_PINS))
		{
			CLEAR_BIT(*PortRegPtr,Dio_Channels[ChannelId] % NUMBER_OF_PORT_PINS);
			ChannelLevel = STD_LOW;
		}
		else if (BIT_IS_CLEAR(*PinRegPtr,Dio_Channels[ChannelId] % NUMBER_OF_PORT_PINS))
		{
			SET_BIT(*PortRegPtr,Dio_Channels[ChannelId] % NUMBER_OF_PORT_PINS);
			ChannelLevel = STD_HIGH;
		}
		return ChannelLevel;
	}
}
#endif