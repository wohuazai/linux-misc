以配置GPIO9为例：
1. 从shell命令行配置：
创建操作节点：
echo 9 > /sys/class/gpio/export 

设置方向(in/out)：
echo out > /sys/class/gpio/gpio9/direction 

若配置为out，设置输出电平(0/1)：
echo 1 > /sys/class/gpio/gpio9/value 
echo 0 > /sys/class/gpio/gpio9/value 

若配置为 in，直接使用
cat /sys/class/gpio/gpio9/value 


2. 代码中配置：
	可以参考 app_gpio.c 中的 app_gpio_read() 和 app_gpio_write() 接口。


另外，各个 GPIO 的初始状态可以参考 kernel 源码中 gpio_evb.h 的 SYSTEM_GPIO_XREF_TABLE
