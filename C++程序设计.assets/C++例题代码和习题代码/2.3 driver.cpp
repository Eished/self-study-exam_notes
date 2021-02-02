#include <iostream>
#include <string>
using namespace std;
class myDate
{
public:
  myDate();                    //构造函数
  myDate(int, int, int);       //构造函数
  void setDate(int, int, int); //设置日期
  void setDate(myDate);        //设置日期
  myDate getDate();            //获取日期
  void setYear(int);           //设置年
  int getMonth();              //获取月
  void printDate() const;      //打印日期

private:
  int year, month, day; //成员变量,年月日
};
//类体外定义成员函数
myDate::myDate()
{
  year = 1970, month = 1, day = 1;
}
myDate::myDate(int y, int m, int d)
{
  year = y;
  month = m;
  day = d;
}
void myDate::setDate(int y, int m, int d)
{
  year = y;
  month = m;
  day = d;
  return;
}
void myDate::setDate(myDate oneD)
{
  year = oneD.year;
  month = oneD.month;
  day = oneD.day;
  return;
}
myDate myDate::getDate()
{
  return *this;
}
void myDate::setYear(int y)
{
  year = y;
  return;
}
int myDate::getMonth()
{
  return month;
}

void myDate::printDate() const
{
  cout << year << "/" << month << "/" << day;
  return;
}
class Student
{
public:
  void setStudent(string, myDate); //设置学生信息
  void setName(string);            //设置姓名
  string getName();                //获取姓名
  void setBirthday(myDate);        //设置生日
  myDate getBirthday();            //获取生日
  void printStudent() const;       //打印信息

private:
  string name;     //姓名
  myDate birthday; //生日
};
//类体外定义成员函数
void Student::setStudent(string s, myDate d)
{
  name = s;
  birthday.setDate(d);
  return;
}
void Student::setName(string n)
{
  name = n;
  return;
}
string Student::getName()
{
  return name;
}
void Student::setBirthday(myDate d)
{
  birthday.setDate(d);
  return;
}
myDate Student::getBirthday()
{
  return birthday;
}
void Student::printStudent() const
{
  cout << "姓名:" << name << "\t生日:";
  birthday.printDate(); //调用类myDate 的成员函数
  cout << endl;
}
int main()
{
  Student ss;
  int y, m, d;
  string name_;
  cout << "请输入学生的姓名和生日, 生日以\"年 月 日\"的次序输入:";
  cin >> name_ >> y >> m >> d;
  ss.setStudent(name_, myDate(y, m, d));
  ss.printStudent();
  return 0;
}