#include <iostream>
using namespace std;
class A
{
  int m;

public:
  A() {}
  A(int a) : m(a) {}
  int get() { return m; }
  void set(int a) { m = a; }
};
int main()
{
  A *p = new A[2];
  p->set(30);
  p = p + 1;
  p->set(50);
  A a[2] = {1, 9};
  cout << a[0].get() << "," << a[1].get() << endl;
  cout << p->get() << endl;
  p = p - 1;
  cout << p->get() << endl;
  delete[] p;
  return 0;
}