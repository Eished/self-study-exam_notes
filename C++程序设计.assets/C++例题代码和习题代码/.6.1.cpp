#include <iostream>
using namespace std;
class A
{
public:
  int i;
  virtual void func()
  {
    cout << "A0" << endl;
  }
  virtual void func2()
  {
    cout << "A1" << endl;
  }
};
class B : public A
{
  int j;
  void func()
  {
    cout << "B0" << endl;
  }
  virtual void func3()
  {
    cout << "B3" << endl;
  }
};
int main()
{
  A *a;
  B b;
  a = &b;
  a->func();
  a->func2();
  // a->func3();
  return 0;
}