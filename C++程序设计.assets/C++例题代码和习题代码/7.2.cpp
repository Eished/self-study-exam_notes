#include <iostream>
using namespace std;
int main()
{
  int x, count, sum = 0;
  freopen("input.dat", "r", stdin); //标准输入定向到文件
  for (count = 0; count < 10; count++)
  {
    cin >> x;
    sum += x;
  }
  cout << "前" << count << "个整数的平均值 = " << 1.0 * sum / count << endl;
  return 0;
}