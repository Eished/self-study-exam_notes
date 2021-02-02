#include <iostream>
using namespace std;
class myComplex //复数类
{
private:
  double real, imag; //复数的实部和虚部
public:
  myComplex();
  myComplex(double r, double i);
  myComplex addCom(myComplex c);                                        //成员函数, 调用者对象与参数对象c相加
  void outCom();                                                        //成员函数, 输出调用者对象的有关数据
  myComplex operator-(const myComplex &c);                              //成员 重载函数
  friend myComplex operator+(const myComplex &c1, const myComplex &c2); //友元 重载函数
  friend myComplex operator-(const myComplex &c1, const myComplex &c2); //友元 重载函数
  friend myComplex operator-(const myComplex &c1, double r);            //友元 重载函数
  friend myComplex operator-(double r, const myComplex &c1);            //友元 重载函数
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
myComplex myComplex::addCom(myComplex c)
{
  return myComplex(real + c.real, imag + c.imag);
}
void myComplex::outCom()
{
  cout << "(" << real << "," << imag << ")";
}
myComplex myComplex::operator-(const myComplex &c)
{
  return myComplex(this->real - c.real, this->imag - c.imag); //返回一个临时对象
}
myComplex operator+(const myComplex &c1, const myComplex &c2) //c1+c2
{
  return myComplex(c1.real + c2.real, c1.imag + c2.imag); //返回一个临时对象
}
myComplex operator-(const myComplex &c1, const myComplex &c2) //c1-c2
{
  return myComplex(c1.real - c2.real, c1.imag - c2.imag); //返回一个临时对象
}
myComplex operator-(const myComplex &c1, double r) //c1-r
{
  return myComplex(c1.real - r, c1.imag); //返回一个临时对象
}
myComplex operator-(double r, const myComplex &c1) //r-c1
{
  return myComplex(r + c1.real, -c1.imag); //返回一个临时对象
}

int main()
{
  myComplex c1(1, 2), c2(3, 4), res;
  c1.outCom();
  cout << "operator+";
  c2.outCom();
  cout << "=";
  res = c1 + c2;
  res.outCom();
  cout << endl;
  c1.outCom();
  cout << "operator-";
  c2.outCom();
  cout << "=";
  res = c1 - c2;
  res.outCom();
  cout << endl;
  res = c1 - c2;
  res.outCom();
  res = c1 - 5;
  res.outCom();
  res = 5 - c1;
  res.outCom();
  return 0;
}