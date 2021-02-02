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
  Student();                       //构造函数,无参数
  Student(string);                 //构造函数,带一个参数
  void setStudent(string, myDate); //设置学生信息
  void setName(string);            //设置姓名
  string getName();                //获取姓名
  void setBirthday(myDate);        //设置生日
  myDate getBirthday();            //获取生日
  void printStudent() const;       //打印信息
  // Student(const Student &s);

private:
  string name;     //姓名
  myDate birthday; //生日
};

//定义构造函数
Student::Student() : name("NoName"), birthday(myDate()){};  //添加,不带参数
Student::Student(string n) : name(n), birthday(myDate()){}; //添加,带一个参数

//类体外定义成员函数
// Student::Student(const Student &s)
// {
//   name = "Copy" + s.name;
//   birthday = s.birthday;
// }
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
  Student stud;
  stud.printStudent();                           //输出默认值
  stud.setName("111");                           //姓名改为111
  stud.printStudent();                           //输出修改后的值 111
  Student *spointer[2] = {new Student(), &stud}; //初始化
  Student sy[2] = {Student(), stud};             //初始化 分配新的内存地址
  for (int i = 0; i < 2; i++)                    //使用指针输出指针指向的对象的值
    spointer[i]->printStudent();                 //姓名111
  for (int i = 0; i < 2; i++)                    //使用点运算符输出各值
    sy[i].printStudent();                        //姓名111
  stud.setName("222");                           //姓名222
  for (int i = 0; i < 2; i++)                    //sp[1]指向的对象的值改变
    spointer[i]->printStudent();                 //姓名222
  spointer[0]->setName("333");                   //影响student的值
  spointer[1]->setName("444");                   //影响stud的值
  for (int i = 0; i < 2; i++)                    //指向对象的值都改变
    spointer[i]->printStudent();                 // 姓名444
  stud.printStudent();                           //值变成 姓名444 生日1970
  for (int i = 0; i < 2; i++)
    sy[i].printStudent(); //值不变
  // 姓名NoName 生日1970
  // 姓名111 生日1970
  return 0;
}