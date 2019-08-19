/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : LPTMR0.h
**     Project     : Final Review
**     Processor   : MK20DX256VLK10
**     Component   : Init_LPTMR
**     Version     : Component 01.011, Driver 01.11, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-21, 15:59, # CodeGen: 51
**     Abstract    :
**          This file implements the LPTMR (LPTMR0) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : LPTMR0
**          Device                                         : LPTMR0
**          Settings                                       : 
**            Clock gate                                   : Enabled
**            Clock settings                               : 
**              Clock select                               : Internal Reference Clock
**              Prescale value/Glitch filter               : Prescaler/2; Glitch Filter not supported
**              Prescaler bypass                           : Bypassed
**            Compare value                                : 0
**            Free running                                 : Enabled
**            Timer mode                                   : Timer Counter
**              Input clock frequency                      : 32.768 kHz
**              Period                                     : 2000.0000 ms
**          Pins                                           : 
**            Input pin                                    : Disabled
**            Pin polarity                                 : Active High
**          Interrupts                                     : 
**            Interrupt                                    : INT_LPTimer
**            Interrupt request                            : Disabled
**            Interrupt priority                           : 0 (Highest)
**            ISR name                                     : 
**            Timer interrupt                              : Disabled
**          Initialization                                 : 
**            Timer enable                                 : yes
**            Call Init method                             : yes
**     Contents    :
**         Init - void LPTMR0_Init(void);
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
** @file LPTMR0.h
** @version 01.11
** @brief
**          This file implements the LPTMR (LPTMR0) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup LPTMR0_module LPTMR0 module documentation
**  @{
*/         

#ifndef LPTMR0_H_
#define LPTMR0_H_

/* MODULE LPTMR0. */

/* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

/* Peripheral base address parameter */
#define LPTMR0_DEVICE LPTMR0_BASE_PTR


/*
** ===================================================================
**     Method      :  LPTMR0_Init (component Init_LPTMR)
**     Description :
**         This method initializes registers of the LPTMR module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LPTMR0_Init(void);


/* END LPTMR0. */
#endif /* #ifndef __LPTMR0_H_ */
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
