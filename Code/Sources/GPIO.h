/*
 * GPIO.h
 *
 *  Created on: Apr 4, 2016
 *      Author: lbs1
 */

#ifndef GPIO_H_
#define GPIO_H_

/*  PortA to Port E bit-access 
 *  	E.g.(Note: MUST enable port pin in Processor Expert Init_GPIO, which also helps to ensure no conflicts in pin usage)  
 *  	PTE4d = 1; 		// PTE4 = output pin
 *  	PTE4o = 0;  	// clear PTE2 output pin to 0
 *  	
 *  	PTE2d = 0;		// PTE2 = input pin
 *  	val = PTE2i;	// read value at PTE2 pin into variable val
 */

/************/
/* GPIO  */
/************/
/*** define new type 'ioreg32' ***/
typedef struct
{
	unsigned B0:1;
	unsigned B1:1;
	unsigned B2:1;
	unsigned B3:1;
	unsigned B4:1;
	unsigned B5:1;
	unsigned B6:1;
	unsigned B7:1;
	unsigned B8:1;
	unsigned B9:1;
	unsigned B10:1;
	unsigned B11:1;
	unsigned B12:1;
	unsigned B13:1;
	unsigned B14:1;
	unsigned B15:1;
	unsigned B16:1;
	unsigned B17:1;
	unsigned B18:1;
	unsigned B19:1;
	unsigned B20:1;
	unsigned B21:1;
	unsigned B22:1;
	unsigned B23:1;	
	unsigned B24:1;
	unsigned B25:1;
	unsigned B26:1;
	unsigned B27:1;
	unsigned B28:1;
	unsigned B29:1;
	unsigned B30:1;
	unsigned B31:1;
}ioreg32;

/*** define new type 'ioreg8' ***/
typedef struct
{
	unsigned B0:1;
	unsigned B1:1;
	unsigned B2:1;
	unsigned B3:1;
	unsigned B4:1;
	unsigned B5:1;
	unsigned B6:1;
	unsigned B7:1;
}ioreg8;

typedef struct {
	unsigned byte0:8;
	unsigned byte1:8;
	unsigned byte2:8;
	unsigned byte3:8;
} iobyte;

// Port A
#define wPTA (*(iobyte *) 0x400FF000)
#define rPTA (*(iobyte *) 0x400FF010)

#define PTAo (*(ioreg32 *)0x400FF000)		// Port A output register
#define PTAi (*(ioreg32 *)0x400FF010)		// Port A input register
#define PTAd (*(ioreg32 *)0x400FF014)		// Port A data direction register

#define PTA0o PTAo.B0
#define PTA1o PTAo.B1
#define PTA2o PTAo.B2
#define PTA3o PTAo.B3
#define PTA4o PTAo.B4
#define PTA5o PTAo.B5
#define PTA12o PTAo.B12
#define PTA13o PTAo.B13
#define PTA14o PTAo.B14
#define PTA15o PTAo.B15
#define PTA16o PTAo.B16
#define PTA17o PTAo.B17

#define PTA0i PTAi.B0
#define PTA1i PTAi.B1
#define PTA2i PTAi.B2
#define PTA3i PTAi.B3
#define PTA4i PTAi.B4
#define PTA5i PTAi.B5
#define PTA12i PTAi.B12
#define PTA13i PTAi.B13
#define PTA14i PTAi.B14
#define PTA15i PTAi.B15
#define PTA16i PTAi.B16
#define PTA17i PTAi.B17

#define PTA0d PTAd.B0
#define PTA1d PTAd.B1
#define PTA2d PTAd.B2
#define PTA3d PTAd.B3
#define PTA4d PTAd.B4
#define PTA5d PTAd.B5
#define PTA12d PTAd.B12
#define PTA13d PTAd.B13
#define PTA14d PTAd.B14
#define PTA15d PTAd.B15
#define PTA16d PTAd.B16
#define PTA17d PTAd.B17

// Port B
#define PTBo (*(ioreg32 *)0x400FF040)		// Port E output register
#define PTBi (*(ioreg32 *)0x400FF050)		// Port E input register
#define PTBd (*(ioreg32 *)0x400FF054)		// Port E data direction register

#define PTB0o PTBo.B0
#define PTB1o PTBo.B1
#define PTB2o PTBo.B2
#define PTB3o PTBo.B3
#define PTB10o PTBo.B10
#define PTB11o PTBo.B11
#define PTB16o PTBo.B16
#define PTB17o PTBo.B17
#define PTB18o PTBo.B18
#define PTB19o PTBo.B19

#define PTB0i PTBi.B0
#define PTB1i PTBi.B1
#define PTB2i PTBi.B2
#define PTB3i PTBi.B3
#define PTB10i PTBi.B10
#define PTB11i PTBi.B11
#define PTB16i PTBi.B16
#define PTB17i PTBi.B17
#define PTB18i PTBi.B18
#define PTB19i PTBi.B19

#define PTB0d PTBd.B0
#define PTB1d PTBd.B1
#define PTB2d PTBd.B2
#define PTB3d PTBd.B3
#define PTB10d PTBd.B10
#define PTB11d PTBd.B11
#define PTB16d PTBd.B16
#define PTB17d PTBd.B17
#define PTB18d PTBd.B18
#define PTB19d PTBd.B19

// Port C
#define PTCo (*(ioreg32 *)0x400FF080)		// Port E output register
#define PTCi (*(ioreg32 *)0x400FF090)		// Port E input register
#define PTCd (*(ioreg32 *)0x400FF094)		// Port E data direction register

#define PTC0o PTCo.B0
#define PTC1o PTCo.B1
#define PTC2o PTCo.B2
#define PTC3o PTCo.B3
#define PTC4o PTCo.B4
#define PTC5o PTCo.B5
#define PTC6o PTCo.B6
#define PTC7o PTCo.B7
#define PTC8o PTCo.B8
#define PTC9o PTCo.B9
#define PTC10o PTCo.B10
#define PTC11o PTCo.B11
#define PTC16o PTCo.B16
#define PTC17o PTCo.B17

#define PTC0i PTCi.B0
#define PTC1i PTCi.B1
#define PTC2i PTCi.B2
#define PTC3i PTCi.B3
#define PTC4i PTCi.B4
#define PTC5i PTCi.B5
#define PTC6i PTCi.B6
#define PTC7i PTCi.B7
#define PTC8i PTCi.B8
#define PTC9i PTCi.B9
#define PTC10i PTCi.B10
#define PTC11i PTCi.B11
#define PTC16i PTCi.B16
#define PTC17i PTCi.B17

#define PTC0d PTCd.B0
#define PTC1d PTCd.B1
#define PTC2d PTCd.B2
#define PTC3d PTCd.B3
#define PTC4d PTCd.B4
#define PTC5d PTCd.B5
#define PTC6d PTCd.B6
#define PTC7d PTCd.B7
#define PTC8d PTCd.B8
#define PTC9d PTCd.B9
#define PTC10d PTCd.B10
#define PTC11d PTCd.B11
#define PTC16d PTCd.B16
#define PTC17d PTCd.B17

// Port D
#define wPTD (*(iobyte *) 0x400FF0C0)
#define rPTD (*(iobyte *) 0x400FF0D0)

#define PTDo (*(ioreg32 *)0x400FF0C0)		// Port E output register
#define PTDi (*(ioreg32 *)0x400FF0D0)		// Port E input register
#define PTDd (*(ioreg32 *)0x400FF0D4)		// Port E data direction register

#define PTD0o PTDo.B0
#define PTD1o PTDo.B1
#define PTD2o PTDo.B2
#define PTD3o PTDo.B3
#define PTD4o PTDo.B4
#define PTD5o PTDo.B5
#define PTD6o PTDo.B6
#define PTD7o PTDo.B7

#define PTD0i PTDi.B0
#define PTD1i PTDi.B1
#define PTD2i PTDi.B2
#define PTD3i PTDi.B3
#define PTD4i PTDi.B4
#define PTD5i PTDi.B5
#define PTD6i PTDi.B6
#define PTD7i PTDi.B7

#define PTD0d PTDd.B0
#define PTD1d PTDd.B1
#define PTD2d PTDd.B2
#define PTD3d PTDd.B3
#define PTD4d PTDd.B4
#define PTD5d PTDd.B5
#define PTD6d PTDd.B6
#define PTD7d PTDd.B7

// Port E
#define PTEo (*(ioreg32 *)0x400FF100)		// Port E output register
#define PTEi (*(ioreg32 *)0x400FF110)		// Port E input register
#define PTEd (*(ioreg32 *)0x400FF114)		// Port E data direction register

#define PTE0o PTEo.B0
#define PTE1o PTEo.B1
#define PTE2o PTEo.B2
#define PTE3o PTEo.B3
#define PTE4o PTEo.B4
#define PTE5o PTEo.B5

#define PTE0i PTEi.B0
#define PTE1i PTEi.B1
#define PTE2i PTEi.B2
#define PTE3i PTEi.B3
#define PTE4i PTEi.B4
#define PTE5i PTEi.B5

#define PTE0d PTEd.B0
#define PTE1d PTEd.B1
#define PTE2d PTEd.B2
#define PTE3d PTEd.B3
#define PTE4d PTEd.B4
#define PTE5d PTEd.B5

#endif /* GPIO_H_ */
