#include <iostream>
using namespace std;
class Demo
{
private:
  int n;

public:
  Demo(int i = 0) : n(i) {}
  Demo &operator++();   //用于前置
  Demo operator++(int); //用于后置
  operator int() { return n; }
  friend Demo &operator--(Demo &);
  friend Demo operator--(Demo &, int);
};
Demo &Demo::operator++() //前置++
{
  n++;
  return *this;
}
Demo Demo::operator++(int k) //后置++
{
  Demo tmp(*this); //记录修改前的对象
  n++;
  return tmp; //返回修改前对象
}
Demo &operator--(Demo &d) //前置--
{
  d.n--;
  return d;
}
Demo operator--(Demo &d, int) //后置--
{
  Demo tmp(d);
  d.n--;
  return tmp;
}
int main()
{
  Demo d(10);
  cout << (d++) << ","; // d.operator++(0)
  cout << d << ",";
  cout << (++d) << ","; // d.operator++()
  cout << d << ",";
  cout << (d--) << ","; // d.operator--(d,0)
  cout << d << ",";
  cout << (--d) << ","; // d.operator--(d)
  cout << d << ",";
  return 0;
}