//Question 2 Code from HW03
//Write a C++ function that takes in an arithmetic expression in prefix notation and converts it into a binary tree, such that each operation is stored in a node whose left subtree stores the left operand, and whose right subtree stores the right operand.

#include <iostream>
using namespace std;

class node{
public:
  node* l;
  node* r;
  char value;
  node(char val){
    value = val;
    l = NULL;
    r = NULL;
  }
};

void inOrder(node* root){
  if(root == NULL){
    return;
  }
  inOrder(root->l);
  cout << root->value << " ";
  inOrder(root->r);
}

bool checkOperator(char ch){
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
    return 1;//true
  }
  else{
    return 0;//false
  }
}

int convertToTree(node** root, string prefix, int position = 0){
  if(position == prefix.size()){
    return position;
  }
  while(1){
    int temp;
    if(*root == NULL){
      node* newNode = new node(prefix[position]);
      *root = newNode;
    }
    else{
      if(!checkOperator(prefix[position])){
        return position;
      }
      //recursion
      //left subtree
      temp = convertToTree(&(*root)->l,prefix,position+1);
      //right subtree
      temp = convertToTree(&(*root)->r,prefix,position+1);
      return position;
    }
  }
}

int main(){
  string prefix;
  char repeat;
  node* root = NULL;
  cout << "Would you like to begin the program? Enter 'y' for yes and 'n' for no: ";
  cin >> repeat;
  while(repeat=='y'){
    cout << "Enter a 'prefix' expression: ";
    cin >> prefix;
    cout << "Processing..." << endl;
    convertToTree(&root,prefix);
    cout << "Binary Tree created: ";
    inOrder(root);
    cout << endl;
    cout << "Would you like to continue? Enter 'y' for yes and 'n' for no: ";
    cin >> repeat;
  }
  if(repeat=='n'){
    cout << "Ending program now..." << endl;
    exit(1);
  }
  return 0;
}
