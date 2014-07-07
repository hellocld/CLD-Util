// 
// Program:		vector.h
// Author:		Chris Langford
// Date:		07/03/2014
// Description:		A set of structs for storing vector information
//

#ifndef CLD_UTIL_OBJECTS_VECTOR_H
#define CLD_UTIL_OBJECTS_VECTOR_H

#include <iostream>

namespace CLD_Util {
	namespace Objects {
		struct vec2d {
			vec2d(float xx, float yy)
				:x(xx), y(yy){};
			float x;
			float y;

			//operator overloads
			vec2d operator+ (const vec2d& other) {
				float rx = x + other.x;
				float ry = y + other.y;
				return vec2d(rx, ry);
			}
			vec2d operator- (const vec2d& other) {
				float rx = x - other.x;
				float ry = y- other.y;
				return vec2d(rx, ry);
			}
			vec2d operator* (const vec2d& other) {
				float rx = x * other.x;
				float ry = y * other.y;
				return vec2d(rx, ry);
			}
			vec2d operator* (float i) {
				float rx = x * i;
				float ry = y * i;
				return vec2d(rx, ry);
			}
			vec2d operator/ (const vec2d& other) {
				float rx = x / other.x;
				float ry = y / other.y;
				return vec2d(rx, ry);
			}
			vec2d operator/ (float i) {
				float rx = x / i;
				float ry = y / i;
				return vec2d(rx, ry);
			}

			friend std::ostream& operator<< (std::ostream& out, const vec2d& v);

		};

		std::ostream& operator<< (std::ostream& out, const vec2d& v) {
			out<<"x:\t"<<v.x<<"\n";
			out<<"y:\t"<<v.y<<"\n";
		}
	}
}

#endif
