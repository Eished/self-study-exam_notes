#include <iostream>
using namespace std;
class A
{
  double x, y;

public:
  A(double r = 0, double i = 0) : x(r), y(i) {}
  operator double();
};
A::operator double() { return x; }
int main()
{
  A a(1.2, -3.4);
  cout << (double)a << endl;
  double n = 12 + a;
  cout << n;
  return 0;
}