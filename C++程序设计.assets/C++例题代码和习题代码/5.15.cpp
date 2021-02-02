#include <iostream>
using namespace std;
class BaseClass //����
{
protected:
  int v1, v2;

public:
  BaseClass();
  BaseClass(int, int);
  ~BaseClass();
};
BaseClass::BaseClass()
{
  cout << "BaseClass No parameter" << endl;
}
BaseClass::BaseClass(int m, int n)
{
  v1 = m;
  v2 = n;
  cout << "BaseClass Two parameter" << endl;
}
BaseClass::~BaseClass()
{
  cout << "BaseClass Destroy" << endl;
}

class DerivedClass : public BaseClass
{
  int v3;

public:
  DerivedClass();
  DerivedClass(int);
  DerivedClass(int, int, int);
  ~DerivedClass();
};
DerivedClass::DerivedClass()
{
  cout << "DerivedClass No parameter" << endl;
}
DerivedClass::DerivedClass(int k) : v3(k)
{
  cout << "DerivedClass One parameter" << endl;
}
DerivedClass::DerivedClass(int m, int n, int k) : BaseClass(m, n), v3(k)
{
  cout << "DerivedClass Three parameter" << endl;
}
DerivedClass::~DerivedClass()
{
  cout << "DerivedClass Destroy" << endl;
}

int main()
{
  cout << "create no parameter object" << endl;
  BaseClass baseCla;
  DerivedClass derivedCla;
  cout << "create with parameter object" << endl;
  BaseClass baseCla1(10, 20);
  DerivedClass derivedCla1(30);
  return 0;
}