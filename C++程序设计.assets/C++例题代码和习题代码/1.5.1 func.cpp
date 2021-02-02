#include <iostream>
using namespace std;
void SwapValue(int a, int b) //形参
{
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
  cout << "在SwapValue()函数中:\t\ta=" << a << ", b=" << b << endl;
  return;
}
void SwapRef(int &a, int &b) //a,b 实参引用地址的值互换
{
  int tmp;
  tmp = a;
  a = b;
  b = tmp;
  cout << "在SwapRef()函数中:\t\ta=" << a << ", b=" << b << endl;
  return;
}
int main()
{
  int a = 10;
  int b = 20;
  cout << "数据交换前:\t\ta=" << a << ", b=" << b << endl
       << endl;
  SwapValue(a, b);
  cout << "SwapValue后:\t\ta=" << a << ", b=" << b << endl
       << endl;
  a = 10;
  b = 20;
  SwapRef(a, b);
  cout << "SwapRef后:\t\ta=" << a << ", b=" << b << endl
       << endl;
  return 0;
}