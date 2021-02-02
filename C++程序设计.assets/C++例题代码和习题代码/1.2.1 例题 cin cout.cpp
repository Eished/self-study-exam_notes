#include <iostream>
#include <string>
using namespace std;
int main()
{
  int oneInt1, oneInt2;
  char strArray[20];
  string str;
  double oneDouble;
  char oneChar = 'a';
  cout << "输入两个整型值，一个字符，一个字符串，一个浮点值,";
  cout << "以空格、tab、enter 键分割" << endl;
  cin >> oneInt1 >> oneInt2 >> oneChar >> strArray >> oneDouble;
  str = strArray;
  cout << "输入的数据是:" << endl;     //endl 是换行
  cout << "字符串:\t\t" << str << endl //\t是制表符
       << "两个整型值:\t" << oneInt1 << "和\t" << oneInt2 << endl
       << "字符:\t\t" << oneChar << "\n" //"\n"是换行符,与endl相同
       << "浮点值:\t\t" << oneDouble << endl;
  cout << "1234\
56785" << endl; //"\" 用于连接换行的内容
  return 0;
}