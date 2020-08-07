#include <iostream>
#include <vector>

#include "CopyList.h"
#include "IndirectList.h"

void testCopyList() {
  auto list = CopyList<int>();
  auto vec = std::vector<int>();
  for (int i = 0; i < 1024; i++) {
    list.add(i * i);
    vec.push_back(i * i);
  }
  for (int i = 0; i < list.size(); i++) {
    if (list[i] != vec[i]) {
      std::cout << "Error" << std::endl;
    }
  }
}

void testIndirectList() {
  auto list = IndirectList<int>();
  auto vec = std::vector<int>();
  for (int i = 0; i < 1024; i++) {
    list.add(i * i);
    vec.push_back(i * i);
  }
  for (int i = 0; i < list.size(); i++) {
    if (list[i] != vec[i]) {
      std::cout << "Error" << std::endl;
    }
  }
}

int main() {
  testCopyList();
  testIndirectList();
  return 0;
}
