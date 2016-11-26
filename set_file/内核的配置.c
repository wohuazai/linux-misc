###�ں˵�����
@ make    s5pv210_defconfig  //������׼�������ļ�

1.    General setup  --->  //ͨ������ 
     ��һ��   ���� ��
		1.1 [*]   Configure standard kernel features (for small systems)  ---> 
                        //�ں˱���kernel panic, ����ʾ����ִ��ջ

2.[*] Enable loadable module support  --->  // ʹ��insmod
     ��ʹ�ܹ�          ģ��   ֧�֣�

3.[*] Enable the block layer  --->  // ����IO����, һ��ʹ��Ĭ�ϵľ�ok
                  (��   �� )
4.    System Type  --->   //ѡ���ض���arm core /cpu ����,�Լ����ǵ�һ������, make menuconfig֮��Ӧ��ȷ��һ�¸ò���
	     �����ͣ�
		4.1       ARM system type (Samsung S5PV210/S5PC110)  --->
     		4.2 (0)   S3C UART to use for low-level messages // �ں˵ĵ�����Ϣ��Ҫ��ttySAC0��ӡ���������Ҫ��bootargs�е�console=xx����һ��
     		4.3       S5PV210 Machines  --->//һ��Ĭ�Ͼͻ�ѡ�ϣ�ֻ�����ǲ鿴�����ļ�ѡ����Ƿ���ȷ

5.    Bus support  ---> // һЩ���ߵ�֧��,һ��ʹ��Ĭ�Ͼ�ok
	   ��֧�֣�
		
6.    Kernel Features  --->  //�ں˵�����,����Ӧ�ú��ں˿ռ���ڴ�ֲ�
	     ������  ��
		6.1       Memory split (3G/1G user/kernel split)  --->
   		6.2 [*]   Use the ARM EABI to compile the kernel //������湤�����г�����eabi,һ��Ҫѡ��
    	 	6.3 [*]   Allow old ABI binaries to run with this kernel (EXPERIMENTAL)

7.    Boot options  ---> //����ѡ��, �ں��������̵���,�����޸ĵ�����
     ������  ѡ�
		
8.    CPU Power Management  ---> // cpu��Դ����, һ�����õ���豸���л�Ҫ��ѡ��
         ������  ����   ��
9.    Power management options  ---> // ��Χ�豸�ĵ�Դ����    suspend()  resum()
      
10[*] Networking support  ---> // �����֧��,�����϶���Э�鷽���,����TCP/IP, ���׽���, �鲥 , pppЭ��
      10.1  Networking options  ---> 
              10.1.1 <*>   Packet sockets 
          	10.1.2 <*>   Unix domain sockets 
         	10.1.3 [*]   TCP/IP networking  <==========���������,һ��Ҫѡ��
          	10.1.4 [*]   IP: multicasting  
         	10.1.5 [*]   IP: kernel level autoconfiguration
		10.1.6 [*]   IP: BOOTP support

11.   Device Drivers  --->  // �豸����,��������������: ������===�豸������, ������˵�ѡ��
	
		11.1 <*>   Memory Technology Device (MTD) support  --->  // ��nand,onenand�ȵ��豸,��Ҫѡ��mtd
			    10.1.1 [*]   Command line partition table parsing //uboot���Դ��ݷ�����
       		    10.1.2 <*>   Caching block device access to MTD devices // CONFIG_MTD_BLOCK
        	           10.1.3 <*>   NAND Device Support  --->  //nand�豸֧��, �����ĳ��ƽ̨��nand������ѡ��
		
		11.2 [*]   Network device support  --->  //��Ҫ������
                         10.2.1 [*]   Ethernet (10 or 100Mbit) (NEW)  ---> 
                                      10.2.1.1<*>   DM9000 support
		
		11.3 [*]   USB support  --->
     		 	    11.3.1 <*>   Support for Host-side USB  
      		   	    11.3.2 [*]   USB device filesystem (DEPRECATED) 
                    	    11.3.3 [*]   USB device class-devices (DEPRECATED) (NEW) 
      			    11.3.4 <*>   USB Modem (CDC ACM) support			 // 3G����
      			    11.3.5 <*>   USB Serial Converter support  ---> usbת����		

		11.4       Graphics support  ---> // ͼ��: lcd
      			    11.4.1 <*>   Support for frame buffer devices  --->
       	  	    		   11.4.1.1 <*>    Samsung S3C framebuffer support
           		    11.4.2   	   Console display driver support --->
					   11.4.2.1 <*>    Framebuffer Console support
			    11.4.3 [*]   Bootup logo  --->  // ������log��ǰ����LCD����OK�ˣ�log������ʾ

12.   File systems  ---> // �ļ�ϵͳ��֧��,����֧��ntfs, ext4, nfs, cramfs, jiffs, minix..yaffs, ubifs,procfs,sysfs
		
		12.1 <*>   Ext3 journalling file system support
 		12.2 <*>   The Extended 4 (ext4) filesystem  
		12.3       Pseudo filesystems  ---> // �����ļ�ϵͳ: ���ڴ��й����ļ�,����֮��,�ļ��Ͳ�����, ������ʱ����ʱ����
			    // dev/, proc/, sys/����Ŀ¼�е��ļ�������ʱ
      			    12.3.1 [*]    /proc file system support (NEW) 
      			    12.3.2 [*]    sysfs file system support (NEW) 
			    12.3.3 [*]    Virtual memory file system support (former shm fs) 
			    12.3.4 [*]    Tmpfs POSIX Access Control Lists 
		
		//Configure standard kernel features (for small systems)���ѡ��һ��Ҫѡ��
 		12.4 [*]   Miscellaneous filesystems  ---> //�����ļ�ϵͳ, ��֧�ִ����nand���ļ��Ĺ���ʽ
			    12.4.1 <*>    Journalling Flash File System v2 (JFFS2) support
     			    12.4.2 [*]    JFFS2 write-buffering support 
	
 		12.5 <*>   Compressed ROM file system support (cramfs)
  			    12.5.1 <*>   SquashFS 4.0 - Squashed file system support
 		
		12.6 [*]   Network File Systems (NEW)  ---> // �����ļ�ϵͳ: nfs
			    12.6.1 <*>    NFS client support 
			    12.6.2 [*]    NFS client support for NFS version 3                                  x x
  				           12.8.2.1 [*]    NFS client support for the NFSv3 ACL protocol extension 
			   
			    12.6.3 [*]    Root file system on NFS 
		
		12.7 <*> Native language support  ---> //�ں�֧�ֵ��ַ����뷽ʽ
  			    12.7.1 <*>    Codepage 437 (United States, Canada)
   			    12.7.2 <*>    Simplified Chinese charset (CP936, GB2312)
   			    12.7.3 <*>    ASCII (United States)  
   			    12.7.4 <*>    NLS ISO 8859-1  (Latin 1; Western European Languages) 
   			    12.7.5 <*>    NLS UTF-8
----------------------------------------------------------------------------------------------------------------------------------------
�ܽ�: һ����Ҫѡ��procfs , sysfs, tmpfs,  cramfs, jffs, squashfs, nfs

$ make  zImage/uImage -j2
$ cp arch/arm/boot/zImage /tftpboot


ʵ������֪ʶ�㣺
1�������ں˱���ķ��� 
2����Ϥmenuconfig�����˵�����˼���Լ�������ø���ѡ�����ѡ����ע�����¼���ģ�飺 
    a�����������ǣ���Ҫѡ����Щ
    b��nandflash��Ҫ������Щ 
    c��LCD��Ҫ������Щѡ��
    d���ļ�ϵͳ��Ҫ������Щ�������� 

========================================================================================================================
=========================================================================================================================
###dm9000����ֲ

plat_devƽ̨�����޸�:
����vim arch/arm/mach-s5pc100/mach-smdkv210.c
����
//1. �޸�������mac��ַ:
static struct dm9000_plat_data smdkv210_dm9000_platdata = {
	.flags = DM9000_PLATF_16BITONLY | DM9000_PLATF_NO_EEPROM,
	.dev_addr    = { 0x00, 0x09, 0xc0, 0xff, 0xec, 0xee }, // ����Ϊ��λ����

};


//2. �޸Ľṹ������smdkv210_dm9000_resourcesΪ��
static struct resource smdkv210_dm9000_resources[] = {
��     [0] = {
��     	.start = 0x88000000,
��            .end  = 0x88000000 + 0x3,
              .flags = IORESOURCE_MEM,
��      },
��     [1] = {	
		.start = 0x88000000 + 0x4,	
		.end  = 0x88000000 + 0x4 + 0x3,	
		.flags = IORESOURCE_MEM,
��      },
	[2] = {
		.start = IRQ_EINT(10),
		.end = IRQ_EINT(10),
		.flags = IORESOURCE_IRQ | IORESOURCE_IRQ_HIGHLEVEL,
��      },
��};

//3. �޸ĺ���smdkv210_dm9000_initΪ��
��static void __init smdkv210_dm9000_init(void)
��{
�� 	unsigned int tmp;
��
�� 	gpio_request(S5PV210_MP01(1), "nCS1");
�� 	s3c_gpio_cfgpin(S5PV210_MP01(1), S3C_GPIO_SFN(2));
�� 	gpio_free(S5PV210_MP01(1));
��
�� 	tmp = (5 << S5P_SROM_BCX__TACC__SHIFT);
�� 	__raw_writel(tmp, S5P_SROM_BC1);
��	
�� 	tmp = __raw_readl(S5P_SROM_BW);
�� 	tmp&= (S5P_SROM_BW__CS_MASK << S5P_SROM_BW__NCS1__SHIFT);
�� 	tmp |= (1 << S5P_SROM_BW__NCS1__SHIFT);
�� 	__raw_writel(tmp, S5P_SROM_BW);
��}

-------------------------------------------------------------------------------------------------------------------------
plat_drv��ֲ������
 
//1.�޸�������driver/net/dm9000.c, ���ļ���ƫ��ʼ��λ�����
static unsigned char  boot_dev_addr[6];
static unsigned char  boot_mac_flag = 0;
static int __init netmac_boot_setup(char *str)
{
 	int i = 0;
 	char *buf, *tok;
 	char *whitespace = ":";
 	buf = str;
 	do {
  		buf = buf + strspn(buf, whitespace); // find : 
  		tok = strsep(&buf, whitespace); // seperate string
  		if (*tok == '\0') {
     		break;
    	   }
    		if(i >= 6)
     			break;
     		boot_dev_addr[i++] = (unsigned char )simple_strtoul(tok, NULL, 16);
	   }while(buf);
  
	if (i != 6)
   		return 0;

	boot_mac_flag = 1;
	return 1;
}

__setup("ethaddr=", netmac_boot_setup); // �������__setup������bootargs�д��ݵ�ethaddr=00:12:34:aa:ac:ef ����Ч

//2. �޸�dm9000_probe()
if (!is_valid_ether_addr(ndev->dev_addr) && pdata != NULL) {
  	mac_src = "platform data";
  	///////////////jihq add
  	if(boot_mac_flag)
   		memcpy(ndev->dev_addr, boot_dev_addr, 6); //ʹ��uboot���ݹ�����mac��ַ
 	else
  		memcpy(ndev->dev_addr, pdata->dev_addr, 6);
 }


-------------------------------------------------------------------------------------------------------------------------
dm9000���ں�����

�����ں�

$ make menuconfig


[*] Networking support (NEW)  --->

	Networking options  ---> 

		<*> Packet socket

		<*> Unix domain sockets

		[*] TCP/IP networking

		[*]   IP: multicasting 

		[*]   IP: kernel level autoconfiguration

		[*]     IP: BOOTP support 

Device Drivers  --->  

	[*] Network device support  --->

		[*]   Ethernet (10 or 100Mbit)  --->

			<*>   DM9000 support 

File systems  --->  

	[*] Network File Systems  --->

		<*>   NFS client suppor

		[*]     NFS client support for NFS version 3  

		[*]       NFS client support for the NFSv3 ACL protocol extension

		[*]     Root file system on NFS 

 

�����ںˣ���������tftpbootĿ¼��

$ make  zImage

$ cp arch/arm/boot/zImage  /tftpboot

