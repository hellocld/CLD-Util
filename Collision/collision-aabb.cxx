// 
// Program:		collision-aabb.cxx
// Author:		Chris Langford
// Date:		07/03/2014
// Description:		A collection of simple AABB collision check utilities
//

#include "collision-aabb.h"
#include <cmath>

//---------------------------------------------------------------------------
//Function:			aabbCheck()
//Description:			simple AABB check
//Arguments:
//	Box a:			Box of first object
//	Box b:			Box of second object
//Returns:
//	bool:			True if collision is detected
bool CLD_Util::Collision_AABB::aabbCheck(CLD_Util::Objects::Box a, CLD_Util::Objects::Box b) {
	//lets get the centers of the objects
	CLD_Util::Objects::vec2d centerA;
	CLD_Util::Objects::vec2d centerB;

	centerA.x = a.x + a.w/2;
	centerA.y = a.y + a.h/2;
	
	centerB.x = b.x + b.w/2;
	centerB.y = b.y + b.h/2;

	//check for overlap
	//If the total distance between the furthest edges of each box along one
	//axis is shorter than the total width of both boxes, there's an overlap
	//on that axis. If both axis contain an overlap, that means there's a
	//collision
	if(std::abs(centerA.x - centerB.x) + (a.w + b.w)/2 < a.w + b.w && std::abs(centerA.y - centerB.y) + (a.h + b.h)/2 < a.h + b.h) 
		return true;

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
void CLD_Util::Collision_AABB::aabbSweepCheck(CLD_Util::Objects::Box a, CLD_Util::Objects::vec2d vA, 
	CLD_Util::Objects::Box b, CLD_Util::Objects::vec2d vB, 
	CLD_Util::Objects::vec2d& normalA,
	CLD_Util::Objects::vec2d& normalB) {
	
	//do a quick broadphase check to see if anything's collided
	if(aabbCheck(getBroadphaseBox(a, vA), getBroadphaseBox(b, vB))) {
		//do collision checking stuff
	} else {
		//no collision; set all the vectors to 0
		normalA->x = 0;
		normalA->y = 0;
		normalB->x = 0;
		normalB->y = 0;
	}
}

//---------------------------------------------------------------------------
//Function:			getBroadphaseBox
//Description:			Generates a box for broadphase AABB testing
//Arguments:
//	Box a:			Box of the object
//	vec2d vA:		Velocity of the object
//Returns:
//	Box:			A Broadphase Box
CLD_Util::Objects::Box CLD_Util::Collision_AABB::getBroadphaseBox(CLD_Util::Objects::Box a, CLD_Util::Objects::vec2d vA) {
	CLD_Util::Objects::Box box;
	//all generated value depend on whether or not velocity is negative or
	//positive in either axis
	box.x = vA.x > 0 ? a.x : a.x + vA.x;
	box.y = vA.y > 0 ? a.y : a.y + vA.y;
	box.w = vA.x > 0 ? a.w + vA.x : a.w - vA.x;
	box.h = vA.y > 0 ? a.h + vA.y : a.h - vA.y;
	
	return box;	
}
