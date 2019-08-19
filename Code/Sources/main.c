/* ###################################################################
 **     Filename    : main.c
 **     Project     : Final Review
 **     Processor   : MK20DX256VLK10
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2016-07-18, 15:57, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.01
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */         
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "PTC.h"
#include "ADC1.h"
#include "SysTick.h"
#include "FTM0.h"
#include "FTM1.h"
#include "FTM2.h"
#include "UART0.h"
#include "UART1.h"
#include "PTA.h"
#include "PTB.h"
#include "PTD.h"
#include "PTE.h"
#include "ADC0.h"
#include "LPTMR0.h"
#include "UART2.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "GPIO.h"
#include "ADC.h"
#include "UART.h"


volatile int  i,g;
volatile long  LDist,RDist,difLeft, difRight,xx;
volatile long xbeeWaitCount,ii;
volatile int8_t cse,cse1 = 10,cse2 = 12,cse3 = 6,cse4 = 13,cse5 = 6,cse6 = 16,cse33 = 5,detected = 6,RCmillise,step,stickLine,Servo,RCmillisec,lineSearch;
volatile int8_t send,RC = 1,rp,zz,tt,ttt,s,openRoller,on,off,countLineOne,countLineThree,countLineFour,countLineFive,firstDetected,stopDetected,zzz,recover,sr,rollerState;
volatile int16_t Pellet_in,flag,analogCount,tick,x,second,analog,ss,sss,ss1,st,wait;
volatile char xbeeReceive;
volatile int16_t LsetSpeed, LnewCount, LoldCount, Lspeed, LerrSpeed, LolderrSpeed, LerrSpeedRate, LsumSpeed, LsumErrSpeed, LspeedOut, LKp = 10 , LKd = 10 , LKi = 0 ; // For Left Wheel
volatile long LsetDist, LerrDist, LerrDistRate, LolderrDist, LsumErrDist,LDistout,LerrDistRate,LDistOut,LoldDist; // Dist Control
volatile long RsetDist, RerrDist, RerrDistRate, RolderrDist, RsumErrDist,RDistout,RerrDistRate,RDistOut, RoldDist; // Dist Control
volatile int16_t RsetSpeed, RnewCount, RoldCount, Rspeed, RerrSpeed, RolderrSpeed, RerrSpeedRate, RsumSpeed, RsumErrSpeed, RspeedOut, RKp = 10, RKd = 10 , RKi = 0; // For Right Wheel
volatile int8_t saveLeft, saveRight, saveForward, saveBackward,start,followState2,rr;
volatile int8_t fin1,fin2,fin3,fin4,fin5,fin6,fin7,last,d,recover2,stickLine1;
volatile int32_t recTime;
volatile int16_t ambientreading4, ambientreading5,ambientreading6, ambientreading7, ambientreading14, ambientreading15, mixreading4, mixreading5,mixreading6, mixreading7, mixreading14, mixreading15; // For line sensor
volatile int16_t clearreadingLB, clearreadingRB ,clearreadingR2, clearreadingR1, clearreadingL1, clearreadingL2,delay;// for line sensor
/* User includes (#include below this line is not maintained by Processor Expert) */





void writeAXRegister (char bytes[]){
	char x, N, n=0, sum=0;
	//	PTE2o = 1;//enable single-wire Tx	
	//	PTE3o = 0; //disable single-wire Rx;
	for (x=1; x<=bytes[0];x++){
		sum = sum + bytes[x];
	}
	n = bytes[0]-1; 	// subtract ID from count
	N = n+2;			// calculate N
	sum = sum + 0x03 + N;
	send1Char(0xFF);				// send 2 0xFFs
	send1Char(0xFF);
	send1Char(bytes[1]);			// send ID
	send1Char(N);					// send length
	send1Char(0x03);				// write-to-Control Table command
	for (x=2; x<=bytes[0]; x++){	// send register address and data(s)
		send1Char(bytes[x]);
	}	
	send1Char(~sum);				// send checksum
	// the next 2 lines must go together, else Tx disabled before last byte is sent 
	//while (TC1 != 1); // wait for last byte to be fully Tx
	//	PTC8o = 0;// disable single-wire Tx 
	//PTC9o = 1; //enable single-wire Rx
}

char LEDon[]  = {3, 0x0d, 0x19, 0x01};
char LEDoff[] = {3, 0x0d, 0x19, 0x00};
char CWservo[] = {6,0xfe, 0x1E, 0x00, 0x00, 0x00, 0x01};
char CCWservo[] = {6,0xfe ,0x1E, 0xFF, 0x03, 0x00, 0x01};
char SetCW[] = {6,0xfe,0x05,0x03,0x08,0xff,0x01};
char MaxTorque[] = {4,0xfe,0x0e,0xbc,0x02};
char Compliance[] = {6,0xfe,0x1a,0x01,0x01,0x80,0x80};

char Set0[] = {6,0xfe,0x1e,0x30,0x00,0x00,0x00}; // speed 600
char Set90[] = {6,0xfe,0x1e,0x66,0x01,0x00,0x00};
char Set180[] = {6,0xfe,0x1e,0x9c,0x02,0x00,0x00};
char Set270[] = {6,0xfe,0x1e,0xc2,0x03,0x00,0x00};
char Set45[] = {6,0xfe,0x1e,0xc2,0x00,0x00,0x00};
char Set0s[] = {6,0xfe,0x1e,0x30,0x00,0x90,0x01}; // speed 600
char Set90s[] = {6,0xfe,0x1e,0x66,0x01,0x90,0x01};
char Set180s[] = {6,0xfe,0x1e,0x9c,0x02,0x90,0x01};
char Set270s[] = {6,0xfe,0x1e,0xc2,0x03,0x90,0x01};


char WheelMode[] = {4,0xfe,0x08,0x00,0x00};
char ServoMode[] = {4,0xfe,0x08,0x0ff,0x03};

char MoveCCW[] = {4,0xfe,0x20,0xff,0x03};
char MoveCW[] = {4,0xfe,0x20,0xff,0x07};
char StopMoving[] = {4,0xfe,0x20,0x00,0x00};

void ServoDeg(char no){
	switch(no){
	case 0 : writeAXRegister(Set0);break;
	case 1 : writeAXRegister(Set90);break;
	case 2 : writeAXRegister(Set180);break;
	case 3 : writeAXRegister(Set270); break;
	case 9 : writeAXRegister(Set45); break;
	}
	for(i=0;i<1000;i++);
}   		
void RCControl(char control){
	if(control == 'u'){
		RC = 3;
	}
	else{
		RC = 2;
	}
}
void SendXBee(char cha){
	send2Char('?');
	for(ii=0;ii<100;ii++);
	send2Char(cha);
	for(ii=0;ii<100;ii++);
	send2Char(cha);
	for(ii=0;ii<100;ii++);
	send2Char(cha);
	for(ii=0;ii<100;ii++);
	send2Char(cha);
	for(ii=0;ii<100;ii++);
	send2Char(cha);
	for(ii=0;ii<100;ii++);

	send2Char(cha);
	for(ii=0;ii<300;ii++);
	send2Char(cha);
	for(ii=0;ii<300;ii++);
	send2Char(cha);
	for(ii=0;ii<300;ii++);
	send2Char(cha);
	for(ii=0;ii<300;ii++);
	send2Char(cha);
	for(ii=0;ii<300;ii++);

	send2Char(cha);
	for(ii=0;ii<500;ii++);
	send2Char(cha);
	for(ii=0;ii<500;ii++);
	send2Char(cha);
	for(ii=0;ii<500;ii++);
	send2Char(cha);
	for(ii=0;ii<500;ii++);
	send2Char(cha);
	for(ii=0;ii<500;ii++);

	send2Char(cha);
	for(ii=0;ii<1000;ii++);
	send2Char(cha);
	for(ii=0;ii<1000;ii++);
	send2Char(cha);
	for(ii=0;ii<1000;ii++);
	send2Char(cha);
	for(ii=0;ii<1000;ii++);
	send2Char(cha);
	for(ii=0;ii<1000;ii++);

	send2Char(cha);
	for(ii=0;ii<3000;ii++);
	send2Char(cha);
	for(ii=0;ii<3000;ii++);
	send2Char(cha);
	for(ii=0;ii<3000;ii++);
	send2Char(cha);
	for(ii=0;ii<3000;ii++);
	send2Char(cha);
	for(ii=0;ii<3000;ii++);			
}
volatile int16_t collectingPelletTotalCount,collectingFirstPellet;
volatile int servoSecond;

void CollectingProcess(int collect){
	if(collect == 0){
		return;
	}else{
		if(servoSecond > 300){
			if(collectingFirstPellet == 0){
				Servo = 1;
				ServoDeg(Servo);
				collectingFirstPellet = 1;
			}
			if(Pellet_in > 65){
				if(collectingPelletTotalCount<10){
					if(Servo == 2){
						Servo--;
					}else{
						Servo++;
					}
					ServoDeg(Servo);
					collectingPelletTotalCount++;
				}
			}
			servoSecond = 0;
		}
	}
}

volatile int8_t servoSecond1Activated,servoSecond2Activated,takuku;
volatile int16_t period;

void SortingProcess(int sort){

	if(sort == 1){
		if(takuku == 0){
			ServoDeg(1);
			takuku = 1;
		}
		if(servoSecond > 300){
			if(Pellet_in > 65){
				if(period > 200){ // GREEN Colour // > 1000
					if(Servo == 3){
						writeAXRegister(WheelMode);
						for(i=0;i<100;i++);
						writeAXRegister(MoveCCW);
						for(i=0;i<100000;i++);
						writeAXRegister(StopMoving);
						for(i=0;i<100;i++);
						writeAXRegister(ServoMode);
						for(i=0;i<100;i++);
						Servo = 0;
						ServoDeg(Servo);
					}else{
						if(servoSecond1Activated == 0){
							Servo++;
							ServoDeg(Servo);
						}
					}
					servoSecond = 0;
				}else{ // BLUE Colour
					if(Servo == 0){
						writeAXRegister(WheelMode);
						for(i=0;i<100;i++);
						writeAXRegister(MoveCW);
						for(i=0;i<120000;i++);
						writeAXRegister(StopMoving);
						for(i=0;i<100;i++);
						writeAXRegister(ServoMode);
						for(i=0;i<100;i++);
						Servo = 3;
						ServoDeg(Servo);
					}else{
						if(servoSecond2Activated == 0){
							Servo--;
							ServoDeg(Servo);
						}
					}
					servoSecond = 0;

				}	
			}
		}

	}


}

volatile int8_t ints;
volatile int edge1,edge2;

void pta5isr(void) {
	PORTA_ISFR = PORTA_ISFR | 0x0020; // write 1 to clear interrupt flag of PTA5
	ints++;
	if (ints == 1) { // 1st interrupt read in 16-bit counter value as (signed) int16_t 
		LPTMR0_CNR = 0;
		edge1 = LPTMR0_CNR;
	} else if (ints == 2) { // 2nd interrupt read in 16-bit counter again 
		LPTMR0_CNR = 0;
		edge2 = LPTMR0_CNR;
		period = edge2 - edge1; // difference in count value = period in terms of 32.768KHz clock periods
		ints = 0; // reset ints for next period measurement
	}

}
volatile int batt, move;

void BattMon(){

	if(batt<175){
		PTE4o = 0;
		PTE5o = 1; 
		for(i=0;i<100000;i++);
		PTE4o = 1;
		PTE5o = 0;
		for(i=0;i<100000;i++);
	}// less than 10V
	else{
	}
}
void wheelmotor(void)
{
	LnewCount = FTM2_CNT;
	Lspeed = LnewCount - LoldCount;
	LDist = LDist + Lspeed;
	LoldCount = LnewCount;
	LsetDist = LsetDist + LsetSpeed;
	LerrDist = LsetDist - LDist;
	LerrDistRate = LerrDist - LolderrDist;
	LolderrDist = LerrDist;
	LsumErrDist = LsumErrDist + LerrDist;
	LDistOut = LKp*LerrDist + LKd*LerrDistRate + LKi*LsumErrDist;
	if(LDistOut > 999){
		LDistOut = 999;
	}
	else if (LDistOut < -999){
		LDistOut = -999;
	}
	if(LDistOut<0){
		LDistOut = -LDistOut;
		FTM0_C4V = 0;
		FTM0_C5V = LDistOut;
	}
	else{
		FTM0_C4V = LDistOut;
		FTM0_C5V = 0;
	}
	RnewCount = -FTM1_CNT; //This will change the count value to positive
	Rspeed = RnewCount - RoldCount;
	RoldCount = RnewCount;
	RDist = RDist + Rspeed;
	RsetDist = RsetDist + RsetSpeed;
	RerrDist = RsetDist - RDist;
	RerrDistRate = RerrDist - RolderrDist;
	RolderrDist = RerrDist;
	RsumErrDist = RsumErrDist + RerrDist;
	RDistOut = RKp*RerrDist + RKd*RerrDistRate + RKi*RsumErrDist;
	if(RDistOut>999){
		RDistOut = 999;
	}else if (RDistOut<-999){
		RDistOut = -999;
	}
	if(RDistOut < 0){
		RDistOut = -RDistOut;
		FTM0_C6V = 0;
		FTM0_C7V = RDistOut;
	}
	else{
		FTM0_C6V = RDistOut;
		FTM0_C7V =  0;
	}	
}// end of wheel motor

void uart2isr(void)
{	
	RDRF2 = 0;	// clear flag
	xbeeReceive = UART2_D; //UART0_D;
}

void Forward(int distance, int speed)
{
	if(saveForward == 0){
		LoldDist = LDist;
		RoldDist = RDist;
		saveForward = 1;
		ss=0;
	}			
	if(LsetDist - LoldDist < (distance*908) || RsetDist - RoldDist > -(distance*908)){ 
		if(speed >= 30){
			for(ss;ss<speed;ss++){
				LsetSpeed = ss;
				RsetSpeed = -ss;
				for(ii=0;ii<9000;ii++);
			}
		}
		else{
			if(speed != 29){
				for(ss;ss<speed;ss++){
					LsetSpeed = ss;
					RsetSpeed = -ss;
					for(ii=0;ii<8000;ii++);
				}
			}else{

			}
		}
		LsetSpeed = speed;
		RsetSpeed = -speed;
		st = speed;
	}else{
		ss=0;
		if(speed != 29){
			for(st;st>0;st--){
				for(ii=0;ii<8000;ii++);
				LsetSpeed = st;
				RsetSpeed = -st;
			}	
		}else{
			LsetSpeed = 0;
			RsetSpeed = 0;
			fin1 = 1;
			return;
		}
		LsetSpeed = 0;
		RsetSpeed = 0;
		fin1 = 1;
		return;
	}
}
void BackWard(int distance, int speed)
{
	if(saveBackward == 0){
		LoldDist = LDist;
		RoldDist = RDist;
		saveBackward = 1;
	}
	if(LsetDist - LoldDist > -(distance*908) || RsetDist - RoldDist < (distance*908) ){       		
		LsetSpeed = -speed;
		RsetSpeed =  speed;		
	}else{
		LsetSpeed = 0;
		RsetSpeed = 0;
		fin2 = 1;	
	}
}

void goForWard(void)
{
	LsetSpeed = 10;
	RsetSpeed = -10;

}


void goBackWard(void)
{
	LsetSpeed = -10;
	RsetSpeed = 10;
}

void stop(void)
{
	LsetSpeed = 0;
	RsetSpeed = 0;
}	

void  LnsSensor(void) {
	ADC1_CFG2 = ADC1_CFG2 | 0x010; // select multiplexer b
	//Ambient reading for front line sensor 
	scADC1_SE6;
	while (ADC1_COCO != 1);
	ambientreading6 = ADC1_RA; scADC1_SE7;
	while (ADC1_COCO != 1);
	ambientreading7 = ADC1_RA; scADC1_SE14;
	while (ADC1_COCO != 1); 
	ambientreading14 = ADC1_RA; scADC1_SE15;
	while (ADC1_COCO != 1);
	ambientreading15 = ADC1_RA; PTC6o = 1; // turn on the transmitter 
	for(delay = 0; delay < 100 ; delay ++);
	scADC1_SE6; 
	while (ADC1_COCO != 1);
	mixreading6 = ADC1_RA; scADC1_SE7;
	while (ADC1_COCO != 1); 
	mixreading7 = ADC1_RA;
	scADC1_SE14;
	while (ADC1_COCO != 1);
	mixreading14 = ADC1_RA;
	scADC1_SE15; 
	while (ADC1_COCO != 1);
	mixreading15 = ADC1_RA;
	PTC6o = 0;// turn off the transmitter 
	clearreadingL1 = mixreading14 - ambientreading14;
	clearreadingL2 = mixreading15 - ambientreading15;
	clearreadingR2 = mixreading6 - ambientreading6;
	clearreadingR1 = mixreading7 - ambientreading7;
	for(delay =0; delay < 10 ; delay++);
	ADC1_CFG2 = ADC1_CFG2 & 0xFFEF; //select multiplexer a
	for(delay =0; delay < 10 ; delay++);// ambientreading for the back-line sensor 
	scADC1_SE4; 
	while (ADC1_COCO != 1); 
	ambientreading4 = ADC1_RA; 
	scADC1_SE5; 
	while (ADC1_COCO != 1); 
	ambientreading5 = ADC1_RA;
	PTC7o = 1;
	for (delay = 0; delay< 100; delay++); 
	scADC1_SE4;
	while (ADC1_COCO != 1);
	mixreading4 = ADC1_RA; 
	scADC1_SE5; 
	while (ADC1_COCO != 1);
	mixreading5 = ADC1_RA; 
	PTC7o = 0;
	clearreadingLB = mixreading4 - ambientreading4;
	clearreadingRB = mixreading5 - ambientreading5;
	// Analog Distance Sensor
	for (delay = 0; delay < 10; delay++); 
	ADC1_CFG2 = ADC1_CFG2 | 0x10; // select multiplexer b
	for (delay = 0; delay < 10; delay++); 
	scADC1_SE5;
	while(ADC1_COCO != 1);
	analog = ADC1_RA;
}



void Systickpwm(void)
{
	xbeeWaitCount++;
	if(on == 1){
		tick++;}

	scADC0_SE23;			// start ADC conversion of signal at single-ended ADC0_SE8 pin   
	while (ADC0_COCO == 0);	 // wait for conversion completed (COCO) before reading ADC value
	batt = ADC0_RA;
	wheelmotor();
	LnsSensor();
	RCmillisec++;

	if (RCmillisec < RC){
		PTC16o = 1;
	}
	else{
		PTC16o = 0;
		if(RCmillisec>50){
			RCmillisec = 0;
		}
	}

	if(openRoller == 1)
	{
		second++;
		if(second < 1300){
			PTA13o = 1;
			PTA12o = 0;
		}
		else if(second < 1700){
			PTA13o = 0;
			PTA12o = 0;
		}
		else{
			if(second < 3000){
				PTA13o = 0;
				PTA12o = 1;
			}
			else if(second < 3400){
				PTA13o = 0;
				PTA12o = 0;
			}
			else{
				second = 0;
			}
		}
	}
	else if(openRoller == 0)
	{
		PTA13o = 0;
		PTA12o = 0;
	}

	scADC0_SE15;				// start ADC conversion of signal at single-ended ADC0_SE8 pin   
	while (ADC0_COCO == 0);	// wait for conversion completed (COCO) before reading ADC value
	Pellet_in = ADC0_RA;

	servoSecond++;

	analogCount++;
	recTime++;

}

void GoAndFollowR1(int speed,int distance){
	if(saveForward == 0){
		LoldDist = LDist;
		RoldDist = RDist;
		saveForward = 1;
	}
	if(distance != 0){
		if(LsetDist - LoldDist > (distance*908) && RsetDist - RoldDist < -(distance*908)){ 
			fin1 = 1;
			return;
		}else{
			fin1 = 0;
		}
	}
	if(clearreadingR1 < 200 && clearreadingR1 > 30){
		LsetSpeed = speed;
		RsetSpeed = -speed;
		//followState1 = 0; 
	}else if(clearreadingR1 <= 30){
		//if(followState1 == 0){
		LsetSpeed = speed;
		RsetSpeed = 0;
		/*if(clearreadingR2 > 100){
				followState1 = 1;
			}
		}else{
			LsetSpeed = 0;
			RsetSpeed = -speed;
		}*/
	}else if(clearreadingR1 >= 200){
		LsetSpeed = 0;
		RsetSpeed = -speed;
	}
}

void GoAndFollowR2(int speed,int distance){
	if(saveForward == 0){
		LoldDist = LDist;
		RoldDist = RDist;
		saveForward = 1;
	}
	if(distance != 0){
		if(LsetDist - LoldDist > (distance*908) && RsetDist - RoldDist < -(distance*908)){ 
			fin1 = 1;
			return;
		}else{
			fin1 = 0;
		}
	}

	if(clearreadingR2 < 240 && clearreadingR2 > 30){
		LsetSpeed = speed;
		RsetSpeed = -speed;
		followState2 = 0;
	}else if(clearreadingR2 <= 30){
		if(followState2 == 0){
			LsetSpeed = 0;
			RsetSpeed = -speed;
		}else{
			LsetSpeed = speed;
			RsetSpeed = 0;
		}
		if(clearreadingR1 > 100){
			followState2 = 1;
		}
	}else if(clearreadingR2 >= 240){
		LsetSpeed = speed;
		RsetSpeed = 0;
	}
}

void GoAndFollowRB(int speed,int distance){

	if(saveBackward == 0){
		LoldDist = LDist;
		RoldDist = RDist;
		saveBackward = 1;
	}
	if(distance != 0){
		if(LsetDist - LoldDist > -(distance*908)){
			fin2 = 0;
		}else{

			fin2 = 1;
			return;
		}
	}
	if(clearreadingRB < 180 && clearreadingRB > 90){
		LsetSpeed = -speed;
		RsetSpeed = speed;
	}else if(clearreadingRB <= 90){
		LsetSpeed = -speed;
		RsetSpeed = 0;
	}else if(clearreadingRB >= 180){
		LsetSpeed = 0;
		RsetSpeed = speed;
	}
}
void GoAndFollowR1S(int speed,int distance){
	if(saveForward == 0){
		LoldDist = LDist;
		RoldDist = RDist;
		saveForward = 1;
	}
	if(distance != 0){
		if(LsetDist - LoldDist > (distance*908) && RsetDist - RoldDist < -(distance*908)){ 
			fin1 = 1;
			return;
		}else{
			fin1 = 0;
		}
	}
	if(clearreadingR1 < 180 && clearreadingR1 > 30){
		LsetSpeed = speed;
		RsetSpeed = -speed;
		//followState1 = 0; 
	}else if(clearreadingR1 <= 30){
		//if(followState1 == 0){
		LsetSpeed = 0;
		RsetSpeed = -speed;


	}else if(clearreadingR1 >= 180){
		LsetSpeed = speed;
		RsetSpeed = 0;
	}
}
void GoAndFollowRBS(int speed,int distance){

	if(saveBackward == 0){
		LoldDist = LDist;
		RoldDist = RDist;
		saveBackward = 1;
	}
	if(distance != 0){

		if(LsetDist - LoldDist > -(distance*908)){
			fin2 = 0;
		}else{

			fin2 = 1;
			return;
		}
	}
	if(clearreadingRB < 180 && clearreadingRB > 90){
		LsetSpeed = -speed;
		RsetSpeed = speed;
	}else if(clearreadingRB <= 90){
		LsetSpeed = 0;
		RsetSpeed = speed;


	}else if(clearreadingRB >= 180){
		LsetSpeed = -speed;
		RsetSpeed = 0;
	}
}

void TurnRight(int value2, int x2, int y2)
{
	saveForward = 0;
	saveBackward = 0;
	if(saveRight == 0){
		LoldDist = LDist;
		saveRight = 1;
	}
	difRight = LDist - LoldDist;
	if(difRight < value2){
		LsetSpeed = x2;
		RsetSpeed = y2;
	}else{
		LsetSpeed = 0;
		RsetSpeed = 0;
		fin3 = 1;
	}		
}

void BackwardTurnRight(int value3, int x3, int y3)
{
	saveForward = 0;
	saveBackward = 0;
	if(saveRight == 0){
		LoldDist = LDist;
		saveRight = 1;
	}
	difRight = LDist - LoldDist;
	if(difRight > -value3){
		LsetSpeed = -x3;
		RsetSpeed = -y3;
	}else{
		LsetSpeed = 0;
		RsetSpeed = 0;
		fin7 = 1;
	}		
}

void speedTurnLeft(int value3,int value4,int x3, int y3)
{
	saveForward = 0;
	saveBackward = 0;
	if(saveLeft == 0){
		RoldDist = RDist;
		saveLeft = 1;
	}
	difLeft = RDist - RoldDist;
	if(-difLeft <= value3){
		LsetSpeed = x3;
		RsetSpeed = -y3;
	}else{
		LsetSpeed = 0;
		RsetSpeed = 0;
		fin5 = 1;
	}
}
void speedTurnRight(int value3,int value4,int x3, int y3)
{
	saveForward = 0;
	saveBackward = 0;
	if(saveRight == 0){
		LoldDist = LDist;
		saveRight = 1;
	}		
	difRight = LDist - LoldDist;
	if(difRight < value4){
		LsetSpeed = x3;
		RsetSpeed = y3;
	}else{
		LsetSpeed = 0;
		RsetSpeed = 0;
		fin6 = 1;
	}		
}

void TurnLeft(int value1 , int x1 , int y1)
{    
	saveForward = 0;
	saveBackward = 0;
	if(saveLeft == 0){
		RoldDist = RDist;
		saveLeft = 1;
	}
	difLeft = RDist - RoldDist;
	if(-difLeft <= value1){
		LsetSpeed = x1;
		RsetSpeed = y1;
	}	  	  	  
	else{
		LsetSpeed = 0;
		RsetSpeed = 0;
		fin4 = 1;		
	}		
}

void Reset(void)
{					
	LsetDist = 0;
	LDist = 0;
	RsetDist = 0;
	RDist = 0;
	difLeft = 0;
	difRight = 0;
}


void randomPush()
{
	while(cse6 != 16){
		switch(cse6){
		case 1 : GoAndFollowR1S(10,10);
		if(fin1 == 1){
			cse6 = 19;
			fin1 = 0;
		}
		break;

		case 19: GoAndFollowR1S(20,110);
		PTA13o = 1;
		PTA12o = 1;
		if(fin1 == 1){
			cse6 = 20;
			fin1 = 0;
			saveForward = 0;
		} 
		break;
		case 20: GoAndFollowR1S(5,10);
		PTA13o = 1;
		PTA12o = 1;
		if(fin1 == 1){
			stop();
			cse6 = 18;
			fin1 = 0;
			saveBackward = 0;	
		}
		break;			
		case 18: GoAndFollowRBS(5,15);
		PTA13o = 0;
		PTA12o = 0;
		if(fin2 == 1){
			cse6 = 2;
			fin2 = 0;
			saveBackward = 0;
		}
		break;
		case 2: GoAndFollowRBS(20,0);

		if(clearreadingLB > 180 && rp == 0){
			rp = 1;
		}
		if(clearreadingL1 > 180 && rp == 1){
			rp = 2;
		}
		if(clearreadingLB > 180 && rp == 2){
			rp = 3;
		}
		if(clearreadingL1 > 180 && rp == 3){
			rp = 4;
		}
		if(clearreadingLB > 180 && rp == 4){
			cse6 = 3;
			fin2 = 0;
		}


		break;
		case 3: 
			rp = 0;
			stop();
			Reset();
			cse6 = 4;
			saveLeft = 0;
			break;
		case 4: 
			TurnLeft(9500,-25,-25);
			if(fin4 == 1){
				cse6 = 5;
				fin4 = 0;
				saveForward = 0;
			}
			break;
		case 5: 
			Forward(9,20);
			if(clearreadingL1 < 80 && clearreadingL2 > 80)
			{
				LsetSpeed = 20;
				RsetSpeed = 0;
			}
			if(clearreadingL1 > 80 && clearreadingL2 < 80)
			{
				LsetSpeed = 0;
				RsetSpeed = -20;
			}
			if(clearreadingL1 < 80 && clearreadingL2 < 80)
			{
				LsetSpeed = 0;
				RsetSpeed = -20;
			}
			if(fin1 == 1)
			{
				saveRight = 0;
				cse6 = 6;
				fin1 = 0;
			}
			break;

		case 6: TurnRight(12000,25,25);
		if(fin3 == 1)
		{
			cse6 = 15;
			fin3 = 0;
			saveForward = 0;
		}
		break;
		case 7: 
			Forward(105,50);
			PTA13o = 1;
			PTA12o = 1;
			if(fin1 == 1)
			{
				for(xx = 0; xx < 30000; xx++);
				stop();
				for(xx = 0; xx < 30000; xx++);
				cse6 = 8;
				fin1 = 0;
				saveBackward = 0;	
			} 
			break;
		case 8:
			BackWard(5,15);
			PTA13o = 0;
			PTA12o = 0;
			if(fin2 == 1)
			{
				for(xx=0;xx < 30000;xx++);
				cse6 = 9;
				fin2 = 0;
				saveRight = 0;
			}
			break;
		case 9:
			BackwardTurnRight(4000,10,10);
			if(fin7 == 1)
			{
				cse6 = 10;
				fin7 = 0;
			}
			break;
		case 10:
			if(clearreadingRB < 200)
			{
				LsetSpeed = -10;
				RsetSpeed = 10;
			}
			else
			{
				cse6 = 11;
				saveBackward = 0;
			}
			break;
		case 11: GoAndFollowRBS(20,0);

		if(clearreadingL1 > 180 && rp == 0){
			rp = 2;
		}
		if(clearreadingLB > 180 && rp == 2){
			rp = 3;
		}
		if(clearreadingL1 > 180 && rp == 3){
			rp = 4;
		}
		if(clearreadingLB > 180 && rp == 4){
			cse6 = 12;
			fin2 = 0;
			saveLeft = 0;
		}

		break;
		case 12: 
			stop();
			cse6 = 13;									
			break;
		case 13: TurnLeft(10500,-25,-25);
		if(fin4 == 1)
		{
			saveForward = 0;
			cse6 = 14;
			fin4 = 0;
		}
		break;

		case 14: 	Forward(20,10);
		if(clearreadingL1 < 80 && clearreadingL2 > 80)
		{
			LsetSpeed = 20;
			RsetSpeed = 0;
		}
		if(clearreadingL1 > 80 && clearreadingL2 < 80)
		{
			LsetSpeed = 0;
			RsetSpeed = -20;
		}
		if(clearreadingL1 < 80 && clearreadingL2 < 80)
		{
			LsetSpeed = 0;
			RsetSpeed = -20;
		}
		if(fin1 == 1)
		{
			cse6 = 16;
			fin1 = 0;
			start = 1;
			saveRight = 0;
		}
		break;

		case 15:LsetSpeed = 10;
		RsetSpeed = -10;
		for(xx=0;xx<150000;xx++);
		stop();
		for(xx = 0; xx<50000;xx++);
		cse6 = 17;
		zzz = 1;
		break;

		case 17:
			if((clearreadingRB < 100 || clearreadingLB < 100) && zzz == 1 )
			{
				while(clearreadingLB < 100 && clearreadingRB < 100)
				{
					LsetSpeed = -10;
					RsetSpeed = 10;
				}

				zzz = 2;

			}
			if(clearreadingRB > 100 && clearreadingLB < 100 && zzz == 2){
				while(clearreadingLB < 100){
					LsetSpeed = -10;
					RsetSpeed = 0;
				}	

				zzz = 3;
			}
			if(clearreadingRB < 100 && clearreadingLB > 100 && zzz == 2){
				while(clearreadingRB < 100){
					LsetSpeed = 0;
					RsetSpeed = 10;
				}

				zzz = 3;
			}
			if(clearreadingRB > 100 && clearreadingLB > 100 && zzz == 2)
			{
				zzz = 3;
			}

			if(zzz == 3)
			{
				stop();
				cse6 = 7;
			}
			break;	

		}
	}
}

void detectPellet(int cse)
{
	while(cse != 6){			   
		switch(cse){
		case 1:
			countLineThree = 1;
			switch(tt){
			case 0:TurnRight(11500,25,25);
			saveForward = 0;
			if(fin3 == 1){
				tt = 1;
				fin3 = 0;
			}
			break;
			case 1:LsetSpeed = 10;
			RsetSpeed = -10;
			for(ii=0;ii<240000;ii++);
			stop();
			for(ii=0;ii<50000;ii++);
			tt = 2;
			break;
			case 2:if(clearreadingRB > 150 || clearreadingLB > 150){
				tt = 3;
			}else{
				LsetSpeed = -10;
				RsetSpeed = 10;
			}
			break;
			case 3:if(clearreadingRB > 150 && clearreadingLB < 150 && ttt == 0){
				while(clearreadingLB < 150){
					LsetSpeed = -10;
					RsetSpeed = 0;
				}
				tt = 4;
				ttt = 1;
			}
			if(clearreadingRB < 150 && clearreadingLB > 150 && ttt == 0){
				while(clearreadingRB < 150){
					LsetSpeed = 0;
					RsetSpeed = 10;
				}
				tt = 4;
				ttt = 1;
			}
			if(clearreadingRB > 150 && clearreadingLB > 150 && ttt == 0){
				tt = 4;
				ttt = 1;
			}
			break;
			case 4:stop();
			saveForward = 0;
			cse = 2;
			break;
			}
			break;
			case 2:tt = 0;
			ttt = 0;
			saveRight = 0;
			Forward(59,50);	
			PTA13o = 1;
			PTA12o = 1;
			if(fin1 == 1){
				stop();
				cse = 3;
				fin1 = 0;
				ss1 = 0;
			} 
			break;		    				  	  		  	  	  	  	  
			case 3: sss = 50;
			if(s == 0){
				while(ss1 < sss){
					for(ss1;ss1<sss;ss1++){
						LsetSpeed = -ss1;
						RsetSpeed = ss1;
						for(ii=0;ii<3200;ii++);
					}
				}
				LsetSpeed  = -sss;
				RsetSpeed = sss;
			}
			if((clearreadingLB > 30 || clearreadingRB > 30) && zz == 0){
				for(ss1; ss1 > 0; ss1--){
					LsetSpeed = -ss1;
					RsetSpeed = ss1;
					for(ii = 0; ii < 2800; ii++);
				}
				LsetSpeed = 0;
				RsetSpeed = 0;
				for(xx = 0; xx < 50000; xx++);
				zz = 1;
				s = 1;
				recTime = 0;
			}
			if((clearreadingRB < 100 || clearreadingLB < 100) && zz == 1 ){
				if(clearreadingLB < 100 && clearreadingRB < 100){
					if(recTime < 3000){
						LsetSpeed = 10;
						RsetSpeed = -10;
						zz = 1;
					}else{
						zz = 2;
						clearreadingLB = 101;
						clearreadingRB = 99;
					}
				}else{
					zz = 2;
				}	
			}
			if(clearreadingRB > 100 && clearreadingLB < 100 && zz == 2){
				while(clearreadingLB < 100){
					LsetSpeed = 10;
					RsetSpeed = 0;
				}	
				zz = 3;
			}
			if(clearreadingRB < 100 && clearreadingLB > 100 && zz == 2){
				while(clearreadingRB < 100){
					LsetSpeed = 0;
					RsetSpeed = -10;
					if(clearreadingR1 > 150){
						saveLeft = 0;
						saveRight = 0;
						stop();
						Reset();
						detected = 6;
						PTE4o = 1;
						// shit
						cse = 7;
						clearreadingRB = 101;
						recover2 = 1;
						//break;
					}
				}
				if(recover2 == 0){							 
					zz = 3;
				}else{
					zz = 4;
				}
			}
			if(clearreadingRB > 100 && clearreadingLB > 100 && zz == 2){
				zz = 3;
			}
			if(zz == 3){
				stop();
				cse = 4;
			}
			break;		
			case 4: zz = 0;
			s = 0;
			while(fin4 == 0){
				TurnLeft(8500,-20,-20);
			}
			if(fin4 == 1){
				cse = 5;
				fin4 = 0;
			}
			break;		  	  	 
			case 5: saveLeft = 0;
			saveRight = 0;
			stop();
			Reset();
			countLineThree = 0;
			detected = 6;
			PTE4o = 1;
			cse = 6;
			saveForward = 0; 
			break;
			case 7:
				PTE4o = 0;
				TurnRight(17000,20,20);
				if(fin3 == 1){
					fin3 = 0;
					cse = 8;
				}
				break;
			case 8: if(clearreadingL1 < 150){
				LsetSpeed = 4;
				RsetSpeed = -10;
			}else{
				cse = 9;
			}
			break;
			case 9:
				if(stickLine1 == 0){
					if(clearreadingL1 > 150){
						LsetSpeed = 10;
						RsetSpeed = -10;
					} 
					if(clearreadingL1 < 150){
						LsetSpeed = 10;
						RsetSpeed = 0; 
					} 
					if(clearreadingL1 > 150 && clearreadingLB > 100){
						stickLine1 = 1;
					}
				}else{
					flag = 1; // shit
					stopDetected = 1;
					countLineThree = 0;
					countLineOne = 1;
					cse = 6;
				}
				break;
		}
	}
}

void detectPelletCommonZone(int cse5)
{
	while(cse5 != 6){			   
		switch(cse5)
		{
		case 1: countLineFive = 1;
		stop();
		TurnRight(10000,15,15);
		if(fin3 == 1)
		{
			while(clearreadingLB < 230 && clearreadingRB <230)
			{
				LsetSpeed = 10;
				RsetSpeed = -10;
			}
			while(clearreadingLB < 240)
			{
				LsetSpeed = 10;
				RsetSpeed = 0;
			}
			while(clearreadingRB < 170)
			{
				LsetSpeed = 0;
				RsetSpeed = -10;
			}
			/*stop();   	
				for(xx = 0; xx < 1000 ; xx++);*/	  	    
			cse5 = 2;
			fin3 = 0;
		}
		break;

		case 2: saveRight = 0;
		Forward(37,20);	
		PTA13o = 1;
		PTA12o = 1;
		if(fin1 == 1)
		{
			cse5 = 3;
			fin1 = 0;
		} 
		break;		    				  	  		  	  	  	  	  

		case 3: 
			PTA13o = 0;
			PTA12o = 0;
			while(clearreadingL1 < 230 && clearreadingR1 <230)
			{
				LsetSpeed = -20;
				RsetSpeed = 20;
			}

			for(xx = 0; xx < 5000 ; xx++);
			analogCount = 0;
			cse5 = 4;
			break;

		case 4:
			while(fin4 == 0)
			{
				TurnLeft(11000,-15,-15);
			}
			if(fin4 == 1)
			{
				/*if(clearreadingR1 < 200 && f6 == 0)
				{
					LsetSpeed = 10;
					RsetSpeed = 0;
				}
				else if(clearreadingR1 > 180 && f6 == 0)
				{
					f6 = 1;
				}*/

				if(clearreadingRB < 180)
				{
					LsetSpeed = 10;
					RsetSpeed = 0;
				}
				else if(clearreadingRB > 180)
				{
					cse5 = 5;
					fin4 = 0;
				}

				//if(clearreadingR1> 180 && clearreadingRB > 160 && f6 == 2)
				//{					
				//}
			}
			break;

		case 5: saveLeft = 0;
		countLineFive = 0;
		stop();
		Reset();
		detected = 6;
		PTE4o = 1;
		cse5 = 6;
		break;		    				  	  	  
		}
	}
}

void moveToMidLine()
{
	if(clearreadingR1 > 120)
	{
		stopDetected = 1;
		analogCount = 0;
	}
	if(clearreadingL2 > 180 && clearreadingLB > 180 && clearreadingRB > 160)
	{
		if(flag == 0)
		{
			step = 1;
		}
		while(step != 5)
		{			
			switch(step){
			case 1: countLineThree = 1;
			saveForward = 0;
			saveRight = 0;
			stop();
			step = 2;
			break;

			case 2: Forward(1,10);
			if(fin1 == 1)
			{
				step = 3;
				fin1 = 0;
			}
			break;

			case 3: TurnRight(13500,15,15);
			if(fin3 == 1)
			{
				step = 4;
				fin3 = 0;
				saveForward = 0;	
			}
			break;

			case 4: Forward(20,20);
			if(clearreadingL1 < 80 && clearreadingL2 > 80) { 
				LsetSpeed = 20; 
				RsetSpeed = 0;
			} 
			if(clearreadingL1 > 80 && clearreadingL2 < 80) {
				LsetSpeed = 0;
				RsetSpeed = -20;
			} 
			if(clearreadingL1 < 80 && clearreadingL2 < 80) {
				LsetSpeed = 0;
				RsetSpeed = -20;
			}
			if(fin1 == 1)
			{
				step = 5;
				fin1 = 0;
				flag = 1;
				countLineThree = 0;
				countLineOne = 1;

			}
			break;
			}
		}					
	}		  
	if(clearreadingR1 > 150 && countLineOne == 1)
	{
		PTE5o = 0;
		saveRight = 0;
		countLineOne = 3;
		countLineThree = 1;
		saveRight = 0;
		saveForward = 0;
		//stop();
	}
	if(countLineOne == 3)
	{
		Forward(4,8);
		PTA13o = 1;
		PTA12o = 1;
		if(fin1 == 1)
		{
			PTA13o = 0;
			PTA12o = 0;
			countLineOne = 4;
			fin1 = 0;
		}
	}
	if(countLineOne == 4)
	{
		if(fin3 == 0)
		{
			TurnRight(28000,15,0); // change?? #################################
			openRoller = 1; //Open roller

		}
		else
		{	
			if(fin1 == 0)
			{
				GoAndFollowR2(7,5);
			}
			else
			{

				fin1 = 0;
				SortingProcess(1);		 
				saveRight = 0;
				if(clearreadingL1 > 180)
				{					
					stop();
					for(xx = 0; xx < 10000;xx++);
					start = 2;
					fin3 = 0;	
					openRoller = 0;
					saveRight = 0;
					//SortingProcess(0);

				}
				else
				{
					RCControl('u');
					GoAndFollowR2(6,0);

				}
			}
		}
	}			
}

void collectFirstTime()
{	
	while(cse1!= 10)
	{
		switch(cse1){
		case 1:collectingFirstPellet = 0;
		collectingPelletTotalCount = 0; 
		TurnRight(11500,20,20);
		PTE5o = 0;
		if(fin3 == 1){
			cse1 = 2;
			fin3 = 0;
		}
		break;
		case 2: if(clearreadingRB < 180){
			LsetSpeed = 15;
			RsetSpeed = -15;
		}else{
			stop();
			if(wait == 1){
				xbeeWaitCount = 0;
				while(xbeeReceive !='W' && xbeeWaitCount<10000 );
				wait = 0;
			}
			cse1 = 3;
			saveRight = 0;
		}
		break;
		case 3:RCControl('d'); 
		TurnRight(13500,20,20); // CHANGE?? ###################################3
		if(fin3 == 1){	
			cse1 = 4;
			fin3 = 0;				
		}
		break;
		case 4: 
			cse1 = 5;
			break;
		case 5: saveLeft = 0;
		GoAndFollowR2(25,181);
		CollectingProcess(1);
		if(fin1 == 1){	
			openRoller = 2;
			PTA12o = 1;
			PTA13o = 1;
			cse1 = 6;
			fin1 = 0;
		}
		break;
		case 6: if(clearreadingR1 > 150 && sr == 0){ // emoo
			sr = 1;
		}
		if(clearreadingR1 < 30 && sr == 1){
			sr = 2;
		}
		if(clearreadingR1 > 150 && sr == 2){
			sr = 3;
			stop();
			cse1 = 9;
		}
		if(sr != 3){
			speedTurnLeft(30000,0,10,17);	
		}	
		if(fin5 == 1){
			cse1 = 7;
			fin5 = 0;
			if(send == 1){
				SendXBee('A');
			}
		}		
		break;

		case 7: sr = 0;
		if(clearreadingR1 > 150){
			LsetSpeed = 0;
			RsetSpeed = 0;
			cse1 = 8;
		}else{
			LsetSpeed = 15;
			RsetSpeed = -15;
		}
		break;
		case 8: if(clearreadingR1 > 150 && clearreadingRB < 100){
			LsetSpeed = 10;
			RsetSpeed = -10;
		}
		if(clearreadingR1 < 150 && clearreadingRB < 100){
			LsetSpeed = 0;
			RsetSpeed = -10;
		}
		if(clearreadingR1 > 150 && clearreadingRB > 100){
			cse1 = 9;
		}
		saveForward = 0;
		xbeeWaitCount = 0;
		break;
		case 9:if(clearreadingL1>100 && clearreadingLB>100){
			start = 3;
			cse1 = 11;
			saveForward = 0;
			//openRoller = 0;
		}else{
			GoAndFollowR1S(20,0);
		}
		break;
		case 11:	openRoller = 0; 
		LsetSpeed = 10;
		RsetSpeed = -10;
		for(xx=0;xx<100000;xx++);
		LsetSpeed = -10;
		RsetSpeed = 10;
		for(xx=0;xx<100000;xx++);
		cse1 = 10;
		break;
		}
	}
}

void collectSecondTime()
{
	saveLeft = 0;
	while(cse2 != 12)
	{
		switch(cse2){	   		
		case 1: collectingPelletTotalCount = 1;
		if(fin4 == 0){
			TurnLeft(11500,-15,-15); //####################################3 Change
		}else{
			if(send == 0){		
				SendXBee('T');
			}
			while(xbeeReceive  != 'T' && xbeeWaitCount < 100000); 
			cse2 = 2;
			fin4 = 0;
		}
		break;
		case 2: GoAndFollowR1(10,30);
		if(fin1 == 1){
			stop();
			for(xx = 0; xx > 1000; xx++);
			cse2 = 3;
			fin1 = 0;
		}
		break;
		case 3: GoAndFollowR1(25,0);
		if(clearreadingLB > 100 && countLineFour == 0){
			countLineFour = 1;
			saveLeft = 0;
		}
		if(clearreadingL1 > 100 && countLineFour == 1){
			stop();
			for(xx = 0; xx<50000;xx++);
			cse2 = 4;
		}
		break;
		case 4: TurnLeft(13000,-15,-15);
		if(fin4 == 1){
			stop();
			for(xx = 0; xx<50000;xx++);
			cse2 = 5;
			fin4 = 0;
		}
		break;
		case 5: GoAndFollowR1(25,116);
		if(fin1 == 1){
			stop();
			for(xx= 0 ; xx < 50000; xx++ );
			saveLeft = 0;
			cse2 = 6;
			fin1 = 0;
		}
		break;
		case 6: 
			if(fin4 == 0){
				TurnLeft(7000,-15,-15); // Change############
			}
			if(fin4 == 1){	
				if(clearreadingR1>150){
					stop();
					cse2 = 7;
					fin4 = 0;
				}else{
					LsetSpeed = 10;
					RsetSpeed = -10;
				}
			}
			break;
		case 7: saveLeft = 0;
		saveRight = 0;			
		if(stickLine == 0){
			if(clearreadingR1 > 150 && clearreadingRB < 100){
				LsetSpeed = 10;
				RsetSpeed = -10;
			} 
			if(clearreadingR1 < 150 && clearreadingRB < 100){
				LsetSpeed = 0;
				RsetSpeed = -10; 
			} 
			if(clearreadingR1 > 150 && clearreadingRB > 100){
				stickLine = 1;
			}
		}else{
			GoAndFollowR1S(25,162);
		}
		CollectingProcess(1); //opening the sorting process
		if(fin1 == 1){
			openRoller = 2;
			PTA12o = 1;
			PTA13o = 1;
			cse2 = 8;
			fin1 = 0;
		}
		break;
		case 8:speedTurnLeft(30000,0,10,17);
		if(clearreadingR1 < 30 && recover == 0){
			recover = 1;
		}
		if(clearreadingR1 > 100 && recover == 1){
			cse2 = 11;
			fin5 = 0;
		}
		if(fin5 == 1){
			cse2 = 9;
			fin5 = 0;
		}		
		break;
		case 9: recover = 0;
		if(clearreadingR1 > 150){
			LsetSpeed = 0;
			RsetSpeed = 0;
			cse2 = 10;		
		}else{
			LsetSpeed = 15;
			RsetSpeed = -15;
		}
		break;				
		case 10: if(clearreadingR1 > 150 && clearreadingRB < 100){
			LsetSpeed = 10;
			RsetSpeed = -10;
		}
		if(clearreadingR1 < 150 && clearreadingRB < 100){
			LsetSpeed = 0;
			RsetSpeed = -10;
		}
		if(clearreadingR1 > 150 && clearreadingRB > 100){
			cse2 = 11;
		}
		break;
		case 11 : if(clearreadingL1>150 && clearreadingLB>150){
			LsetSpeed = 0;
			RsetSpeed = 0;
			openRoller = 0;
			start = 4;
			cse2 = 12;
			SendXBee('S');
		}else{
			GoAndFollowR1S(15,0);
		}	 
		break;
		}
	}
}

void commonZoneOne(void)
{
	while(cse3!=9){
		switch(cse3){
		case 1: Forward(4,15);
		if(fin1 == 1){
			fin1 = 0;
			cse3 = 2;
			saveForward = 0;
		}
		break;
		case 2: BackWard(14,15);
		if(fin2 == 1){
			fin2 = 0;
			cse3 = 3;
			saveBackward = 0;
		}
		break;
		case 3: TurnRight(10000,20,20);
		if(fin3 == 1){
			fin3 = 0;
			cse3 = 4;
			saveRight = 0;
		}
		break;
		case 4: LsetSpeed = 10;
		RsetSpeed = -10;
		for(xx=0;xx<200000;xx++);
		cse3 = 5;
		break;
		case 5:if((clearreadingRB < 100 || clearreadingLB < 100) && rr == 1 ){
			while(clearreadingLB < 100 && clearreadingRB < 100){
				LsetSpeed = -10;
				RsetSpeed = 10;
			}
			rr = 2;
		}
		if(clearreadingRB > 100 && clearreadingLB < 100 && rr == 2){
			while(clearreadingLB < 100){
				LsetSpeed = -10;
				RsetSpeed = 0;
			}	
			rr = 3;
		}
		if(clearreadingRB < 100 && clearreadingLB > 100 && rr == 2){
			while(clearreadingRB < 100){
				LsetSpeed = 0;
				RsetSpeed = 10;
			}	
			rr = 3;
		}
		if(clearreadingRB > 100 && clearreadingLB > 100 && rr == 2){
			rr = 3;
		}
		if(rr == 3){
			stop();
			cse3 = 6;
		}
		break;	
		case 6: TurnRight(10000,20,20);
		if(fin3 == 1){
			fin3 = 0;
			cse3 = 7;
			saveRight= 0;
		}
		break;
		case 7: if(clearreadingRB < 100){
			LsetSpeed = 15;
			RsetSpeed = -15;
		}else{
			stop();
			for(xx=0; xx<50000;xx++);
			cse3 = 8;
		}
		break;
		case 8: if(fin3 == 0){
			TurnRight(14000,15,-15); // change?? #################################
					openRoller = 1; //Open roller
		}else{	
			if(fin1 == 0){
				GoAndFollowR2(7,5);
			}else{
				fin1 = 0;
				SortingProcess(1);		 
				saveRight = 0;
				if(clearreadingL1 > 180){					
					stop();
					for(xx = 0; xx < 10000;xx++);
					cse3 = 9;
					start = 4;
					fin3 = 0;	
					openRoller = 0;
					saveRight = 0;
					//SortingProcess(0);
				}
				else{
					RCControl('u');
					GoAndFollowR2(6,0);
				}
			}
		}
		break;
		}
	}
}









/*lint -save  -e970 Disable MISRA rule (6.3) checking. */


int main(void){
	/*lint -restore Enable MISRA rule (6.3) checking. */                                                                                                                                                                  
	/* Write your local variable definition here */

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */

	writeAXRegister(MaxTorque);
	for(i=0;i<1000;i++);
	writeAXRegister(Compliance);
	for(i=0;i<1000;i++);
	writeAXRegister(ServoMode);
	for(i=0;i<1000;i++);   

	//open later



	while((xbeeReceive != 'G' && xbeeWaitCount < 40000) && PTD0i == 1);
	// while(PTD0i == 1);
	Servo = 1;
	ServoDeg(9); 
	for(i=0;i<300000;i++);
	PTE4o = 1;
	PTE5o = 0;

	while(1)
	{		 
		BattMon();


		if(start == 0)
		{
			cse6 = 1;
			randomPush();
			start = 1;
		}

		if(start == 1)
		{
			if(countLineThree == 0)

			{
				LsetSpeed = 20;
				RsetSpeed = -20;
				if(clearreadingL1 < 80 && clearreadingL2 > 80)
				{
					LsetSpeed = 20;
					RsetSpeed = 0;
				}
				if(clearreadingL1 > 80 && clearreadingL2 < 80)
				{
					LsetSpeed = 0;
					RsetSpeed = -20;
				}
				if(clearreadingL1 < 80 && clearreadingL2 < 80)
				{
					LsetSpeed = 0;
					RsetSpeed = -20;
				}
			}
			moveToMidLine();

			if(analog > 54 && firstDetected == 0){
				firstDetected = 1;
				analogCount = 0;
			}
			if(firstDetected == 1 && analogCount > 400){
				detected = 1;
				firstDetected = 0;
				PTE4o = 0;
				analogCount = 0;

			}
			else{
				detected = 6;
				PTE4o = 1;
			}
		}
		if(stopDetected == 0)
		{
			detectPellet(detected);
		}
		else
		{
			PTE5o = 1;
		}



		if(start == 2)
		{
			cse1 = 1;
			collectFirstTime();

		}

		if(start == 3)
		{
			cse2 = 1;
			saveBackward = 0;
			collectSecondTime();
			saveLeft = 0;
		}
		if(start == 4)
		{
			cse3 = 1;
			commonZoneOne();
		}
		if(start == 5){
			send = 1;
			openRoller = 0;
			cse1 = 1;
			collectFirstTime();
			saveForward = 0;
			if(start == 3)
			{
				last = 1;
				start = 10;
			}
		}

		if(last == 1)
		{
			LsetSpeed = 10;
			RsetSpeed = -10;
			for(xx=0;xx<100000;xx++);
			LsetSpeed = -10;
			RsetSpeed = 10;
			for(xx=0;xx<100000;xx++);
			last = 0;
			saveLeft = 0;
			start = 6;
		}
		if(start == 6)
		{
			TurnLeft(95000,-15,-15);
			if(fin4 == 1)
			{
				start = 7;
				fin4 = 0;
			}
		}
		if(start == 7)
		{
			stop();
			start = 8;
		}



	}// end of while

		/* For example: for(;;) { } */

		/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
		/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
/*** End of RTOS startup code.  ***/
/*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
for(;;){}
/*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
