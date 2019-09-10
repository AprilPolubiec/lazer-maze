/********************************************************************
File Name: lmmBlocker.h
Programmer: April Polubiec
Date Written: 04/01/2019
Purpose:  Define properties of Blocker modules.


MUTATOR MEMBERS
//pre: none
//post: will initialize the modType to "Blocker"
lmmBlocker();


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
lmmMirror is a derived class of lmModule and is the base class of lmmTarget.

LIBRARIES INCLUDED:
There is 1 external library included.

********************************************************************/

#ifndef LMMBLOCKER_H_
#define LMMBLOCKER_H_

#include"lmModule.h"

namespace lmclass {

class lmmBlocker : public lmModule {
public:
	lmmBlocker();
	virtual bool out(const unsigned short SIDE) const;
};

} /* namespace lmclass */

#endif /* LMMBLOCKER_H_ */
