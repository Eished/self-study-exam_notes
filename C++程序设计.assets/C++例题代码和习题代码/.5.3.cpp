#include <iostream>
using namespace std;
class Base
{
  int n;

public:
  Base() //没有方法内容会报错
  {
    cout << "基类" << endl;
  }
  void Print()
  {
    cout << "基类打印" << endl;
  }
};

class Derived : public Base
{
public:
  Derived()
  {
    cout << "派生类" << endl;
  }
  void Print()
  {
    cout << "派生类打印" << endl;
  }
};

int main()
{
  Base b;
  Derived der;
  cout << "-----基类指针指向派生类对象-------" << endl;
  Base *pBase = &der; //基类指针指向派生类对象
  pBase->Print();     //基类 Print 函数

  cout << "-------基类指针指向基类对象-----" << endl;
  pBase = &b;     //基类指针指向基类对象
  pBase->Print(); //基类 Print 函数

  cout << "-------派生类对象转换为基类对象-----" << endl;
  ((Base)der).Print(); //指针或对象是什么类型就调用什么类型的函数
  // ((Derived)b).Print(); //基类对象无法转换为派生类对象

  cout << "------派生类指针指向派生类对象------" << endl;
  Derived *pDer = &der; //派生类指针指向派生类对象
  pDer->Print();        //派生类 Print 函数

  cout << "-----派生类指针指向 基类指针转换成派生类指针-------" << endl;
  pDer = (Derived *)(pBase); //基类指针转换成派生类指针赋值给派生类指针
  pDer->Print();             //派生类 Print 函数

  cout << "-----派生类指针指向 转换成派生类型的基类对象-------" << endl;
  pDer = (Derived *)(&b); //派生类指针指向转换成派生类型的基类对象
  pDer->Print();          //派生类 Print 函数

  cout << "-----派生类指针转换成基类指针-------" << endl;
  pBase = ((Base *)(pDer)); //派生类指针转换成基类指针
  pBase->Print();           //基类 Print 函数

  cout << "-----函数调用-------" << endl;
  pDer->Base::Print();           //派生类指针调用基类函数
  pBase->Base::Print();          //基类指针调用基类函数
  ((Derived *)(pBase))->Print(); //基类指针转换派生指针调用派生类函数
  pBase->Print();
  pDer->Print();
  return 0;
}