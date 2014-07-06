// 
// Program:		boxConversion.h
// Author:		Chris Langford
// Date:		07/05/2014
// Description:		Some simple conversions for the box class to other
// 			useful formats
//

#ifndef BOX_CONVERSION_H
#define BOX_CONVERSION_H

#include "../Objects/box.h"

#ifdef _SDL_H
// Function:		boxToSDLRect()
// Description:		Converts a box to an SDL_Rect
// Arguments:
// 	Box box:	a box
// Returns:
// 	SDL_Rect:	a SDL_Rect object
//this only gets compiled if SDL has been included
SDL_Rect boxToSDLRect (CLD_Util::Objects::Box box) {
	SDL_Rect sBox;
	sBox.x = box.x;
	sBox.y = box.y;
	sBox.w = box.w;
	sBox.h = box.h;

	return sBox;
}
#endif

