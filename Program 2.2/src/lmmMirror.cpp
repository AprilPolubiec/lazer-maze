/*
 * lmmMirror.cpp
 *
 *  Created on: Mar 30, 2019
 *      Author: AprilPolubiec
 */

#include "lmmMirror.h"

namespace lmclass {

//pre: none
//post: will initialize the modType to "Mirror"
lmmMirror::lmmMirror()
{
	lmModule::setType("Mirror");
}

//pre: SIDE should be < 4.
//post: will return true if hit on side 0 or 1.
bool lmmMirror::out(const unsigned short SIDE) const
{
	switch(orientation)
	{
	case 0:
		if (SIDE == 0 || SIDE == 1)
			return true;
		else
			return false;
		break;
	case 1:
		if(SIDE == 1 || SIDE == 2)
			return true;
		else
			return false;
		break;
	case 2:
		if (SIDE == 2 || SIDE == 3)
			return true;
		else
			return false;
		break;
	case 3:
		if (SIDE == 3 || SIDE == 0)
			return true;
		else
			return false;
	}

}

//pre: none.
//post: always returns true.
bool lmmMirror::hit() const
{
	return true;
}

} /* namespace lmclass */
