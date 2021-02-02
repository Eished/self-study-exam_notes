#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  int n = 0;
  char ch;
  while (ch = cin.get() != EOF) //遇到结束符才推出
  {
    cout.put(ch);
    n++;
  }
  cout << "输入字符统计：" << n << endl;
  return 0;
}