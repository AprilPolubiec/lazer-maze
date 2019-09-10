#include "laserMaze.h"

namespace lmclass
{
 laserMaze::laserMaze(const size_t ROWS, const size_t COLS)
 {
   assert(ROWS > 0);
   mCols = COLS;
   mRows = ROWS;
   if(mCols == 0)
    mCols = mRows;

   lmmPtr = new lmModule*[mRows * mCols];
   for (size_t i = 0; i < mRows * mCols; ++i)
	   lmmPtr[i] = new lmmPassThru;
 }

 laserMaze::~laserMaze()
 {
  for (size_t i = 0; i < mRows * mCols; ++i)
    delete lmmPtr[i];
  delete[] lmmPtr;
 }

 void laserMaze::set(const size_t R, const size_t C, lmModule* lmmIn)
 {
	 assert(R < mRows && C < mCols);
	 delete lmmPtr[R * mCols + C];
	 lmmPtr[R * mCols + C] = lmmIn;
 }

 lmModule& laserMaze::at(const size_t R, const size_t C)
 {
   assert(R < mRows && C < mCols);
   return *lmmPtr[R * mCols + C];
 }

 bool laserMaze::solved()
 {
   update();
   for (size_t i = 0; i < mRows * mCols; ++i)
   {
	   if (lmmPtr[i]->type() != "PassThru" && lmmPtr[i]->type() != "Laser" && !lmmPtr[i]->hit())
		   return false;
   }
   return true;
 }

 void laserMaze::update()
 {
	 bool tempArr[4];
	 for (size_t i = 0; i < mRows * mCols; ++i)
	 {
		 if (i < mCols)
			 tempArr[0] = false;
		 else
			tempArr[0] = lmmPtr[i - mCols]->out(2);

		 if (i % mCols == mCols - 1)
			 tempArr[1] = false;
		 else
			 tempArr[1] = lmmPtr[i + 1]->out(3);

		 if (i >= mCols * (mRows - 1))
			 tempArr[2] = false;
		 else
			 tempArr[2] = lmmPtr[i + mCols]->out(0);

		 if (i % mCols == 0)
			 tempArr[3] = false;
		 else
             tempArr[3] = lmmPtr[i - 1]->out(1);

		 if (lmmPtr[i]->set(tempArr))
			 i = -1;
	 }
 }

 bool laserMaze::checksHit()const
 {
	 for (size_t i = 0; i < mRows * mCols; ++i)
	 {
		 if (lmmPtr[i]->type() != "CheckPoint" && !lmmPtr[i]->hit())
			 return false;
	 }
	 return true;
 }

 bool laserMaze::targetsHit()const
 {
	 for (size_t i = 0; i < mRows * mCols; ++i)
	 {
		 if (lmmPtr[i]->type() == "Target" && !lmmPtr[i]->hit())
			 return false;
	 }
	 return true;
 }
}
