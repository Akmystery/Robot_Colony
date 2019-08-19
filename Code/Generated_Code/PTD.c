/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PTD.c
**     Project     : Final Review
**     Processor   : MK20DX256VLK10
**     Component   : Init_GPIO
**     Version     : Component 01.006, Driver 01.06, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-21, 15:59, # CodeGen: 51
**     Abstract    :
**          This file implements the GPIO (PTD) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : PTD
**          Device                                         : PTD
**          Settings                                       : 
**            Pin 0                                        : Initialize
**              Pin direction                              : Input
**              Output value                               : No initialization
**              Open drain                                 : No initialization
**              Pull resistor                              : Enabled
**              Pull selection                             : Pull Up
**              Slew rate                                  : No initialization
**              Drive strength                             : No initialization
**              Interrupt/DMA request                      : No initialization
**              Digital filter                             : No initialization
**              Passive filter                             : No initialization
**              Lock                                       : No initialization
**            Pin 1                                        : Do not initialize
**            Pin 2                                        : Do not initialize
**            Pin 3                                        : Do not initialize
**            Pin 4                                        : Do not initialize
**            Pin 5                                        : Do not initialize
**            Pin 6                                        : Do not initialize
**            Pin 7                                        : Do not initialize
**            Digital filter clock source                  : Bus clock
**            Digital filter width                         : 0
**          Pin selection/routing                          : 
**            Pin 0                                        : Enabled
**              Pin                                        : PTD0/LLWU_P12/SPI0_PCS0/UART2_RTS_b/FB_ALE/FB_CS1_b/FB_TS_b
**              Pin signal                                 : 
**            Pin 1                                        : Disabled
**            Pin 2                                        : Disabled
**            Pin 3                                        : Disabled
**            Pin 4                                        : Disabled
**            Pin 5                                        : Disabled
**            Pin 6                                        : Disabled
**            Pin 7                                        : Disabled
**          Interrupts                                     : 
**            Port interrupt                               : Enabled
**              Interrupt                                  : INT_PORTD
**              Interrupt request                          : Disabled
**              Interrupt priority                         : 0 (Highest)
**              ISR Name                                   : 
**          Initialization                                 : 
**            Call Init method                             : yes
**     Contents    :
**         Init - void PTD_Init(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file PTD.c
** @version 01.06
** @brief
**          This file implements the GPIO (PTD) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup PTD_module PTD module documentation
**  @{
*/         

/* MODULE PTD. */

#include "PTD.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  PTD_Init (component Init_GPIO)
**     Description :
**         This method initializes registers of the GPIO module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void PTD_Init(void)
{
  /* GPIOD_PDDR: PDD&=~1 */
  GPIOD_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(0x01));
}


/* END PTD. */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
