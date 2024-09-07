core_cm3.c 和 core_cm3.h 文件位于\Libraries\CMSIS\CM3\CoreSupport 子目录下面， 分
别是内核访问层的源文件和头文件，提供进入 M3 内核的接口。这两个文件是由 Arm 公司提供
的 CMSIS 核心文件，对所有 M3 内核的芯片都一样，永远都不需要修改。
startup_stm32f10x_ld.s：适用于小容量产品，Flash-32 KB；
startup_stm32f10x_md.s：适用于中等容量产品，64 KB-Flash-128 KB；
startup_stm32f10x_hd.s：适用于大容量产品，256 KB-Flash。
启动文件主要进行堆栈等的初始化、 中断向量表以及中断函数定义， 还要引导程序进入 main函数。