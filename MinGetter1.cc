#include "MinGetter1.h"
#include <algorithm>

bool MinGetter1::put(int value) {
  if (deduplication.find(value) == deduplication.end()) {
    deduplication.insert(value);
    values.push_back(value);
  }

  return true;
}

int MinGetter1::get_min_value() {
  if (values.empty()) {
    return -1;
  }
  int min = values.at(0);
  for (auto var : values) {
    if (var < min) {
      min = var;
    }
  }
  values.erase(remove(values.begin(), values.end(), min), values.end());
  return min;
}

int MinGetter1::size() {
  return values.size();
}

bool MinGetter1::clear() {
  MinGetterBase::clear();
  values.clear();
  return true;
}

string MinGetter1::describe() {
  return "unordered array";
}
