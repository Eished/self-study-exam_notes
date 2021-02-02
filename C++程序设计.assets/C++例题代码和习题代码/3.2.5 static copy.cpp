#include <iostream>
#include <string>
using namespace std;
class Test
{
public:
  static int x;
  Test(int i = 10)
  {
    x = i + x;
  }
  int Getnum()
  {
    return Test::x + 7;
  }
};
int Test::x = 83;
int main()
{
  Test test;
  cout << test.Getnum() << endl;
  return 0;
}