#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  double values[] = {1.23, 20.3456, 300.4567, 4000.56789, 50000.1234567};
  cout.fill('*'); //填充*
  for (int i = 0; i < sizeof(values) / sizeof(double); i++)
  {
    cout << "values[" << i << "]=(";
    cout.width(10); //设置宽度
    cout << values[i] << ")" << endl;
  }
  cout.fill(' '); //填充空格
  for (int i = 0; i < sizeof(values) / sizeof(double); i++)
  {
    cout << "values[" << i << "]=(";
    cout.width(10);        //设置宽度
    cout.precision(i + 3); //设置保留有效数字
    cout << values[i] << ")" << endl;
  }
  return 0;
}