# use-lib-scene
c语言中很多形式的 库 的使用，场景化，标准化。以后直接拿来用。
并分类为Linux系统和Android系统两种平台的编译使用方式


.
├── dlopen-scene
├── link-scene
├── README.md
└── static-lib

3 directories, 1 file
上面动态库分为dlopen和link，而静态库貌似是不需要dlopen的，原因何在？
原因：



link-scene测试链接方式使用Makefile
Makefile变量解释
（1）Makefile中的 符号 $@, $^, $< 的意思：
　　$@  表示目标文件
　　$^  表示所有的依赖文件
　　$<  表示第一个依赖文件
　　$?  表示比目标还要新的依赖文件列表

（2）wildcard、notdir、patsubst的意思：
　　wildcard : 扩展通配符
　　notdir ： 去除路径
　　patsubst ：替换通配符
