#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  int n = 65535, m = 20;
  //分别输出一个整数的十进制 十六进制 八进制
  cout << "十进制：" << n << "=" << hex << n << "=" << oct << n << endl;
  //使用 setbase 分别输出一个整数的十进制、十六进制和八进制
  cout << "" << setbase(10) << m << "=" << setbase(16) << m << "=" << setbase(8) << m << endl;
  //使用 showbase 和 setbase 分别输出一个整数 十进制、十六进制、八进制
  cout << showbase;
  cout << setbase(10) << m << "=" << setbase(16) << m << "=" << setbase(8) << m << endl;
  return 0;
}