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

```bash
g++ -fPIC -shared -O2 kathrein_util.cpp -o libkathrein_util.so # 生成相应的动态库
g++ -O2 -L . main_test.cpp -lkathrein_util # 将结果添加上
```

在执行相应可执行文件的时候, 需要调整`LD_LIBRARY_PATH`, 用于找到`libkathrein_util.so`的位置. 例如
```bash
export LD_LIBRARY_PATH=.
```

## 后续计划

后续计划添加Python相关的绑定内容. 
