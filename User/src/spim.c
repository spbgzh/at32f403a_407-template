#include "spim.h"
#include "at32f403a_407.h"

void spim_init(void)
{
  gpio_init_type gpio_init_struct;

  /* enable the clock */
  crm_periph_clock_enable(CRM_IOMUX_PERIPH_CLOCK, TRUE);
  crm_periph_clock_enable(CRM_GPIOA_PERIPH_CLOCK, TRUE);
  crm_periph_clock_enable(CRM_GPIOB_PERIPH_CLOCK, TRUE);

  /* init spim io */
  gpio_default_para_init(&gpio_init_struct);
  gpio_init_struct.gpio_drive_strength = GPIO_DRIVE_STRENGTH_STRONGER;
  gpio_init_struct.gpio_out_type = GPIO_OUTPUT_PUSH_PULL;
  gpio_init_struct.gpio_mode = GPIO_MODE_MUX;
  gpio_init_struct.gpio_pull = GPIO_PULL_NONE;
  gpio_init_struct.gpio_pins = GPIO_PINS_8;
  gpio_init(GPIOA, &gpio_init_struct);
  gpio_init_struct.gpio_pins =
      GPIO_PINS_1 | GPIO_PINS_6 | GPIO_PINS_7 | GPIO_PINS_10 | GPIO_PINS_11;
  gpio_init(GPIOB, &gpio_init_struct);

  /* enable spim, and select pb10, pb11 as spim io */
  gpio_pin_remap_config(EXT_SPIM_GMUX_1001, TRUE);

  /* use en25qh128a as spim flash */
  flash_spim_model_select(FLASH_SPIM_MODEL2);

  /* unlock the spim flash program erase controller */
  while (flash_flag_get(FLASH_SPIM_OBF_FLAG))
    ;
  flash_spim_unlock();
  while (FLASH->ctrl3_bit.oplk)
    ;

  /* if the data written to spim flash need to be scrambled, please specify the
   * scrambled range */
  flash_spim_encryption_range_set(0);
}
