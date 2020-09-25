# [Linux C语言结构体](https://www.imooc.com/learn/409)

# 第一章 课程介绍

## 

# 第二章 预处理

## 2.1 什么是预处理？

- 编译四个步骤
  - `.C文件` →(**预处理**) `.i文件` →(**编译**) `.s文件` →(**汇编**) `.o文件` →(**链接**) 可执行文件
- 预处理
  1. 展开头文件
  2. 宏替换

## 2.2 宏定义

- 宏定义

  - ```C
    #include <stdio.h>
    #define R 10        /*宏定义*/
    #define M int main( /*宏定义*/
    
    M)
    {
      int a = R;
      printf("a=%d\n", a);
      printf("hello world\n");
      return 0;
    }
    ```

  - 在预编译阶段替换，单纯的字符串替换，**不考虑C语法**，不用加 `;`

    - 常量
    - 数组 buffer

## 2.3 宏函数

- ```C
  #include <stdio.h>
  #define R 20        /*宏定义*/
  #define M int main( /*宏定义*/
  #define N(n) n * 10 /*宏定义*/
  #define ADD(a, b) (a + b) /*宏定义 加括号提高计算优先级*/
  int add(int a, int b) { return a + b; }
  M)
  {
    int a = R;
    printf("a=%d\n", a);
    printf("hello world\n");
  
    int b = N(a); // int b=a*10;
    printf("b=%d\n", b);
  
    int c = add(a, b); // 函数
    printf("c=%d\n", c);
  
    int d = ADD(a, b); // 宏函数替换
    printf("d=%d\n", d);
  
    int e = ADD(a, b) * ADD(a, b); // 预处理后 宏替换为：a+b*a+b。运算是编译时执行
    printf("e=%d\n", e);
  
    int f = ADD(10.5, 10);
    printf("f=%d\n", f);
  
    float h = ADD(10.5, 10); // 宏替换不考虑数据类型
    printf("h=%f\n", h);
  
    // 宏替换 条件编译
  
    return 0;
  }
  ```

  

## 2.4 typedef

- `typedef`：给变量类型起别名

  - `typedef int tni;`：把`int` 取别名 `tni`；
  - 不同于宏替换，预处理之后别名任然有效，等于普通变量
  
- 通常用法，声明结构体类型

  - ```C
    typedef struct 类型名{
      // 声明和函数
    }实例化变量;
    ```



# 第三章 结构体

## 3.1 声明和定义

- 创建结构体类型

  - ```C
    struct weapon
    {
      char name[20];
      int atk;
      int price;
    };
    ```

- 声明变量

  - 可以直接在尾部定义变量

    - ```C
      struct weapon// 可以不声明结构体类型名字,但不能重复使用
      {
        char name[20];
        int atk;
        int price;
      }weapon_1;
      ```

  - 也可以单独定义

    - ```C
      #include <stdio.h>
      struct weapon //自定义类型
      {
        char name[20];
        int atk;
        int price;
      } weapon_2; //可以直接在尾部定义变量
      int main()
      {
        int a = 0;
        float b = 0.0;
      
        struct weapon weapon_1; // 可以省略 struct
      
        return 0;
      }
      ```

    

## 3.2 初始化和引用

- 访问结构体成员

  - 初始化列表

    - 传入参数与结构体参数依次对应

    - 可以省略 `struct`

    - ```C
        struct weapon weapon_1 = {"weapon_name", 100, 200};
      ```

      

  - 使用 `.` 运算符访问结构体成员变量

    - `.` 运算符优先级最高

    - 成员变量可以进行运算

    - ```C
        printf("%s\n", weapon_1.name);
      ```

    - ```C
        printf("%s\n%d\n", weapon_1.name, ++weapon_1.price);
      ```

- 结构体数组

  - ```C
      // 结构体数组的使用方法
      struct weapon weapon_2[2] = {"weapon_name1", 100, 200, "weapon_name2", 300, 400}; //每个数据项可以用{}括起来
      printf("%s\n%d\n", weapon_2[0].name, weapon_2[1].atk);
    ```

    

## 3.3 结构体指针

- 指向结构体变量的指针变量

  - 点运算符优先级高于 `*` ，要加括号。也可以使用指针指向运算符

  - ```C
      // 结构体指针
      struct weapon *w;
      w = &weapon_1;
      printf("name=%s\n", (*w).name); //点运算符优先级高于 * ，要加括号
      // 使用指针指向运算符
      printf("name=%s\n", w->name);
    ```

- 指向结构体数组的指针变量

  - ```C
      // 指针指针结构体数组
      struct weapon *p;
      p = weapon_2; // p->name;  p 里面是 wapon_2[0].name
      printf("name=%s\n", p->name);
      // p+1 指针第二个成员
      printf("name=%s\n", (++p)->name);
    ```

    

# 第四章 共用体

## 4.1 共用体

- 也称为联合体，关键字：`union`

**结构体与共用体不同：**

- 结构体大小 = 最后一个成员的偏移量 + 最后一个成员的大小 + 末尾填充字节数

  - 偏移量：某一成员地址与结构体首地址的距离

  - 每个成员相对于首地址的偏移量都得是**当前成员所占内存的整数倍**

  - 然后判断是不是**最宽变量类型的整数倍**

    - ```C
      struct data
      {
        int a;  // 4字节
        char b; // 1字节,填充三字节
        int c;  // 偏移量为8字节, 结构体总大小12字节, 然后判断是不是最宽变量类型的整数倍
      };
      ```

- 共用体

  - **初始化表只能有一个参数**

  - **所有变量共用内存地址**

  - ```C
    #include <stdio.h>
    union data 
    {
      int a;  
      char b; 
      int c; 
    };
    int main()
    {
      union data data_1; // 初始化表只能有一个常量
      data_1.b = 'C';
      data_1.a = 10; // 共用内存，覆盖前面的成员
      printf("%d\n %d\n", data_1.b, data_1.a);
      return 0;
    }
    ```

    

# 第五章 动态数据结构

## 5.1 静态链表

- 创建静态链表

  - ```C
    #include <stdio.h>
    struct weapon //自定义类型作为节点元素
    {
      int price;
      int atk;
      struct weapon *next; // 存放下一个节点的地址
    };
    int main()
    {
      struct weapon a, b, c, *head;
      a.price = 100;
      a.atk = 100;
      b.price = 200;
      b.atk = 200;
      c.price = 300;
      c.atk = 300;
      // 连成链表
      head = &a;
      a.next = &b;
      b.next = &c;
      c.next = NULL;
      // 生成指针p 访问结点
      struct weapon *p;
      p = head;
      while (p != NULL)
      {
        printf("%d,%d\n", p->atk, p->price);
        p = p->next;
      }
      
      return 0;
    }
    ```

  

## 5.2 动态链表

- 程序运行时创建新节点。

- 单向动态链表

  - ```C
    #include <stdio.h>
    #include <malloc.h>
    struct weapon //自定义类型作为节点元素
    {
      int price;
      int atk;
      struct weapon *next; // 存放下一个节点的地址
    };
    
    struct weapon *create()
    {
      struct weapon *head;
      struct weapon *p1, *p2;
      int n = 0;
      // malloc 分配内存 , sizeof 判断数据类型长度
      p1 = p2 = (struct weapon *)malloc(sizeof(struct weapon));
      scanf("%d,%d", &p1->price, &p1->atk); // 输入格式: 数据,数据
      head = NULL;
      while (p1->price != 0)
      {
        n++;
        if (n == 1)
          head = p1;
        else
          p2->next = p1;
    
        p2 = p1;
        p1 = (struct weapon *)malloc(sizeof(struct weapon));
        scanf("%d,%d", &p1->price, &p1->atk);
      }
      p2->next = NULL;
      return head;
    }
    int main()
    {
      struct weapon *p;
      p = create();
      printf("%d,%d", p->price, p->atk);
      return 0;
    }
    ```

    

# 第六章 位运算

- 比加减运算快一点，比乘除运算快很多
- `~` : 按位取反

## 6.1 按位与 `&`

- 二进制数进行逻辑与运算

  - **必须是整型或字符型，必须补码形式**

  - ```C
    #include <stdio.h>
    #include <malloc.h>
    int main()
    {
      // & | ^ ~ << >>
      int a = 4; // 00000000 00000000 00000000 00000100
      int b = 7; // 00000000 00000000 00000000 00000111
                 // 00000000 00000000 00000000 00000100
      int C = a & b;
      printf("%d\n", C);
    
      // 迅速清零： 与 0 按位与
      int zero = a & 0;
      printf("%d\n", zero);
    
      // 保留指定位: b 低八位 置1, a&b, 得到 a 的低八位
      // 判断奇偶性: a&1=1 则是奇数，a&1=0 则是偶数
      return 0;
    }
    ```

    

## 6.2 按位或 `|`

```C
#include <stdio.h>
int main()
{
  //&|^~<< >>
  int a = 9; // 00000000 00000000 00000000 00001001
  int b = 5; // 00000000 00000000 00000000 00000101
             // 00000000 00000000 00000000 00001101
  int C = a | b;
  printf("c=%d\n", c);
  a = a | 0xFF; //低八位 置1
  printf("a=%d\n", a);
  return 0;
}
```



## 6.3 按位异或 `^`

```C
#include <stdio. h>
int main(){
  //&|^~<<>>
  int a=9;//0000 1001
  int b=5;//0000 0101
  				//0000 1100
  int c=a^b;
  printf("c=%d\n",c);
  
  // 定位翻转
  // 数值交换
  a = a^b;
  b=b^a;
  a=a^b;
  printf("a=%d\n, b=%d\n" ,a,b);

  return 0;
}
```

- 取反 `~` 右结合性

  - ```C
    ~( 00001001 ) // 11110110
    ```

    

## 6.4 左移右移 `<<` `>>`

- 高位丢弃，低位补零
  - 左移：乘以 2 的 n 次方
  - 右移：除以 2 的 n 次方

```C
#include <stdio. h>
int main(){
// &|^~<<>>
int a=3; //00000000 00000000 00000000 00000011
a= a<<4; //00000000 00000000 00000000 00110000
int i=1; //00000001
				 //00000100
return 0;
}
```



# 第七章 重识递归函数

## 7.1 递归调用

- 在调用函数过程中被调用的函数调用它本身的过程

  - ```C
    #include <stdio.h>
    int func(int n)
    {
      int r;
      if (n < 0)
        printf("data error\n");
      else if (n == 0 | n == 1)
        r = 1;
      else
        r = n * func(n - 1);
      return r;
    }
    int main()
    {
      int n;
      printf("pLease input n\n");
      scanf("%d", &n);// 4字节 n 不能超过31阶
      int result = func(n);
      printf("result = %d\n", result);
      return 0;
    }
    ```

    

## 7.2 递归原理

- 函数调用

  ```C
  int functionB(int a,int b){
  return (a+b);
  }
  int functionA(){
  functionB(10,10);
  return 0;
  }
  ```

- 递归与递推

  - 递归
    - 从高阶到低阶可求解，再到高阶
  - 递推
    - 从低阶到高阶



# 附录：C++与C不兼容之处

C的大部分代码在C++上都能应用，而C++的代码在C上不能应用。（记住是大部分，不是所有）

C++是C语言的超集，虽然C++兼容C，但是C++中也有与Ｃ语言中不兼容的地方。



### 4.1 变量声明的位置

C中变量声明和代码是分开的，必须在函数开始处声明；

C++中，变量可以在任意处声明，只要保证先声名后使用的原则就可以。



### 4.2 struct结构体方面

用`struct`定义变量

`struct mystruct{ int i;float x;`

在`c`中声明`struct`变量要这么写：`struct mystruct a;`

在`C++`中前面不用加`struct：mystruct a;`

一种兼容的用法是：

`typedef struct _mystructint i;float x;} mystruct;`

然后用`mystruct` 定义变量。枚举型(`enum`),联合体类型(`union`)也是同样。

在C++中，`struct`结构体支持成员函数的定义，C中不行。另外要注意的是，C++中成员函数的默认访问说明符为`public`,这一点和类不同，类的默认访问说明符为`private`.



### 4.3 bool类型值

C++中有`bool`(或`boolean`类型);`C`中可没有这样的`bool`类型，均为数值类型！需要注意的是真为非零(如：１，５２，-５，-２等)，假的数值为０。



### 4.4 注释的不同

C中的注释至有一种 `/*......*/`;

C++中的注释包含两种`/*......*/和//`。



### 4.5 强制数据类型装换

Ｃ中的强制转化形式为：`(类型)变量`；

C++中还可以使用:`类型(变量)`的形式。



### 4.6 赋值

C语言中的赋值只有一中即：`=;`

C++中除了使用`=`外，还可以使用`()`。例如：`int x(5)`；就等于: `int x=5;`我想这种写法是给C++中对象初始化时初始化属性是对象时使用的，那么对于基本类型也可以使用了。



### 4.7 函数

Ｃ语言中函数没有参数默认值，在C++中函数有参数默认值的概念，注意参数默认值与函数重载的区别。

C语言中函数的定义又两种形式，经典形式和标准形式，C++中只支持标准形式。

标准形式：`int string(int x,float y){......}`

经典形式: `int string(x,y)int x;float y;{......}`

C++的函数必须先声名原型或定义才能使用,因为C++是强数据类型语言,在C语言中,未声名和定义函数之前调用函数是允许的.



### 4.8 运算符&和关键字const

`&`运算符最基本的含义是取地址，C和Ｃ++中都支持这一语法。但在C++中`&`还可以表示引用。有了引用的概念后函数调用可以作为左值。例如：

`int &rtux()......rtux()=5;`

以上表达式在C++中完全正确，但在C语言中是非法的。

`const`关键字要注意一点不同的就是在C++的类函数中，函数可以声名是可以用`const`，表示这个函数没有改变类中的任何属性。如：`void unchange()const; ` C 不能有这样的生明。



### 4.9 extern说明符

在C语言的某些版本中，可以在程序中多次使用一个全局变量而无需使用`extern`说明符。但在C++中除定义全局变量外，在其他模块使用应先用`extern`生明。



### 4.10 void指针

在C语言中`void`指针可以赋给任何类型的指针，但在C++中，却不行，但可以先进行强制数据类型转换，在赋值。

 