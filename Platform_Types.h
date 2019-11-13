/*********************************************************************************
 **                                                                             **
 **  FOLDERNAME	  : Platform_Types.h         								    **
 **                                                                             **
 **  VERSION      : 1.0.0                                                       **
 **                                                                             **
 **  DATE         : 2019-11-9                                                   **
 **                                                                             **                                                                             **
 **  PLATFORM     : AVR ATmega32.                                               **
 **                                                                             **
 **  AUTHOR       : Abdelrahman Hafez.	                                        **
 **                                                                             **
 **  VENDOR       : Abdelrahman Hafez Co.LTD.							        **
 **                                                                             **                                                                           **
 **  DESCRIPTION  : Platform Types Implementation.								**
 **                                                                             **
 **  SPECS        : Manuale coded.									            **
 **                                                                             **
 **  MAY BE CHANGED BY USER : No.                                               **
 ********************************************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

/* Id for the company in the AUTOSAR */
#define PLATFORM_VENDOR_ID                          (1996U)

/* Platform Types Module Id */
#define PLATFORM_TYPES_MODULE_ID                    (199U)

/*
 * Module Version 1.0.0
 */
#define PLATFORM_SW_MAJOR_VERSION                   (1U)
#define PLATFORM_SW_MINOR_VERSION                   (0U)
#define PLATFORM_SW_PATCH_VERSION                   (0U)				

/*
 * AUTOSAR Version 4.3.1
 */
#define PLATFORM_AR_RELEASE_MAJOR_VERSION           (4U)
#define PLATFORM_AR_RELEASE_MINOR_VERSION           (3U)
#define PLATFORM_AR_RELEASE_PATCH_VERSION           (1U)

/*
 * CPU register width types
 */
#define CPU_TYPE_8                                  (8U)
#define CPU_TYPE_16                                 (16U)
#define CPU_TYPE_32                                 (32U)

/*
 * Bit Ordering (in Register-Byte-) Definitions
 */
#define MSB_FIRST                   (0u)        /* Big endian */
#define LSB_FIRST                   (1u)        /* Little endian */

/*
 * Byte Ordering (in Memory) Definitions
 */
#define HIGH_BYTE_FIRST             (0u)        /* Big endian */
#define LOW_BYTE_FIRST              (1u)        /* Little endian */

/*
 * CPU type and endianess for AVR
 */
#define CPU_TYPE            CPU_TYPE_8
#define CPU_BIT_ORDER       LSB_FIRST
#define CPU_BYTE_ORDER      LOW_BYTE_FIRST


#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

typedef unsigned char         boolean;
typedef unsigned char         uint8;          
typedef signed char           sint8;          
typedef unsigned short        uint16;         
typedef signed short          sint16;         
typedef unsigned long         uint32;         
typedef signed long           sint32;         
typedef unsigned long long    uint64;         
typedef signed long long      sint64;
typedef float                 float32;
typedef double                float64;

#endif /* PLATFORM_TYPES_H */
