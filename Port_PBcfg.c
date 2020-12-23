 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Dalia Ayman
 ******************************************************************************/

#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (3U)

/* AUTOSAR Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Port_PBcfg.c and Port.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif
   
   
/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration = {
PORT_PIN_17, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_18, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_19, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_20, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_21, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_22, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_23, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_24, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,

PORT_PIN_45, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_46, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_47, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_48, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_58, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_57, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_01, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_04, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,

PORT_PIN_52, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_51, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_50, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_49, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_16, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_15, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_14, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_13, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,

PORT_PIN_61, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_62, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_63, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_64, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_43, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_44, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_53, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_10, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,

PORT_PIN_09, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_08, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_07, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_06, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_59, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_60, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,

PORT_PIN_28, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_29, PORT_PIN_MODE_DIO, PORT_PIN_OUT, INTERNAL_RESESTOR_OFF, PORT_PIN_DIGITAL, CHANGEABLE_ON, CHANGEABLE_ON, 0,
PORT_PIN_30, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_31, PORT_DEFAULT_PIN_MODE, PORT_DEFAULT_PIN_DIRECTION, PORT_DEFAULT_INTERNAL_RESESTOR_VALUE, DEFAULT_PIN_DIGITAL_OR_ANALOG, PORT_DEFULT_PIN_DIRECTION_CHANGEABLE, PORT_DEFULT_PIN_MODE_CHANGEABLE, PORT_DEFAULT_PIN_INITIAL_VALUE,
PORT_PIN_05, PORT_PIN_MODE_DIO, PORT_PIN_IN, INTERNAL_RESESTOR_PULL_UP, PORT_PIN_DIGITAL, CHANGEABLE_ON, CHANGEABLE_ON, 0
};


   