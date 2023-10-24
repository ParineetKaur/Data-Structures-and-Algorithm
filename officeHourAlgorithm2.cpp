Question: Generate random student names and topics for a Q&A session and associate students with their questions and topics

#include <iostream>
#include <vector>
#include <map>
using namespace std;

string generateTopic(){
  vector<string>studentTopics{"Searching Algorithms", "Operator Overloading", "Programming Basics", "Selection Sort", "Heaps", "Sorting", "Binary Trees", "Multimaps", "Quick Sort", "Recursion"};
  string topic = studentTopics[rand() % 10];
  return topic;
}

int main(){
  srand(time(0));
  string topic
  int studentCount = rand() % 40;
  vector<string>studentNames{"Laila","Maya","Lora","Kyle","John","Melody","Sana"};
  multimap<string,string> studentLine;//two strings: one for student and other for topic
  for(int i = 0; i <= 100; i++){
    int questionCount = rand() % studentCount;
    for(int l = 0; l < questionCount; l++){
      string questionComesFrom = studentNames[rand() % studentCount];
      topic = generateTopic();
      studentLine.insert(questionComesFrom, topic);
    }
   }

   for(int j = 0; j < studentCount; j++){
     string name = studentNames[j];
     cout << name << "->" << endl;
     cout << "-----------------------------" << endl;
     cout << topic << endl;
     }
     return 0;
   }
