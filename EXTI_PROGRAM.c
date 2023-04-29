/*
 * EXTI_PROGRAM.c
 *
 *  Created on: Apr 25, 2023
 *      Author: youss
 */

#include "STD_TYPES.h"
#include "REGISTERS.h"
#include "DIO_INTERFACE.h"
#include "BITMATH.h"
#include "EXTI_INTERFACE.h"



static void (*EXTI_Ptr_CallBack_INT0)(void) = NULL;
static void (*EXTI_Ptr_CallBack_INT1)(void) = NULL;
static void (*EXTI_Ptr_CallBack_INT2)(void) = NULL;


EXTI_Error_Status EXTI_SensingStateINT0(u8 Copy_u8SenseState){

	u8 Loc_Error_Status = EXTI_No_Error;

	switch(Copy_u8SenseState){

	case EXTI_FallingEdge:

		SetBit(MCUCR,MCUCR_ISC01);
		ClrBit(MCUCR,MCUCR_ISC00);

		break;

	case EXTI_LowLevel:

		ClrBit(MCUCR,MCUCR_ISC01);
		ClrBit(MCUCR,MCUCR_ISC00);

		break;

	case EXTI_OnChange:

		SetBit(MCUCR,MCUCR_ISC00);
		ClrBit(MCUCR,MCUCR_ISC01);

		break;

	case EXTI_RisingEdge:

		SetBit(MCUCR,MCUCR_ISC01);
		SetBit(MCUCR,MCUCR_ISC00);

		break;

	default:
		Loc_Error_Status = EXTI_SenseState_Error;
	}
	return Loc_Error_Status;
}

EXTI_Error_Status EXTI_SensingStateINT1(u8 Copy_u8SenseState){

	u8 Loc_Error_Status = EXTI_No_Error;

	switch(Copy_u8SenseState){

	case EXTI_FallingEdge:

		SetBit(MCUCR,MCUCR_ISC11);
		ClrBit(MCUCR,MCUCR_ISC10);

		break;

	case EXTI_LowLevel:

		ClrBit(MCUCR,MCUCR_ISC11);
		ClrBit(MCUCR,MCUCR_ISC10);

		break;

	case EXTI_OnChange:

		SetBit(MCUCR,MCUCR_ISC10);
		ClrBit(MCUCR,MCUCR_ISC11);

		break;

	case EXTI_RisingEdge:

		SetBit(MCUCR,MCUCR_ISC11);
		SetBit(MCUCR,MCUCR_ISC10);

		break;

	default:
		Loc_Error_Status = EXTI_SenseState_Error;
	}
	return Loc_Error_Status;
}

EXTI_Error_Status EXTI_SensingStateINT2(u8 Copy_u8SenseState){

	u8 Loc_Error_Status = EXTI_No_Error;

	switch(Copy_u8SenseState){

	case EXTI_FallingEdge:

		ClrBit(MCUCR,MCUCSR_ISC2);

		break;

	case EXTI_RisingEdge:

		SetBit(MCUCR,MCUCSR_ISC2);

		break;

	default:
		Loc_Error_Status = EXTI_SenseState_Error;
	}
	return Loc_Error_Status;
}

void EXTI_VoidEnableINT0(void){

	SetBit(GICR,GICR_INT0);
}

void EXTI_VoidEnableINT1(void){

	SetBit(GICR,GICR_INT1);
}

void EXTI_VoidEnableINT2(void){

	SetBit(GICR,GICR_INT2);
}

void EXTI_VoidDisableINT0(void){

	ClrBit(GICR,GICR_INT0);

}

void EXTI_VoidDisableINT1(void){

	ClrBit(GICR,GICR_INT1);

}

void EXTI_VoidDisableINT2(void){

	ClrBit(GICR,GICR_INT2);

}

void EXTI_VoidClrFlagInt0(void){

	SetBit(GIFR,GIFR_INTF0);
}

void EXTI_VoidClrFlagInt1(void){

	SetBit(GIFR,GIFR_INTF1);
}

void EXTI_VoidClrFlagInt2(void){

	SetBit(GIFR,GIFR_INTF2);
}


EXTI_Error_Status EXTI_InitINT0(u8 Copy_u8SenseState, void (*PtrCallBack)(void)){

	u8 Loc_Error_Status = EXTI_No_Error;

	if(PtrCallBack !=0){
		EXTI_Ptr_CallBack_INT0 = PtrCallBack;
	}
	else {
		Loc_Error_Status = EXTI_PtrCallBack_Error;
	}


	EXTI_SensingStateINT0(Copy_u8SenseState);
	EXTI_VoidEnableINT0();

	return Loc_Error_Status;
}
EXTI_Error_Status EXTI_InitINT1(u8 Copy_u8SenseState, void (*PtrCallBack)(void)){

	u8 Loc_Error_Status = EXTI_No_Error;

	if(PtrCallBack !=0){
		EXTI_Ptr_CallBack_INT1 = PtrCallBack;
	}
	else {
		Loc_Error_Status = EXTI_PtrCallBack_Error;
	}


	EXTI_SensingStateINT1(Copy_u8SenseState);
	EXTI_VoidEnableINT1();

	return Loc_Error_Status;
}
EXTI_Error_Status EXTI_InitINT2(u8 Copy_u8SenseState, void (*PtrCallBack)(void)){

	u8 Loc_Error_Status = EXTI_No_Error;

	if(PtrCallBack !=0){
		EXTI_Ptr_CallBack_INT2 = PtrCallBack;
	}
	else {
		Loc_Error_Status = EXTI_PtrCallBack_Error;
	}


	EXTI_SensingStateINT1(Copy_u8SenseState);
	EXTI_VoidEnableINT2();

	return Loc_Error_Status;
}

void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){

	if(EXTI_Ptr_CallBack_INT0 != NULL){
		EXTI_Ptr_CallBack_INT0();
	}
}

void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){

	if(EXTI_Ptr_CallBack_INT1 != NULL){
		EXTI_Ptr_CallBack_INT1();
	}
}

void __vector_3 (void) __attribute__((signal));
void __vector_3 (void){

	if(EXTI_Ptr_CallBack_INT2 != NULL){
		EXTI_Ptr_CallBack_INT2();
	}
}
