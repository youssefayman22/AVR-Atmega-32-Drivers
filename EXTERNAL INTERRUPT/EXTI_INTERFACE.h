/*
 * EXTI_INTERFACE.h
 *
 *  Created on: Apr 25, 2023
 *      Author: youss
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum{
	EXTI_No_Error,
	EXTI_SenseState_Error,
	EXTI_PtrCallBack_Error,
}EXTI_Error_Status;

#define EXTI_LowLevel		(0u)
#define EXTI_OnChange		(1u)
#define EXTI_FallingEdge	(2u)
#define EXTI_RisingEdge		(3u)

EXTI_Error_Status EXTI_SensingStateINT0(u8 Copy_u8SenseState);
void EXTI_VoidEnableINT0(void);
void EXTI_VoidDisableINT0(void);
void EXTI_VoidClrFlagInt0(void);
EXTI_Error_Status EXTI_InitINT0(u8 Copy_u8SenseState, void (*PtrCallBack)(void));

EXTI_Error_Status EXTI_SensingStateINT1(u8 Copy_u8SenseState);
void EXTI_VoidEnableINT1(void);
void EXTI_VoidDisableINT1(void);
void EXTI_VoidClrFlagInt1(void);
EXTI_Error_Status EXTI_InitINT1(u8 Copy_u8SenseState, void (*PtrCallBack)(void));

EXTI_Error_Status EXTI_SensingStateINT2(u8 Copy_u8SenseState);
void EXTI_VoidEnableINT2(void);
void EXTI_VoidDisableINT2(void);
void EXTI_VoidClrFlagInt2(void);
EXTI_Error_Status EXTI_InitINT2(u8 Copy_u8SenseState, void (*PtrCallBack)(void));

#endif /* EXTI_INTERFACE_H_ */
