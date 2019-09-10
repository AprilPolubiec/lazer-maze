/********************************************************************
File Name: lmModule.h
Programmer: April Polubiec
Date Written: 04/01/2019
Purpose:  Absolute base class for Laser Maze Game modules.


MUTATOR MEMBERS

//pre: none
//post: will initialize the input array to all false,
//      orientation to 0 and locked to false.
lmModule();

//pre: none
//post: the object will be destroyed
~lmModule();

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
bool set(const bool SIN[]);

//pre: OIN should be 0, 1, 2 or 3 to set.
//post: if the module in unlocked and OIN is < 4, the object's
//      orientation will be rotated clockwise OIN times.
//      The object's orientation will be returned.
unsigned short orient(const unsigned short OIN = -1);

//pre: none.
//post: the module will not be able to have its orientation
//      changed.
void lock();

//pre: none.
//post: the module will be able to have its orientation
//      changed.
void unlock();

//pre: none.
//post: sets the object's data member "modType" to the name passed
void setType(std::string name);

ACCESSOR MEMBERS

//pre: none.
//post: the module's orientation will be returned.
bool islocked()const;

//pre: SIDE should be < 4.
//post: if SIDE is valid, the module's output for the side
//      facing SIDE direction on the board (0 up, 1 right,
//      2 down and 3 left) will be returned.
//      This is a pure virtual function.
virtual bool out(const unsigned short SIDE)const = 0;

//pre: none.
//post: returns true if the module was hit by a laser.
//      Module hit rules:
//        Target - must be hit on its side 2.
//        CheckPoint - must be hit on its side 0 or 2.
//        All Other Modules - Always return true.
//      This is a virtual function.
virtual bool hit()const;

//pre: none.
//post: returns the name of the module.
//      This is a virtual function.
virtual std::string type()const;


TYPEDEF, STATIC AND CONSTANT MEMBERS:
There are no typedef members, static or constant members.

VALUE SEMANTICS:
The assignment operator and copy constructor have NOT been overridden and will NOT work correctly.

ORDER SEMANTICS (COMPARISONS):
No comparison operators are implemented.

DYNAMIC MEMORY USAGE:
There is no dynamically allocated memory.

INVARIANTS:
lmModule is the base class of a collection of modules that will
be placed on the board.

LIBRARIES INCLUDED:
There are 2 standard libraries included.
 std::string : used for module name storage and return

********************************************************************/


#ifndef LMMODULE_H_
#define LMMODULE_H_

#include<iostream>
#include<string>

namespace lmclass {

class lmModule {
public:
	static const int SIZE = 4;
	lmModule();
	~lmModule();
	bool set(const bool SIN[]);
	virtual bool out(const unsigned short SIDE) const = 0;
	std::string type() const;
	void setType(std::string name);
	unsigned short orient(const unsigned short OIN=-1);
	virtual bool hit() const;
	void lock();
	void unlock();
	bool islocked()const;
protected:
	bool inputs[SIZE];
	std::string modType;
	unsigned short orientation;
	bool isLocked;
};

} /* namespace lmclass */

#endif /* LMMODULE_H_ */
