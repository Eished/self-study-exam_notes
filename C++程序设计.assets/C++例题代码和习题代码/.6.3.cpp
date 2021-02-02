#include <iostream>
using namespace std;
class A
{
public:
  virtual void func() = 0;
};
class B : public A
{
public:
  void func()
  {
    cout << "A1" << endl;
  }
};
class C : public A
{
public:
  void func()
  {
    cout << "A2" << endl;
  }
};
void fun(A *p)
{
  p->func();
}
int main()
{
  B b;
  C c;
  A *p = &b;
  fun(p);
  p = &c;
  fun(p);

  return 0;
}