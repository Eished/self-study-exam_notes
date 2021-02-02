#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class myComplex
{
private:
  double real, imag;

public:
  myComplex(double r = 0, double i = 0) : real(r), imag(i){}; //内联成员函数
  operator double()                                           //重载强制类型转换运算符 double
  {
    return real;
  }
};

int main()
{
  myComplex c(1.2, -3.4);
  cout << (double)c << endl;
  double n = 12 + c; //等价于 double n=12+ coperator double()
  cout << n;
  return 0;
}