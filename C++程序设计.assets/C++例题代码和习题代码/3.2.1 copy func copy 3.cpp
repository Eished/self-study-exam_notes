#include <iostream>
#include <string>
using namespace std;
class Samp
{
public:
  void Setij(int a, int b)
  {
    i = a;
    j = b;
    cout << "i=" << i << "构造函数" << endl;
  }
  void printDemo();
  ~Samp()
  {
    cout << "i=" << i << "析构函数" << endl;
  }
  int GetMuti()
  {
    return i * j;
  }

protected:
  int i;
  int j;
};

int main()
{
  Samp *p;
  p = new Samp[5];
  if (!p)
  {
    cout << "内存分配错误\n";
    return 1;
  }
  for (int j = 0; j < 5; j++)

    p[j].Setij(j, j);
  for (int k = 0; k < 5; k++)
    cout << "Muti[" << k << "] 值是:" << p[k].GetMuti() << endl;
  delete[] p;

  return 0;
}