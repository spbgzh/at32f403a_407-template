#include "at32f403a_407_clock.h"
#include "at32f403a_407_delay.h"
#include "at32f403a_407_printf.h"
#include "operate_spim.h"
#include "run_in_spim.h"

/**
  * @brief  main function.
  * @param  none
  * @retval none
  */
int main(void)
{
  sclk_240m_hext_config();

  uart_print_init(115200);

  /* initialize delay function */
  delay_init();

	printf ("基于AT32F403A V2库版本的 spim 程序 \r\n");
	spim_init();			//spim接口初始化
	spim_operate();			//保存数据到spim 测试函数，从flash 的2M的地址开始写入4KB大小的数据
	spim_run();				//代码运行在spim 测试函数，死循环每1s自加1并且输出log

  while(1)
  {
    
  }
}
