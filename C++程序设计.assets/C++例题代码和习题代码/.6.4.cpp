#include <iostream>
using namespace std;
class A
{
public:
  virtual void fun()
  {
    cout << "A::fun()" << endl;
  }
};
class D : public A
{
public:
  virtual void fun()
  {
    cout << "D::fun()" << endl;
  }
};
void Test()
{
  A a;
  D d;
  a.fun();
  d.fun();
}
int main()
{
  Test();
  // A a;
  // D d;
  // a.fun();
  // d.fun();
  return 0;
}