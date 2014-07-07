// 
// Program:		collision-aabb.h
// Author:		Chris Langford
// Date:		07/03/2014
// Description:		A collection of simple AABB collision check utilities
//

#ifndef CLD_UTIL_COLLISION_AABB_H
#define CLD_UTIL_COLLISION_AABB_H

#include "../Objects/box.h"
#include "../Objects/vector.h"

namespace CLD_Util {
	namespace Collision_AABB {
		//---------------------------------------------------------------------------
		//Function:			aabbCheck()
		//Description:			simple AABB check
		//Arguments:
		//	Box a:			Box of first object
		//	Box b:			Box of second object
		//Returns:
		//	bool:			True if collision is detected
		bool aabbCheck(CLD_Util::Objects::Box a, CLD_Util::Objects::Box b);
		
		//---------------------------------------------------------------------------
		//Function:			aabbSweepCheck()
		//Description:			AABB sweep check
		//Arguments:
		//	Box a:			Box of first object
		//	vec2d v:		Velocity of first object
		//	Box b:			Box of second object
		//	vec2d& normal:		Collision normals of object
		//Returns:
		//	float:			Time (0, 1) of collision (1 if
		//				no collision)
		float aabbSweepCheck(CLD_Util::Objects::Box a, CLD_Util::Objects::vec2d v, 
				    CLD_Util::Objects::Box b, CLD_Util::Objects::vec2d& normal);
	
		///---------------------------------------------------------------------------
		//Function:			getBroadphaseBox
		//Description:			Generates a box for broadphase AABB testing
		//Arguments:
		//	Box a:			Box of the object
		//	vec2d vA:		Velocity of the object
		//Returns:
		//	Box:			A Broadphase Box
		CLD_Util::Objects::Box getBroadphaseBox(CLD_Util::Objects::Box a, CLD_Util::Objects::vec2d vA);
	}
}

#endif
