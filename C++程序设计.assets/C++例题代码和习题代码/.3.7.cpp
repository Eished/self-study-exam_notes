#include <iostream>
using namespace std;
class A
{
  int n;

public:
  A() { n = 1; }
  int getValue() const
  {
    return n;
  }
  int getValue()
  {
    return 2 * n;
  }
};
int main()
{
  const A a;
  A a2;
  cout << a.getValue() << "," << a2.getValue();
  return 0;
}