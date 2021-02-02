#include <iostream>
using namespace std;
class Test
{
  int x, y;

public:
  void fun(int a, int b)
  {
    x = a;
    y = b;
  }
  void show()
  {
    cout << x;
    if (y > 0)
      cout << y << endl;
  }
};
int main()
{
  Test a;
  a.fun(1, 10);
  a.show();
  a.fun(2, 0);
  a.show();
  return 0;
}