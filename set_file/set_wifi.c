#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 256
#define SIZE_LESSER 20
#define FLAG_SUB "##"

#define WIFI_CFG 	"wpa_supplicant.cfg"
#define WIFI_SRC 	"wifi_info.cfg"
#define BACKUPS     "backups_wifi.cfg"

#define SSID		"ssid"
#define PSK		"psk"

static FILE *write_fp;
static char *ps_site;
static char replace_buf[SIZE]= {0};


//参数1: 修改的文件，参数2:搜索的内容 ，参数3:修改的内容为
int mate_str(char *find_letter)      //返回大于0，表示找到的位置。返回0找不到
{
    int mate_flag,ret = -1;
    int line_len;

    write_fp = fopen(WIFI_CFG,"r+");
    if(NULL == write_fp)
    {
	perror("fopen wpa_supplicant.cfg failed");
	exit(1);
    }

    memset(replace_buf,0,sizeof(SIZE));
    while(fgets(replace_buf,SIZE,write_fp) != NULL)
    {
	//	line_len += strlen(replace_buf);
	if(ps_site = strstr(replace_buf,find_letter))
	{	
	    mate_flag = 1;
	    break;
	}
    }

    if(mate_flag){
	line_len = ftell(write_fp);
	ret = line_len - strlen(ps_site);
    }
    return ret;
}

//获取字符串函数
void acquire_str(char *find_letter,char *wifi_param)
{
    int line_len;
    
    line_len = mate_str(find_letter); 
    if(line_len == -1){
	printf("find %s failed\n",find_letter);
	wifi_param = NULL;                   //表示查找失败
    }else{
	ps_site += strlen(find_letter)+1;
//	memcpy(wifi_param,ps_site,strlen(ps_site));
	strncpy(wifi_param,ps_site,strlen(ps_site)-1);
    }
    fclose(write_fp);
}    

//替换字符串函数
int replace_str(char *find_letter,char *alter_letter)
{
    FILE *backups_fp;
    int line_len;


    backups_fp = fopen(BACKUPS,"w+");
    if(NULL == backups_fp)
    {
	perror("fopen wifi_info.cfg failed");
	fclose(write_fp);
	exit(1);
    }

    line_len = mate_str(find_letter); 
    if(line_len == 0){
	printf("find %s failed\n",find_letter);
	fclose(write_fp);
	fclose(backups_fp);
	remove(BACKUPS);
	return -1;
    }

    while(!feof(write_fp) && !ferror(write_fp))
    {
	memset(replace_buf,0,sizeof(SIZE));
	fread(replace_buf,1,SIZE,write_fp);
	fwrite(replace_buf,1,strlen(replace_buf),backups_fp);
    }
    if(truncate(WIFI_CFG,line_len))
    {
	perror("truncate backups.cfg failed");
	fclose(write_fp);
	fclose(backups_fp);
	remove(BACKUPS);
	exit(1);
    }
    fseek(backups_fp,0,SEEK_SET);
    fseek(write_fp,0,SEEK_END);

    /*
       if(!strcmp(find_letter,SSID) || !strcmp(alter_letter,PSK))
       sprintf(replace_buf,"%s=%s\n",find_letter,alter_letter);
       else
     */
    sprintf(replace_buf,"%s=%s\n",find_letter,alter_letter);

    fwrite(replace_buf,1,strlen(replace_buf),write_fp);

    while(!feof(backups_fp) && !ferror(backups_fp))
    {
	memset(replace_buf,0,sizeof(SIZE));
	fread(replace_buf,1,SIZE,backups_fp);
	fwrite(replace_buf,1,strlen(replace_buf),write_fp);
    }
    fclose(write_fp);
    fclose(backups_fp);
    remove(BACKUPS);
    return 0;
}



int main()
{
    if(replace_str("ssid","\"huazai1992\""))
    {
	printf("set_wifi failed\n");
	return -1;      
    }
#if 0
    char temp[SIZE]; 
    char *sp = temp;

    acquire_str("ssid",sp);
    if(sp == NULL)
    {
	printf("set_wifi failed\n");
	return -1;      
    }
    printf("%s\n",sp);   
#endif
    return 0;
}



/*
//获取以某个封装字符串的函数，如：xxx##xxx##
int packaging_data()
{
FILE *read_fp;
int n = 0;
char *temp;

char buf[SIZE]= {0},replace_buf[SIZE]= {0};
char ssid[SIZE_LESSER],psk[SIZE_LESSER],phone[SIZE_LESSER],account_psk[SIZE_LESSER];
read_fp = fopen(WIFI_SRC,"r");
if(NULL == read_fp)
{
perror("fopen wifi_info.cfg failed");
exit(1);
}

while(fgets(buf,SIZE,read_fp) != NULL)   //把文件的内容复制到buf_dat
{
strcat(replace_buf,buf);
memset(buf,0,sizeof(buf));
}

if(NULL ==(temp = strtok(replace_buf,FLAG_SUB)))   //如果ssid为0，则退出。
{
printf("Invalid ssid !\n");
return -1;
}

do
{
if(n == 0)
memcpy(ssid,temp,strlen(temp));
if(n == 1)
memcpy(psk,temp,strlen(temp));
if(n == 2)
memcpy(phone,temp,strlen(temp));
if(n == 3)
memcpy(account_psk,temp,strlen(temp));
if(n == 4)
break;
n++;
}
while(temp =strtok(NULL,FLAG_SUB));
memset(replace_buf,0,sizeof(SIZE));
}
 */
