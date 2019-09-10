/*
 * lmmTarget.cpp
 *  Created on: Mar 30, 2019
 *      Author: AprilPolubiec
 */

#include "lmmTarget.h"

namespace lmclass {

//pre: none
//post: will initialize the modType to "Target"
lmmTarget::lmmTarget()
{
	lmModule::setType("Target");
}

//pre: SIDE should be < 4.
//post: if SIDE is valid, the module's output for the side
//      facing SIDE direction on the board (0 up, 1 right,
//      2 down and 3 left) will be returned.
bool lmmTarget::out(const unsigned short SIDE) const
{

	return false;
}

//pre: none.
//post: returns true if the module received input on side 2.
bool lmmTarget::hit() const
{
	if(inputs[2])
		return true;
	else
		return false;

}

} /* namespace lmclass */
