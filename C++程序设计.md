> **计算机信息管理专业课程**
>
> 自考笔记在线更新地址 : https://github.com/Eished/self-study-exam_notes

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

  - 配置文件在附录

  - VScode 执行完会自动关闭终端, return 前设置断点

    - 或者修改 `launch.json` 文件为  `"externalConsole": false,`
    - 内置终端支持 utf-8

  - 使用外置终端，utf-8 中文乱码问题, 在 vs code 修改代码的打开和保存方式

    直接就将代码保存为 gb2312。在 vs code 右下角可以看到当前文件编码方式，点击utf-8 修改打开和保存方式为 gb2312。

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
  - `void` 声明无返回值
  - 默认值不能是局部变量，调用函数可以用局部变量
- 调用的函数有默认值的函数时, 可以不给出对应的实参或给出部分实参, 相当于使用默认值或部分使用默认值
- **默认值的形参必须从右至左提供, 有形参的必须在最后**
  - 调用时实参为从左至右连续排列，不给则后面取默认值
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
  - 唯一 `const` 位于符号 `*` 左侧, 表示指针所指数据为常量, 数据不能通过本指针改变, 但可以通过其它方式修改; 指针本身是变量, 可以指向其它内存单元
    
    - `const int *p = a`
  - 唯一 const 位于符号 * 右侧, 表示指针本身是常量, 不能改变指针指向, 数据可以通过本指针改变
    
    - `int * const p = a`
  - 在符号 * 左右各一个 const 时, 表示指针和所指数据都是常量, 都不能改变
    
    - `const int * const p = a`
    
  - > 调用时变量前加 "&" -------返回该变量的地址
    >
    > 声明时变量前加 "基本类型 *" -------该指针变量表示另一个普通变量的地址  eg:int * 或 char *
    >
    > 调用时变量前加 "*"-------表示取该地址的内容
    >
    > 声明时变量前加 "基本类型 **"-------该二级指针变量表示另一个一级"基本类型 *"指针变量地址  



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
  
    - ```C++
      #include <iostream>
      using namespace std;
      int *A = new int[5];
      int main()
      {
        for (int i = 0; i < 5; i++)
        {
          A[i] = i + 1;
          cout << A[i] << endl;
        }
        // delete[] A;
        delete A;
        for (int i = 0; i < 5; i++)
        {
          cout << A[i] << endl;
        }
        return 0;
      }
      ```
  
      



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

- `string` 对象用法示例 

  | 函数                                                 | 功能                                                         |
  | ---------------------------------------------------- | ------------------------------------------------------------ |
  | `const char *c_str() const;`                         | 返回一个指向字符串的指针, 内容与原 string 相同, 用于转换为 `const char *` |
  | `int size() const;`                                  | 返回当前字符串大小                                           |
  | `int length() const;`                                | 返回当前字符串长度                                           |
  | `bool empty() const;`                                | 返回当前字符串是否为空                                       |
  | `size_type find(const char *str , size_type index);` | 返回 `str` 在字符串中第一次出现的位置, 从 `index` 开始查找, 没有返回-1 |
  | `size_type find( char ch , size_type index);`        | 返回 `ch` 在字符串中第一次出现的位置, 从 `index` 开始查找, 没有返回-1 |
  | `string &insert(int p, const string &s);`            | 在 `p` 位置插入字符串 s                                      |
  | `string &append(const char *s);`                     | 将字符串 `s` 拼接到当前字符串结尾                            |
  | `string substr(int pos=0, int n=npos) const;`        | 返回从 `pos` 开始的 `n` 个字符组成的字符串                   |

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
   - `public`: 公有, 任何地方可以访问
   - `private`: 私有, 仅能在本类中被访问
   - `protected`: 允许本类及子类中被访问
2. 成员的访问
   
   - 代码略
3. 隐藏的作用
   
   - 有利于程序修改, 避免错误
   
   

## 第七节 标识符的作用域与可见性

1. 函数原型作用域
   - **最小的作用域**, 例如: 形参
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

     

4. **复制构造函数与类型转换构造函数**

   - 使用已有对象来建立一个新对象

     - 复制构造函数参数类型是本类的引用
     - 复制构造函数总是存在的
     - 只有一个参数，形参是本类对象的引用

   - 对于类 A ，复制构造函数的原型如下

     - `A::A(const A&);`
     - `A::A(A&);`

   - 声明和实现复制构造函数的格式

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

   - 调用复制构造函数
     
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

   注意: 复制构造函数的参数表中加上 const 更好

   

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
  - 无参数, 无返回值，不能重载
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

     - 在类定义中声明静态成员变量, **必须在类外定义成员静态变量的初值**
     - `类型 类名::静态成员变量 = 初值;` 前面不加 static 

   - 静态成员函数

     - 类的静态成员函数没有 this 指针, 不能在静态成员函数内访问非静态成员
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

   - 重名标识符，不同作用域允许重名

     1. 无包含关系，互不影响
     2. 有包含关系，在哪定义在哪有效
     

2. 类对象的生存期和作用域

   - 类对象生成时调用构造函数, 销毁时调用析构函数
   - 作用域越大的越晚销毁



## 第五节 常量成员和常引用成员

- 使用 const 修饰的量称为常量

  - 常量函数
  - 常量对象
  - 常量成员变量
    - 必须在构造函数的初始化列表中初始化

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

   - 定义封闭类的的构造函数时, 需要添加**初始化列表**, 指明要调用成员对象的那个构造函数
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
     
     int main()
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

     - ```C++
       #include <iostream>
       using namespace std;
       class myComplex //复数类
       {
       private:
         double real, imag; //复数的实部和虚部
       public:
         myComplex();
         myComplex(double r, double i);
         myComplex addCom(myComplex c); //成员函数, 调用者对象与参数对象c相加
         void outCom();                 //成员函数, 输出调用者对象的有关数据
       };
       myComplex::myComplex(double r, double i)
       {
         real = r;
         imag = i;
       }
       myComplex::myComplex()
       {
         real = 0;
         imag = 0;
       }
       myComplex myComplex::addCom(myComplex c)
       {
         return myComplex(real + c.real, imag + c.imag);
       }
       void myComplex::outCom()
       {
         cout << "(" << real << "," << imag << ")";
       }
       
       int main()
       {
         myComplex c1(1, 2), c2(3, 4), res;
         res = c1.addCom(c2); //调用成员函数必须通过类对象
         c1.outCom();
         cout << "+";
         c2.outCom();
         cout << "=";
         res.outCom();
         cout << endl;
         return 0;
       }
       ```

   - 友元函数实现复数操作

     - ```C++
       #include <iostream>
       using namespace std;
       class myComplex //复数类
       {
       private:
         double real, imag; //复数的实部和虚部
       public:
         myComplex();
         myComplex(double r, double i);
         friend myComplex addCom(myComplex c1, myComplex c2); //友元函数, 两个参数对象相加
         friend void outCom(myComplex c);                     //友元函数, 输惨参数对象数据
       };
       myComplex::myComplex(double r, double i)
       {
         real = r;
         imag = i;
       }
       myComplex::myComplex()
       {
         real = 0;
         imag = 0;
       }
       myComplex addCom(myComplex c1, myComplex c2) //定义函数
       {
         return myComplex(c1.real + c2.real, c1.imag + c2.imag);
       }
       void outCom(myComplex c) //定义函数
       {
         cout << "(" << c.real << "," << c.imag << ")";
       }
       
       int main()
       {
         myComplex c1(1, 2), c2(3, 4), res;
         res = addCom(c1, c2); //调用成员函数必须通过类对象
         outCom(c1);
         cout << "+";
         outCom(c2);
         cout << "=";
         outCom(res);
         cout << endl;
         return 0;
       }
       ```

       

3. 友元类

   - `friend class 类名;`

   - 类友元关系是单向的, 不能传递, 非必要时不用类友元

   - 类友元示例

     - ```C++
       #include <iostream>
       using namespace std;
       class myComplex //复数类
       {
       private:
         double real, imag; //复数的实部和虚部
       public:
         myComplex();
         myComplex(double r, double i);
         friend class oper; //友元类
       };
       myComplex::myComplex(double r, double i)
       {
         real = r;
         imag = i;
       }
       myComplex::myComplex()
       {
         real = 0;
         imag = 0;
       }
       class oper
       {
       public:
         myComplex addCom(myComplex c1, myComplex c2); //友元函数, 两个参数对象相加
         void outCom(myComplex c);                     //友元函数, 输惨参数对象数据
       };
       myComplex oper::addCom(myComplex c1, myComplex c2) //定义函数
       {
         return myComplex(c1.real + c2.real, c1.imag + c2.imag);
       }
       void oper::outCom(myComplex c) //定义函数
       {
         cout << "(" << c.real << "," << c.imag << ")";
       }
       
       int main()
       {
         myComplex c1(1, 2), c2(3, 4), res;
         oper o;
         res = o.addCom(c1, c2); //调用成员函数必须通过类对象
         o.outCom(c1);
         cout << "+";
         o.outCom(c2);
         cout << "=";
         o.outCom(res);
         cout << endl;
         return 0;
       }
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
       
       int main()
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

  - 每个当前对象都含有一个指向该对象的this指针，
  - `this`指针只能在类的成员函数中使用，
  - 其中静态成员函数不能够有this指针。
  - `this ->成员变量 = 形参;`

- this 指针的使用

  - ```C++
    #include <iostream>
    using namespace std;
    class myComplex
    {
    public:
      double real, imag;
      myComplex() : real(0), imag(0) {}
      myComplex(double, double);
      myComplex AddRealOne();
      myComplex AddImagOne();
      void outCom(); //成员函数, 输出调用者对象的有关数据
    };
    myComplex::myComplex(double real, double imag)
    {
      this->real = real;
      this->imag = imag;
    }
    void myComplex::outCom()
    {
      cout << "(" << real << "," << imag << ")";
    }
    myComplex myComplex::AddRealOne()
    {
      this->real++;
      return *this; // 返回对象本身
    }
    myComplex myComplex::AddImagOne()
    {
      this->imag++;
      return *this; // 返回对象本身
    }
    
    int main()
    {
      myComplex c1(1, 1), c2, c3;
      c1.outCom();
      c2.outCom();
      c3.outCom();
      cout << endl
           << "分界线" << endl;
      c2 = c1.AddRealOne();
      c1.outCom();
      c3 = c1.AddImagOne();
      c2.outCom();
      c3.outCom();
      cout << endl;
      return 0;
    }
    ```

    



# 第四章 运算符重载

- 运算重载符
- 运算重载符作为成员函数和友元函数的两种方式
- 对自己定义的类重载运算符
- 对特定类重载前置和后置异同
- 浅拷贝和深拷贝

## 第一节 运算符重载的概念

1. 重载运算符的概念

   - 已有的运算符赋予多重含义, 使同一个运算符作用于不同类型的数据时产生不同的行为

   - 可重载的运算符

     - | 运算符         | 举例                                                         |
       | -------------- | ------------------------------------------------------------ |
       | 双目算术运算符 | `+, -, *, /, %`                                              |
       | 关系运算符     | `==, !=, <, >, <=, >=`                                       |
       | 逻辑运算符     | `||, &&, !`                                                  |
       | 单目运算符     | `+(正), -(负), *(指针), &(取地址)`                           |
       | 自增自减运算符 | `++, --`                                                     |
       | 位运算符       | `|(按位或), &(按位与), ~(按位取反), ^(按位异或), <<(左移), >>(右移)` |
       | 赋值运算符     | `=, +=, -=, *=, /=, %=, &=(按位与赋值), |=(按位或赋值), ^=(按位异反赋值), <<=(左移赋值), >>=(右移赋值)` |
       | 空间申请与释放 | `new, delete, new[], delete[]`                               |
       | 其他运算符     | `()(函数调用), ->(成员访问), ,(逗号), [](下标)`              |

   - 不可重载的运算符和符号

     - | 成员访问运算符     | `.`            |
       | ------------------ | -------------- |
       | 成员指针访问运算符 | `.*`  , ` ->*` |
       | 域运算符           | `::`           |
       | 长度运算符         | `sizeof`       |
       | 条件运算符         | `?:`           |
       | 预处理符号         | `#`            |

   - 用于类运算的运算符通常都要重载, 系统提供了两个重载运算符

     - `=, &` 复制和地址

   - 运算符重载的实质是编写以运算符为名称的函数

     - 使用运算符的表达式就被解释为对重载函数的调用
     - `返回值类型 operator 运算符(形参表){函数体}`
     - 可以是全局函数, 成员函数

   

2. 重载运算符为类的成员函数

   - 使用重载运算符

     - ```C++
       #include <iostream>
       using namespace std;
       class myComplex //复数类
       {
       private:
         double real, imag; //复数的实部和虚部
       public:
         myComplex();
         myComplex(double r, double i);
         myComplex addCom(myComplex c);                                        //成员函数, 调用者对象与参数对象c相加
         void outCom();                                                        //成员函数, 输出调用者对象的有关数据
         myComplex operator-(const myComplex &c);                              //成员 重载函数
         friend myComplex operator+(const myComplex &c1, const myComplex &c2); //友元 重载函数
       };
       myComplex::myComplex(double r, double i)
       {
         real = r;
         imag = i;
       }
       myComplex::myComplex()
       {
         real = 0;
         imag = 0;
       }
       myComplex myComplex::addCom(myComplex c)
       {
         return myComplex(real + c.real, imag + c.imag);
       }
       void myComplex::outCom()
       {
         cout << "(" << real << "," << imag << ")";
       }
       myComplex myComplex::operator-(const myComplex &c)
       {
         return myComplex(this->real - c.real, this->imag - c.imag); //返回一个临时对象
       }
       myComplex operator+(const myComplex &c1, const myComplex &c2)
       {
         return myComplex(c1.real + c2.real, c1.imag + c2.imag); //返回一个临时对象
       }
       
       int main()
       {
         myComplex c1(1, 2), c2(3, 4), res;
         c1.outCom();
         cout << "operator+";
         c2.outCom();
         cout << "=";
         res = c1 + c2;
         res.outCom();
         cout << endl;
         c1.outCom();
         cout << "operator-";
         c2.outCom();
         cout << "=";
         res = c1 - c2;
         res.outCom();
         cout << endl;
         return 0;
       }
       ```

       

3. 重载运算符为友元函数

   - 重载运算符作为友元函数时, 两个操作参数都要列出

   - 重载作为友元函数

     - ```C++
       #include <iostream>
       using namespace std;
       class myComplex //复数类
       {
       private:
         double real, imag; //复数的实部和虚部
       public:
         myComplex();
         myComplex(double r, double i);
         myComplex addCom(myComplex c);                                        //成员函数, 调用者对象与参数对象c相加
         void outCom();                                                        //成员函数, 输出调用者对象的有关数据
         myComplex operator-(const myComplex &c);                              //成员 重载函数
         friend myComplex operator+(const myComplex &c1, const myComplex &c2); //友元 重载函数
         friend myComplex operator-(const myComplex &c1, const myComplex &c2); //友元 重载函数
         friend myComplex operator-(const myComplex &c1, double r);            //友元 重载函数
         friend myComplex operator-(double r, const myComplex &c1);            //友元 重载函数
       };
       myComplex::myComplex(double r, double i)
       {
         real = r;
         imag = i;
       }
       myComplex::myComplex()
       {
         real = 0;
         imag = 0;
       }
       myComplex myComplex::addCom(myComplex c)
       {
         return myComplex(real + c.real, imag + c.imag);
       }
       void myComplex::outCom()
       {
         cout << "(" << real << "," << imag << ")";
       }
       myComplex myComplex::operator-(const myComplex &c)
       {
         return myComplex(this->real - c.real, this->imag - c.imag); //返回一个临时对象
       }
       myComplex operator+(const myComplex &c1, const myComplex &c2) //c1+c2
       {
         return myComplex(c1.real + c2.real, c1.imag + c2.imag); //返回一个临时对象
       }
       myComplex operator-(const myComplex &c1, const myComplex &c2) //c1-c2
       {
         return myComplex(c1.real - c2.real, c1.imag - c2.imag); //返回一个临时对象
       }
       myComplex operator-(const myComplex &c1, double r) //c1-r
       {
         return myComplex(c1.real - r, c1.imag); //返回一个临时对象
       }
       myComplex operator-(double r, const myComplex &c1) //r-c1
       {
         return myComplex(r + c1.real, -c1.imag); //返回一个临时对象
       }
       
       int main()
       {
         myComplex c1(1, 2), c2(3, 4), res;
         c1.outCom();
         cout << "operator+";
         c2.outCom();
         cout << "=";
         res = c1 + c2;
         res.outCom();
         cout << endl;
         c1.outCom();
         cout << "operator-";
         c2.outCom();
         cout << "=";
         res = c1 - c2;
         res.outCom();
         cout << endl;
         res = c1 - c2;
         res.outCom();
         res = c1 - 5;
         res.outCom();
         res = 5 - c1;
         res.outCom();
         return 0;
       }
       ```

       

4. 重载运算符的规则

   1. 重载后含义应符合原有用法习惯
   2. **不能改变原有的语义, 包括优先级和结合性**
   3. **不能改变运算符操作的个数和语法结构**
   4. 不能创建新的运算符
   5. `(), [], ->, =` 只能重载为**成员函数**, 不能重载为全局函数
   6. 不能改变该运算符用于基本数据类型对象的含义



## 第二节 重载赋值运算符

1. 重载赋值运算符

   - `=` 只能重载为成员函数

   - 重载后被解释为函数调用的形式

     - `s1.operator = (s2);`

   - 为类 myComplex 重载赋值运算符

     - ```C++
       #include <iostream>
       using namespace std;
       class myComplex //复数类
       {
       private:
         double real, imag; //复数的实部和虚部
       public:
         myComplex();
         myComplex(double r, double i);
         ~myComplex() {}                                                       //不能有分号
         myComplex addCom(myComplex c1);                                       //成员函数, 调用者对象与参数对象c相加
         void outCom();                                                        //成员函数, 输出调用者对象的有关数据
         void outCom(string s);                                                //成员函数, 输出调用者对象的有关数据
         void changeReal(double r);                                            //成员函数
         myComplex operator-(const myComplex &c);                              //成员 重载函数
         friend myComplex operator+(const myComplex &c1, const myComplex &c2); //友元 重载函数 c1+c2
         friend myComplex operator+(const myComplex &c1, double r);            //友元 重载函数 c1+r
         friend myComplex operator+(double r, const myComplex &c1);            //友元 重载函数 r+c1
         friend myComplex operator-(const myComplex &c1, const myComplex &c2); //友元 重载函数
         friend myComplex operator-(const myComplex &c1, double r);            //友元 重载函数
         friend myComplex operator-(double r, const myComplex &c1);            //友元 重载函数
         myComplex &operator=(const myComplex &c);                             //成员函数
         myComplex &operator=(double);                                         //成员函数
       };
       myComplex::myComplex(double r, double i)
       {
         real = r;
         imag = i;
       }
       myComplex::myComplex()
       {
         real = 0;
         imag = 0;
       }
       myComplex myComplex::addCom(myComplex c1)
       {
         return myComplex(this->real + c1.real, this->imag + c1.imag);
       }
       void myComplex::outCom()
       {
         cout << "(" << real << "," << imag << ")";
       }
       void myComplex::outCom(string s)
       {
         cout << s << "(" << real << "," << imag << ")" << endl;
       }
       void myComplex::changeReal(double r)
       {
         this->real = r;
       }
       // myComplex myComplex::operator-(const myComplex &c)
       // {
       //   return myComplex(this->real - c.real, this->imag - c.imag); //返回一个临时对象
       // }
       myComplex operator+(const myComplex &c1, const myComplex &c2) //c1+c2
       {
         return myComplex(c1.real + c2.real, c1.imag + c2.imag); //返回一个临时对象
       }
       myComplex operator+(const myComplex &c1, double r) //c1+r
       {
         return myComplex(c1.real + r, c1.imag); //返回一个临时对象
       }
       myComplex operator+(double r, const myComplex &c1) //r+c2
       {
         return myComplex(r + c1.real, c1.imag); //返回一个临时对象
       }
       myComplex operator-(const myComplex &c1, const myComplex &c2) //c1-c2
       {
         return myComplex(c1.real - c2.real, c1.imag - c2.imag); //返回一个临时对象
       }
       myComplex operator-(const myComplex &c1, double r) //c1-r
       {
         return myComplex(c1.real - r, c1.imag); //返回一个临时对象
       }
       myComplex operator-(double r, const myComplex &c1) //r-c1
       {
         return myComplex(r + c1.real, -c1.imag); //返回一个临时对象
       }
       myComplex &myComplex::operator=(const myComplex &c1)
       {
         this->real = c1.real;
         this->imag = c1.imag;
         return *this;
       }
       myComplex &myComplex::operator=(double r)
       {
         this->real = r;
         this->imag = 0;
         return *this;
       }
       
       int main()
       {
         myComplex c1(1, 2), c2(3, 4), res;
         c1.outCom("\t\t\tc1");
         c2.outCom("\t\t\tc2");
         res = c1 + c2;
         res.outCom("执行 res = c1 + c2 →\tres");
         res = c1.addCom(c2);
         res.outCom("执行 res = c1.addCom(c2) →\tres");
         res = c1 + 5;
         res.outCom("执行 res = c1 + 5 →\tres");
         res = 5 + c1;
         res.outCom("执行 res = 5 + c1 →\tres");
         res = c1;
         c1.outCom("\t\t\tc1");
         res.outCom("执行 res = c1 →\tres");
         c1.changeReal(-3);
         c1.outCom("执行 changeReal(-3) →\tc1");
         res.outCom("\t\t\tres");
         res = c1;
         res.outCom("res = c1 →\tres");
         res = 7;
         res.outCom("res = 7 →\tres");
         res = 7 + 8;
         res.outCom("res = 7 + 8; →\tres");
         res = c1 = c2;
         c1.outCom("\t\t\tc1");
         c2.outCom("\t\t\tc2");
         res.outCom("res = c1 = c2 →\tres");
       
         return 0;
       }
       ```

       

2. 浅拷贝和深拷贝

   - 浅拷贝
     - 赋值号左侧对象的值一一赋值给左侧对象
     - 如果值得对象涉及指针或引用, 它们之间值相互关联, 因为指向同一个内存地址
   - 深拷贝
     - 重载赋值运算符后, 赋值语句是将一个对象中指针成员变量指向内容复制到另一个对象中指针成员变量指向的地方
     - `delete 指针;` 释放原指针的内存再保存到新的指针指向的内存地址



## 第三节 重载流插入运算符和流提取运算符

- 流插入运算符

  - 左移运算符 `<<` 和 `cout` 一起用于输出, 称为 “流插入运算符”

- 流提取运算符

  - 左移运算符 `>>` 和 `cin` 一起用于输出, 称为 “流插入运算符”

- C++ 类库提供的头文件对 `<<` `>>` 进行了重载

  - `cout <<` 是 `ostream` 的对象
  - `cin >>` 是 `istream` 的对象
  - 在头文件 `iostream` 中声明, 所以要用 `#include<iostream>`

- 重载流运算符

  - 操作符右边是流对象的别名, 不是操作对象

    - 运算符接在流对象后面, 直接访问类的私有数据
    - **流只能继承不能修改, 重载函数不能是流类库中的成员, 必须重载为类的友元**

  - 重载流插入运算符

    ```C++
    ostream &operator<<(ostream & output, 类名&对象名)
    {
    	... 
    	return output;
    }
    ```

  - 重载流提取运算符

    ```C++
    istream &operator>>(istream & input, 类名&对象名)
    {
    	... 
    	return input;
    }
    ```

    - `input`是 `istream` 对象的引用, 是 `cin`  的别名: `istream & input = cin;`

  - 流插入运算符和流提取运算符重载为友元

    - ```C++
      #include <iostream>
      #include <cstdlib>
      #include <string>
      using namespace std;
      class myComplex
      {
      private:
        double real, imag;
      
      public:
        myComplex() : real(0), imag(0) {}
        myComplex(double r, double i) : real(r), imag(i) {}
        friend ostream &operator<<(ostream &os, const myComplex &c); //友元,插入
        friend istream &operator>>(istream &is, myComplex &c);       //友元,提取
      };
      ostream &operator<<(ostream &os, const myComplex &c)
      {
        if (c.imag >= 0)
        {
          os << c.real << "+" << c.imag << "i"; //以 a+bi 的形式输入
        }
        else
        {
          os << c.real << "-" << -c.imag << "i";
        }
        return os;
      }
      istream &operator>>(istream &is, myComplex &c)
      {
        string s;
        is >> s;                  //将a+bi 作为字符串读入,a+bi中间不能有空格
        int pos = s.find("+", 0); //查找虚部
        if (pos == -1)
          pos = s.find("-", 1);                      //虚部为负数时
        string sReal = s.substr(0, pos);             //分离出代表实部的字符串
        c.real = atof(sReal.c_str());                //atof() 能将参数内容转换成浮点数
        sReal = s.substr(pos, s.length() - pos - 1); //分离出代表虚部的字符串
        c.imag = atof(sReal.c_str());
        return is;
      }
      int main()
      {
        myComplex c, c1;
        int n;
        cout << "请输入两个复数([-]a±bi)和一个整数, 以空格分隔" << endl;
        cin >> c >> c1 >> n;
        cout << c << "," << n << "," << c1;
        return 0;
      }
      ```

      

  - 流插入运算符重载为成员函数

    - ```C++
      #include <iostream>
      #include <cstdlib>
      #include <string>
      using namespace std;
      class myComplex
      {
      private:
        double real, imag;
      
      public:
        myComplex() : real(0), imag(0) {}
        myComplex(double r, double i) : real(r), imag(i) {}
        ostream &operator<<(ostream &os);                      //成员函数 ,插入
        friend istream &operator>>(istream &is, myComplex &c); //友元,提取
      };
      ostream &myComplex::operator<<(ostream &os)
      {
        if (this->imag >= 0)
        {
          os << this->real << "+" << this->imag << "i"; //以 a+bi 的形式输入
        }
        else
        {
          os << this->real << "-" << -this->imag << "i";
        }
        return os;
      }
      istream &operator>>(istream &is, myComplex &c)
      {
        string s;
        is >> s;                  //将a+bi 作为字符串读入,a+bi中间不能有空格
        int pos = s.find("+", 0); //查找虚部
        if (pos == -1)
          pos = s.find("-", 1);                      //虚部为负数时
        string sReal = s.substr(0, pos);             //分离出代表实部的字符串
        c.real = atof(sReal.c_str());                //atof() 能将参数内容转换成浮点数
        sReal = s.substr(pos, s.length() - pos - 1); //分离出代表虚部的字符串
        c.imag = atof(sReal.c_str());
        return is;
      }
      
      int main()
      {
        myComplex c, c1;
        int n;
        cout << "请输入两个复数([-]a±bi)和一个整数, 以空格分隔" << endl;
        cin >> c >> c1 >> n;
        c1 << (c << cout << ",") << "," << n; //注意调用形式
        return 0;
      }
      ```

      



## 第四节 重载强制类型转换运算符 (重要)

- 类的名字本身也是运算符, 强制类型转换运算符

  - 是单目运算符, 也可以重载, 但只能重载为成员函数, 不能重载为全局函数

  - `类型名 对象` 重载后等价于 `对象.operator 类型名()`

  - 重载强制类型转换运算符 `double`

    - ```C++
      #include <iostream>
      #include <cstdlib>
      #include <string>
      using namespace std;
      class myComplex
      {
      private:
        double real, imag;
      
      public:
        myComplex(double r = 0, double i = 0) : real(r), imag(i){}; //成员函数
        operator double()                                           //重载强制类型转换运算符 double
        {
          return real;
        }
      };
      
      int main()
      {
        myComplex c(1.2, -3.4);
        cout << (double)c << endl; // c.operator double() 输出1.2
        double n = 12 + c; //等价于 double n=12+c.operator double()
        cout << n;
        return 0;
      }
      ```

      



## 第五节 重载自增、自减运算符

- 有前置 后置之分

  - 允许写一个增加无用int 类型形参的版本, 处理前置时调用参数个数正常的重载函数
  - 处理后置 表达式时, 调用多出一个参数的重载函数
  - 前置 `++，--` 优先级高于赋值，后置自增自减运算优先级低于赋值

- 自增作为成员函数 自减作为友元

  - ```C++
    #include <iostream>
    using namespace std;
    class Demo
    {
    private:
      int n;
    
    public:
      Demo(int i = 0) : n(i) {}
      Demo &operator++();   //用于前置
      Demo operator++(int); //用于后置
      operator int() { return n; }
      friend Demo &operator--(Demo &);
      friend Demo operator--(Demo &, int);
    };
    Demo &Demo::operator++() //前置++
    {
      n++;
      return *this;
    }
    Demo Demo::operator++(int k) //后置++
    {
      Demo tmp(*this); //记录修改前的对象
      n++;
      return tmp; //返回修改前对象
    }
    Demo &operator--(Demo &d) //前置--
    {
      d.n--;
      return d;
    }
    Demo operator--(Demo &d, int) //后置--
    {
      Demo tmp(d);
      d.n--;
      return tmp;
    }
    int main()
    {
      Demo d(10);
      cout << (d++) << ","; // d.operator++(0)
      cout << d << ",";
      cout << (++d) << ","; // d.operator++()
      cout << d << ",";
      cout << (d--) << ","; // d.operator--(d,0)
      cout << d << ",";
      cout << (--d) << ","; // d.operator--(d)
      cout << d << ",";
      return 0;
    }
    ```

- 都作为成员函数

  - ```C++
    #include <iostream>
    using namespace std;
    class Demo
    {
    private:
      int n;
    
    public:
      Demo(int i = 0) : n(i) {}
      Demo &operator++();   //用于前置
      Demo operator++(int); //用于后置
      operator int() { return n; }
      Demo &operator--();
      Demo operator--(int);
    };
    Demo &Demo::operator++() //前置++
    {
      n++;
      return *this;
    }
    Demo Demo::operator++(int k) //后置++
    {
      Demo tmp(*this); //记录修改前的对象
      n++;
      return tmp; //返回修改前对象
    }
    Demo &Demo::operator--() //前置--
    {
      n--;
      return *this;
    }
    Demo Demo::operator--(int k) //后置--
    {
      Demo tmp(*this);
      n--;
      return tmp;
    }
    int main()
    {
      Demo d(10);
      cout << (d++) << ","; // d.operator++(0)
      cout << d << ",";
      cout << (++d) << ","; // d.operator++()
      cout << d << ",";
      cout << (d--) << ","; // d.operator--(d,0)
      cout << d << ",";
      cout << (--d) << ","; // d.operator--(d)
      cout << d << ",";
      return 0;
    }
    ```

    



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

   - 通过已有的类建立新类的过程, 叫做派生; 
     - 原来的类叫基类, 也叫父类或一般类;
     - 新类称为派生类/子类/特殊类
   - 除构造函数和析构函数外, 基类所有成员派生为子类成员
     
     - 子类中可以增加/修改成员和权限
   - 覆盖
     
     - 派生类成员覆盖基类同名成员, 也称为重定义/ 重写/ 同名隐藏
     
     

2. 派生类的定义与大小

   - 格式

     - ```C++
       class 派生类名:继承方式说明符 基类名
       {
       	类名
       };
       ```

     - 继承方式说明符指明基类成员在派生类中的访问属性, 一般用 `public`

   - 派生类的大小

     - 派生类大小 = 基类成员变量大小 + 派生类对象自身成员变量大小
     - 对象的大小只与普通成员变量有关
     - 字节补齐原则
       - `char` 变量占 1字节, 补齐为 4 字节
       - 空类的大小是1
       - 32位系统 指针 4 字节,  64 位系统指针 8 字节
       
       

3. 继承关系的特殊性

   - 基类的 友元类/友元函数, 派生类不继承 友元类/友元函数

   - 基类/成员是 某类的友元函数, 派生类继承友元关系

   - 如果基类中的成员是静态的，派生类中也是静态的，静态属性可继承(5-4)

     - ```C++
       #include <iostream>
       using namespace std;
       class Base
       {
       private:
         float x;
       
       public:
         static int staV;
         Base()
         {
           staV++;
         }
       };
       int Base::staV = 0;
       class Derived : public Base
       {
       private:
         float y;
       
       public:
         Derived()
         {
           staV++;
         }
       };
       int main()
       {
         Base a;
         cout << a.staV << endl;
         Derived d;
         cout << d.staV << endl;
         return 0;
       }
       ```

       

4. 有继承关系的类之间的访问

   - 如果派生类声明了与基类成员函数同名函数, 即使参数表不同, 继承的同名函数会被隐藏

     - 访问被隐藏的成员, 使用基类名和作用域分辨符来限定

   - 访问基类和派生类成员的方式(5-5)

     - ```C++
       #include <iostream>
       using namespace std;
       class CB
       {
       
       public:
         int a;
         CB(int x)
         {
           a = x;
         }
         void showa()
         {
           cout << "Class Cb--a=" << a << endl;
         }
       };
       class CD : public CB
       {
       public:
         int a;                   //与基类同名
         CD(int x, int y) : CB(x) //x 初始化基类的成员变量a
         {
           a = y;
         }
         void showa() //基类同名函数
         {
           cout << "Class CD--a" << a << endl;
         }
         void print2a()
         {
           cout << "a=" << a << endl;         //访问派生类a
           cout << "CB::a=" << CB::a << endl; //访问基类a
         }
       };
       int main()
       {
         CB CBobj(12);
         CBobj.showa();
         CD CDobj(48, 999);
         CDobj.showa();     //访问派生类的showa()
         CDobj.CB::showa(); //访问基类的showa()
         cout << "CDobj.a" << CDobj.a << endl;
         cout << "CDobj.CB::a=" << CDobj.CB::a << endl;
         return 0;
       }
       ```

   - 类之间的访问示例(5-6)

     - ```C++
       #include <iostream>
       #include <string>
       using namespace std;
       class CStudent //基类
       {
       private:
         string name; //姓名
         string id;   //学号
         char gender; //性别,'F'代表女生, 'M'代表男生
         int age;     //年龄
       public:
         void PrintInfo();
         void SetInfo(const string &, const string &, int, char);
         void SetName(string);
         string GetName();
         void SetId(string);
         string GetId();
       };
       void CStudent::PrintInfo()
       {
         cout << "姓名:\t" << name << endl;
         cout << "学号:\t" << id << endl;
         cout << "年龄:\t" << age << endl;
         cout << "性别:\t" << gender << endl;
       }
       void CStudent::SetInfo(const string &name_, const string &id_, int age_, char gender_)
       {
         name = name_;
         id = id_;
         age = age_;
         gender = gender_;
       }
       void CStudent::SetName(string name)
       {
         this->name = name;
       }
       string CStudent::GetName()
       {
         return name;
       }
       void CStudent::SetId(string id)
       {
         this->id = id;
       }
       string CStudent::GetId()
       {
         return id;
       }
       
       class CUndergraduateStudent : public CStudent //本科生类, 继承于类 CStudent
       {
       private:
         string department; //学生所属的系名
       
       public:
         void PrintInfo();
         void SetInfo(const string &, const string &, int, char, const string &);
       };
       void CUndergraduateStudent::PrintInfo()
       {
         CStudent::PrintInfo();
         cout << "院系:\t" << department << endl
              << endl;
       }
       void CUndergraduateStudent::SetInfo(const string &name_, const string &id_, int age_, char gender_, const string &department_)
       {
         CStudent::SetInfo(name_, id_, age_, gender_);
         department = department_;
       }
       
       class CGraduatedStudent : public CStudent //研究生类
       {
       private:
         string department; //学生所属的系名
         string advisor;    //导师
       public:
         void PrintInfo();
         void SetInfo(const string &name_, const string &id_, int age_, char gender_, const string &department_, const string &advisor_);
       };
       void CGraduatedStudent::PrintInfo()
       {
         CStudent::PrintInfo();
         cout << "院系:\t" << department << endl;
         cout << "导师:\t" << advisor << endl;
       }
       void CGraduatedStudent::SetInfo(const string &name_, const string &id_, int age_, char gender_, const string &department_, const string &advisor_)
       {
         CStudent::SetInfo(name_, id_, age_, gender_);
         department = department_;
         advisor = advisor_;
       }
       int main()
       {
         CStudent s1;
         CUndergraduateStudent s2;
         CGraduatedStudent s3;
         s2.SetInfo("张三", "2020-6-2-4", 19, 'M', "数学系");
         s3.SetInfo("李四", "M2021-12", 19, 'F', "计算机系", "罗教授");
         s2.PrintInfo();
         s3.PrintInfo();
         cout << s2.GetName() << endl;
         s2.SetName("王五");
         s2.PrintInfo();
         cout << s2.GetName() << "," << s2.GetId() << endl;
         return 0;
       }
       ```

   - 类之间的访问(5-7)

     - ```C++
       #include <iostream>
       #include <string>
       using namespace std;
       class employee //基类
       {
         short age;
         float salary;
       
       protected:
         string name;
       
       public:
         employee(short ag, float sa, string na)
         {
           age = ag;
           salary = sa;
           name = na;
         };
         void print()
         {
           cout << "\n"
                << name << ":\t";
           cout << age << ":\t";
           cout << salary;
         };
         ~employee() {}
       };
       class manager : public employee //派生类
       {
         int level;
       
       public:
         manager(short ag, float sa, string na, int lev) : employee(ag, sa, na) //初始化基类
         {
           level = lev;
         }
         void print()
         {
           employee::print();
           cout << "\tlevel:" << level;
         }
       };
       class engineer : public employee //
       {
         char speciality, adegree;
       
       public:
         engineer(short ag, float sa, string na, char spe, char ade) : employee(ag, sa, na) //初始化基类
         {
           speciality = spe;
           adegree = ade;
         }
         void print()
         {
           employee::print();
           cout << "\tspeciality:" << speciality;
           cout << "\tadegree:" << adegree;
         }
       };
       enum ptitle
       {
         PS,
         GM,
         VPS,
         VGM
       };
       class director : public manager
       {
         ptitle post;
       
       public:
         director(short ag, float sa, string na, int le, ptitle po) : manager(ag, sa, na, le) //初始化基类
         {
           post = po;
         }
         void print()
         {
           manager::print();
           cout << "\tpost:" << post << endl;
         }
       };
       int main()
       {
         employee emp1(23, 610.5, "wang"), emp2(27, 824.75, "li");
         manager man1(32, 812.45, "zhang", 11), man2(34, 1200.5, "chen", 7);
         engineer eng(26, 1420.10, "sun", 'E', 'M');
         director dir(38, 1800.2, "liu", 2, VPS);
         emp1.print();
         emp2.print();
         man1.print();
         man2.employee::print();
         eng.print();
         dir.print();
         return 0;
       }
       ```

       

5. `protected` 访问范围说明符

   - 保护成员访问范围比私有成员大, 基类的保护成员可以被派生类成员函数访问
   - 基类需要隐藏的成员一般设置为保护成员, 方便派生类成员访问

   

6. 多重继承

   - 一个类同时有多个基类

   - 格式

     - ```C++
       class 派生类名:继承方式说明符 基类名1, 继承方式说明符 基类名2, ... ,继承方式说明符 基类名n
       {
       	类体
       }
       ```

     - 派生类继承了所有成员变量和成员函数, 和普通继承一样

   - 如果多个基类成员重名

     - 对派生类而言, 不加类名限定时默认访问的是派生类成员;
     - 访问基类成员时, 加对应类名限定;
     - 如果重名成员继承到派生类中, 不加限定访问会产生二义性问题
   
   - 多重继承(5-11)
   
     - ```C++
       #include <iostream>
       using namespace std;
       class BaseClass1 //基类
       {
       public:
         int v1, v2;
         BaseClass1();
         BaseClass1(int, int);
         ~BaseClass1();
       };
       BaseClass1::BaseClass1()
       {
         cout << "BaseClass1 No parameter" << endl;
       }
       BaseClass1::BaseClass1(int m, int n) : v1(m), v2(n)
       {
         cout << "BaseClass1 Two parameter" << endl;
       }
       BaseClass1::~BaseClass1()
       {
         cout << "BaseClass1 Destroy" << endl;
       }
       
       class BaseClass2
       {
       public:
         int v1, v4;
         BaseClass2();
         BaseClass2(int, int);
         ~BaseClass2();
       };
       BaseClass2::BaseClass2()
       {
         cout << "BaseClass2 No parameter" << endl;
       }
       BaseClass2::BaseClass2(int m, int n) : v1(m), v4(n)
       {
         cout << "BaseClass2 Two parameter" << endl;
       }
       BaseClass2::~BaseClass2()
       {
         cout << "BaseClass2 Destroy" << endl;
       }
       
       class DerivedClasss : public BaseClass1, public BaseClass2
       {
       public:
         int v3;
       
       public:
         DerivedClasss();
         DerivedClasss(int);
         DerivedClasss(int, int, int, int);
         ~DerivedClasss();
       };
       DerivedClasss::DerivedClasss()
       {
         cout << "DerivedClasss No parameter" << endl;
       }
       DerivedClasss::DerivedClasss(int k) : v3(k)
       {
         cout << "DerivedClasss One parameter" << endl;
       }
       DerivedClasss::DerivedClasss(int m, int n, int k, int t) : BaseClass1(m, n), BaseClass2(m, t), v3(k)
       {
         cout << "DerivedClasss Four parameter" << endl;
       }
       DerivedClasss::~DerivedClasss()
       {
         cout << "DerivedClasss Destroy" << endl;
       }
       int main()
       {
         cout << " create object with parameter" << endl;
         DerivedClasss derivedCla1(1000, 2000, 3000, 4000);
         cout << "v1=" << derivedCla1.BaseClass1::v1 << endl;
         cout << "v2=" << derivedCla1.v2 << endl;
         cout << "v1=" << derivedCla1.BaseClass2::v1 << endl;
         cout << "v4=" << derivedCla1.v4 << endl;
         cout << "v3=" << derivedCla1.v3 << endl;
         return 0;
       }
       ```
   
       
   
   

## 第二节 访问控制

1. 公有控制

   - 基类的公有成员和保护成员的访问属性在派生类中不变, 而基类的私有成员在基类外不可直接访问, 派生类不能访问私有成员

   - 公有继承访问控制

     |         各成员         |     派生类中     |  基类与派生类外  |
     | :--------------------: | :--------------: | :--------------: |
     |     基类的公有成员     |     直接访问     |     直接访问     |
     |     基类的保护成员     |     直接访问     | 调用共有函数访问 |
     |     基类的私有成员     | 调用共有函数访问 | 调用共有函数访问 |
     |  从基类继承的公有成员  |     直接访问     |     直接访问     |
     |  从基类继承的保护成员  |     直接访问     | 调用共有函数访问 |
     |  从基类继承的私有成员  | 调用共有函数访问 | 调用共有函数访问 |
     | 派生类中定义的公有成员 |     直接访问     |     直接访问     |
     | 派生类中定义的保护成员 |     直接访问     | 调用共有函数访问 |
     | 派生类中定义的私有成员 |     直接访问     | 调用共有函数访问 |

   - 方便统一处理, 提高程序效率

     - 函数的形参为基类的对象/引用/指针时, 实参可以使派生类的对象/指针, 不用为每个类设计单独的模块

2. 类型兼容规则

   - 任何需要基类对象的地方, 都可以用公有派生类的对象来替代, 也称为 赋值兼容规则

     1. 派生类的对象可以赋值给基类对象
     2. 派生类对象可以用来初始化基类引用
     3. 派生类对象的地址可以赋值给基类指针, 即派生类的指针可以赋值给基类的指针

     此规则反过来不成立

   - 验证类型兼容规则输出的结果(5-14)

     - ```C++
       #include <iostream>
       using namespace std;
       class A //基类
       {
         int an;
       
       public:
         A() {}
         A(int n)
         {
           an = n;
         }
         void print()
         {
           cout << "A 的对象:";
           cout << "an:" << an;
         }
         void print(int k)
         {
           cout << "an:" << an;
         }
       };
       class B : public A
       {
         int bn;
       
       public:
         B(int n) : A(2 * n)
         {
           bn = n;
         }
         void print()
         {
           cout << "\nB 的对象:";
           A::print(1);
           cout << ", bn=" << bn << endl;
         }
       };
       
       int main()
       {
         A a(10);
         B b(20);
         a.print();
         b.print();
         a = b;
         a.print();
         b.print();
         return 0;
       }
       ```

       

3. 私有继承

   - 基类中的公有成员和保护成员都以私有成员身份出现在派生类中, 基类的私有成员在派生类中不可直接访问

     |                |   第一级派生中   | 第二季派生中 | 基类与派生类外 |
     | :------------: | :--------------: | :----------: | :------------: |
     | 基类的公有成员 |     直接访问     |   不可访问   |    不可访问    |
     | 基类的保护成员 |     直接访问     |   不可访问   |    不可访问    |
     | 基类的私有成员 | 调用公有函数访问 |   不可访问   |    不可访问    |

     

4. 保护继承

   - 基类中公有成员和保护成员都以保护成员继承到派生类中, 私有成员不可直接访问



## 第三节 派生类的构造函数和析构函数

1. 构造函数与析构函数

   - 派生类不继承构造函数, 需要在派生类的构造函数中调用基类的构造函数, 已完成继承成员的初始化

     - 执行派生类构造函数前, 总是先执行基类的构造函数, 析构函数反之

   - 派生类在构造函数中添加初始化列表, 说明基类成员变量如何初始化

     - 只要基类不是默认构造函数, 都要显式给出基类名和参数表

     - 基类定义了带有形参的构造函数, 派生类就应当定义构造函数

     - 格式

       - ```C++
         派生类名::派生类名(参数表):基类名1(基类1 初始化参数表), ... ,基类名m (基类m 初始化参数表), 成员对象名1(成员对象1 初始化参数表), ... ,成员对象名n (成员对象n 初始化参数表)
         {
         	派生类构造函数函数体   //其它初始化操作
         }
         ```

   - 基类和派生类的构造/解析函数(5-15)

     - ```C++
       #include <iostream>
       using namespace std;
       class BaseClass 
       {
       protected:
         int v1, v2;
       
       public:
         BaseClass();
         BaseClass(int, int);
         ~BaseClass();
       };
       BaseClass::BaseClass()
       {
         cout << "BaseClass No parameter" << endl;
       }
       BaseClass::BaseClass(int m, int n)
       {
         v1 = m;
         v2 = n;
         cout << "BaseClass Two parameter" << endl;
       }
       BaseClass::~BaseClass()
       {
         cout << "BaseClass Destroy" << endl;
       }
       
       class DerivedClass : public BaseClass
       {
         int v3;
       
       public:
         DerivedClass();
         DerivedClass(int);
         DerivedClass(int, int, int);
         ~DerivedClass();
       };
       DerivedClass::DerivedClass()
       {
         cout << "DerivedClass No parameter" << endl;
       }
       DerivedClass::DerivedClass(int k) : v3(k)
       {
         cout << "DerivedClass One parameter" << endl;
       }
       DerivedClass::DerivedClass(int m, int n, int k) : BaseClass(m, n), v3(k)
       {
         cout << "DerivedClass Three parameter" << endl;
       }
       DerivedClass::~DerivedClass()
       {
         cout << "DerivedClass Destroy" << endl;
       }
       
       int main()
       {
         cout << "create no parameter object" << endl;
         BaseClass baseCla;
         DerivedClass derivedCla;
         cout << "create with parameter object" << endl;
         BaseClass baseCla1(10, 20);
         DerivedClass derivedCla1(30);
         return 0;
       }
       ```

   - 派生类函数执行的一般次序

     1. 调用基类构造函数, 调用顺序按照被继承时声明的顺序(从左至右)
     2. 对派生类新增成员变量的初始化, 调用顺序按照类中的声明顺序
     3. 执行派生类的构造函数体中的内容

   - 调用基类和派生类的构造函数/析构函数和成员函数(5-16)

     - ```C++
       #include <iostream>
       using namespace std;
   class Base //基类
       {
       private:
         int Y;
       
       public:
         Base(int y = 0)
         {
           Y = y;
           cout << "Base(" << y << ")" << endl;
         }
         ~Base()
         {
           cout << "~Base()" << endl;
         }
         void print()
         {
           cout << Y << " ";
         }
       };
       class Derived : public Base
       {
       private:
         int Z;
       
       public:
         Derived(int y, int z) : Base(y)
         {
           Z = z;
           cout << "Derived(" << y << "," << z << ")" << endl;
         }
         ~Derived()
         {
           cout << "~Derived()" << endl;
         }
         void print()
         {
           Base::print();
           cout << Z << endl;
         }
       };
       
       int main()
       {
         Derived d(10, 20);
         d.print();
         return 0;
       }
       ```
       
       

2. 复制构造函数

   - 一个类, 自动生成复制构造函数或自定义

     - 默认的复制构造函数自动调用基类的复制构造函数, 对派生类新增的成员对象复制

   - 派生类中的复制构造函数(5-17)

     - ```C++
       #include <iostream>
       using namespace std;
       class A //基类
       {
       public:
         A()
         {
           i = 100;
           cout << "class A default construct function" << endl;
         }
         A(const A &s)
         {
           i = s.i;
           cout << "calss A copy construct funciton" << endl;
         }
         int getValue();
         void setValue(int);
       
       private:
         int i;
       };
       int A::getValue()
       {
         return i;
       }
       void A::setValue(int k)
       {
         i = k;
       }
       class B : public A
       {
       private:
         float f;
       
       public:
         B()
         {
           f = 20.1;
           cout << "class B default construct function" << endl;
         }
         B(const B &v) : A::A(v), f(v.f)
         {
           cout << "class B copy construct function" << endl;
         }
         float getValue();
         int getValue1()
         {
           return A::getValue();
         }
       };
       float B::getValue()
       {
         return f;
       }
       
       int main()
       {
         A a;
         B b;
         B bb(b); //调用类A 复制构造函数、类B 赋值构造函数
         return 0;
       }
       ```

   - 赋值运算符的重载及使用(5-18)

     - ```C++
       
       ```

       

3. 多重继承的构造函数与析构函数

   - 多重继承(5-19)

     - ```C++
       
       ```

       

## 第四节 类之间的关系

1. 类与类之间的关系

   - 使用已有类编写新类的两种方式
     - 继承和组合
     - 继承关系和组合关系(包含关系)
     
     

2. 封闭类的派生

   - 一个类的成员变量是另一个类的对象, 称为封闭类

   - 定义封闭类构造函数的一般形式: 

     - ```C++
       类名::类名(形参表): 内嵌对象1(形参表),内前对象2(形参表), ...
       {
       	类体
       }
       ```

     - `内嵌对象1(形参表),内前对象2(形参表), ...` 是初始化列表, 对内嵌对象进行初始化

   - 封闭类的构造函数(5-20)

     - ```C++
       
       ```

       

3. **互包含关系的类**

   - 两个类相互引用, 称为循环依赖的类

     - ```C++
       class A //类 A 的定义
       {
       public:
       	void f(B b); //以类B对象为参数的成员函数
       };
       class B //定义类 B
       {
       public:
       	void g(A a); //以类A对象为参数的成员函数
       }
       ```

     - 会编译错误

   - 向前引用声明

     - 引用未定义的类之前, 将该类的名字告诉编译器, 完整类的定义可以写在其他地方
     - 在提供一个完整的类定义之前, **不能定义该类的对象**, 也不能内联成员函数中使用该类的对象

   - 相互包含的类(5-21)

     - ```C++
       
       ```

       

## 第五节 多层次的派生

- 类之间的继承关系具有传递性

- 派生类成员包括

  - 派生类自己定义的成员
  - 直接基类中定义的成员
  - 间接基类中定义的全部成员

- 生成派生类对象时, 会依次执行所有基类的构造函数, 最后执行派生类的构造函数; 析构反之

- 一个类可以是多个类的直接基类, 只能说明一次

  - 一个类可以多次成为某个派生类的间接基类

- 多级派生时构造函数的调用(5-22)

  - ```C++
    
    ```

    

## 第六节 基类与派生类指针的相互转换

- 公有派生时, 派生类对象也是基类对象, 所以派生类对象可以赋值给基类对象

  - 使用指针指向派生类对象
  - 派生类指针赋值给基类指针
    - 即使基类指针指向派生类对象, 不能通过基类指针访问派生类中定义的函数
    - 当派生类指针指向基类对象时, 必须要将基类对象强制类型转换, 才能赋值给派生类指针

- 使用指针的情况(5-23)

  - ```C++
    
    ```

- 基类引用也可以强制类型转换为派生类引用

- 强制转换都存在安全隐患

  - `dynamic_cast` 强制类型转换运算符, 判断转换是否安全 (指针或引用是否真的指向派生类对象)



# 第六章 多态与虚函数

- 多态原理
- 虚析构函数
- 纯虚函数

## 第一节 多态的基本概念

面对对象程序设计语言有封装/继承/多态三种机制

1. 多态
   - 编译时多态
     
     - 根据实参确定调用哪个函数
   - 运行时多态
     - 继承/虚函数
     - 函数调用与代码入口地址的绑定需要在运行时刻再能确定, 称为动态联编/ 动态绑定
   - 类之间满足赋值兼容的前提下, 实现动态绑定必须满足两个条件
     1. 必须声明虚函数
     2. 通过基类类型的引用或者指针调用虚函数
     
     
   
2. 虚函数
   - `virtual` 关键字只在类定义中的成员函数声明处使用, 不能在类外部成员写函数体时使用
     - 静态成员函数不能是虚函数
     - 包含虚函数的类称为“多态类”
     - `virtual 函数返回值类型 函数名(形参表);`
   - 注意
     1. 虽然虚函数声明为内联不会引起错误, 但因为内联函数是在编译阶段进行动态处理的, 而对虚函数的调用是动态绑定的, 所以虚函数一般不声明为内联函数
     2. 派生类重写基类的虚函数实现多态, 要求函数名/参数列表及返回值类型要完全相同
     3. 基类中定义了虚函数, 在派生类中该函数始终个保持虚函数的特性
     4. 只有类的非静态成员函数才能定义为虚函数, 静态成员函数和友元函数不能定义为虚函数
     5. 如果虚函数的定义是在类体外, 则只需在声明函数时添加 `virtual` 关键字, 定义时不加 `virtual` 关键字
     6. 构造函数不能定义为虚函数, `operator=` 容易混淆, 也不要定义为虚函数
     7. 不要在构造函数和析构函数中调用虚函数, 构造/析构函数中, 对象不完整
     8. 最好将基类的析构函数声明为虚函数
     9. 全局函数不属于类, 没有继承关系, 无法覆盖, 不能使用多态
     10. 基类声明成员函数为虚函数, 派生类相同成员函数都是虚函数
     
     
   
3. 通过基类指针实现多态 

   - 声明虚函数后, 派生类对象的地址可以赋值给基类指针, 基类指针可以指向派生类对象

   - 调用基类指针时, 指针指向基类对象则执行基类的虚函数, 指向派生类对象则执行派生类的虚函数

   - 通过基类指针实现多态示例(6-1)

     - ```C++
       
       ```

   - 用基类指针访问基类对象及派生类对象

     - ```C++
       
       ```

       

4. 通过基类引用实现多态

   - 引用等同于指针

   - 基类引用实现多态(6-3)

     - ```C++
       
       ```

       

5. **多态的实现原理**

   - 多态的关键在于通过指针/引用调用一个虚函数时, 编译阶段不能确定到底调用的是基类还是派生类的函数, 运行时才能确定

   - 多态机制下对象储存空间的大小(6-4)

     - ```C++
       
       ```

   - 类A中每个对象都保存自己的虚函数表的地址, 这是实现多态的关键

     - 每个虚函数的类都有一个虚函数表, 编译器生成, 程序运行时载入

   

## 第二节 多态实例

- 使用多态处理图形示例

  - ```C++
    
    ```

    

## 第三节 多态的使用

- 在成员函数中调用虚函数(6-6)

  - ```C++
    
    ```

- 在构造函数和析构函数中调用虚函数(6-7)

  - ```C++
    
    ```

- 多态与非多态的对比(6-8)

  - ```C++
    
    ```

    

## 第四节 虚析构函数

- 只调用基类的析构函数, 只会完成该析构函数内的空间释放, 不会涉及派生类析构函数内的空间, 造成内存泄漏

  - 虚析构函数

    - `virtual ~类名();`
    - 没有返回值类型, 没有参数

  - 如果一个类的析构函数时虚函数, 则它的派生函数的析构函数都是虚函数

  - 不使用虚析构函数的情况(6-9)

    - ```C++
      
      ```

    - 构造函数不能是虚函数

    

## 第五节 纯虚函数和抽象类

1. 纯虚函数

   - 基类中某个虚函数不用给出确切的定义, 可以将它声明为纯虚函数
     - 相当于一个统一的接口形式
   - 基类中声明
     - 只有函数名, 不具备函数功能, 不能在基类中调用
   - 格式
     - `virtual 函数类型 函数名(参数表)=0;`
     - 参数表要写 `=0` 表示函数体, 派生类中必须重写这个函数

   

2. 抽象类

   - 纯虚函数的类称为抽象类

     - 抽象类中有未完成的函数定义, 不能实例化对象
     - 抽象类的派生类中, 如果内有给出全部纯虚函数的定义, 派生类继续是抽象类, 直到派生类中给出纯虚函数定义后, 才不是抽象类
     - 可以定义抽象类的指针和引用, 指针访问派生类的成员, 具有多态性

   - 抽象类实例(6-10)

     - ```C++
       
       ```

       

3. 虚基类

   - 为了避免二义性, C++ 提供虚基类机制, 派生类中继承同一个间接基类的成员仅保留一个版本

   - 定义虚基类的格式

     - ```C++
       class 派生类名 : virtual 派生方式 基类名
       {
         派生类体
       };
       ```

   - 虚基类(6-11)

     - ```C++
       
       ```

       



# 第七章 输入/输出流

- `cin cout` 重定向
- 格式控制
- 常见成员函数

## 第一节 流类简介

- C++ 没有输入输出语句

  - C++ 标准库中面向对象的 I/O 流类库，输入输出均通过流完成。流是 I/O 流类的核心概念。

- 数据传输称为流

  - 读操作称为提取
  - 写操作称为插入
  - 输入输出的相关类称为流类

- 常用 I/O 流类列表

  |     类名     |   关键字   |                       说明                        |  包含文件  |
  | :----------: | :--------: | :-----------------------------------------------: | :--------: |
  |  抽象流基类  |   `ios`    |                      流基类                       |   `ios`    |
  |   输入流类   | `istream`  | 通用输入流基类和其它输入流基类，`cin` 是该类对象  | `istream`  |
  |   输入流类   | `ifstream` |         文件输入流类，用于从文件读取数据          | `ifstream` |
  |   输出流类   | `ostream`  | 通用输出流基类和其它输出流基类，`cout` 是该类对象 | `ostream`  |
  |   输出流类   | `ofstream` |        文件输出流类，用于向其他文件写数据         | `fstream`  |
  | 输入输出流类 | `iostream` |     通用输入输出流基类和其它输入输出流类基类      | `iostream` |
  | 输入输出流类 | `fstream`  |         文件输入输出流类，读取和写入文件          | `fstream`  |

  

## 第二节 标准流对象

- 标准流对象（也称为标准流），为用户提供外设与内存之间的通信通道，对数据进行解释和传输，和必要的数据缓冲等

  - 四个标准流对象

    - `cin` ：标准输入流
      - 关联输入设备（键盘），可以重定向为从文件读取数据
    - `cout`：标准输出流
      - 关联输出设备（显示器），可以重定向为向文件写入数据
    - `cerr`：非缓冲错误输出流
      - 关联标准错误信息输出设备（显示器），非缓冲，不能重定向
    - `clog`：缓冲错误输出流
      - 关联标准错误信息输出设备（显示器），缓冲，不能重定向

  - 重定向函数 `freopen` 的原型如下

    - `FILE *freopen(const char *path, const char *mode, FILE *stream);`
    - `freopen()` 将 `stream` 按 `mode` 指定的模式重定向到路径 `path` 指向的文件，如果错误则关闭 stream 返回 NULL

  - 将标准输出 `cout` 重定向到文件(7-1)

    - ```C++
      
      ```

  - 标准输入重定向为文件(7-2)

    - ```C++
      
      ```

  - `ios` 中错误状态字

    | 标识常量  |  值  |              含义              |
    | :-------: | :--: | :----------------------------: |
    | `goodbit` | 0X00 |           流状态正常           |
    | `eofbit`  | 0X01 |           文件结束符           |
    | `failbit` | 0X02 | I/O 操作失败,数据未丢失,可恢复 |
    | `badbit`  | 0X04 |   非法操作,数据丢失,不可恢复   |

  - `ios` 中流相关的成员函数, 可直接使用

    1. 返回流是否结束

       - `int eof() const;`
       - 是否遇到文件尾, 是则返回1, 否则返回0
       - Ctrl+Z 表示输入流结束

    2. 返回流是否处于正常状态

       - `int fail() const;`

    3. 判断流是否正常

       - ```C++
         int good() const;
         int operator void *();
         ```

       - `eofbit failbit badbit` 是否为1，否则返回0

    4. 返回流是否处于失败状态

       - ```C++
         int bad() const;
         int operator void !();
         ```

       - `eofbit failbit badbit` 是否为1，否则返回0

    5. 返回状态字

       - `int rdstate() const;`

    6. 恢复状态字

       - `void clear(int nStata = 0 );`

  - 标准输入重定向为文件并判断文件状态(7-3)

    - ```C++
      
      ```

  - 将键盘输入的数据累加(7-4)

    - ```C++
      
      ```

      

## 第三节 控制 IO 格式

1. 流操纵符

   - C++ 中常见数据类型的默认 I/O 格式

     | I/O 的数据类型                      | 默认的输入格式                                    | 默认的输出格式                 |
     | ----------------------------------- | ------------------------------------------------- | ------------------------------ |
     | `short/int/long(signed / unsigned)` | 与整数型常数相同                                  | 一般整数形式，复数前面有负号   |
     | `float/double/long/double`          | 与浮点数相同                                      | 浮点或指数格式，取决于哪个更短 |
     | `char *(signed/unsigned)`           | 从第一个空白字符（空格、\t、\n)开始到下个空白字符 | 字符序列（无引号）             |
     | `char *(signed/unsigned)`           | 第一个非空白字符                                  | 字符序列（无引号）             |
     | `void*`                             | 无前缀的十六进制数                                | 无前缀的十六进制数             |
     | `Bool`                              | `将true`或 `1` 识别为`true`，或反过来             | `1或0`                         |

   - `iostream` 中常用流操纵符

     | 流操纵符 | 作用                       | 输入/输出 |
     | -------- | -------------------------- | --------- |
     | `endl`   | 输出一个新行符，并清空流   | `O`       |
     | `ends`   | 输出字符串结束，并清空流   | `O`       |
     | `flush`  | 清空流缓冲区               | `O`       |
     | `dec*`   | 以十进制形式输入输出整数   | `I/O`     |
     | `hex`    | 以十六进制形式输入输出整数 | `I/O`     |
     | `oct`    | 以八进制形式输入输出整数   | `I/O`     |
     | `ws`     | 提取空白字符               | `O`       |

     - `*` 表示默认设置，不属于操纵符的一部分

   - 常用的用于格式控制的流操纵符

     | 流操纵符                    | 作用                                                         |
     | --------------------------- | ------------------------------------------------------------ |
     | `fixed`                     | 普通小数形式输出浮点数                                       |
     | `scientific`                | 科学计数法形式输出浮点数                                     |
     | `left`                      | 左对齐，宽度不足时填充字符到右边                             |
     | `right *`                   | 右对齐，宽度不足时填充字符到左边                             |
     | `setbase(int b)`            | 设置输出整数时的进制，`b`为8、10、16                         |
     | `setw(int w)`               | 指定输出宽度为 w 个字符，或输入字符串时读入w个字符。一次有效 |
     | `setfill(int c)`            | 指定输出宽度，宽度不足时用ASCII码为c的字符填充（默认空格）   |
     | `setpercision(int n)`       | 设置浮点数精度n。默认n为有效数字位数，`fixed/scientific`后n是小数点后保留位数 |
     | `setiosflags(fmtfalgs f)`   | 通用操作符。将格式标志f对应的格式标志位置为1                 |
     | `resetiosflags(fmtfalgs f)` | 通用操作符。将格式标志f对应的格式标志位置为0（清除）         |
     | `boolapha`                  | 把`true` 和 `false` 输出为字符串                             |
     | `noboolalpha *`             | 把`true` 和 `false` 输出为1和0                               |
     | `showbase`                  | 输出表示数值进制的前缀                                       |
     | `noshowbase *`              | 不输出表示数值进制的前缀                                     |
     | `showpoint`                 | 总是输出小数点                                               |
     | `noshowpoint *`             | 只有当小数部分存在时输出小数点                               |
     | `showpos`                   | 非负数值中显示+                                              |
     | `noshowpos *`               | 非负数值中不显示+                                            |
     | `skipws *`                  | 输入时跳过空白字符                                           |
     | `noskipws`                  | 输入时不跳过空白字符                                         |
     | `uppercase`                 | 十六进制数中使用 A-E。若输出前缀，为0X，科学计数法输出 E     |
     | `no uppercase*`             | 十六进制数中使用 a-e。若输出前缀，为0x，科学计数法输出 e     |
     | `internal`                  | 数值的符号（正负号）指定宽度内左对齐，数值右对齐，中间填充字符 |

   - 使用流操纵符控制整数输出(7-5)

     - ```C++
       
       ```

   - 使用流操纵符控制浮点数输出(7-6)

     - ```C++
       
       ```

   - 通过 `setw()` 控制输入格式(7-7)

     - ```
       
       ```

       

2. 标志字

   - 常见格式标志常量及含义

     | 标志常量名       | 值     | 含义                                               | 输入/输出 |
     | ---------------- | ------ | -------------------------------------------------- | --------- |
     | `ios::skipws`    | 0X0001 | 跳过输入中的空白                                   | `I`       |
     | `ios::left`      | 0X0002 | 按输出左对齐，填充字符右边                         | `O`       |
     | `ios::right`     | 0X0004 | 按输出右对齐，填充字符左边                         | `O`       |
     | `ios::internal`  | 0X0008 | 在符号位或基数指示符后填入字符                     | `O`       |
     | `ios::dec *`     | 0X0010 | 转换为十进制基数形式                               | `I/O`     |
     | `ios::oct`       | 0X0020 | 转换为八进制基数形式                               | `I/O`     |
     | `ios::hex`       | 0X0040 | 转换为十六进制基数形式                             | `I/O`     |
     | `ios::showbase`  | 0X0080 | 在输出中显示基数指示符                             | `O`       |
     | `ios::showpoint` | 0X0100 | 在输出浮点数时必须带小数点和尾部的 0               | `O`       |
     | `ios::uppercase` | 0X0200 | 以大写字母表示十六进制数，科学计数法使用大写字母 E | `O`       |
     | `ios::showpos`   | 0X0400 | 正数前加 + 号                                      | `O`       |
     | `ios::scentific` | 0X0800 | 科学计数法显示浮点数                               | `O`       |
     | `ios::fixed`     | 0X1000 | 定点法表示浮点数                                   | `O`       |
     | `ios::unitbuf`   | 0X2000 | 插入操作后立即刷新流                               | `O`       |

     - 标志常量实际是在一个整数中仅将某一个二进制位设为 1，其它清零。
     - 设置多个标志，用位或 `|` 运算符连接
     - 流格式标志每一位表示一种格式，会有相互制约；矛盾时清除原来的标志

   - 清除同类互斥位

     - `ios::basefield`    `值为 dec | oct | hex`

     - `ios::adjustifield`   `值为 left | right | internal`

     - `ios::floatfield`   `值为 scientific | fixed`

     - ```C++
       cout setf(ios::oct,ios::basefield);//示例，标准流为八进制基数形式插入
       ```

   - 通过 `setiosflags()` 设置标志字进行格式控制(7-8)

     - ```C++
       
       ```

       

## 第四节 调用 cout 的成员函数

- 常见用于控制格式的成员函数原型如下

  1. 设置和返回标志字
  2. 设置标志位
  3. 清除标志位
  4. 设置和返回输出宽度
  5. 设置填充字符
  6. 设置数据显示精度

- `ostream` 类的成员函数及作用相同的流操作符

  | 成员函数              | 作用相同的流操作符     |
  | --------------------- | ---------------------- |
  | `precision(int p)`    | `setprecision(np)`     |
  | `width(int nw)`       | `setw(nw)`             |
  | `fill(char cFill)`    | `setfill(cFill)`       |
  | `setf(long IFlags)`   | `setiosflags(IFlags)`  |
  | `unsetf(long IFlags)` | `resetioslags(IFlags)` |

- 使用 cout 中的函数控制输出格式(7-9)

  - ```C++
    
    ```

- 使用 cout() 函数

  - ```C++
    
    ```



## 第五节 调用 cin 的成员函数

1. `get()` 函数，只介绍常用的

   - `int get()`

   - 从输入流中读入一个字符（包括空白），返回值就是该字符的ASII 码。如果碰到输入结束符，则返回值为系统常量 EOF（End Of File，文件结束标记）。

   - 采用 EOF 判断输入是否结束

     - ```C++
       
       ```

     - `Ctrl + Z` 和 `Enter` 键代表文件结束

     

2. `getline()` 函数

   - `istream & getline(char * buf, int bufSize);`

     - 从输入流中的当前字符开始读取 `bufSize-1` 个字符到缓冲区 `buf` ，或读到 `\n` 为止。函数会在 `buf` 中读入数据的结尾自动添加串结束标记 `\0`。

   - `istream & getline(char * buf, int bufSize, char delim);`

     - 从输入流中的当前字符开始读取 `bufSize-1` 个字符到缓冲区 `buf` ，或读到字符 `delim` 为止。函数会在 `buf` 中读入数据的结尾自动添加串结束标记 `\0`。

   - `getline()` 函数功能演示

     - ```C++
       
       ```

       

3. `eof()` 函数

   - `bool eof();`

     - 用于判断输入流是否已经结束，返回 ture 表示结束

     

4. `ignore()` 函数

   - `istream & ignore(int n=1, int delim = EOF);`

     - 跳过输入流中的 `n` 个字符，或跳过 delim 之前的所有字符。默认跳过一个字符

   - 从输入的字符串中提取电话号码(7-13)

     - ```C++
       
       ```

       

5. `peek()` 函数

   - `int peek();`

     - 返回输入流中的当前字符，只读不操作

   - 日期格式转换(7-14)

     - ```C++
       
       ```

       



# 第八章 文件操作

- 文件
- ifstream、ofstream、fstream
- 顺序访问和随机访问，文件读写指针和移动文件指针

## 第一节 文件基本概念和文件流类

1. 文件的概念
   - 编码方式
     - 文本文件
     - 二进制文件
   - 存储方式
     - 顺序存储文件
     - 随机存储文件
   - 基本操作
     - 读文件（输入）
     - 写文件（输出）
   - 本质都是二进制文件
   
   
   
2. C++ 文件流类

   - 文件是物理概念，流是逻辑概念
   - 标准库内三个流类可用于文件操作，统称为文件流类
     1. `ifstream`：用于文件中读取数据
     2. `ofstream`：用于向文件中写入数据
     3. `fstream`：既可用于读取，也可写入

   

## 第二节 打开和关闭文件

1. 打开文件

   - 打开方式

     1. 建立流对象，调用 `open()` 函数连接外部文件

        - ```C++
          流类名 对象名;
          对象名.open(文件名, 模式);
          ```

     2. 调用流类带参数的构造函数，在建立流对象的同时连接外部文件

        - `流类名 对象名(文件名, 模式)`

     流类：文件流类

     文件名：外部文件名

     模式：类 `ios` 定义的打开模式的标记常量，表示打开方式

   - 文件打开模式标记

     | 模式标记                      | 适用对象                     | 作用                                                         |
     | ----------------------------- | ---------------------------- | ------------------------------------------------------------ |
     | `ios::in`                     | `ifstream; fstream`          | 读方式打开文件，如果不存在则报错                             |
     | `ios::out`                    | `ofstream; fstream`          | 写方式打开，不存在则新建；已存在则清空原内容                 |
     | `ios::app`                    | `ofstream`                   | 追加方式打开，不存在则新建                                   |
     | `ios::ate`                    | `ofstream`                   | 打开已有文件，将指针指向文件末尾；不存在则报错               |
     | `ios::trunc`                  | `ofstream`                   | 删除文件现有内容，单独使用时同 `ios::out`                    |
     | `ios::binary`                 | `ifstream;ofstream; fstream` | 以二级制打开文件；不指定则默认文本方式打开                   |
     | `ios::in|ios::out`            | ` fstream`                   | 打开已存在文件，即可读取，也可写入；不存在则报错             |
     | `ios::in|ios::out`            | `ofstream`                   | 打开已存在文件，可写入；不存在则报错                         |
     | `ios::in|ios::out|ios::trunc` | `fstream`                    | 打开已存在文件，即可读取，也可写入；存在则清空原内容，不存在则新建 |

   - 打开文件示例

     - ```C++
       
       ```

       

2. 关闭文件

   - 发出关闭文件指令后，系统会将缓冲区中的数据完整地写入文件，同时添加文件结束标记，切断流对象与外部文件的连接

   - 建立流对象，调用 `open()` 函数连接外部文件(8-1)

     - ```C++
       
       ```

   - 调用流类带参数的构造函数打开文件(8-2)

     - ```C++
       
       ```

       

## 第三节 文件读写操作

1. 读写文本文件

   - C++ 将文件看成顺序排列的无结构的字节流。

     - 对于长度 n 的文件来说，字节号从 `0 ~ n-1` ，最后一位是文件结束标识符EOF `0x1A` 

   - 对文本文件 `score.txt` 进行输入/输出(8-3)

     - ```C++
       
       ```

   - 读入学生成绩文件 `score.txt` 并显示内容(8-4)

     - ```C++
       
       ```

   - 读入文本文件，加上行号后显示内容(8-5)

     - ```C++
       
       ```

   - 对文本文件的内容进行排序，将结果输出到另一个文件(8-6)

     - ```C++
       
       ```

       

2. 读写二进制文件 

   1. 用 `ostream::write()` 成员函数写文件

      - `ostream & write(char *buffer, int nCount);`

      - 用二进制保存学生信息(8-7)

        - ```C++
          
          ```

      - 向二进制文件中追加数据(8-8)

        - ```C++
          
          ```

      

   2. 用 `istream::read()` 成员函数读文件

      - `istream &read(char * buffer, int nCount);`
      - 从文件读取 nCount 个字节的内容，存放到 buffer 指向的内存缓冲区，返回作用对象的引用
      - 非格式化操作，读取内容不处理，直接存入缓冲，由程序的类型定义解释

      

   3. 用 `ostream::gcount()` 成员函数得到读取字节数

      - `int gcount();`

      - 从二进制文件中读取数据(8-9)

        - ```C++
          
          ```

          

3. 用成员函数 `put()` 和 `get()` 读写文件

   1. `get()` 的三种主要形式

      1. `int get();`

         - 不带参数，从指定输入流中提取一个字符（包含空白），返回该字符。遇到文件尾则返回文件尾

         

      2. `istream & get(char &rch);`

         - 从指定输入流中提取一个字符（包含空白），将该字符作为 rch 引用的对象。遇到文件尾返回0；否则返回对 istream 对象的引用

         

      3. `istream & get(char *pch, int nCount, char delim='\n');`

         - 从流的当前字符开始，读取 nCount-1 个字符，或遇到指定分隔符 delim 结束。
         - 把读取的字符（不包含分隔符）写入数组 pch ，并增加结束符 ‘\0’

         

   2. `put()` 函数

      - `ostream& put(char ch);`
      - 向输出流中插入一个字节

      

   3. 文件复制(8-10)

      - ```C++
        
        ```

        

4. 文本文件与二进制文件的异同

   - Windows 中，以文本方式打开文件，系统会对文本文件中字符 `\r\n`（俗称回车换行）进行专门处理
     - 读文件，`\r\n` 转化成 `\n` ；
     - 写文件， `\n` 转化成 `\r\n` 再写入

   

## 第四节 随机访问文件

- 顺序文件，只能顺序存取

  - 键盘、显示器

- 随机文件，任意存取

  - 磁盘

- 流指针，文件操作的位置指针 

- `istream` 中与位置指针相关的函数

  1. 移动读指针函数
  2. 返回读指针当前位置值的函数

- `ostream` 中与位置指针相关的函数

  1. 移动指针函数
  2. 返回写指针当前位置值的函数

- 修改程序 8-7 ，观察文件读操作中位置指针的变化(8-11)

  - ```C++
    
    ```

- 读取程序 8-7 中 student.dat ，在文件中查找最高分和最低分并显示学生信息。若同时获得最高分只显示第一个

  - ```C++
    
    ```

    



# 第九章 函数模板与类模板

- 函数模板
- 类模板
- 模板与继承

## 第一节 函数模板

1. 函数模板概念

   - 使用虚拟的类型参数。

     - 实际的类型来实例化函数时，将函数模板与某个具体的数据类型连用。编译器将以此产生模板函数。
     - 这个过程叫函数模板实例化。

   - 定义函数模板格式

     - ```C++
       template <模板参数列表>
       返回值类型名 函数模板名(参数表)
       {
       	函数具体定义
       }
       ```

   - 类型 参数名可以是

     1. class 标识符
     2. 类型说明符 标识符

     

2. 函数模板示例

   - 定义求绝对值的函数模板,并进行不同的调用(9-1)

     - ```C++
       
       ```

   - 定义对象交换的函数模板(9-2)

     - ```C++
       
       ```

   - 对象排序程序(9-3)

     - ```C++
       
       ```

       

3. 函数或函数模板调用语句的匹配顺序

   - 函数模板可以重载，只要形参不同

   - 重载函数模板(9-4)

     - ```C++
       
       ```

   - 函数与函数模板名相同，一条函数调用语句该匹配哪个函数或模板？

     1. 先找参数完全匹配的普通函数（不是由模板实例化得到的模板函数）
     2. 再找参数完全匹配的模板函数
     3. 找实参经过自动类型转换后能够匹配的普通函数
     4. 报错

   - 函数调用匹配顺序(9-5)

     - ```C++
       
       ```

     

## 第二节 类模板

1. 类模板概念

   - 编译器通过类模板可以自动生成多个面向不同数据类型的类

   - 泛型数据替代实际的数据类型来说明变量，从而定义一个泛型类。

   - 声明类模板

     - ```C++
       template <模板参数表>
       class 类模板名
       {
       	类体定义
       }
       ```

     - 类模板以外定义函数成员

       ```C++
       template <模板参数表>
       返回类型名 类模板名 <模板参数标识符列表>::成员函数名(参数表)
       {
       	类体定义
       }
       ```

   - 使用类模板创建对象, 给出 类型形参/普通形参/实参

     - `类模板名 <模板参数表> 对象名1, ... ,对象名n;`
     - `类模板名 <模板参数表> 对象名1(构造函数实参), ... ,对象名n(构造函数实参)；`
     - 由类模板实例化的类叫模板类

     

2. 类模板示例

   - 二元数组类模板(9-6)

     - ```C++
       
       ```

   - 类模板(9-7)

     - ```C++
       
       ```

   - 在类模板中使用模板函数

     - ```C++
       
       ```

   - 类模板中使用静态成员

     - ```C++
       
       ```

   - 使用普通函数的类模板

     - ```C++
       
       ```

       

3. 类模板与继承

   - 类模板和类模板之间、类模板和类之间可以相互继承，派生关系的四种情况

     1. 普通类继承模板类

        - ```C++
          
          ```

          

     2. 类模板继承普通类

        - ```C++
          
          ```

          

     3. 类模板继承类模板

        - ```C++
          
          ```

          

     4. 类模板继承模板类

        - ```C++
          
          ```

          

     根据类模板实例化的类即是模板类。



# 附录 VScode 配置文件

## 编译环境 TDM-GCC

1. `c_cpp_properties.json`

   ```json
   {
       "configurations": [
           {
               "name": "Win32",
               "includePath": [
                   "${workspaceFolder}/**"
               ],
               "defines": [
                   "_DEBUG",
                   "UNICODE",
                   "_UNICODE"
               ],
               "intelliSenseMode": "msvc-x64"
           }
       ],
       "version": 4
   }
   ```

2. `launch.json`

   ```C++
   {
     "version": "0.2.0",
     "configurations": [
   
       {
         "name": "(gdb) Launch", // 配置名称，将会在启动配置的下拉菜单中显示
         "type": "cppdbg", // 配置类型，这里只能为cppdbg
         "request": "launch", // 请求配置类型，可以为launch（启动）或attach（附加）
         "program": "${workspaceRoot}/${fileBasenameNoExtension}.exe", // 将要进行调试的程序的路径
         "args": [], // 程序调试时传递给程序的命令行参数，一般设为空即可
         "stopAtEntry": false, // 设为true时程序将暂停在程序入口处，一般设置为false
         "cwd": "${workspaceRoot}", // 调试程序时的工作目录，一般为${workspaceRoot}即代码所在目录
         "environment": [],
         "externalConsole": false, // 调试时是否显示控制台窗口，一般设置为true显示控制台
         "MIMode": "gdb",
         "miDebuggerPath": "C:\\TDM-GCC-64\\bin\\gdb64.exe", // miDebugger的路径，注意这里要与MinGw的路径对应
         "preLaunchTask": "g++", // 调试会话开始前执行的任务，一般为编译程序，c++为g++, c为gcc
         "setupCommands": [{
           "description": "Enable pretty-printing for gdb",
           "text": "-enable-pretty-printing",
           "ignoreFailures": true
         }]
       }
     ]
   }
   ```

3. `tasks.json`

   ```C++
   {
     "version": "2.0.0",
     "tasks": [{
       "label": "g++",
       "command": "g++",
       "args": [
         "-g",
         "${file}",
         "-o",
         "${fileDirname}/${fileBasenameNoExtension}.exe"
       ],
       "problemMatcher": {
         "owner": "cpp",
         "fileLocation": [
           "relative",
           "${workspaceRoot}"
         ],
         "pattern": {
           "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
           "file": 1,
           "line": 2,
           "column": 3,
           "severity": 4,
           "message": 5
         }
       },
       "group": {
         "kind": "build",
         "isDefault": true
       }
     }]
   }
   ```




# 附录 基本数据类型

## 基本的内置类型

C++ 为程序员提供了种类丰富的内置数据类型和用户自定义的数据类型。下表列出了七种基本的 C++ 数据类型：

| 类型     | 关键字  |
| :------- | :------ |
| 布尔型   | bool    |
| 字符型   | char    |
| 整型     | int     |
| 浮点型   | float   |
| 双浮点型 | double  |
| 无类型   | void    |
| 宽字符型 | wchar_t |



| 类型               | 位            | 范围                                                         |
| :----------------- | :------------ | :----------------------------------------------------------- |
| char               | 1 个字节      | -128 到 127 或者 0 到 255                                    |
| unsigned char      | 1 个字节      | 0 到 255                                                     |
| signed char        | 1 个字节      | -128 到 127                                                  |
| int                | 4 个字节      | -2147483648 到 2147483647                                    |
| unsigned int       | 4 个字节      | 0 到 4294967295                                              |
| signed int         | 4 个字节      | -2147483648 到 2147483647                                    |
| short int          | 2 个字节      | -32768 到 32767                                              |
| unsigned short int | 2 个字节      | 0 到 65,535                                                  |
| signed short int   | 2 个字节      | -32768 到 32767                                              |
| long int           | 8 个字节      | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807      |
| signed long int    | 8 个字节      | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807      |
| unsigned long int  | 8 个字节      | 0 到 18,446,744,073,709,551,615                              |
| float              | 4 个字节      | 精度型占4个字节（32位）内存空间，+/- 3.4e +/- 38 (~7 个数字) |
| double             | 8 个字节      | 双精度型占8 个字节（64位）内存空间，+/- 1.7e +/- 308 (~15 个数字) |
| long double        | 16 个字节     | 长双精度型 16 个字节（128位）内存空间，可提供18-19位有效数字。 |
| wchar_t            | 2 或 4 个字节 | 1 个宽字符                                                   |

> type:           ************size**************
> bool:           所占字节数：1   最大值：1               最小值：0
> char:           所占字节数：1   最大值：               最小值：
> signed char:    所占字节数：1   最大值：               最小值：
> unsigned char:  所占字节数：1   最大值：                最小值：
> wchar_t:        所占字节数：2   最大值：65535           最小值：0
> short:          所占字节数：2   最大值：32767           最小值：-32768
> int:            所占字节数：4   最大值：2147483647      最小值：-2147483648
> unsigned:       所占字节数：4   最大值：4294967295      最小值：0
> long:           所占字节数：4   最大值：2147483647      最小值：-2147483648
> unsigned long:  所占字节数：4   最大值：4294967295      最小值：0
> double:         所占字节数：8   最大值：1.79769e+308    最小值：2.22507e-308
> long double:    所占字节数：16  最大值：1.18973e+4932   最小值：3.3621e-4932
> float:          所占字节数：4   最大值：3.40282e+38     最小值：1.17549e-38
> size_t:         所占字节数：8   最大值：18446744073709551615    最小值：0
> string:         所占字节数：32
> type:           ************size**************

## typedef 声明

您可以使用 **typedef** 为一个已有的类型取一个新的名字。下面是使用 typedef 定义一个新类型的语法：

```
typedef type newname; 
```

例如，下面的语句会告诉编译器，feet 是 int 的另一个名称：

```
typedef int feet;
```

现在，下面的声明是完全合法的，它创建了一个整型变量 distance：

```
feet distance;
```

## 枚举类型

枚举类型(enumeration)是C++中的一种派生数据类型，它是由用户定义的若干枚举常量的集合。

如果一个变量只有几种可能的值，可以定义为枚举(enumeration)类型。所谓"枚举"是指将变量的值一一列举出来，变量的值只能在列举出来的值的范围内。

创建枚举，需要使用关键字 **enum**。枚举类型的一般形式为：

```
enum 枚举名{ 
     标识符[=整型常数], 
     标识符[=整型常数], 
... 
    标识符[=整型常数]
} 枚举变量;
    
```

如果枚举没有初始化, 即省掉"=整型常数"时, 则从第一个标识符开始。

例如，下面的代码定义了一个颜色枚举，变量 c 的类型为 color。最后，c 被赋值为 "blue"。

```
enum color { red, green, blue } c;
c = blue;
```

默认情况下，第一个名称的值为 0，第二个名称的值为 1，第三个名称的值为 2，以此类推。但是，您也可以给名称赋予一个特殊的值，只需要添加一个初始值即可。例如，在下面的枚举中，**green** 的值为 5。

```
enum color { red, green=5, blue };
```

在这里，**blue** 的值为 6，因为默认情况下，每个名称都会比它前面一个名称大 1，但 red 的值依然为 0。



# 附录 cmath 常用函数：

## 取绝对值-fabs(double)

```
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double a=-12.1;
	a=fabs(a);
	cout<<a;
	
 } 
12345678910
```

结果返回double类型：

```
12.1
1
```

## 向上取整和向下取整-floor（double）和ceil（double）

```
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double a=-12.1,b,c;
	b=floor(a);//向下取整
	c=ceil(a);//向上取整
	cout<<b<<endl<<c<<endl;
	
 } 
1234567891011
```

结果返回double类型：

```
-13
-12
12
```

## 次方函数-pow（double a，double b）

返回a的b次方，double类型。

## 开平方根函数-sqrt（double x）

返回根号a，double类型。

## log函数-log（double x）

返回以自然对数为底的对数。

## 三角函数

```
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double pi=acos(-1);
	double a=sin(pi*45/180);
	double b=cos(pi*45/180);
	double c=tan(pi*45/180);
	cout<<a<<endl<<b<<endl<<c;
	
 } 
123456789101112
```

pi是圆周率的精确定义，注意这里用的是弧度制，而不是角度制，返回：

```
-0.707107
-0.707107
1.000000
123
```

## 四舍五入函数-round（double x）

返回x的四舍五入，double类型