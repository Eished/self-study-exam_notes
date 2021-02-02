#include <iostream>
#include <string>
using namespace std;
int main()
{
  string str;
  if (str.empty())
  {
    cout << "null,"
         << "length=" << str.length() << endl;
  }
  else
  {
    cout << "Not null" << endl;
  }
  str = str.append("sadfgflk");
  cout << "str is " << str << ",size=" << str.size() << endl;
  const char *p = str.c_str();
  cout << "p=" << p << endl;
  cout << "p=" << *p << endl;
  cout << "find:" << str.find("ad", 0) << endl;
  cout << "find:" << str.find("de", 4) << endl;
  string str1 = str.insert(4, "123");
  cout << str1 << endl;
  cout << str.substr(5, str.length())
       << endl
       << str.length() << endl;
  str.append("+love");
  cout << str << endl;
  const string str2 = "321";
  str.insert(str.length() - 1, str2);
  cout << str << endl;
  int num = str.find("f1", 2);
  cout << num << endl;
  int num2 = str.find('f', 2);
  cout << num << endl;
  cout << str.empty() << endl;
  cout << str.size() << endl;
  cout << str.length() << endl;
  cout << sizeof(str) << endl;
  return 0;
}