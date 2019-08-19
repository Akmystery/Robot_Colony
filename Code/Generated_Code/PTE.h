/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PTE.h
**     Project     : Final Review
**     Processor   : MK20DX256VLK10
**     Component   : Init_GPIO
**     Version     : Component 01.006, Driver 01.06, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-29, 10:09, # CodeGen: 62
**     Abstract    :
**          This file implements the GPIO (PTE) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : PTE
**          Device                                         : PTE
**          Settings                                       : 
**            Pin 0                                        : Do not initialize
**            Pin 1                                        : Do not initialize
**            Pin 2                                        : Initialize
**              Pin direction                              : Output
**              Output value                               : 1
**              Open drain                                 : No initialization
**              Pull resistor                              : No initialization
**              Pull selection                             : No initialization
**              Slew rate                                  : No initialization
**              Drive strength                             : No initialization
**              Interrupt/DMA request                      : No initialization
**              Digital filter                             : No initialization
**              Passive filter                             : No initialization
**              Lock                                       : No initialization
**            Pin 3                                        : Initialize
**              Pin direction                              : Output
**              Output value                               : 0
**              Open drain                                 : No initialization
**              Pull resistor                              : No initialization
**              Pull selection                             : No initialization
**              Slew rate                                  : No initialization
**              Drive strength                             : No initialization
**              Interrupt/DMA request                      : No initialization
**              Digital filter                             : No initialization
**              Passive filter                             : No initialization
**              Lock                                       : No initialization
**            Pin 4                                        : Initialize
**              Pin direction                              : Output
**              Output value                               : 0
**              Open drain                                 : No initialization
**              Pull resistor                              : No initialization
**              Pull selection                             : No initialization
**              Slew rate                                  : No initialization
**              Drive strength                             : No initialization
**              Interrupt/DMA request                      : No initialization
**              Digital filter                             : No initialization
**              Passive filter                             : No initialization
**              Lock                                       : No initialization
**            Pin 5                                        : Initialize
**              Pin direction                              : Output
**              Output value                               : 0
**              Open drain                                 : No initialization
**              Pull resistor                              : No initialization
**              Pull selection                             : No initialization
**              Slew rate                                  : No initialization
**              Drive strength                             : No initialization
**              Interrupt/DMA request                      : No initialization
**              Digital filter                             : No initialization
**              Passive filter                             : No initialization
**              Lock                                       : No initialization
**            Digital filter clock source                  : Bus clock
**            Digital filter width                         : 0
**          Pin selection/routing                          : 
**            Pin 0                                        : Disabled
**            Pin 1                                        : Disabled
**            Pin 2                                        : Enabled
**              Pin                                        : ADC1_SE6a/PTE2/LLWU_P1/SPI1_SCK/UART1_CTS_b/SDHC0_DCLK/FB_AD25
**              Pin signal                                 : 
**            Pin 3                                        : Enabled
**              Pin                                        : ADC1_SE7a/PTE3/SPI1_SIN/UART1_RTS_b/SDHC0_CMD/FB_AD24/SPI1_SOUT
**              Pin signal                                 : 
**            Pin 4                                        : Enabled
**              Pin                                        : PTE4/LLWU_P2/SPI1_PCS0/UART3_TX/SDHC0_D3/FB_CS3_b/FB_BE7_0_b/FB_TA_b
**              Pin signal                                 : 
**            Pin 5                                        : Enabled
**              Pin                                        : PTE5/SPI1_PCS2/UART3_RX/SDHC0_D2/FB_TBST_b/FB_CS2_b/FB_BE15_8_b
**              Pin signal                                 : 
**          Interrupts                                     : 
**            Port interrupt                               : Enabled
**              Interrupt                                  : INT_PORTE
**              Interrupt request                          : Disabled
**              Interrupt priority                         : 0 (Highest)
**              ISR Name                                   : 
**          Initialization                                 : 
**            Call Init method                             : yes
**     Contents    :
**         Init - void PTE_Init(void);
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
** @file PTE.h
** @version 01.06
** @brief
**          This file implements the GPIO (PTE) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup PTE_module PTE module documentation
**  @{
*/         

#ifndef PTE_H_
#define PTE_H_

/* MODULE PTE. */

/* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

/* Peripheral base address parameter */
#define PTE_DEVICE PTE_BASE_PTR

/* Peripheral port base address parameter */
#define PTE_PORT_DEVICE PORTE_BASE_PTR



/*
** ===================================================================
**     Method      :  PTE_Init (component Init_GPIO)
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
void PTE_Init(void);


/* END PTE. */
#endif /* #ifndef __PTE_H_ */
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