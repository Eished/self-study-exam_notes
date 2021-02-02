#include <iostream>
using namespace std;
int oneX = 10;
int oneY = 20;
int a = 11;
int &refValue(int &x) //返回值是引用,可作左值
{
  return x;
}
int main()
{
  // refValue(oneX) = 30;             //返回值是引用,可作左值
  cout << "oneX=" << oneX << endl; //输出 oneX=30
  // refValue(oneY) = 40;             //返回值是引用的函数调用表达式,可作左值使用
  cout << "oneY=" << oneY << endl; //输出oneY=40
  refValue(a) = 111;
  cout << refValue(a) << endl
       << a;
  return 0;
}