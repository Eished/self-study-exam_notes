#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  double x = 1234567.89, y = 1.23456789;
  //无格式控制
  cout << "无格式控制：\t\t x=(" << x << "),y=(" << y << ")\n";

  //保留5位有效数字
  cout << "保留5位有效数字：\t\t x=(" << setprecision(5) << x << "),y=(" << y << ")\n";

  //保留小数点后5位
  cout << "保留小数点后5位：\t\t x=(" << fixed << setprecision(5) << x << "),y=(" << y << ")\n";

  //科学计数法，保留小数点后5位
  cout << "科学计数法，保留小数点后5位：\t\t x=(" << scientific << setprecision(5) << x << "),y=(" << y << ")\n";

  //非负数显示正号，输出宽度为12字符，宽度不足时用‘*’填补
  cout << "非负数显示正号：\t\t " << showpos << fixed << setw(12) << setfill('*') << y << endl;

  //非负数不显示正号，输出宽度为12字符，宽度不足时右边用填充字符填充
  cout << "不显示正号，右边用填充字符填充：\t\t " << noshowpos << left << setw(12) << y << endl;

  //输出宽度为12字符，宽度不足时左边用填充字符填充
  cout << "左边用填充字符填充：\t\t " << showpos << right << setw(12) << y << endl;

  //宽度不足时，负号和数值分列左右，中间用填充字符填充
  cout << "中间用填充字符填充：\t\t " << showpos << internal << setw(12) << -y << endl;
}