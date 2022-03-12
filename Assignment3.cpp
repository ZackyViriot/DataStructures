#include <iostream>
using namespace std;

class Student
{
public:
    Student(const string &n = "", float g = 0, int s = 0); // conststructor

    // Getter and setter functions
    string getName() const;
    float getGpa() const;
    int getSemester() const;

private: // member variables
    string name;
    float gpa;
    int semester;
};
Student::Student(const string &n, float g, int s)
    : name(n), gpa(g), semester(s) {}
string Student::getName() const {return name;}
float Student::getGpa() const {return gpa;}
int Student::getSemester() const {return semester;}


class GameEntry : public Student
{
public:
    GameEntry(const string &sn = "", int s = 0);
    int getScore() const;
    string getSportName() const;

    // friend function 
    friend string compare(GameEntry s1,GameEntry s2);
    friend int isDiv10(int num);
    friend bool isPerfect(int n);
    friend int posFunction(int score);

private:
    int score;
    string sportName;
};
GameEntry::GameEntry(const string &sn,int s)
    : sportName(sn),score(s){}
string GameEntry::getSportName()const { return sportName;}
int GameEntry::getScore() const {return score;}

std::ostream &operator<<(ostream &out, const GameEntry &obj)
{
}

// friend compare function
string compare(GameEntry s1, GameEntry s2)
{
    if ((s1.getGpa()) && (s1.getScore()) > ((s2.getGpa()) && (s2.getScore()))){
        return "congrats player 1 you have won";
    }else if ((s2.getGpa()) && (s2.getScore()) > ((s1.getGpa()) && (s1.getScore()))){
        return "congrats player 2 you have won";
    }else {
        return "congrats yall are the same so there will be no winner";
    }
}
// perfect number function 
// these are the function used for perfect number  
int isDiv10(int num) {
  if (num % 10 == 0) {
    return true;

  } else {
    return false;
  }
}

bool isPerfect(int n) {
  int i = 1, sum = 0;
  for (i = 1; i < n; i++) {
    if (n % i == 0) {
      sum = sum + 1;
    }
  }
  if (n == sum) {
    return true;
  } else {
    return false;
  }
}

int posFunction(int score) {
  if (isPerfect(score)) {
    if (isDiv10(score)) {
      return score + 17;
    } else {
      return score + 15;
    }
  } else {
    if (isDiv10(score)) {
      return score + 2;
    } else {
      return score;
    }
  }
}
int main(){
    GameEntry s1,s2;


    return 0;

}
