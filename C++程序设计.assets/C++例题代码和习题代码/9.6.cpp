#include <iostream>
using namespace std;
template <class T1, class T2>
class Pair
{
public:
  T1 first;
  T2 second;
  Pair(T1 k, T2 v) : first(k), second(v) {}
  bool operator<(const Pair<T1, T2> &p) const; //成员函数
};
template <class T1, class T2>
bool Pair<T1, T2>::operator<(const Pair<T1, T2> &p) const //成员函数
{
  return first < p.first;
}
int main()
{
  Pair<string, int> student1("Tom", 19);
  //
  Pair<string, int> student2("Jim", 21);
  //
  Pair<string, string> dic("word", "danci");
  Pair<int, int> coordinate(10, 20);
  cout << "学生：" << student1.first << " " << student1.second << endl;
  cout << "学生：" << student2.first << " " << student2.second << endl;
  cout << "坐标：" << coordinate.first << " " << coordinate.second << endl;
  cout << "学生：" << dic.first << " " << dic.second << endl;
  bool a = student1 < student2;
  if (a == 0)
    cout << student1.first << "位于" << student2.first << "之后" << endl;
  else
    cout << student1.first << "位于" << student2.first << "之前" << endl;
  return 0;
}