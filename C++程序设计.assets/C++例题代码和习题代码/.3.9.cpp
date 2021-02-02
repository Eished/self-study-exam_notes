#include <iostream>
using namespace std;
class A
{
public:
  int x, y;
  void init(int initx, int inity)
  {
    x = initx;
    y = inity;
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
void dispaly(A &a)
{
  cout << a.getx() << "," << a.gety() << endl;
}
int main()
{
  A B[5]{{5, 5}, {3, 3}, {1, 1}, {2, 2}, {4, 4}};
  A *p = B;
  B[3].init(7, 3);
  p->init(7, 8);
  for (int k = 0; k < 5; k++)
    dispaly(*(p++));
  return 0;
}