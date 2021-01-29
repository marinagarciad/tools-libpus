/* Body file for function Function1
 * Generated by TASTE on 2020-06-16 11:29:05
 * You can edit this file, it will not be overwritten
 * Provided interfaces : hola
 * Required interfaces : 
 * User-defined properties for this function:
 *   |_ Taste::Active_Interfaces = any
 *   |_ Taste::coordinates = 88257 34335 117598 52049
 * Timers              : 
 */

#include "function1.h"
//#include <stdio.h>

#include "pus_apid.h"
#include "pus_error.h"
#include "pus_packet.h"
#include "pus_time.h"

// PUS INCLUDES
#include "pus_housekeeping.h"
#include "pus_parameter_management.h"
#include "pus_events.h"
#include "pus_st08_packets.h"
#include "pus_obcp_engine.h"

#include <unistd.h>


//Scripts
#include "code.mpy.h"

void function1_startup(void)
{
   // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
   // puts ("[Function1] Startup");
   pusPacket_t tc;
	pusPacket_t tm;
	pusTime_t tv, now;
	pusApidInfo_t apid;

	pus_initApidInfo(&apid, 33, NULL);
   pus_setTcSource(&tc, 11);
	pus_setSequenceCount(&tc, 22);

   pus_obcp_initialize(NULL);
	pus_obcp_startEngine();


	pusSt18ObcpId_t id1 ,id2;
	memcpy(id1.arr, "OBCP_1\0", 10);
	memcpy(id2.arr, "OBCP_2\0", 10);

	pusSt18ObcpCode_t code1;
	memcpy(code1.arr, mpy_script_data[0], mpy_script_len[0]);
	code1.nCount = mpy_script_len[0];
	pus_obcp_loadObcp(&id1, &code1);

	memcpy(code1.arr, mpy_script_data[1], mpy_script_len[1]);
	code1.nCount = mpy_script_len[1];
	pus_obcp_loadObcp(&id2, &code1);

	printf("\n-------------\n");
	pus_obcp_activateObcp(&id1);
	pus_obcp_activateObcp(&id2);


	sleep(3); //wait to the end of the test
	pus_obcp_unloadObcp(&id1);
	pus_obcp_unloadObcp(&id2);
	printf("-------------\n");
}

void function1_PI_hola(void)
{
   // Write your code here
}


