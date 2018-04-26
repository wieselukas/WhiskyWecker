/*
 * main.c
 *
 *  Created on: 2018 Apr 26 09:12:09
 *  Author: lukas
 */


#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)


int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  TIMER_Start(&TIMER_0);

  while(1U)
  {

  }
}

void Interrupt0_Handler(void){
	/* Acknowledge the period match interrupt*/
	TIMER_ClearEvent(&TIMER_0);

	/* Toggle the LED*/
	DIGITAL_IO_ToggleOutput(&DIGITAL_IO_1_1);

	TIMER_Start(&TIMER_0);
}
