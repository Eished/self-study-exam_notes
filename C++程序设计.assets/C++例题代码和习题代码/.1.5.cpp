#include <iostream>
#include <cmath>
using namespace std;
int f(int);
int main()
{
  for (int i = 0; i < 3; i++)
  {
    cout << f(i) << endl;
  }
  return 0;
}
int f(int a)
{
  int b = 0, c = 1;
  b++;
  c++;
  return int(a + pow(double(b), 2) + c);
}