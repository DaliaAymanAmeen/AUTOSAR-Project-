 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Dalia Ayman
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and PORT Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;   

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port module.
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
        if (NULL_PTR == ConfigPtr)
	{
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_Init_SID,
		     PORT_E_PARAM_CONFIG);
	}
	else
#endif
	{
                /*
		 * Set the module state to initialized and point to the PB configuration structure using a global pointer.
		 * This global pointer is global to be used by other functions to read the PB configuration structures
		 */
		Port_Status = PORT_INITIALIZED;
                
                volatile uint32 delay = 0;
                /* temp variable to save the current configured port */
                uint8 current_port;
                /* temp variable to save the current configured pin */
                Port_PinType current_pin;
                /* Iterate over the congiguration structure to initialize the 43 pins */
                for (uint8 i = 0; i < PORT_CONFIGURED_PINS ; i++)
                {
                    current_pin = Port_Configuration.Pins[i].pin_num;
                    /*******************************************************************************
                    *                              Initialize Port A                               *
                    *******************************************************************************/
                    if (current_pin >=0 && current_pin <=7) // Port A
                    {
                        current_port = 0; // Port A
                        /* Enable clock for PORT A and allow time for clock to start */
                        SYSCTL_REGCGC2_REG |= (1<< current_port);
                        delay = SYSCTL_REGCGC2_REG;
                        
                        /* initialize the pin direction */
                        switch(Port_Configuration.Pins[i].direction)
                        {
                            case 0: // input pin
                              CLEAR_BIT(GPIO_PORTA_DIR_REG, current_pin);
                              /* initialize the pin internal resistor */
                              switch(Port_Configuration.Pins[i].resistor)
                              {
                                  case 0: // OFF
                                      CLEAR_BIT(GPIO_PORTA_PUR_REG, current_pin);
                                      CLEAR_BIT(GPIO_PORTA_PDR_REG, current_pin);
                                      break;
                                  case 1: // PULL UP
                                      SET_BIT(GPIO_PORTA_PUR_REG, current_pin);
                                      CLEAR_BIT(GPIO_PORTA_PDR_REG, current_pin);
                                      break;
                                  case 2: // PULL DOWN
                                      CLEAR_BIT(GPIO_PORTA_PUR_REG, current_pin);
                                      SET_BIT(GPIO_PORTA_PDR_REG, current_pin);  
                                      break;
                              }
                              break;
                            case 1: // output pin
                              SET_BIT(GPIO_PORTA_DIR_REG, current_pin);
                              /* initialize the pin initial value */
                              switch(Port_Configuration.Pins[i].initial_value)
                              {
                                case 1: // STD_HIGH
                                  SET_BIT(GPIO_PORTA_DATA_REG, current_pin); 
                                  break;
                                case 0: // STD_LOW
                                  CLEAR_BIT(GPIO_PORTA_DATA_REG,  current_pin);
                                  break;
                               }
                              break;
                        }
                        /*initialize the pin option (analog or digital)*/
                        switch(Port_Configuration.Pins[i].analog_digital)
                        {
                          case 0: // Analog pin
                            CLEAR_BIT(GPIO_PORTA_DEN_REG, current_pin); 
                            SET_BIT(GPIO_PORTA_AMSEL_REG, current_pin);
                            break;
                          case 1: // Digital pin
                            SET_BIT(GPIO_PORTA_DEN_REG,  current_pin); 
                            CLEAR_BIT(GPIO_PORTA_AMSEL_REG, current_pin);
                            break;          
                        }
                        /* initialize the pin mode */
                        switch(Port_Configuration.Pins[i].pin_mode)
                        {
                          case 0: //DIO
                            CLEAR_BIT(GPIO_PORTA_AFSEL_REG, current_pin);
                            GPIO_PORTA_PCTL_REG &= ~(0x0000000F << (current_pin * 4));
                            break;
                          default:
                            SET_BIT(GPIO_PORTA_AFSEL_REG, current_pin);
                            GPIO_PORTE_PCTL_REG |= ((0x00000000) +(Port_Configuration.Pins[i].pin_mode) << (current_pin * 4));
                            break;                           
                        }                       
                    }
                    /*******************************************************************************
                    *                              Initialize Port B                               *
                    *******************************************************************************/
                    else if (current_pin >=8 && current_pin <=15) // Port B
                    {
                        current_port = 1; // Port B
                        current_pin = current_pin - 8;
                        /* Enable clock for PORT A and allow time for clock to start */
                        SYSCTL_REGCGC2_REG |= (1<< current_port);
                        delay = SYSCTL_REGCGC2_REG;
                        
                        /* initialize the pin direction */
                        switch(Port_Configuration.Pins[i].direction)
                        {
                            case 0: // input pin
                              CLEAR_BIT(GPIO_PORTB_DIR_REG, current_pin);
                              /* initialize the pin internal resistor */
                              switch(Port_Configuration.Pins[i].resistor)
                              {
                                  case 0: // OFF
                                      CLEAR_BIT(GPIO_PORTB_PUR_REG, current_pin);
                                      CLEAR_BIT(GPIO_PORTB_PDR_REG, current_pin);
                                      break;
                                  case 1: // PULL UP
                                      SET_BIT(GPIO_PORTB_PUR_REG, current_pin);
                                      CLEAR_BIT(GPIO_PORTB_PDR_REG, current_pin);
                                      break;
                                  case 2: // PULL DOWN
                                      CLEAR_BIT(GPIO_PORTB_PUR_REG, current_pin);
                                      SET_BIT(GPIO_PORTB_PDR_REG, current_pin);  
                                      break;
                              }
                              break;
                            case 1: // output pin
                              SET_BIT(GPIO_PORTB_DIR_REG, current_pin);
                              /* initialize the pin initial value */
                              switch(Port_Configuration.Pins[i].initial_value)
                              {
                                case 1: // STD_HIGH
                                  SET_BIT(GPIO_PORTB_DATA_REG, current_pin); 
                                  break;
                                case 0: // STD_LOW
                                  CLEAR_BIT(GPIO_PORTB_DATA_REG, current_pin);
                                  break;
                               }
                              break;
                        }
                        /*initialize the pin option (analog or digital)*/
                        switch(Port_Configuration.Pins[i].analog_digital)
                        {
                          case 0: // Analog pin
                            CLEAR_BIT(GPIO_PORTB_DEN_REG, current_pin); 
                            SET_BIT(GPIO_PORTB_AMSEL_REG, current_pin);
                            break;
                          case 1: // Digital pin
                            SET_BIT(GPIO_PORTB_DEN_REG, current_pin); 
                            CLEAR_BIT(GPIO_PORTB_AMSEL_REG, current_pin);
                            break;          
                        }
                        /* initialize the pin mode */
                        switch(Port_Configuration.Pins[i].pin_mode)
                        {
                          case 0: //DIO
                            CLEAR_BIT(GPIO_PORTB_AFSEL_REG, current_pin);
                            GPIO_PORTB_PCTL_REG &= ~(0x0000000F << (current_pin * 4)); 
                            break;
                          default:
                            SET_BIT(GPIO_PORTB_AFSEL_REG, current_pin);
                            GPIO_PORTE_PCTL_REG |= ((0x00000000) +(Port_Configuration.Pins[i].pin_mode) << (current_pin * 4));
                            break;                              
                        } 
                    }
                    /*******************************************************************************
                    *                              Initialize Port C                               *
                    *******************************************************************************/                    
                    else if (current_pin >=16 && current_pin <=23) // Port C
                    {
                        current_port = 2; // Port C
                        current_pin = current_pin - 8*2;
                        if(current_pin == 0 || current_pin == 1 || current_pin == 2 || current_pin == 3)
                        {
                          /* Do Nothing ...  this is the JTAG pins */
                          continue;
                        }
                        /* Enable clock for PORT C and allow time for clock to start */
                        SYSCTL_REGCGC2_REG |= (1<< current_port);
                        delay = SYSCTL_REGCGC2_REG;
                        
                        /* initialize the pin direction */
                        switch(Port_Configuration.Pins[i].direction)
                        {
                            case 0: // input pin
                              CLEAR_BIT(GPIO_PORTC_DIR_REG, current_pin);
                              /* initialize the pin internal resistor */
                              switch(Port_Configuration.Pins[i].resistor)
                              {
                                  case 0: // OFF
                                      CLEAR_BIT(GPIO_PORTC_PUR_REG, current_pin);
                                      CLEAR_BIT(GPIO_PORTC_PDR_REG, current_pin);
                                      break;
                                  case 1: // PULL UP
                                      SET_BIT(GPIO_PORTC_PUR_REG, current_pin);
                                      CLEAR_BIT(GPIO_PORTC_PDR_REG, current_pin);
                                      break;
                                  case 2: // PULL DOWN
                                      CLEAR_BIT(GPIO_PORTC_PUR_REG, current_pin);
                                      SET_BIT(GPIO_PORTC_PDR_REG, current_pin);  
                                      break;
                              }
                              break;
                            case 1: // output pin
                              SET_BIT(GPIO_PORTC_DIR_REG,current_pin);
                              /* initialize the pin initial value */
                              switch(Port_Configuration.Pins[i].initial_value)
                              {
                                case 1: // STD_HIGH
                                  SET_BIT(GPIO_PORTC_DATA_REG,current_pin); 
                                  break;
                                case 0: // STD_LOW
                                  CLEAR_BIT(GPIO_PORTC_DATA_REG, current_pin);
                                  break;
                               }
                              break;
                        }
                        /*initialize the pin option (analog or digital)*/
                        switch(Port_Configuration.Pins[i].analog_digital)
                        {
                          case 0: // Analog pin
                            CLEAR_BIT(GPIO_PORTC_DEN_REG, current_pin); 
                            SET_BIT(GPIO_PORTC_AMSEL_REG, current_pin);
                            break;
                          case 1: // Digital pin
                            SET_BIT(GPIO_PORTC_DEN_REG, current_pin); 
                            CLEAR_BIT(GPIO_PORTC_AMSEL_REG,current_pin);
                            break;          
                        }
                        /* initialize the pin mode */
                        switch(Port_Configuration.Pins[i].pin_mode)
                        {
                          case 0: //DIO
                            CLEAR_BIT(GPIO_PORTC_AFSEL_REG, current_pin);
                            GPIO_PORTC_PCTL_REG &= ~(0x0000000F << (current_pin * 4)); 
                            break;
                          default:
                            SET_BIT(GPIO_PORTC_AFSEL_REG, current_pin);
                            GPIO_PORTE_PCTL_REG |= ((0x00000000) +(Port_Configuration.Pins[i].pin_mode) << (current_pin * 4));
                            break;                              
                        }
                        
                    }
                    /*******************************************************************************
                    *                              Initialize Port D                               *
                    *******************************************************************************/
                    else if (current_pin >=24 && current_pin <=31) // Port D
                    {
                        current_port = 3; // Port D
                        current_pin = current_pin - 8*3;
                        /* Enable clock for PORT D and allow time for clock to start */
                        SYSCTL_REGCGC2_REG |= (1<< current_port);
                        delay = SYSCTL_REGCGC2_REG;
                        /* Unlock pin PD7*/
                        if (current_pin == 7) 
                        {
                            GPIO_PORTD_LOCK_REG = 0x4C4F434B;
                            SET_BIT(GPIO_PORTD_CR_REG, current_pin);                            
                        }                        
                        /* initialize the pin direction */
                        switch(Port_Configuration.Pins[i].direction)
                        {
                            case 0: // input pin
                              CLEAR_BIT(GPIO_PORTD_DIR_REG, current_pin);
                              /* initialize the pin internal resistor */
                              switch(Port_Configuration.Pins[i].resistor)
                              {
                                  case 0: // OFF
                                      CLEAR_BIT(GPIO_PORTD_PUR_REG, current_pin);
                                      CLEAR_BIT(GPIO_PORTD_PDR_REG, current_pin);
                                      break;
                                  case 1: // PULL UP
                                      SET_BIT(GPIO_PORTD_PUR_REG, current_pin);
                                      CLEAR_BIT(GPIO_PORTD_PDR_REG, current_pin);
                                      break;
                                  case 2: // PULL DOWN
                                      CLEAR_BIT(GPIO_PORTD_PUR_REG, current_pin);
                                      SET_BIT(GPIO_PORTD_PDR_REG, current_pin);  
                                      break;
                              }
                              break;
                            case 1: // output pin
                              SET_BIT(GPIO_PORTD_DIR_REG, current_pin);
                              /* initialize the pin initial value */
                              switch(Port_Configuration.Pins[i].initial_value)
                              {
                                case 1: // STD_HIGH
                                  SET_BIT(GPIO_PORTD_DATA_REG, current_pin); 
                                  break;
                                case 0: // STD_LOW
                                  CLEAR_BIT(GPIO_PORTD_DATA_REG, current_pin);
                                  break;
                               }
                              break;
                        }
                        /*initialize the pin option (analog or digital)*/
                        switch(Port_Configuration.Pins[i].analog_digital)
                        {
                          case 0: // Analog pin
                            CLEAR_BIT(GPIO_PORTD_DEN_REG, current_pin); 
                            SET_BIT(GPIO_PORTD_AMSEL_REG, current_pin);
                            break;
                          case 1: // Digital pin
                            SET_BIT(GPIO_PORTD_DEN_REG, current_pin); 
                            CLEAR_BIT(GPIO_PORTD_AMSEL_REG, current_pin);
                            break;          
                        }
                        /* initialize the pin mode */
                        switch(Port_Configuration.Pins[i].pin_mode)
                        {
                          case 0: //DIO
                            CLEAR_BIT(GPIO_PORTD_AFSEL_REG, current_pin);
                            GPIO_PORTD_PCTL_REG &= ~(0x0000000F << (current_pin * 4));   
                            break;
                          default:
                            SET_BIT(GPIO_PORTD_AFSEL_REG, current_pin);
                            GPIO_PORTE_PCTL_REG |= ((0x00000000) +(Port_Configuration.Pins[i].pin_mode) << (current_pin * 4));
                            break;  
                        }
                    }
                    /*******************************************************************************
                    *                              Initialize Port E                               *
                    *******************************************************************************/                    
                    else if (current_pin >=32 && current_pin <=37) // Port E
                    {
                        current_port = 4; // Port E      
                        current_pin = current_pin - 8*4;
                        /* Enable clock for PORT E and allow time for clock to start */
                        SYSCTL_REGCGC2_REG |= (1<< current_port);
                        delay = SYSCTL_REGCGC2_REG;
                        
                        /* initialize the pin direction */
                        switch(Port_Configuration.Pins[i].direction)
                        {
                            case 0: // input pin
                              CLEAR_BIT(GPIO_PORTE_DIR_REG, current_pin);
                              /* initialize the pin internal resistor */
                              switch(Port_Configuration.Pins[i].resistor)
                              {
                                  case 0: // OFF
                                      CLEAR_BIT(GPIO_PORTE_PUR_REG, current_pin);
                                      CLEAR_BIT(GPIO_PORTE_PDR_REG, current_pin);
                                      break;
                                  case 1: // PULL UP
                                      SET_BIT(GPIO_PORTE_PUR_REG, current_pin);
                                      CLEAR_BIT(GPIO_PORTE_PDR_REG, current_pin);
                                      break;
                                  case 2: // PULL DOWN
                                      CLEAR_BIT(GPIO_PORTE_PUR_REG, current_pin);
                                      SET_BIT(GPIO_PORTE_PDR_REG, current_pin);  
                                      break;
                              }
                              break;
                            case 1: // output pin
                              SET_BIT(GPIO_PORTE_DIR_REG, current_pin);
                              /* initialize the pin initial value */
                              switch(Port_Configuration.Pins[i].initial_value)
                              {
                                case 1: // STD_HIGH
                                  SET_BIT(GPIO_PORTE_DATA_REG, current_pin); 
                                  break;
                                case 0: // STD_LOW
                                  CLEAR_BIT(GPIO_PORTE_DATA_REG,current_pin);
                                  break;
                               }
                              break;
                        }
                        /*initialize the pin option (analog or digital)*/
                        switch(Port_Configuration.Pins[i].analog_digital)
                        {
                          case 0: // Analog pin
                            CLEAR_BIT(GPIO_PORTE_DEN_REG, current_pin); 
                            SET_BIT(GPIO_PORTE_AMSEL_REG, current_pin);
                            break;
                          case 1: // Digital pin
                            SET_BIT(GPIO_PORTE_DEN_REG, current_pin); 
                            CLEAR_BIT(GPIO_PORTE_AMSEL_REG, current_pin);
                            break;          
                        }
                        /* initialize the pin mode */
                        switch(Port_Configuration.Pins[i].pin_mode)
                        {
                          case 0: //DIO
                            CLEAR_BIT(GPIO_PORTE_AFSEL_REG, current_pin);
                            GPIO_PORTE_PCTL_REG &= ~(0x0000000F << (current_pin * 4)); 
                            break;
                          default:
                            SET_BIT(GPIO_PORTE_AFSEL_REG, current_pin);
                            GPIO_PORTE_PCTL_REG |= ((0x00000000) +(Port_Configuration.Pins[i].pin_mode) << (current_pin * 4));
                            break;  
                        }
                    }
                    
                    /*******************************************************************************
                    *                              Initialize Port F                               *
                    *******************************************************************************/ 
                    else if (current_pin >=38 && current_pin <=42) // Port F
                    {
                        current_port = 5; // Port F
                        current_pin = current_pin - 38;
                        /* Enable clock for PORT F and allow time for clock to start */
                        SYSCTL_REGCGC2_REG |= (1<< current_port);
                        delay = SYSCTL_REGCGC2_REG;
                        
                        /* Unlock pin PF0*/
                        if (current_pin == 0) 
                        {
                            GPIO_PORTF_LOCK_REG = 0x4C4F434B;
                            SET_BIT(GPIO_PORTF_CR_REG, current_pin);                            
                        }
                        /* initialize the pin direction */
                        switch(Port_Configuration.Pins[i].direction)
                        {
                            case 0: // input pin
                              CLEAR_BIT(GPIO_PORTF_DIR_REG, current_pin);
                              /* initialize the pin internal resistor */
                              switch(Port_Configuration.Pins[i].resistor)
                              {
                                  case 0: // OFF
                                      CLEAR_BIT(GPIO_PORTF_PUR_REG, current_pin);
                                      CLEAR_BIT(GPIO_PORTF_PDR_REG, current_pin);
                                      break;
                                  case 1: // PULL UP
                                      SET_BIT(GPIO_PORTF_PUR_REG, current_pin);
                                      CLEAR_BIT(GPIO_PORTF_PDR_REG, current_pin);
                                      break;
                                  case 2: // PULL DOWN
                                      CLEAR_BIT(GPIO_PORTF_PUR_REG, current_pin);
                                      SET_BIT(GPIO_PORTF_PDR_REG, current_pin);  
                                      break;
                              }
                              break;
                            case 1: // output pin
                              SET_BIT(GPIO_PORTF_DIR_REG, current_pin);
                              /* initialize the pin initial value */
                              switch(Port_Configuration.Pins[i].initial_value)
                              {
                                case 1: // STD_HIGH
                                  SET_BIT(GPIO_PORTF_DATA_REG, current_pin); 
                                  break;
                                case 0: // STD_LOW
                                  CLEAR_BIT(GPIO_PORTF_DATA_REG, current_pin);
                                  break;
                               }
                              break;
                        }
                        /*initialize the pin option (analog or digital)*/
                        switch(Port_Configuration.Pins[i].analog_digital)
                        {
                          case 0: // Analog pin
                            CLEAR_BIT(GPIO_PORTF_DEN_REG, current_pin); 
                            SET_BIT(GPIO_PORTF_AMSEL_REG, current_pin);
                            break;
                          case 1: // Digital pin
                            SET_BIT(GPIO_PORTF_DEN_REG, current_pin); 
                            CLEAR_BIT(GPIO_PORTF_AMSEL_REG, current_pin);
                            break;          
                        }
                        /* initialize the pin mode */
                        switch(Port_Configuration.Pins[i].pin_mode)
                        {
                          case 0: //DIO
                            CLEAR_BIT(GPIO_PORTF_AFSEL_REG, current_pin);
                            GPIO_PORTF_PCTL_REG &= ~(0x0000000F << (current_pin * 4));
                            break;
                          default:
                            SET_BIT(GPIO_PORTF_AFSEL_REG, current_pin);
                            GPIO_PORTF_PCTL_REG |= ((0x00000000) +(Port_Configuration.Pins[i].pin_mode) << (current_pin * 4));
                            break;                              
                        }
                        
                    }

                }
             
	}
}


/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number , Direction - Port Pin Direction 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the port pin direction 
************************************************************************************/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction) 
{
      boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
        /* check if PORT Driver is Initialized */
        if (PORT_NOT_INITIALIZED == Port_Status)
	{
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinDirection_SID,
		  PORT_E_UNINIT);
                error = TRUE;
	}
        else
        {
            /* No Action Required */
        }
  
        /* check if Port Pin ID number is Valid */
        if (Pin > PORT_CONFIGURED_PINS-1)
        {
              Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinDirection_SID,
		 PORT_E_PARAM_PIN);
              error = TRUE;
        }
        
        else
        {
            /* No Action Required */
        }
        
         /* check if Port Pin ID is chanagable */
        if (Port_Configuration.Pins[Pin].Pin_DirectionChangeable == CHANGEABLE_OFF)  
        {
              Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinDirection_SID,
		 PORT_E_DIRECTION_UNCHANGEABLE);
              error = TRUE;
        }
        
        else
        {
            /* No Action Required */
        }
      
#endif
    if(FALSE == error)
    {
        if (Pin >=0 && Pin <=7) // Port A
        {     
              switch(Direction)
              {
                  case 0: // input pin
                    CLEAR_BIT(GPIO_PORTA_DIR_REG, Pin);
                    break;
                case 1: // output pin
                    SET_BIT(GPIO_PORTA_DIR_REG, Pin);
                    break;
              }
        }
        
        if (Pin >=8 && Pin <=15) // Port B
        {     
              Pin = Pin - 8;
              switch(Direction)
              {
                  case 0: // input pin
                    CLEAR_BIT(GPIO_PORTB_DIR_REG, Pin);
                    break;
                case 1: // output pin
                    SET_BIT(GPIO_PORTB_DIR_REG, Pin);
                    break;
              }
        }
        
        if (Pin >=16 && Pin <=23) // Port C
        {     
              Pin = Pin - 8*2;
              switch(Direction)
              {
                  case 0: // input pin
                    CLEAR_BIT(GPIO_PORTC_DIR_REG, Pin);
                    break;
                case 1: // output pin
                    SET_BIT(GPIO_PORTC_DIR_REG, Pin);
                    break;
              }
        }
        if (Pin >=24 && Pin <=31) // Port D
        {     
              Pin = Pin - 8*3;
              switch(Direction)
              {
                  case 0: // input pin
                    CLEAR_BIT(GPIO_PORTD_DIR_REG, Pin);
                    break;
                case 1: // output pin
                    SET_BIT(GPIO_PORTD_DIR_REG, Pin);
                    break;
              }
        }
        
        if (Pin >=32 && Pin <=37) // Port E
        {     
              Pin = Pin - 8*4;
              switch(Direction)
              {
                  case 0: // input pin
                    CLEAR_BIT(GPIO_PORTE_DIR_REG, Pin);
                    break;
                case 1: // output pin
                    SET_BIT(GPIO_PORTE_DIR_REG, Pin);
                    break;
              }
        }
        
        if (Pin >=38 && Pin <=42) // Port F
        {     
              Pin = Pin - 38;
              switch(Direction)
              {
                  case 0: // input pin
                    CLEAR_BIT(GPIO_PORTF_DIR_REG, Pin);
                    break;
                case 1: // output pin
                    SET_BIT(GPIO_PORTF_DIR_REG, Pin);
                    break;
              }
        }      
    }
    else
    {
      /* No Action Required */
    }
}
#endif

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Refreshes port direction. 
************************************************************************************/
void Port_RefreshPortDirection(void)
{
     boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
        /* check if PORT Driver is Initialized */
        if (PORT_NOT_INITIALIZED == Port_Status)
	{
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_RefreshPortDirection_SID,
		  PORT_E_UNINIT);
                error = TRUE;
	}
        else
        {
            /* No Action Required */
        }
  

#endif
      if(FALSE == error)
      {
         Port_PinType current_pin;
         for (uint8 i = 0; i < PORT_CONFIGURED_PINS ; i++)
         {
            current_pin = Port_Configuration.Pins[i].pin_num;
            if (current_pin >=0 && current_pin <=7) // Port A
            {
              if (Port_Configuration.Pins[i].Pin_DirectionChangeable) 
              {
                continue;
              }
              else
              {
                switch(Port_Configuration.Pins[i].direction)
                {
                  case 0: // input pin
                    CLEAR_BIT(GPIO_PORTA_DIR_REG, current_pin);
                    break;
                  case 1: // output pin
                    SET_BIT(GPIO_PORTA_DIR_REG, current_pin);
                    break;
                 }
              } 
            }
            
            if (current_pin >=8 && current_pin <=15) // Port B
            {
              current_pin = current_pin - 8;
              if (Port_Configuration.Pins[i].Pin_DirectionChangeable) 
              {
                continue;
              }
              else
              {
                switch(Port_Configuration.Pins[i].direction)
                {
                  case 0: // input pin
                    CLEAR_BIT(GPIO_PORTB_DIR_REG, current_pin);
                    break;
                  case 1: // output pin
                    SET_BIT(GPIO_PORTB_DIR_REG, current_pin);
                    break;
                 }
              } 
            }
            
            if (current_pin >=16 && current_pin <=23) // Port C
            {
              current_pin = current_pin - 8*2;
              if (Port_Configuration.Pins[i].Pin_DirectionChangeable) 
              {
                continue;
              }
              else
              {
                switch(Port_Configuration.Pins[i].direction)
                {
                  case 0: // input pin
                    CLEAR_BIT(GPIO_PORTC_DIR_REG, current_pin);
                    break;
                  case 1: // output pin
                    SET_BIT(GPIO_PORTC_DIR_REG, current_pin);
                    break;
                 }
              } 
            }
            
            if (current_pin >=24 && current_pin <=31) // Port D
            {
              current_pin = current_pin - 8*3;
              if (Port_Configuration.Pins[i].Pin_DirectionChangeable) 
              {
                continue;
              }
              else
              {
                switch(Port_Configuration.Pins[i].direction)
                {
                  case 0: // input pin
                    CLEAR_BIT(GPIO_PORTD_DIR_REG, current_pin);
                    break;
                  case 1: // output pin
                    SET_BIT(GPIO_PORTD_DIR_REG, current_pin);
                    break;
                 }
              } 
            } 
            
            if (current_pin >=32 && current_pin <=37) // Port E
            {
              current_pin = current_pin - 8*4;
              if (Port_Configuration.Pins[i].Pin_DirectionChangeable) 
              {
                continue;
              }
              else
              {
                switch(Port_Configuration.Pins[i].direction)
                {
                  case 0: // input pin
                    CLEAR_BIT(GPIO_PORTE_DIR_REG, current_pin);
                    break;
                  case 1: // output pin
                    SET_BIT(GPIO_PORTE_DIR_REG, current_pin);
                    break;
                 }
              } 
            }
            
            if (current_pin >=38 && current_pin <=42) // Port F
            {
              current_pin = current_pin - 38;
              if (Port_Configuration.Pins[i].Pin_DirectionChangeable) 
              {
                continue;
              }
              else
              {
                switch(Port_Configuration.Pins[i].direction)
                {
                  case 0: // input pin
                    CLEAR_BIT(GPIO_PORTF_DIR_REG, current_pin);
                    break;
                  case 1: // output pin
                    SET_BIT(GPIO_PORTF_DIR_REG, current_pin);
                    break;
                 }
              } 
            } 
            
           }
      }
      else
      {
          /* No Action Required */
      }
}
/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): versioninfo - Pointer to where to store the version information of this module. 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Return the version information of this module. 
************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
    boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
        /* check if PORT Driver is Iitialized */
        if (PORT_NOT_INITIALIZED == Port_Status)
	{
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_GetVersionInfo_SID,
		  PORT_E_UNINIT);
                error = TRUE;
	}
        else
        {
            /* No Action Required */
        }
        
        /* check if the input pointer parameter is not a NULL_PTR */
        if (PORT_NOT_INITIALIZED == versioninfo)
	{
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_GetVersionInfo_SID,
		  PORT_E_PARAM_POINTER);
                error = TRUE;
	}
        else
        {
            /* No Action Required */
        }
#endif
      if(FALSE == error)
      {
        /* Copy the vendor Id */
        versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
        /* Copy the module Id */
        versioninfo->moduleID = (uint16)PORT_MODULE_ID;
        /* Copy Software Major Version */
        versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
        /* Copy Software Minor Version */
        versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
        /* Copy Software Patch Version */
        versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
      }
      else
      {
        /* No Action Required */
      }
}
#endif


/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number , Mode - New Port Pin mode to be set on port pin. 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the port pin mode. 
************************************************************************************/
#if (PORT_SET_PIN_MODE_API == STD_ON)
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode)
{
     boolean error = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)
        /* check if PORT Driver is initialized */
        if (PORT_NOT_INITIALIZED == Port_Status)
	{
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinMode_SID,
		  PORT_E_UNINIT);
                error = TRUE;
	}
        else
        {
            /* No Action Required */
        }
        
        /* check if Port Pin ID number is Valid */
        if (Pin > PORT_CONFIGURED_PINS-1)
        {
              Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinMode_SID,
		 PORT_E_PARAM_PIN);
              error = TRUE;
        }
        
        else
        {
            /* No Action Required */
        }
        
         /* check if Port Pin ID is chanagable */
        if (Port_Configuration.Pins[Pin].Pin_DirectionChangeable == CHANGEABLE_OFF)  
        {
              Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinMode_SID,
		 PORT_E_DIRECTION_UNCHANGEABLE);
              error = TRUE;
        }
        
        else
        {
            /* No Action Required */
        }
                    
         /* check if Pin Mode Type ID is Valid */
        if (Mode > 9 && Mode != 14)  
        {
              Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, Port_SetPinMode_SID,
		 PORT_E_PARAM_INVALID_MODE);
              error = TRUE;
        }
        
        else
        {
            /* No Action Required */
        }  

#endif
    if(FALSE == error)
    {        
        if (Pin >=0 && Pin <=7) // Port A
        {     
              switch(Mode)
              {
                case 0: //DIO
                  CLEAR_BIT(GPIO_PORTA_AFSEL_REG, Pin);
                  GPIO_PORTA_PCTL_REG &= ~(0x0000000F << (Pin * 4));
                  break;
                default:
                  SET_BIT(GPIO_PORTA_AFSEL_REG, Pin);
                  GPIO_PORTA_PCTL_REG |= ((0x00000000) +(Mode) << (Pin * 4));
                  break;                    
              }            
        }
        
        if (Pin >=8 && Pin <=15) // Port B
        {     
              Pin = Pin - 8;
              switch(Mode)
              {
                case 0: //DIO
                  CLEAR_BIT(GPIO_PORTB_AFSEL_REG, Pin);
                  GPIO_PORTB_PCTL_REG &= ~(0x0000000F << (Pin * 4));
                  break;
                default:
                  SET_BIT(GPIO_PORTB_AFSEL_REG, Pin);
                  GPIO_PORTB_PCTL_REG |= ((0x00000000) +(Mode) << (Pin * 4));
                  break;                  
              }

        }
        
        if (Pin >=16 && Pin <=23) // Port C
        {     
              Pin = Pin - 8*2;
              switch(Mode)
              {
                case 0: //DIO
                  CLEAR_BIT(GPIO_PORTC_AFSEL_REG, Pin);
                  GPIO_PORTC_PCTL_REG &= ~(0x0000000F << (Pin * 4));
                  break;
                default:
                  SET_BIT(GPIO_PORTC_AFSEL_REG, Pin);
                  GPIO_PORTC_PCTL_REG |= ((0x00000000) +(Mode) << (Pin * 4));
                  break;                      
              }
        }
        
        if (Pin >=24 && Pin <=31) // Port D
        {     
              Pin = Pin - 8*3;
              switch(Mode)
              {
                case 0: //DIO
                  CLEAR_BIT(GPIO_PORTD_AFSEL_REG, Pin);
                  GPIO_PORTD_PCTL_REG &= ~(0x0000000F << (Pin * 4));
                  break;
                default:
                  SET_BIT(GPIO_PORTD_AFSEL_REG, Pin);
                  GPIO_PORTD_PCTL_REG |= ((0x00000000) +(Mode) << (Pin * 4));
                  break;    
              }
        }
        
        if (Pin >=32 && Pin <=37) // Port E
        {     
              Pin = Pin - 8*4;
              switch(Mode)
              {
                case 0: //DIO
                  CLEAR_BIT(GPIO_PORTE_AFSEL_REG, Pin);
                  GPIO_PORTE_PCTL_REG &= ~(0x0000000F << (Pin * 4));
                  break;
                default:
                  SET_BIT(GPIO_PORTE_AFSEL_REG,Pin);
                  GPIO_PORTE_PCTL_REG |= ((0x00000000) +(Mode) << (Pin * 4));
                  break;    
              }
        }
        
        if (Pin >=38 && Pin <=42) // Port F
        {     
              Pin = Pin - 38;
              switch(Mode)
              {
                case 0: //DIO
                  CLEAR_BIT(GPIO_PORTF_AFSEL_REG, Pin);
                  GPIO_PORTF_PCTL_REG &= ~(0x0000000F << (Pin * 4));
                  break;
                default:
                  SET_BIT(GPIO_PORTF_AFSEL_REG, Pin);
                  GPIO_PORTF_PCTL_REG |= ((0x00000000) +(Mode) << (Pin * 4));
                  break;    
              }
        }   
    }
    else
    {
      /* No Action Required */
    }
}
#endif
