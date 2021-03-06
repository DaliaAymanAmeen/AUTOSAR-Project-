 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Dalia Ayman
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR */
#define PORT_VENDOR_ID    (13U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)


/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* PORT Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"
   
   
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for PORT initialization */
#define Port_Init_SID                   (uint8)0x00

/* Service ID for PORT set pin direction */   
#define Port_SetPinDirection_SID        (uint8)0x01
 
/* Service ID for PORT refresh port direction */   
#define Port_RefreshPortDirection_SID   (uint8)0x02
   
/* Service ID for PORT GetVersionInfo */
#define Port_GetVersionInfo_SID         (uint8)0x03
   
/* Service ID for PORT set pin mode */
#define Port_SetPinMode_SID             (uint8)0x04
   
   
/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Port Pin ID */
#define PORT_E_PARAM_PIN                (uint8)0x0A
   
/* DET code to report Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE   (uint8)0x0B
   
/* DET code to report API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG             (uint8)0x0C
 
/* 
 * DET code to report API Port_SetPinMode 
 * service called when mode is unchangeable
*/
#define PORT_E_PARAM_INVALID_MODE       (uint8)0x0D
#define PORT_E_MODE_UNCHANGEABLE        (uint8)0x0E                      
   
/* DET code to report API service called
 * without module initialization
*/
#define PORT_E_UNINIT                   (uint8)0x0F

/* DET code to report APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER            (uint8)0x10

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Port_PinType used by the PORT APIs */
typedef uint8 Port_PinType;

/* Type definition for Port_PinModeType used by the PORT APIs */
typedef uint8 Port_PinModeType;

/* Description: Enum to hold PIN direction */
typedef enum
{       
    PORT_PIN_IN, PORT_PIN_OUT
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    INTERNAL_RESESTOR_OFF,INTERNAL_RESESTOR_PULL_UP,INTERNAL_RESESTOR_PULL_DOWN
}Port_InternalResistor;

/* Description: Enum to hold PIN (Digital or Analog) option */
typedef enum
{
    PORT_PIN_ANALOG,PORT_PIN_DIGITAL
}Port_AnalogDigital;

/* Description: Enum to hold PIN changables */
typedef enum
{
    CHANGEABLE_ON,CHANGEABLE_OFF
}Port_Chnageable;

/* Description: Structure to configure each individual PIN:
 *	1. the number of the pin in the PORT.
 *      2. the pin mode 
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the internal resistor --> Disable, Pull up or Pull down
 *	5. the pin option --> ANALOG or DIGITAL
 *	6. the option of Pin_DirectionChangeable --> ON or OFF
 *      7. the option of Pin_ModeChangeable --> OD or OFF
 *      8. the initial value of the pin --> STD_LOW. STD_HIGH
 */
/* Structure for Port_ConfigPin */
typedef struct
{       
    Port_PinType pin_num; 
    Port_PinModeType pin_mode;
    Port_PinDirectionType direction;
    Port_InternalResistor resistor;
    Port_AnalogDigital analog_digital;
    Port_Chnageable Pin_DirectionChangeable; 
    Port_Chnageable Pin_ModeChangeable; 
    uint8 initial_value;
    
}Port_ConfigPin;
   
/* Data Structure required for initializing the PORT Driver */
typedef struct{  
   Port_ConfigPin Pins[PORT_CONFIGURED_PINS];
}Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for PORT initialization API */
void Port_Init(const Port_ConfigType* ConfigPtr);

/* Function for Port set pin direction API */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction); 
#endif

/* Function for Port refresh port direction API */
void Port_RefreshPortDirection(void);

/* Function for Port GetVersionInfo API */
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif

/* Function for Port set pin mode API */
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode);
#endif

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */

   