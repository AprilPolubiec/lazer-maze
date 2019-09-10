/*
 * lmmBlocker.cpp
 *
 *  Created on: Mar 30, 2019
 *      Author: AprilPolubiec
 */

#include "lmmBlocker.h"

namespace lmclass {

//pre: none
//post: will initialize the modType to "Blocker"
lmmBlocker::lmmBlocker()
{
	lmModule::setType("Blocker");
}

//pre: SIDE should be < 4.
//post: will always return true.
bool lmmBlocker::out(const unsigned short SIDE) const
{
	return true;
}

} /* namespace lmclass */
