#include <iostream>
#include <string>
using namespace std;
class constClass
{
  const int conMbr; //类中的常量成员变量
  int Mbr;          //普通成员变量

public:
  constClass() : conMbr(0), Mbr(100) {} //初始化列表处给初始值
  constClass(int i) : conMbr(i)         //初始化列表处给初始值
  {
    Mbr = 200;
  }
  void printConst()
  {
    cout << "conMbr=" << conMbr << ",Mbr" << Mbr << endl;
  }
  int getConst()
  {
    cout << "调用非常量函数" << endl;
    return conMbr;
  }
  int getConst() const
  {
    cout << "调用常量函数" << endl;
    return conMbr;
  }
  int getValue()
  {
    return Mbr;
  }
  void processConst()
  {
    cout << "--在processConst函数中 非常量--" << endl;
    int x = 2 * conMbr + 1;
    cout << "x=2*conMbr+1=" << x << endl; //可以读取 conMbr
    //conMbr++; //错误, 不能更改常量成员变量 conMbr的值
    Mbr++; //可以修改非常量成员 Mbr的值
    cout << "Mbr=" << Mbr << endl;
  }
  void processConst() const
  {
    cout << "--在processConst函数中 常量--" << endl;
    int x = conMbr + 1;
    cout << "x=conMbr+1=" << x << endl; //可以读取 conMbr
    //conMbr++; //错误, 不能更改常量成员变量 conMbr的值
    // Mbr++; //不能修改非常量成员 Mbr的值
    cout << "Mbr=" << Mbr << endl;
  }
};

int main()
{
  constClass ob1(123), ob2;
  ob1.printConst();
  cout << "ob2.getConst()=" << ob2.getConst() << endl;
  ob2.processConst();
  const constClass ob3(20);
  cout << "ob3.getConst()=" << ob3.getConst() << endl;
  ob3.processConst();
  return 0;
}