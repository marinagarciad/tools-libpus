/* Header file for function OnBoardSW in C language
 * Generated by TASTE on 2021-07-08 16:59:21
 * Context Parameters present : NO
 * Provided interfaces : trigger
 * Required interfaces : getOnBoardParam, getParamValue, pushNewEvent, setOnBoardParam, setParamValue
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 199364 64408 238261 91808
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

/* The purpose of this file is to provide a wrapper around the user code,
 * with a single interface that is independent of the implementation language
 * of the function. The parameters of each PI are blackboxes encoded
 * in the form specified in the interface view (Native, uPER, or ACN)
*/

#pragma once
#if defined(__unix__) || defined (__MSP430__)
   #include <stdlib.h>
   #include <stdio.h>
#else
   typedef unsigned size_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include "onboardsw.h"

// Function initialization - calls user startup code of all dependent functions
void init_onboardsw(void);


/* Provided interfaces */
void onboardsw_trigger(void);


#ifdef __cplusplus
}
#endif

