#include <iostream>
using namespace std;
class Test
{
public:
  int x, y;

private:
  int a, b;

public:
  int getc();
};
int Test::getc()
{
  return a;
}
int main()
{
  Test a;
  cout << a.x << endl
       << a.getc();
  return 0;
}