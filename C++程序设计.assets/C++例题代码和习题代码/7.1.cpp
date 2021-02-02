#include <iostream>
using namespace std;
int main()
{
  int x, y;
  cin >> x >> y;
  freopen("test.txt", "w", stdout);
  if (y == 0)
    cerr << "error." << endl;
  else
    cout << x << "/" << y << "=" << x / y << endl;
  return 0;
}