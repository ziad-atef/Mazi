#ifndef _HAL_GPIO
#define _HAL_GPIO

#include "stm32f10x.h" 

#define LOW 0
#define HIGH 1

//configuration struction



typedef struct
	{
		GPIO_TypeDef *port;
		uint32_t pin;
		uint32_t mode; 
		uint32_t  mode_type;
		uint32_t pull;
		uint32_t speed;
		uint32_t alt_func;
		
		
		
		
		
	}GPIO_TYPE;

//PORT names
#define PORTA    GPIOA
#define PORTB    GPIOB
#define PORTC    GPIOC
#define PORTD    GPIOD
#define PORTE    GPIOE
#define PORTF    GPIOF
#define PORTG    GPIOG


//PIN MODE
#define OUTPUT_MODE          ((uint32_t) 0x01)
#define INPUT_MODE            ((uint32_t) 0x02)


//INPUT MODES TYPE
#define INPUT_ANALOG    ((uint32_t) 0x00)
#define INPUT_FLOATING    ((uint32_t) 0x01) //DEFAULT AT RESET
#define INPUT_PU_PD        ((uint32_t) 0x02) //INPUT WITH PULL UP OR PULL DOWN


//OUTPUT MODES TYPE
#define OUTPUT_GEN_PURPOSE           ((uint32_t) 0x00) //GENERAL PURPOSE OUTPUT
#define OUTPUT_OD     (              (uint32_t) 0x01) //OUTPUT OPEN DRAIN
#define OUTPUT_ALT_FUNCTION          ((uint32_t) 0x02) //PUSH PULL
#define OUTPUT_ALT_FUNCTION_OD        ((uint32_t) 0x03) //OPEN DRAIN



//PIN SPEEDS 

#define  SPEED_2MHZ             ((uint32_t) 0x02)
#define  SPEED_10MHZ            ((uint32_t) 0x01)     
#define  SPEED_50MHZ            ((uint32_t) 0x03)  

//CLOCK ENABLING

#define GPIO_CLOCK_ENABLE_ALT_FUNC       (RCC->APB2ENR |= (1<<0))
#define GPIO_CLOCK_ENABLE_PORTA      (RCC->APB2ENR |= (1<<2))
#define GPIO_CLOCK_ENABLE_PORTB      (RCC->APB2ENR |= (1<<3))
#define GPIO_CLOCK_ENABLE_PORTC      (RCC->APB2ENR |= (1<<4))
#define GPIO_CLOCK_ENABLE_PORTD      (RCC->APB2ENR |= (1<<5))

// HIGH BIT POSITION FoR CRH REGiSTER AND MODE

#define CNF_POS_BIT1  (PINPOS[pinNumber]+2) 
#define CNF_POS_BIT2  (PINPOS[pinNumber]+3) 



// Functions prototypes

//GPIO Configurations


static void config_pin(GPIO_TypeDef *port,uint32_t pinNumber,uint32_t  Mode_type);
static void config_pin_speed(GPIO_TypeDef *port,uint32_t pinNumber,uint32_t pinSpeed,uint32_t  mode);

// GPIO USER PIN FUNCTIONS

void gpio_write(GPIO_TypeDef *port,uint32_t pinNumber,uint8_t state);
void gpio_toggle(GPIO_TypeDef *port,uint32_t pinNumber);
void gpio_init(GPIO_TYPE gpio_type);


#endif