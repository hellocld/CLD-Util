// 
// Program:		box.h
// Author:		Chris Langford
// Date:		07/03/2014
// Description:		A simple struct for storing rectangle information
//

#ifndef CLD_UTIL_OBJECTS_BOX_H
#define CLD_UTIL_OBJECTS_BOX_H

namespace CLD_Util {
	namespace Objects {
		struct Box {
			Box (float xx, float yy, float ww, float hh) :
				x(xx), y(yy), w(ww), h(hh) {}
			Box ()
				:x(0), y(0), w(1), h(1) {}
			float x;
			float y;
			float w;
			float h;
		};
	}
}

#endif
