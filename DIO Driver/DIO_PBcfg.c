/********************************************************************************
 **                                                                             **
 **  FOLDERNAME	  : DIO_BPcfg.c         			                            **
 **                                                                             **
 **  VERSION      : 1.0.0                                                       **
 **                                                                             **
 **  DATE         : 2019-12-13                                                  **
 **                                                                             **                                                                             **
 **  PLATFORM     : AVR ATmega32                                                **
 **                                                                             **
 **  AUTHOR       : Abdelrahman Hafez.	                                        **
 **                                                                             **
 **  VENDOR       : Abdelrahman Hafez Co.LTD							        **
 **                                                                             **                                                                           **
 **  DESCRIPTION  : Post-Building Configuration Of Port Driver                  **
 **                                                                             **
 **  SPECS        : Manuale coded									            **
 **                                                                             **
 **  MAY BE CHANGED BY USER : No                                                **
 **                                                                             **
 ********************************************************************************/
#include "DIO.h"
/******************************************************************************
 *                             AUTOSAR Module Info                            *
 ******************************************************************************/
/*
 * Module Version 1.0.0
 */
#define DIO_PBCFG_SW_MAJOR_VERSION                                        (1U)
#define DIO_PBCFG_SW_MINOR_VERSION                                        (0U)
#define DIO_PBCFG_SW_PATCH_VERSION                                        (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define DIO_PBCFG_AR_RELEASE_MAJOR_VERSION                                (4U)
#define DIO_PBCFG_AR_RELEASE_MINOR_VERSION                                (3U)
#define DIO_PBCFG_AR_RELEASE_PATCH_VERSION                                (1U)

/* AUTOSAR Version checking between DIO_PBcfg.c and DIO.h files */
#if ((DIO_PBCFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
||   (DIO_PBCFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
||   (DIO_PBCFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
#error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between DIO_PBcfg.c and DIO.h files */
#if ((DIO_PBCFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
||   (DIO_PBCFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
||   (DIO_PBCFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
#error "The SW version of PBcfg.c does not match the expected version"
#endif

/******************************************************************************
 *                             DIO Configuration Set                         *
 ******************************************************************************/

const Dio_ConfigType Dio_Configuration = 
{
	.Channels={0,21,26},
	.Ports={0},
	.ChannelGroups={ {0,0x1E,1} }
};