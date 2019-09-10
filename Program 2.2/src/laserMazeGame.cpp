
// laserMaze.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include <limits>
#include "laserMaze.h"
#include "lmModule.h"
#include "lmmPassThru.h"
#include "lmmLaser.h"
#include "lmmTarget.h"
#include "lmmMirror.h"
#include "lmmDblMirror.h"
#include "lmmSplitter.h"
#include "lmmBlocker.h"
#include "lmmCheckPoint.h"

void dispBoard(lmclass::laserMaze& gameBoard);
bool fileIO(const unsigned ioOP, lmclass::laserMaze& gameBoard);

int main()
{
	lmclass::laserMaze gameBoard;
	lmclass::lmModule* lmmod = nullptr;
	unsigned opCode, modNum, ioOp;
	unsigned row, col, reorient;
	bool won;

do
{
	gameBoard.update();
	dispBoard(gameBoard);
	std::cout << std::endl;
	std::cout << "(1)Load, (2)Remove or (3)Orient a module, (4)Fire laser, (5)Load/Save or (6)Quit" << std::endl;
	std::cout << "What do you want to do? ";
	while (!(std::cin >> opCode) || opCode > 6)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	switch (opCode)
	{
	case 1: std::cout << "(1)Laser, (2)Target, (3)Mirror, (4)Double Mirror, (5)Splitter, (6)Check Point, (7)Blocker" << std::endl;
		std::cout << "Enter Module # to load onto the board: ";
		while (!(std::cin >> modNum) || modNum > 7)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "Enter the target row and column for new module (i.e. 3 2): ";
		while (!(std::cin >> row) || row > 4)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		while (!(std::cin >> col) || col > 4)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << std::endl;
		switch (modNum)
		{
		case 1: lmmod = new lmclass::lmmLaser; break;
		case 2: lmmod = new lmclass::lmmTarget; break;
		case 3: lmmod = new lmclass::lmmMirror; break;
		case 4: lmmod = new lmclass::lmmDblMirror; break;
		case 5: lmmod = new lmclass::lmmSplitter; break;
		case 6: lmmod = new lmclass::lmmCheckPoint; break;
		case 7: lmmod = new lmclass::lmmBlocker; break;
		default: lmmod = new lmclass::lmmPassThru; break;
		}
		gameBoard.set(row, col, lmmod);
		break;
	case 2: std::cout << "Enter the target row and column of the module to remove (i.e. 3 2): ";
		while (!(std::cin >> row) || row > 4)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		while (!(std::cin >> col) || col > 4)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << std::endl;
		lmmod = new lmclass::lmmPassThru;
		gameBoard.set(row, col, lmmod);
		break;
	case 3: std::cout << "Enter the target row and column of the module to reorient (i.e. 3 2): ";
		while (!(std::cin >> row) || row > 4)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		while (!(std::cin >> col) || col > 4)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << "Enter the number of 90 degree turns to the right to make (i.e. 0 to 3): ";
		while (!(std::cin >> reorient) || reorient > 3)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::cout << std::endl;
		gameBoard.at(row, col).orient(reorient);
		break;
	case 4: gameBoard.update();
		won = gameBoard.solved();
		if (won)
			std::cout << "You have solved the maze!" << std::endl;
		else
			std::cout << "You did not solve the maze." << std::endl;
		break;
	case 5: std::cout << "(1)Load Game, (2)Save Game or (3)Cancel Operation? " << std::endl;
		while (!(std::cin >> ioOp) || ioOp > 3)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (ioOp != 3 && !fileIO(ioOp, gameBoard))
			std::cout << "File System Error Occurred!" << std::endl;
		break;
	case 6: std::cout << "Bye." << std::endl;
	}

}while (opCode != 6);

    return 0;
}

void dispBoard(lmclass::laserMaze& gameBoard)
{
	for (unsigned short r = 0; r < 5; ++r)
		for (unsigned short l = 0; l < 3; ++l)
		{
			for (unsigned short c = 0; c < 5; ++c)
			{
				if (l == 0 || l == 2)
				{
					if (gameBoard.at(r, c).out(l))
						std::cout << "+-*-+ ";
					else
						std::cout << "+---+ ";
				}
				else
				{
					if (gameBoard.at(r, c).out(3))
						std::cout << "*";
					else
						std::cout << "|";

					if (gameBoard.at(r, c).type() != "PassThru")
					{
						std::cout << gameBoard.at(r, c).type().at(0);
						if (gameBoard.at(r, c).type() == "Target" && gameBoard.at(r, c).hit())
							std::cout << '*';
						else
							std::cout << ' ';
						std::cout << gameBoard.at(r, c).orient();
					}
					else
						std::cout << "   ";

					if (gameBoard.at(r, c).out(1))
						std::cout << "* ";
					else
						std::cout << "| ";
				}
			}
			std::cout << std::endl;
		}
}

bool fileIO(const unsigned ioOP, lmclass::laserMaze& gameBoard)
{
	unsigned modNum, orientation, row, col;
	lmclass::lmModule* lmmod = nullptr;

	if (ioOP == 1)
	{
		std::ifstream infile;   //Create an input stream
		infile.open("lmSavedGame.dat", std::ios::in);  //Open the stream

		if (!infile)
		{
			return false;
		}
		else
			while (!infile.eof())              //Loop to read in infile records
			{
				infile >> modNum;
				infile >> orientation;
				infile >> row;
				infile >> col;
				switch (modNum)
				{
				case 1: lmmod = new lmclass::lmmLaser; break;
				case 2: lmmod = new lmclass::lmmTarget; break;
				case 3: lmmod = new lmclass::lmmMirror; break;
				case 4: lmmod = new lmclass::lmmDblMirror; break;
				case 5: lmmod = new lmclass::lmmSplitter; break;
				case 6: lmmod = new lmclass::lmmCheckPoint; break;
				case 7: lmmod = new lmclass::lmmBlocker; break;
				default: lmmod = new lmclass::lmmPassThru; break;
				}
				lmmod->orient(orientation);
				gameBoard.set(row, col, lmmod);
			}

		infile.close();                         //Close the input file
		return true;
	}
	if (ioOP == 2)
	{
		std::ofstream outfile;   //Create an input stream

		outfile.open("lmSavedGame.dat", std::ios::out);  //Open the stream

		if (!outfile)
		{
			return false;
		}
		else
		{
			std::string modType;
			for (size_t i = 0; i < 25; ++i)
			{
				modType = gameBoard.at(i / 5, i % 5).type();
				if (modType != "PassThru")
				{
					if (modType == "Laser")
						outfile << 1 << ' ';
					else
						if (modType == "Target")
							outfile << 2 << ' ';
						else
							if (modType == "Mirror")
								outfile << 3 << ' ';
							else
								if (modType == "DblMirror")
									outfile << 4 << ' ';
								else
									if (modType == "Splitter")
										outfile << 5 << ' ';
									else
										outfile << 6 << ' ';
					outfile << gameBoard.at(i / 5, i % 5).orient() << ' ';
					outfile << i / 5 << ' ' << i % 5 << std::endl;
				}
			}
			outfile.close();                         //Close the input file
			return true;
		}
	}
	return false;
}
