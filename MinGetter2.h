#ifndef MINGETTER2_H
#define MINGETTER2_H

#include "MinGetterBase.h"
#include <vector>
using namespace std;

class MinGetter2 : public MinGetterBase {

public:
  MinGetter2() {
    values.clear();
  }
  ~MinGetter2() {
    values.clear();
  }
  virtual int get_min_value();
  virtual bool put(int);
  virtual int size();
  virtual bool clear();
  virtual string describe();
private:
  vector<int> values;

};


#endif
