//Question 3 from HW07
//Code Execution image is in Part3_execution
#include <iostream>
using namespace std;

void insertionSort(int arr[], int elementCount){
  int val, index;
  for(int i = 1; i < elementCount; i++){
    val = arr[i];
    index = i;
    while(index > 0 && arr[index -1] > val){
      arr[index] = arr[index -1];
      index = index - 1;
    }
    arr[index] = val;
  }
}

int main(){
  const int SIZE = 10;
  int a[SIZE];
  for(int i = 0; i < SIZE; i++){
    cin >> a[i];
  }
  insertionSort(a,SIZE);
  for(int j = 0; j < SIZE; j++){
    cout << a[j] << " ";
  }
  cout << endl;
  return 0;
}
