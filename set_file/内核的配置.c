###内核的配置
@ make    s5pv210_defconfig  //拷贝标准板配置文件

1.    General setup  --->  //通用配置 
     （一般   设置 ）
		1.1 [*]   Configure standard kernel features (for small systems)  ---> 
                        //内核崩溃kernel panic, 会提示代码执行栈

2.[*] Enable loadable module support  --->  // 使能insmod
     （使能够          模块   支持）

3.[*] Enable the block layer  --->  // 磁盘IO调度, 一般使用默认的就ok
                  (块   层 )
4.    System Type  --->   //选择特定的arm core /cpu 类型,以及它们的一下属性, make menuconfig之后应当确认一下该部分
	     （类型）
		4.1       ARM system type (Samsung S5PV210/S5PC110)  --->
     		4.2 (0)   S3C UART to use for low-level messages // 内核的调试信息需要由ttySAC0打印出来，这个要和bootargs中的console=xx保持一致
     		4.3       S5PV210 Machines  --->//一般默认就会选上，只是我们查看配置文件选择的是否正确

5.    Bus support  ---> // 一些总线的支持,一般使用默认就ok
	   （支持）
		
6.    Kernel Features  --->  //内核的特性,比如应用和内核空间的内存分布
	     （特性  ）
		6.1       Memory split (3G/1G user/kernel split)  --->
   		6.2 [*]   Use the ARM EABI to compile the kernel //如果交叉工具链中出现了eabi,一定要选上
    	 	6.3 [*]   Allow old ABI binaries to run with this kernel (EXPERIMENTAL)

7.    Boot options  ---> //启动选项, 内核启动过程当中,可以修改的特性
     （引导  选项）
		
8.    CPU Power Management  ---> // cpu电源管理, 一般在用电池设备当中会要做选择
         （功率  管理   ）
9.    Power management options  ---> // 外围设备的电源管理    suspend()  resum()
      
10[*] Networking support  ---> // 网络的支持,基本上都是协议方面的,比如TCP/IP, 域套接字, 组播 , ppp协议
      10.1  Networking options  ---> 
              10.1.1 <*>   Packet sockets 
          	10.1.2 <*>   Unix domain sockets 
         	10.1.3 [*]   TCP/IP networking  <==========如果有网卡,一定要选上
          	10.1.4 [*]   IP: multicasting  
         	10.1.5 [*]   IP: kernel level autoconfiguration
		10.1.6 [*]   IP: BOOTP support

11.   Device Drivers  --->  // 设备驱动,包含两部分驱动: 控制器===设备的驱动, 经常光顾的选项
	
		11.1 <*>   Memory Technology Device (MTD) support  --->  // 有nand,onenand等等设备,需要选择mtd
			    10.1.1 [*]   Command line partition table parsing //uboot可以传递分区表
       		    10.1.2 <*>   Caching block device access to MTD devices // CONFIG_MTD_BLOCK
        	           10.1.3 <*>   NAND Device Support  --->  //nand设备支持, 具体的某个平台的nand控制器选项
		
		11.2 [*]   Network device support  --->  //需要有网卡
                         10.2.1 [*]   Ethernet (10 or 100Mbit) (NEW)  ---> 
                                      10.2.1.1<*>   DM9000 support
		
		11.3 [*]   USB support  --->
     		 	    11.3.1 <*>   Support for Host-side USB  
      		   	    11.3.2 [*]   USB device filesystem (DEPRECATED) 
                    	    11.3.3 [*]   USB device class-devices (DEPRECATED) (NEW) 
      			    11.3.4 <*>   USB Modem (CDC ACM) support			 // 3G配置
      			    11.3.5 <*>   USB Serial Converter support  ---> usb转串口		

		11.4       Graphics support  ---> // 图形: lcd
      			    11.4.1 <*>   Support for frame buffer devices  --->
       	  	    		   11.4.1.1 <*>    Samsung S3C framebuffer support
           		    11.4.2   	   Console display driver support --->
					   11.4.2.1 <*>    Framebuffer Console support
			    11.4.3 [*]   Bootup logo  --->  // 启动的log，前提是LCD驱动OK了，log才能显示

12.   File systems  ---> // 文件系统的支持,比如支持ntfs, ext4, nfs, cramfs, jiffs, minix..yaffs, ubifs,procfs,sysfs
		
		12.1 <*>   Ext3 journalling file system support
 		12.2 <*>   The Extended 4 (ext4) filesystem  
		12.3       Pseudo filesystems  ---> // 虚拟文件系统: 在内存中管理文件,掉电之后,文件就不存在, 开机的时候临时创建
			    // dev/, proc/, sys/几个目录中的文件都是临时
      			    12.3.1 [*]    /proc file system support (NEW) 
      			    12.3.2 [*]    sysfs file system support (NEW) 
			    12.3.3 [*]    Virtual memory file system support (former shm fs) 
			    12.3.4 [*]    Tmpfs POSIX Access Control Lists 
		
		//Configure standard kernel features (for small systems)这个选项一定要选上
 		12.4 [*]   Miscellaneous filesystems  ---> //杂项文件系统, 对支持存放在nand中文件的管理方式
			    12.4.1 <*>    Journalling Flash File System v2 (JFFS2) support
     			    12.4.2 [*]    JFFS2 write-buffering support 
	
 		12.5 <*>   Compressed ROM file system support (cramfs)
  			    12.5.1 <*>   SquashFS 4.0 - Squashed file system support
 		
		12.6 [*]   Network File Systems (NEW)  ---> // 网络文件系统: nfs
			    12.6.1 <*>    NFS client support 
			    12.6.2 [*]    NFS client support for NFS version 3                                  x x
  				           12.8.2.1 [*]    NFS client support for the NFSv3 ACL protocol extension 
			   
			    12.6.3 [*]    Root file system on NFS 
		
		12.7 <*> Native language support  ---> //内核支持的字符编码方式
  			    12.7.1 <*>    Codepage 437 (United States, Canada)
   			    12.7.2 <*>    Simplified Chinese charset (CP936, GB2312)
   			    12.7.3 <*>    ASCII (United States)  
   			    12.7.4 <*>    NLS ISO 8859-1  (Latin 1; Western European Languages) 
   			    12.7.5 <*>    NLS UTF-8
----------------------------------------------------------------------------------------------------------------------------------------
总结: 一般需要选择procfs , sysfs, tmpfs,  cramfs, jffs, squashfs, nfs

$ make  zImage/uImage -j2
$ cp arch/arm/boot/zImage /tftpboot


实验掌握知识点：
1，掌握内核编译的方法 
2，熟悉menuconfig中主菜单的意思，以及如何配置各个选项，几个选项中注意以下几个模块： 
    a，配置网卡是，需要选择哪些
    b，nandflash需要配置哪些 
    c，LCD需要配置那些选项
    d，文件系统需要配置哪些基本类型 

========================================================================================================================
=========================================================================================================================
###dm9000的移植

plat_dev平台代码修改:
　　vim arch/arm/mach-s5pc100/mach-smdkv210.c
　　
//1. 修改网卡的mac地址:
static struct dm9000_plat_data smdkv210_dm9000_platdata = {
	.flags = DM9000_PLATF_16BITONLY | DM9000_PLATF_NO_EEPROM,
	.dev_addr    = { 0x00, 0x09, 0xc0, 0xff, 0xec, 0xee }, // 设置为座位号码

};


//2. 修改结构体数组smdkv210_dm9000_resources为：
static struct resource smdkv210_dm9000_resources[] = {
　     [0] = {
　     	.start = 0x88000000,
　            .end  = 0x88000000 + 0x3,
              .flags = IORESOURCE_MEM,
　      },
　     [1] = {	
		.start = 0x88000000 + 0x4,	
		.end  = 0x88000000 + 0x4 + 0x3,	
		.flags = IORESOURCE_MEM,
　      },
	[2] = {
		.start = IRQ_EINT(10),
		.end = IRQ_EINT(10),
		.flags = IORESOURCE_IRQ | IORESOURCE_IRQ_HIGHLEVEL,
　      },
　};

//3. 修改函数smdkv210_dm9000_init为：
　static void __init smdkv210_dm9000_init(void)
　{
　 	unsigned int tmp;
　
　 	gpio_request(S5PV210_MP01(1), "nCS1");
　 	s3c_gpio_cfgpin(S5PV210_MP01(1), S3C_GPIO_SFN(2));
　 	gpio_free(S5PV210_MP01(1));
　
　 	tmp = (5 << S5P_SROM_BCX__TACC__SHIFT);
　 	__raw_writel(tmp, S5P_SROM_BC1);
　	
　 	tmp = __raw_readl(S5P_SROM_BW);
　 	tmp&= (S5P_SROM_BW__CS_MASK << S5P_SROM_BW__NCS1__SHIFT);
　 	tmp |= (1 << S5P_SROM_BW__NCS1__SHIFT);
　 	__raw_writel(tmp, S5P_SROM_BW);
　}

-------------------------------------------------------------------------------------------------------------------------
plat_drv移植方法：
 
//1.修改驱动：driver/net/dm9000.c, 在文件的偏向开始的位置添加
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

__setup("ethaddr=", netmac_boot_setup); // 有了这个__setup，我们bootargs中传递的ethaddr=00:12:34:aa:ac:ef 才有效

//2. 修改dm9000_probe()
if (!is_valid_ether_addr(ndev->dev_addr) && pdata != NULL) {
  	mac_src = "platform data";
  	///////////////jihq add
  	if(boot_mac_flag)
   		memcpy(ndev->dev_addr, boot_dev_addr, 6); //使用uboot传递过来的mac地址
 	else
  		memcpy(ndev->dev_addr, pdata->dev_addr, 6);
 }


-------------------------------------------------------------------------------------------------------------------------
dm9000的内核配置

配置内核

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

 

编译内核，并拷贝到tftpboot目录下

$ make  zImage

$ cp arch/arm/boot/zImage  /tftpboot

