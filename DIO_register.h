/**********************************************/
/*Auther  :YASMIN ASHRAF TOEMA                */
/*Version :V01                                */  
/*Date    :25/3/2020                          */
/*Descriotion : Registers Addresses           */ 
/**********************************************/

/***********************************************/
/* Guard of file will call one time in .c      */
/***********************************************/

#ifndef _DIO_REG_H_ 
#define _DIO_REG_H_


/*******************   PORTA Registers    *******************/
#define       DIO_U8_PORTA       *((volatile u8 *)0x3B)
#define       DIO_U8_DDRA        *((volatile u8 *)0x3A)
#define       DIO_U8_PINA        *((volatile u8 *)0x39)
/************************************************************/

/*******************   PORTB Registers    *******************/
#define       DIO_U8_PORTB       *((volatile u8 *)0x38)
#define       DIO_U8_DDRB        *((volatile u8 *)0x37)
#define       DIO_U8_PINB        *((volatile u8 *)0x36)
/************************************************************/

/*******************   PORTC Registers    *******************/
#define       DIO_U8_PORTC       *((volatile u8 *)0x35)
#define       DIO_U8_DDRC        *((volatile u8 *)0x34)
#define       DIO_U8_PINC        *((volatile u8 *)0x33)
/************************************************************/

/*******************   PORTD Registers    *******************/
#define       DIO_U8_PORTA       *((volatile u8 *)0x32)
#define       DIO_U8_DDRA        *((volatile u8 *)0x31)
#define       DIO_U8_PINA        *((volatile u8 *)0x30)
/************************************************************/

/*** END OF _DIO_REG_H_ ***/
#endif  
/**************************/