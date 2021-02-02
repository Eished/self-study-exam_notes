#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  char str[30];
  while (!+cin.eof()) //当输入流没有结束时继续循环
  {
    cin.ignore(10, ':'); //在cin流中跳过':'之前的全部字符
    if (!cin.eof())      //输入流没有结束
    {
      cin >> str; //输入电话号码
      cout << str << endl;
    }
  }
  return 0;
}