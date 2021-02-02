#include <iostream>
using namespace std;
class Test
{
  int x, y;

public:
  Test(int a, int b)
  {
    x = a;
    y = b;
  }
  int getx()
  {
    return x;
  }
  int gety()
  {
    return y;
  }
};
int main()
{
  Test mt(10, 20);
  cout << mt.getx() << mt.gety() << endl;
  return 0;
}