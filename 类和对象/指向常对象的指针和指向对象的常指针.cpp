#include <iostream>
#include<string>
#include<iomanip>
using namespace std;
class Student
{
public:
	Student(int n, float s) :num(n), score(s) {};
     void change(int n, float s)const { num = n; score = s; }
	 void display() const{ cout << num << " " << score << endl; }

private:
	mutable int num;
	mutable float score;
};

int main()
{
	 const Student stud(101, 78.5);
	 const Student* p = &stud;
	 //	  Student stud(101, 78.5);
	// Student* const p = &stud;
	 p->display();
	 p->change(101, 80.5);
	 p->display();
	system("pause");
	return 0;
}
