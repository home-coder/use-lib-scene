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
动态共享库是fPIC即地址无关，它的地址是写死的，只要是linux 64 32平台编译的只能分别在64 32位上运行，并且其它所有进程都可以共享这一段
由动态共享库加载进内存的那一段内存。

而其它的比如gcc出来的.o二进制文件或者对这个二进制进行一次包装的.a静态库都是没有自己的地址的，需要编译的时候链接一下才能分配地址。所以只能编译时链接，而不能动态的dlopen，因为dlopen也得不到地址。

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


两点任务：
在link的时候考虑，-L的指定方式为什么提示找不到动态库呢，而把库so导入/usr/lib就可以了呢。
另外就是完善Makefile
还有就是去usb那个仓，思考-L 和 /usr/lib产生的编译结果，运行时status为什么值不一样。

关于上面的问题，目前采用直接copy就可以了.

------------------------------------------------------------------------------------------



在Makefile中，可以见到include src 等等目录结构很清晰，
但是Android的标准是将一个功能放到一个目录下面，即将头文件.h 源.c等放到一个目录下面，然后这个目录起名字比如function，然后目录下添加Android.mk,与Makefile的区别很大
