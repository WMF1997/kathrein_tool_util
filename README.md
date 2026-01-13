# kathrein\_tool\_util

## 介绍

之前"捻叶成剑"大佬在B站动态提到的, 计算基站覆盖距离相关的小工具(Kathrein Scala Division)的相应功能的底层代码, 按照使用结果, 我使用C++重新进行了实现. 

"捻叶成剑"大佬在B站的原动态: 
https://www.bilibili.com/opus/587407919569244756

之前自己写的相关内容, 在B站的动态: 
https://www.bilibili.com/opus/676797317380046903 

## 相应工具的链接
 
链接: https://pan.baidu.com/s/11tzpD5OJDqmkLRXuFZmXlQ 提取码: 3594  
需要注意的是, Reflection Conversion Table功能, 需要依赖于MSCOMCTL.OCX这个ActiveX控件, 可以上网按照相应步骤进行配置, 配置之后就可以使用了. (记得Windows 10没问题, Windows 11不确定要怎么弄)

## 这段代码的编译

可以直接使用cmake进行编译. 也可以使用自己单独编写的makefile进行编译. 

如果是使用cmake的话, 会在`${CMAKE_BINARY_DIR}/bin`和`${CMAKE_BINARY_DIR}/lib`有相应的编译产物, 直接使用/执行即可. 不需要任何其他的操作. 

但是, 如果使用单独编写的Makefile, 在完成编译后, 要执行相应可执行文件的时候, 需要调整设置`LD_LIBRARY_PATH`, 用于获得`libkathrein_util.so`的对应文件夹路径, 例如如果在`out`文件夹下, 执行:

```bash
export LD_LIBRARY_PATH=.
```

## 编译生成pybind11的Python绑定 

可以参考下面这段编译指令. (在`src/`目录下执行):

```bash 
g++ \
    -shared -O2 -fPIC -ffast-math -march=native \
    -I /home/wmf1997/python313/lib/python3.13/site-packages/pybind11/include \
    -I /home/wmf1997/.local/share/uv/python/cpython-3.13.2-linux-x86_64-gnu/include/python3.13 \
    -I ../include \
    kathrein_util.cpp \
    kathrein_util_pybind11.cpp \
    -o kathrein_util_pybind11.so
```

## 后续计划

- [x] 调整目录组织结构
- [x] 添加CMake的相应编译构建流程
- [x] <可选> 添加Makefile的相应编译构建流程
- [x] 添加Python相关的绑定内容. 计划使用pybind11作为相应的基础库. (现在尝试添加了一个稍微简单的, 不使用CMake的版本, 使用纯g++命令编译的结果)


