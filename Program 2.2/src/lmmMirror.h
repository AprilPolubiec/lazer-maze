/********************************************************************
File Name: lmmMirror.h
Programmer: April Polubiec
Date Written: 04/01/2019
Purpose:  Define properties of Mirror modules.


MUTATOR MEMBERS
//pre: none
//post: will initialize the modType to "Mirror"
lmmMirror();


ACCESSOR MEMBERS
//pre: SIDE should be < 4.
//post: will return true if hit on side 0 or 1.
virtual bool out(const unsigned short SIDE) const;

//pre: none.
//post: always returns true.
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
lmmMirror is a derived class of lmModule and is the base class of lmmTarget.

LIBRARIES INCLUDED:
There is 1 external library included.

********************************************************************/
#ifndef LMMMIRROR_H_
#define LMMMIRROR_H_

#include"lmModule.h"

namespace lmclass {

class lmmMirror : public lmModule {
public:
	lmmMirror();
	virtual bool out(const unsigned short SIDE) const;
	virtual bool hit() const;

};

} /* namespace lmclass */

#endif /* LMMMIRROR_H_ */
