#include <stdlib.h>
#include <stdio.h>

#include "altera_up_avalon_video_pixel_buffer_dma.h"

#include "vga.h"

int vga_init()
{
    alt_up_pixel_buffer_dma_dev *pixel_buffer;
    pixel_buffer = alt_up_pixel_buffer_dma_open_dev("/dev/VGA_Subsystem_VGA_Pixel_DMA");
    if (pixel_buffer == NULL)
    {
        printf("Pixel DMA failed to open!\n");
        return 1;
    }
    printf("Pixel DMA open success!\n");

    //unsigned char *vga_buf = (unsigned char *)malloc(sizeof(unsigned char) * 320 * 240 * 3);

    // Clear both buffers (makes all pixels black)
    alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 0);
    //alt_up_pixel_buffer_dma_clear_screen(pixel_buffer, 1);
    alt_up_pixel_buffer_dma_draw_box(pixel_buffer, 0, 0, 319, 239, 0x00FFFF, 0);

    return 0;
}
