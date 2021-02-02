#include <iostream>
using namespace std;
class A
{
  int r, w;

public:
  A()
  {
    cout << "A默认构造" << endl;
  }
  A(int r1, int w1) : r(r1), w(w1)
  {
    cout << "2个参数构造" << endl;
  }
  ~A()
  {
    cout << "A默认析构" << endl;
  }
};

class B
{
  int pr;
  A ty;

public:
  B()
  {
    cout << "B默认构造" << endl;
  }
  B(int p, int tr, int w) : pr(p), ty(tr, w)
  {
    cout << "3个参数构造" << endl;
  }
  ~B()
  {
    cout << "B默认析构" << endl;
  }
};
int main()
{
  B();
  B b(1, 2, 3);
  return 0;
}