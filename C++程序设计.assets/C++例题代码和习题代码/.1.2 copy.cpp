#include <iostream>
using namespace std;

int main()
{
  const int x = 5, y = 6;
  const int *p = &x;
  p = &y;
  cout << *p << endl;
  return 0;
}