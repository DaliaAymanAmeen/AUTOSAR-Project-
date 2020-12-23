 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Dalia Ayman
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION       (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION       (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION       (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                   (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                   (STD_OFF)

/* Pre-compile option for Port set pin mode API */
#define PORT_SET_PIN_MODE_API                   (STD_ON)

/* Pre-compile option for Port set pin direction API */
#define PORT_SET_PIN_DIRECTION_API              (STD_ON)

/* Number of the configured Port Pins */
#define PORT_CONFIGURED_PINS                    (43U)

/*******************************************************************************
 *              Default Values for Port_ConfigPin Structure Members            *
 *******************************************************************************/

/* Default Pin mode */
#define PORT_DEFAULT_PIN_MODE                   (PORT_PIN_MODE_DIO)

/* Default pin Dierction */
#define PORT_DEFAULT_PIN_DIRECTION              (PORT_PIN_OUT)

/* Default pin internal resistor value */
#define PORT_DEFAULT_INTERNAL_RESESTOR_VALUE    (INTERNAL_RESESTOR_OFF)

/* Default pin option (Digital or Analog) */
#define DEFAULT_PIN_DIGITAL_OR_ANALOG           (PORT_PIN_DIGITAL)

/* Defult pin direction changable option */
#define PORT_DEFULT_PIN_DIRECTION_CHANGEABLE    (CHANGEABLE_ON)

/* Defult pin mode changable option */
#define PORT_DEFULT_PIN_MODE_CHANGEABLE         (CHANGEABLE_ON)

/* Define Default Pin Initial Value */
#define PORT_DEFAULT_PIN_INITIAL_VALUE          (STD_LOW)

/*******************************************************************************
 *                      Modes of Port Pins                                     *
 *******************************************************************************/

#define PORT_PIN_MODE_ADC                 (5U) 
#define PORT_PIN_MODE_CAN                 (8U) 
#define PORT_PIN_MODE_DIO                 (0U) 
#define PORT_PIN_MODE_DIO_GPT             (3U) 
#define PORT_PIN_MODE_DIO_WDG             (1U) 
#define PORT_PIN_MODE_FLEXRAY             (14U) 
#define PORT_PIN_MODE_ICU                 (6U) 
#define PORT_PIN_MODE_LIN                 (7U)  
#define PORT_PIN_MODE_MEM                 (9U)
#define PORT_PIN_MODE_PWM                 (4U)
#define PORT_PIN_MODE_SPI                 (2U)

/*******************************************************************************
 *                          Define the 43 pins                                 *
 *******************************************************************************/

#define PORT_PIN_17                     (0U)                    //A0
#define PORT_PIN_18                     (1U)                    //A1
#define PORT_PIN_19                     (2U)                    //A2
#define PORT_PIN_20                     (3U)                    //A3
#define PORT_PIN_21                     (4U)                    //A4
#define PORT_PIN_22                     (5U)                    //A5
#define PORT_PIN_23                     (6U)                    //A6
#define PORT_PIN_24                     (7U)                    //A7
   
#define PORT_PIN_45                     (8U)                    //B1
#define PORT_PIN_46                     (9U)                    //B2
#define PORT_PIN_47                     (10U)                   //B3
#define PORT_PIN_48                     (11U)                   //B4
#define PORT_PIN_58                     (12U)                   //B5
#define PORT_PIN_57                     (13U)                   //B6
#define PORT_PIN_01                     (14U)                   //B7
#define PORT_PIN_04                     (15U)                   //B7
   
#define PORT_PIN_52                     (16U)                   //C0
#define PORT_PIN_51                     (17U)                   //C1
#define PORT_PIN_50                     (18U)                   //C2
#define PORT_PIN_49                     (19U)                   //C3
#define PORT_PIN_16                     (20U)                   //C4
#define PORT_PIN_15                     (21U)                   //C5
#define PORT_PIN_14                     (22U)                   //C6
#define PORT_PIN_13                     (23U)                   //C7        
   
#define PORT_PIN_61                     (24U)                   //D0
#define PORT_PIN_62                     (25U)                   //D1
#define PORT_PIN_63                     (26U)                   //D2  
#define PORT_PIN_64                     (27U)                   //D3
#define PORT_PIN_43                     (28U)                   //D4
#define PORT_PIN_44                     (29U)                   //D5
#define PORT_PIN_53                     (30U)                   //D6
#define PORT_PIN_10                     (31U)                   //D7
   
#define PORT_PIN_09                     (32U)                   //E0
#define PORT_PIN_08                     (33U)                   //E1
#define PORT_PIN_07                     (34U)                   //E2
#define PORT_PIN_06                     (35U)                   //E3
#define PORT_PIN_59                     (36U)                   //E4
#define PORT_PIN_60                     (37U)                   //E5
   
#define PORT_PIN_28                     (38U)                   //F0
#define PORT_PIN_29                     (39U)                   //F1
#define PORT_PIN_30                     (40U)                   //F2
#define PORT_PIN_31                     (41U)                   //F3
#define PORT_PIN_05                     (42U)                   //F4


#endif /* PORT_CFG_H */



