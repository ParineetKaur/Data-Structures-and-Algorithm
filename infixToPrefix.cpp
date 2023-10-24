// Question: Convert an infix expression to a prefix expression using a stack-based algorithm. 

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

//check if character is operand or not
bool checkOperand(char ch){
  if((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z')){//making sure that even when the user enters an upper case, the program detects it
    return 1;//true
  }
  else{
    return 0;//false
  }
}

bool checkOperator(char ch){
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
    return 1;
  }
  else{
    return 0;
  }
}

int checkPrecedence(char ch){
  if(ch == '^'){
    return 3;
  }
  else if(ch == '/' || ch == '*'){
    return 2;
  }
  if(ch == '-' || ch == '+'){
    return 1;
  }
  else{
    return -1;
  }
}

string infixToPrefix(stack<char> st, string i){
  string p;
  //reverse
  reverse(i.begin(),i.end());
  //flip the brackets
  for(int j = 0; j < i.length();j++){
    if(i[j] == '('){
      i[j]=')';
    }
    else if(i[j] == ')'){
      i[j]='(';
    }
  }
  for(int j = 0; j < i.length();j++){
  //operands
  if(checkOperand(i[j])){
    p += i[j];
  }
  //brackets
  else if(i[j]=='('){
    st.push(i[j]);
  }
  else if(i[j]==')'){
    while((st.top()!='(') && (!st.empty())){
      p+=st.top();
      st.pop();
    }
    //we do not need the opening bracket in prefix expression
    if(st.top()=='('){
      st.pop();
    }
  }
  //operators
  else if(checkOperator(i[j])){
    //check if stack is empty
    if(st.empty()){
      st.push(i[j]);
    }
    //if not empty
    else{
      //check precedence
      if(checkPrecedence(i[j]>checkPrecedence(st.top()))){
        st.push(i[j]);
      }
      else if((checkPrecedence(i[j])==checkPrecedence(st.top()))&&(i[j]=='^')){
        while((checkPrecedence(i[j])==checkPrecedence(st.top()))&&(i[j]=='^')){
          p+=st.top();
          st.pop();
        }
        st.push(i[j]);
      }
      //some operators have the same precedence, so we want that to work from left to right
      else if(checkPrecedence(i[j])==checkPrecedence(st.top())){
        st.push(i[j]);
      }
      else if(checkPrecedence(i[j])<checkPrecedence(st.top())){
        st.push(i[j]);
      }
    }
  }
}
//if some elements are left
while(!st.empty()){
  p+=st.top();
  st.pop();
}
reverse(p.begin(),p.end());
return p;
}


int main(){
  char repeat;
  string infix, prefix;
  cout << "Would you like to begin the process? Enter 'y' for yes and 'n' for no: ";
  cin >> repeat;
  while(repeat=='y'){
    cout << "Enter a 'infix' expression: ";
    cin >> infix;
    stack<char> st;
    cout << "The 'infix' expression you entered was: " << infix << endl;
    cout << "We will now provide the 'prefix' expression... " << endl;
    prefix = infixToPrefix(st, infix);
    cout << "The 'prefix' expression is: " << prefix << endl;
    cout << "Would you like to continue the process? Enter 'y' for yes and 'n' for no: ";
    cin >> repeat;
  }
  if(repeat=='n'){
    cout << "Ending program now..." << endl;
    exit(1);
  }
  return 0;
}
