gpio 为输入状态是默认为低电平

gpio_direction_input(s5pv_gpc0(3));

应用层加头文件， main 2 xxx

中断和输入子系统是两个概念   所有的中断产生都一样都是改变其电平高低

每个gpio都有个号码， S5PV210_GPC0(num)  

接受后的数据要清空buf

可在kernal中seting one struct type value，可以不是 kmalloc 申请spase

see void or void *  show private data

xxx_t  show type 类型data

ret = request_irq(irqno, key_irq_handler, flags,name, &allkeys[i]); 的第四个参数在 cat /proc/interrupts 可以找到
