#ifndef __ALTERA_UP_AVALON_ADC_REGS_H__
#define __ALTERA_UP_AVALON_ADC_REGS_H__

#include <io.h>

// Channel 0 / Start Register
#define ALT_UP_ADC_CH_0						0
#define IOADDR_ALT_UP_ADC_CH_0(base)		\
        __IO_CALC_ADDRESS_NATIVE(base, ALT_UP_ADC_CH_0)
#define IORD_ALT_UP_ADC_CH_0(base)			\
        IORD(base, ALT_UP_ADC_CH_0)
#define IOWR_ALT_UP_ADC_CH_0(base, data)	\
        IOWR(base, ALT_UP_ADC_CH_0, data)

// Channel 2 / Auto-Run Register
#define ALT_UP_ADC_CH_1						1
#define IOADDR_ALT_UP_ADC_CH_1(base)		\
        __IO_CALC_ADDRESS_NATIVE(base, ALT_UP_ADC_CH_1)
#define IORD_ALT_UP_ADC_CH_1(base)			\
        IORD(base, ALT_UP_ADC_CH_1)
#define IOWR_ALT_UP_ADC_CH_1(base, data)	\
        IOWR(base, ALT_UP_ADC_CH_1, data)
	
// Channel 2 / SCLK Counter Register
#define ALT_UP_ADC_CH_2						2
#define IOADDR_ALT_UP_ADC_CH_2(base)		\
        __IO_CALC_ADDRESS_NATIVE(base, ALT_UP_ADC_CH_2)
#define IORD_ALT_UP_ADC_CH_2(base)			\
        IORD(base, ALT_UP_ADC_CH_2)
#define IOWR_ALT_UP_ADC_CH_2(base, data)	\
        IOWR(base, ALT_UP_ADC_CH_2, data)
		
// Channel 3 Register
#define ALT_UP_ADC_CH_3						3
#define IOADDR_ALT_UP_ADC_CH_3(base)		\
        __IO_CALC_ADDRESS_NATIVE(base, ALT_UP_ADC_CH_3)
#define IORD_ALT_UP_ADC_CH_3(base)			\
        IORD(base, ALT_UP_ADC_CH_3)
#define IOWR_ALT_UP_ADC_CH_3(base, data)	\
        IOWR(base, ALT_UP_ADC_CH_3, data)
		
// Channel 4 / Start Register
#define ALT_UP_ADC_CH_4						4
#define IOADDR_ALT_UP_ADC_CH_4(base)		\
        __IO_CALC_ADDRESS_NATIVE(base, ALT_UP_ADC_CH_4)
#define IORD_ALT_UP_ADC_CH_4(base)			\
        IORD(base, ALT_UP_ADC_CH_4)
#define IOWR_ALT_UP_ADC_CH_4(base, data)	\
        IOWR(base, ALT_UP_ADC_CH_4, data)
			
// Channel 5 / Start Register
#define ALT_UP_ADC_CH_5						5
#define IOADDR_ALT_UP_ADC_CH_5(base)		\
        __IO_CALC_ADDRESS_NATIVE(base, ALT_UP_ADC_CH_5)
#define IORD_ALT_UP_ADC_CH_5(base)			\
        IORD(base, ALT_UP_ADC_CH_5)
#define IOWR_ALT_UP_ADC_CH_5(base, data)	\
        IOWR(base, ALT_UP_ADC_CH_5, data)
		
// Channel 6 / Start Register
#define ALT_UP_ADC_CH_6						6
#define IOADDR_ALT_UP_ADC_CH_6(base)		\
        __IO_CALC_ADDRESS_NATIVE(base, ALT_UP_ADC_CH_6)
#define IORD_ALT_UP_ADC_CH_6(base)			\
        IORD(base, ALT_UP_ADC_CH_6)
#define IOWR_ALT_UP_ADC_CH_6(base, data)	\
        IOWR(base, ALT_UP_ADC_CH_6, data)
		
// Channel 7 / Start Register
#define ALT_UP_ADC_CH_7						7
#define IOADDR_ALT_UP_ADC_CH_7(base)		\
        __IO_CALC_ADDRESS_NATIVE(base, ALT_UP_ADC_CH_7)
#define IORD_ALT_UP_ADC_CH_7(base)			\
        IORD(base, ALT_UP_ADC_CH_7)
#define IOWR_ALT_UP_ADC_CH_7(base, data)	\
        IOWR(base, ALT_UP_ADC_CH_7, data)
		
#endif /* __ALTERA_UP_AVALON_ADC_REGS_H_ */
