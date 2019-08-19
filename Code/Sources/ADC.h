/*
 * ADC.h
 *
 *  Created on: Apr 5, 2016
 *      Author: lbs1
 */

#ifndef ADC_H_
#define ADC_H_

/************/
/*    ADC   */
/************/

/*  ADC 
 *     - Use Init_ADC to set up ADC0 or ADC1
 *     - MUST enable clock gate, Conversion mode = Single, Result data format = 10-bit (0 to 1023 for 0 to 3.3V), Conversion trigger=SW
 *     - E.g. 1 of usage (for dedicated single ended pins e.g. ADC1's SE8 on channel 8) 
 *     	    scADC1_SE8;				// start ADC conversion of signal at single-ended ADC1_SE8 pin   
 *	        while (ADC1_COCO == 0);	// wait for conversion completed (COCO) before reading ADC value 
 *	        ADC1se8Val = ADC1_RA;	// reading results register RA automatically clears COCO flag
 *	        
 *     - E.g. 2 of usage (for shared pins e.g. ADC1's SE4a on channel 4)
 *  		ADC1_CFG2 = ADC1_CFG2 & 0xFFFFFFEF; // clears bit 4 i.e. MUXSEL bit to select all ADC1 a pins
 *     	    scADC1_SE4;							// start ADC conversion of signal at single-ended ADC1_SE4a pin   
 *	        while (ADC1_COCO == 0);				// wait for conversion completed (COCO) before reading ADC value 
 *	        ADC1se4aVal = ADC1_RA;				// reading results register RA automatically clears COCO flag
 *	        
 *     - E.g. 3 of usage (for shared pins e.g. ADC1's SE4b on channel 4)
 *  		ADC1_CFG2 = ADC1_CFG2 | 0x10;  		// sets bit 4 i.e.MUXSEL bit to select all ADC1 b pins
 *     	    scADC1_SE4;							// start ADC conversion of signal at single-ended ADC1_SE4b pin   
 *	        while (ADC1_COCO == 0);				// wait for conversion completed (COCO) before reading ADC value 
 *	        ADC1se4bVal = ADC1_RA;				// reading results register RA automatically clears COCO flag	        
*/

//ADC0_SC1A already defined by PE
//#define ADC0_SC1A 		(*(ioreg32 *)0x4003B000) 	// UART0 status register 1 whose bit 6 is transmit complete
#define ADC0_COCO 		(ADC0_SC1A & 0x080) >> 7		// conversion complete flag status fir reading
#define disADC0			 ADC0_SC1A=0x1f	      	    	// start conversions for the differential ADC0 channels    

// ADC0 differential inputs 
#define scADC0_D0		ADC0_SC1A=0x20	// start conversions for the differential ADC0 channels  	
#define scADC0_D3		ADC0_SC1A=0x023

// ADC1 single-ended inputs 
#define scADC0_SE_DP0	ADC0_SC1A=0x00	// start conversions for the various single-ended ADC0 channels
#define scADC0_SE_DM0	ADC0_SC1A=0x01
#define scADC0_SE_DP3	ADC0_SC1A=0x02
#define scADC0_SE_DM3	ADC0_SC1A=0x03
#define scADC0_SE4		ADC0_SC1A=0x04
#define scADC0_SE5		ADC0_SC1A=0x05
#define scADC0_SE6		ADC0_SC1A=0x06
#define scADC0_SE7		ADC0_SC1A=0x07
#define scADC0_SE8		ADC0_SC1A=0x08
#define scADC0_SE9		ADC0_SC1A=0x09
#define scADC0_SE12		ADC0_SC1A=0x0C
#define scADC0_SE13		ADC0_SC1A=0x0D
#define scADC0_SE14		ADC0_SC1A=0x0E
#define scADC0_SE23		ADC0_SC1A=0x17
#define scADC0_SE15     ADC0_SC1A=0x0F

//ADC0_RA results register already defined by PE

//ADC1_SC1A already defined by PE
//#define ADC1_SC1A 	(*(reg32 *)0x400BB000) 		// UART0 status register 1 whose bit 6 is transmit complete
//alternatively #define ADC1_SC1A 	(*(int *)0x400BB000)allows for assignment of decimal or hexa values 
#define ADC1_COCO 		(ADC1_SC1A & 0x080)>>7		// for reading conversion complete flag status
#define disADC1 		ADC1_SC1A.byte0=0x1f      	// disable ADC1

// ADC1 differential inputs 
#define scADC1_D0		ADC1_SC1A=0x20	// start conversions for the differential ADC1 channels
#define scADC1_D3		ADC0_SC1A=0x23

// ADC1 single-ended inputs 
#define scADC1_SE_DP0	ADC1_SC1A=0x00	// start conversions for the various single-ended ADC1 channels
#define scADC1_SE_DM0	ADC1_SC1A=0x01
#define scADC1_SE_DP3	ADC1_SC1A=0x02
#define scADC1_SE_DM3	ADC1_SC1A=0x03
#define scADC1_SE4		ADC1_SC1A=0x04
#define scADC1_SE5		ADC1_SC1A=0x05
#define scADC1_SE6		ADC1_SC1A=0x06
#define scADC1_SE7		ADC1_SC1A=0x07
#define scADC1_SE8		ADC1_SC1A=0x08
#define scADC1_SE9		ADC1_SC1A=0x09
#define scADC1_SE14		ADC1_SC1A=0x0E
#define scADC1_SE15		ADC1_SC1A=0x0F
#define scADC1_SE17		ADC1_SC1A=0x11
#define scADC1_SE18		ADC1_SC1A=0x12

//ADC1_RA results register already defined by PE

#endif /* ADC_H_ */
