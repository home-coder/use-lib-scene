/************************************************************************************/
/*
 * **********************************************************************************
 *  Copyright(C) 2012  joysee   ALL RIGHTS RESERVED 
 *  Please review the terms of the license agreement before using
 *  this file. If you are not an authorized user, please destroy this
 *  source code file and notify CHINA DTV immediately that you
 *  inadvertently received an unauthorized copy.
 * **********************************************************************************
 * \file Rt10upDriver.h
 *
 * h file   .
 * File description        : Rt10up interface Code
 * author                  : tpwang                                                              
 *      
 * History:                                                               
 *          ----------------------------------------------------                 
 *          V0.01, 2012.05.20, tpwang, initial version  
 *          V0.02, 2013.01.30, tpwang, last modification   
 *			V0.03, 2013.08.22, tpwang, adaptor qualcomm  platform, last modification                           
 ************************************************************************************/

#ifndef __NOVEL_SUPERTV_RT10UP_H__
#define __NOVEL_SUPERTV_RT10UP_H__


#define UUIUSB_IOC_MAGIC        ('k')
#define RT10UP_TUNER_SET_FREQ           _IO(UUIUSB_IOC_MAGIC,1)
#define RT10UP_TUNER_GET_FREQ           _IO(UUIUSB_IOC_MAGIC,2)
#define RT10UP_TUNER_SET_PID            _IO(UUIUSB_IOC_MAGIC,3)
#define RT10UP_TUNER_GET_TSDATA         _IO(UUIUSB_IOC_MAGIC,4)
#define RT10UP_TUNER_GET_SIGNAL_STATUS  _IO(UUIUSB_IOC_MAGIC,5)
#define RT10UP_GET_INFRARED             _IO(UUIUSB_IOC_MAGIC,6)
#define RT10UP_CA_SC_GET_STATUS         _IO(UUIUSB_IOC_MAGIC,7)
#define RT10UP_CA_SC_RESET              _IO(UUIUSB_IOC_MAGIC,8)
#define RT10UP_CA_SC_CMD                _IO(UUIUSB_IOC_MAGIC,9)
#define RT10UP_CA_GET_STBID             _IO(UUIUSB_IOC_MAGIC,10)
#define RT10UP_CA_SC_SET_CW             _IO(UUIUSB_IOC_MAGIC,11)
#define RT10UP_CA_SC_FUNCTION           _IO(UUIUSB_IOC_MAGIC,12)
#define RT10UP_CA_SC_TRANSMIT           _IO(UUIUSB_IOC_MAGIC,13)
#define RT10UP_CA_SC_INSERT             _IO(UUIUSB_IOC_MAGIC,14)
#define RT10UP_TUNER_CHECKIICWR         _IO(UUIUSB_IOC_MAGIC,15)
#define RT10UP_RESET_USB_PIPE           _IO(UUIUSB_IOC_MAGIC,16)
#define RT10UP_USB_SPEED_MODE           _IO(UUIUSB_IOC_MAGIC,17)
#define RT10UP_TUNER_SET_PID_AND_TYPE   _IO(UUIUSB_IOC_MAGIC,18)
#define RT10UP_TUNER_GET_PSI_TSDATA     _IO(UUIUSB_IOC_MAGIC,19)
#define RT10UP_FRONT_END_WRITE          _IO(UUIUSB_IOC_MAGIC,20)
#define RT10UP_FRONT_END_READ           _IO(UUIUSB_IOC_MAGIC,21)
#define RT10UP_IS_READY					_IO(UUIUSB_IOC_MAGIC,22)
#define RT10UP_CA_SC_VCCEN       	    _IO(UUIUSB_IOC_MAGIC,23)

/*�ڶ���tuner*/
#define RT10UP_TUNER_SET_FREQ2           _IO(UUIUSB_IOC_MAGIC,24)
#define RT10UP_TUNER_GET_FREQ2           _IO(UUIUSB_IOC_MAGIC,25)
#define RT10UP_TUNER_SET_PID2            _IO(UUIUSB_IOC_MAGIC,26)
#define RT10UP_TUNER_GET_TSDATA2         _IO(UUIUSB_IOC_MAGIC,27)
#define RT10UP_TUNER_GET_SIGNAL_STATUS2  _IO(UUIUSB_IOC_MAGIC,28)
#define RT10UP_TUNER_SET_PID_AND_TYPE2   _IO(UUIUSB_IOC_MAGIC,29)
#define RT10UP_TUNER_GET_PSI_TSDATA2     _IO(UUIUSB_IOC_MAGIC,30)
#define RT10UP_CA_SC_FUNCTION2           _IO(UUIUSB_IOC_MAGIC,31)
#define RT10UP_TUNER_GET_LOCK2           _IO(UUIUSB_IOC_MAGIC,32)

/*������tuner*/
#define RT10UP_TUNER_SET_FREQ3           _IO(UUIUSB_IOC_MAGIC,35)
#define RT10UP_TUNER_GET_FREQ3           _IO(UUIUSB_IOC_MAGIC,36)
#define RT10UP_TUNER_SET_PID3            _IO(UUIUSB_IOC_MAGIC,37)
#define RT10UP_TUNER_GET_TSDATA3         _IO(UUIUSB_IOC_MAGIC,38)
#define RT10UP_TUNER_GET_SIGNAL_STATUS3  _IO(UUIUSB_IOC_MAGIC,40)
#define RT10UP_TUNER_SET_PID_AND_TYPE3   _IO(UUIUSB_IOC_MAGIC,41)
#define RT10UP_TUNER_GET_PSI_TSDATA3     _IO(UUIUSB_IOC_MAGIC,42)
#define RT10UP_CA_SC_FUNCTION3           _IO(UUIUSB_IOC_MAGIC,43)
#define RT10UP_TUNER_GET_LOCK3           _IO(UUIUSB_IOC_MAGIC,44)

#define RT10UP_TUNER_GET_LOCK            _IO(UUIUSB_IOC_MAGIC,50)
#define RT10UP_TUNER_INIT		     	 _IO(UUIUSB_IOC_MAGIC,51)
#define RT10UP_TUNER_DEINIT		     	 _IO(UUIUSB_IOC_MAGIC,52)
#define RT10UP_SC_POWERONOFF		     _IO(UUIUSB_IOC_MAGIC,53)
#define RT10UP_SC_BAUDRATE		         _IO(UUIUSB_IOC_MAGIC,54)
#define RT10UP_SC_SEND		             _IO(UUIUSB_IOC_MAGIC,55)
#define RT10UP_SC_RECEIVE		         _IO(UUIUSB_IOC_MAGIC,56) 

#define RT10UP_TUNER_IICREAD             _IO(UUIUSB_IOC_MAGIC,57) 
#define RT10UP_TUNER_IICWRITE			 _IO(UUIUSB_IOC_MAGIC,58)
#define RT10UP_TUNER_IICRESET			 _IO(UUIUSB_IOC_MAGIC,59)

#define RT10UP_ENABLE_SCRAMBLE			     _IO(UUIUSB_IOC_MAGIC,60)
#define RT10UP_SET_SCRAMBLE_KEY			 _IO(UUIUSB_IOC_MAGIC,61)

#define RT10UP_SET_GPIO_LEVEL			 _IO(UUIUSB_IOC_MAGIC,71)

#define MAX_PID_NUM                     (32)
#define CA_TRAM_CMD_MAX                 (320)
#define CA_ATR_MAX                      (33+3)
#define CA_DATA_MAX                     (256)

typedef signed long    LONG;
typedef unsigned long  ULONG;
typedef unsigned short USHORT;
typedef unsigned char  UCHAR;
typedef unsigned char* PUCHAR;  
typedef unsigned long* PULONG;


typedef struct usb_device USBDEV;
typedef struct usb_device USBHANDLE;
typedef struct completion   COMPLETION;
typedef struct urb          URB;
typedef struct workqueue_struct WORKQUEUE;
typedef struct work_struct  WORKTASK;


typedef enum {
    SETSYBOL_ERROR  = -9,
    SETQAM_ERROR    = -8,
    USBICWR_ERROR   = -7,
    IICWRFAIL       = -6,
    INVAILDFREQ     = -5,
    MEMORYERROR     = -4,
    INVAILDPARM     = -3,
    LOCKFAIL        = -2,
    TUNERERROR      = -1,
    ERROR           = -1,
    TIMEOUT         = -1,
    NOERROR         = 0,
    TUNERSUCESS     = 0
}TUNERSTATUS,SCSTATUS,STATUS;

typedef struct _tm10023Qam_t
{
    UCHAR  bQam;
    UCHAR  bLockthr;
    UCHAR  bMseth;
    UCHAR  bAref;
    UCHAR  bAgcRefNyq;
    UCHAR  bErAgcNyqThd;
} tmQam_t;

typedef struct RT10UP_REQUEST_CONTROL
{   
    UCHAR   request_code;  
    USHORT  address;   
    UCHAR   direction;    
    USHORT  length;   
    UCHAR   buffer[CA_DATA_MAX];
}REQUEST_CONTROL,*PREQUEST_CONTROL;   

typedef struct _NOVEL_USB_FREQ_SET_CONTROL
{
    ULONG   freq_;
    ULONG   QAM_;
    ULONG   SymbolRate_;
} NOVEL_USB_FREQ_SET_CONTROL, *PNOVEL_USB_FREQ_SET_CONTROL;

typedef struct _NOVEL_USB_PID_SET_CONTROL
{
    ULONG     num_;  // 0 ȫ����
    USHORT    pids_[MAX_PID_NUM];

} NOVEL_USB_PID_SET_CONTROL, *PNOVEL_USB_PID_SET_CONTROL;

typedef struct _NOVEL_USB_PID_TYPE_SET_CONTROL
{
    NOVEL_USB_PID_SET_CONTROL  pidArray;
    UCHAR                      pidType[MAX_PID_NUM];
} NOVEL_USB_PID_TYPE_SET_CONTROL, *PNOVEL_USB_PID_TYPE_SET_CONTROL;


typedef struct _NOVEL_CW 
{
    USHORT  pids_;
    UCHAR  oddkey_[8];
    UCHAR  evenkey_[8];
} NOVEL_CW,*PNOVEL_CW;

typedef struct _NOVEL_SECRET_CW 
{
    USHORT pid_;
    UCHAR  oddkey_[8];
    UCHAR  evenkey_[8];
} NOVEL_SECRET_CW,*PNOVEL_SECRET_CW;

typedef struct _NOVEL_USB_CW_SET_CONTROL
{
    ULONG     num_;
    NOVEL_CW  cw_[MAX_PID_NUM];

} NOVEL_USB_CW_SET_CONTROL, *PNOVEL_USB_CW_SET_CONTROL;

typedef struct _NOVEL_VENDOR_OR_CLASS_REQUEST_CONTROL
{
    UCHAR   request_code;
    USHORT  address;
    UCHAR   direction;
    USHORT  length;
    UCHAR   buffer[CA_DATA_MAX];
} NOVEL_VENDOR_OR_CLASS_REQUEST_CONTROL, *PNOVEL_VENDOR_OR_CLASS_REQUEST_CONTROL;

typedef struct _NOVEL_USB_STB_ID
{
    USHORT  wPlatformID;
    ULONG   dwUniqueID;
} NOVEL_USB_STB_ID, *PNOVEL_USB_STB_ID;

typedef struct _NOVEL_USB_CHIP_DATA
{
    UCHAR ChipData[CA_DATA_MAX];
} NOVEL_USB_CHIP_DATA, *PNOVEL_USB_CHIP_DATA;

typedef struct
{
    ULONG nLen;
    UCHAR Data[CA_DATA_MAX];
}CA_SCARD_ATR;


typedef struct
{
    UCHAR Command[CA_TRAM_CMD_MAX];
    ULONG nCommandLen;  
    UCHAR Reply[CA_TRAM_CMD_MAX];  
    ULONG nReplyLen;
}CA_SCARD_CMD;

typedef struct
{
    UCHAR key[16];
    UCHAR keylen;  
    UCHAR evenodd;//0:no scaramble,1:odd,2:even
}SCARMBLE_KEY;

typedef struct
{
    UCHAR nPlatformID[2];
    UCHAR nReserve[2];
    UCHAR nUniqueID[4]; // ������ֵ
}STB_ID;


typedef struct
{
    ULONG PID;
    ULONG counter;
}PID_COUNTINUER;

typedef struct
{   
    UCHAR    *buffer;   
    ULONG    length;    
}TUNER_DATA_BUF_CMD,*PTUNER_DATA_BUF_CMD;   

typedef enum
{   
    OFF = 0,
    ON  
}CTLONOFF,*PCTLONOFF;
 
typedef enum
{   
    BAUDRATE9600  = 0,
    BAUDRATE38400 ,
    BAUDRATE57600 ,
    BAUDRATE115200  
}SCBAUDRATE,*PSCBAUDRATE;

typedef enum
{   
    GET_TS_BUFFER_MODE,
    PSI_TS_MODE,
    ALL_TS_MODE
}TUNER_DATA_MODE,*PTUNER_DATA_MODE;  
 
typedef enum
{   
    TS_VIDEO_TYPE,
    TS_AUDIO_TYPE,
    TS_PSI_TYPE
}STREAM_TYPE,*PSTREAM_TYPE;

//7�����ֱ�׼
typedef enum
{   
    DTVS_DVB_C_TYPE,
    DTVS_DVB_T_TYPE,
    DTVS_DVB_S_TYPE,
    DTVS_DTMB_TYPE,
    DTVS_ATSC_TYPE,
    DTVS_ISDB_TYPE,
    DTVS_T_DMB_TYPE
}DTVS_TYPE,*PDTVS_TYPE;

typedef struct
{   
    UCHAR tunerID;
	DTVS_TYPE mode;    
}TUNER_MODE_CMD,*PTUNER_MODE_CMD;  

typedef struct
{   
    UCHAR gpio;
	UCHAR level;    
}IO_CMD,*PIO_CMD;  


typedef struct
{   
    unsigned long iicadd; 
    unsigned char iicaddsize; 
    unsigned char *buf;
    unsigned long wsize;
    unsigned char *rbuf;
    unsigned long rsize;
}IICCMD;

typedef struct
{   
    unsigned char tunerNo; 
    unsigned char demoNo; 
    unsigned char dataNo;
}MaptunerDataTable;

#endif

