#include <iostream>
using namespace std;
template <class T>
class A
{
  int x, y, s;

public:
  A(T a, T b)
  {
    x = a;
    y = b;
    s = x + y;
  }
  void show()
  {
    cout << "x+y=" << s << endl;
  }
};
int main()
{
  A<int> add(10, 100);
  add.show();
  A<float> add2(1.1, 2);
  add2.show();
  return 0;
}