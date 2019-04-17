#ifndef MINGETTERBASE_H
#define MINGETTERBASE_H
#include <unordered_set>
#include <string>

using namespace std;

class MinGetterBase {

public:

  MinGetterBase(){
    deduplication.clear();
  };
  ~MinGetterBase() {
    deduplication.clear();
  };

  virtual int get_min_value() = 0;
  virtual bool put(int) = 0;
  virtual int size() = 0;
  virtual bool clear() = 0;
  virtual string describe() = 0;

protected:
  unordered_set<int> deduplication;

};



#endif
