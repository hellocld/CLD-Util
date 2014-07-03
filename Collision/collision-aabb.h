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
		//	vec2d vA:		Velocity of first object
		//	Box b:			Box of second object
		//	vec2d vB:		Velocity of second object
		//	vec2d& normalA:		Collision normals of first object
		//	vec2d& normalB:		Collision normals of second
		//				object
		//Returns:
		//	float:			Time (0, 1) of collision (1 if
		//				no collision)
		void aabbSweepCheck(CLD_Util::Objects::Box a, CLD_Util::Objects::vec2d vA, 
				    CLD_Util::Objects::Box b, CLD_Util::Objects::vec2d vB, 
				    CLD_Util::Objects::vec2d& normalA,
				    CLD_Util::Objects::vec2d& normalB);
	
		//---------------------------------------------------------------------------
		//Function:			aabbBroadphaseCheck()
		//Description:			Does a broadphase check between
		//				two moving objects
		//Arguments:
		//	Box a:			Box of the first object
		//	vec2d vA:		Velocity of the first object
		//	Box b:			Box of the second object
		//	vec2d vB:		Velocity of the second object
		//Returns:
		//	bool:			True if broadphase collision is
		//				detected
		bool aabbBroadphaseCheck(CLD_Util::Objects::Box a, CLD_Util::Objects::vec2d vA, 
				         CLD_Util::Objects::Box b, CLD_Util::Objects::vec2d vB);
	}
}

#endif
