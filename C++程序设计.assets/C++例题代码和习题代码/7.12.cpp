#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  char buf[10];
  int i = 0;
  while (cin.getline(buf, 10)) //输入超过九个就会出错
  {
    cout << ++i << ":" << buf << endl;
    cout << "last:" << buf << endl;
  }
  return 0;
}