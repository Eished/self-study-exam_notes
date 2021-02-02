#include <iostream>
using namespace std;
class pointer
{
public:
  int a;
  int *p;
  pointer()
  {
    a = 100;
    p = new int(10); //初始化内存
    *p = 11;         //向内存赋值
  }
  pointer(const pointer &temp) //复制构造函数
  {
    if (this != &temp)
    {
      a = temp.a; // a 是局部变量，内存跟随对象
      p = temp.p; // p 是指针变量，内存固定，需要深度复制
      cout << "*p=" << *p << ",p=" << p << endl;
      // delete p;                 //删除指针，新指针的地址还是原来的地址，不能删除
      p = new int(*temp.p + 1); //把指针 temp.p 的值赋值给 指针 p
      *p = *temp.p + 10;        //加10更好分辨 *p
      cout << "*p=" << *p << ",p=" << p << endl;
    }
  }
  ~pointer() //析构函数
  {
    if (p != NULL)
      delete p;
  }
  pointer operator=(pointer &a) //成员函数 重载赋值运算符
  {
    if (this == &a)
      return *this;
    else
    {
      delete p;
      this->p = new int(*a.p);
      cout << "*p3=" << *p << ",p3=" << p << endl;
      return *this;
    }
  }
};
int main()
{
  pointer p1;
  pointer p2(p1);
  pointer p3;
  p3 = p1;
  p1.a = 123;
  *p1.p = 234;
  cout << p1.a << ",p1=" << *p1.p << endl;
  cout << p2.a << ",p2=" << *p2.p << endl;
  cout << p3.a << ",p3=" << *p3.p << endl;
  return 0;
}