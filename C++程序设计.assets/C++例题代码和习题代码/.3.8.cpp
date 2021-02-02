#include <iostream>
using namespace std;
class A
{
  int n;

public:
  A(int j = 5) { n = j++; }
  void print() const
  {
    cout << n << endl;
  }
  void print()
  {
    n = n + 1;
    cout << n;
  }
};
int main()
{
  A a;
  const A a2(2);
  a.print();
  a2.print();
  return 0;
}