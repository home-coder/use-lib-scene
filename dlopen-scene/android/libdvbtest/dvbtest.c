#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <pthread.h>

#include "Rt10upDriver.h"
#define TS_PACKET_SIZE (188)
#define USB_CHIP_BULK_SIZE (496)
#define LEN_READ (TS_PACKET_SIZE*USB_CHIP_BULK_SIZE*2)
void cmdMainMenu(void)
{
	printf("input your mode:\n");
	printf("	v.chip version\n");
	printf("	o.open device\n");
	printf("	1.tune freq\n");
	printf("	2.tune state\n");
	printf("	3.Crrent freq\n");
	printf("	4.Get Ts data to save file\n");
	printf("	5.smart card reset\n");
	printf("	6.smart card transmit\n");
	printf("	7.set filter(PID,when pid=0 full stream) \n");
	printf("	8.get samart status\n");
	printf("	9.getSTBID\n");
	printf("	d.init DVB mode\n");
	printf("	t.init dtmb mode\n");
	printf("	h.high vcc \n");
	printf("	l.low vcc \n");
	printf("	c.close \n");
	printf("	q.quit\n");
}

int dvbtest()
{
	ULONG i =0;
	UCHAR buf[256];
	char input;
	int ret ;
	int fd=0;
	FILE *filefd;
	int freqence,QAM,SymbolRate;
	int pid=0;
	UCHAR  VCCLevel;
	UCHAR *buffer;
	ULONG blocknum=0;
	CA_SCARD_CMD sc_cmd;
	CA_SCARD_ATR  scATR,*pATR;
	pATR = &scATR;
	NOVEL_USB_FREQ_SET_CONTROL freq;
	NOVEL_USB_PID_SET_CONTROL fullts;
//	TUNER_MODE_CMD tuner_mode_cmd;
	STB_ID id;
	ULONG block;
	UCHAR tunerNumer = 0;
	
	
	cmdMainMenu();
	while(1)
	{
	    
		scanf("%c",&input);
		if(input == 'q')
		{
			close(fd);
			break;
		}
		switch(input)
		{
		
		case 'o'://open device
			if ((fd = open("/dev/rt10up", O_RDWR)) < 0)
			{
				printf("\n ---------- open /dev/rt10up error --------- \n");
				return 0;
			}
			else
			{
			    printf("open device(/dev/rt10up) sucess fd =%x\n",fd);
		    }
		    cmdMainMenu();
			break;
		case 'v'://chip version
		    if(fd <= 0)
		    {
		        printf("/dev/rt10up error\n");
		        
		        break;
		    }
			ret = ioctl(fd,RT10UP_TUNER_CHECKIICWR,0);
			printf("\n ------------Chip type:%x\n",ret);
			cmdMainMenu();
			break;
		case 'd':	
//			tuner_mode_cmd.tunerID = 0;
//			tuner_mode_cmd.mode = DTVS_DVB_C_TYPE;
//			ret = ioctl(fd,RT10UP_TUNER_INIT,&tuner_mode_cmd);
//			printf("\n ------------RT10UP_TUNER_INIT :%x\n",ret);
			break;
		case 't':	
//			tuner_mode_cmd.tunerID = 0;
//			tuner_mode_cmd.mode = DTVS_DTMB_TYPE;
//			ret = ioctl(fd,RT10UP_TUNER_INIT,&tuner_mode_cmd);
//			printf("\n ------------RT10UP_TUNER_INIT :%x\n",ret);
			break;		
		case '1'://tune freq
		    printf("please input freq(MHZ) QAM SymbolRate\n");
		    printf("lg: 698 2 6875\n");
			scanf("%d %d %d",&freqence,&QAM,&SymbolRate);
			freq.freq_=(ULONG)freqence*1000;
			freq.QAM_ = (ULONG)QAM;
			freq.SymbolRate_=(ULONG)SymbolRate;
			printf("you input freq=%ldMhz,QAM=%ld,SymbolRate_=%ld\n",freq.freq_,freq.QAM_,freq.SymbolRate_);
			ret =ioctl(fd, RT10UP_TUNER_SET_FREQ, &freq);
			if(ret == 0)
			{
				printf("tune freq sucess\n");
			}
			else
			{
				printf("tune freq fail ret =%x\n",ret);
			}
			cmdMainMenu();
			break;
		case '2'://tune state
			ret =ioctl(fd, RT10UP_TUNER_GET_SIGNAL_STATUS, buf);
			printf("GetTunerStatus %02X	\n",ret);
			for( i = 0;i< 8;i++)
			{
				printf("%02X	 ",buf[i]);
			}
			printf("\n");
            cmdMainMenu();
			break;
		case '3'://Crrent freq
		    ret = ioctl(fd,RT10UP_TUNER_GET_FREQ,(UCHAR *)&freq);
		    printf("current freq %ldkhz,QAM=%ld,SymbolRate_=%ld\n",freq.freq_,freq.QAM_,freq.SymbolRate_);
			cmdMainMenu();
			break;
		case '4'://Get Ts data to save file
			printf("first please input 7 to set filter ,otherwise follow last filter,if the pid is not correct,you can not get tsdata\n");
			printf("please input block(one block = 188*496*2)\n");
			scanf("%ld",&block);
			
			filefd = fopen("/data/test.ts","wb+");
			if( filefd == NULL)
			{
				printf("\n ---------- open /data/test.ts error --------- \n");
				return 0;
			}
			buffer =(UCHAR*)malloc(block*LEN_READ);
			if(buffer == NULL)
			{
				fclose(filefd);
				return 0;
			}
			for( i = 0 ;i < block ;)
			{
				ret = ioctl(fd,RT10UP_TUNER_GET_TSDATA,buffer);
				if( ret != LEN_READ)
				{
					continue;
				}
				i++ ; 
			}
			for( blocknum = 0 ; blocknum < block ; blocknum++ )
			{
				fwrite(buffer+blocknum*LEN_READ,LEN_READ,1,filefd);
			}
			fclose(filefd);
			
			free(buffer);
			cmdMainMenu();
			break;
		case '5'://smart card reset
			pATR->nLen = 0;
			memset(pATR->Data,0,256);
			ret =ioctl(fd, RT10UP_CA_SC_RESET,&scATR );
			printf("\n ---------- RT10UP_CA_SC_RESET end --------- ret=%x\n",ret);
			for( i = 0;i<scATR.nLen;i++)
			{
				printf("%02X   ",scATR.Data[i]);
			}
			printf("%02ld   ",scATR.nLen);
			printf("\n");
            cmdMainMenu();
			break;
		case '6'://smart card transmit
			memset(buf,0,256);
			buf[0] = 0x00;
			buf[1] = 0xA4;
			buf[2] = 0x04;
			buf[3] = 0x00;
			buf[4] = 0x05;
			buf[5] = 0xF9;
			buf[6] = 0x5A;
			buf[7] = 0x04;
			buf[8] = 0x00;
			buf[9] = 0x06;
			buf[10] = 0;
			memcpy(sc_cmd.Command,buf,10);
			sc_cmd.nCommandLen = 10;
			for(i = 0;i<sc_cmd.nCommandLen;i++)
			{
			    printf("%02X  ",sc_cmd.Command[i]);
			}
			printf("\n");
			ret = ioctl(fd,RT10UP_CA_SC_CMD,&sc_cmd);
			printf("\n ------------RT10UP_CA_SC_CMD :%x\n",ret);
			for( i = 0;i< sc_cmd.nReplyLen;i++)
			{
				printf("%02X	 ",sc_cmd.Reply[i]);
			}
			printf("\n");
			cmdMainMenu();
			break;
		case '7':
			printf("please input pid\n");
			scanf("%d",&pid);
			if(pid==0)
			{
				fullts.num_ = 0;
			}
			else
			{
				fullts.num_ = 1;
				fullts.pids_[0] = (USHORT)pid;
			}
			ret =ioctl(fd, RT10UP_TUNER_SET_PID, &fullts);
			cmdMainMenu();
			break;
		case '8'://get samart status
			memset(buf,0,256);
			ret = ioctl(fd,RT10UP_CA_SC_GET_STATUS,buf);
			printf("\n ------------RT10UP_CA_SC_GET_STATUS :%x\n",ret);
			break;
		case '9'://getSTBID
			memset(buf,0,256);
			ret =ioctl(fd, RT10UP_CA_GET_STBID, &id);
			printf("\n ---------- RT10UP_CA_GET_STBID end --------- ret=%d,nUniqueID=%02x%02x%02x%02x\n",ret,id.nUniqueID[0],id.nUniqueID[1],id.nUniqueID[2],id.nUniqueID[3]);
			cmdMainMenu();
			break;
		case '0':
		    cmdMainMenu();
			break;
		case 'h':	
    	VCCLevel = 1;
    	ret = ioctl(fd,RT10UP_CA_SC_VCCEN, &VCCLevel); 	
    	cmdMainMenu();
   		break;
   	case 'l':	
    	VCCLevel = 0;
    	ret = ioctl(fd,RT10UP_CA_SC_VCCEN, &VCCLevel); 	
    	cmdMainMenu();
   		break;
		case 'c'://Close device
			tunerNumer = 0;
//			ret = ioctl(fd,RT10UP_TUNER_DEINIT,&tunerNumer);
//			printf("\n ------------RT10UP_TUNER_DEINIT :%x\n",ret);
		    cmdMainMenu();
			return 0;
		default:
			break;
		}
	}
	return 0;
}
