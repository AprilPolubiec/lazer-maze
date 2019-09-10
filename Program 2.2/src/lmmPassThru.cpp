/*
 * lmmPassThru.cpp
 *
 *  Created on: Mar 30, 2019
 *      Author: AprilPolubiec
 */

#include "lmmPassThru.h"

namespace lmclass {

//pre: none
//post: will initialize the modType to "PassThru"
lmmPassThru::lmmPassThru()
{
	lmModule::setType("PassThru");
}

//pre: SIDE should be < 4.
//post: will return true, since lasers will always pass through module
bool lmmPassThru::out(const unsigned short SIDE) const
{
	return true;
}

} /* namespace lmclass */
