#include "at32f403a_407_clock.h"
#include "stdio.h"
#include "timer.h"
#include "usart.h"
#include "delay.h"
/**
 * @brief  main function.
 * @param  none
 * @retval none
 */
int main(void) {
  system_clock_config();
  delay_init();
  usart1_dma_init(115200);
  
  while (1) {
  }
}

/**
 * @}
 */

/**
 * @}
 */
