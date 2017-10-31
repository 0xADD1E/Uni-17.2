#include "PFAString.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

PFAString::PFAString() {
  capacity = 0;
  arr = new std::string[capacity];
  size = 0;
}
PFAString::PFAString(const int requestedCapacity) {
  capacity = requestedCapacity;
  arr = new std::string[capacity];
  size = 0;
}
PFAString::PFAString(const int requestedCapacity, const std::string fillWith) {
  capacity = requestedCapacity;
  arr = new std::string[capacity];
  size = capacity;
  for (int i = 0; i < capacity; i++) {
    arr[i] = fillWith;
  }
}
PFAString::PFAString(const PFAString &copy) {
  capacity = copy.size;
  arr = new std::string[capacity];
  size = copy.size;
  for (int i = 0; i < size; i++) {
    arr[i] = copy[i];
  }
}
PFAString::~PFAString() { delete[] arr; }

int PFAString::get_capacity() { return capacity; }
int PFAString::get_size() { return size; }

void PFAString::push_back(std::string insert) {
  if (capacity < size + 1) {
    if (capacity == 0) {
      resize(1);
    } else {
      resize(2 * capacity);
    }
  }
  arr[size] = insert;
  size++;
}
void PFAString::pop_back() { size--; }
void PFAString::resize(int newCapacity) {
  if (newCapacity < 0) {
    resize(0);
    return;
  }

  if (newCapacity < capacity) {
    size = newCapacity;
    return;
  }

  std::string *new_arr = new std::string[newCapacity];
  for (int i = 0; i < newCapacity && i < capacity; i++) {
    new_arr[i] = arr[i];
  }

  delete[] arr;
  arr = new_arr;
  size = min(size, newCapacity);
  capacity = newCapacity;
}
void PFAString::resize(int newCapacity, std::string fillWith) {
  resize(newCapacity);
  for (int i = size; i < newCapacity; i++) {
    arr[i] = fillWith;
  }
  size = newCapacity;
}
void PFAString::empty_array() { size = 0; }
std::string &PFAString::operator[](const int index) const {
  if (index < 0 || index > size) {
    exit(1);
  }
  return arr[index];
}
PFAString PFAString::operator=(const PFAString copy) {
  capacity = copy.size;
  arr = new std::string[capacity];
  size = copy.size;
  for (int i = 0; i < size; i++) {
    arr[i] = copy[i];
  }
  return *this;
}
bool PFAString::operator==(const PFAString compareTo) const {
  return !(*this < compareTo || compareTo < *this);
}
bool PFAString::operator<(const PFAString compareTo) const {
  int minLength = min(size, compareTo.size);
  for (int i = 0; i < minLength; i++) {
    if (arr[i] != compareTo[i]) {
      return arr[i] < compareTo[i];
    }
  }
  return size < compareTo.size;
}
bool PFAString::operator>(const PFAString compareTo) const {
  return compareTo < *this;
}
bool PFAString::operator<=(const PFAString compareTo) const {
  return !(compareTo < *this);
}
bool PFAString::operator>=(const PFAString compareTo) const {
  return !(*this < compareTo);
}
