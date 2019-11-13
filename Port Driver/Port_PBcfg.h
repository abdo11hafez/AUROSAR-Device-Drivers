/********************************************************************************
 **                                                                             **
 **  FOLDERNAME	  : Port_BPcfg.h         			                            **
 **                                                                             **
 **  VERSION      : 1.0.0                                                       **
 **                                                                             **
 **  DATE         : 2019-11-13                                                   **
 **                                                                             **                                                                             **
 **  PLATFORM     : AVR ATmega32                                                **
 **                                                                             **
 **  AUTHOR       : Abdelrahman Hafez.	                                        **
 **                                                                             **
 **  VENDOR       : Abdelrahman Hafez Co.LTD							        **
 **                                                                             **                                                                           **
 **  DESCRIPTION  : Post-Building Configuration Of Port Driver           **
 **                                                                             **
 **  SPECS        : Manuale coded									            **
 **                                                                             **
 **  MAY BE CHANGED BY USER : Yes                                               **
 **                                                                             **
 ********************************************************************************/

#ifndef PORT_PBCFG_H_
#define PORT_PBCFG_H_

#define PORTA_NUM_OF_PINS							    (8U)
#define PORTB_NUM_OF_PINS								(8U)
#define PORTC_NUM_OF_PINS								(8U)
#define PORTD_NUM_OF_PINS								(8U)

#define PORTA_PIN0_DIRECTION							(PORT_PIN_IN)	// LED2
#define PORTA_PIN1_DIRECTION							(PORT_PIN_IN)
#define PORTA_PIN2_DIRECTION							(PORT_PIN_IN)
#define PORTA_PIN3_DIRECTION							(PORT_PIN_IN)
#define PORTA_PIN4_DIRECTION							(PORT_PIN_IN)
#define PORTA_PIN5_DIRECTION							(PORT_PIN_IN)
#define PORTA_PIN6_DIRECTION							(PORT_PIN_IN)
#define PORTA_PIN7_DIRECTION							(PORT_PIN_IN)

#define PORTB_PIN0_DIRECTION							(PORT_PIN_IN)
#define PORTB_PIN1_DIRECTION							(PORT_PIN_IN)
#define PORTB_PIN2_DIRECTION							(PORT_PIN_IN)
#define PORTB_PIN3_DIRECTION							(PORT_PIN_IN)
#define PORTB_PIN4_DIRECTION							(PORT_PIN_IN)
#define PORTB_PIN5_DIRECTION							(PORT_PIN_IN)
#define PORTB_PIN6_DIRECTION							(PORT_PIN_IN)
#define PORTB_PIN7_DIRECTION							(PORT_PIN_IN)

#define PORTC_PIN0_DIRECTION							(PORT_PIN_IN)
#define PORTC_PIN1_DIRECTION							(PORT_PIN_IN)
#define PORTC_PIN2_DIRECTION							(PORT_PIN_IN)
#define PORTC_PIN3_DIRECTION							(PORT_PIN_IN)
#define PORTC_PIN4_DIRECTION							(PORT_PIN_IN)
#define PORTC_PIN5_DIRECTION							(PORT_PIN_OUT)	// LED1
#define PORTC_PIN6_DIRECTION							(PORT_PIN_IN)
#define PORTC_PIN7_DIRECTION							(PORT_PIN_IN)

#define PORTD_PIN0_DIRECTION							(PORT_PIN_IN)
#define PORTD_PIN1_DIRECTION							(PORT_PIN_IN)
#define PORTD_PIN2_DIRECTION							(PORT_PIN_IN)	//BUTTON
#define PORTD_PIN3_DIRECTION							(PORT_PIN_IN)
#define PORTD_PIN4_DIRECTION							(PORT_PIN_IN)
#define PORTD_PIN5_DIRECTION							(PORT_PIN_IN)
#define PORTD_PIN6_DIRECTION							(PORT_PIN_IN)
#define PORTD_PIN7_DIRECTION							(PORT_PIN_IN)

/************************************************************************************
*************************************************************************************/

#define PORTA_PIN0_DIR_CHANGEABLE							(TRUE)	 // LED2
#define PORTA_PIN1_DIR_CHANGEABLE							(FALSE)
#define PORTA_PIN2_DIR_CHANGEABLE							(FALSE)
#define PORTA_PIN3_DIR_CHANGEABLE							(FALSE)
#define PORTA_PIN4_DIR_CHANGEABLE							(FALSE)
#define PORTA_PIN5_DIR_CHANGEABLE							(FALSE)
#define PORTA_PIN6_DIR_CHANGEABLE							(FALSE)
#define PORTA_PIN7_DIR_CHANGEABLE							(FALSE)

#define PORTB_PIN0_DIR_CHANGEABLE							(FALSE)
#define PORTB_PIN1_DIR_CHANGEABLE							(FALSE)
#define PORTB_PIN2_DIR_CHANGEABLE							(FALSE)
#define PORTB_PIN3_DIR_CHANGEABLE							(FALSE)
#define PORTB_PIN4_DIR_CHANGEABLE							(FALSE)
#define PORTB_PIN5_DIR_CHANGEABLE							(FALSE)
#define PORTB_PIN6_DIR_CHANGEABLE							(FALSE)
#define PORTB_PIN7_DIR_CHANGEABLE							(FALSE)

#define PORTC_PIN0_DIR_CHANGEABLE							(FALSE)
#define PORTC_PIN1_DIR_CHANGEABLE							(FALSE)
#define PORTC_PIN2_DIR_CHANGEABLE							(FALSE)
#define PORTC_PIN3_DIR_CHANGEABLE							(FALSE)
#define PORTC_PIN4_DIR_CHANGEABLE							(FALSE)
#define PORTC_PIN5_DIR_CHANGEABLE							(TRUE)	// LED1
#define PORTC_PIN6_DIR_CHANGEABLE							(FALSE)
#define PORTC_PIN7_DIR_CHANGEABLE							(FALSE)

#define PORTD_PIN0_DIR_CHANGEABLE							(FALSE)
#define PORTD_PIN1_DIR_CHANGEABLE							(FALSE)
#define PORTD_PIN2_DIR_CHANGEABLE							(FALSE)	//BUTTON
#define PORTD_PIN3_DIR_CHANGEABLE							(FALSE)
#define PORTD_PIN4_DIR_CHANGEABLE							(FALSE)
#define PORTD_PIN5_DIR_CHANGEABLE							(FALSE)
#define PORTD_PIN6_DIR_CHANGEABLE							(FALSE)
#define PORTD_PIN7_DIR_CHANGEABLE							(FALSE)


/************************************************************************************
*************************************************************************************/

 #define PORTA_PIN0_INIT_MODE							(PORT_PIN_MODE_DIO)	 // LED2
 #define PORTA_PIN1_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTA_PIN2_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTA_PIN3_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTA_PIN4_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTA_PIN5_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTA_PIN6_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTA_PIN7_INIT_MODE							(PORT_PIN_MODE_DIO)

 #define PORTB_PIN0_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTB_PIN1_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTB_PIN2_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTB_PIN3_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTB_PIN4_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTB_PIN5_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTB_PIN6_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTB_PIN7_INIT_MODE							(PORT_PIN_MODE_DIO)

 #define PORTC_PIN0_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTC_PIN1_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTC_PIN2_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTC_PIN3_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTC_PIN4_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTC_PIN5_INIT_MODE							(PORT_PIN_MODE_DIO)	// LED1
 #define PORTC_PIN6_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTC_PIN7_INIT_MODE							(PORT_PIN_MODE_DIO)

 #define PORTD_PIN0_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTD_PIN1_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTD_PIN2_INIT_MODE							(PORT_PIN_MODE_DIO)	//BUTTON
 #define PORTD_PIN3_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTD_PIN4_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTD_PIN5_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTD_PIN6_INIT_MODE							(PORT_PIN_MODE_DIO)
 #define PORTD_PIN7_INIT_MODE							(PORT_PIN_MODE_DIO)

/************************************************************************************
*************************************************************************************/

#define PORTA_PIN0_MODE_CHANGEABLE							(FALSE)	// LED2
#define PORTA_PIN1_MODE_CHANGEABLE							(FALSE)
#define PORTA_PIN2_MODE_CHANGEABLE							(FALSE)
#define PORTA_PIN3_MODE_CHANGEABLE							(FALSE)
#define PORTA_PIN4_MODE_CHANGEABLE							(FALSE)
#define PORTA_PIN5_MODE_CHANGEABLE							(FALSE)
#define PORTA_PIN6_MODE_CHANGEABLE							(FALSE)
#define PORTA_PIN7_MODE_CHANGEABLE							(FALSE)

#define PORTB_PIN0_MODE_CHANGEABLE							(FALSE)
#define PORTB_PIN1_MODE_CHANGEABLE							(FALSE)
#define PORTB_PIN2_MODE_CHANGEABLE							(FALSE)
#define PORTB_PIN3_MODE_CHANGEABLE							(FALSE)
#define PORTB_PIN4_MODE_CHANGEABLE							(FALSE)
#define PORTB_PIN5_MODE_CHANGEABLE							(FALSE)
#define PORTB_PIN6_MODE_CHANGEABLE							(FALSE)
#define PORTB_PIN7_MODE_CHANGEABLE							(FALSE)

#define PORTC_PIN0_MODE_CHANGEABLE							(FALSE)
#define PORTC_PIN1_MODE_CHANGEABLE							(FALSE)
#define PORTC_PIN2_MODE_CHANGEABLE							(FALSE)
#define PORTC_PIN3_MODE_CHANGEABLE							(FALSE)
#define PORTC_PIN4_MODE_CHANGEABLE							(FALSE)
#define PORTC_PIN5_MODE_CHANGEABLE							(FALSE)	// LED1
#define PORTC_PIN6_MODE_CHANGEABLE							(FALSE)
#define PORTC_PIN7_MODE_CHANGEABLE							(FALSE)

#define PORTD_PIN0_MODE_CHANGEABLE							(FALSE)
#define PORTD_PIN1_MODE_CHANGEABLE							(FALSE)
#define PORTD_PIN2_MODE_CHANGEABLE							(FALSE)	//BUTTON
#define PORTD_PIN3_MODE_CHANGEABLE							(FALSE)
#define PORTD_PIN4_MODE_CHANGEABLE							(FALSE)
#define PORTD_PIN5_MODE_CHANGEABLE							(FALSE)
#define PORTD_PIN6_MODE_CHANGEABLE							(FALSE)
#define PORTD_PIN7_MODE_CHANGEABLE							(FALSE)

/************************************************************************************
*************************************************************************************/

#define PORTA_PIN0_LEVEL								(PORT_PIN_LEVEL_LOW)	  // LED2
#define PORTA_PIN1_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTA_PIN2_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTA_PIN3_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTA_PIN4_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTA_PIN5_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTA_PIN6_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTA_PIN7_LEVEL								(PORT_PIN_LEVEL_LOW)

#define PORTB_PIN0_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTB_PIN1_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTB_PIN2_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTB_PIN3_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTB_PIN4_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTB_PIN5_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTB_PIN6_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTB_PIN7_LEVEL								(PORT_PIN_LEVEL_LOW)

#define PORTC_PIN0_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTC_PIN1_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTC_PIN2_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTC_PIN3_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTC_PIN4_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTC_PIN5_LEVEL								(PORT_PIN_LEVEL_LOW)	// LED1
#define PORTC_PIN6_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTC_PIN7_LEVEL								(PORT_PIN_LEVEL_LOW)

#define PORTD_PIN0_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTD_PIN1_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTD_PIN2_LEVEL								(PORT_PIN_LEVEL_LOW)	//BUTTON
#define PORTD_PIN3_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTD_PIN4_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTD_PIN5_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTD_PIN6_LEVEL								(PORT_PIN_LEVEL_LOW)
#define PORTD_PIN7_LEVEL								(PORT_PIN_LEVEL_LOW)


/************************************************************************************
*************************************************************************************/

#define PORTA_PIN0_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)	   // LED2
#define PORTA_PIN1_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTA_PIN2_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTA_PIN3_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTA_PIN4_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTA_PIN5_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTA_PIN6_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTA_PIN7_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)

#define PORTB_PIN0_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTB_PIN1_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTB_PIN2_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTB_PIN3_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTB_PIN4_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTB_PIN5_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTB_PIN6_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTB_PIN7_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)

#define PORTC_PIN0_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTC_PIN1_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTC_PIN2_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTC_PIN3_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTC_PIN4_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTC_PIN5_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)	// LED1
#define PORTC_PIN6_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTC_PIN7_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)

#define PORTD_PIN0_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTD_PIN1_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTD_PIN2_PULLUP_STATE								(PORT_PIN_PULL_UP_ACTIV)	//BUTTON
#define PORTD_PIN3_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTD_PIN4_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTD_PIN5_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTD_PIN6_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)
#define PORTD_PIN7_PULLUP_STATE								(PORT_PIN_PULL_UP_INACTIV)



#endif /* PORT_PBCFG_H_ */