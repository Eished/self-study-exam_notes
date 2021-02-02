#include <iostream>
using namespace std;
class CBase
{
protected:
  int n;

public:
  CBase(int i) : n(i) {}
  void Print() { cout << "CBase:n=" << n << endl; }
};
class CDerived : public CBase
{
public:
  int v;
  CDerived(int i) : CBase(i), v(2 * i) {}
  void Func(){};
  void Print()
  {
    cout << "CDerived:n=" << n << endl;
    cout << "CDerived:v=" << v << endl;
  }
};
int main()
{
  CDerived objDerived(3);
  CBase objBase(5);
  CBase *pBase = &objDerived; // 使得基类指针指向派生类对象
                              //pBase->Func(); //错, CBase类没有Func()成员函数
                              //pBase->v = 5;  //错 CBase类没有v成员变量
  pBase->Print();
  cout << "1)------------" << endl;
  //CDerived * pDerived = & objBase; //错，不能将基类指针赋值给派生类指针
  CDerived *pDerived = static_cast<CDerived *>(&objBase);
  pDerived->Print(); //慎用，可能出现不可预期的错误
  cout << "2)------------" << endl;
  objDerived.Print();
  cout << "3)------------" << endl;
  pDerived->v = 128; //往别人的空间里写入数据，会有问题
  objDerived.Print();
  return 0;
}