#include "at32f403a_407_clock.h"
#include "stdio.h"
#include "timer.h"
#include "usart.h"
#include "delay.h"
#include "rtc.h"
#include "spim.h"
#include "usercode_to_bootloader.h"

calendar_type time_struct = {
    .year = 2024,
    .month = 6,
    .date = 30,
    .hour = 12,
    .min = 0,
    .sec = 0,
};

int main(void)
{
  UserSystemInit();
  system_clock_config();
  delay_init();
  usart1_dma_init(115200);
  spim_init();
  rtc_init(&time_struct);

  while (1)
  {
  }
}
