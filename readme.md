## 安装gtest
- 到gtest的github仓库clone代码
- 进入工程后，mkdir build && cd build && cmake .. && make && sudo make install
- 执行完之后，在/usr/local/lib 目录下面就会有libgtest.a库了

## 编译
- ```g++ test.cc /usr/local/lib/libgtest.a -lpthread -o test -std=c++11```
