/********************************************************************************
 **                                                                             
 **  FOLDERNAME	  : Port_Cfg.h         									        
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
 **  DESCRIPTION  : PRE-Compile Configuration Options Of Port Module Driver     
 **                                                                             
 **  SPECS        : Manuale coded									            
 **                                                                             
 **  MAY BE CHANGED BY USER : Yes                                               
 **															                    
 ********************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION           		   	(1U)
#define PORT_CFG_SW_MINOR_VERSION           		   	(0U)
#define PORT_CFG_SW_PATCH_VERSION            		  	(0U)

 /*
 * AUTOSAR Version 4.3.1
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION    		  	(4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     		 	(3U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     			(1U)

/******************************************************************************
 *                  API's PRE-Compile Configuration Options                   *
 ******************************************************************************/

#define PORT_DEV_ERROR_DETECT							(STD_ON)
#define PORT_SET_PIN_DIRECTION_API						(STD_ON)
#define	PORT_SET_PIN_MODE_API							(STD_OFF)
#define	PORT_VERSION_INFO_API							(STD_ON)

/******************************************************************************
*						   AVR-uC Port Properties						      *
******************************************************************************/

#define NUMBER_OF_PORT_PINS								(8U)						
#define TOTAL_NUMBER_OF_PORTS							(4U)
#define TOTAL_NUMBER_OF_PINS                            (32U)

#endif /* PORT_CFG_H_ */
