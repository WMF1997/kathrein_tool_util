# kathrein_tool_util

## 介绍
之前"捻叶成剑"大佬在B站动态提到的, 计算基站覆盖距离相关的小工具(Kathrein Scala Division)的相应功能的底层代码, 按照使用结果自己使用C++重新实现. 

"捻叶成剑"大佬在B站的原动态: 
https://www.bilibili.com/opus/587407919569244756

之前自己写的相关内容, 在B站的动态: 
https://www.bilibili.com/opus/676797317380046903 

## 相应工具的链接 
链接: https://pan.baidu.com/s/11tzpD5OJDqmkLRXuFZmXlQ 提取码: 3594 
需要注意的是, Reflection Conversion Table功能, 需要依赖于MSCOMCTL.OCX这个ActiveX控件, 可以上网按照相应步骤进行配置, 配置之后就可以使用了. (记得Windows 10没问题, Windows 11不确定要怎么弄)

## 这段代码的编译
```bash
g++ kathrein_util.cpp -o kathrein_util 
```
另外, 既然将这段代码公开了, 后续他人使用的时候, 可以改为`-fPIC`的方式, 发布为动态库. 

