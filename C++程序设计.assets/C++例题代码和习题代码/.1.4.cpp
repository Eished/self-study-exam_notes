#include <iostream>
using namespace std;
class A
{
public:
  int fun(double x)
  {
    return int(x / 2);
  }
  int fun(int x)
  {
    return x * 2;
  }
};
int main()
{
  A a;
  int s = a.fun(6.0) + a.fun(2);
  cout << s;
  return 0;
}