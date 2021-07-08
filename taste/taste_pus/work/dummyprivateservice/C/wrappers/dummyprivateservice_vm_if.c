/* Body file for function DummyPrivateService
 * Generated by TASTE on 2021-07-08 16:59:21
 * Provided interfaces : forwardTc
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 134437 32417 177819 47196
 * Timers              : 
 */
#include "dummyprivateservice_vm_if.h"
#include "C_ASN1_Types.h"
#ifdef __unix__
   #include <stdio.h>
#endif




unsigned dummyprivateservice_initialized = 0;
void init_dummyprivateservice(void)
{
   if (!dummyprivateservice_initialized) {
      dummyprivateservice_initialized = 1;
      // Call user code startup function
      dummyprivateservice_startup();
#ifdef __unix__
      puts ("[TASTE] Initialization completed for function DummyPrivateService");
#endif
      dummyprivateservice_initialized = 2;
   }
}
void dummyprivateservice_forwardTc
      (const char *IN_tcpacket, size_t IN_tcpacket_len)

{

   static asn1SccPusPacket IN_TCPACKET;
#ifdef __unix__
   asn1SccPusPacket_Initialize(&IN_TCPACKET);
#endif
   if (0 != Decode_NATIVE_PusPacket (&IN_TCPACKET, (void *)IN_tcpacket, IN_tcpacket_len)) {
      #ifdef __unix__
         puts("Error decoding PusPacket in function DummyPrivateService_forwardTc");
      #endif
      return;
   }

   //  Declare user code function as external (it may not have a .h if it is in Ada)
   extern void dummyprivateservice_PI_forwardTc
      (const asn1SccPusPacket *);




   // Call user code
   dummyprivateservice_PI_forwardTc (&IN_TCPACKET);

}

