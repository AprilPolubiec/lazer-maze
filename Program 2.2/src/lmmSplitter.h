
/********************************************************************
File Name: lmmSplitter.h
Programmer: April Polubiec
Date Written: 04/01/2019
Purpose:  Define properties of Splitter modules.


MUTATOR MEMBERS
//pre: none
//post: will initialize the modType to "Splitter"
lmmSplitter();


ACCESSOR MEMBERS
//pre: SIDE should be < 4.
//post: if SIDE is valid, the module's output for the side
//      facing SIDE direction on the board (0 up, 1 right,
//      2 down and 3 left) will be returned.
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
lmmSplitter is a derived class of lmModule.

LIBRARIES INCLUDED:
There is 1 external library included.

********************************************************************/

#ifndef LMMSPLITTER_H_
#define LMMSPLITTER_H_

#include"lmModule.h"

namespace lmclass {

class lmmSplitter : public lmModule {
public:
	lmmSplitter();
	virtual bool out(const unsigned short SIDE) const;
};

} /* namespace lmclass */

#endif /* LMMSPLITTER_H_ */
