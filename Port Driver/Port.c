/********************************************************************************
 **                                                                             
 **  FOLDERNAME	  : Port.c         											    
 **                                                                             
 **  VERSION      : 1.0.0                                                       
 **                                                                             
 **  DATE         : 2019-11-13                                                  
 **                                                                                                                                                          
 **  PLATFORM     : AVR ATmega32                                                
 **                                                                             
 **  AUTHOR       : Abdelrahman Hafez.	                                        
 **                                                                             
 **  VENDOR       : Abdelrahman Hafez Co.LTD							        
 **                                                                                                                                                        
 **  DESCRIPTION  : Port Driver source file										
 **                                                                             
 **  SPECS        : Manuale coded									            
 **                                                                             
 **  MAY BE CHANGED BY USER : No                                                
 **															                    
 ********************************************************************************/

#include "Port.h"
#include "Port_MemMap.h"
#include "Det.h"

/*******************************************************************************
 *                           Private Global Variables                          *
 *******************************************************************************/

STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

void Port_Init(const Port_ConfigType* ConfigPtr) 
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if (ConfigPtr == NULL_PTR) {
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,PORT_E_PARAM_CONFIG);
	} 
	else
#endif
	{
	    Port_Container * PortCfg = ConfigPtr->Ports;
		Port_Pin * PinCfg = NULL_PTR;
		volatile uint8 * DirectionRegPtr  = NULL_PTR;
		volatile uint8 * PortRegPtr = NULL_PTR;
		uint8 Port_Index;
		uint8 Pin_Index;
		uint8 PortNumber = 0;
		uint8 PinNumber  = 0;
		for (Port_Index = 0; Port_Index < TOTAL_NUMBER_OF_PORTS; Port_Index++)
		{
			PinCfg = PortCfg[Port_Index].Pins;
			for (Pin_Index = 0; Pin_Index < NUMBER_OF_PORT_PINS; Pin_Index++)
			{
				PortNumber = PinCfg[Pin_Index].PinId / NUMBER_OF_PORT_PINS ;
				PinNumber  = PinCfg[Pin_Index].PinId % NUMBER_OF_PORT_PINS ;
				switch (PortNumber)
				{
					case 0:
					PortRegPtr = &PORTA_REG;
					DirectionRegPtr  = &DDRA_REG;
					break;
					case 1:
					PortRegPtr = &PORTB_REG;
					DirectionRegPtr  = &DDRB_REG;
					break;
					case 2:
					PortRegPtr = &PORTC_REG;
					DirectionRegPtr  = &DDRC_REG;
					break;
					case 3:
					PortRegPtr = &PORTD_REG;
					DirectionRegPtr  = &DDRD_REG;
					break;
				}
				switch (PinCfg[Pin_Index].PortPinInitialMode)
				{
					case PORT_PIN_MODE_DIO :
						switch (PinCfg[Pin_Index].Direction)
						{
							case PORT_PIN_OUT :
								SET_BIT(*DirectionRegPtr,PinNumber);
								if (PinCfg[Pin_Index].LevelValue == PORT_PIN_LEVEL_HIGH)
								{
									SET_BIT(*PortRegPtr,PinNumber);
								}
								else
								{
									CLEAR_BIT(*PortRegPtr,PinNumber);
								}
								break;
							case PORT_PIN_IN :
								CLEAR_BIT(*DirectionRegPtr,PinNumber);
								if (PinCfg[Pin_Index].PullupStatus == PORT_PIN_PULL_UP_ACTIV)
								{
									SET_BIT(*PortRegPtr,PinNumber);
								}
								else
								{
									CLEAR_BIT(*PortRegPtr,PinNumber);
								}
								break;
						}
						break;
					case PORT_PIN_MODE_ADC :		 /*NOT implemented yet*/
						break;
					case PORT_PIN_MODE_SPI :		 /*NOT implemented yet*/
						break;
					case PORT_PIN_MODE_PWM :		 /*NOT implemented yet*/
						break;
					case PORT_PIN_MODE_CAN :		 /*NOT implemented yet*/
						break;
					case PORT_PIN_MODE_LIN :		 /*NOT implemented yet*/
						break;
					case PORT_PIN_MODE_FLEXRAY :	 /*NOT implemented yet*/
						break;
					case PORT_PIN_MODE_ICU :		 /*NOT implemented yet*/
						break;
					case PORT_PIN_MODE_DIO_GPT :	 /*NOT implemented yet*/
						break;
					case PORT_PIN_MODE_DIO_WDG :	 /*NOT implemented yet*/
						break;
					case PORT_PIN_MODE_MEM :		 /*NOT implemented yet*/
						break;
				}
			}		
		}
		Port_Status = PORT_INITIALIZED;
	}
}

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if (Port_Status == PORT_NOT_INITIALIZED)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,PORT_E_UNINIT);
	}
	else if (Pin >= TOTAL_NUMBER_OF_PINS)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,PORT_E_PARAM_PIN);
	}
	else
#endif
    {
		uint8 PortNumber = Pin / NUMBER_OF_PORT_PINS ;
		uint8 PinNumber  = Pin % NUMBER_OF_PORT_PINS ;
		volatile uint8 * DirectionRegPtr  = NULL_PTR;
		#if (PORT_DEV_ERROR_DETECT == STD_ON)
		if ((PortConfigSet.Ports[PortNumber]).Pins[PinNumber].PinDirectionChangeable == FALSE )
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID ,PORT_E_MODE_UNCHANGEABLE);
		}
		else
		#endif
		{
			switch (PortNumber)
			{
				case 0:
					DirectionRegPtr = &DDRA_REG;
					break;
				case 1:
					DirectionRegPtr = &DDRB_REG;
					break;
				case 2:
					DirectionRegPtr = &DDRC_REG;
					break;
				case 3:
					DirectionRegPtr = &DDRD_REG;
					break;
			}
			if (Direction == PORT_PIN_OUT)
			{
				SET_BIT(*DirectionRegPtr,PinNumber);
			}
			else if(Direction == PORT_PIN_IN)
			{
				CLEAR_BIT(*DirectionRegPtr,PinNumber);
			}
		}
	}
}
#endif

void Port_RefreshPortDirection(void)
{
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if (Port_Status == PORT_NOT_INITIALIZED)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,PORT_E_UNINIT);
	}
	else
	#endif
	{
		 volatile uint8 * DirectionRegPtr  = NULL_PTR;
		 volatile uint8 * PortRegPtr = NULL_PTR;
		 uint8 Port_Index;
		 uint8 Pin_Index;
		 uint8 PortNumber = 0;
		 uint8 PinNumber  = 0;
		 for (Port_Index = 0; Port_Index < TOTAL_NUMBER_OF_PORTS; Port_Index++)
		 {
			 for (Pin_Index = 0; Pin_Index < NUMBER_OF_PORT_PINS; Pin_Index++)
			 {
				 PortNumber = (PortConfigSet.Ports[Port_Index]).Pins[Pin_Index].PinId / NUMBER_OF_PORT_PINS ;
				 PinNumber  = (PortConfigSet.Ports[Port_Index]).Pins[Pin_Index].PinId % NUMBER_OF_PORT_PINS ;
				 switch (PortNumber)
				 {
					 case 0:
						PortRegPtr = &PORTA_REG;
						DirectionRegPtr  = &DDRA_REG;
						 break;
					 case 1:
						PortRegPtr = &PORTB_REG;
						DirectionRegPtr  = &DDRB_REG;
						break;
					 case 2:
						PortRegPtr = &PORTC_REG;
						DirectionRegPtr  = &DDRC_REG;
						break;
					 case 3:
						PortRegPtr = &PORTD_REG;
						DirectionRegPtr  = &DDRD_REG;
						break;
				 }
				 switch (((PortConfigSet.Ports[Port_Index]).Pins[Pin_Index]).Direction)
				 {
					 case PORT_PIN_OUT :
						SET_BIT(*DirectionRegPtr,PinNumber);
						break;
					 case PORT_PIN_IN :
						 CLEAR_BIT(*DirectionRegPtr,PinNumber);
						 if ((PortConfigSet.Ports[Port_Index]).Pins[Pin_Index].PullupStatus == PORT_PIN_PULL_UP_ACTIV)
						 {
							 SET_BIT(*PortRegPtr,PinNumber);
						 }
						 else
						 {
							 CLEAR_BIT(*PortRegPtr,PinNumber);
						 }
						 break;	
				 }
			 }
		 }
	}
}


#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
#if(PORT_DEV_ERROR_DETECT == STD_ON)
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_GET_VERSION_INFO_SID ,PORT_E_UNINIT);
	}
	if(versioninfo == NULL_PTR)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else	
#endif
	{
		versioninfo ->vendorID = (uint16)PORT_VENDOR_ID;
		versioninfo ->moduleID = (uint16)PORT_MODULE_ID;
		versioninfo ->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		versioninfo ->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		versioninfo ->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif		  
