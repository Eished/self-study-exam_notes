#include <iostream>
using namespace std;
void func(int a, int b, int c = 0)
{
  cout << a << b << c;
}
int main()
{
  func(5, 9);
  return 0;
}