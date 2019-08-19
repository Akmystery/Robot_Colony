/*
 * UART.h
 *
 *  Created on: Apr 5, 2016
 *      Author: lbs1
 */
#ifndef UART_H_
#define UART_H_

/************/
/*   UART   */
/************/

//   UARTx (UART0, UART1, UART2 or UART3)
//     - Use Init_UART to setup UARTx, baud rate, enable clock gate, enable Receive Full interrupt, enable Tx and Rx and select pins in Processor Expert
//     - sendxChar, sendxString functions provided
//     - received bytes are stored in circular buffer uartxBuffer of length 10 in the uartxisr. Change the length of buffer as necessary     

/* UART0 */
#define UART0_S1 (*(ioreg8 *)0x4006A004) // UART0 status register 1 whose bit 6 is transmit complete
#define TC0 UART0_S1.B6					 // UART0 Transmit Complete flag
#define RDRF0 UART0_S1.B5				 // UART0 Receive Data Register Full flag

volatile char uart0Buffer[10];			 // circular buffer to store bytes received via interrupt
volatile int  index0 = 0;				 // index for uart buffer
volatile char rx0char;					 // variable to store received character from serial port

void send0Char (char x){
	  while(TC0 != 1);
	  UART0_D = x; 
	  TC0 = 0;
}

void send0String (char* ptr){
	while (*ptr != 0) {
		send0Char(*ptr);
		ptr++;
	}
	send0Char(13);	// optional
}
void uart0isr (void){
	RDRF0 = 0;	// clear flag
	rx0char = UART0_D;
	uart0Buffer[index0] = rx0char; //UART0_D;
	index0++;
	if (rx0char == 13){ // check for '\r' to reset index
		index0 = 0;
	}
	if (index0 > 9) {	// check for buffer overflow to reset index
		index0 = 0;
	}
}


/* UART1 */
volatile char uart1Buffer[10];			 // circular buffer to store bytes received via interrupt
volatile int  index1 = 0;				 // index for uart buffer
volatile char rx1char;					 // variable to store received character from serial port
#define UART1_S1 (*(ioreg8 *)0x4006B004) // UART1 status register 1 whose bit 6 is transmit complete
#define TC1 UART1_S1.B6					 // UART1 Transmit Complete flag'
#define RDRF1 UART1_S1.B5				 // UART1 Receive Data Register Full flag

void send1Char (char x){
	  while(TC1 != 1);
	  UART1_D = x; 
	  TC1 = 0;
}

void send1String (char* ptr){
	while (*ptr != 0) {
		send1Char(*ptr);
		ptr++;
	}
	send1Char(13);	// optional
}

void uart1isr (void){
	RDRF1 = 0;	// clear flag
	rx1char = UART1_D;
	uart1Buffer[index1] = rx1char; //UART0_D;
	index1++;
	if (rx1char == 13){ // check for '\r' to reset index
		index1 = 0;
	}
	if (index1 > 9) {	// check for buffer overflow to reset index
		index1 = 0;
	}
}

/* UART2 */
volatile char uart2Buffer[10];			 // circular buffer to store bytes received via interrupt
volatile int  index2 = 0;				 // index for uart buffer
volatile char rx2char;					 // variable to store received character from serial port
#define UART2_S1 (*(ioreg8 *)0x4006C004) // UART2 status register 1 whose bit 6 is transmit complete
#define TC2 UART2_S1.B6					 // UART2 Transmit Complete flag'
#define RDRF2 UART2_S1.B5				 // UART2 Receive Data Register Full flag

void send2Char (char x){
	  while(TC2 != 1);
	  UART2_D = x; 
	  TC2 = 0;
}

void send2String (char* ptr){
	while (*ptr != 0) {
		send2Char(*ptr);
		ptr++;
	}
	send2Char(13);	// optional
}

/*void uart2isr (void){
	RDRF2 = 0;	// clear flag
	rx2char = UART2_D;
	uart2Buffer[index2] = rx2char; //UART0_D;
	index2++;
	if (rx2char == 13){ // check for '\r' to reset index
		index2 = 0;
	}
	if (index2 > 9) {	// check for buffer overflow to reset index
		index2 = 0;
	}
}*/

/* UART3 */
volatile char uart3Buffer[10];			 // circular buffer to store bytes received via interrupt
volatile int  index3 = 0;				 // index for uart buffer
volatile char rx3char;					 // variable to store received character from serial port
#define UART3_S1 (*(ioreg8 *)0x4006D004) // UART3 status register 1 whose bit 6 is transmit complete
#define TC3 UART3_S1.B6					 // UART3 Transmit Complete flag'
#define RDRF3 UART3_S1.B5				 // UART3 Receive Data Register Full flag

void send3Char (char x){
	  while(TC3 != 1);
	  UART3_D = x; 
	  TC3 = 0;
}

void send3String (char* ptr){
	while (*ptr != 0) {
		send3Char(*ptr);
		ptr++;
	}
	send3Char(13);	// optional
}

void uart3isr (void){
	RDRF3 = 0;	// clear flag
	rx3char = UART3_D;
	uart3Buffer[index3] = rx3char; //UART0_D;
	index3++;
	if (rx3char == 13){ // check for '\r' to reset index
		index3 = 0;
	}
	if (index3 > 9) {	// check for buffer overflow to reset index
		index3 = 0;
	}
}

#endif /* UART_H_ */
