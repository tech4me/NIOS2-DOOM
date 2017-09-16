#ifndef __nios2_syscall__
#define __nios2_syscall__

// i_sound ignored

/*i_system*/
	//return time in 1/35 (1/70 on original) tics, called by I_GetTime
	int GetTicks();

	//return string of error message, dont think really need it
	//char* GetError();

	//wait count ms before returning
	void delay(int count);

/*i_video*/
	//return which key is pressed, map to DOOM Keyboard definition in doomdef.h 
	int translateKey(char keyval);

	//return pointer to event_t object, then call D_PostEvent
	event_t* checkEvent(event_t* event);


	bool pollEvent(eventSys* event);

	//update display using screen's value?
	void updateRect(surface* screen, positions);

	//set screen to colors' value?
	void setColors(surface* screen, color* colors, startPt, endPt);

	SDL_SWSURFACE, SDL_HWPALLETTE //need to allocate video surface in memory


	SDL_SetVideoMode(int video_w, int video_h, 8, video_flags);

	showCursor, wm_setcaption

/* d_event.h */
	typedef struct
	{
	    evtype_t	type;
	    int		data1;		// keys / mouse/joystick buttons
	} event_t;









#endif