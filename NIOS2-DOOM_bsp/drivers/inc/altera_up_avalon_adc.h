#ifndef __ALTERA_UP_AVALON_ADC_H__
#define __ALTERA_UP_AVALON_ADC_H__

#include <stddef.h>
#include "sys/alt_dev.h"
#include "sys/alt_alarm.h"
#include "sys/alt_warning.h"

#include "altera_up_avalon_adc_regs.h"

/**
 *
 *
 *
 **/
typedef struct alt_up_adc_dev {
	/// @brief device structure
	alt_dev dev;
	/// @brief the base address of the device
	unsigned int base;
} alt_up_adc_dev;

/**
 * @brief Open the adc device specified be <em> name </em>
 *
 * @param name -- the adc name. For Example, if the aprallel port name in Qsys is "ADC_slave", then <em> name </em> should be "/dev/ADC_slave"
 *
 * @return The corresponding device structure, or NULL if the device is not found.
 **/
alt_up_adc_dev* alt_up_adc_open_dev (const char* name);

/**
 * @brief Read from a given channel
 *
 * @param adc -- struct for the adc device
 * @param channel -- the channel number to be read
 *
 * @return The 12-bit value read from the ADC
 **/
unsigned int alt_up_adc_read (alt_up_adc_dev * adc, unsigned channel);

/**
 * @brief Update the ADC readings
 *
 * @param adc -- struct for the adc device
 **/
//void alt_up_adc_update(alt_up_adc_dev* adc)
#define alt_up_adc_update(adc)  IOWR_ALT_UP_ADC_CH_0(((adc)->base), 0x0)

/**
 * @brief Enable Auto-Update
 *
 * @param adc -- struct for the adc device
 **/
//void alt_up_adc_auto_enable(alt_up_adc_dev* adc)
#define alt_up_adc_auto_enable(adc)  IOWR_ALT_UP_ADC_CH_1(((adc)->base), 0x1)

/**
 * @brief Disable Auto-Update
 *
 * @param adc -- struct for the adc device
 **/
//void alt_up_adc_auto_disable(alt_up_adc_dev* adc)
#define alt_up_adc_auto_disable(adc)  IOWR_ALT_UP_ADC_CH_1(((adc)->base), 0x0)

/*
 * Macros used by alt_sys_init 
 */
#define ALTERA_UP_AVALON_ADC_INSTANCE(name, device)	\
static alt_up_adc_dev device =						\
{																\
  {																\
	ALT_LLIST_ENTRY,											\
	name##_NAME,												\
	NULL, /* open */											\
	NULL, /* close */											\
	NULL, /* read */											\
	NULL, /* write */											\
	NULL, /* lseek */											\
	NULL, /* fstat */											\
	NULL, /* ioctl */											\
  },															\
  name##_BASE,													\
}

#define ALTERA_UP_AVALON_ADC_INIT(name, device)		\
{									  							\
	alt_dev_reg(&device.dev);									\
}

#endif /* __ALTERA_UP_AVALON_ADC_H__ */
