/********************************************************************
File Name: lmmLaser.h
Programmer: April Polubiec
Date Written: 04/01/2019
Purpose:  Define properties of Laser modules.


MUTATOR MEMBERS
//pre: none
//post: will initialize the modType to "Laser"
lmmLaser();


ACCESSOR MEMBERS
//pre: SIDE should be < 4.
//post: will always return true.
virtual bool out(const unsigned short SIDE) const;

TYPEDEF, STATIC AND CONSTANT MEMBERS:
There are no typedef members, static or constant members.

VALUE SEMANTICS:
The assignment operator and copy constructor have NOT been overridden and will NOT work correctly.

ORDER SEMANTICS (COMPARISONS):
No comparison operators are implemented.

DYNAMIC MEMORY USAGE:
There is no dynamically allocated memory.

INVARIANTS:
lmmLaser is a derived class of lmModule.

LIBRARIES INCLUDED:
There is 1 external library included.

********************************************************************/

#ifndef LMMLASER_H_
#define LMMLASER_H_

#include"lmModule.h"

namespace lmclass {

class lmmLaser : public lmModule {
public:
	lmmLaser();
	virtual bool out(const unsigned short SIDE) const;
};

} /* namespace lmclass */

#endif /* LMMLASER_H_ */
