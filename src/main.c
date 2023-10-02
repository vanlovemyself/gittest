#include "keypad.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>




void app_main() {

   bool blink = false;

   esp_rom_gpio_pad_select_gpio(2);
   gpio_set_direction(2,GPIO_MODE_OUTPUT);

    /// keypad pinout
    ///                     R1  R2  R3  R4  C1  C2  C3  C4 
    gpio_num_t keypad[8] = {13, 12, 14, 27, 26, 25, 33, 32};

    /// Initialize keyboard
    keypad_initalize(keypad);
    while(true)
    {
        char keypressed = keypad_getkey();  /// gets from key queue
        if(keypressed != '\0')
        {
            
            

        }

        if(blink == true)
        {
            gpio_set_level(2,1);
            vTaskDelay(500/ portTICK_PERIOD_MS);
            gpio_set_level(2,0);
            vTaskDelay(500/ portTICK_PERIOD_MS);
        }
      
        
    }
    
}