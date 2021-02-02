#include <iostream>
#include <string>
using namespace std;
class employee //基类
{
  short age;
  float salary;

protected:
  string name;

public:
  employee(short ag, float sa, string na)
  {
    age = ag;
    salary = sa;
    name = na;
  };
  void print()
  {
    cout << "\n"
         << name << ":\t";
    cout << age << ":\t";
    cout << salary;
  };
  ~employee() {}
};
class manager : public employee //派生类
{
  int level;

public:
  manager(short ag, float sa, string na, int lev) : employee(ag, sa, na) //初始化基类
  {
    level = lev;
  }
  void print()
  {
    employee::print();
    cout << "\tlevel:" << level;
  }
};
class engineer : public employee //
{
  char speciality, adegree;

public:
  engineer(short ag, float sa, string na, char spe, char ade) : employee(ag, sa, na) //初始化基类
  {
    speciality = spe;
    adegree = ade;
  }
  void print()
  {
    employee::print();
    cout << "\tspeciality:" << speciality;
    cout << "\tadegree:" << adegree;
  }
};
enum ptitle
{
  PS,
  GM,
  VPS,
  VGM
};
class director : public manager
{
  ptitle post;

public:
  director(short ag, float sa, string na, int le, ptitle po) : manager(ag, sa, na, le) //初始化基类
  {
    post = po;
  }
  void print()
  {
    manager::print();
    cout << "\tpost:" << post << endl;
  }
};
int main()
{
  employee emp1(23, 610.5, "wang"), emp2(27, 824.75, "li");
  manager man1(32, 812.45, "zhang", 11), man2(34, 1200.5, "chen", 7);
  engineer eng(26, 1420.10, "sun", 'E', 'M');
  director dir(38, 1800.2, "liu", 2, VPS);
  emp1.print();
  emp2.print();
  man1.print();
  man2.employee::print();
  eng.print();
  dir.print();
  return 0;
}