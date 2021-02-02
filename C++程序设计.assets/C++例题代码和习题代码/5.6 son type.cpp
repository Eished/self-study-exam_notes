#include <iostream>
#include <string>
using namespace std;
class CStudent //基类
{
private:
  string name; //姓名
  string id;   //学号
  char gender; //性别,'F'代表女生, 'M'代表男生
  int age;     //年龄
public:
  void PrintInfo();
  void SetInfo(const string &, const string &, int, char);
  void SetName(string);
  string GetName();
  void SetId(string);
  string GetId();
};
void CStudent::PrintInfo()
{
  cout << "姓名:\t" << name << endl;
  cout << "学号:\t" << id << endl;
  cout << "年龄:\t" << age << endl;
  cout << "性别:\t" << gender << endl;
}
void CStudent::SetInfo(const string &name_, const string &id_, int age_, char gender_)
{
  name = name_;
  id = id_;
  age = age_;
  gender = gender_;
}
void CStudent::SetName(string name)
{
  this->name = name;
}
string CStudent::GetName()
{
  return name;
}
void CStudent::SetId(string id)
{
  this->id = id;
}
string CStudent::GetId()
{
  return id;
}

class CUndergraduateStudent : public CStudent //本科生类, 继承于类 CStudent
{
private:
  string department; //学生所属的系名

public:
  void PrintInfo();
  void SetInfo(const string &, const string &, int, char, const string &);
};
void CUndergraduateStudent::PrintInfo()
{
  CStudent::PrintInfo();
  cout << "院系:\t" << department << endl
       << endl;
}
void CUndergraduateStudent::SetInfo(const string &name_, const string &id_, int age_, char gender_, const string &department_)
{
  CStudent::SetInfo(name_, id_, age_, gender_);
  department = department_;
}

class CGraduatedStudent : public CStudent //研究生类
{
private:
  string department; //学生所属的系名
  string advisor;    //导师
public:
  void PrintInfo();
  void SetInfo(const string &name_, const string &id_, int age_, char gender_, const string &department_, const string &advisor_);
};
void CGraduatedStudent::PrintInfo()
{
  CStudent::PrintInfo();
  cout << "院系:\t" << department << endl;
  cout << "导师:\t" << advisor << endl;
}
void CGraduatedStudent::SetInfo(const string &name_, const string &id_, int age_, char gender_, const string &department_, const string &advisor_)
{
  CStudent::SetInfo(name_, id_, age_, gender_);
  department = department_;
  advisor = advisor_;
}
int main()
{
  CStudent s1;              //基类对象
  CUndergraduateStudent s2; //派生类对象
  CGraduatedStudent s3;     //派生类对象
  s2.SetInfo("张三", "2020-6-2-4", 19, 'M', "数学系");
  s3.SetInfo("李四", "M2021-12", 19, 'F', "计算机系", "罗教授");
  s2.PrintInfo();                                    //调用派生类函数
  s3.PrintInfo();                                    //调用派生类函数
  cout << s2.GetName() << endl;                      //通过基类公有成员函数访问
  s2.SetName("张二");                                //基类公有成员函数
  s2.PrintInfo();                                    //派生类公有成员函数
  cout << s2.GetName() << "," << s2.GetId() << endl; //基类公有成员函数
  return 0;
}