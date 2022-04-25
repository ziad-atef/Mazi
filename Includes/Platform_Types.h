/******************************************************************************
 *
 * Module name: Platform Types
 *
 * File Name: Platform_Types.h
 *
 * Description: Platform types for ARM Cortex-M4F
 *
 * Author: Electerical Vehicle team 2021.
 *
 *******************************************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H


/*
 * Boolean Values
 */
#ifndef FALSE
#define FALSE                                       (0U)
#endif
#ifndef TRUE
#define TRUE                                        (1U)
#endif


typedef unsigned char           boolean;

typedef signed char             sint8;
typedef unsigned char           uint8;
typedef signed short            sint16;
typedef unsigned short          uint16;
typedef signed long             sint32;
typedef signed long long        sint64;
typedef unsigned long           uint32;
typedef unsigned long long      uint64;

typedef signed long             sint8_least;
typedef unsigned long           uint8_least;
typedef signed long             sint16_least;
typedef unsigned long           uint16_least;
typedef signed long             sint32_least;
typedef unsigned long           uint32_least;
typedef float                   float32;
typedef double                  float64; 

#endif /* PLATFORM_TYPES_H */

