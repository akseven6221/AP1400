#### 1.两个文件互相`include`的问题
- 不要去互相引用，编译就会报错，没有的类直接本地声明就行。

#### 2.std::rand()生成0-2^15-1的数据，挺好用的

#### 3.关于函数头后面的`const`

```cpp
    double get_wallet(std::string id) const;
```
- 加上这个`const`能使得调用这个函数的变量的`const`变量强制不受改变，也能让`const`成员变量调用这个方法能够通过编译

#### 友元函数:
- 测例里有一个独立的函数，那个函数不属于任何类而且还要用到类里的私有变量，那怎么办呢？我们可以用友元函数，类中声明`friend <函数头>`，类外实现即可