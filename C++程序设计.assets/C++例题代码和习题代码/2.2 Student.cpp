class Student
{
public:
  void setStudent(string, myDate); //设置学生信息
  void setName(string);            //设置姓名
  string getName();                //获取姓名
  void setBirthday(myDate);        //设置生日
  myDate getBirthday();            //获取生日
  void printStudent() const;       //打印信息

private:
  string name;     //姓名
  myDate birthday; //生日
};
//类体外定义成员函数
void Student::setStudent(string s, myDate d)
{
  name = s;
  birthday.setDate(d);
  return;
}
void Student::setName(string n)
{
  name = n;
  return;
}
string Student::getName()
{
  return name;
}
void Student::setBirthday(myDate d)
{
  birthday.setDate(d);
  return;
}
myDate Student::getBirthday()
{
  return birthday;
}
void Student::printStudent() const
{
  cout << "姓名:" << name << "\t生日:";
  birthday.printDate(); //调用类myDate 的成员函数
  cout << endl;
}