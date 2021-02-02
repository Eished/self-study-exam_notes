#include <iostream>
using namespace std;
class Base
{
private:
  float x;

public:
  static int staV;
  Base()
  {
    staV++;
  }
};
int Base::staV = 0;
class Derived : public Base
{
private:
  float y;

public:
  Derived()
  {
    staV++;
  }
};
int main()
{
  Base a;
  cout << a.staV << endl;
  Derived d;
  cout << d.staV << endl;
  return 0;
}