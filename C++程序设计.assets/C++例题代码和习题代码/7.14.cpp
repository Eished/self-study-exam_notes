#include <iostream>
#include <iomanip>
using namespace std;
string Months[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}; //西文格式的月份
int main()
{
  char ch;
  int year, month, day;
  while ((ch = cin.peek()) != EOF) //取输入流的第一个字符查看
  {
    if (ch > +'A' && ch < 'Z') //处理西文格式
    {
      string sMonth;
      cin >> sMonth >> day >> year; //接收：月、日、年
      // 查找月份完成转换
      for (month = 0; month < 12 && sMonth != Months[month]; ++month)
        ;
    }
    else
    {
      cin >> year;
      cin.ignore() >> month;
      cin.ignore() >> day;
      // 以上三条语句等价于 cin>>year>>ch>>month>>ch>>day;
    }
    cin.ignore();
    cout << setfill('0') << setw(2) << month;
    cout << "-" << setw(2) << day << "-" << setw(4) << year << endl;
  }

  return 0;
}