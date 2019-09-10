/*
 * lmmCheckPoint.cpp
 *
 *  Created on: Mar 30, 2019
 *      Author: AprilPolubiec
 */

#include "lmmCheckPoint.h"

namespace lmclass {

//pre: none
//post: will initialize the modType to "CheckPoint"
lmmCheckPoint::lmmCheckPoint()
{
	lmModule::setType("CheckPoint");
}

//pre: SIDE should be < 4.
//post: will always return true.
bool lmmCheckPoint::out(const unsigned short SIDE) const
{
	return true;
}

//pre: none.
//post: returns true if the module was hit on side 0 or 2.
bool lmmCheckPoint::hit() const
{
	if(inputs[2] || inputs[0])
		return true;
	else
		return false;

}

} /* namespace lmclass */
