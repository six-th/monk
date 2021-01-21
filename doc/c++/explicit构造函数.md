

```cpp


按照默认规定，只有一个参数的构造函数也定义了一个隐式转换，将该构造函数对应数据类型的数据转换为该类对象，如下面所示：
class String {
String ( const char* p ); // 用C风格的字符串p作为初始化值
//…
}
String s1 = “hello”; //OK 隐式转换，等价于String s1 = String（“hello”）;
但是有的时候可能会不需要这种隐式转换，如下：
class String {
String ( int n ); //本意是预先分配n个字节给字符串
String ( const char* p ); // 用C风格的字符串p作为初始化值
//…
}
下面两种写法比较正常：
String s2 ( 10 ); //OK 分配10个字节的空字符串
String s3 = String ( 10 ); //OK 分配10个字节的空字符串
下面两种写法就比较疑惑了：
String s4 = 10; //编译通过，也是分配10个字节的空字符串
String s5 = ‘a’; //编译通过，分配int（‘a’）个字节的空字符串
s4 和s5 分别把一个int型和char型，隐式转换成了分配若干字节的空字符串，容易令人误解。
为了避免这种错误的发生，我们可以声明显示的转换，使用explicit 关键字：
class String {
explicit String ( int n ); //本意是预先分配n个字节给字符串
String ( const char* p ); // 用C风格的字符串p作为初始化值
//…
}
加上explicit，就抑制了String ( int n )的隐式转换，
下面两种写法仍然正确：
String s2 ( 10 ); //OK 分配10个字节的空字符串
String s3 = String ( 10 ); //OK 分配10个字节的空字符串
下面两种写法就不允许了：
String s4 = 10; //编译不通过，不允许隐式的转换
String s5 = ‘a’; //编译不通过，不允许隐式的转换
因此，某些时候，explicit 可以有效得防止构造函数的隐式转换带来的错误或者误解

----------------------------------------------------------
explicit 只对构造函数起作用，用来抑制隐式转换。如： 
class A { 
A(int a); 
}; 
int Function(A a); 

当调用 Function(2) 的时候，2 会隐式转换为 A 类型。这种情况常常不是程序员想要的结果，所以，要避免之，就可以这样写： 

class A { 
explicit A(int a); 
}; 
int Function(A a); 

这样，当调用 Function(2) 的时候，编译器会给出错误信息（除非 Function 有个以 int 为参数的重载形式），这就避免了在程序员毫不知情的情况下出现错误。

总结：explicit 只对构造函数起作用，用来抑制隐式转换。


参考：
http://blog.csdn.net/smilelance/archive/2007/03/14/1528737.aspx
http://topic.csdn.net/t/20040509/15/3046021.html

```