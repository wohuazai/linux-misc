gpio Ϊ����״̬��Ĭ��Ϊ�͵�ƽ

gpio_direction_input(s5pv_gpc0(3));

Ӧ�ò��ͷ�ļ��� main 2 xxx

�жϺ�������ϵͳ����������   ���е��жϲ�����һ�����Ǹı����ƽ�ߵ�

ÿ��gpio���и����룬 S5PV210_GPC0(num)  

���ܺ������Ҫ���buf

����kernal��seting one struct type value�����Բ��� kmalloc ����spase

see void or void *  show private data

xxx_t  show type ����data

ret = request_irq(irqno, key_irq_handler, flags,name, &allkeys[i]); �ĵ��ĸ������� cat /proc/interrupts �����ҵ�
