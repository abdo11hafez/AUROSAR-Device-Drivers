/*********************************************************************************
 **                                                                             
 **  FOLDERNAME	  : Compiler.h         										    
 **                                                                             
 **  VERSION      : 1.0.0                                                       
 **                                                                             
 **  DATE         : 2019-11-9                                                   
 **                                                                                                                                                          
 **  PLATFORM     : AVR ATmega32.                                               
 **                                                                             
 **  AUTHOR       : Abdelrahman Hafez.	                                        
 **                                                                             
 **  VENDOR       : Abdelrahman Hafez Co.LTD.							        
 **                                                                                                                                                        
 **  DESCRIPTION  : Compiler Abstraction Implementation.						
 **                                                                             
 **  SPECS        : Manuale coded.									            
 **                                                                             
 **  MAY BE CHANGED BY USER : No.                                               
 **															                    
 ********************************************************************************/

#ifndef COMPILER_H
#define COMPILER_H

/* Id for the company in the AUTOSAR */
#define COMPILER_VENDOR_ID                                  (1996U)

/* Compiler Abstraction Module Id */
#define COMPILER_MODULE_ID									 (198U)

/*
 * Module Version 1.0.0
 */
#define COMPILER_SW_MAJOR_VERSION                           (1U)
#define COMPILER_SW_MINOR_VERSION                           (0U)
#define COMPILER_SW_PATCH_VERSION                           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define COMPILER_AR_RELEASE_MAJOR_VERSION                   (4U)
#define COMPILER_AR_RELEASE_MINOR_VERSION                   (3U)
#define COMPILER_AR_RELEASE_PATCH_VERSION                   (1U)

#define AUTOMATIC
#define TYPEDEF

#define NULL_PTR          ((void *)0)

#define INLINE            inline
#define LOCAL_INLINE      static inline
#define STATIC            static

#define FUNC(rettype, memclass)						  memclass rettype
#define FUNC_P2CONST(rettype, ptrclass, memclass)     const ptrclass rettype * memclass
#define FUNC_P2VAR(rettype, ptrclass, memclass)		  ptrclass rettype * memclass


#endif
