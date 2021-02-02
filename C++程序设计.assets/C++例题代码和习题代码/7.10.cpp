#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  char c = 'a', str[80] = "1234567890abcdefghijklmn";
  int x = 65;
  cout << "cout.put('a'):";
  cout.put('a');
  cout << "\ncout.put(c+25):";
  cout.put(c + 25); //字母转换成整数再相加
  cout << "\ncout.put(x):";
  cout.put(x);
  cout << "\ncout.put(str,20):";
  cout.write(str, 20); //将str的前20个字节输入到流中
  return 0;
}