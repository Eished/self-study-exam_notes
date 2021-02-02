#include <iostream>
using namespace std;
class B
{
  int b;

public:
  B(int n)
  {
    b = n;
    cout << b << endl;
  }
  ~B()
  {
    cout << "B destroy" << endl;
  }
};
class C
{
  int c;

public:
  C(int n, int m)
  {
    c = n;
    cout << c << endl;
  }
  ~C()
  {
    cout << "C destroy" << endl;
  }
};
class D : public B, public C
{
  int d;

public:
  D(int n1, int n2, int n3, int n4) : C(n3, n4), B(n2)
  {
    d = n1;
    cout << d << endl;
  }
  ~D()
  {
    cout << "D destroy" << endl;
  }
};
int main()
{
  D objD(2, 4, 6, 8);
  return 0;
}