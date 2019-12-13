/********************************************************************************
 **                                                                             **
 **  FOLDERNAME	  : DIO_Cfg.h         									        **
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
 **  DESCRIPTION  : PRE-Compile Configuration Options Of DIO Module Driver      **
 **                                                                             **
 **  SPECS        : Manual coded									            **
 **                                                                             **
 **  MAY BE CHANGED BY USER : Yes                                               **
 **															                    **
 ********************************************************************************/

#ifndef DIO_CFG_H_
#define DIO_CFG_H_

/*
 * Module Version 1.0.0
 */
#define DIO_CFG_SW_MAJOR_VERSION           		   	(1U)
#define DIO_CFG_SW_MINOR_VERSION           		   	(0U)
#define DIO_CFG_SW_PATCH_VERSION            		(0U)

 /*
 * AUTOSAR Version 4.3.1
 */
#define DIO_CFG_AR_RELEASE_MAJOR_VERSION    		  	(4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION     		 	(3U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION     			(1U)

/******************************************************************************
 *                  API's PRE-Compile Configuration Options                   *
 ******************************************************************************/

#define DIO_DEV_ERROR_DETECT							(STD_ON)
#define	DIO_VERSION_INFO_API							(STD_ON)
#define DIO_FLIP_CHANNEL_API                            (STD_ON)

#define NUMBER_OF_PORT_PINS								(8U)
#define TOTAL_NUMBER_OF_PORTS							(4U)
#define TOTAL_NUMBER_OF_PINS                            (32U)


#define DIO_CONFIGURED_CHANNLES             (3U)
#define DIO_CONFIGURED_PORTS 				(1U)
#define DIO_CONFIGURED_GROUPS 				(1U)

#endif /* DIO_CFG_H_ */
