#include <iostream>
using namespace std;
class Date
{
  int n;

public:
  Date(int y, int m, int d)
  {
    SetDate(y, m, d);
  }
  void SetDate(int y, int m, int d)
  {
    year = y;
    month = m;
    day = d;
  }
  void Print() const
  {
    cout << year << '/' << month << '/' << day << "; ";
  }

protected:
  int year, month, day;
};

class DateTime : public Date
{
public:
  DateTime(int y, int m, int d, int h, int mi, int s) : Date(y, m, d) //初始化Date
  {
    SetTime(h, mi, s);
  }
  void SetTime(int h, int mi, int s)
  {
    hours = h;
    minutes = mi;
    seconds = s;
  }
  void Print() const
  {
    cout << hours << ":" << minutes << ":" << seconds << "\n";
  }

private:
  int hours, minutes, seconds;
};
int main()
{
  DateTime dt(2018, 7, 16, 12, 30, 0);
  DateTime *pdt = &dt;
  ((Date)dt).Print(); // 对象类型转换，调用基类成员函数
  dt.Print();
  cout << "---------------------" << endl;
  ((Date *)pdt)->Print(); // 对象指针类型转换，调用基类成员函数
  pdt->Print();
  return 0;
}