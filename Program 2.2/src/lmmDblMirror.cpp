/*
 * lmmDblMirror.cpp
 *
 *  Created on: Mar 30, 2019
 *      Author: AprilPolubiec
 */

#include "lmmDblMirror.h"

namespace lmclass {

//pre: none
//post: will initialize the modType to "DblMirror"
lmmDblMirror::lmmDblMirror()
{
	lmModule::setType("DblMirror");
}

//pre: SIDE should be < 4.
//post: will always return true.
bool lmmDblMirror::out(const unsigned short SIDE) const
{
	return true;
}

} /* namespace lmclass */
