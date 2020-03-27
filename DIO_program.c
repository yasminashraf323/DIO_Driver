/**********************************************/
/*Auther  :YASMIN ASHRAF TOEMA                */
/*Version :V01                                */  
/*Date    :25/3/2020                          */
/*Descriotion : IMPLEMENTATION FUNCTION       */ 
/**********************************************/


/** STD LIB DIRECTIVES **/
#include"STD_types.h"
#include"BIT_MATH.h"
#include"ERROR_STATUS.h"
/************************/

/** COMPONENT DIRECTIVES **/
#include"DIO_interface.h"
#include"DIO_register.h"
/**************************/

/************************** FUNCTIONS IMPLEMENTATION *********************************/
/*************************************************************************************/
/*      Descriotion       : This Function  Used To Set Port Direction                */
/*      Inputs            : PortID And Direction                                     */
/*      outputs           :  ErrorStatus                                             */
/*************************************************************************************/
ErrorStatus  DIO_enumSetPortDirection( u8 DIO_u8 PortID,u8 DIO_u8 Direction)
{
	ErrorStatus Local_error= ES_NOK;
	if(DIO_u8 PortID < 4)
	{
		switch(PortID)
		{
			case PortA: DIO_U8_DDRA = DIO_u8 Direction; break; 
			case PortB: DIO_U8_DDRB = DIO_u8 Direction; break;
			case PortC: DIO_U8_DDRC = DIO_u8 Direction; break;
			case PortD: DIO_U8_DDRD = DIO_u8 Direction; break;
		}
		Local_error= ES_OK;
	}
	else
	{
	Local_error= ES_OUT_OF_RANGE;	
	}
	return Local_error;
}  
/***************************************************************************************************/
/***************************************************************************************************/
/*      Descriotion       : This Function  Used To Set Pin Direction                              */
/*      Inputs            : PortID ,PinID And Direction                                                   */
/*      outputs           :  ErrorStatus                                                           */
/***************************************************************************************************/
ErrorStatus  DIO_enumSetPinDirection( u8 DIO_u8PortID,u8 DIO_u8PinID,u8 DIO_u8Direction)
{
	ErrorStatus Local_error= ES_NOK;
	if((DIO_u8 PortID < 4)&&(DIO_u8 PinID<8))
	{
		if(DIO_u8 Direction==DIO_U8_OUTPUT)
		{
		switch(PortID)
		{
			case PORTA: SET_BIT(DIO_U8_DDRA,DIO_u8PinID); break; 
			case PORTB: SET_BIT(DIO_U8_DDRB,DIO_u8PinID); break;
			case PORTC: SET_BIT(DIO_U8_DDRC,DIO_u8PinID); break;
			case PORTD: SET_BIT(DIO_U8_DDRD,DIO_u8PinID); break;
		}
		}else
		{
		 Local_error= ES_OUT_OF_RANGE;
		}
		Local_error= ES_OK;
	}
	else
	{
	Local_error= ES_OUT_OF_RANGE;	
	}
	return Local_error;
} 
/**************************************************************************/
/**************************************************************************/
/*      Descriotion       : This Function  Used To Set Port value         */
/*      Inputs            : PortID And Value                              */
/*      outputs           :  ErrorStatus                                  */
/**************************************************************************/
ErrorStatus  DIO_enumSetPortValue( u8 DIO_u8PortID,u8 DIO_u8Value)
{
	ErrorStatus Local_error= ES_NOK;
	if(DIO_u8 PortID < 4)
	{
		switch(PortID)
		{
			case PORTA: DIO_U8_PORTA =  DIO_u8 Value; break; 
			case PORTB: DIO_U8_PORTB =  DIO_u8 Value; break;
			case PORTC: DIO_U8_PORTC =  DIO_u8 Value; break;
			case PORTD: DIO_U8_PORTD =  DIO_u8 Value; break;
		}
		Local_error= ES_OK;
	}
	else
	{
	Local_error= ES_OUT_OF_RANGE;	
	}
	return Local_error;
} 
/*************************************************************************************/
/*************************************************************************************/
/*      Descriotion       : This Function  Used To Set Pin Value                     */
/*      Inputs            : PortID,PinID And Value                                   */
/*      outputs           :  ErrorStatus                                             */
/*************************************************************************************/
ErrorStatus  DIO_enumSetPinValue( u8 DIO_u8PortID,u8 DIO_u8PinID,u8 DIO_u8Value)
{
	ErrorStatus Local_error= ES_NOK;
	if((DIO_u8 PortID < 4)&&(DIO_u8 PinID<8))
	{
		if(DIO_u8Value==DIO_U8_HIGH)
		switch(PortID)
		{
			case PORTA: SET_BIT(DIO_U8_PORTA,DIO_u8PinID); break; 
			case PORTB: SET_BIT(DIO_U8_PORTB,DIO_u8PinID); break;
			case PORTC: SET_BIT(DIO_U8_PORTC,DIO_u8PinID); break;
			case PORTD: SET_BIT(DIO_U8_PORTD,DIO_u8PinID); break;
		}
		else if(DIO_u8Value==DIO_U8_LOW)
		{
			switch(PortID)
		   {
			case PORTA: CLR_BIT(DIO_U8_PORTA,DIO_u8PinID); break; 
			case PORTB: CLR_BIT(DIO_U8_PORTB,DIO_u8PinID); break;
			case PORTC: CLR_BIT(DIO_U8_PORTC,DIO_u8PinID); break;
			case PORTD: CLR_BIT(DIO_U8_PORTD,DIO_u8PinID); break;
		   }
		   Local_error= ES_OK;
		}
		
	}
	else
	{
	Local_error= ES_OUT_OF_RANGE;	
	}
	return Local_error;
} 
/*************************************************************************************/
/*************************************************************************************/
/*      Descriotion       : This Function  Used To Get Pin Value                     */
/*      Inputs            : PortID And PinID                                    */
/*      outputs           :  U8 (unsigned char)                                      */
/*************************************************************************************/
u8  DIO_enumGetPinValue( u8 DIO_u8 PortID,u8 DIO_u8PinID)
{
	ErrorStatus Local_error= ES_NOK;
	u8 Local_u8value = 0;
	if((DIO_u8 PortID < 4)&&(DIO_u8 PinID<8))
	{
		switch(PortID)
		{
			case PORTA: Local_value = GET_BIT(DIO_U8_PINA,DIO_u8PinID); break; 
			case PORTB: Local_value = GET_BIT(DIO_U8_PINB,DIO_u8PinID); break;
			case PORTC: Local_value = GET_BIT(DIO_U8_PINC,DIO_u8PinID); break;
			case PORTD: Local_value = GET_BIT(DIO_U8_PIND,DIO_u8PinID); break;
		}
		Local_error= ES_OK;
	}
	else
	{
	Local_error= ES_OUT_OF_RANGE;	
	}
	return Local_u8value;
	
}
/******************************************************************************************/