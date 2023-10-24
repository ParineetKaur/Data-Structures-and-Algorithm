//Part 2 of HW09

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <queue>
using namespace std;

class graph{
public:
  graph();
  int i();
  void add_vertex(int a, int b){
    _v.push_back(std::list<int>());
  }
  void add_edge(int a, int b){
    assert(a < i() && b < i());
    if (!is_edge(a, b)){
      _v[a].push_front(b);
      _v[b].push_front(a);
    }
  }
  bool is_edge(int a, int b){
    if(a >= i() || b >= i()){
      return false;
    }
    for(auto e: _v[a]){
      if (e == b){
        return true;
      }
      return false;
    }
  }
  list<int> shortest_path(int start, int end){
      vector<int> parent(i(),-1);
      bfs(start,parent);
      if(parent[end] == -1){
        cout << "No Answer Found" << endl;
        return list<int>();
      }
    }
private:
  void bfs(int start, vector<int> & parent){
    queue<int> q;
    parent[start] = start;
    q.push(start);
    while(!q.empty()){
      int f = q.front();
      q.pop();
      for(auto e: _v[f]){
        if (parent[e] == -1){
          parent[e] = f;
          q.push(e);
        }
      }
    }
  }
  vector<list<int>>_v;
};

class doubletPuzzle{
public:
  doubletPuzzle();
  void buildDictionary(string dictionary);
  void solve(string firstWord, string lastWord);
private:
  graph newGraphWord;
  vector<string> dictionary;
  int converge(string firstWord, string nextWord);
};

void doubletPuzzle::buildDictionary(string dictionary){
  ifstream inFile(dictionary);
  string line;
  cout << "Building a Dictionary..." << endl;
  while(getline(inFile,line)){
    if(line.length() != 0){
      graph.add_vertex();
      dictionary.push_back(line);
    }
  }
  inFile.close();
  for(int j = 0; j < dictionary.size(); j++){
    string firstWord = dictionary[j];
    for(int i = 0; i < dictionary.size(); i++){
      string secondWord = dictionary[i];
      if(converge(firstWord, secondWord) == 4){
        graph.add_edge(j,i);
      }
    }
  }
}

void doubletPuzzle::solve(string firstWord, string lastWord){
  int firstIndex;
  int secondIndex;
  for(int j = 0; j < dictionary.size(); j++){
    if(firstWord == dictionary[j]){
      firstIndex = j;
    }
  }
  for(int i = 0; i < dictionary.size(); i++){
    if(lastWord == dictionary[i]){
      secondIndex = i;
    }
  }
  cout << firstWord << "->" << lastWord << endl;
  list<int> a = graph.shortest_path(firstIndex, secondIndex);
  list<int>::iterator iter;
  for(iter = a.begin(); iter != a.end(); iter++){
    cout << dictionary[*iter] << " ";
  }
  cout << endl;
}

int main(){
  doubletPuzzle p1;
  p1.buildDictionary("dictionary.txt");
  p1.solve("black", "white");
  p1.solve("tears", "smile");
  p1.solve("small", "giant");
  p1.solve("stone", "money");
  p1.solve("angel", "devil");
  p1.solve("amino", "right");
  p1.solve("amigo", "signs");
  return 0;
}
