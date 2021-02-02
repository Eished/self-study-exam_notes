#include <iostream>
using namespace std;

int main()
{
  int *p1;
  int **p2 = &p1;
  int b = 20;
  p1 = &b;
  cout << **p2 << endl
       << *p2;

  return 0;
}