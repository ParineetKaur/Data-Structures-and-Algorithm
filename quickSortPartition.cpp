// Question: Implement partition in the Quicksort algorithm to rearrange an array of integers around a pivot element.

#include <iostream>
using namespace std;

void partition(int data[], size_t n, size_t& pivot_index){
  if(n > 1){
    int pivotElement = data[0];
    int too_big_index = 1;
    int too_small_index = n -1;
    while(too_big_index <= too_small_index){
      while(too_big_index < n && data[too_big_index] < pivotElement){
        too_big_index++;
      }
      while(data[too_small_index] > pivotElement){
        too_small_index--;
      }
      if(too_big_index < too_small_index){
        int t = data[too_big_index];
        data[too_big_index] = data[too_small_index];
        data[too_small_index] = t;
      }
    }
      pivot_index = too_small_index;
      data[0] = data[pivot_index];
      data[pivot_index] = pivot_Element;
    }
  }
