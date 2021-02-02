#include <iostream>
using namespace std;
int main()
{
  char ch;
  int x, count = 0, sum = 0;
  cout << "请输入整数 Ctrl+Z 退出" << endl;
  do
  {
    while (cin >> x)
    {
      sum += x;
      count++;
    }
    cout << "确认退出请输入 Q";
    cin.clear();
    cin >> ch;
  } while (toupper(ch) != 'Q');
  cout << "sum=" << sum << ",count=" << count << endl;
  return 0;
}