/*
* I/O test program
*/
#include <core.h>
int led_pin = 1;
int btn_pin = 5;

void setup()
{
#ifndef PCDUINO_IDE
    if ( argc != 3 )
    {
        printf("Usage %s BUTTON_PIN_NUM(0-13) LED_PIN_NUM(0-13)\n", argv[0]);
        exit(-1);   
    }
    
   
    btn_pin = atoi(argv[1]);
    led_pin = atoi(argv[2]);
#endif
    
            
    pinMode(led_pin, OUTPUT);
}

void loop()
{

        digitalWrite(led_pin, HIGH); // turn on LED
    delay(100);  
        digitalWrite(led_pin, LOW); // turn off LED
    delay(100);  
}
