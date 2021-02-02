#include <iostream>
using namespace std;
class A
{

  int real, imag;

public:
  A(int r = 0, int i = 0)
  {
    real = r;
    imag = i;
  }
  A operator-(A &c);              // 重载为成员函数
  A friend operator+(A &a, A &b); //重载为友元
  void out()
  {
    cout << real << "," << imag << endl;
  }
};
A operator+(A &a, A &b)
{
  int r = a.real + b.real;
  int i = a.imag + b.imag;
  return A(r, i);
}
A A::operator-(A &c)
{
  cout << real << "," << imag << endl;
  int r = this->real - c.real;
  int i = this->imag - c.imag;
  return A(r, i);
}
int main()
{
  A a(1, 2), b(3, 4), z;
  z = a + b;
  z.out();
  z = a - b;
  z.out();
  return 0;
}