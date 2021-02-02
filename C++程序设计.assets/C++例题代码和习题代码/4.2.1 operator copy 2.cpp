#include <iostream>
using namespace std;
class myComplex //复数类
{
private:
  double real, imag; //复数的实部和虚部
public:
  myComplex();
  myComplex(double r, double i);
  ~myComplex() {}                                                       //不能有分号
  myComplex addCom(myComplex c1);                                       //成员函数, 调用者对象与参数对象c相加
  void outCom();                                                        //成员函数, 输出调用者对象的有关数据
  void outCom(string s);                                                //成员函数, 输出调用者对象的有关数据
  void changeReal(double r);                                            //成员函数
  myComplex operator-(const myComplex &c);                              //成员 重载函数
  friend myComplex operator+(const myComplex &c1, const myComplex &c2); //友元 重载函数 c1+c2
  friend myComplex operator+(const myComplex &c1, double r);            //友元 重载函数 c1+r
  friend myComplex operator+(double r, const myComplex &c1);            //友元 重载函数 r+c1
  friend myComplex operator-(const myComplex &c1, const myComplex &c2); //友元 重载函数
  friend myComplex operator-(const myComplex &c1, double r);            //友元 重载函数
  friend myComplex operator-(double r, const myComplex &c1);            //友元 重载函数
  myComplex &operator=(const myComplex &c);                             //成员函数
  myComplex &operator=(double);                                         //成员函数
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
myComplex myComplex::addCom(myComplex c1)
{
  return myComplex(this->real + c1.real, this->imag + c1.imag);
}
void myComplex::outCom()
{
  cout << "(" << real << "," << imag << ")";
}
void myComplex::outCom(string s)
{
  cout << s << "(" << real << "," << imag << ")" << endl;
}
void myComplex::changeReal(double r)
{
  this->real = r;
}
myComplex myComplex::operator-(const myComplex &c)
{
  return myComplex(this->real - c.real, this->imag - c.imag); //返回一个临时对象
}
myComplex operator+(const myComplex &c1, const myComplex &c2) //c1+c2
{
  return myComplex(c1.real + c2.real, c1.imag + c2.imag); //返回一个临时对象
}
myComplex operator+(const myComplex &c1, double r) //c1+r
{
  return myComplex(c1.real + r, c1.imag); //返回一个临时对象
}
myComplex operator+(double r, const myComplex &c1) //r+c2
{
  return myComplex(r + c1.real, c1.imag); //返回一个临时对象
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
myComplex &myComplex::operator=(const myComplex &c1)
{
  this->real = c1.real;
  this->imag = c1.imag;
  return *this;
}
myComplex &myComplex::operator=(double r)
{
  this->real = r;
  this->imag = 0;
  return *this;
}

int main()
{
  myComplex c1(1, 2), c2(3, 4), res;
  c1.outCom("\t\t\tc1");
  c2.outCom("\t\t\tc2");
  res = c1 + c2;
  res.outCom("执行 res = c1 + c2 →\tres");
  res = c1.addCom(c2);
  res.outCom("执行 res = c1.addCom(c2) →\tres");
  res = c1 + 5;
  res.outCom("执行 res = c1 + 5 →\tres");
  res = 5 + c1;
  res.outCom("执行 res = 5 + c1 →\tres");
  res = c1;
  c1.outCom("\t\t\tc1");
  res.outCom("执行 res = c1 →\tres");
  c1.changeReal(-3);
  c1.outCom("执行 changeReal(-3) →\tc1");
  res.outCom("\t\t\tres");
  res = c1;
  res.outCom("res = c1 →\tres");
  res = 7;
  res.outCom("res = 7 →\tres");
  res = 7 + 8;
  res.outCom("res = 7 + 8; →\tres");
  res = c1 = c2;
  c1.outCom("\t\t\tc1");
  c2.outCom("\t\t\tc2");
  res.outCom("res = c1 = c2 →\tres");

  return 0;
}