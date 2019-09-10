/*
 * lmmLaser.cpp
 *
 *  Created on: Mar 30, 2019
 *      Author: AprilPolubiec
 */

#include "lmmLaser.h"

namespace lmclass {

//pre: none
//post: will initialize the modType to "Laser"
lmmLaser::lmmLaser()
{
	lmModule::setType("Laser");
}

//pre: SIDE should be < 4.
//post: will always return true.
bool lmmLaser::out(const unsigned short SIDE) const
{
	return true;
}

} /* namespace lmclass */
