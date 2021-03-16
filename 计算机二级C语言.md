# 计算机二级C语言

https://www.bilibili.com/video/BV1sb411a7h6

## 第二章 C基础

### 数据类型

<img src="计算机二级C语言.assets/image-20210228165002037.png" alt="image-20210228165002037" style="zoom:50%;" />

<img src="计算机二级C语言.assets/image-20210228165107432.png" alt="image-20210228165107432" style="zoom: 50%;" />

<img src="计算机二级C语言.assets/image-20210228165302131.png" alt="image-20210228165302131" style="zoom: 50%;" />

![image-20210228165518360](计算机二级C语言.assets/image-20210228165518360.png)

### 算术表达式

![image-20210228165735248](计算机二级C语言.assets/image-20210228165735248.png)

![image-20210228171058198](计算机二级C语言.assets/image-20210228171058198.png)

运算规则（优先级）：先函数，再括号后乘除，终加减，最后赋值

1. 等号优先级最低, 先计算右边, 在赋值给左边
2. n=n+1;有意义, 在原有变量n的基础上,增加1;
3. 左边不能是表达式a+b=c错误
4. 右边可以是赋值表达式a=b=7+1; 但是a=7+1=b是错误的

### 一些容易出错的优先级问题

上表中，优先级同为1 的几种运算符如果同时出现，那怎么确定表达式的优先级呢？这是很多初学者迷糊的地方。下表就整理了这些容易出错的情况：

![img](http://c.biancheng.net/cpp/uploads/allimg/120205/1-120205192420113.jpg)

### 复合赋值表达式

主要运算符号

```
+= -= /= *=
例:
n+=1;(n=n+1)
n*=m+1(n=n*(m+1))
```

例: 已有变量a, 其值为9, 计算表达式a+=a-=a+a的值
1.先计算a+a=18
2计算a-=18 (此时a仍然是9) a=a-18a变成9
3计算 a+=9 (此时a是9) a=a+(-9) a变

### 赋值运算的类型转换

赋值两边类型不一致,将等号右侧的值转换成左侧数据类型,仅限数值,成为"赋值兼容
整数运算符转换原则

1. 运算符号两边一个短整型,一个长整型,都转化成长整型
2. 运算符号两边一个无符号,一个有符号,都转化成无符号

整数赋值转换原则

1. 左短右长,截取右边,丢高保低
2. 左无右有,复制右边,负数变整数
3. 左有右无,复制右边,高位为1,变负数

### 自增 自减 逗号 运算符号

![image-20210228212639736](计算机二级C语言.assets/image-20210228212639736.png)

1自增、自减符号可以放在变量前面形成前缀也可以放在后面形成后缀
2如果是前缀,先做自我运算,后运行语句;
3如果是后缀,先运行语句,后做自我运算;
4.不要在一个表达式中多次对同一个变量做运算

### 逗号表达式

逗号表达式运算法则从左到右,一个表达式一个表达式计算,全部运算完毕后,

**最后一个表达式的结果是整个表达式的值**
例:

```
(i=3,i++,++i,i+5)
表达式的值为10,
i的值是5
```



## 第三章 顺序结构

### 赋值语句

赋值语句也称作表达式语句,主要在赋值表达式后加入分号;就构成表达式语句

```
int i=10;∥/赋初值语句
12;/赋值语句
```



### 数据输出

![image-20210228214148828](计算机二级C语言.assets/image-20210228214148828.png)

#### 输出修饰符

![image-20210228215047599](计算机二级C语言.assets/image-20210228215047599.png)

![image-20210228215639828](计算机二级C语言.assets/image-20210228215639828.png)

#### 长度修饰符

![image-20210228215908532](计算机二级C语言.assets/image-20210228215908532.png)

![image-20210228220346134](计算机二级C语言.assets/image-20210228220346134.png)

![image-20210228220444566](计算机二级C语言.assets/image-20210228220444566.png)

重点考第七种

![image-20210228221324734](计算机二级C语言.assets/image-20210228221324734.png)

`printf`中是右运算

### 数据输入

![image-20210228222320578](计算机二级C语言.assets/image-20210228222320578.png)

#### 输入格式控制符

![image-20210228222706786](计算机二级C语言.assets/image-20210228222706786.png)

#### `scanf`函数的使用说明

![image-20210228222939558](计算机二级C语言.assets/image-20210228222939558.png)

![image-20210228224523963](计算机二级C语言.assets/image-20210228224523963.png)

![image-20210228224810423](计算机二级C语言.assets/image-20210228224810423.png)

![image-20210228224924300](计算机二级C语言.assets/image-20210228224924300.png)

### 复合语句和空语句

![image-20210228232358154](计算机二级C语言.assets/image-20210228232358154.png)

### 算法-后两位四舍五入

原理
(1)原数乘以100
(2)加上0.5
(3)取整
(4)除以100输出

![image-20210228233651472](计算机二级C语言.assets/image-20210228233651472.png)



## 第四章 选择结构

### 关系运算和逻辑运算

![image-20210301154207159](计算机二级C语言.assets/image-20210301154207159.png)

![image-20210301175121668](计算机二级C语言.assets/image-20210301175121668.png)

![image-20210301175152857](计算机二级C语言.assets/image-20210301175152857.png)

### 逻辑运算符

双目运算符 单目运算符

![image-20210301175428058](计算机二级C语言.assets/image-20210301175428058.png)

### if语句和用if语句构成的选择结构

![image-20210301180319126](计算机二级C语言.assets/image-20210301180319126.png)

![image-20210301180420205](计算机二级C语言.assets/image-20210301180420205.png)

### 条件表达式

![image-20210301181927291](计算机二级C语言.assets/image-20210301181927291.png)

### switch语句

![image-20210301182238106](计算机二级C语言.assets/image-20210301182238106.png)

![image-20210301232201980](计算机二级C语言.assets/image-20210301232201980.png)

switch 是另外一种选择结构的语句，用来代替简单的、拥有多个分枝的 if else 语句，基本格式如下：

```c
switch(表达式){
  case 整型数值1: 语句 1;
  case 整型数值2: 语句 2;
  ......
  case 整型数值n: 语句 n;
  default: 语句 n+1;
}
```

```c
#include <stdio.h>

int main()
{
  int i = 10, f;
  scanf("%d", &f);
  switch (i / f)
  {
  case 2:
    printf("2");
  case 5:
    printf("5");
  case 10:
    printf("10");
    break;
  default:
    printf("Null");
  }
  return 0;
}

```

它的执行过程是：
1) 首先计算“表达式”的值，假设为 m。

2) 从第一个 case 开始，比较“整型数值1”和 m，如果它们相等，就**执行冒号后面的所有语句**，也就是从“语句1”一直执行到“语句n+1”，而**不管后面的 case 是否匹配成功**。

3) 如果“整型数值1”和 m 不相等，就跳过冒号后面的“语句1”，继续比较第二个 case、第三个 case……一旦发现和某个整型数值相等了，就会执行后面所有的语句。假设 m 和“整型数值5”相等，那么就会从“语句5”一直执行到“语句n+1”。

4) 如果直到最后一个“整型数值n”都没有找到相等的值，那么就执行 default 后的“语句 n+1”。

需要重点强调的是，当和某个整型数值匹配成功后，会执行该分支以及后面所有分支的语句。

由于 default 是最后一个分支，匹配后不会再执行其他分支，所以也可以不添加`break;`语句。

1. case 后面必须是一个整数，或者是结果为整数的表达式，但不能包含任何变量。
2. default 不是必须的。当没有 default 时，如果所有 case 都匹配失败，那么就什么都不执行。



## 第五章 循环结构

### 5.1 while和do-while

![image-20210301234921036](计算机二级C语言.assets/image-20210301234921036.png)

![image-20210301235220621](计算机二级C语言.assets/image-20210301235220621.png)

***do-while 分号结尾***

### 正负号累加算法

![image-20210302001438279](计算机二级C语言.assets/image-20210302001438279.png)

整型/浮点型=浮点型；使用 1.0/n 使整型转换为浮点型

### 精度处理

```c
abs() /*取整数绝对值*/
fabs() /*取整数绝对值*/
```

![image-20210302003225860](计算机二级C语言.assets/image-20210302003225860.png)

### 5.2 重要算法 斐波那契数列

![image-20210303234513413](计算机二级C语言.assets/image-20210303234513413.png)

```c
#include <stdio.h>

int main()
{
  int f, f1 = 0, f2 = 1;
  printf("%d,", f1);
  do
  {
    printf("%d,", f2);
    f = f1 + f2;
    f1 = f2;
    f2 = f;
  } while (f2 <= 1000);
  return 0;
}
```



### 5.3 for循环

![image-20210316150204808](计算机二级C语言.assets/image-20210316150204808.png)

三个参数都可以省略。分号不能省略。



### 5.4 循环嵌套 重点算法判断质数（素数）

重点算法判断质数（素数）
1.什么是质数？
能够被1和自身整除的数
2.最小的质数？
2″是最小的质数
3.如何判断—个数是不是质数？
从2开始到此数之间没能找到一个数
将其除尽，此数为质数。

### 5.5 continue 语句 break 语句

结束本次循环

跳出所有循环

![image-20210316150956225](计算机二级C语言.assets/image-20210316150956225.png)

![image-20210316151401498](image-20210316151401498.png)



## 第六章 字符型数据

大纲中只规定了字符串与字符数组。
但本章内容涉及以下内容：

1. 字符常量，字符串常量
2. 字符变量的定义及使用
3. 字符型与整型数据的换算关系
4. 转义字符
5. 字符的输入与输出



### 6.1 字符型常量

![image-20210316151840802](计算机二级C语言.assets/image-20210316151840802.png)

![image-20210316153247522](计算机二级C语言.assets/image-20210316153247522.png)

![image-20210316153650534](计算机二级C语言.assets/image-20210316153650534.png)

**字符常量**

![image-20210316153710178](计算机二级C语言.assets/image-20210316153710178.png)

**什么是转义字符常量？**
单引号括起来，中间由反斜杠开头后跟一个特定字符。
常用转义字符

```c
\n回车换行
\t个制表符（按键盘tab键出现的空格数）
\r回车符 
\\输出反斜杠
\'单引号字符
\"双引号字符
\O空值（屏幕不可见）ACSII值0
注意：
\数字’只代表一个字符
```

**什么是字符串常量？**
双引号括起来，中间由若干字符和
转义字符组成。

`例如：“abd"“acb\n"`

**字符计算**

```c
'B'-'A'=1;
'a'-'A'=32;
```



### 6.2字符变量

定义形式

```c
char 变量名 [=值]
例
char a='a';
char a=97;
```

![image-20210316155648733](计算机二级C语言.assets/image-20210316155648733.png)



### 6.3 字符的输入输出

字符输出：`putchart(字符)` 等同于 `printf("%c",char)`
字符输入：`变量= getchar()` 等同于 `sacnf("%c",&char)`
注意:
空格、tab、回车会被接收



### 重点算法 字母大小写转换

例：把从终端输入的小字母转换成大写字母，其他字符不变
分析

1. 小写字母转大写需要减去32
2. 如何判断小写字母，在`a`到`z`之间的字符

```c
#include <stdio.h>
int main()
{
  char c;                         //定义一个字符型变量
  while ((c = getchar()) != '\n') //没有读入字符没有到回车时候转换
  {
    if (c >= 'a' && c <= 'z')
    {
      c = c - 'a' + 'A'; //或者直接写c=c-32
      putchar(c);        //输出字符c
    }
  }
  putchar('\n');
}
```



### 重点算法 统计字符个数

例:统计字符中大写字母和小写字母个数

```c
#include <stdio.h>
int main()
{
  int s = 0, b = 0, n = 0; //定义变量s为小写字母数量,b为大写字母数量,n数字
  char c;
  while ((c = getchar()) != '\n')
  {
    if (c >= 'a' && c <= 'z')
      s++;
    if (c >= 'A' && c <= 'Z')
      b++;
    if (c >= '0' && c <= '9')
      n++;
  }
  printf("%d,%d,%d", s, b, n);
}
```



## 第七章 函数

1. 库函数的正确调用.
2. 函数的定义方法.
3. 函数的类型和返回值.
4. 开式参数与实在参数,参数值的传递.
5. 函数的正确调用,**嵌套调用,递归调用.**
6. **局部变量和全局变量.**
7. **变量的存储类别(自动,静态,寄存器,外部)，变量的作用域和生存期**

### 7.1 库函数

1. C语言是由函数组成的从 `main()`函数开始,在`main()`函数中结束
2. 标准库函数的引入通过命令行的形式 `#include<库函数头文件>`或者`#include"库函数头文件"`
3. 标准库函数的调用形式: 函数名(参数表)
   例：`y=sqrt(13);//开平方`

**常用数学函数**

- pow(底数,指数) 求幂
- sqrt(数值) 开平方
- abs(整数值) 取整数的绝对值
- fabs(实型值) 取实型值的绝对值
- sin(实型) 取得sin值
- cos(实型) 取得cos值
- exp(实型) 以自然对数e为底的幂



### 7.2 函数的定义和返回值

用户自定义函数的一般形式:

```c
函数返回值的类型名 函数名(类型名形参1, 类型名形参2,...)/*函数的首部*/
{
说明部分           /函数体*/
语句部分  
}
```

注意:

1. 函数名及形参由用户定义的标识符组成
2. 同一程序中函数名必须唯一
3. 形参名字在同一函数中命名唯一
4. **不能函数内部定义函数**
5. 如果**不指定返回值类型, 返回值为int型**
6. 函数调用前必须先定义(说明)
7. 无返回值,在函数返回类型处,用 void



**返回值**

函数返回值通过 return语句返回,形式: return表达式

一个函数中允许有多条 return,但是只能有一条执行





### 7.3 函数的调用

调用方法:

1. 函数名(实在参数表)

2. 函数名() 无实参情况
   例

   ```c
   double x=10.2,y=19.3,z;
   z=add(x,y);
   ```

函数调用原则：先定义，后调用。如果函数在调用之后，除返回值是int和char型的，都需要在程序之前进行说明

```c
char b()
{
  printf("bbbb");
}
#include <stdio.h>
double c()
{
  printf("ccc");
}

double d();

// 函数调用与声明
int main()
{
  double e();
  a();
  b();
  c();
  d();
  e();
}
int a()
{
  printf("aaaa");
}
// char a()
// {
//   printf("aaaa");
// }
// double a()
// {
//   printf("aaaa");
// }

double d()
{
  printf("dddd");
}
double e()
{
  printf("eee");
}

```



### 7.5 函数调用之间的数据传递

函数调用中，实参的数据和形参对应传递
两种传递方式

1. 值传递
   只传送值，实参不做改变
2. 地址传递
   传送地址，实参被改变

```c
#include <stdio.h>
void swap(int, int); /*函数说明*/
int main()
{
  int x = 10, y = 20;
  printf("(1)x=%d y=%d\n", x, y);
  swap(x, y); //值传递
  printf("(4)x=%d y=%d\n", x, y);
}
void swap(int a, int b)
{
  int t;
  printf("(2)a=%d b=%d\n", a, b);
  t = a, a = b, b = t;
  printf("(3)a=%d b=%d\n", a, b);
}
```



### 7.6 逗号表达式

逗号优先级最低

只保留右侧操作

右加加优先级低于传参

```c
#include <stdio.h>
#include <stdlib.h>
int main()
{
  int a = 1, b = 1;
  a = ++a, a + 10, a * 10;
  printf("a=%d", a);
  b = (++b, b + 10, b * 10);
  printf("b=%d", b);
  return 0;
}
```

![image-20210316181226371](计算机二级C语言.assets/image-20210316181226371.png)

21

![image-20210316181309884](计算机二级C语言.assets/image-20210316181309884.png)

5.5

![image-20210316181603099](计算机二级C语言.assets/image-20210316181603099.png)

4



## 第八章 地址和指针

1. 变量的地址和指针
2. 指针变量的定义和指针变量的基类型
3. 给指针变量赋值
4. 对指针变量的操作
5. 函数之间地址值的传递

### 8.1 变量地址和指针

计算机的内存是以字节为单位的一片连续的存储空间,每—个字节都有一个编号这个编号就成为内存地址.

每个变量的地址是指该变量所占存储单元的第一个字节的地址

回忆:

计算机的存储单位

一进制的位(bit)  8bit=1字节. 1024字节=1KB, 1024KB=1M, 1024M=1G

例: int a=5;在内存中的存储结构通过&a可以取出a在内存中的地址此时a的地址为1245052

一种特殊的变量
这种变量只是用来存放内存地址的,起名为指针变量
假设定义了一个只存地址的变量 p
把变量a的地址赋予指针变量 p,
则指针变量p的值为 1245052
当访问变量a时,访问的是什么? 5
当访问指针变量p时,访问的是什么? 1245052

当访问变量时,为"直接存取(直接访问)"
我们也可以通过指针变量间接的访问该地址中原来的值.此时称为"间接存取(间接访问)



### 8.2 指针变量的定义和指针变量的基类型

```c
int*pi;
int *pJ, *pa;
```

说明:

1. pl, pJ, pa都是变量,不过都是指针变量,定义时在普通变量名的左边加上星号就行了
2. pi,pj,pa三个指针变量的类型为整型,说明三变量中只能存放n类型变量的地址
3. 这时我们称n是指针变量 pi, pj, pa的基类型.



例: 

```c
double *pd;
char *s1,*s2;
pd的基类型为 dou ble类型,在指针变量pd中,
只能存放 double类型变量的地址.
s1和s2的基类型为char类型,在指针变量s1和
s2中,只能存放cha类型变量的地址
  
指向指针的指针
例:
int **p,k,*s=&k; // 先取*p，再取*（*p）
p=&s;
```



### 8.3 给指针变量赋值

```c
int k,*q,p;//*k为整型变量,q和p都是指针变量.*
k=1;//*给普通变量赋值
q=&K;//*整型变量k的地址赋值给指针变量q*/
p=q;//*将q的值赋值给p*/
```

```c
#include <stdio.h>
int main()
{
  int a, b = 2, *p = NULL;// 必须赋值后才能使用指针
  a = 1;
  p = &a;
  *p = b;
  printf("%d,%d,%p,%p,%p", *p, a, &p, p, &a);
}
```



**给指针变量赋值**
除了给指针变量赋地址值之外,还可以给指针变量赋—个特殊的值, 该值为"空"值
注意
此时,指针变量p中不是没有值,而是有一个空值。

通过指针来引用一个存储单元,"间址运算符 \*"

```c
#include <stdio.h>
main(){
int k,*q,*p;
q=&k;
p=97;
printf("%d\n%d\n%d\n k,*q,*p);
}
```



### 8.4 对指针变量的操作

址运算符说明

1. \*与\&是逆运算

2. 在指针变量已经存有某一变量地址时, 可以利用"\*变量=值"的形式给指针变量指向的内存空间赋值

3. 关于`++、--`号对指针变量的运算
   例:

   ```c
   ++*p 代表 ++(*p);
   p++ 代表 *(p++);
   
   如果在右边使用自增或者自减符号,必须加括号
   (*p)++
   ```

   

例:用指针指向两个变量,通过指针运算选出值最小的那个数

```c
#include <stdio.h>
main(){
  int a,b,min,*pa,*pb,*pmin;
  pa=&a; pb=&b; pmin=&min;
  scanf("%d%d",pa,pb);
  printf( "a=%d b=%d\",a,b);
  *pmin=*pa;
  if(*pa>*pb) *pmin=*pb;
  printf("min=%d\n", min);
}

```



**移动指针**
所谓移动指针就是对指针变量加上或减去个整数,或通过赋值运算,使指针变昰指向相邻的存储单元

形式:

1. 指针变量+整型常量
2. 指针变量+整型变量



假定在内存中开辟了如图所示的五个连续的存放int类型整数的存储单元.
并分别给它们取代号为:`a[0]、a[1]、a[2 ]a[3]、a[4]`
这些代号所代表的存储单元中,分别有值为: 11、22、33、44、55.p指向a0所在地址,p++代表a[1]

![image-20210316214814009](计算机二级C语言.assets/image-20210316214814009.png)



### 8.5 函数之间地址值的传递

形参为指针变量时实参和形参之间的数据传递

```c
#include <stdio. h>
int myadd (int *a, int *b)
{int sum;
sum=*a+*b
return sum;
 }
main(){
  Int x,y,z;
  pint(" Enter xy:") scanf("%d%d",&x,&y);
  z=myadd(&x, &y)
  printf("%d+%d=%d\n ",x,y,z);
}
```



## 第九章 数组

一维数组和二维数组的定义、初始化和数组元素的引用

1. 维数组的定义和一维数组元素的引用
2. 维数组和指针
3. 函数之间对维数组和数组元素的引用
4. 维数组应用举例
5. 二维数组的定义和二维数组元素的引用
6. 二维数组和指针
7. 二维数组名和指针数组作为实参



### 9.1 一维数组的定义和一维数组元素的引用

1. 什么是数组?

   数组是具有相同类型的变量的集合,这些变量在内存中占有连续的存储单元

   一维数组的定义形式如下:

   ```c
   类型名 数组名[整型常量表达式或整型常量]
   数组名:和变量名的命名规则相同
     
   [整型常量表达式]:也叫下标表达式,当只有一下标时,为一维数组,代表数组的数量
   ```

   ```c
   int a[8];//定义了一个名为a的一维数组
   	方括号中的8规定了a数组含有8个元素变量),
   它们是a0、a[1]、…a[7]
     类型名in规定了a数组中每个元素都是整型,在每个元素中只能存放整型数.
   在使用该数组时,它的下标范围是从0~7,即下标的下界为0,上界为7.
   ```

2. 在一个定义数组语句中,可以有多个数组说明符,
   它们之间用逗号隔开.如: `double w[22],v[100],u[5]`

3. 个数组元索实质上就是一个变量,代表内存中的一个存储单元.

   在引用数组元素时,数组元素中下标表达式的值必须是整数,下标表达式值的下限从0开始.



例9.1 编写程序,定义一个含有30个元素的int类型数组.

依次给数组元素赋奇数1、3、5、…
然后按每行10个数顺序输出,最后再按每行10个数逆序输出
分析
(1)定义30个元素的一维数组
(2)循环从1开始每次加2赋值给数组
(3)顺序输出,当数量%10==0时候换行
(4)逆序输出,当数量%10==0时候换行

```c
#include <stdio.h>
#define M 30
int main()
{
  int s[M], i, k = 1;
  for (i = 0; i < M; i++)
  {
    s[i] = k;
    k += 2;
  }
  printf("\nSequence Output: \n");
  for (i = 0; i < M; i++)
  {
    printf("%4d", s[i]);
    if ((i + 1) % 10 == 0)
      printf("\n");
  }
  printf("\ninvert Output: \n");
  for (i = M - 1; i >= 0; i--)
  {
    printf("%4d", s[i]);
    if (i % 10 == 0)
      printf("\n");
  }
  printf("\n");
}
```



### 9.2 一维数组和指针

维数组和数组元素的地址
如下定义的是一个包含5个元索的一维数组
`int a[5];`
引用5个元素地址
`a[0]、&a[1]、&a[2]、&a[3]、&a[4]`
直接输出a, 观察发现`a与&a[0]`相等.
数组名a也表示地址
**数组名代表数组的首地址,也就是第一个元素的地址.**
注意:不可以给a赋新的值



**通过数组的首地址引用数组元素**

```c
#include <stdio.h>
#define M 3
int main()
{
  int *p, a[M], i;
  for (p = a; p - a < M; p++)
  {
    scanf("%d", p);
    printf("%p，%p\n", a, p); // a为数组首地址 p为数组首地址
  }
  p -= M; // 重置指针起始位置
  for (i = 0; i < M; i++)
  {
    printf("%d，%d，%d\n", p[i], *(a + i), *(p + i)); // 通过指针获取数组值 数组和指针操作相同； a 是常量，p 是变量
  }
}
```



**用带下标的指针变量引用一维数组元素**
例如:

```
若有以下定义和语句:
int *p, s[10],i;
比如的取值范围:i>=0&&i<10
地址的表示方式有三种:&s[i] s+ p+i
数组元索的表示方式也有三种:s[i] *(s+1) *(p + i)
```

数组首地址是常量，指针是变量。



### 9.3 函数之间对一维数组和数组元素的引用

**数组元素地址作为实参**
例:编写函数,对具有10个元素的char类型数组从下标为4的元素开始,全部设置星号"*,保持前4个元素中的内容不变.



**函数的指针形参和函数体中数组的区别**

返回形参数组时，只返回首地址，数组内存已经销毁。数组要用实参传输。



### 9.5 二维数组的定义和二维数组元素的引用

二维数组的定义形式如下
类型名数组名`[整型常量表达式1][整型常量表达式2] 例如: int a[3][4]`

1. 定义了一个名为a的二维数组.
2. a中每个元素都是整型
3. a数组中共有两个下标,第一个方括号中的下标的下限为0,上限为2; 第二个方括号中的下标的下限为0,上限为3.





## 第十章 字符串





## 第十一章 对函数的进一步讨论





## 第十二章 全局变量及其作用域和生存周期







### 函数的存储分类





## 第十三章 宏替换







### 文件包含和动态存储分配





## 第十四章 结构体、共同体和用户自定义类型





## 第十五章 位运算





## 第十六章 文件





## 附件 VSCode配置

```json
// https://code.visualstudio.com/docs/cpp/launch-json-reference
{
    "version": "0.2.0",
    "configurations": [{
        "name": "(gdb) Launch", // 配置名称，将会在启动配置的下拉菜单中显示
        "type": "cppdbg", // 配置类型，对于C/C++可认为此处只能是cppdbg，由cpptools提供；不同编程语言不同
        "request": "launch", // 可以为launch（启动）或attach（附加）
        "program": "${fileDirname}/${fileBasenameNoExtension}.exe", // 将要进行调试的程序的路径
        "args": [], // 程序调试时传递给程序的命令行参数，一般设为空
        "stopAtEntry": false, // 设为true时程序将暂停在程序入口处，相当于在main上打断点
        "cwd": "${workspaceFolder}", // 调试程序时的工作目录，此为工作区文件夹；改成${fileDirname}可变为文件所在目录
        "environment": [], // 环境变量
        "externalConsole": false, // 使用单独的cmd窗口，与其它IDE一致；为false时使用内置终端
        "internalConsoleOptions": "neverOpen", // 如果不设为neverOpen，调试时会跳到“调试控制台”选项卡，你应该不需要对gdb手动输命令吧？
        "MIMode": "gdb", // 指定连接的调试器，可以为gdb或lldb。但我没试过lldb
        "miDebuggerPath": "gdb.exe", // 调试器路径，Windows下后缀不能省略，Linux下则不要
        "setupCommands": [
            { // 模板自带，好像可以更好地显示STL容器的内容，具体作用自行Google
                "description": "Enable pretty-printing for gdb",
                "text": "-enable-pretty-printing",
                "ignoreFailures": false
            }
        ],
        "preLaunchTask": "Compile" // 调试前执行的任务，一般为编译程序。与tasks.json的label相对应
    }]
}
```

```json
// https://code.visualstudio.com/docs/editor/tasks
{
    "version": "2.0.0",
    "tasks": [{
        "label": "Compile", // 任务名称，与launch.json的preLaunchTask相对应
        "command": "gcc",   // 要使用的编译器，C++用g++
        "args": [
            "${file}",
            "-o",    // 指定输出文件名，不加该参数则默认输出a.exe，Linux下默认a.out
            "${fileDirname}/${fileBasenameNoExtension}.exe",
            "-g",    // 生成和调试有关的信息 断点参数
            // "-m64",  // 不知为何有时会生成16位程序而无法运行，此条可强制生成64位的
            "-Wall", // 开启额外警告
            "-static-libgcc",     // 静态链接libgcc，一般都会加上
            // "-fexec-charset=GBK", // 生成的程序使用GBK编码，不加这条会导致Win下输出中文乱码；繁体系统改成BIG5
            // "-D__USE_MINGW_ANSI_STDIO", // 用MinGW写C时留着，否则不需要，用于支持printf的%zd和%Lf等
        ], // 编译的命令，其实相当于VSC帮你在终端中输了这些东西
        "type": "process", // process是把预定义变量和转义解析后直接全部传给command；shell相当于先打开shell再输入命令，所以args还会经过shell再解析一遍
        "group": {
            "kind": "build",
            "isDefault": true // 不为true时ctrl shift B就要手动选择了
        },
        "presentation": {
            "echo": true,
            "reveal": "always", // 执行任务时是否跳转到终端面板，可以为always，silent，never。具体参见VSC的文档，即使设为never，手动点进去还是可以看到
            "focus": false,     // 设为true后可以使执行task时焦点聚集在终端，但对编译C/C++来说，设为true没有意义
            "panel": "shared"   // 不同的文件的编译信息共享一个终端面板
        },
        "problemMatcher":"$gcc" // 捕捉编译时终端里的报错信息到问题面板中，修改代码后需要重新编译才会再次触发
        // 本来有Lint，再开problemMatcher就有双重报错，但MinGW的Lint效果实在太差了；用Clangd可以注释掉
    }]
}
```

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
            "intelliSenseMode": "gcc-x64",
            "compilerPath": "C:/TDM-GCC-64/bin/g++.exe"
        }
    ],
    "version": 4
}
```

```json
{
    "files.defaultLanguage": "c", // ctrl+N新建文件后默认的语言
    // "editor.formatOnType": true,  // 输入分号(C/C++的语句结束标识)后自动格式化当前这一行的代码
    // "editor.suggest.snippetsPreventQuickSuggestions": false, // clangd的snippets有很多的跳转点，不用这个就必须手动触发Intellisense了
    // "editor.acceptSuggestionOnEnter": "off", // 我个人的习惯，按回车时一定是真正的换行，只有tab才会接受Intellisense
    // "editor.snippetSuggestions": "top", // （可选）snippets显示在补全列表顶端，默认是inline

    // "code-runner.runInTerminal": true, // 设置成false会在“输出”中输出，无法输入
    // "code-runner.executorMap": {
    //     "c": "gcc '$fileName' -o '$fileNameWithoutExt.exe' -Wall -O2 -m64 -lm -static-libgcc -fexec-charset=GBK -D__USE_MINGW_ANSI_STDIO && &'./$fileNameWithoutExt.exe'",
    //     "cpp": "g++ '$fileName' -o '$fileNameWithoutExt.exe' -Wall -O2 -m64 -static-libgcc -fexec-charset=GBK && &'./$fileNameWithoutExt.exe'"
    //     // "c": "gcc $fileName -o $fileNameWithoutExt.exe -Wall -O2 -m64 -lm -static-libgcc -fexec-charset=GBK -D__USE_MINGW_ANSI_STDIO && $dir$fileNameWithoutExt.exe",
    //     // "cpp": "g++ $fileName -o $fileNameWithoutExt.exe -Wall -O2 -m64 -static-libgcc -fexec-charset=GBK && $dir$fileNameWithoutExt.exe"
    // }, // 右键run code时运行的命令；未注释的仅适用于PowerShell（Win10默认）和pwsh，文件名中有空格也可以编译运行；注释掉的适用于cmd（win7默认）、PS和bash，但文件名中有空格时无法运行
    // "code-runner.saveFileBeforeRun": true, // run code前保存
    // "code-runner.preserveFocus": true,     // 若为false，run code后光标会聚焦到终端上。如果需要频繁输入数据可设为false
    // "code-runner.clearPreviousOutput": false, // 每次run code前清空属于code runner的终端消息，默认false
    // "code-runner.ignoreSelection": true,   // 默认为false，效果是鼠标选中一块代码后可以单独执行，但C是编译型语言，不适合这样用
    // "code-runner.fileDirectoryAsCwd": true, // 将code runner终端的工作目录切换到文件目录再运行，对依赖cwd的程序产生影响；如果为false，executorMap要加cd $dir

    "C_Cpp.clang_format_sortIncludes": true, // 格式化时调整include的顺序（按字母排序）
}
```

