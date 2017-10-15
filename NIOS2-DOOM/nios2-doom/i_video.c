// Emacs style mode select   -*- C++ -*-
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// $Log:$
//
// DESCRIPTION:
//	DOOM graphics stuff for SDL library
//
//-----------------------------------------------------------------------------

static const char
	rcsid[] = "$Id: i_x.c,v 1.6 1997/02/03 22:45:10 b1 Exp $";

#include <stdlib.h>
#include <stdint.h>

#include "system.h"
#include "vga.h"
#include "keyboard.h"

#include "m_swap.h"
#include "doomstat.h"
#include "i_system.h"
#include "v_video.h"
#include "m_argv.h"
#include "d_main.h"

#include "doomdef.h"

// Fake mouse handling.
boolean grabMouse;

static uint32_t pallette_colors[256];

void I_ShutdownGraphics(void)
{
}

//
// I_StartFrame
//
void I_StartFrame(void)
{
	// er?
}

int translatekey(KB_CODE_TYPE decode_mode, alt_u8 buf, char ascii)
{
	int rc;
	switch (decode_mode)
	{
	case KB_ASCII_MAKE_CODE:
	case KB_BINARY_MAKE_CODE:
		switch (buf)
		{
		case 0x45: // 0
			rc = 0x30;
			break;
		case 0x16: // 1
			rc = 0x31;
			break;
		case 0x1E: // 2
			rc = 0x32;
			break;
		case 0x26: // 3
			rc = 0x33;
			break;
		case 0x25: // 4
			rc = 0x34;
			break;
		case 0x2E: // 5
			rc = 0x35;
			break;
		case 0x36: // 6
			rc = 0x36;
			break;
		case 0x3D: // 7
			rc = 0x37;
			break;
		case 0x3E: // 8
			rc = 0x38;
			break;
		case 0x46: // 9
			rc = 0x39;
			break;
		case 0x29: // Space case
			rc = 0x20;
			break;
		case 0x76:
			rc = KEY_ESCAPE;
			break;
		case 0x5A:
			rc = KEY_ENTER;
			break;
		case 0x0D:
			rc = KEY_TAB;
			break;
		case 0x05:
			rc = KEY_F1;
			break;
		case 0x06:
			rc = KEY_F2;
			break;
		case 0x04:
			rc = KEY_F3;
			break;
		case 0x0C:
			rc = KEY_F4;
			break;
		case 0x03:
			rc = KEY_F5;
			break;
		case 0x0B:
			rc = KEY_F6;
			break;
		case 0x83:
			rc = KEY_F7;
			break;
		case 0x0A:
			rc = KEY_F8;
			break;
		case 0x01:
			rc = KEY_F9;
			break;
		case 0x09:
			rc = KEY_F10;
			break;
		case 0x78:
			rc = KEY_F11;
			break;
		case 0x07:
			rc = KEY_F12;
			break;
		case 0x59:
			rc = KEY_RSHIFT;
			break;
		case 0x11:
			rc = KEY_LALT;
			break;
		}
		break;
	case KB_LONG_BINARY_MAKE_CODE:
		switch (buf)
		{
		case 0x74:
			rc = KEY_RIGHTARROW;
			break;
		case 0x6B:
			rc = KEY_LEFTARROW;
			break;
		case 0x75:
			rc = KEY_UPARROW;
			break;
		case 0x72:
			rc = KEY_DOWNARROW;
			break;
		case 0x14:
			rc = KEY_RCTRL;
			break;
		case 0x11:
			rc = KEY_RALT;
			break;
		}
		break;
	case KB_BREAK_CODE:
		switch (buf)
		{
		case 0x45: // 0
			rc = 0x30;
			break;
		case 0x16: // 1
			rc = 0x31;
			break;
		case 0x1E: // 2
			rc = 0x32;
			break;
		case 0x26: // 3
			rc = 0x33;
			break;
		case 0x25: // 4
			rc = 0x34;
			break;
		case 0x2E: // 5
			rc = 0x35;
			break;
		case 0x36: // 6
			rc = 0x36;
			break;
		case 0x3D: // 7
			rc = 0x37;
			break;
		case 0x3E: // 8
			rc = 0x38;
			break;
		case 0x46: // 9
			rc = 0x39;
			break;
		case 0x29: // Space case
			rc = 0x20;
			break;
		case 0x76:
			rc = KEY_ESCAPE;
			break;
		case 0x5A:
			rc = KEY_ENTER;
			break;
		case 0x0D:
			rc = KEY_TAB;
			break;
		case 0x05:
			rc = KEY_F1;
			break;
		case 0x06:
			rc = KEY_F2;
			break;
		case 0x04:
			rc = KEY_F3;
			break;
		case 0x0C:
			rc = KEY_F4;
			break;
		case 0x03:
			rc = KEY_F5;
			break;
		case 0x0B:
			rc = KEY_F6;
			break;
		case 0x83:
			rc = KEY_F7;
			break;
		case 0x0A:
			rc = KEY_F8;
			break;
		case 0x01:
			rc = KEY_F9;
			break;
		case 0x09:
			rc = KEY_F10;
			break;
		case 0x78:
			rc = KEY_F11;
			break;
		case 0x07:
			rc = KEY_F12;
			break;
		case 0x59:
			rc = KEY_RSHIFT;
			break;
		case 0x11:
			rc = KEY_LALT;
			break;
		}
		break;
	case KB_LONG_BREAK_CODE:
		switch (buf)
		{
		case 0x74:
			rc = KEY_RIGHTARROW;
			break;
		case 0x6B:
			rc = KEY_LEFTARROW;
			break;
		case 0x75:
			rc = KEY_UPARROW;
			break;
		case 0x72:
			rc = KEY_DOWNARROW;
			break;
		case 0x14:
			rc = KEY_RCTRL;
			break;
		case 0x11:
			rc = KEY_RALT;
			break;
		}
		break;
	default:
		break;
	}
	return rc;
}

void I_GetEvent(KB_CODE_TYPE decode_mode, alt_u8 buf, char ascii)
{
	event_t event;

	switch (decode_mode)
	{
	case KB_ASCII_MAKE_CODE:
	case KB_BINARY_MAKE_CODE:
	case KB_LONG_BINARY_MAKE_CODE:
		event.type = ev_keydown;
		event.data1 = translatekey(decode_mode, buf, ascii);
		D_PostEvent(&event);
		break;

	case KB_BREAK_CODE:
	case KB_LONG_BREAK_CODE:
		event.type = ev_keyup;
		event.data1 = translatekey(decode_mode, buf, ascii);
		D_PostEvent(&event);
		break;
	default:
		break;
	}
}

//
// I_StartTic
//
void I_StartTic(void)
{
	KB_CODE_TYPE decode_mode;
	alt_u8 buf;
	char ascii;
	do
	{
		decode_scancode(keyboard, &decode_mode, &buf, &ascii);
		I_GetEvent(decode_mode, buf, ascii);
	} while (decode_mode != KB_INVALID_CODE);
}

//
// I_UpdateNoBlit
//
void I_UpdateNoBlit(void)
{
	// what is this?
}

//
// I_FinishUpdate
//
void I_FinishUpdate(void)
{
	static int lasttic;
	int tics;
	int i;

	// draws little dots on the bottom of the screen
	if (devparm)
	{

		i = I_GetTime();
		tics = i - lasttic;
		lasttic = i;
		if (tics > 20)
			tics = 20;

		for (i = 0; i < tics * 2; i += 2)
			screens[0][(SCREENHEIGHT - 1) * SCREENWIDTH + i] = 0xff;
		for (; i < 20 * 2; i += 2)
			screens[0][(SCREENHEIGHT - 1) * SCREENWIDTH + i] = 0x0;
	}

	while (alt_up_pixel_buffer_dma_check_swap_buffers_status(pixel_buffer))
		;

	// Get backbuffer from control register
	register unsigned int *backbuffer = *((int *)(VGA_SUBSYSTEM_VGA_PIXEL_DMA_BASE) + 1);
	register unsigned char *screen = (unsigned char *)screens[0];
	register unsigned int offset_y = pixel_buffer->y_coord_offset - 2; // -2 because I used unsigned int * for backbuffer
	register unsigned int x, y;

	for (y = 0; y < SCREENHEIGHT; y++)
	{
		for (x = 0; x < SCREENWIDTH; x++)
		{
			backbuffer[x] = pallette_colors[*screen];
			screen++;
		}
		backbuffer += (1 << offset_y);
	}
	alt_up_pixel_buffer_dma_swap_buffers(pixel_buffer);
}

//
// I_ReadScreen
//
void I_ReadScreen(byte *scr)
{
	memcpy(scr, screens[0], SCREENWIDTH * SCREENHEIGHT);
}

//
// I_SetPalette
//
void I_SetPalette(byte *palette)
{
	int i;
	for (i = 0; i < 256; ++i)
	{
		pallette_colors[i] = 0;
		pallette_colors[i] |= gammatable[usegamma][*palette++] << 16;
		pallette_colors[i] |= gammatable[usegamma][*palette++] << 8;
		pallette_colors[i] |= gammatable[usegamma][*palette++];
	}
}

void I_InitGraphics(void)
{
	static int firsttime = 1;

	if (!firsttime)
		return;
	firsttime = 0;

	// check if the user wants to grab the mouse (quite unnice)
	grabMouse = !!M_CheckParm("-grabmouse");
}
