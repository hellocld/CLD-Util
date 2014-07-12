// 
// Program:		boxConversion.h
// Author:		Chris Langford
// Date:		07/05/2014
// Description:		Some simple conversions for the box class to other
// 			useful formats
//

#ifndef BOX_TOOLS_H
#define BOX_TOOLS_H

#include "../Objects/box.h"
#include "../Objects/vector.h"

namespace CLD_Util {
	namespace Tools {
#ifdef _SDL_H
		// Function:		boxToSDLRect()
		// Description:		Converts a box to an SDL_Rect
		// Arguments:
		// 	Box box:	a box
		// Returns:
		// 	SDL_Rect:	a SDL_Rect object
		//this only gets compiled if SDL has been included
		inline SDL_Rect boxToSDLRect (CLD_Util::Objects::Box box) {
			SDL_Rect sBox;
			sBox.x = box.x;
			sBox.y = box.y;
			sBox.w = box.w;
			sBox.h = box.h;

			return sBox;
		}
#endif

		// Function:		boxMove()
		// Description:		Moves a box via a vec2d
		// Arguments:
		// 	Box box:	The box to move
		// 	vec2d vector:	Amount to move the box
		// Returns:
		// 	none
		inline void boxMove(CLD_Util::Objects::Box& box, CLD_Util::Objects::vec2d vector) {
			box.x += vector.x;
			box.y += vector.y;
		}

		// Function:		boxResize()
		// Description:		Resizes a box via a vec2d
		// Arguments:
		// 	Box box:	The box to resize
		// 	vec2d resize:	New dimensions
		// Returns:
		// 	none
		inline void boxResize(CLD_Util::Objects::Box& box, CLD_Util::Objects::vec2d resize) {
			box.w = resize.x;
			box.h = resize.y;
		}
	}
}

#endif
