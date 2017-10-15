#include <stdlib.h>
#include <stdio.h>

#include "keyboard.h"

int keyboard_init()
{
    keyboard = alt_up_ps2_open_dev("/dev/PS2_Port");
    if (keyboard == NULL)
    {
        printf("Keyboard failed to open!\n");
        return 1;
    }
    printf("Keyboard open success!\n");
    return 0;
}