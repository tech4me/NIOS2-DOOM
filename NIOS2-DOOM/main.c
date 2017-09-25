#include <stdlib.h>
#include <stdio.h>

#include "altera_avalon_pio_regs.h"

#include "nios2-doom/i_main.h"

#include "nios2-doom-helper/ro_memfs.h"
#include "nios2-doom-helper/vga.h"

RO_MEMFS_INSTANCE(RO_MEMFS, ro_memfs);

int main()
{
    RO_MEMFS_INIT(RO_MEMFS, ro_memfs);
 
    // Set environmental variable to search for wad files in hostfs dir
    setenv("DOOMWADDIR", "/mnt/memfs", 1);

    vga_init();

    Doom_Main(0, NULL);

    int count = 0;
    int delay;
    while (1)
    {
        IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE, count & 0x01);
        delay = 0;
        while (delay < 2000000)
        {
            delay++;
        }
        count++;
    }
    return 0;
}
