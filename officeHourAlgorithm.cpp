// Question: Simulate students arriving for a professor's office hours, track their wait times, meeting durations, and calculate the professor's overtime

#include <iostream>
#include <thread>
#include <chrono>
#include <time.h>
#include <queue>
using namespace std;

class Student{
public:
  Student(){
    studentArrival = rand() % 60;
    meetingDuration = 0;
    }
  //setters
  void setArrival(int arrival);
  void setStartTime(int begin);
  void setDuration(int duration);
  //getters
  int getArrival();
  int getStartTime();
  int getDuration();
  //random student arrival method
  void randomArrival(queue<Student *> & student);
  //student wait time
  int studentWaitTime();
  //meeting duration should also have a function so that time spent on one student can be recorded
  void officeHours(queue<Student *> student);
  //Here, the averager is being used as a method to keep track of the average wait time and students in queue, etc.
  void averager(queue<Student *> student, int& studentCount, int& totalStudentWait, int& meetingTotals, int& professorOverTime);
private:
  int studentArrival;//variable to see when student arrives
  int meetingBegins;//variable to see when student begins meeting with the Proffesor
  int meetingDuration;//variable to check how much time was given for each student's meeting
};

void Student::setArrival(int arrival){
  studentArrival = arrival;
}

void Student::setStartTime(int begin){
  meetingBegins = begin;
}

void Student::setDuration(int duration){
  meetingDuration = duration;
}

int Student::getArrival(){
  return studentArrival;
}
int Student::getStartTime(){
  return meetingBegins;
}
int Student::getDuration(){
  return meetingDuration;
}

void Student::randomArrival(queue<Student *> & student){
  int studentArrivalTime = 0;
  srand(time(0));
  do{
    int newTime = rand() % 60;
    studentArrivalTime += newTime;
    if(studentArrivalTime < 60){
      student.push(new Student());
    }
  }while (studentArrivalTime < 60);
}

int Student::studentWaitTime(){
  if(meetingBegins >= studentArrival){
    return (meetingBegins - studentArrival);
  }
  return 0;
}

void Student::officeHours(queue<Student *> student){
  int current = 0;
  int studentArrivalTime;
  int meetingDuration;
  while(student.empty() == false){
    Student* s = student.front();
    studentArrivalTime = s->getArrival();
    if(studentArrivalTime > current){
      this_thread::sleep_for(chrono::seconds(studentArrivalTime - current));
      current = studentArrivalTime;
    }
    meetingDuration = rand() % 60;
    s->setStartTime(current);
    s->setDuration(meetingDuration);
    this_thread::sleep_for(chrono::seconds(meetingDuration));
    current += meetingDuration;
    student.pop();
  }
}

void Student::averager(queue<Student *> student, int& studentCount, int& totalStudentWait, int& meetingTotals, int& professorOverTime){
  while(student.empty() == false){
    Student* studentAttendance = student.front();
    student.pop() ;
    studentCount++;
    totalStudentWait += studentAttendance->studentWaitTime();
    meetingTotals += studentAttendance->getDuration();
    int meetingEndTime = studentAttendance->getStartTime() + studentAttendance->getDuration();
    if(meetingEndTime > 60){
      professorOverTime += (meetingEndTime - 60);
    }
  }
}

int main(){
  Student officeHours;
  queue<Student *> studentLine;
  int studentCount = 0;
  int totalStudentWait = 0;
  int meetingDurationTotal = 0;
  int professorExceedsTime = 0;
  for(int i = 0; i < 100; i++){
    officeHours.randomArrival(studentLine);
    officeHours.officeHours(studentLine);
    officeHours.averager(studentLine, studentCount, totalStudentWait, meetingDurationTotal, professorExceedsTime);
  }
  cout << "Average Student Wait Time: " << (totalStudentWait * 1.0) / studentCount << endl;
  cout << "______________________________________________________________________________________" << endl;
  cout << "Average student time spent with Professor during office hours: " << (meetingDurationTotal * 1.0) / studentCount << endl;
  cout << "______________________________________________________________________________________" << endl;
  cout << "verage time a Professor spends at an office hour beyond the allotted 1 hour: " << (professorExceedsTime * 1.0) / 100 << endl;
  return 0;
}
