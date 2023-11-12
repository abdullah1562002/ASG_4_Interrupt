/*
 * EXTI_private.h
 *
 * Created: 9/2/2023 10:53:08 PM
 *  Author: Kareem Hussein
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


                          /* EXTERNAL INTERRUPT REGISTERS */

// MCU Control Register
#define MCUCR          (*(volatile u8*)0x55)
#define ISC00          0
#define ISC01          1
#define ISC10          2
#define ISC11          3

// MCU Control and Status Register
#define MCUCSR         (*(volatile u8*)0x54)
#define ISC2           6

// General Interrupt Control Register
#define GICR           (*(volatile u8*)0x5B)
#define INT0            6
#define INT1            7
#define INT2            5

// General Interrupt Flag Register
#define GIFR           (*(volatile u8*)0x5A)
#define INTF0          6
#define INTF1          7
#define INTF2          5



#endif /* EXTI_PRIVATE_H_ */