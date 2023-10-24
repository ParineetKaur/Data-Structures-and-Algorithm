//Question 1 Code

#include <iostream>
using namespace std;

void heapify(int* BinaryTree, int size, int i){
  int greatest = i;
  int left = 2*i; 
  int right = (2*i)+1;
  if(left <= size && BinaryTree[left] > BinaryTree[greatest]){//check for overflow
    greatest = left;
  }
  if(right <= size && BinaryTree[right] > BinaryTree[greatest]){
    greatest = right;
  }
  if(greatest != i){
    swap(BinaryTree, i, greatest);
    heapify(BinaryTree,size,greatest);
  }
}
