/* Header file for function DummyPrivateService in C language
 * Generated by TASTE on 2021-07-08 16:59:21
 * Context Parameters present : NO
 * Provided interfaces : forwardTc
 * Required interfaces : 
 * User-defined properties for this function:
  *  |_ Taste::Active_Interfaces = any
  *  |_ Taste::coordinates = 134437 32417 177819 47196
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

#include "dummyprivateservice.h"

// Function initialization - calls user startup code of all dependent functions
void init_dummyprivateservice(void);


/* Provided interfaces */
void dummyprivateservice_forwardTc
      (const char *IN_tcpacket, size_t IN_tcpacket_len);


#ifdef __cplusplus
}
#endif

