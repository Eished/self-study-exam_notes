#include <iostream>
using namespace std;
float bigger(int a, float b)
{
  if (a > b)
    return a;
  else
    return b;
}
int main()
{
  int xI = 10;
  float yF = 40.444;
  cout << bigger(xI, yF);
  return 0;
}