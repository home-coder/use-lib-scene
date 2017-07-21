/************************************************************************************/
/*
 * **********************************************************************************
 *  Copyright(C) 2013  joysee   ALL RIGHTS RESERVED 
 *  Please review the terms of the license agreement before using
 *  this file. If you are not an authorized user, please destroy this
 *  source code file and notify CHINA DTV immediately that you
 *  inadvertently received an unauthorized copy.
 * **********************************************************************************
 * \file Rt10upError.h
 *
 * h file   .
 * File description        : Rt10up error Code 
 * author                  : tpwang                                                              
 *      
 * History:                                                               
 *          ----------------------------------------------------                 
 *          V0.01, 2013.09.12, tpwang, initial version  
 *			V0.01, 2013.09.12, tpwang, adaptor qualcomm  platform, last modification                           
 ************************************************************************************/

#ifndef __RT10UP_ERROR_CODE_H__
#define __RT10UP_ERROR_CODE_H__


#define RT10UP_SUCCESS                        			(0x00)

#define RT10UP_ERR_MEM_MALLOC_FAIL						(0x801A0001)	
#define RT10UP_ERR_INVALID_POINT						(0x801A0002)
#define RT10UP_ERR_INVALID_PARA							(0x801A0003)
#define RT10UP_ERR_DEV_NOT_OPEN							(0x801A0004)
#define RT10UP_ERR_DEV_DISCONNET						(0x801A0005)
#define RT10UP_ERR_DEV_BUSY								(0x801A0006)
#define RT10UP_ERR_DATA_FULL							(0x801A0007)
#define RT10UP_ERR_DOWNLD_FIRMWARE_FAILED				(0x801A0008)
#define RT10UP_ERR_CMD_NOT_SUPPORT						(0x801A0009)


#define RT10UP_ERR_TUNER_NOT_INIT                       (0x802A0001)
#define RT10UP_ERR_TUNER_NOT_OPEN                       (0x802A0002)
#define RT10UP_ERR_TUNER_INVALID_POINT                  (0x802A0003)
#define RT10UP_ERR_TUNER_INVALID_PARA                   (0x802A0004)
#define RT10UP_ERR_TUNER_FAILED_INIT                    (0x802A0005)
#define RT10UP_ERR_TUNER_FAILED_TUNE	                (0x802A0006)
#define RT10UP_ERR_TUNER_FAILED_GETSTATUS               (0x802A0007)
#define RT10UP_ERR_TUNER_FAILED_GETSIGNALSTRENGTH       (0x802A0008)
#define RT10UP_ERR_TUNER_FAILED_GETBER                  (0x802A0009)
#define RT10UP_ERR_TUNER_NOT_SUPPORT                    (0x802A000A)

#define RT10UP_ERR_SC_NOT_INIT                       (0x802B0001)
#define RT10UP_ERR_SC_NOT_OPEN                       (0x802B0002)
#define RT10UP_ERR_SC_INVALID_POINT                  (0x802B0003)
#define RT10UP_ERR_SC_INVALID_PARA                   (0x802B0004)
#define RT10UP_ERR_SC_FAILED_RESET                   (0x802B0005)
#define RT10UP_ERR_SC_FAILED_TRASMIT	             (0x802B0006)
#define RT10UP_ERR_SC_WAITING	             	 	 (0x802B0007)
#define RT10UP_ERR_SC_TIMEOUT	             	 	 (0x802B0008)
#define RT10UP_ERR_SC_NONE	             	     	 (0x802B0009)
#define RT10UP_ERR_SC_UNRECOGNIZED				 	 (0x802B000A)
#define RT10UP_ERR_SC_NOT_SUPPORT                    (0x802B000C)


//status code
#define RT10UP_STATUS_RESET                          (0x802C0000)
#define RT10UP_STATUS_NOT_READ_DATA                  (0x802C0001)
#define RT10UP_STATUS_IDLE                           (0x802C0002)
#define RT10UP_STATUS_SC_IN                          (0x802C0003)
#define RT10UP_STATUS_SC_OUT                         (0x802C0004)
#define RT10UP_STATUS_ERR_DATALEN                    (0x802C0005)
#define RT10UP_STATUS_SEND                           (0x802C0006)
#define RT10UP_STATUS_RECEIVE                        (0x802C0007)

#define RT10UP_ERR_USB_RW_FAILED    	           (0x802C0001)
 



#endif /* __RT10UP_ERROR_CODE_H__ */
