// 
// Program:		collision-aabb.cxx
// Author:		Chris Langford
// Date:		07/03/2014
// Description:		A collection of simple AABB collision check utilities
//

#include "collision-aabb.h"
#include <stdlib.h>

//---------------------------------------------------------------------------
//Function:			aabbCheck()
//Description:			simple AABB check
//Arguments:
//	Box a:			Box of first object
//	Box b:			Box of second object
//Returns:
//	bool:			True if collision is detected
bool CLD_Util::Collision_AABB::aabbCheck(CLD_Util::Objects::Box a, CLD_Util::Objects::Box b) {
	//really just a big if statement to see if the future positions of
	//either box are overlapping
	if(abs((a.x + a.w)-(b.x + b.w)) < (a.w + b.w) && abs((a.y + a.h) - (b.y + b.h)) < (a.h + b.h))
		//collision detected, return true
		return true;
	//no collision, return false
	return false;
}

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
		    CLD_Util::Objects::vec2d& normalB) {
	//not yet written
}

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
		         CLD_Util::Objects::Box b, CLD_Util::Objects::vec2d vB) {
	//not yet written
}


	

