/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : FTM1.c
**     Project     : Final Review
**     Processor   : MK20DX256VLK10
**     Component   : Init_FTM
**     Version     : Component 01.009, Driver 01.09, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-21, 15:59, # CodeGen: 51
**     Abstract    :
**          This file implements the FTM (FTM1) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : FTM1
**          Device                                         : FTM1
**          Settings                                       : 
**            Clock gate                                   : Enabled
**            Clock settings                               : 
**              Clock source                               : No clock
**              Prescaler                                  : divide by 1
**              Counter init                               : 0
**              Modulo counter                             : 0
**              Period                                     : Counter stopped
**              Deadtime                                   : 
**                Deadtime prescaler                       : divide by 1
**                Deadtime value                           : 0
**                Deadtime delay                           : DISABLED
**              Num of timer overflows                     : 0
**            FTM mode                                     : Disabled
**            BDM mode                                     : FTM counter stopped; channels outputs functional
**            Global time base                             : Disabled
**            Global time base output                      : Disabled
**            Write protection                             : Disabled
**            Quadrature decoder                           : 
**              Quadrature decoder                         : Enabled
**              Quadrature decoder mode                    : Phase A / Phase B
**              Phase A input polarity                     : Normal
**              Phase B input polarity                     : Normal
**              Phase A input filter                       : Disabled
**              Phase B input filter                       : Disabled
**            Combined channels                            : 
**              Channels 0 and 1                           : 
**                Complementary mode                       : Disabled
**                Fault control                            : Disabled
**                Synchronization                          : Disabled
**                Deadtime                                 : Disabled
**                Inverting                                : Disabled
**            Synchronization                              : 
**              Synchronization mode                       : Disabled
**                Counter reinitialization                 : Disabled
**              HW trigger mode                            : Enabled
**              CNTIN synchronization                      : Disabled
**              INVCTRL synchronization                    : Disabled
**              SWOCTRL synchronization                    : Disabled
**              Software Trigger                           : Disabled
**              OUTMASK synchronization                    : Disabled
**              Minimum loading point                      : Disabled
**              Maximum loading point                      : Disabled
**            External triggers                            : 
**              Counter init trigger                       : Disabled
**              Channel 0 trigger                          : Disabled
**              Channel 1 trigger                          : Disabled
**            Fault control settings                       : 
**              Fault control mode                         : Disabled
**              Fault input filter value                   : Disabled
**              Fault input 0 filter                       : Disabled
**              Fault input 0 polarity                     : High
**              Fault input 1 filter                       : Disabled
**              Fault input 1 polarity                     : High
**              Fault input 2 filter                       : Disabled
**              Fault input 2 polarity                     : High
**          Channels                                       : 
**            Channel 0                                    : Disabled
**            Channel 1                                    : Disabled
**          Pins                                           : 
**            Fault pins                                   : 
**              Fault pin 0                                : Disabled
**              Fault pin 1                                : Disabled
**              Fault pin 2                                : Disabled
**            External clock pin                           : Disabled
**            Phase A Input pin                            : Enabled
**              Pin                                        : ADC0_SE8/ADC1_SE8/TSI0_CH0/PTB0/LLWU_P5/I2C0_SCL/FTM1_CH0/FTM1_QD_PHA
**              Pin signal                                 : 
**            Phase B Input pin                            : Enabled
**              Pin                                        : ADC0_SE9/ADC1_SE9/TSI0_CH6/PTB1/I2C0_SDA/FTM1_CH1/FTM1_QD_PHB
**              Pin signal                                 : 
**            HW Synchronization triggers                  : 
**              Hardware Trigger 0                         : Disabled
**              Hardware Trigger 1                         : Disabled
**              Hardware Trigger 2                         : Disabled
**          Interrupts                                     : 
**            Channels / Timer overflow / Fault            : 
**              Interrupt                                  : INT_FTM1
**              Interrupt request                          : Disabled
**              Interrupt priority                         : 0 (Highest)
**              ISR Name                                   : 
**              Channels interrupt/DMA                     : See the respective Channel settings
**              Timer overflow interrupt                   : Disabled
**              Fault interrupt                            : Disabled
**          Initialization                                 : 
**            Initialize the Channels Output               : no
**            Load enable                                  : no
**            Channel 0 load select                        : no
**            Channel 1 load select                        : no
**            Call Init method                             : yes
**     Contents    :
**         Init - void FTM1_Init(void);
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
** @file FTM1.c
** @version 01.09
** @brief
**          This file implements the FTM (FTM1) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup FTM1_module FTM1 module documentation
**  @{
*/         

/* MODULE FTM1. */

#include "FTM1.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  FTM1_Init (component Init_FTM)
**     Description :
**         This method initializes registers of the FTM module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void FTM1_Init(void)
{
  /* SIM_SCGC6: FTM1=1 */
  SIM_SCGC6 |= SIM_SCGC6_FTM1_MASK;
  (void)(FTM1_SC == 0U);               /* Dummy read of the FTM1_SC register to clear the interrupt flag */
  /* FTM1_SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TOF=0,TOIE=0,CPWMS=0,CLKS=0,PS=0 */
  FTM1_SC = (FTM_SC_CLKS(0x00) | FTM_SC_PS(0x00)); /* Stop the counter */
  /* FTM1_MODE: WPDIS=1 */
  FTM1_MODE |= FTM_MODE_WPDIS_MASK;    /* Disable write protection */
  /* FTM1_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  FTM1_C0SC = 0x00U;
  /* FTM1_C1SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  FTM1_C1SC = 0x00U;
  /* FTM1_MODE: FTMEN=0 */
  FTM1_MODE &= (uint32_t)~(uint32_t)(FTM_MODE_FTMEN_MASK);
  /* FTM1_INVCTRL: INV0EN=0 */
  FTM1_INVCTRL &= (uint32_t)~(uint32_t)(FTM_INVCTRL_INV0EN_MASK);
  /* FTM1_COMBINE: FAULTEN0=0,SYNCEN0=0,DTEN0=0,COMP0=0 */
  FTM1_COMBINE &= (uint32_t)~(uint32_t)(
                   FTM_COMBINE_FAULTEN0_MASK |
                   FTM_COMBINE_SYNCEN0_MASK |
                   FTM_COMBINE_DTEN0_MASK |
                   FTM_COMBINE_COMP0_MASK
                  );
  /* FTM1_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0 */
  FTM1_C0SC &= (uint32_t)~(uint32_t)(
                FTM_CnSC_CHF_MASK |
                FTM_CnSC_MSB_MASK |
                FTM_CnSC_MSA_MASK |
                FTM_CnSC_ELSB_MASK |
                FTM_CnSC_ELSA_MASK |
                0xFFFFFF02U
               );
  /* FTM1_C1SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0 */
  FTM1_C1SC &= (uint32_t)~(uint32_t)(
                FTM_CnSC_CHF_MASK |
                FTM_CnSC_MSB_MASK |
                FTM_CnSC_MSA_MASK |
                FTM_CnSC_ELSB_MASK |
                FTM_CnSC_ELSA_MASK |
                0xFFFFFF02U
               );
  /* FTM1_OUTINIT: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  FTM1_OUTINIT &= (uint32_t)~(uint32_t)(0xFFFFFF00U);
  /* FTM1_FLTCTRL: FFVAL=0 */
  FTM1_FLTCTRL &= (uint32_t)~(uint32_t)(FTM_FLTCTRL_FFVAL(0x0F));
  /* FTM1_FLTPOL: FLT2POL=0,FLT1POL=0,FLT0POL=0 */
  FTM1_FLTPOL &= (uint32_t)~(uint32_t)(
                  FTM_FLTPOL_FLT2POL_MASK |
                  FTM_FLTPOL_FLT1POL_MASK |
                  FTM_FLTPOL_FLT0POL_MASK
                 );
  /* FTM1_FLTCTRL: FFLTR2EN=0,FFLTR1EN=0,FFLTR0EN=0,FAULT2EN=0,FAULT1EN=0,FAULT0EN=0 */
  FTM1_FLTCTRL &= (uint32_t)~(uint32_t)(
                   FTM_FLTCTRL_FFLTR2EN_MASK |
                   FTM_FLTCTRL_FFLTR1EN_MASK |
                   FTM_FLTCTRL_FFLTR0EN_MASK |
                   FTM_FLTCTRL_FAULT2EN_MASK |
                   FTM_FLTCTRL_FAULT1EN_MASK |
                   FTM_FLTCTRL_FAULT0EN_MASK
                  );
  /* FTM1_SYNC: SWSYNC=0,TRIG2=0,TRIG1=0,TRIG0=0,SYNCHOM=0,REINIT=0,CNTMAX=0,CNTMIN=0 */
  FTM1_SYNC &= (uint32_t)~(uint32_t)(
                FTM_SYNC_SWSYNC_MASK |
                FTM_SYNC_TRIG2_MASK |
                FTM_SYNC_TRIG1_MASK |
                FTM_SYNC_TRIG0_MASK |
                FTM_SYNC_SYNCHOM_MASK |
                FTM_SYNC_REINIT_MASK |
                FTM_SYNC_CNTMAX_MASK |
                FTM_SYNC_CNTMIN_MASK
               );
  /* FTM1_EXTTRIG: INITTRIGEN=0,CH1TRIG=0,CH0TRIG=0 */
  FTM1_EXTTRIG &= (uint32_t)~(uint32_t)(
                   FTM_EXTTRIG_INITTRIGEN_MASK |
                   FTM_EXTTRIG_CH1TRIG_MASK |
                   FTM_EXTTRIG_CH0TRIG_MASK
                  );
  /* FTM1_MOD: MOD=0 */
  FTM1_MOD &= (uint32_t)~(uint32_t)(FTM_MOD_MOD(0xFFFF));
  /* FTM1_CNTIN: INIT=0 */
  FTM1_CNTIN &= (uint32_t)~(uint32_t)(FTM_CNTIN_INIT(0xFFFF));
  /* FTM1_DEADTIME: DTPS=0,DTVAL=0 */
  FTM1_DEADTIME &= (uint32_t)~(uint32_t)(
                    FTM_DEADTIME_DTPS(0x03) |
                    FTM_DEADTIME_DTVAL(0x3F)
                   );
  /* FTM1_CNT: COUNT=0 */
  FTM1_CNT &= (uint32_t)~(uint32_t)(FTM_CNT_COUNT(0xFFFF));
  /* FTM1_MODE: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,FAULTIE=0,FAULTM=0,PWMSYNC=0,INIT=0,FTMEN=0 */
  FTM1_MODE &= (uint32_t)~(uint32_t)(
                FTM_MODE_FAULTIE_MASK |
                FTM_MODE_FAULTM(0x03) |
                FTM_MODE_PWMSYNC_MASK |
                FTM_MODE_INIT_MASK |
                FTM_MODE_FTMEN_MASK |
                0xFFFFFF00U
               );
  /* FTM1_SYNCONF: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,SYNCMODE=0,??=0,SWOC=0,INVC=0,??=0,CNTINC=0,??=0,HWTRIGMODE=0 */
  FTM1_SYNCONF &= (uint32_t)~(uint32_t)(
                   FTM_SYNCONF_SYNCMODE_MASK |
                   FTM_SYNCONF_SWOC_MASK |
                   FTM_SYNCONF_INVC_MASK |
                   FTM_SYNCONF_CNTINC_MASK |
                   FTM_SYNCONF_HWTRIGMODE_MASK |
                   0xFFE0E04AU
                  );
  /* FTM1_SC: TOF=0,TOIE=0,CLKS=0,PS=0 */
  FTM1_SC &= (uint32_t)~(uint32_t)(
              FTM_SC_TOF_MASK |
              FTM_SC_TOIE_MASK |
              FTM_SC_CLKS(0x03) |
              FTM_SC_PS(0x07)
             );
  /* FTM1_FMS: FAULTF=0,WPEN=0,FAULTF3=0,FAULTF2=0,FAULTF1=0,FAULTF0=0 */
  FTM1_FMS &= (uint32_t)~(uint32_t)(
               FTM_FMS_FAULTF_MASK |
               FTM_FMS_WPEN_MASK |
               FTM_FMS_FAULTF3_MASK |
               FTM_FMS_FAULTF2_MASK |
               FTM_FMS_FAULTF1_MASK |
               FTM_FMS_FAULTF0_MASK
              );
  /* FTM1_QDCTRL: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,PHAFLTREN=0,PHBFLTREN=0,PHAPOL=0,PHBPOL=0,QUADMODE=0,QUADIR=0,TOFDIR=0,QUADEN=1 */
  FTM1_QDCTRL = FTM_QDCTRL_QUADEN_MASK;
  /* FTM1_CONF: GTBEOUT=0,GTBEEN=0,BDMMODE=0,NUMTOF=0 */
  FTM1_CONF &= (uint32_t)~(uint32_t)(
                FTM_CONF_GTBEOUT_MASK |
                FTM_CONF_GTBEEN_MASK |
                FTM_CONF_BDMMODE(0x03) |
                FTM_CONF_NUMTOF(0x1F)
               );
  /* FTM1_PWMLOAD: LDOK=0,CH1SEL=0,CH0SEL=0 */
  FTM1_PWMLOAD &= (uint32_t)~(uint32_t)(
                   FTM_PWMLOAD_LDOK_MASK |
                   FTM_PWMLOAD_CH1SEL_MASK |
                   FTM_PWMLOAD_CH0SEL_MASK
                  );
}


/* END FTM1. */
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
