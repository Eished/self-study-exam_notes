#include <iostream>
using namespace std;
class BaseClass1 //»ùÀà
{
public:
  int v1, v2;
  BaseClass1();
  BaseClass1(int, int);
  ~BaseClass1();
};
BaseClass1::BaseClass1()
{
  cout << "BaseClass1 No parameter" << endl;
}
BaseClass1::BaseClass1(int m, int n) : v1(m), v2(n)
{
  cout << "BaseClass1 Two parameter" << endl;
}
BaseClass1::~BaseClass1()
{
  cout << "BaseClass1 Destroy" << endl;
}

class BaseClass2
{
public:
  int v1, v4;
  BaseClass2();
  BaseClass2(int, int);
  ~BaseClass2();
};
BaseClass2::BaseClass2()
{
  cout << "BaseClass2 No parameter" << endl;
}
BaseClass2::BaseClass2(int m, int n) : v1(m), v4(n)
{
  cout << "BaseClass2 Two parameter" << endl;
}
BaseClass2::~BaseClass2()
{
  cout << "BaseClass2 Destroy" << endl;
}

class DerivedClasss : public BaseClass1, public BaseClass2
{
public:
  int v3;

public:
  DerivedClasss();
  DerivedClasss(int);
  DerivedClasss(int, int, int, int);
  ~DerivedClasss();
};
DerivedClasss::DerivedClasss()
{
  cout << "DerivedClasss No parameter" << endl;
}
DerivedClasss::DerivedClasss(int k) : v3(k)
{
  cout << "DerivedClasss One parameter" << endl;
}
DerivedClasss::DerivedClasss(int m, int n, int k, int t) : BaseClass1(m, n), BaseClass2(m, t), v3(k)
{
  cout << "DerivedClasss Four parameter" << endl;
}
DerivedClasss::~DerivedClasss()
{
  cout << "DerivedClasss Destroy" << endl;
}
int main()
{
  cout << " create object with parameter" << endl;
  DerivedClasss derivedCla1(1000, 2000, 3000, 4000);
  cout << "v1=" << derivedCla1.BaseClass1::v1 << endl;
  cout << "v2=" << derivedCla1.v2 << endl;
  cout << "v1=" << derivedCla1.BaseClass2::v1 << endl;
  cout << "v4=" << derivedCla1.v4 << endl;
  cout << "v3=" << derivedCla1.v3 << endl;
  return 0;
}