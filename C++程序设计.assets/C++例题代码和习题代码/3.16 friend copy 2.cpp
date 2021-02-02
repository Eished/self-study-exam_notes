#include <iostream>
using namespace std;
class myComplex //复数类
{
private:
  double real, imag; //复数的实部和虚部
public:
  myComplex();
  myComplex(double r, double i);
  friend myComplex addCom(myComplex c1, myComplex c2); //友元函数, 两个参数对象相加
  friend void outCom(myComplex c);                     //友元函数, 输惨参数对象数据
};
myComplex::myComplex(double r, double i)
{
  real = r;
  imag = i;
}
myComplex::myComplex()
{
  real = 0;
  imag = 0;
}
myComplex addCom(myComplex c1, myComplex c2) //定义函数
{
  return myComplex(c1.real + c2.real, c1.imag + c2.imag);
}
void outCom(myComplex c) //定义函数
{
  cout << "(" << c.real << "," << c.imag << ")";
}

int main()
{
  myComplex c1(1, 2), c2(3, 4), res;
  res = addCom(c1, c2); //调用成员函数必须通过类对象
  outCom(c1);
  cout << "+";
  outCom(c2);
  cout << "=";
  outCom(res);
  cout << endl;
  return 0;
}