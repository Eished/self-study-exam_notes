#include <iostream>
using namespace std;
class A
{
private:
  static int num;

public:
  A(int n);
  void show();
};
int A::num = 5;
A::A(int n)
{
  num = n;
}
void A::show()
{
  cout << num;
}
int main()
{
  A a(10);
  a.show();
  return 0;
}