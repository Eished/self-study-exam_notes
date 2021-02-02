#include <iostream>
using namespace std;
class A
{
public:
  int x, y;
  void init(int a, int b)
  {
    x = a;
    y = b;
  }
};
int main()
{
  A a;
  a.init(5, 9);
  cout << a.x << a.y;
  return 0;
}