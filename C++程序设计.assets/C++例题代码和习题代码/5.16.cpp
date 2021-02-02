#include <iostream>
using namespace std;
class Base //»ùÀà
{
private:
  int Y;

public:
  Base(int y = 0)
  {
    Y = y;
    cout << "Base(" << y << ")" << endl;
  }
  ~Base()
  {
    cout << "~Base()" << endl;
  }
  void print()
  {
    cout << Y << " ";
  }
};
class Derived : public Base
{
private:
  int Z;

public:
  Derived(int y, int z) : Base(y)
  {
    Z = z;
    cout << "Derived(" << y << "," << z << ")" << endl;
  }
  ~Derived()
  {
    cout << "~Derived()" << endl;
  }
  void print()
  {
    Base::print();
    cout << Z << endl;
  }
};

int main()
{
  Derived d(10, 20);
  d.print();
  return 0;
}