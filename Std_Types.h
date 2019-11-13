/********************************************************************************
 **                                                                             **
 **  FOLDERNAME	  : Std_Types.h         			                            **
 **                                                                             **
 **  VERSION      : 1.0.0                                                       **
 **                                                                             **
 **  DATE         : 2019-11-9                                                   **
 **                                                                             **                                                                             **
 **  PLATFORM     : AVR ATmega32                                                **
 **                                                                             **
 **  AUTHOR       : Abdelrahman Hafez.	                                        **
 **                                                                             **
 **  VENDOR       : Abdelrahman Hafez Co.LTD							        **
 **                                                                             **                                                                           **
 **  DESCRIPTION  : Standard Types Impelemintation                              **
 **                                                                             **
 **  SPECS        : Manuale coded									            **
 **                                                                             **
 **  MAY BE CHANGED BY USER : no                                                **
 **                                                                             **
 ********************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "Platform_Types.h"
#include "Compiler.h"

/* Id for the company in the AUTOSAR */
#define STD_TYPES_VENDOR_ID                                  (1996U)

/* Standard Types Module Id */
#define STD_TYPES_MODULE_ID									 (197U)

/*
 * Module Version 1.0.0
 */
#define STD_TYPES_SW_MAJOR_VERSION                           (1U)
#define STD_TYPES_SW_MINOR_VERSION                           (0U)
#define STD_TYPES_SW_PATCH_VERSION                           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define STD_TYPES_AR_RELEASE_MAJOR_VERSION                   (4U)
#define STD_TYPES_AR_RELEASE_MINOR_VERSION                   (3U)
#define STD_TYPES_AR_RELEASE_PATCH_VERSION                   (1U)

/*
 *  standard API return type used in the project
 */
typedef uint8  Std_ReturnType;

/*
 * type used to request the version of a BSW module 
 * using the <Module name>_GetVersionInfo() function.
 */
typedef struct
{
  uint16  vendorID;
  uint16  moduleID;
  uint8	  sw_major_version;
  uint8   sw_minor_version;
  uint8   sw_patch_version;
} Std_VersionInfoType;

#define E_OK            0x00U      /* Function Return OK */
#define E_NOT_OK        0x01U      /* Function Return NOT OK */

#define STD_HIGH		0x01U		/* Physical state 5V or 3.3V */
#define STD_LOW			0x00U		/* Physical state 0V */

#define STD_ACTIVE      0x01U       /* Logical state active */
#define STD_IDLE        0x00U       /* Logical state idle */

#define STD_ON          0x01U       /* Standard ON */
#define STD_OFF         0x00U       /* Standard OFF */


#endif /* STD_TYPES_H */
