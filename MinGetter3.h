#ifndef MINGETTER3_H
#define MINGETTER3_H

#include "MinGetterBase.h"
#include <vector>
using namespace std;

class MinGetter3 : public MinGetterBase {

public:
  MinGetter3() {
    values.clear();
  }
  ~MinGetter3() {
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
