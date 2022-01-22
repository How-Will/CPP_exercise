# 10.1 概述

### [练习 10.1](10_1.cpp)

> 头文件 algorithm 中定义了一个名为 count 的函数，它类似 find， 接受一对迭代器和一个值作为参数。 count 返回给定值在序列中出现的次数。编写程序，读取 int 序列存入 vector 中，打印有多少个元素的值等于给定值。

### [练习 10.2](10_2.cpp)

> 重做上一题，但读取 string 序列存入 list 中。

# 10.2 初始泛型算法

## 10.2.1 只读算法

### [练习 10.3](10_3.cpp)

> 用 accumulate 求一个 vector<int> 中的元素之和。

### 练习 10.4

> 假定 v 是一个 vector<double>，那么调用 accumulate(v.cbegin(), v.cend(), 0) 有何错误（如果存在的话）？

只能得到整型的结果。`accumulate` 的第三个参数的类型决定了函数中使用哪个加法运算符以及返回值的类型（第 338 页）。

### 练习 10.5

> 在本节对名册 (roster) 调用 equal 的例子中，如果两个名册中保存的都是 C 风格字符串而不是 string，会发生什么？

若使用 `char*`，则会编译时会警告：`warning: ISO C++11 does not allow conversion from string literal to 'char *'`；使用 `const char*` 则可以正确比较两个 C 风格字符串是否相等。

## 10.2.2 写容器元素的算法

### [练习 10.6](10_6.cpp)

> 编写程序，使用 fill_n 将一个序列中的 int 值都设置为 0。

### 练习 10.7

> 下面程序是否有错误？如果有，请改正：
>
> (a)
>
> ```cpp
> vector<int> vec;
> list<int> lst;
> int i;
> while (cin >> i) lst.push_back(i);
> copy(lst.cbegin(), lst.cend(), vec.begin());
> ```
>
> (b)
>
> ```cpp
> vector<int> vec;
> vec.reserve(10);  // reverse 将在 9.4 节（第 318 页）介绍
> fill_n(vec.begin(), 10, 0);
> ```

- 传递给 `copy` 的目的序列至少要包含与输入序列一样多的元素，即 `vec` 的至少要跟 `lst` 一样大，修改如下

  ```cpp
  vector<int> vec;
  list<int> lst;
  int i;
  while (cin >> i) lst.push_back(i);
  vec.resize(lst.size());
  copy(lst.cbegin(), lst.cend(), vec.begin());
  ```

- `reserve(10)` 只是给容器分配至少能容纳 10 个元素的内存空间，而不改变容器中元素的数量（第 318 页），修改如下

  ```cpp
  vector<int> vec;
  vec.resize(10);
  fill_n(vec.begin(), 10, 0);
  ```

### 练习 10.8

> 本节提到过，标准库算法不会改变它们所操作的容器的大小。为什么使用 back_inserter 不会使这一断言失效？

使用 `back_inserter`，改变容器大小的是插入迭代器，而不是标准库算法，它通过调用 `push_back` 向容器中添加新元素。

## 10.2.3 重排容器元素的算法

### [练习 10.9](10_9.cpp)

> 实现你自己的 elimDups。分别在读取输入后、调用 unique 后以及调用 erase 后打印 vector 的内容。

### 练习 10.10

> 你认为算法不改变容器大小的原因是什么？

算法运行于迭代器之上，执行迭代器的操作，而不执行容器的操作，可以让算法不依赖于容器，只依赖于容器中元素的类型，这样算法可以用于标准库容器，也可以用于内置数组，有更好的通用性。

# 0.3 定制操作

## 10.3.1 向算法传递函数

### [练习 10.11](10_11.cpp)

> 编写程序，使用 stable_sort 和 isShorter 将传递给你的 elimDups 版本的 vector 排序。打印 vector 的内容，验证你的程序的正确性。

### [练习 10.12](10_12.cpp)

> 编写名为 compareIsbn 的函数，比较两个 Sales_data 对象的 isbn() 成员。使用这个函数排序一个保存 Sales_data 对象的 vector。

```
bool compareIsbn(const Sales_data& data1, const Sales_data& data2) {
  return data1.isbn() < data2.isbn();
}
```

### [练习 10.13](10_13.cpp)

> 标准库定义了名为 partition 的算法，它接受一个谓词，对容器内容进行划分，使得谓词为 true 的值会排在容器的前半部分，而使谓词为 false 的值会排在后半部分。算法返回一个迭代器，指向最后一个使谓词为 true 的元素之后的位置。编写函数，接受一个 string，返回一个 bool 值，指出 string 是否有 5 个或更多字符。使用此函数划分 words。打印出长度大于等于 5 的元素。

