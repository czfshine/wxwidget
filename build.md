# 编译wxwidgets源码

不同IDE或编译器有不同的方法，下面列举几个：

## 用Visual Studio

* 下载源码包，解压，用Visual Studio打开`build/msw/wx.dsw`文件。
* 当VS版本较高时，要升级项目文件，等待升级。
* 选择你要生成的版本，默认是DeBug X86.
* 启动生成，等待生成结束
* 在lib/vc_lib 里面就是生成后的静态链接库（后缀lib）
* 在lib/vc_lib/mswd 里有生成后的setup.h（每个程序都包含它）


## 用gcc

在 build/msw 目录下执行 `make -f makefile.gcc`,等待编译结束。

