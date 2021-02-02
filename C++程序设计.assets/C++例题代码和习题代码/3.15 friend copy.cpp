#include <iostream>
using namespace std;
class myComplex //������
{
private:
  double real, imag; //������ʵ�����鲿
public:
  myComplex();
  myComplex(double r, double i);
  myComplex addCom(myComplex c); //��Ա����, �����߶������������c���
  void outCom();                 //��Ա����, ��������߶�����й�����
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

int main()
{
  myComplex c1(1, 2), c2(3, 4), res;
  res = c1.addCom(c2); //���ó�Ա��������ͨ�������
  c1.outCom();
  cout << "+";
  c2.outCom();
  cout << "=";
  res.outCom();
  cout << endl;
  return 0;
}