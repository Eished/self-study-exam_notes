#include <iostream>
using namespace std;
class A
{
  int a, b;

public:
  A(int x = 0, int y = 0)
  {
    a = x;
    b = y;
    cout << a << "," << b;
  }
};
int main()
{
  A *p;
  // p = new A(4, 5);
  p = new A(1, 2);
  return 0;
}