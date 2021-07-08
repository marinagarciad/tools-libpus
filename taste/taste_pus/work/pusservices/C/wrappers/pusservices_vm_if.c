/* Body file for function PusServices
 * Generated by TASTE on 2021-07-08 16:59:21
 * Provided interfaces : ack, addTc, addTm, getOnBoardParam, getParamValue, newTc, pushNewEvent, setOnBoardParam, setParamValue, trigger
 * Required interfaces : forwardTc, newTm
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 133885 62204 179396 91179
 * Timers              : 
 */
#include "pusservices_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




extern void init_dummyprivateservice(void);
extern unsigned dummyprivateservice_initialized;
unsigned pusservices_initialized = 0;
void init_pusservices(void)
{
   if (!pusservices_initialized) {
      pusservices_initialized = 1;
      // Call user code startup function
      pusservices_startup();
      // Iterate over all synchronous RIs, and call their parent's
      // init function. Multiple calls are prevented by the "init" guard.
      if (0 == dummyprivateservice_initialized) {
          init_dummyprivateservice();
      }
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function PusServices");
#endif
      pusservices_initialized = 2;
   }
}
void pusservices_ack
      (const char *IN_tcpacket, size_t IN_tcpacket_len,
       const char *IN_reporttype, size_t IN_reporttype_len,
       const char *IN_error, size_t IN_error_len,
       const char *IN_errorinfo, size_t IN_errorinfo_len,
       const char *IN_step, size_t IN_step_len)

{

   static asn1SccPusPacket IN_TCPACKET;
#ifdef __unix__
   asn1SccPusPacket_Initialize(&IN_TCPACKET);
#endif
   if (0 != Decode_NATIVE_PusPacket (&IN_TCPACKET, (void *)IN_tcpacket, IN_tcpacket_len)) {
      #ifdef __unix__
         puts("Error decoding PusPacket in function PusServices_ack");
      #endif
      return;
   }
   static asn1SccPusSubserviceType IN_REPORTTYPE;
#ifdef __unix__
   asn1SccPusSubserviceType_Initialize(&IN_REPORTTYPE);
#endif
   if (0 != Decode_NATIVE_PusSubserviceType (&IN_REPORTTYPE, (void *)IN_reporttype, IN_reporttype_len)) {
      #ifdef __unix__
         puts("Error decoding PusSubserviceType in function PusServices_ack");
      #endif
      return;
   }
   static asn1SccPusSt01FailureCode IN_ERROR;
#ifdef __unix__
   asn1SccPusSt01FailureCode_Initialize(&IN_ERROR);
#endif
   if (0 != Decode_NATIVE_PusSt01FailureCode (&IN_ERROR, (void *)IN_error, IN_error_len)) {
      #ifdef __unix__
         puts("Error decoding PusSt01FailureCode in function PusServices_ack");
      #endif
      return;
   }
   static asn1SccPusSt01FailureInfo IN_ERRORINFO;
#ifdef __unix__
   asn1SccPusSt01FailureInfo_Initialize(&IN_ERRORINFO);
#endif
   if (0 != Decode_NATIVE_PusSt01FailureInfo (&IN_ERRORINFO, (void *)IN_errorinfo, IN_errorinfo_len)) {
      #ifdef __unix__
         puts("Error decoding PusSt01FailureInfo in function PusServices_ack");
      #endif
      return;
   }
   static asn1SccPusStepId IN_STEP;
#ifdef __unix__
   asn1SccPusStepId_Initialize(&IN_STEP);
#endif
   if (0 != Decode_NATIVE_PusStepId (&IN_STEP, (void *)IN_step, IN_step_len)) {
      #ifdef __unix__
         puts("Error decoding PusStepId in function PusServices_ack");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void pusservices_PI_ack
      (const asn1SccPusPacket *,
       const asn1SccPusSubserviceType *,
       const asn1SccPusSt01FailureCode *,
       const asn1SccPusSt01FailureInfo *,
       const asn1SccPusStepId *);




   // Call user code
   pusservices_PI_ack (&IN_TCPACKET, &IN_REPORTTYPE, &IN_ERROR, &IN_ERRORINFO, &IN_STEP);

}
void pusservices_addTc
      (const char *IN_tcpacket, size_t IN_tcpacket_len)

{

   static asn1SccPusPacket IN_TCPACKET;
#ifdef __unix__
   asn1SccPusPacket_Initialize(&IN_TCPACKET);
#endif
   if (0 != Decode_NATIVE_PusPacket (&IN_TCPACKET, (void *)IN_tcpacket, IN_tcpacket_len)) {
      #ifdef __unix__
         puts("Error decoding PusPacket in function PusServices_addTc");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void pusservices_PI_addTc
      (const asn1SccPusPacket *);




   // Call user code
   pusservices_PI_addTc (&IN_TCPACKET);

}
void pusservices_addTm
      (const char *IN_tmpacket, size_t IN_tmpacket_len)

{

   static asn1SccPusPacket IN_TMPACKET;
#ifdef __unix__
   asn1SccPusPacket_Initialize(&IN_TMPACKET);
#endif
   if (0 != Decode_NATIVE_PusPacket (&IN_TMPACKET, (void *)IN_tmpacket, IN_tmpacket_len)) {
      #ifdef __unix__
         puts("Error decoding PusPacket in function PusServices_addTm");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void pusservices_PI_addTm
      (const asn1SccPusPacket *);




   // Call user code
   pusservices_PI_addTm (&IN_TMPACKET);

}
void pusservices_getOnBoardParam
      (const char *IN_paramid, size_t IN_paramid_len,
       char *OUT_paramvalue, size_t *OUT_paramvalue_len,
       char *OUT_isavailable, size_t *OUT_isavailable_len)

{

   static asn1SccPusSt20OnBoardParameterId IN_PARAMID;
#ifdef __unix__
   asn1SccPusSt20OnBoardParameterId_Initialize(&IN_PARAMID);
#endif
   if (0 != Decode_NATIVE_PusSt20OnBoardParameterId (&IN_PARAMID, (void *)IN_paramid, IN_paramid_len)) {
      #ifdef __unix__
         puts("Error decoding PusSt20OnBoardParameterId in function PusServices_getOnBoardParam");
      #endif
      return;
   }
   static asn1SccPusSt20StoredParam OUT_PARAMVALUE;
#ifdef __unix__
   asn1SccPusSt20StoredParam_Initialize(&OUT_PARAMVALUE);
#endif
   static asn1SccPusSt01FailureCode OUT_ISAVAILABLE;
#ifdef __unix__
   asn1SccPusSt01FailureCode_Initialize(&OUT_ISAVAILABLE);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void pusservices_PI_getOnBoardParam
      (const asn1SccPusSt20OnBoardParameterId *,
       asn1SccPusSt20StoredParam *,
       asn1SccPusSt01FailureCode *);




   // Call user code
   pusservices_PI_getOnBoardParam (&IN_PARAMID, &OUT_PARAMVALUE, &OUT_ISAVAILABLE);

   *OUT_paramvalue_len = Encode_NATIVE_PusSt20StoredParam
      ((void *)OUT_paramvalue,
       sizeof (asn1SccPusSt20StoredParam),
       &OUT_PARAMVALUE);
   *OUT_isavailable_len = Encode_NATIVE_PusSt01FailureCode
      ((void *)OUT_isavailable,
       sizeof (asn1SccPusSt01FailureCode),
       &OUT_ISAVAILABLE);
}
void pusservices_getParamValue
      (const char *IN_paramid, size_t IN_paramid_len,
       char *OUT_paramvalue, size_t *OUT_paramvalue_len,
       char *OUT_isavailable, size_t *OUT_isavailable_len)

{

   static asn1SccPusSt03ParameterId IN_PARAMID;
#ifdef __unix__
   asn1SccPusSt03ParameterId_Initialize(&IN_PARAMID);
#endif
   if (0 != Decode_NATIVE_PusSt03ParameterId (&IN_PARAMID, (void *)IN_paramid, IN_paramid_len)) {
      #ifdef __unix__
         puts("Error decoding PusSt03ParameterId in function PusServices_getParamValue");
      #endif
      return;
   }
   static asn1SccPusSt03StoredParam OUT_PARAMVALUE;
#ifdef __unix__
   asn1SccPusSt03StoredParam_Initialize(&OUT_PARAMVALUE);
#endif
   static asn1SccPusSt01FailureCode OUT_ISAVAILABLE;
#ifdef __unix__
   asn1SccPusSt01FailureCode_Initialize(&OUT_ISAVAILABLE);
#endif

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void pusservices_PI_getParamValue
      (const asn1SccPusSt03ParameterId *,
       asn1SccPusSt03StoredParam *,
       asn1SccPusSt01FailureCode *);




   // Call user code
   pusservices_PI_getParamValue (&IN_PARAMID, &OUT_PARAMVALUE, &OUT_ISAVAILABLE);

   *OUT_paramvalue_len = Encode_NATIVE_PusSt03StoredParam
      ((void *)OUT_paramvalue,
       sizeof (asn1SccPusSt03StoredParam),
       &OUT_PARAMVALUE);
   *OUT_isavailable_len = Encode_NATIVE_PusSt01FailureCode
      ((void *)OUT_isavailable,
       sizeof (asn1SccPusSt01FailureCode),
       &OUT_ISAVAILABLE);
}
void pusservices_newTc
      (const char *IN_tcpacket, size_t IN_tcpacket_len)

{

   static asn1SccPusPacket IN_TCPACKET;
#ifdef __unix__
   asn1SccPusPacket_Initialize(&IN_TCPACKET);
#endif
   if (0 != Decode_NATIVE_PusPacket (&IN_TCPACKET, (void *)IN_tcpacket, IN_tcpacket_len)) {
      #ifdef __unix__
         puts("Error decoding PusPacket in function PusServices_newTc");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void pusservices_PI_newTc
      (const asn1SccPusPacket *);




   // Call user code
   pusservices_PI_newTc (&IN_TCPACKET);

}
void pusservices_pushNewEvent
      (const char *IN_eveninfo, size_t IN_eveninfo_len)

{

   static asn1SccPusSt05Event IN_EVENINFO;
#ifdef __unix__
   asn1SccPusSt05Event_Initialize(&IN_EVENINFO);
#endif
   if (0 != Decode_NATIVE_PusSt05Event (&IN_EVENINFO, (void *)IN_eveninfo, IN_eveninfo_len)) {
      #ifdef __unix__
         puts("Error decoding PusSt05Event in function PusServices_pushNewEvent");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void pusservices_PI_pushNewEvent
      (const asn1SccPusSt05Event *);




   // Call user code
   pusservices_PI_pushNewEvent (&IN_EVENINFO);

}
void pusservices_setOnBoardParam
      (const char *IN_paramid, size_t IN_paramid_len,
       const char *IN_paramvalue, size_t IN_paramvalue_len)

{

   static asn1SccPusSt20OnBoardParameterId IN_PARAMID;
#ifdef __unix__
   asn1SccPusSt20OnBoardParameterId_Initialize(&IN_PARAMID);
#endif
   if (0 != Decode_NATIVE_PusSt20OnBoardParameterId (&IN_PARAMID, (void *)IN_paramid, IN_paramid_len)) {
      #ifdef __unix__
         puts("Error decoding PusSt20OnBoardParameterId in function PusServices_setOnBoardParam");
      #endif
      return;
   }
   static asn1SccPusSt20StoredParam IN_PARAMVALUE;
#ifdef __unix__
   asn1SccPusSt20StoredParam_Initialize(&IN_PARAMVALUE);
#endif
   if (0 != Decode_NATIVE_PusSt20StoredParam (&IN_PARAMVALUE, (void *)IN_paramvalue, IN_paramvalue_len)) {
      #ifdef __unix__
         puts("Error decoding PusSt20StoredParam in function PusServices_setOnBoardParam");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void pusservices_PI_setOnBoardParam
      (const asn1SccPusSt20OnBoardParameterId *,
       const asn1SccPusSt20StoredParam *);




   // Call user code
   pusservices_PI_setOnBoardParam (&IN_PARAMID, &IN_PARAMVALUE);

}
void pusservices_setParamValue
      (const char *IN_paramid, size_t IN_paramid_len,
       const char *IN_paramvalue, size_t IN_paramvalue_len)

{

   static asn1SccPusSt03ParameterId IN_PARAMID;
#ifdef __unix__
   asn1SccPusSt03ParameterId_Initialize(&IN_PARAMID);
#endif
   if (0 != Decode_NATIVE_PusSt03ParameterId (&IN_PARAMID, (void *)IN_paramid, IN_paramid_len)) {
      #ifdef __unix__
         puts("Error decoding PusSt03ParameterId in function PusServices_setParamValue");
      #endif
      return;
   }
   static asn1SccPusSt03StoredParam IN_PARAMVALUE;
#ifdef __unix__
   asn1SccPusSt03StoredParam_Initialize(&IN_PARAMVALUE);
#endif
   if (0 != Decode_NATIVE_PusSt03StoredParam (&IN_PARAMVALUE, (void *)IN_paramvalue, IN_paramvalue_len)) {
      #ifdef __unix__
         puts("Error decoding PusSt03StoredParam in function PusServices_setParamValue");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void pusservices_PI_setParamValue
      (const asn1SccPusSt03ParameterId *,
       const asn1SccPusSt03StoredParam *);




   // Call user code
   pusservices_PI_setParamValue (&IN_PARAMID, &IN_PARAMVALUE);

}
void pusservices_trigger()
{
   //  Directly call user code, no parameters to pass
   extern void pusservices_PI_trigger(void);
   pusservices_PI_trigger();
   // puts ("pusservices_trigger called");
}

