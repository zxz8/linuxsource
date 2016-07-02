/*****************************************************************************
   模块名      : Recorder
   文件名      : RecInterface.h
   相关文件    : 
   文件实现功能: Rec库封装对外接口提供
   作者        : 
   版本        : V4.0  Copyright(C) 2007-2009 KDC, All rights reserved.
-----------------------------------------------------------------------------
   修改记录:
   日  期      版本        修改人      修改内容
   2007/08/06  4.0         张宝卿      创建
******************************************************************************/
#ifndef _REC_INTERFACE_H_
#define _REC_INTERFACE_H_

#include "kdvtype.h"
#include "ksp.h"
#include "kdvmcurec.h"
//#include "recgeninfo.h"

/*====================================================================
  函数名      ：RecInit
  功能        ：本静态库总的初始入口
  引用全局变量：
  输入参数说明：TRecCfgInfo &tCfgInfo：[in]  初始化参数 
                u8 &byErrId:        [out] 初始化失败的原因，见emRecGenErr
  返回值说明  ：成功返回 TRUE，否则返回FALSE
----------------------------------------------------------------------
  修改记录    ：
  日  期      版本        修改人        修改内容
  07/08/06    4.0         张宝卿        创建
====================================================================*/
BOOL32 RecInit( TRecCfgInfo &tCfgInfo, u8 &byErrId );


/*====================================================================
    函数名	     ：ModifyCfg
	功能		 ：修改录像机配置
	引用全局变量 ：
    输入参数说明 ：TRecCfgInfo &tCfgInfo   [in] 配置信息
                   u8       &byErrId    [out]配置信息错误ID
                   u8       &byRestartRec   [out] 成功修改配置后是否需要重启 1-重启，0-不重启
	返回值说明   ：成功返回 TRUE，否则返回FALSE
----------------------------------------------------------------------
	修改记录    ：
	日  期      版本        修改人        修改内容
	07/08/06	4.0			张宝卿		  创建
====================================================================*/
BOOL32 RecModifyCfg( TRecCfgInfo &tCfgInfo, u8 &byErrId, u8 &byRestartRec );

/*====================================================================
    函数名	     ：RecStop
	功能		 ：退出录像机
	引用全局变量 ：
    输入参数说明 ：u8 byErrId: 退出异常错误码ID，参见 emRecGenErr. 默认：emRecSucceed
	返回值说明   ：成功返回 TRUE，否则返回FALSE
----------------------------------------------------------------------
	修改记录    ：
	日  期      版本        修改人        修改内容
	07/08/06	4.0			张宝卿		  创建
====================================================================*/
BOOL32 RecStop( u8 &byErrId );

/*====================================================================
    函数名	     ：RecStartCallBack
	功能		 ：开始录像(开始会议)回调
	引用全局变量 ：
    输入参数说明 ：TRecProperty  &tRecProperty   [out]录像信息
                   TConfProperty &tConfProperty  [out]会议信息
                   u8            &byErrId        [out]开始录像失败原因上报，参见 emRecGenErr. 默认：emRecSucceed
	返回值说明   ：void
----------------------------------------------------------------------
	修改记录    ：
	日  期      版本        修改人        修改内容
	07/08/06	4.0			张宝卿		  创建
====================================================================*/
typedef void (*RecStartCallBack)( TRecProperty &tRecProperty, TConfProperty &tConfProperty, u8 &byErrId );


/*====================================================================
    函数名	     ：SetRecStartCB
	功能		 ：开始录像(开始会议)回调
	引用全局变量 ：
    输入参数说明 ：RecStartCallBack pCBStart   [in] 注册的回调函数
	返回值说明   ：void
----------------------------------------------------------------------
	修改记录    ：
	日  期      版本        修改人        修改内容
	07/08/06	4.0			张宝卿		  创建
====================================================================*/
void SetRecStartCB(RecStartCallBack pCBStart);

/*====================================================================
    函数名	     ：RecPauseCallBack
	功能		 ：暂停录像(开始会议)回调
	引用全局变量 ：
    输入参数说明 ：DWORD dwIndex    [in] 开始会议时传入的索引号，TConfProperty.m_dwIndex
                   u8 &byErrId      [out]恢复录像失败原因上报，参见 emRecGenErr. 默认：emRecSucceed
	返回值说明   ：void
----------------------------------------------------------------------
	修改记录    ：
	日  期      版本        修改人        修改内容
	07/11/10	4.0			张宝卿		  创建
====================================================================*/
typedef void (*RecPauseCallBack)(DWORD dwIndex, u8 &byErrId);

/*====================================================================
    函数名	     ：SetRecPauseCB
	功能		 ：暂停录像(开始会议)回调
	引用全局变量 ：
    输入参数说明 ：RecPauseCallBack pCBPause    [in] 注册的回调函数
	返回值说明   ：void
----------------------------------------------------------------------
	修改记录    ：
	日  期      版本        修改人        修改内容
	07/11/10	4.0			张宝卿		  创建
====================================================================*/
void SetRecPauseCB(RecPauseCallBack pCBPause);

/*====================================================================
    函数名	     ：RecResumeCallBack
	功能		 ：恢复录像(开始会议)回调
	引用全局变量 ：
    输入参数说明 ：DWORD dwIndex    [in] 开始会议时传入的索引号，TConfProperty.m_dwIndex
                   u8 &byErrId      [out]恢复录像失败原因上报，参见 emRecGenErr. 默认：emRecSucceed
	返回值说明   ：void
----------------------------------------------------------------------
	修改记录    ：
	日  期      版本        修改人        修改内容
	07/11/10	4.0			张宝卿		  创建
====================================================================*/
typedef void (*RecResumeCallBack)(DWORD dwIndex, u8 &byErrId);

/*====================================================================
    函数名	     ：SetRecResumeCB
	功能		 ：暂停录像(开始会议)回调
	引用全局变量 ：
    输入参数说明 RecResumeCallBack pCBResume    [in] 注册的回调函数
	返回值说明   ：void
----------------------------------------------------------------------
	修改记录    ：
	日  期      版本        修改人        修改内容
	07/11/10	4.0			张宝卿		  创建
====================================================================*/
void SetRecResumeCB(RecResumeCallBack pCBResume);


/*====================================================================
    函数名	     ：RecStopCallBack
	功能		 ：结束录像(结束会议)回调
	引用全局变量 ：
    输入参数说明 ：DWORD dwIndex    [in] 开始会议时传入的索引号，TConfProperty.m_dwIndex
                   u8 &byErrId      [out]结束录像失败原因上报，参见 emRecGenErr. 默认：emRecSucceed
	返回值说明   ：void
----------------------------------------------------------------------
	修改记录    ：
	日  期      版本        修改人        修改内容
	07/08/06	4.0			张宝卿		  创建
====================================================================*/
typedef void (*RecStopCallBack)(DWORD dwIndex, u8 &byErrId);

/*====================================================================
    函数名	     ：SetRecStopCB
	功能		 ：停止录像(停止会议)回调
	引用全局变量 ：
    输入参数说明 ：RecStopCallBack pCBStop [in] 注册的回调函数
	返回值说明   ：void
----------------------------------------------------------------------
	修改记录    ：
	日  期      版本        修改人        修改内容
	07/08/06	4.0			张宝卿		  创建
====================================================================*/
void SetRecStopCB(RecStopCallBack pCBStop);

/*====================================================================
    函数名	     ：RecStreamCallBack
	功能		 ：码流属性及数据回调处理
	引用全局变量 ：
    输入参数说明 ：TStreamProperty *ptSProperty [out]: 流属性回调
                   u8              &byErrId     [out]: 流属性及数据回调错误原因，参见 emRecGenErr. 默认：emRecSucceed
	返回值说明   ：void
----------------------------------------------------------------------
	修改记录    ：
	日  期      版本        修改人        修改内容
	07/08/06	4.0			张宝卿		  创建
====================================================================*/
typedef void (*RecStreamCallBack)( TStreamProperty *ptSProperty, u8 &byErrId );

/*====================================================================
    函数名	     ：SetRecStreamCB
	功能		 ：码流到来回调
	引用全局变量 ：
    输入参数说明 ：RecStopCallBack pCBStream [in] 注册的回调函数
	返回值说明   ：void
----------------------------------------------------------------------
	修改记录    ：
	日  期      版本        修改人        修改内容
	07/08/06	4.0			张宝卿		  创建
====================================================================*/
void SetRecStreamCB(RecStreamCallBack pCBStream);


#endif  //!_REC_INTERFACE_H_