#ifndef MINGETTER1_H
#define MINGETTER1_H

#include "MinGetterBase.h"
#include <vector>
using namespace std;

class MinGetter1 : public MinGetterBase {

public:
  MinGetter1() {
    values.clear();
  }
  ~MinGetter1() {
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
