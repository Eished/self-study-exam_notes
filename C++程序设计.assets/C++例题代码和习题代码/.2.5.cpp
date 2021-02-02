#include <iostream>
using namespace std;
class A
{
private:
  int x, y;

public:
  int getx()
  {
    return x;
  }
  int gety()
  {
    return y;
  }
  void setx(int x0)
  {
    x = x0;
  }
  void sety(int y0)
  {
    y = y0;
  }
  void displayx()
  {
    cout << "x=" << x << endl;
  }
  void displayy()
  {
    cout << "y=" << y << endl;
  }
};
int main()
{
  A obj, *p, arr[10];
  obj.setx(111);
  cout << obj.getx() << endl;
  obj.displayx();

  p = new A;
  (*p).setx(56);
  p->sety(78);
  int k = (*p).getx();
  int m = p->gety();
  cout << "k=" << k << endl;
  cout << "m=" << m << endl;
  for (int i = 0; i < 5; i++)
  {
    arr[i].setx(i + 10);
    arr[i].sety(i + 20);
  }
  p = &arr[9];
  while (p >= &arr[5])
  {
    p->setx(88);
    p->sety(99);
    p--;
  }
  for (int i = 0; i < 10; i++)
    cout << arr[i].getx() << " , " << arr[i].gety() << endl;
  return 0;
}