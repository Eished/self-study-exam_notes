#include <iostream>
using namespace std;
int main()
{
  int x, count, sum = 0;
  freopen("input.dat", "r", stdin); //标准输入定向到文件
  for (count = 0; count < 10; count++)
  {
    cin >> x;
    if (cin.eof())
    {
      cout << cin.eof() << "结束" << endl;
      break;
    }
    else
    {
      cout << x << "," << sum << endl;
      sum += x;
    }
  }
  // 遇到输出中文失败，程序不输出结果，代码编码问题，GB2312改为 UTF-8即可。
  cout << "前" << count << "个整数的平均值 = " << 1.0 * sum / count << endl;
  return 0;
}