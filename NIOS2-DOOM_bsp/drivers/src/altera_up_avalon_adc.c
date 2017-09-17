#include <string.h>
#include <errno.h>
#include <limits.h>
#include <math.h>

#include <priv/alt_file.h>
#include "altera_up_avalon_adc.h"

#define read_ch0(adc)  IORD_ALT_UP_ADC_CH_0(((adc)->base))
#define read_ch1(adc)  IORD_ALT_UP_ADC_CH_1(((adc)->base))
#define read_ch2(adc)  IORD_ALT_UP_ADC_CH_2(((adc)->base))
#define read_ch3(adc)  IORD_ALT_UP_ADC_CH_3(((adc)->base))
#define read_ch4(adc)  IORD_ALT_UP_ADC_CH_4(((adc)->base))
#define read_ch5(adc)  IORD_ALT_UP_ADC_CH_5(((adc)->base))
#define read_ch6(adc)  IORD_ALT_UP_ADC_CH_6(((adc)->base))
#define read_ch7(adc)  IORD_ALT_UP_ADC_CH_7(((adc)->base))

alt_up_adc_dev* alt_up_adc_open_dev (const char* name){

	alt_up_adc_dev* dev = (alt_up_adc_dev*) alt_find_dev(name, &alt_dev_list);
	
	return dev;
}

unsigned int alt_up_adc_read (alt_up_adc_dev * adc, unsigned channel){

	unsigned int ch = channel % 8;
	
	switch (ch){
		case 0:
			return read_ch0(adc);
		case 1:
			return read_ch1(adc);
		case 2:
			return read_ch2(adc);
		case 3:
			return read_ch3(adc);
		case 4:
			return read_ch4(adc);
		case 5:
			return read_ch5(adc);
		case 6:
			return read_ch6(adc);
		case 7:
			return read_ch7(adc);
		default:
			return 0;
	}
}

