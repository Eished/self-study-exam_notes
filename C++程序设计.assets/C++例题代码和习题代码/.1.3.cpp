#include <iostream>
using namespace std;
double pi = 3.14159;
int main()
{
  double r;
  cout << "输入r：";
  cin >> r;
  double l = 2.0 * pi * r;
  double s = pi * r * r;
  cout << l << endl;
  cout << s << endl;
  return 0;
}