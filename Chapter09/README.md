# 9.1 顺序容器概述

### 练习 9.1

> 对于下面的程序任务，vector、deque 和 list 哪种容器最为适合？解释你的选择的理由。如果没有哪一种容器优于其他容器，也请解释理由。
>
> (a) 读取固定数量的单词，将它们按字典序插入到容器中。我们将在下一章中看到，关联容器更适合这个问题。
>
> (b) 读取未知数量的单词，总是将单词插入到末尾。删除操作在头部进行。
>
> (c) 从一个文件读取未知数量的整数。将这些数排序，然后将它们打印到标准输出。

- `list`，因为需要在容器的任意位置进行插入操作
- `deque`，因为需要在头部进行插入和删除操作，而`deque`在头尾位置进行插入/删除速度很快
- `vector`，不需要插入/删除操作

# 9.2 容器库概览

### 练习 9.2

> 定义一个 list 对象，其元素类型是 int 的 deque。

```cpp
list<deque<int>> deq_list;
```

## 9.2.1 迭代器

### 练习 9.3

> 构成迭代器范围的迭代器有何限制？

- 指向同一个容器中的元素，或者是容器最后一个元素之后的位置
- 可以通过反复递增`begin`来到达`end`，即`end`不在`begin`之前

### 练习 9.4

> 编写函数，接受一对指向 vector<int> 的迭代器和一个 int 值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。

```cpp
bool findValue(vector<int>::const_iterator b, vector<int>::const_iterator e, int val){
    for(auto it = b; it != e; it++){
        if(*it == val){
            return true;
        }
    }
    return false;
}
```

### 练习 9.5

> 重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。

```cpp
std::vector<int>::const_iterator findValue(vector<int>::const_iterator b, vector<int>::const_iterator e, int val){
    for(auto it = b; it != e; it++){
        if(*it == val){
            return it;
        }
    }
    return e;
}
```

### 练习 9.6

> 下面的程序有何错误？你应该如何修改它？
>
> ```cpp
> list<int> lst1;
> list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
> while (iter1 < iter2) /* ... */
> ```

`list<int>::iterator` 对象没有关系运算符 `<`，应修改为

```cpp
while (iter1 != iter2) /* ... */
```

## 9.2.2 容器类型成员

### 练习 9.7

> 为了索引 int 的 vector 中的元素，应该使用什么类型？

应使用`std::vector<int>::iterator`或`std::vector<int>::const_iterator`或`std::vector<int>::size_type`

### 练习 9.8

> 为了读取 string 的 list 中的元素，应该使用什么类型？如果写入 list，又应该使用什么类型？

读取应该使用 `std::list<std::string>::const_iterator`，写入应使用 `std::list<std::string>::iterator`

## 9.2.3 begin 和 end 成员

### 练习 9.9

> begin 和 cbegin 两个函数有什么不同？

`cbegin` 返回 const 迭代器；`begin` 返回迭代器，且被重载过，与 `auto` 一起使用时，获得的迭代器类型依赖于容器类型

### 练习 9.10

> 下面 4 个对象分别是什么类型？
>
> ```cpp
> vector<int> v1;
> const vector<int> v2;
> auto it1 = v1.begin(), it2 = v2.begin();
> auto it3 = v1.cbegin(), it4 = v2.cbegin();
> ```

`v1` 为 `vector<int>` 类型；`v2` 为 `const vector<int>` 类型，`begin` 与 `auto` 一起使用时，获得的迭代器类型依赖于容器类型，因此推导出的 `it1` 和 `it2` 的类型不同，编译报错。若无错误，`it1` 为 `vector<int>::iterator`，`it2`，`it3` 和 `it4` 为 `vector<int>::const_iterator`。

## 9.2.4 容器定义和初始化

### 练习 9.11

> 对 6 种创建和初始化 vector 对象的方法，每一种都给出一个实例。解释每个 vector 包含什么值。

```c++
vector<int> ivec1;	//ivec1为空容器
vector<int> ivec2{0, 1, 2, 3};	//ivec2包含0, 1, 2, 3
vector<int> ivec3(10);	//ivec3包含10个0
vector<int> ivec4(ivec3);	//ivec4初始化为ivec3的拷贝，含10个0
vector<int> ivec5(10, 1);	//ivec5包含10个1
vector<int> ivec6(ivec3.begin(), ivec3.end());	//ivec6包含10个0
```

### 练习 9.12

> 对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。

前者两个容器必须是相同的容器类型，且保存的是相同的元素类型，对于 `array` 还必须有相同大小；后者只需迭代器范围元素的类型内与创建的容器的元素类型相容

### [练习 9.13](9_13.cpp)

> 如何从一个 list<int> 初始化一个 vector<double>？从一个 vector<int> 又该如何创建？编写代码验证你的答案。

## 9.2.5 赋值和 swap

### [练习 9.14](9_14.cpp)

> 编写程序，将一个 list 中的 char * 指针（指向 C 风格字符串）元素赋值给一个 vector 中的 string。

## 9.2.7 关系运算符

### [练习 9.15](9_15.cpp)

> 编写程序，判定两个 vector<int> 是否相等。

### [练习 9.16](9_16.cpp)

> 重写上一题的程序，比较一个 list<int> 中的元素和一个 vector<int> 中的元素。

### 练习 9.17

> 假定 c1 和 c2 是两个容器，下面的比较操作有何限制（如果有的话）？
>
> ```cpp
> if (c1 < c2)
> ```

- 关系运算符左右两边的运算对象必须是相同类型的容器，且必须保存相同类型的元素
- 容器的元素要需要定义相应的比较运算符（第 304 页）

# 9.3 顺序容器操作

## 9.3.1 向顺序容器添加元素

### [练习 9.18](9_18.cpp)

> 编写程序，从标准输入读取 string 序列，存入一个 deque 中。编写一个循环，用迭代器打印 deque 中的元素。

### [练习 9.19](9_19.cpp)

> 重写上一题的程序，用 list 替代 deque。列出程序要做出哪些改变。

只需修改容器的定义

### [练习 9.20](9_20.cpp)

> 编写程序，从一个 list<int> 拷贝元素到两个 deque 中。值为偶数的所有元素都拷贝到一个 deque 中，而奇数值元素都拷贝到另一个 deque 中。

### 练习 9.21

> 如果我们将第 308 页中使用 insert 返回值将元素添加到 list 中的循环程序改写为将元素插入到 vector 中，分析循环将如何工作。

```cpp
std::vector<std::string> vec;
auto iter = vec.begin();
while (std::cin >> word) iter = vec.insert(iter, word);
```

在循环之前，我们将 `iter` 初始化为 `vec.begin()`。第一次调用 `insert` 会将我们刚刚读入的 `string` 插入到 `iter` 所指向的元素之前的位置。 `insert` 返回的迭代器恰好指向这个新元素。我们将此迭代器赋予 `iter` 并重复循环，读取下一个单词。只要继续有单词读入,每步 while 循环就会将一个新元素插入到 `iter` 之前,并将 `iter` 改变为新加入元素的位置。此元素为（新的）首元素。因此，每步循环将一个新元素插入到` vec` 首元素之前的位置

### 练习 9.22

> 假定 iv 是一个 int 的 vector，下面的程序存在什么错误？你将如何修改？
>
> ```cpp
> vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
> while (iter != mid)
>   if (*iter == some_val) iv.insert(iter, 2 * some_val);
> ```

向 vector 插入元素会使所有指向容器的迭代器、引用和指针失效，且循环变量没有改变，循环不会终止，修改如下

```cpp
while (iter != mid) {
  if (*iter == some_val) {
    iv.insert(iter, 2 * some_val);
  }
  ++iter;
}
```

## 9.3.2 访问元素

### 练习 9.23

> 在本节第一个程序（第 309 页）中，若 c.size() 为 1，则 val、val2、val3 和 val4 的值会是什么？

`val`、`val2`、`val3` 和 `val4` 都是容器中唯一值的拷贝

### [练习 9.24](9_24.cpp)

> 编写程序，分别使用 at、下标运算符、front 和 begin 提取一个 vector 中的第一个元素。在一个空 vector 上测试你的程序。

## 9.3.3 删除元素

### 练习 9.25

> 对于第 312 页中删除一个范围内的元素的程序，如果 elem1 与 elem2 相等会发生什么？如果 elem2 是尾后迭代器，或者 elem1 和 elem2 皆为尾后迭代器，又会发生什么？

- 如果 `elem1` 和 `elem2` 相等，则不删除任何元素
- 如果 `elem2` 是尾后迭代器，则删除 `elem1` 以及之后的所有元素
- 如果 `elem1` 和 `elem2` 都为尾后迭代器，则不删除任何元素

### [练习 9.26](9_26.cpp)

> 使用下面代码定义的 ia，将 ia 拷贝到一个 vector 和一个 list 中。使用单迭代器版本的 erase 从 list 中删除奇数元素，从 vector 中删除偶数元素。
>
> ```cpp
> int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
> ```

## 9.3.4 特殊的 forward_list 操作

### [练习 9.27](9_27.cpp)

> 编写程序，查找并删除 forward_list<int> 中的奇数元素。

### [练习 9.28](9_28.cpp)

> 编写函数，接受一个 forward_list<string> 和两个 string 共三个参数。函数应在链表中查找第一个 string，并将第二个 string 插入到紧接着第一个 string 之后的位置。若第一个 string 未在链表中，则将第二个 string 插入到链表末尾。

## 9.3.5 改变容器大小

### 练习 9.29

> 假定 vec 包含 25 个元素，那么 vec.resize(100) 会做什么？如果接下来调用 vec.resize(10) 会做什么？

调整 `vec` 的大小为 100 个元素，对新添加的 75 个元素进行值初始化；调整 `vec` 的大小为 10 个元素，丢弃多出的 90 个元素

### 练习 9.30

> 接受单个参数的 resize 版本对元素类型有什么限制（如果有的话）？

元素必须提供默认构造函数

## 9.3.6 容器操作可能使迭代器失效

### 练习 9.31

> 第 316 页中删除偶数值元素并复制奇数值元素的程序不能用于 list 或 forward_list。为什么？修改程序，使之也能用于这些类型。

- `list` 的迭代器不支持 `iter += 2` 这类复合赋值语句（第 296 页），修改如下：

  ```cpp
  ++iter;
  ++iter;
  ```

- `forward_list` 需要使用特殊版本的添加和删除操作（第 313 页），修改如下：

  ```cpp
  std::forward_list<int> fli = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto prev = fli.before_begin();
  auto curr = fli.begin();
  while (curr != fli.end()) {
    if (*curr % 2) {
      curr = fli.insert_after(curr, *curr);
      prev = curr;
      ++curr;
    } else {
      curr = fli.erase_after(prev);
    }
  }
  ```

### 练习 9.32

> 在第 316 页的程序中，向下面语句这样调用 insert 是否合法？如果不合法，为什么？
>
> ```cpp
> iter = vi.insert(iter, *iter++);
> ```

不合法，大多数运算符都没有规定运算对象的求值顺序（第 133 页），此语句的行为是未定义的

### 练习 9.33

> 在本节最后一个例子中，如果不将 insert 的结果赋予 begin，将会发生什么？编写程序，去掉此赋值语句，验证你的答案。

`insert(begin, 42)` 在迭代器 `begin` 之前创建一个值为 42 的元素（第 305 页），因此 `begin` 会失效，产生运行时错误

### [练习 9.34](9_34.cpp)

> 假定 vi 是一个保存 int 的容器，其中有偶数值也有奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确。
>
> ```cpp
> iter = vi.begin();
> while (iter != vi.end())
>   if (*iter % 2) iter = vi.insert(iter, *iter);
> ++iter;
> ```

`while` 的循环体内没有修改循环控制变量 `iter`，此代码会导致无限循环

# 9.4 vector 对象是如何增长的

### 练习 9.35

> 解释一个 vector 的 capacity 和 size 有何区别。

容器的 size 是指它已经保存的元素的数目；而 capacity 则是在不分配新的内存空间的前提下它最多可以保存多少元素（第 318 页）。

### 练习 9.36

> 一个容器的 capacity 可能小于它的 size 吗？

不可能，size 与添加的元素数目相等，而 capacity 至少与 size 一样大，具体会分配多少额外空间则视标准库具体实现而定（第 319 页）。

### 练习 9.37

> 为什么 list 或 array 没有 capacity 成员函数？

`list` 中的元素不是连续存储的，而 `array` 的大小是固定的，二者都不需要重新分配内存空间。

### [练习 9.38](9_38.cpp)

> 编写程序，探究在你的标准库实现中，vector 是如何增长的。

`vector` 的 capacity 以 2 的指数次方式增长

### 练习 9.39

> 解释下面程序片段做了什么：
>
> ```cpp
> vector<string> svec;
> svec.reserve(1024);
> string word;
> while (cin >> word) svec.push_back(word);
> svec.resize(svec.size() + svec.size() / 2);
> ```

 定义一个保存 `string` 对象的 `vector` 容器，分配至少能容纳 1024 个元素的内存空间。每次从标准输入中读取一个字符串，存入 `vector` 容器，直至循环结束。将元素数量的大小修改为当前值的 1.5 倍，新元素使用空字符串填充。

### 练习 9.40

> 如果上一题中的程序读入了 256 个词，在 resize 之后容器的 capacity 可能是多少？如果读入了 512 个、1000 个、或 1048 个词呢？

- 若读入 256 个词，resize 之后容器的 capacity 是 1024
- 若读入 512 个词，resize 之后容器的 capacity 是 1024
- 若读入 1000 个、1048个 词，resize 之后容器的 capacity 视标准库具体实现而定

# 9.5 额外的 string 操作

## 9.5.1 构造 string 的其他方法

### [练习 9.41](9_41.cpp)

> 编写程序，从一个 vector<char> 初始化一个 string。

### 练习 9.42

> 假定你希望每次读取一个字符存入一个 string 中，而且知道最少需要读取 100 个字符，应该如何提高程序的性能？

定义 `string` 后使用 `reserve(100)` 分配至少能容纳 100 个字符的内存空间。
