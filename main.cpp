#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void quickSort(std::vector<char>::iterator begin, std::vector<char>::iterator end) {
  if(begin==end) {
    return;
  }
  std::vector<char>::iterator pivot, min, max;
  pivot = begin + std::distance(begin, end) / 2;
  std::iter_swap(pivot, end-1);
  pivot = end-1;
  min = begin;
  max = end - 1;
  while(min!=max) {
    if(*min<*pivot) {
      min++;
    } else if(*max>=*pivot) {
      max--;
    } else {
      std::iter_swap(min, max);
    }
  }
  std::iter_swap(max, pivot);
  pivot = max;
  if(std::distance(begin,end)>2) {
    quickSort(begin,pivot+1);
    quickSort(pivot+1,end);
  }
}

int main(int argc, char *argv[]) {
  if(argc!=2) {
    std::cout << "Usage: " << argv[0] << " <characters to be sorted>" << std::endl;
    return 0;
  }
  std::string input = argv[1];
  std::vector<char> toSort{input.begin(), input.end()};
  quickSort(toSort.begin(), toSort.end());
  std::cout << "Final: ";
  for(char c : toSort) {
    std::cout << c;
  }
  std::cout << std::endl;
}
