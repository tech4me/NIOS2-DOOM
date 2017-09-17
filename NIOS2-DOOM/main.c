#include <stdio.h>

#include "altera_avalon_pio_regs.h"
#include "altera_up_avalon_video_pixel_buffer_dma.h"

#include "nios2-doom/i_main.h"

int main()
{
    alt_up_pixel_buffer_dma_dev* pixel_buffer;
    pixel_buffer = alt_up_pixel_buffer_dma_open_dev("/dev/VGA_Subsystem_VGA_Pixel_DMA");
    if (pixel_buffer == NULL)
    {
        printf("Pixel DMA failed to open!\n");
        return 1;
    }
    printf("Pixel DMA open success!\n");

    alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 0);
    alt_up_pixel_buffer_dma_draw_box(pixel_buffer, 0, 0, 319, 239, 0xF800, 0);
    /*
    char buffer[256];
    FILE* fp = fopen("/mnt/host/readme.txt", "rb");
    if (fp == NULL)
    {
        printf("Cannot open readme!\n");
        return 1;
    }
    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);
    */
    Doom_Main(0, NULL);

    int count = 0;
    int delay;
    while (1)
    {
        IOWR_ALTERA_AVALON_PIO_DATA(LEDS_BASE , count & 0x01);
        delay = 0;
        while (delay < 2000000)
        {
            delay++;
        }
        count++;
    }
    return 0;
}
