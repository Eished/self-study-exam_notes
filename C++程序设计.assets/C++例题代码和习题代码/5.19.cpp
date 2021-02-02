#include <iostream>
using namespace std;
class Base //基类
{
protected:
  int v1, v2;

public:
  Base();
  Base(int, int);
  ~Base();
  void SetValue(int, int);
  void PrintValue();
};
Base::Base() : v1(0), v2(0) //无参数时初始化成员变量
{
  cout << "Base 无参构造函数" << endl;
}
Base::Base(int m, int n) : v1(m), v2(n)
{
  v1 = m;
  v2 = n;
  cout << "Base 带2个参数构造函数, " << v1 << ", " << v2 << endl;
}
Base::~Base()
{
  cout << "Base 析构函数" << endl;
}
void Base::SetValue(int m, int n)
{
  v1 = m;
  v2 = n;
}
void Base::PrintValue()
{
  cout << "v1=" << v1 << "\tv2=" << v2 << endl;
}

class Base2 //基类
{
protected:
  int v1, v4;

public:
  Base2();
  Base2(int, int);
  ~Base2();
  void SetValue(int, int);
  void PrintValue();
};
Base2::Base2() : v1(0), v4(0) //无参数时初始化成员变量
{
  cout << "Base2 无参构造函数" << endl;
}
Base2::Base2(int m, int n) : v1(m), v4(n)
{
  v1 = m;
  v4 = n;
  cout << "Base2 带2个参数构造函数, " << v1 << ", " << v4 << endl;
}
Base2::~Base2()
{
  cout << "Base2 析构函数" << endl;
}
void Base2::SetValue(int m, int n)
{
  v1 = m;
  v4 = n;
}
void Base2::PrintValue()
{
  cout << "v1=" << v1 << "\tv4=" << v4 << endl;
}

class Derived : public Base, public Base2
{
public:
  int v3;

public:
  Derived();
  Derived(int);
  Derived(int, int, int, int);
  ~Derived();
  void SetValue(int m, int n, int k, int h)
  {
    Base::SetValue(m, n);
    Base2::SetValue(2 * m, h);
    v3 = k;
  }
  void SetValue(int m, int n, int k)
  {
    Base::SetValue(m, n);
    Base2::SetValue(2 * m, 2 * n);
    v3 = k;
  }
  void SetValue(int m, int n)
  {
    Base::SetValue(m, n);
    Base2::SetValue(-1, -1);
    v3 = -1;
  }
  void PrintValue();
};
Derived::Derived() : Base(0, 0), Base2(0, 0), v3(0) //此处默认参数决定基类调用的构造函数参数
{
  cout << "Derived 无参构造函数" << endl;
}
Derived::Derived(int k)
{
  v3 = k;
  cout << "带1个参数构造函数" << endl;
}
Derived::Derived(int m, int n, int k, int t) : Base(m, n), Base2(m, t), v3(k)
{
  cout << "带4个参数构造函数" << endl;
}
Derived::~Derived()
{
  cout << "Derived 析构函数" << endl;
}
void Derived::PrintValue()
{
  Base::PrintValue();
  cout << "\tv3=" << v3 << endl;
  Base2::PrintValue();
  cout << endl;
}

int main()
{
  cout << "带4个参数对象的创建" << endl;
  Derived derived(1000, 2000, 3000, 4000);
  derived.PrintValue();
  cout << endl
       << "不带参数对象的创建" << endl;
  Derived derived2;
  derived2.PrintValue();
  cout << endl
       << "带1个参数对象的创建" << endl;
  Derived derived3(111);
  derived3.PrintValue();
  return 0;
}