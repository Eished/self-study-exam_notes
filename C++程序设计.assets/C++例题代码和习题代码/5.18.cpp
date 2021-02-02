#include <iostream>
using namespace std;
class Base
{
public:
  Base() {}
  Base(Base &c)
  {
    cout << "Base 复制构造函数" << endl;
  }
  Base operator=(const Base &b)
  {
    cout << "Base::operator=" << endl;
    return *this;
  }
};
class Derived : public Base
{
public:
  Derived()
  {
    cout << "Derived::构造函数" << endl;
  }
};

int main()
{
  Derived d1, d2;
  Derived d3(d1); // d3 初始化过程中会调用类 Base 的复制构造函数
  d2 = d1;        // 会调用类 Base 的重载运算符“=”运算符
  return 0;
}