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

## 第二节 面向对象程序设计的概念和特点

## 第三节 类的初步知识

## 第四节 类的示例程序剖析

## 第五节 访问对象的成员

## 第六节 类成员的可访问范围

## 第七节 标识符的作用域与可见性



# 第三章 类和对象进阶

- 构造函数、析构函数、复制构造函数
- 特殊成员，包括静态成员、常量成员、常引用成员
- 类成员的生存期及作用域
- 封闭类的概念，定义封闭类
- 友元函数
- this 指针

## 第一节 构造函数

## 第二节 析构函数

## 第三节 类的静态成员

## 第四节 变量及对象的生存期和作用域

## 第五节 常量成员和常引用成员

## 第六节 成员对象和封闭类

## 第七节 友元

## 第八节 this 指针



# 第四章 运算符重载

- 运算重载符
- 运算重载符作为成员函数和友元函数的两种方式
- 对自己定义的类重载运算符
- 对特定类重载前置和后置异同
- 浅拷贝和深拷贝

## 第一节 运算符重载的概念

## 第二节 重载赋值运算符

## 第三节 重载流插入运算符和流提取运算符

## 第四节 重载强制类型转换运算符

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

## 第二节 访问控制

## 第三节 派生类的构造函数和析构函数

## 第四节 类之间的关系

## 第五节 多层次的派生

## 第六节 基类与派生类指针的相互转换



# 第六章 多态与虚函数

- 多态原理
- 虚析构函数
- 纯虚函数

## 第一节 多态的基本概念

## 第二节 多态实例

## 第三节 多态的使用

## 第四节 虚析构函数

## 第五节 纯虚函数和抽象类



# 第七章 输入/输出流

- cin cout 重定向
- 格式控制
- 常见成员函数

## 第一节 流类简介

## 第二节 标准流对象

## 第三节 控制 IO 格式

## 第四节 调用 cout 的成员函数

## 第五节 调用 cin 的成员函数



# 第八章 文件操作

- 文件
- ifstream、ofstream、fstream
- 顺序访问和随机访问，文件读写指针和移动文件指针

## 第一节 文件基本概念和文件流类

## 第二节 打开和关闭文件

## 第三节 文件读写操作

## 第四节 随机访问文件



# 第九章 函数模板与类模板

- 函数模板
- 类模板
- 模板与继承

## 第一节 函数模板

## 第二节 类模板



