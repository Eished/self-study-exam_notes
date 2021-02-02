#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class myComplex
{
private:
  double real, imag;

public:
  myComplex() : real(0), imag(0) {}
  myComplex(double r, double i) : real(r), imag(i) {}
  ostream &operator<<(ostream &os);                      //成员函数 ,插入
  friend istream &operator>>(istream &is, myComplex &c); //友元,提取
};
ostream &myComplex::operator<<(ostream &os)
{
  if (this->imag >= 0)
  {
    os << this->real << "+" << this->imag << "i"; //以 a+bi 的形式输入
  }
  else
  {
    os << this->real << "-" << -this->imag << "i";
  }
  return os;
}
istream &operator>>(istream &is, myComplex &c)
{
  string s;
  is >> s;                  //将a+bi 作为字符串读入,a+bi中间不能有空格
  int pos = s.find("+", 0); //查找虚部
  if (pos == -1)
    pos = s.find("-", 1);                      //虚部为负数时
  string sReal = s.substr(0, pos);             //分离出代表实部的字符串
  c.real = atof(sReal.c_str());                //atof() 能将参数内容转换成浮点数
  sReal = s.substr(pos, s.length() - pos - 1); //分离出代表虚部的字符串
  c.imag = atof(sReal.c_str());
  return is;
}

int main()
{
  myComplex c, c1;
  int n;
  cout << "请输入两个复数([-]a±bi)和一个整数, 以空格分隔" << endl;
  cin >> c >> c1 >> n;
  c1 << (c << cout << ",") << "," << n; //注意调用形式
  return 0;
}