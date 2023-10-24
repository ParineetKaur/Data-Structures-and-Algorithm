//Question 4 from HW07
#include <iostream>
using namespace std;
// Library facilities used: itemtool.h, stdlib.h
//
// NOTES FROM THE IMPLEMENTOR:
// How the partition works on small arrays:
//
// Notice that n=0 is not permitted by the precondition.
//
// If n=1, then too_big_index is initialized as 1, and too_small_index is
// initialized as 0. Therefore, the body of the loop is never executed,
// and after the loop pivot_index is set to zero.
//
// If n=2, then both too_big_index and too_small_index are initialized as 1.
// The loop is entered, and there are two cases to consider:
// -- if data[1] <= pivot, then too_big_index increases to 2, and
//    too_small_index stays at 1. The if-statement at the bottom of the loop
//    is then skipped, and after the loop we copy data[1] down to data[0],
//    and copy the pivot into data[0]. Thus, the smaller element is in
//    data[0], and the larger element (the pivot) is in data[1].
// -- if data[1] > pivot, then too_big_index stays at 1, and too_small_index
//    decreases to 0. The if-statement at the bottom of the loop is then
//    skipped, and after the loop we end up copying the pivot onto data[0]
//    (leaving data[1] alone). Thus, the smaller element (the pivot) remains
//    at data[0], leaving the larger element at data[1].
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
