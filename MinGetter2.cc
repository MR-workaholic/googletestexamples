#include "MinGetter2.h"


bool MinGetter2::put(int value) {
  if (deduplication.find(value) == deduplication.end()) {
    deduplication.insert(value);
    for (auto pos = values.begin(); pos != values.end(); ++pos) {
      if (*pos > value) {
        values.insert(pos, value);
        return true;
      }else if (*pos == value) {
        return true;
      }
    }
    values.insert(values.end(), value);
  }
  return true;
}

int MinGetter2::get_min_value() {
  if (values.empty()) {
    return -1;
  }
  int min = *(values.begin());
  values.erase(values.begin());
  return min;
}

int MinGetter2::size() {
  return values.size();
}

bool MinGetter2::clear() {
  MinGetterBase::clear();
  values.clear();
  return true;
}

string MinGetter2::describe() {
  return "ordered array";
}
