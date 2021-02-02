#include <iostream>
using namespace std;
class CB
{

public:
  int a;
  CB(int x)
  {
    a = x;
  }
  void showa()
  {
    cout << "Class Cb--a=" << a << endl;
  }
};
class CD : public CB
{
public:
  int a;                   //与基类同名
  CD(int x, int y) : CB(x) //x 初始化基类的成员变量a
  {
    a = y;
  }
  void showa() //基类同名函数
  {
    cout << "Class CD--a" << a << endl;
  }
  void print2a()
  {
    cout << "a=" << a << endl;         //访问派生类a
    cout << "CB::a=" << CB::a << endl; //访问基类a
  }
};
int main()
{
  CB CBobj(12);
  CBobj.showa();
  CD CDobj(48, 999);
  CDobj.showa();     //访问派生类的showa()
  CDobj.CB::showa(); //访问基类的showa()
  cout << "CDobj.a" << CDobj.a << endl;
  cout << "CDobj.CB::a=" << CDobj.CB::a << endl;
  return 0;
}