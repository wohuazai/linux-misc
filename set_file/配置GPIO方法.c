������GPIO9Ϊ����
1. ��shell���������ã�
���������ڵ㣺
echo 9 > /sys/class/gpio/export 

���÷���(in/out)��
echo out > /sys/class/gpio/gpio9/direction 

������Ϊout�����������ƽ(0/1)��
echo 1 > /sys/class/gpio/gpio9/value 
echo 0 > /sys/class/gpio/gpio9/value 

������Ϊ in��ֱ��ʹ��
cat /sys/class/gpio/gpio9/value 


2. ���������ã�
	���Բο� app_gpio.c �е� app_gpio_read() �� app_gpio_write() �ӿڡ�


���⣬���� GPIO �ĳ�ʼ״̬���Բο� kernel Դ���� gpio_evb.h �� SYSTEM_GPIO_XREF_TABLE
