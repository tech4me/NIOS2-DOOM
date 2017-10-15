#include <stdlib.h>
#include <stdio.h>

#include "vga.h"

int vga_init()
{
    pixel_buffer = alt_up_pixel_buffer_dma_open_dev("/dev/VGA_Subsystem_VGA_Pixel_DMA");
    if (pixel_buffer == NULL)
    {
        printf("Pixel DMA failed to open!\n");
        return 1;
    }
    printf("Pixel DMA open success!\n");

    // Clear both buffers (makes all pixels black)
    alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 0);
    alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 1);
    return 0;
}
