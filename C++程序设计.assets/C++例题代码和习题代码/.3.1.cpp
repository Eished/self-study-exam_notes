#include <iostream>
using namespace std;
class A
{
  float x;

public:
  void f(float a)
  {
    x = a;
  }
  float friend max(A &a, A &b);
};
float max(A &a, A &b)
{
  return (a.x > b.x) ? a.x : b.x;
}
int main()
{
  A a, b;
  a.f(2.2);
  b.f(3.3);
  cout << max(a, b);
  return 0;
}