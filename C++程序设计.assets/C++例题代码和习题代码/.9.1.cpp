#include <iostream>
using namespace std;
template <class T>
class f
{
public:
  T x, y;
  void fun(T a, T b)
  {
    x = a;
    y = b;
  }
  T max()
  {
    return (x > y) ? x : y;
  }
};
int main()
{
  f<double> a;
  f<double> b;
  a.fun(1.5, 3.8);
  cout << a.x << "," << a.y << "," << a.max() << endl;
  b.fun(-1, 4);
  cout << b.x << "," << b.y << "," << b.max() << endl;
  return 0;
}