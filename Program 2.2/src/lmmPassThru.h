/********************************************************************
File Name: lmmPassThru.h
Programmer: April Polubiec
Date Written: 04/01/2019
Purpose:  Define properties of PassThru modules.


MUTATOR MEMBERS
//pre: none
//post: will initialize the modType to "PassThru"
lmmPassThru();


ACCESSOR MEMBERS
//pre: SIDE should be < 4.
//post: will return true, since lasers will always pass through module
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
lmmPassThru is a derived class of lmModule.

LIBRARIES INCLUDED:
There is 1 external library included.

********************************************************************/

#ifndef LMMPASSTHRU_H_
#define LMMPASSTHRU_H_

#include"lmModule.h"

namespace lmclass {

class lmmPassThru : public lmModule {
public:
	lmmPassThru();
	virtual bool out(const unsigned short SIDE) const;
};

} /* namespace lmclass */

#endif /* LMMPASSTHRU_H_ */
