#include <iostream>
#include <string>
using namespace std;
class Demo
{
  int id;

public:
  Demo(int i)
  {
    id = i;
    cout << "id=" << id << "构造函数" << endl;
  }
  void printDemo();
  ~Demo()
  {
    cout << "id=" << id << "析构函数" << endl; //下节介绍
  }
};
void Demo::printDemo()
{
  cout << "id=" << id << endl;
}
int main()
{
  Demo d4(4); //主函数内定义
  d4.printDemo();
  d4 = 6; //可看作是将整型数6 转为Demo 对象
  d4.printDemo();
  return 0;
}