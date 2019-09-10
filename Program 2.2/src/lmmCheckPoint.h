/********************************************************************
File Name: lmmCheckPoint.h
Programmer: April Polubiec
Date Written: 04/01/2019
Purpose:  Define properties of CheckPoint modules.


MUTATOR MEMBERS
//pre: none
//post: will initialize the modType to "CheckPoint"
lmmCheckPoint();


ACCESSOR MEMBERS
//pre: SIDE should be < 4.
//post: will always return true.
virtual bool out(const unsigned short SIDE) const;

//pre: none.
//post: returns true if the module was hit on side 0 or 2.
virtual bool hit()const;

TYPEDEF, STATIC AND CONSTANT MEMBERS:
There are no typedef members, static or constant members.

VALUE SEMANTICS:
The assignment operator and copy constructor have NOT been overridden and will NOT work correctly.

ORDER SEMANTICS (COMPARISONS):
No comparison operators are implemented.

DYNAMIC MEMORY USAGE:
There is no dynamically allocated memory.

INVARIANTS:
lmmMirror is a derived class of lmModule and is the base class of lmmTarget.

LIBRARIES INCLUDED:
There is 1 external library included.

********************************************************************/

#ifndef LMMCHECKPOINT_H_
#define LMMCHECKPOINT_H_

#include"lmModule.h"

namespace lmclass {

class lmmCheckPoint : public lmModule {
public:
	lmmCheckPoint();
	virtual bool out(const unsigned short SIDE) const;
	virtual bool hit() const;
};

} /* namespace lmclass */

#endif /* LMMCHECKPOINT_H_ */
