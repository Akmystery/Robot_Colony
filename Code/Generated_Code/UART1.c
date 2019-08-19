/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : UART1.c
**     Project     : Final Review
**     Processor   : MK20DX256VLK10
**     Component   : Init_UART
**     Version     : Component 01.006, Driver 01.06, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-21, 15:59, # CodeGen: 51
**     Abstract    :
**          This file implements the UART (UART1) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : UART1
**          Device                                         : UART1
**          Settings                                       : 
**            Clock gate                                   : Enabled
**            Clock settings                               : 
**              Baud rate divisor                          : 1
**              Baud rate fine adjust                      : 10
**              Baud rate                                  : 998643.810 baud
**            Transfer settings                            : 
**              Data format                                : 8bit
**              Bits ordering                              : LSB first
**              Parity                                     : Off
**              Parity placement                           : Parity in last data bit
**            Idle character counting                      : After start bit
**            Break character generation length            : Short
**            LIN Break detection                          : Disabled
**            Stop in Wait mode                            : Disabled
**            Receiver wakeup settings                     : 
**              Receiver wakeup                            : Normal operation
**              Receiver wake up method                    : Idle-line
**              Receive wakeup idle detect                 : Don't set IDLE bit
**              Match address settings                     : 
**                Match address 1                          : Disabled
**                Match address 1 value                    : 0
**                Match address 2                          : Disabled
**                Match address 2 value                    : 0
**            Modem settings                               : 
**              Tx CTS                                     : Disabled
**              Tx RTS                                     : Disabled
**              Tx RTS polarity                            : Active low
**              Rx RTS                                     : Disabled
**            Infrared settings                            : 
**              Infrared                                   : Disabled
**              Tx narrow pulse width                      : 3/16
**            FIFOs settings                               : 
**              Tx FIFO                                    : Disabled
**              Tx watermark                               : 0
**              Rx FIFO                                    : Disabled
**              Rx watermark                               : 1
**            Loops and Single wire settings               : 
**              Loop mode                                  : Disabled
**              Receiver source in Loop mode               : Loop mode
**              TxD pin direction in Single-wire mode      : Input
**            Receiver input                               : Not inverted
**            Transmitter output                           : Not inverted
**          Pins/Signals                                   : 
**            Receiver pin                                 : Enabled
**              Pin                                        : CMP1_IN1/PTC3/LLWU_P7/SPI0_PCS1/UART1_RX/FTM0_CH2/CLKOUTa/I2S0_TX_BCLK
**              Pin signal                                 : 
**            Transmitter pin                              : Enabled
**              Pin                                        : PTC4/LLWU_P8/SPI0_PCS0/UART1_TX/FTM0_CH3/FB_AD11/CMP1_OUT
**              Pin signal                                 : 
**              Transmitter modulation                     : Disabled
**            CTS pin                                      : Disabled
**            RTS pin                                      : Disabled
**          Interrupts/DMA                                 : 
**            Common Tx/Rx interrupt                       : 
**              Interrupt                                  : INT_UART1_RX_TX
**              Interrupt request                          : Enabled
**              Interrupt priority                         : 0 (Highest)
**              ISR name                                   : uart1isr
**              Transmit empty request                     : Disabled
**              Transmit empty request type                : IRQ
**              Transmit complete request                  : Disabled
**              Receiver full request                      : Disabled
**              Receiver full request type                 : IRQ
**              Idle line request                          : Disabled
**              LIN break detect request                   : Disabled
**              Rx active edge interrupt                   : Disabled
**            Error Interrupt                              : 
**              Error interrupt                            : INT_UART1_ERR
**              Interrupt request                          : Disabled
**              Interrupt priority                         : 0 (Highest)
**              ISR name                                   : 
**              Overrun error interrupt                    : Disabled
**              Noise error interrupt                      : Disabled
**              Framing error interrupt                    : Disabled
**              Parity error interrupt                     : Disabled
**              FIFOs interrupts                           : 
**                Tx FIFO overflow interrupt               : Disabled
**                Rx FIFO underflow interrupt              : Disabled
**                Rx FIFO overflow interrupt               : Disabled
**          Initialization                                 : 
**            Send break                                   : Disabled
**            Enable transmitter                           : Enabled
**            Enable receiver                              : Enabled
**            Call Init method                             : yes
**     Contents    :
**         Init - void UART1_Init(void);
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
** @file UART1.c
** @version 01.06
** @brief
**          This file implements the UART (UART1) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup UART1_module UART1 module documentation
**  @{
*/         

/* MODULE UART1. */

#include "UART1.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  UART1_Init (component Init_UART)
**     Description :
**         This method initializes registers of the UART module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void UART1_Init(void)
{
  /* SIM_SCGC4: UART1=1 */
  SIM_SCGC4 |= SIM_SCGC4_UART1_MASK;
  /* UART1_C2: TE=0,RE=0 */
  UART1_C2 &= (uint8_t)~(uint8_t)((UART_C2_TE_MASK | UART_C2_RE_MASK));
  /* UART1_BDH: LBKDIE=0,RXEDGIE=0,??=0,SBR=0 */
  UART1_BDH = UART_BDH_SBR(0x00);
  /* UART1_BDL: SBR=1 */
  UART1_BDL = UART_BDL_SBR(0x01);
  /* UART1_MA1: MA=0 */
  UART1_MA1 = UART_MA1_MA(0x00);
  /* UART1_MA2: MA=0 */
  UART1_MA2 = UART_MA2_MA(0x00);
  /* UART1_C4: MAEN1=0,MAEN2=0,M10=0,BRFA=0x0A */
  UART1_C4 = UART_C4_BRFA(0x0A);
  /* UART1_C1: LOOPS=0,UARTSWAI=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
  UART1_C1 = 0x00U;
  /* UART1_S2: LBKDIF=1,RXEDGIF=1,MSBF=0,RXINV=0,RWUID=0,BRK13=0,LBKDE=0,RAF=0 */
  UART1_S2 = (UART_S2_LBKDIF_MASK | UART_S2_RXEDGIF_MASK);
  /* UART1_MODEM: ??=0,??=0,??=0,??=0,RXRTSE=0,TXRTSPOL=0,TXRTSE=0,TXCTSE=0 */
  UART1_MODEM = 0x00U;
  /* UART1_IR: ??=0,??=0,??=0,??=0,??=0,IREN=0,TNP=0 */
  UART1_IR = UART_IR_TNP(0x00);
  /* UART1_TWFIFO: TXWATER=0 */
  UART1_TWFIFO = UART_TWFIFO_TXWATER(0x00);
  /* UART1_RWFIFO: RXWATER=1 */
  UART1_RWFIFO = UART_RWFIFO_RXWATER(0x01);
  /* UART1_SFIFO: TXEMPT=1,RXEMPT=1,??=0,??=0,??=0,RXOF=1,TXOF=1,RXUF=1 */
  UART1_SFIFO = UART_SFIFO_TXEMPT_MASK |
                UART_SFIFO_RXEMPT_MASK |
                UART_SFIFO_RXOF_MASK |
                UART_SFIFO_TXOF_MASK |
                UART_SFIFO_RXUF_MASK;
  /* UART1_CFIFO: TXFLUSH=1,RXFLUSH=1,??=0,??=0,??=0,RXOFE=0,TXOFE=0,RXUFE=0 */
  UART1_CFIFO = (UART_CFIFO_TXFLUSH_MASK | UART_CFIFO_RXFLUSH_MASK);
  /* UART1_PFIFO: TXFE=0,RXFE=0 */
  UART1_PFIFO &= (uint8_t)~(uint8_t)(
                  UART_PFIFO_TXFE_MASK |
                  UART_PFIFO_RXFE_MASK
                 );
    (void) UART1_S1;                   /* Dummy read of the UART1_S1 register to clear flags */
    (void) UART1_D;                    /* Dummy read of the UART1_D register to clear flags */
  /* UART1_C5: TDMAS=0,??=0,RDMAS=0,??=0,??=0,??=0,??=0 */
  UART1_C5 &= (uint8_t)~(uint8_t)(
               UART_C5_TDMAS_MASK |
               UART_C5_RDMAS_MASK |
               0x4FU
              );
  /* UART1_C3: R8=0,T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0 */
  UART1_C3 = 0x00U;
  /* UART1_C2: TIE=0,TCIE=0,RIE=0,ILIE=0,TE=1,RE=1,RWU=0,SBK=0 */
  UART1_C2 = (UART_C2_TE_MASK | UART_C2_RE_MASK);
}

/*
** ###################################################################
**
**  The interrupt service routine(s) must be implemented
**  by user in one of the following user modules.
**
**  If the "Generate ISR" option is enabled, Processor Expert generates
**  ISR templates in the CPU event module.
**
**  User modules:
**      main.c
**      Events.c
**
** ###################################################################
PE_ISR(uart1isr)
{
// NOTE: The routine should include actions to clear the appropriate
//       interrupt flags.
//
}
*/


/* END UART1. */
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