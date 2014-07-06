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
//	vec2d v:		Velocity of first object
//	Box b:			Box of second object
//	vec2d& normal:		Collision normals of object
//Returns:
//	float:			Time (0, 1) of collision (1 if
//				no collision)
void CLD_Util::Collision_AABB::aabbSweepCheck(CLD_Util::Objects::Box a, CLD_Util::Objects::vec2d v, CLD_Util::Objects::Box b, 
	CLD_Util::Objects::vec2d& normal) {
	
	//do a quick broadphase check to see if anything's collided
	if(aabbCheck(getBroadphaseBox(a, vA), getBroadphaseBox(b, vB))) {
		float xInvEntry, yInvEntry;
		float xInvExit, yInvExit;

		if(v.x > 0) {
			xInvEntry = b.x - (a.x + a.w);
			xInvExit = (b.x + b.w) - a.x;
		} else {
			xInvEntry = (b.x + b.w) - a.x;
			xInvExit = b.x - (a.x + a.w);
		}
		if(v.y > 0) {
			yInvEntry = b.y - (a.y + a.h);
			yInvExit = (b.y + h.h) - a.y;
		} else {
			yInvEntry = (b.y + b.h) - a.y;
			yInvExit = b.y - (a.y + a.h);
		}

		float xEntry, yEntry;
		float xExit, yExit;

		if(v.x == 0) {
			xEntry = -std::numeric_limits<float>::infinity();
			xExit = std::numeric_limits<float>::infinity();
		} else {
			xEntry = xInvEntry / v.x;
			xExit = xInvExit / v.x;
		}

		if(v.y == 0) {
			yEntry = -std::numeric_limits<float>::infinity();
			yExit = std::numeric_limits<float>::infinity();
		} else {
			yEntry = yInvEntry / v.y;
			yExit = yInvExit / v.y;
		}

		float entryTime = std::max(xEntry, yEntry);
		float exitTime = std::min(xExit, yExit);

		if(entryTime > exitTime || xEntry < 0 && yEntry < 0 || xEntry > 1 || yEntry > 1) {
			normal.x = 0;
			normal.y = 0;
			return 1;
		} else {
			if(xEntry > yEntry) {
				if(xInvEntry < 0) {
					normal.x = 1;
					normal.y = 0;
				} else {
					normal.x = -1;
					normal.y = 0;
				}
			} else {
				if(yInvEntry < 0) {
					normal.x = 0;
					normal.y = 1;
				} else {
					normal.x = 0;
					normal.y = -1;
				}
			}
			return entryTime;
		}

	} else {
		//no collision; set all the vectors to 0
		normal.x = 0;
		normal.y = 0;
		return 1;
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
