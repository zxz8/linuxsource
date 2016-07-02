/*=============================================================================
模   块   名: 网管服务器查询库
文   件   名: nmsinttest.h
相 关  文 件: nmsinttest.cpp
文件实现功能: 查询类
作        者: 王昊
版        本: V4.0  Copyright(C) 2003-2005 KDC, All rights reserved.
-------------------------------------------------------------------------------
修改记录:
日      期  版本    修改人      修改内容
2005/07/26  4.0     王昊        创建
=============================================================================*/

#ifndef _NMSINTTEST_20050726_H_
#define _NMSINTTEST_20050726_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "osp.h"
#include "nmsmsg.h"
#include "nmsinttestcom.h"
#include "nmsmacro.h"

class CNmsIntTest
{
public:
    CNmsIntTest();
    virtual ~CNmsIntTest() {}

public:
    /*=============================================================================
    函 数 名:ConnectNms
    功    能:连接服务器
    参    数:LPCTSTR pszSvrIpAddr               [in]    服务器IP地址
             u16 wPort                          [in]    服务器端口
    注    意:无
    返 回 值:TRUE:连接成功; FALSE:连接失败
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/08/16  4.0     王昊    创建
    =============================================================================*/
    virtual BOOL32 ConnectNms(LPCTSTR pszSvrIpAddr, u16 wPort);

    /*=============================================================================
    函 数 名:DisconnectNms
    功    能:与服务器断链
    参    数:无
    注    意:无
    返 回 值:TRUE:断链成功; FALSE:断链失败
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/08/16  4.0     王昊    创建
    =============================================================================*/
    virtual BOOL32 DisconnectNms(void);

    /*=============================================================================
    函 数 名:CmLoop
    功    能:配置轮询
    参    数:BOOL32 bStart                  [in]    TRUE:开始轮询; FALSE:停止轮询
    注    意:无
    返 回 值:TRUE:指令post成功; FALSE:指令post失败
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/08/16  4.0     王昊    创建
    =============================================================================*/
    virtual BOOL32 CmLoop(BOOL32 bStart);

    /*=============================================================================
    函 数 名:FmLoop
    功    能:告警轮询
    参    数:BOOL32 bStart                  [in]    TRUE:开始轮询; FALSE:停止轮询
    注    意:无
    返 回 值:TRUE:指令post成功; FALSE:指令post失败
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/08/16  4.0     王昊    创建
    =============================================================================*/
    virtual BOOL32 FmLoop(BOOL32 bStart);

    /*=============================================================================
    函 数 名:DeviceStampCheck
    功    能:检查设备的告警时间戳
    参    数:u32 dwDeviceID                 [in]    设备ID
             u32 dwAlarmStamp               [in]    预期告警时间戳
    注    意:无
    返 回 值:TRUE:告警时间戳和预期一致; FALSE:查询失败或告警时间戳与预期不一致
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/08/16  4.0     王昊    创建
    =============================================================================*/
    virtual BOOL32 DeviceStampCheck(u32 dwDeviceID, u32 dwAlarmStamp);

    /*=============================================================================
    函 数 名:DeviceLinkCheck
    功    能:检查设备的链路状态
    参    数:u32 dwDeviceID                 [in]    设备ID
             u8 byLinkState                 [in]    预期链路状态
    注    意:无
    返 回 值:TRUE:链路状态和预期一致; FALSE:查询失败或链路状态与预期不一致
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/08/17  4.0     王昊    创建
    =============================================================================*/
    virtual BOOL32 DeviceLinkCheck(u32 dwDeviceID, u8 byLinkState);

    /*=============================================================================
    函 数 名:GetReturn
    功    能:查询上次操作的结果
    参    数:u32 &dwRet                     [out]   操作结果
    注    意:无
    返 回 值:TRUE:查询成功; FALSE:查询失败
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/08/17  4.0     王昊    创建
    =============================================================================*/
    virtual BOOL32 GetReturn(u32 &dwRet);

    /*=============================================================================
    函 数 名:ConfigQuery
    功    能:服务器配置查询
    参    数:TSvrConfig *ptCfgData          [out]   返回的服务器配置
    注    意:无
    返 回 值:TRUE:查询成功; FALSE:查询失败
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/08/17  4.0     王昊    创建
    =============================================================================*/
    virtual BOOL32 ConfigQuery(TSvrConfig *ptCfgData);

    /*=============================================================================
    函 数 名:Timecheck
    功    能:检查系统当前时间是否和指定时间相近
    参    数:CTime &cAgtTime                [in]    指定时间
    注    意:无
    返 回 值:TRUE:服务器时间与指定时间相差5分钟以内; 
             FALSE:查询失败或服务器时间与指定时间相差5分钟以上
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/08/17  4.0     王昊    创建
    =============================================================================*/
    virtual BOOL32 Timecheck(CTime &cAgtTime);

    /*=============================================================================
    函 数 名:DeviceIsExist
    功    能:检查设备是否存在
    参    数:u32 dwDeviceID                 [in]    设备ID
    注    意:无
    返 回 值:TRUE:设备存在; FALSE:查询失败或设备不存在
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/08/17  4.0     王昊    创建
    =============================================================================*/
    virtual BOOL32 DeviceIsExist(u32 dwDeviceID);

    /*=============================================================================
    函 数 名:GetAllUser
    功    能:获取当前登陆所有用户名
    参    数:TCHAR (*paszUserName)[USER_LEN]    [out]       用户名数组
             s32 &nUserNum                      [in/out]    数组大小/用户个数
    注    意:无
    返 回 值:TRUE:获取成功; FALSE:查询失败或分配空间大小小于实际用户个数
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/08/17  4.0     王昊    创建
    =============================================================================*/
    virtual BOOL32 GetAllUser(TCHAR (*paszUserName)[USER_LEN], s32 &nUserNum);

    /*=============================================================================
    函 数 名:GetEqpVer
    功    能:获取设备版本号
    参    数:TCHAR aszEqpVer[DEVICE_VER_LEN]    [out]   版本号字符串
    注    意:无
    返 回 值:TRUE:获取成功; FALSE:查询失败
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/09/12  4.0     王昊    创建
    =============================================================================*/
    virtual BOOL32 GetEqpVer( TCHAR aszEqpVer[DEVICE_VER_LEN] );

protected:
    /*=============================================================================
    函 数 名:SendMsgToNms
    功    能:向NMS send消息
    参    数:u8 byEventId                   [in]    消息号
             CNmsMsg &cNmsMsg               [in]    消息体
             u8 *pbyAckBuf                  [out]   回应消息
             u16 wAckLen                    [out]   回应消息长度
             u16 *pwRealAckLen              [out]   实际返回长度
    注    意:无
    返 回 值:TRUE:发送成功; FALSE:发送失败
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/08/17  4.0     王昊    创建
    =============================================================================*/
    BOOL32 SendMsgToNms( u8 byEventId, CNmsMsg &cNmsMsg, u8 *pbyAckBuf,
                         u16 wAckLen, u16 *pwRealAckLen = NULL );

    /*=============================================================================
    函 数 名:PostMsgToNms
    功    能:向NMS post消息
    参    数:u8 byEventId                   [in]    消息号
             CNmsMsg &cNmsMsg               [in]    消息体
    注    意:无
    返 回 值:TRUE:发送成功; FALSE:发送失败
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2005/08/17  4.0     王昊    创建
    =============================================================================*/
    BOOL32 PostMsgToNms( u8 byEventId, CNmsMsg &cNmsMsg );

private:
    u32 m_dwNmsNode;        //  服务器节点
    u32 m_dwNmsInsId;       //  服务器实例号
};

#endif  //  _NMSINTTEST_20050726_H_