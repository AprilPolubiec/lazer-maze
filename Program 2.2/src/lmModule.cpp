/*
 * lmModule.cpp
 *  Created on: Mar 30, 2019
 *    Author: April Polubiec
 */

#include "lmModule.h"

namespace lmclass {

//pre: none
//post: will initialize the input array to all false,
//      orientation to 0 and locked to false.
lmModule::lmModule()
:orientation(0), isLocked(false)
{
	for(int i=0;i<SIZE;++i)
		inputs[i] = false;
}

//pre: none
//post: the object will be destroyed
lmModule::~lmModule()
{
}

//pre: SIN should contain an array of 4 Boolean values
//     representing the module's laser inputs from the
//     modules surrounding it on the board; [0] from above,
//     [1]from the right, [2]from below, and [3] from the left.
//     true represents a laser input and false no laser input.
//post: the object's input array will be updated based on the
//      input array sIn and the module's orientation.
//      i.e. - If the module has an orientation of 1, then its
//             top input is facing the right board input, right
//             is facing down, bottom is facing left and left
//             is facing the up.
bool lmModule::set(const bool SIN[])
{
	bool areDiff = false;
	for(int i=0;i<4;++i)
		if (SIN[i]!=inputs[i])
			areDiff = true;
	if (areDiff == true)
	{
		for(int j=0;j<4;++j)
			inputs[j] = SIN[j];
	}

	return areDiff;
}

//pre: SIDE should be < 4.
//post: if SIDE is valid, the module's output for the side
//      facing SIDE direction on the board (0 up, 1 right,
//      2 down and 3 left) will be returned.
//      This is a pure virtual function.
bool lmModule::out(const unsigned short SIDE) const
{
	return 0.0;
}

//pre: none.
//post: returns the name of the module.
//      This is a virtual function.
std::string lmModule::type() const
{
	return modType;
}

//pre: none.
//post: virtual member to be used by derived classes to access private data member, "modType".
// 		Sets "modType" to the name passed.
void lmModule::setType(std::string name)
{
	modType = name;
}

//pre: OIN should be 0, 1, 2 or 3 to set.
//post: if the module in unlocked and OIN is < 4, the object's
//      orientation will be rotated clockwise OIN times.
//      The object's orientation will be returned.
unsigned short lmModule::orient(const unsigned short OIN)
{
	if (!isLocked)
	{
		if (OIN+orientation<=3)
			orientation += OIN;
		else
		{
			orientation = (orientation + OIN) - 4;
		}
	}

	return orientation;
}

//pre: none.
//post: returns true if the module was hit by a laser.
//      Module hit rules:
//        Target - must be hit on its side 2.
//        CheckPoint - must be hit on its side 0 or 2.
//        All Other Modules - Always retu
bool lmModule::hit() const
{
	return false;
}

//pre: none.
//post: the module will not be able to have its orientation
//      changed.
void lmModule::lock()
{
	isLocked = true;
}

//pre: none.
//post: the module will be able to have its orientation
//      changed.
void lmModule::unlock()
{
	isLocked = false;
}

//pre: none.
//post: the module's orientation will be returned.
bool lmModule::islocked() const
{
	return isLocked;
}
}
