#include "MinGetter3.h"
#include <algorithm>

int MinGetter3::size() {
  return values.size();
}

bool MinGetter3::put(int value) {
  if (deduplication.find(value) == deduplication.end()) {
    deduplication.insert(value);
    values.push_back(value);
    push_heap(values.begin(), values.end(), greater<int>());
  }
  return true;
}

int MinGetter3::get_min_value() {
  if (values.empty()) {
    return -1;
  }

  int min = values.at(0);
  pop_heap(values.begin(), values.end(), greater<int>());
  values.pop_back();
  deduplication.erase(min);

  return min;
}

bool MinGetter3::clear() {
  MinGetterBase::clear();
  values.clear();
  return true;
}

string MinGetter3::describe() {
  return "Minimum heap";
}
