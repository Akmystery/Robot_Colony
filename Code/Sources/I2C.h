/*
 * I2C.h
 *
 *  Created on: Apr 5, 2016
 *      Author: lbs1
 */

#ifndef I2C_H_
#define I2C_H_

/************/
/*    I2C   */
/************/

#define I2C0b_C1 (*(ioreg8 *)0x40066002)		// I2C0 control register 1
#define I2C0b_S  (*(ioreg8 *)0x40066003)		// I2C0 status register
#define I2C0b_D  (*(ioreg8 *)0x40066004)		// I2C0 data register

#define I2C0_IFlag I2C0b_S.B1		// Interrupt flag

#define I2C1b_C1 (*(ioreg8 *)0x40067002)		// I2C1 control register 1
#define I2C1b_S  (*(ioreg8 *)0x40067003)		// I2C1 status register
#define I2C1b_D  (*(ioreg8 *)0x40067004)		// I2C1 data register

#define I2C1_En I2C1b_C1.B7			// Enable I2C1
#define I2C1_IEn I2C1b_C1.B6		// Enable I2C1 interrupt
#define I2C1_Master I2C1b_C1.B5		// Master/_Slave cum Start/_Stop activation
#define I2C1_Transmit I2C1b_C1.B4	// Transmit/Receive mode
#define I2C1_TxACK I2C1b_C1.B3		// 0 = Transmit ACK/NACK. 1 = Don't send.Also affected by FACK bit  
#define I2C1_RSTart I2C1b_C1.B2		// Send repeat start

#define I2C1_TCF I2C1b_S.B7			// Transfer Complete Flag
#define I2C1_IFlag I2C1b_S.B1		// Interrupt flag
#define I2C1_RACK I2C1b_S.B0		// 1 = No acknowledge, 0 = there is acknowledge

#endif /* I2C_H_ */
