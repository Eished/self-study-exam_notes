> https://github.com/Eished/self-study-exam_notes

# 大纲 (2019版)

## 考试题型

- 单选题
  - 1分x20题 = 20分
- 填空题
  - 1分x20题 = 20分
- 程序改错题
  - 4分x5题 = 20分
- 完成程序题
  - 4分x5题 = 20分
- 程序分析题
  - 5分x2题 = 10分
- 程序设计题
  - 10分x1题 = 10分

## IDE 

- 书本推荐：Dev C++ 5.11

- 本人使用：VScode

  - 解决utf-8中文乱码问题, 在vs code修改代码的打开和保存方式

    直接就将代码保存为gb2312。在vs code右下角可以看到当前文件编码方式，点击utf-8修改打开和保存方式为gb2312。

  - VScode 执行完会自动关闭终端, return 前设置断点

# 第一章 C++ 语言简介

- C++发展历史，与C语言的异同
- 掌握C++ 程序结构，正确使用头文件及命名空间
- 基本输入/输出
- 函数声明和传参
- 函数重载概念
- 理解 const ，指针，引用，动态内存分配和释放
- string 类基本功能

## 第一节 C++发展简史

- 低级语言：机器语言，汇编语言
- 中级语言：C语言
- 高级语言：面向用户，易懂、通用。

## 第二节 C++特点

- 编译式、通用、大小写敏感，支持面向对象
- 特点
  - 继承和兼容C 语言，简洁高效
  - 面向对象

### 一、基本输入/输出

- 输入：空格、TAB、ENTER 作为分隔符

  ```C++
  #include <iostream>
  using namespace std;
  int main()
  {
    int a = 1, b = 2;
    cin >> a >> b;
    cout << "Hello Vscode\n"
      << a * b
      << endl;
    return 0;
  }
  ```

- 输入/输出示例

  ```C++
  #include <iostream>
  #include <string>
using namespace std;
  int main()
  {
    int oneInt1, oneInt2;
    char strArray[20];
    string str;
    double oneDouble;
    char oneChar = 'a';
    cout << "输入两个整型值，一个字符，一个字符串，一个浮点值,";
    cout << "以空格、tab、enter 键分割" << endl;
    cin >> oneInt1 >> oneInt2 >> oneChar >> strArray >> oneDouble;
    str = strArray;
    cout << "输入的数据是:" << endl;     //endl 是换行
    cout << "字符串:\t\t" << str << endl //\t是制表符
         << "两个整型值:\t" << oneInt1 << "和\t" << oneInt2 << endl
         << "字符:\t\t" << oneChar << "\n" //"\n"是换行符,与endl相同
         << "浮点值:\t\t" << oneDouble << endl;
    return 0;
  }
  ```
  
- `cin` 输入字符类型时根据变量类型自动提取相应长度字节, 数值类型数据需要分隔

- `getchar()`: 获取 space\tab\enter 等特殊字符

- ```C++
  cout <<"1234\ 	//"\" 用于连接换行的内容
  566785"<<endl;
  ```

- `cout` 自动识别输出类型



### 二、头文件和命名空间

- 常用的头文件

  - 标准输入输出流: `<iostream>`
  - 标准文件流: `<fstream>`
  - 标准字符串处理函数: `<string>`
  - 标准数学函数: `<cmath>`

- 自定义头文件

  - `<>`: 系统设定目录寻找, 未找到再去指定目录找
  - `“”`: 用户当前目录或指定目录找
    - `#include "e:\myprog\ex1.h"`

- 命名空间 `using namespace std`

  - 为了避免不同人开发时命名冲突

    - ```C++
      namespace 命名空间名
      {
      命名空间内各种声明(函数声明\类声明)
      }
      ```

  - 引用命名空间标识符

    - 不引用命名空间, 则使用全称: `命名空间名::标识符名`

    - ```C++
      using 命名空间名::标识符; // 单独引用
      using namespace 命名空间名; // 引用整个命名空间
      ```



### 三、强制类型转换运算符

- 不同类型量混合运算时, 系统自动执行类型转换, 也可使用 强制类型转换运算符 `static_cast` 或 `const_cast` 进行转换

  - ```C++
    static_cast<类型名>(表达式); //static_cast 可以省略
    
    oneInt2=static_cast<int>(oneDouble); //强制类型转换
    oneInt2=int(oneDouble); //强制类型转换运算符的新形式
    oneInt2=(int)oneDouble; //强制类型转换运算符的旧形式
    oneInt2=oneDouble; //自动类型转换
    ```

  - ```C++
    const_cast<类型名>(表达式); 
    ```

    - 用于去除指针和引用的常量性,不能去除变量的常量性
    - 常量指针转化为非常量指针, 任指向原对象(`const int *p=> int *p`)
    - 常量引用转化为非常量引用, 任指向原对象
    - 指针的教程: https://www.imooc.com/video/7858
      - 指针的本质就是内存地址

  - 示例: 

    ```C++
    #include <iostream>
    using namespace std;
    int main()
    {
      int a = 10;
      const int *p = &a; //不能使用常量指针p修改a的值,"&"取地址符,"*"从地址取值
      const int ca = 30; //被const修饰
      int *q;
      cout << "a的内存地址为:\t" << &a << "\t a的值为:\t" << a << endl;
      cout << "p指向的地址为:\t" << p << "\t *p的值为:\t" << *p << endl;
      q = const_cast<int *>(p); //去除p的常量性赋给q,如果写q=p;会报错
      *q = 20;                  //如果写*p=20;是错误的
      cout << "a的内存地址为:\t" << &a << "\t a的值为:\t" << a << endl;
      cout << "p指向的地址为:\t" << p << "\t *p的值为:\t" << *p << endl;
      cout << "q指向的地址为:\t" << q << "\t *q的值为:\t" << *q << endl;
      cout << "分界线" << endl;
      p = &ca;                  //ca的值不能修改
      q = const_cast<int *>(p); //去除p的常量性赋给q,如果写q=p;会报错
      *q = 40;                  //如果写*p=40;是错误的
      cout << "ca的内存地址为:\t" << &ca << "\t ca的值为:\t" << ca << endl;
      cout << "p指向的地址为:\t" << p << "\t *p的值为:\t" << *p << endl;
      cout << "q指向的地址为:\t" << q << "\t *q的值为:\t" << *q << endl;
      return 0;
    }
    ```

  - 疑问: 常量的非常量指针修改内存地址内的值, 内存地址相同, 值不同



### 四、函数参数的默认值

- 声明函数时为形参指定默认值
  - 默认值写在声明或定义函数的地方, 不能都写
- 调用的函数有默认值的函数时, 可以不给出对应的实参或给出部分实参, 相当于使用默认值或部分使用默认值
- **默认值的形参必须从右至左提供, 有形参的必须在最后**
  - 调用时实参为连续排列
- 函数原型中, 可省略形参名字, 只给出类型和默认值



### 五、引用和函数参数的传递

- 引用的定义

  - 变量的别名, 对应同一个内存地址

- 引用的定义格式

  - `类型名 &引用名 = 同类型的某变量名`

  - ```C++
    int oneInt;
    int &aname = oneInt; //声明引用, aname 是引用名
    ```

- 引用的规则

  - 只能引用已经初始化的变量

  - 不能用常量初始化引用

  - 不能用表达式初始化引用, 除非表达式返回值是引用

  - 同一个变量可有多个引用

  - 可以在定义前加 const 表示 “常引用”

    -  `int oneInt; const int &cname = oneInt;`

    - 不能通过常引用修改其引用的变量, 普通引用可以修改变量的值

    - 变量可以初始化常量(常引用), 常量(常引用)不能初始化变量

- 类型转换:

  ```C++
  const int cInt = 30;
  const int & rc1 = cInt; //CT&←CT, CT& 表示类型 T 的常引用
  int &r2 = (int &) rc1; //T&←CT& 强制类型转换
  int &r3 = (int &) cInt; //T&←CT 强制类型换换
  ```

  - T 表示类型
  - CT 表示常量类型
  - T& 表示 T 类型的引用
  - CT& 表示 T 类型的常引用
  
- 引用在函数中使用

  - 作为函数的参数, 也可作为函数的返回值
  
  - 函数参数的传递方式
    
    - 传值: 传递对象的值
  - 传引用: 传递对象的首地址(等同于指针)
  
    ```C++
    #include <iostream>
    using namespace std;
    void SwapValue(int a, int b) //形参
    {
      int tmp;
      tmp = a;
      a = b;
      b = tmp;
      cout << "在SwapValue()函数中:\t\ta=" << a << ", b=" << b << endl;
      return;
    }
    void SwapRef(int &a, int &b) //a,b 实参引用地址的值互换
    {
      int tmp;
      tmp = a;
      a = b;
      b = tmp;
      cout << "在SwapRef()函数中:\t\ta=" << a << ", b=" << b << endl;
      return;
    }
    int main()
    {
      int a = 10;
      int b = 20;
      cout << "数据交换前:\t\ta=" << a << ", b=" << b << endl
           << endl;
      SwapValue(a, b);
      cout << "SwapValue后:\t\ta=" << a << ", b=" << b << endl
           << endl;
      a = 10;
      b = 20;
      SwapRef(a, b);
      cout << "SwapRef后:\t\ta=" << a << ", b=" << b << endl
           << endl;
      return 0;
    }
    ```
  ```
  
  - 引用作为函数的返回值
    
    - 赋值语句左边的叫左值, 右边的叫右值
      - 变量\指针\引用 可作左值
      - 表达式作右值
    - 格式
      - `数据类型 & 函数名(参数列表)`
    
    ```C++
    #include <iostream>
    using namespace std;
    int oneX = 10;
    int oneY = 20;
    int &refValue(int &x) //返回值是引用,可作左值
    {
      return x;
    }
    int main()
    {
      refValue(oneX) = 30;             //返回值是引用,可作左值
      cout << "oneX=" << oneX << endl; //输出 oneX=30
      refValue(oneY) = 40;             //返回值是引用的函数调用表达式,可作左值使用
      cout << "oneY=" << oneY << endl; //输出oneY=40
      return 0;
    }
  ```
  
    - 函数返回值也可以是指针
      - `类型标识符 * 函数名(实参列表)`



### 六、const 与指针共同使用

- const 修饰指针变量时
  - 唯一 const 位于符号 * 左侧, 表示指针所指数据为常量, 数据不能通过本指针改变, 但可以通过其它方式修改; 指针本身是变量, 可以指向其它内存单元
    - `const int *p = a`
  - 唯一 const 位于符号 * 右侧, 表示指针本身是常量, 不能改变指针指向, 数据可以通过本指针改变
    - `int * const p = a`
  - 在符号 * 左右各一个 const 时, 表示指针和所指数据都是常量, 都不能改变
    - `const int * const p = a`



### 七、内联函数

- 函数可以 减少程序代码, 实现代码共享, 提高开发效率和可维护性

- 在编译时内嵌到主函数中

  - 格式

    ```C++
    inline 返回值类型 函数名(形参表)
    {
    	函数体
    }
    ```

  - 只在声明函数原型时加 inline 不能内联, 看编译器的选择

  - 函数内有循环和 switch 语句时通常不定义内联函数, 复杂函数编译器依然会当做普通函数处理



### 八、函数的重载

- 程序的同一范围内声明几个功能类似的同名函数

  - ```C++
    int bigger(int a,int b){}
    float bigger(float a,float b){}
    double bigger(double a,double b){}
    ```

  - 参数**类型**或**个数**或**不同类型参数次序**不能相同

  - 函数名加上参数表称为 函数的签名

- 自动类型提升 

  - 不确定类型会自动转换

- 二义性

  - 参数个数不同, 多一个默认值时, 产生二义性



### 九、指针和动态内存分配

- 指针变量保存内存地址

- 动态内存分配

  - C++ 不允许定义不确定元素个数的数组

  - new 运算符实现动态内存分配

    - `p = new T;`

    - ```C++
      int *p;
      p = new int; // 分配4字节空间,p指向首地址
      *p = 5;
      ```

  - new 运算符实现动态分配任意大小的数组

    - `p = new T[N];`

    - ```C++
      int *pArray;
      int i = 5;
      pArray = new int[i*20]; // 分配100个元素的整型数组
      pArray[0] = 20;
      pArray[99] = 30;
      ```

  - 释放指针内存

    - 数组越界不会提示
    - `delete 指针`  指针指向分配了动态内存的指针
    - 释放错误时运行报错, 编译不报错

  - 释放数组内存

    - `delete[]指针`
    - 忘记 [] 时, 导致数组不完全释放

  - 使用 new 时, 一定要 delete 释放内存



### 十、用 string 对象处理字符串

- 使用 string

  - `#include<string>`

- 声明 string 对象

  - `string 变量名`

  - ```C++
    // 字符数组
    char name[] = "C++程序";
    string s1 = name;
    ```

  - ```C++
    // 对象数组
    string city[] = {"Beijing","Shanghai","Tianjin"};
    ```

  - `sizeof(对象/数组)` 元素个数

- string 对象操作

  - 不限长度相互赋值
  - 支持运算符(ASCII)
  - “+” 拼接字符串

- string 对象用法示例 

  | 函数                                                 | 功能                                                         |
  | ---------------------------------------------------- | ------------------------------------------------------------ |
  | `const char *c_str() const;`                         | 返回一个指向字符串的指针, 内容与原 string 相同, 用于转换为 const char * |
  | `int size() const;`                                  | 返回当前字符串大小                                           |
  | `int length() const;`                                | 返回当前字符串长度                                           |
  | `bool empty() const;`                                | 返回当前字符串是否为空                                       |
  | `size_type find(const char *str , size_type index);` | 返回 str 在字符串中第一次出现的位置, 从 index 开始查找, 没有返回-1 |
  | `size_type find( char ch , size_type index);`        | 返回 ch 在字符串中第一次出现的位置, 从 index 开始查找, 没有返回-1 |
  | `string &insert(int p, const string &s);`            | 在 p 位置插入字符串 s                                        |
  | `string &append(const char *s);`                     | 将字符串 s 拼接到当前字符串结尾                              |
  | `string substr(int pos=0, int n=npos) const;`        | 返回从 pos 开始的 n 个字符组成的字符串                       |

- 代码

  ```C++
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
    cout << "find:" << str.find("ad", 0) << endl;
    cout << "find:" << str.find("de", 4) << endl;
    string str1 = str.insert(4, "123");
    cout << str1 << endl;
    return 0;
  }
  ```

  



## 第三节 C++程序结构

- `.cpp` 文件格式

- 有且只有一个主函数 `main()` , 程序从主函数开始执行

- 主函数结束

  - 主函数中遇到 `return`
  - 执行到主函数后面 `}`

- 主函数可以调用其他函数, 其他函数不能调用主函数

- ```C++
  /* 
  多行注释
  多行注释
  */
  
  // 单行注释
  ```



# 第二章 面向对象的基本概念

- 结构化程序设计方法和局限性
- 面对对象程序设计，并对比结构化。理解抽象、封装、继承和多态
- 类定义方法，成员变量，成员函数
- 类定义中访问范围说明符
- 对象
- 指针，引用访问类成员的方法

## 第一节 结构化程序设计

- 将复杂功能模块化, 化繁为简, 从高层到底层 
- 三种基本控制结构: 顺序/选择/循环
  - 数据结构+算法=程序
- 复杂, 难以维护, 难以复用

## 第二节 面向对象程序设计的概念和特点

- 方法
  - 面向对象的分析, 面向对象的设计, 面向对象的程序设计
- 对象的特性
  - 状态: 对象本身的信息, 也叫属性
  - 行为: 对对象的操作, 也叫函数
- 类
  - 同一类对象的共同属性(静态特征)和行为(动态特征)
- 面对对象程序设计的特点
  - 抽象: 同类事物的共同特点概括出来
  - 封装: 对象的属性和操作结合, 对象的属性和操作隐藏, 只给出如何使用
  - 继承: 编写新类时, 以现有类为基础派生, 达到代码扩充和复用
  - 多态: 不同种类的对象都具有名字形同的行为, 而实现方式不同

## 第三节 类的初步知识

1. 类的定义

   - 基本数据类型

     - bool 布尔型
     - char 字符型
     - int 整型
     - float 浮点型
     - double 双精度浮点型

   - C++ 中类时用户自定义的数据类型

     - 先定义类型
     - 声明基本数据类型(对象)

   - 格式

     - ```C++
       class 类名
       {
       访问范围说明符:
       	成员变量1
       	成员变量2
       	...
       	成员函数声明1
       	成员函数声明2
       	...
       访问范围说明符:
       	更多成员变量
       	更多成员函数声明
       	...
       };
       ```

     - 类名不能重复

     - 类定义以“;”结束

     - 访问范围说明符: public(公有) private(私有) protected(保护)

   - 定义类时系统不分配内存, 而是把类看成模板

   - 类成员

     - 按功能划分: 成员变量和成员函数
       - 成员变量私有, 类外不可访问, 为每个成员变量定义一对访问函数, 设置函数和获取函数
       - 成员函数可以重载, 可以设定默认值
     - 按权限划分: 公有成员/私有成员/保护成员

   - 不属于任何类的函数: 全局函数

   - 在类外定义成员函数

     - inline 内联

     - 类内有函数原型

       ```C++
       返回值类型 类名::成员函数名(参数列表)
       {
       	成员函数的函数体
       }
       ```

2. 类的定义示例

   - myDate

     ```C++
     class myDate
     {
     public:
       myDate();                    //构造函数
       myDate(int, int, int);       //构造函数
       void setDate(int, int, int); //设置日期
       void setDate(myDate);        //设置日期
       myDate getDate();            //获取日期
       void setYear(int);           //设置年
       int getMonth();              //获取月
       void printDate() const;      //打印日期
     
     private:
       int year, month, day; //成员变量,年月日
     };
     //类体外定义成员函数
     myDate::myDate()
     {
       year = 1970, month = 1, day = 1;
     }
     myDate::myDate(int y, int m, int d)
     {
       year = y;
       month = m;
       day = d;
     }
     void myDate::setDate(int y, int m, int d)
     {
       year = y;
       month = m;
       day = d;
       return;
     }
     void myDate::setDate(myDate oneD)
     {
       year = oneD.year;
       month = oneD.month;
       day = oneD.day;
       return;
     }
     myDate myDate::getDate()
     {
       return *this;
     }
     void myDate::setYear(int y)
     {
       year = y;
       return;
     }
     int myDate::getMonth()
     {
       return month;
     }
     
     void myDate::printDate() const
     {
       cout << year << "/" << month << "/" << day;
       return;
     }
     ```

   - Student

     ```C++
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
     ```

     

## 第四节 类的示例程序剖析

1. 程序结构

   - 主函数
   - 类和全局函数
   - 全局说明
   - 注释
   - 头文件

2. 成员变量与成员函数的定义

3. 创建类对象的基本形式

   - 对象是类的实例

   - ```C++
     类名 对象名;
     类名 对象名(参数);
     类名 对象名 = 类名(参数);
     类名 对象名1, 对象名2,...;
     类名 对象名1(参数),对象名2(参数),...;
     ```

   - 用 new 创建对象时返回的是一个对象的指针, 必须用 delete 来撤销

     ```C++
     类名 *对象指针名 = new 类名;			 //成员变量不初始化
     类名 *对象指针名 = new 类名();    //成员变量初始化
     类名 *对象指针名 = new 类名(参数);
     ```

   - 声明对象引用, 即别名

     ```C++
     类名 &对象引用名 = 对象;
     类名 *对象指针名 = 对象的地址;
     类名 对象数组名[数组大小];
     ```

   - 同类型对象之间可以相互赋值, 对象和对象指针都可以用作函数参数, 函数返回值可以使对象或指针

     ```C++
     C a1, b1;   //定义了C类的对象a1,b1
     C *p = &a1; //指向对象a1的C类指针p
     C &R = b1;  //C类对象b1的引用R
     C A[3];     //C类对象的数组A,含三个元素
     ```



## 第五节 访问对象的成员

1. 使用对象访问成员变量与调用成员函数

   - 调用格式

     - `对象名.成员变量名`
     - `对象名.成员函数名(参数表)`

   - 验证 Student 的操作

     ```C++
     #include <iostream>
     #include <string>
     using namespace std;
     class myDate
     {
     public:
       myDate();                    //构造函数
       myDate(int, int, int);       //构造函数
       void setDate(int, int, int); //设置日期
       void setDate(myDate);        //设置日期
       myDate getDate();            //获取日期
       void setYear(int);           //设置年
       int getMonth();              //获取月
       void printDate() const;      //打印日期
     
     private:
       int year, month, day; //成员变量,年月日
     };
     //类体外定义成员函数
     myDate::myDate()
     {
       year = 1970, month = 1, day = 1;
     }
     myDate::myDate(int y, int m, int d)
     {
       year = y;
       month = m;
       day = d;
     }
     void myDate::setDate(int y, int m, int d)
     {
       year = y;
       month = m;
       day = d;
       return;
     }
     void myDate::setDate(myDate oneD)
     {
       year = oneD.year;
       month = oneD.month;
       day = oneD.day;
       return;
     }
     myDate myDate::getDate()
     {
       return *this;
     }
     void myDate::setYear(int y)
     {
       year = y;
       return;
     }
     int myDate::getMonth()
     {
       return month;
     }
     
     void myDate::printDate() const
     {
       cout << year << "/" << month << "/" << day;
       return;
     }
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
     int main()
     {
       Student ss;
       int y, m, d;
       string name_;
       cout << "请输入学生的姓名和生日, 生日以\"年 月 日\"的次序输入:";
       cin >> name_ >> y >> m >> d;
       ss.setStudent(name_, myDate(y, m, d));
       ss.printStudent();
       return 0;
     }
     ```

     

2. 使用指针访问对象的成员

   - 使用指针`对象.成员`  变成 `指针->成员`

3. 使用引用访问对象的成员

   - `引用.成员`



## 第六节 类成员的可访问范围

1. 访问范围说明符的含义
   - public: 公有, 任何地方可以访问
   - private: 私有, 仅能在本类中被访问
   - protected: 允许本类及子类中被访问
2. 成员的访问
   - 代码略
3. 隐藏的作用
   - 有利于程序修改, 避免错误

## 第七节 标识符的作用域与可见性

1. 函数原型作用域
   - 最小的作用域, 例如: 形参
2. 局部作用域
   - 一对大括号括起来的的一段程序,称为块
   - 块内作用域称为局部作用域, 变量叫局部变量
3. 类作用域
   - 类成员访问类成员的作用域
4. 命名空间作用域
   - 定义一个命名空间, 该命名空间之内声明的,不属于前面各个作用域的标识符, 都属于该命名空间作用域
   - 在不同的作用域声明的标识符, 可见性的一般原则:
     - 标识符声明在前, 引用在后
     - 同一份作用域中, 不能声明同名的标识符; 不同作用域可以声明同名标识符
     - 包含关系的作用域中, 外层对内层可见; **如果内层声明了同名标识符, 则外层对内层标识符不可见**, 称为隐藏规则



# 第三章 类和对象进阶

- 构造函数、析构函数、复制构造函数
- 特殊成员，包括静态成员、常量成员、常引用成员
- 类成员的生存期及作用域
- 封闭类的概念，定义封闭类
- 友元函数
- this 指针

## 第一节 构造函数

1. 构造函数的作用

   - 对象初始化, 成员变量赋初值

2. 构造函数的定义

   - 构造函数与类名相同, 无返回值, 一个类可以有多个构造函数(参数不能相同), 允许重载

   - `类名(形参1,形参2,...形参n);`

   - ```C++
     // 类外定义构造函数
     // 成员变量 x1,x2,...,xn;
     // 形式1
     类名::类名(形参1,形参2,...形参n):x1(形参1),x2(形参2),...,xn(形参n){}
     
     // 形式2
     类名::类名(形参1,形参2,...,形参n)
     {
       x1 = 形参1;
       x2 = 形参2;
       ...
       xn = 形参n;
     }
     
     // 形式3
     类名::类名()
     {
     	x1 = 初始化表达值1;
     	x2 = 初始化表达值2;
     	...
     	xn = 初始化表达值n;
     }
     ```

     

3. 构造函数的使用

   - 创建对象时根据调用语句中所带实参数量确定使用哪个构造函数

   - 使用 new 创建对象指针

     - `myDate *p = new myDate;` 括号可加可不加
     - 加括号, 系统分配内存时初始化为 0
     - 不加括号时, 只分配内存, 不初始化(随机值)

   - 声明对象数组, 每一个元素都是对象, 一定要定义无参构造函数来初始化

     - 特例, 声明数组时给各元素赋初值, 不用无参构造函数

   - ```C++
     int main()
     {
       Student stud;
       stud.printStudent();                           //输出默认值
       stud.setName("111");                           //姓名改为111
       stud.printStudent();                           //输出修改后的值 111
       Student *spointer[2] = {new Student(), &stud}; //初始化
       Student sy[2] = {Student(), stud};             //初始化 分配新的内存地址
       for (int i = 0; i < 2; i++)                    //使用指针输出指针指向的对象的值
         spointer[i]->printStudent();                 //姓名111
       for (int i = 0; i < 2; i++)                    //使用点运算符输出各值
         sy[i].printStudent();                        //姓名111
       stud.setName("222");                           //姓名222
       for (int i = 0; i < 2; i++)                    //sp[1]指向的对象的值改变
         spointer[i]->printStudent();                 //姓名222
       spointer[0]->setName("333");                   //影响student的值
       spointer[1]->setName("444");                   //影响stud的值
       for (int i = 0; i < 2; i++)                    //指向对象的值都改变
         spointer[i]->printStudent();                 // 姓名444
       stud.printStudent();                           //值变成 姓名444 生日1970
       for (int i = 0; i < 2; i++)
         sy[i].printStudent(); //值不变
       // 姓名NoName 生日1970
       // 姓名111 生日1970
       return 0;
     }
     ```

     

4. 复制构造函数与类型转换构造函数

   - 使用已有对象来建立一个新对象

   - 复制构造函数总是存在的

   - 格式

     - ```C++
       class 类名
       {
       public:
       	类名(参数表);				//构造函数
       	类名(类名 & 对象名);	 //复制构造函数
       	...
       };
       类名::类名(类名 & 对象名) //复制构造函数的实现
       {
       	函数体
       }
       ```

   - ```C++
     #include <iostream>
     #include <string>
     using namespace std;
     class myDate
     {
     public:
       myDate();                    //构造函数
       myDate(int, int, int);       //构造函数
       void setDate(int, int, int); //设置日期
       void setDate(myDate);        //设置日期
       myDate getDate();            //获取日期
       void setYear(int);           //设置年
       int getMonth();              //获取月
       void printDate() const;      //打印日期
     
     private:
       int year, month, day; //成员变量,年月日
     };
     //类体外定义成员函数
     myDate::myDate()
     {
       year = 1970, month = 1, day = 1;
     }
     myDate::myDate(int y, int m, int d)
     {
       year = y;
       month = m;
       day = d;
     }
     void myDate::setDate(int y, int m, int d)
     {
       year = y;
       month = m;
       day = d;
       return;
     }
     void myDate::setDate(myDate oneD)
     {
       year = oneD.year;
       month = oneD.month;
       day = oneD.day;
       return;
     }
     myDate myDate::getDate()
     {
       return *this;
     }
     void myDate::setYear(int y)
     {
       year = y;
       return;
     }
     int myDate::getMonth()
     {
       return month;
     }
     
     void myDate::printDate() const
     {
       cout << year << "/" << month << "/" << day;
       return;
     }
     
     class Student
     {
     public:
       Student();                       //构造函数,无参数
       Student(string);                 //构造函数,带一个参数
       void setStudent(string, myDate); //设置学生信息
       void setName(string);            //设置姓名
       string getName();                //获取姓名
       void setBirthday(myDate);        //设置生日
       myDate getBirthday();            //获取生日
       void printStudent() const;       //打印信息
       Student(const Student &s);       //声明复制构造函数
     
     private:
       string name;     //姓名
       myDate birthday; //生日
     };
     
     //定义构造函数
     Student::Student() : name("NoName"), birthday(myDate()){};  //添加,不带参数
     Student::Student(string n) : name(n), birthday(myDate()){}; //添加,带一个参数
     
     //类体外定义成员函数
     Student::Student(const Student &s) //自定义复制构造函数
     {
       name = "Copy" + s.name;
       birthday = s.birthday;
     }
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
     
     int main()
     {
       Student stud;
       stud.setName("444"); //姓名改为444
       Student ss[2] = {stud, Student()};
       stud.printStudent();
       stud.setName("111");
       ss[0] = Student(stud); //调用复制构造函数
       ss[1] = Student();
       stud.printStudent();
       ss[0].printStudent(); //姓名 Copy111
       ss[1].printStudent(); //默认新对象
       return 0;
     }
     ```

   - 自动调用复制函数的三种情况

     1. 用一个对象去初始化本类另一个对象

        ```C++
        类名 对象名2(对象名1);
        类名 对象名2 = 对象名1;
        ```

     2. 函数F 的参数是类A 的对象, 调用F 时, 会调用类 A 的复制构造函数

     3. 函数返回值是类A 的对象, 函数返回时会调用类 A 的复制构造函数

     注意: 复制构造函数的参数表中加上 const

   **类型转换构造函数**

   - 如果构造函数只有一个参数, 则可以看做类型转换构造函数, 作用是进行类型自动转换

   - ```C++
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
     ```

     

## 第二节 析构函数

- 成员函数的一种

  - 名字与类名相同
  - 类名前加 `~`
  - 无参数, 无返回值
  - 一个类仅有一个
  - 没有定义则自动生成

- 用于释放内存

- 对象数组与 delete 语句

  ```C++
  Student *ss = new Student[2];
  delete []ss;
  ```

- 指针数组与 delete 语句

  ```C++
  Student *ss[2] = {new Student(),new Student()};
  delete ss[0];
  delete ss[1];
  ```

- 程序填空题

  ```C++
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
  ```

  

## 第三节 类的静态成员

1. 静态变量

   - static 

     - 静态全局变量
     - 静态局部变量

   - 拥有全局生命周期, 初始值为0

   - 自动变量和静态变量的使用

     ```C++
     #include <iostream>
     #include <string>
     using namespace std;
     static int glos = 100;
     void f()
     {
       int a = 1;
       static int fs = 1;
       cout << "在f中:a(自动变量)=" << a << " fs(静态)" << fs << " glos(静态)=" << glos << endl;
       a += 2;
       fs += 2;
       glos += 10;
       cout << "在f中:a(自动变量)=" << a << " fs(静态)" << fs << " glos(静态)=" << glos << endl
            << endl;
     }
     int main()
     {
       static int ms = 10;
       for (int i = 1; i <= 3; i++)
         f();
       cout << "ms=" << ms << endl;
       cout << "glos=" << glos << endl;
       return 0;
     }
     ```

     

2. 类的静态成员

   - 静态成员变量

     - 在类定义中声明静态成员变量, 必须在类外定义成员静态变量的初值
     - `类型 类名::静态成员变量 = 初值;` 前面不加 static 

   - 静态成员函数

     - 类的静态成员函数没有 this 指针, 不能再静态成员函数内访问非静态成员
     - **静态成员函数只能处理静态成员变量**

   - 类的静态成员被类的所有成员共享

   - 访问静态成员

     - `类名::静态成员名`
     - `对象名.静态成员名`
     - `对象指针->静态成员名`

   - 静态成员的使用

     - ```
       
       ```

       

   - 程序填空题

     - ```C++
       #include <iostream>
       #include <string>
       using namespace std;
       class Test
       {
       public:
         static int x;
         Test(int i = 10)
         {
           x = i + x;
         }
         int Getnum()
         {
           return Test::x + 7;
         }
       };
       int Test::x = 83;
       int main()
       {
         Test test;
         cout << test.Getnum() << endl;
         return 0;
       }
       ```

       

## 第四节 变量及对象的生存期和作用域

1. 变量的生存期和作用域

   - 生存期

     - 分配内存到释放内存

   - 作用域

     -  变量的有效范围
     - 全局域
       - 程序作用域
         - 多文件作用域, extern 说明的外部变量和外部函数
       - 文件作用域
         - 单文件作用域, 文件内函数外的变量/函数
     - 局部域
       - 类作用域
       - 函数作用域
       - 块作用域
       - 函数原型作用域
         - 不是定义函数, 而是声明函数, 函数原型形参作用域只在声明中
         - 所以通常只要声明形参的个数和类型, 省略参数名

   - 程序中出现的左右标识符都必须说明

     ```
     
     ```

     

2. 类对象的生存期和作用域

   - 类对象生成时调用构造函数, 销毁时调用析构函数
   - 作用域越大的越晚销毁



## 第五节 常量成员和常引用成员

- 使用 const 修饰的量称为常量

  - 常量函数
  - 常量对象
  - 常量成员变量

- 格式

  - 常量对象/常量成员变量
    - `const 数据类型 常量名 = 表达式;`
  - 常量函数
    - `类型说明符 函数名(参数表) const;`

- 都可以调用静态成员函数

  - 常量成员变量及常量成员函数的使用

    ```C++
    #include <iostream>
    #include <string>
    using namespace std;
    class constClass
    {
      const int conMbr; //类中的常量成员变量
      int Mbr;          //普通成员变量
    
    public:
      constClass() : conMbr(0), Mbr(100) {} //初始化列表处给初始值
      constClass(int i) : conMbr(i)         //初始化列表处给初始值
      {
        Mbr = 200;
      }
      void printConst()
      {
        cout << "conMbr=" << conMbr << ",Mbr" << Mbr << endl;
      }
      int getConst()
      {
        cout << "调用非常量函数" << endl;
        return conMbr;
      }
      int getConst() const
      {
        cout << "调用常量函数" << endl;
        return conMbr;
      }
      int getValue()
      {
        return Mbr;
      }
      void processConst()
      {
        cout << "--在processConst函数中 非常量--" << endl;
        int x = 2 * conMbr + 1;
        cout << "x=2*conMbr+1=" << x << endl; //可以读取 conMbr
        //conMbr++; //错误, 不能更改常量成员变量 conMbr的值
        Mbr++; //可以修改非常量成员 Mbr的值
        cout << "Mbr=" << Mbr << endl;
      }
      void processConst() const
      {
        cout << "--在processConst函数中 常量--" << endl;
        int x = conMbr + 1;
        cout << "x=conMbr+1=" << x << endl; //可以读取 conMbr
        //conMbr++; //错误, 不能更改常量成员变量 conMbr的值
        // Mbr++; //不能修改非常量成员 Mbr的值
        cout << "Mbr=" << Mbr << endl;
      }
    };
    
    int main()
    {
      constClass ob1(123), ob2;
      ob1.printConst();
      cout << "ob2.getConst()=" << ob2.getConst() << endl;
      ob2.processConst();
      const constClass ob3(20);
      cout << "ob3.getConst()=" << ob3.getConst() << endl;
      ob3.processConst();
      return 0;
    }
    ```

    



## 第六节 成员对象和封闭类

- 一个类的成员变量如果是另一个类的对象, 称该变量为“成员对象”, 这两个类为**包含关系**; 包含成员对象的类叫做封闭类

1. 封闭类构造函数和初始化列表

   - 定义封闭类的的构造函数时, 需要添加初始化列表, 指明要调用成员对象的那个构造函数
   - 先执行成员变量的构造函数; 销毁时先执行封闭类析构函数, 在执行成员对象的析构函数
   - 添加初始化列表格式
     - `封闭类名::构造函数名(参数表):成员变量1(参数表),成员变量2(参数表),... {...}`

2. **封闭类的复制构造函数**

   - 如果封闭类的**对象是用默认复制构造函数初始化**的, 那么它**包含的成员对象**也会用复制构造函数初始化

   - ```C++
     #include <iostream>
     using namespace std;
     class A
     {
     public:
       A()
       {
         cout << "default" << endl;
       }
       A(A &a)
       {
         cout << "copy" << endl;
       }
     };
     
     class B
     {
       A a;
     };
     
     main()
     {
       B b1, b2(b1);
       return 0;
     }
     ```

     



## 第七节 友元

1. 友元

   -  兼顾C 语言程序设计的习惯与 C++ 信息隐藏的特点, 而增加的功能
   - 是一种类成员的访问权限
     - 破坏了类的封装性和信息隐藏, 但有助于数据共享, 能够提高程序运行效率
   - `friend`

2. 友元函数

   - 全局函数声明为本类友元函数的格式如下

     - `friend 返回值类型 函数名(参数表);`

   - 有某类A 定义后, 将类 A 的成员函数说明为友元函数的格式如下

     - `friend 返回值类型 类A::类A的成员函数名(参数名);`
     - 不能把其他类的私有成员函数声明为友元函数

   - 友元函数不是类的成员函数,但允许访问类的所有成员

     - 在函数体中访问对象成员
       - `对象名.对象成员名`
     - 不受访问权限关键词限制

   - 类成员函数实现复数类操作

     - ```
       
       ```

   - 友元函数实现复数操作

     - ```
       
       ```

       

3. 友元类

   - `friend class 类名;`

   - 类友元关系是单向的, 不能传递, 非必要时不用类友元

   - 类友元示例

     - ```
       
       ```

   - 程序填空题

     - ```C++
       #include <iostream>
       #include <cmath>
       using namespace std;
       class Point
       {
       private:
         double x, y;
         friend class Line;
       
       public:
         Point(double i = 0, double j = 0)
         {
           x = i;
           y = j;
         }
         Point(Point &p)
         {
           x = p.x;
           y = p.y;
         }
       };
       
       class Line
       {
       private:
         Point p1, p2;
       
       public:
         Line(Point &xp1, Point &xp2) : p1(xp1), p2(xp2) {}
         double GetLength();
       };
       
       double Line::GetLength()
       {
         double dx = p2.x - p1.x;
         double dy = p2.y - p1.y;
         return sqrt(dx * dx + dy * dy);
       }
       
       main()
       {
         Point p1, p2(6, 8);
         Line L1(p1, p2);
         cout << L1.GetLength() << endl;
         return 0;
       }
       ```

       



## 第八节 this 指针

- 被调用函数的内存首地址

- 指向对象

  - `this ->成员变量 = 形参;`

- this 指针的使用

  - ```
    
    ```

    



# 第四章 运算符重载

- 运算重载符
- 运算重载符作为成员函数和友元函数的两种方式
- 对自己定义的类重载运算符
- 对特定类重载前置和后置异同
- 浅拷贝和深拷贝

## 第一节 运算符重载的概念

1. 重载运算符的概念
2. 重载运算符为类的成员函数
3. 重载运算符为友元函数
4. 重载运算符的规则

## 第二节 重载赋值运算符

1. 重载赋值运算符
2. 浅拷贝和深拷贝

## 第三节 重载流插入运算符和流提取运算符

- 

## 第四节 重载强制类型转换运算符 (重要)

- 

## 第五节 重载自增、自建运算符



# 第五章 类的继承与派生

- 类的继承与派生
- 继承关系中友元和静态成员变量的派生特点
- 单重继承与多重继承，派生层次
- 权限控制符，基类和派生类之间的访问形式
- 派生类的构造函数和析构函数
- 类之间的关系
- 类与派生类指针

## 第一节 类的继承与类的派生

1. 继承的概念
2. 派生类的定义与大小
3. 继承关系的特殊性
4. 有继承关系的类之间的访问
5. protected 访问范围说明符
6. 多重继承

## 第二节 访问控制

1. 公有控制
2. 类型兼容规则
3. 私有继承

## 第三节 派生类的构造函数和析构函数

1. 构造函数与析构函数
2. 复制构造函数
3. 多重继承的构造函数与析构函数

## 第四节 类之间的关系

1. 类与类之间的关系
2. 封闭类的派生
3. 互包含关系的类

## 第五节 多层次的派生

- 

## 第六节 基类与派生类指针的相互转换

- 



# 第六章 多态与虚函数

- 多态原理
- 虚析构函数
- 纯虚函数

## 第一节 多态的基本概念

1. 多态
2. 虚函数
3. 通过基类指针实现多态
4. 通过基类引用实现多态
5. **多态的实现原理**

## 第二节 多态实例

- 

## 第三节 多态的使用

- 

## 第四节 虚析构函数

- 

## 第五节 纯虚函数和抽象类

1. 纯虚函数
2. 抽象类
3. 虚基类



# 第七章 输入/输出流

- cin cout 重定向
- 格式控制
- 常见成员函数

## 第一节 流类简介

- 

## 第二节 标准流对象

- 

## 第三节 控制 IO 格式

1. 流操纵符
2. 标志字

## 第四节 调用 cout 的成员函数

- 

## 第五节 调用 cin 的成员函数

1. `get()` 函数
2. `getline()` 函数
3. `eof()` 函数
4. `ignore()` 函数
5. `peek()` 函数



# 第八章 文件操作

- 文件
- ifstream、ofstream、fstream
- 顺序访问和随机访问，文件读写指针和移动文件指针

## 第一节 文件基本概念和文件流类

1. 文件的概念
2. C++ 文件流类

## 第二节 打开和关闭文件

1. 打开文件
2. 关闭文件

## 第三节 文件读写操作

1. 读写文本文件
2. 读写二进制文件 
3. 用成员函数 `put()` 和 `get()` 读写文件
4. 文本文件与二进制文件的异同

## 第四节 随机访问文件

- 



# 第九章 函数模板与类模板

- 函数模板
- 类模板
- 模板与继承

## 第一节 函数模板

1. 函数模板概念
2. 函数模板示例
3. 函数或函数模板调用语句的匹配顺序

## 第二节 类模板

1. 类模板概念
2. 类模板示例
3. 类模板与继承



