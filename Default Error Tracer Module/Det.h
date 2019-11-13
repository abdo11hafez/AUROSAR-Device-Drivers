/********************************************************************************
 **                                                                             
 **  FOLDERNAME	  : Det.c         											    
 **                                                                             
 **  VERSION      : 1.0.0                                                       
 **                                                                             
 **  DATE         : 2019-11-13                                                  
 **                                                                                                                                                          **
 **  PLATFORM     : AVR ATmega32.                                               
 **                                                                             
 **  AUTHOR       : Abdelrahman Hafez.	                                        
 **                                                                             
 **  VENDOR       : Abdelrahman Hafez Co.LTD.							        
 **                                                                                                                                                        **
 **  DESCRIPTION  : Default Error Tracer Macros and Type Definitions.			
 **                                                                             
 **  SPECS        : Manuale coded.									            
 **                                                                             
 **  MAY BE CHANGED BY USER : No.                                               
 **															                    
 ********************************************************************************/

#ifndef DET_H
#define DET_H

#define DET_VENDOR_ID                 (1996U)

/* Det Module Id */
#define DET_MODULE_ID                 (15U)

/* Instance Id */
#define DET_INSTANCE_ID               (0U)

/*
 * Det Module Version 1.0.0
 */
#define DET_SW_MAJOR_VERSION          (1U)
#define DET_SW_MINOR_VERSION          (0U)
#define DET_SW_PATCH_VERSION          (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define DET_AR_MAJOR_VERSION          (4U)
#define DET_AR_MINOR_VERSION          (3U)
#define DET_AR_PATCH_VERSION          (1U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking versions between Std Types and Det Modules */
#if ((DET_AR_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
void Det_ReportError(uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 ErrorId );

#endif /* DET_H */
