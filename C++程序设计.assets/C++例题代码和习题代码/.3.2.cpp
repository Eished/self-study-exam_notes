#include <iostream>
using namespace std;
class A
{
  float x, y;

public:
  void f(float a, float b)
  {
    x = a;
    y = b;
  }
  void friend print(A a);
};
void print(A a)
{
  cout << a.x << "," << a.y;
}
int main()
{
  A a;
  a.f(3.0, 5.0);
  print(a);
  return 0;
}