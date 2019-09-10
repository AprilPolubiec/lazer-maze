/*
/********************************************************************
File Name: lmmTarget.h
Programmer: April Polubiec
Date Written: 04/01/2019
Purpose:  Define properties of Target modules.


MUTATOR MEMBERS
//pre: none
//post: will initialize the modType to "Target"
lmmTarget();


ACCESSOR MEMBERS
//pre: SIDE should be < 4.
//post: if SIDE is valid, the module's output for the side
//      facing SIDE direction on the board (0 up, 1 right,
//      2 down and 3 left) will be returned.
virtual bool out(const unsigned short SIDE) const;

//pre: none.
//post: returns true if the module received input on side 2.
virtual bool hit() const;

TYPEDEF, STATIC AND CONSTANT MEMBERS:
There are no typedef members, static or constant members.

VALUE SEMANTICS:
The assignment operator and copy constructor have NOT been overridden and will NOT work correctly.

ORDER SEMANTICS (COMPARISONS):
No comparison operators are implemented.

DYNAMIC MEMORY USAGE:
There is no dynamically allocated memory.

INVARIANTS:
lmmTarget is the derived class of lmmMirror.

LIBRARIES INCLUDED:
There is 1 external library included.

********************************************************************/


#ifndef LMMTARGET_H_
#define LMMTARGET_H_

#include"lmmMirror.h"

namespace lmclass {

class lmmTarget : public lmmMirror {
public:
	lmmTarget();
	virtual bool out(const unsigned short SIDE) const;
	virtual bool hit() const;

};

} /* namespace lmclass */

#endif /* LMMTARGET_H_ */
