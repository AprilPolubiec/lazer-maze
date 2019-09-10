#pragma once
#include "lmModule.h"
#include "lmmPassThru.h"
#include <cassert>

namespace lmclass
{
  class laserMaze
  {
    public:
      laserMaze(const size_t ROWS=5, const size_t COLS=0);
      ~laserMaze();
	  void set(const size_t R, const size_t C, lmModule* lmmIn);
      lmModule& at(const size_t R, const size_t C);
	  void update();
	  bool checksHit()const;
	  bool targetsHit()const;
	  bool solved();
    protected:
	  lmModule** lmmPtr;
      size_t mRows;
      size_t mCols;
  };
}
