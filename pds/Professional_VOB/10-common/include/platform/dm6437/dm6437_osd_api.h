/******************************************************************************
模块名  ： DM6437_OSD_DRV
文件名  ： dm6437_osd_api.h
相关文件： dm6437_osd_api.c
文件实现功能：
作者    ：张方明
版本    ：1.0.0.0.0
-------------------------------------------------------------------------------
修改记录:
日  期      版本        修改人      修改内容
04/22/2008  1.0         张方明      创建
******************************************************************************/
#ifndef __DM6437_OSD_API_H
#define __DM6437_OSD_API_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* runtime include files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "dm6437_drv_common.h"

/****************************** 模块的版本号命名规定 *************************
总的结构：mn.mm.ii.cc.tttt
     如  Osp 1.1.7.20040318 表示
模块名称Osp
模块1版本
接口1版本
实现7版本
04年3月18号提交

版本修改记录：
----------------------------------------------------------------------------
模块版本：DM6437_OSD_DRV 1.1.1.20080515
增加功能：创建
修改缺陷：无
提交人：张方明
----------------------------------------------------------------------------
模块版本：DM6437_OSD_DRV 1.1.2.20080604
增加功能：使用自己的IOM封装
修改缺陷：无
提交人：张方明

****************************************************************************/
/* 版本号定义 */
#define VER_DM6437_OSD_DRV         (const s8*)"DM6437_OSD_DRV 1.1.2.20080604" 

/* 极限值定义 */
#define DM6437_OSD_DEV_MAX_NUM        2      /* 一个DM6437上最大支持2个OSD设备，OSD0+OSD1，OSD1作为OSD0的属性层 */
#define DM6437_OSD_BUF_MAX_NUM        32     /* 目前最多允许分配的BUF个数 */

#define DM6437_DEVID_OSD0             0      /* OSD0设备ID,数据格式要求为RGB565 */
#define DM6437_DEVID_OSD1             1      /* OSD1设备ID, 作为OSD0的属性层，每个象素占用4bits，其中低3位表示其透明度
                                                0~7，0为全透明，7为不透明 */

/* Dm6437OsdCtrl操作码定义 */

/* 类型定义 */
typedef void * HDm6437OsdDev;


/* 视频OSD设备创建的参数结构定义
   窗口大小不能超过Vid0层的窗口,原点在左上角 */
typedef struct{
    u16	      wPosX;                    /* 窗口X方向坐标，像素为单位 */
    u16	      wPosY;                    /* 窗口Y方向坐标，行为单位 */
    u16	      wWidth;                   /* 窗口宽，像素为单位 */
    u16	      wHeight;                  /* 窗口高，行为单位 */
    BOOL      bProgressive;             /* 逐行或隔行显示，TRUE=逐行；FALSE=隔行 */
    TFBufDesc *pBufDescs;               /* 指向用户分配的FBufDesc结构变量数组的首地址 */
    u32       dwFBufNum;                /* 要分配的FBufDesc的个数，范围：0~DM6437_OSD_BUF_MAX_NUM-1 */
    u16	      wWidthMax;                /* 最大窗口宽，像素为单位, 用于分配Buf */
    u16	      wHeightMax;               /* 最大窗口高，行为单位, 用于分配Buf
                                               注意：由于用户会经常打开关闭OSD设备，因此驱动中分配Buf时仅在第一次打开
                                               设备时按照最大分辨率来分配Buf，后面打开设备继续沿用该Buf，这样可以避免
                                               内存碎片过多引起分配失败问题 */
} TDm6437OsdDevParam;



/*==============================================================================
    函数名      : Dm6437OsdOpen
    功能        ：视频OSD设备打开
    输入参数说明：dwDevId: DM6437_DEVID_OSD0/DM6437_DEVID_OSD1;
                  ptParam: 打开的参数
    返回值说明  ：错误返回NULL；成功返回控制句柄
------------------------------------------------------------------------------*/
HDm6437OsdDev Dm6437OsdOpen(u32 dwDevId, TDm6437OsdDevParam *ptParam);

/*==============================================================================
    函数名      : Dm6437OsdClose
    功能        ：视频OSD设备关闭。
    输入参数说明：hOsdDev: Dm6437OsdOpen函数返回的句柄;
    返回值说明  ：错误返回DM6437_DRV_FAILURE或错误码；成功返回DM6437_DRV_SUCCESS
------------------------------------------------------------------------------*/
l32 Dm6437OsdClose(HDm6437OsdDev hOsdDev);

/*==============================================================================
    函数名      : Dm6437OsdFBufGet
    功能        ：取一个视频OSD BUF，用户可以多次调用取多个BUF。
    输入参数说明：hOsdDev: 调用Dm6437OsdOpen函数返回的句柄;
                  pBufDesc: 用户分配并传入指针，驱动将BUF信息拷贝给用户
                  nTimeoutMs: -1=wait forever; 0=no wait;其他正值为超时毫秒数
    返回值说明  ：错误返回DM6437_DRV_FAILURE或错误码；成功返回DM6437_DRV_SUCCESS
------------------------------------------------------------------------------*/
l32 Dm6437OsdFBufGet(HDm6437OsdDev hOsdDev, TFBufDesc *pBufDesc, l32 nTimeoutMs);

/*==============================================================================
    函数名      : Dm6437OsdFBufPut
    功能        ：归还一个视频BUF并加到OSD队列中进行播放
    输入参数说明：hOsdDev: 调用Dm6437OsdOpen函数返回的句柄;
                  pBufDesc: 用户调用Dm6437OsdFBufGet得到的BufDesc信息
    返回值说明  ：错误返回DM6437_DRV_FAILURE或错误码；成功返回DM6437_DRV_SUCCESS
------------------------------------------------------------------------------*/
l32 Dm6437OsdFBufPut(HDm6437OsdDev hOsdDev, TFBufDesc *pBufDesc);

/*==============================================================================
    函数名      : Dm6437OsdCtrl
    功能        ：视频OSD设备控制，目前定义了
                  ......
    输入参数说明：hOsdDev: 调用Dm6437OsdOpen函数返回的句柄;
                 nCmd: 操作码；pArgs: 参数指针
    返回值说明  ：错误返回DM6437_DRV_FAILURE或错误码；成功返回DM6437_DRV_SUCCESS
------------------------------------------------------------------------------*/
l32 Dm6437OsdCtrl(HDm6437OsdDev hOsdDev, l32 nCmd, void *pArgs);

/*====================================================================
    函数名      : Dm6437OsdGetVer
    功能        ：模块版本号查询。
    输入参数说明：pchVer： 给定的存放版本信息的buf指针
                  dwBufLen：给定buf的长度
    返回值说明  ：版本的实际字符串长度。小于0为出错;
                 如果实际字符串长度大于dwBufLen，赋值为0
--------------------------------------------------------------------*/
l32 Dm6437OsdGetVer(s8 *pchVer, u32 dwBufLen);

#ifdef __cplusplus 
} 
#endif /* __cplusplus */

#endif /* __DM6437_OSD_API_H */
