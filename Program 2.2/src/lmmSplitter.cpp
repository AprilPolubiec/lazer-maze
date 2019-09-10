/*
 * lmmSplitter.cpp
 *
 *  Created on: Mar 30, 2019
 *      Author: AprilPolubiec
 */

#include "lmmSplitter.h"

namespace lmclass {

//pre: none
//post: will initialize the modType to "Splitter"
lmmSplitter::lmmSplitter()
{
	lmModule::setType("Splitter");
}

//pre: SIDE should be < 4.
//post: if SIDE is valid, the module's output for the side
//      facing SIDE direction on the board (0 up, 1 right,
//      2 down and 3 left) will be returned.
bool lmmSplitter::out(const unsigned short SIDE) const
{
	return true;
}

} /* namespace lmclass */
