/*****************************************************************************
模块名      : GkcTestOperate
文件名      : GkcTestOperate.h
相关文件    : GkcTestOperate.cpp
              
文件实现功能: 定义Gkc测试操作库的接口类，提供接口给单元测试和集成测试使用
作者        : 陈洪斌
模块版本    : V4.0  Copyright(C) 2002-2005 KDC, All rights reserved.
-----------------------------------------------------------------------------
修改记录:
日  期(n/m/d)      文件版本        修改人      修改内容
2005/08/10         0.1            陈洪斌      创建
******************************************************************************/
#if !defined(AFX_GKCTESTOPERATE_H__F7A57A67_85AC_45AB_B9B8_85A23B451301__INCLUDED_)
#define AFX_GKCTESTOPERATE_H__F7A57A67_85AC_45AB_B9B8_85A23B451301__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <Winsock2.h>

class CGkcTestOperate  
{
public:
	CGkcTestOperate();
	virtual ~CGkcTestOperate();
public:

//////////////////////////////////////////////////////////////////////////
// 系统操作 
//////////////////////////////////////////////////////////////////////////
    /*====================================================================
    函数名      :StartGKC
    功能        :启动被测试的GK控制台
    输入参数说明:lpszGkcFile : 运行Gkc程序的文件名)
    返回值说明  :TRUE 启动成功
                 FALSE 启动失败
    ====================================================================*/
	BOOL StartGkc(LPCSTR lpszGkcFile);

    /*====================================================================
    函数名      :StopGkc
    功能        :测试完成后结束Gkc运行的程序
    输入参数说明:无
    返回值说明  :无
    ====================================================================*/
    BOOL StopGkc();
    
    /*====================================================================
    函数名      :GkcActive
    功能        :在最顶层显示Gkc的窗口
    输入参数说明:无
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL GkcActive();
    
//////////////////////////////////////////////////////////////////////////
//登陆和注销
//////////////////////////////////////////////////////////////////////////
    /*====================================================================
    函数名      :UsrLogIn
    功能        :用户登录
    输入参数说明:lpszUser : 登录用户名称
                 lpszPwd  : 登录用户密码
                 dwServerIp : 登录服务器Ip地址
                 wPort    : 登录服务器端口号
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL UsrLogIn(LPCSTR lpszUser,
                  LPCSTR lpszPwd,
                  DWORD dwServerIp = ntohl(inet_addr("127.0.0.1")),
                  WORD wPort = 60000);

	/*====================================================================
    函数名      :UsrLogOut
    功能        :用户注销
    输入参数说明:无
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL UsrLogOut();

//////////////////////////////////////////////////////////////////////////
// 运行时操作接口
//////////////////////////////////////////////////////////////////////////
    /*====================================================================
    函数名      :RestartGK
    功能        :重起GK
    输入参数说明:无
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL RestartGK();
    
    /*====================================================================
    函数名      :UnRegisterEndpoint
    功能        :强制注销已注册实体
    输入参数说明:tEndpointRasAddr: 已注册实体的Ras地址信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL UnRegisterEndpoint(CString& strH323Alias);

    /*====================================================================
    函数名      :StopCall
    功能        :强制结束呼叫(结束界面上已经显示的某个呼叫)
    输入参数说明:tSrcCallAddr: 主叫地址 (匹配于TCallIdDBData结构中的m_tSrcCallAddr)
                 tDstCallAddr: 被叫地址 (匹配于TCallIdDBData结构中的m_tDstCallAddr)
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL StopCall(CString& strSrcAlias, CString& strDstAlias);
    
//////////////////////////////////////////////////////////////////////////
// 配置操作接口 -- 基本配置
//////////////////////////////////////////////////////////////////////////
    /*====================================================================
    函数名      :AddPrefix
    功能        :新增区号
    输入参数说明:tGkPrefix: 增加的区号信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL AddPrefix(TGKPrefix& tGkPrefix);

    /*====================================================================
    函数名      :DelPrefix
    功能        :删除区号
    输入参数说明:tGkPrefix: 删除的区号信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL DelPrefix(TGKPrefix& tGkPrefix);
    
    /*====================================================================
    函数名      :DelAllPrefix
    功能        :删除所有区号
    输入参数说明:无
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL DelAllPrefix();

    /*====================================================================
    函数名      :AddNeighborGk
    功能        :新增临近GK服务器
    输入参数说明:tNeighborGkInfo : 新增临近GK服务器信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL AddNeighborGk(TNeighborGKInfo& tNeighborGkInfo);

    /*====================================================================
    函数名      :DelNeighborGk
    功能        :删除某个临近GK服务器
    输入参数说明:tNeighborGkInfo : 删除的临近GK服务器信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL DelNeighborGk(TNeighborGKInfo& tNeighborGkInfo);

    /*====================================================================
    函数名      :DelAllNeighborGk
    功能        :删除所有临近GK服务器
    输入参数说明:无
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL DelAllNeighborGk();

    /*====================================================================
    函数名      :SetAuthMethod
    功能        :配置GK注册认证策略
    输入参数说明:cAuthMethod: 认证策略信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL SetAuthMethod(CGkAuthMothod& cAuthMethod);    

//////////////////////////////////////////////////////////////////////////
//  配置操作接口 -- 网段带宽配置接口
//////////////////////////////////////////////////////////////////////////
    /*====================================================================
    函数名      :AddSubnetBandwidth
    功能        :新增网段间带宽
    输入参数说明:tAddCfgBandwidth: 新增网段间带宽信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL AddSubnetBandwidth(TConfigBandWidthDBData& tAddCfgBandwidth);

    /*====================================================================
    函数名      :DelSubnetBandwidth
    功能        :删除网段间带宽
    输入参数说明:tDelCfgBandwidth: 删除的网段间带宽信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL DelSubnetBandwidth(TConfigBandWidthDBData& tDelCfgBandwidth);

    /*====================================================================
    函数名      :ModifySubnetBandwidth
    功能        :修改网段间带宽
    输入参数说明:tOldCfgBandwidth: 修改前的网段间带宽信息
                 tNewCfgBandwidth: 修改后的网段间带宽信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL ModifySubnetBandwidth(TConfigBandWidthDBData& tOldCfgBandwidth,
                                TConfigBandWidthDBData& tNewCfgBandwidth);
    
    /*====================================================================
    函数名      :DelAllSubnetBandwidth
    功能        :删除所有网段间带宽
    输入参数说明:无
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL DelAllSubnetBandwidth();

//////////////////////////////////////////////////////////////////////////
//  配置操作接口 -- 认证Ip范围配置接口
//////////////////////////////////////////////////////////////////////////
    /*====================================================================
    函数名      :AddIpRange
    功能        :新增认证Ip范围
    输入参数说明:tAddCfgIpRange:新增Ip范围信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL AddIpRange(TConfigAuthIPDBData& tAddCfgIpRange); 
    
    /*====================================================================
    函数名      :DelIpRange
    功能        :删除认证Ip范围
    输入参数说明:tDelCfgIpRange:删除Ip范围信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL DelIpRange(TConfigAuthIPDBData& tDelCfgIpRange); 

    /*====================================================================
    函数名      :ModifyIpRange
    功能        :修改认证Ip范围
    输入参数说明:tOldCfgIpRange:修改前的Ip范围信息
                 tNewCfgIpRange:修改后的Ip范围信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL ModifyIpRange(TConfigAuthIPDBData& tOldCfgIpRange,
                        TConfigAuthIPDBData& tNewCfgIpRange);
    /*====================================================================
    函数名      :DelAllIpRange
    功能        :删除所有认证Ip范围
    输入参数说明:无
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL DelAllIpRange(); 

//////////////////////////////////////////////////////////////////////////
//  配置操作接口 -- 认证实体配置接口
//////////////////////////////////////////////////////////////////////////
    /*====================================================================
    函数名      :AddEndpoint
    功能        :新增认证实体
    输入参数说明:tAddCfgEndpoint: 新增禁止/允许实体
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL AddEndpoint(TConfigAliasAuthDBData& tAddCfgEndpoint);

    /*====================================================================
    函数名      :DelEndpoint
    功能        :删除认证实体
    输入参数说明:tDelCfgEndpoint: 删除禁止/允许实体
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL DelEndpoint(TConfigAliasAuthDBData& tDelCfgEndpoint);
    
    /*====================================================================
    函数名      :ModifyEndpoint
    功能        :修改认证实体
    输入参数说明:tOldCfgEndpoint: 修改前的认证实体
                 tNewCfgEndpoint: 修改后的认证实体
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL ModifyEndpoint(TConfigAliasAuthDBData& tOldCfgEndpoint,
                         TConfigAliasAuthDBData& tNewCfgEndpoint);

    /*====================================================================
    函数名      :DelAllEndpoint
    功能        :删除所有认证实体
    输入参数说明:无
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL DelAllEndpoint();
    
//////////////////////////////////////////////////////////////////////////
//  用户管理操作接口
//////////////////////////////////////////////////////////////////////////
    /*====================================================================
    函数名      :AddUser
    功能        :新增用户
    输入参数说明:tAddUser: 新增用户信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL AddUser(TCtrlUserDBData& tAddUser);
    
    /*====================================================================
    函数名      :DelUser
    功能        :删除用户
    输入参数说明:tDelUser: 删除用户信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL DelUser(TCtrlUserDBData& tDelUser);

    /*====================================================================
    函数名      :ModifyUser
    功能        :修改用户
    输入参数说明:tOldUser: 修改前的用户信息
                 tNewUser: 修改后的用户信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL ModifyUser(TCtrlUserDBData& tOldUser, TCtrlUserDBData& tNewUser);

    /*====================================================================
    函数名      :ModifyUserPwd
    功能        :修改用户密码(管理员用户登录的操作)
    输入参数说明:tOldUser: 修改前的用户信息
                 tNewUser: 修改后的用户信息
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL ModifyUserPwd(TCtrlUserDBData& tOldUser, TCtrlUserDBData& tNewUser);    

	/*====================================================================
	函数名      :ModifyUserPwd
	功能        :修改用户密码(非管理员用户修改自身密码)
	输入参数说明:strOldPwd: 旧密码
				 strNewPwd: 新密码
	返回值说明  :TRUE: 操作成功
				 FALSE: 操作失败
	====================================================================*/
	BOOL ModifyUserPwd( LPCSTR strOldPwd, LPCSTR strNewPwd);
    
	/*====================================================================
    函数名      :DelAllUser
    功能        :删除所有用户（不包括管理员用户）
    输入参数说明:无
    返回值说明  :TRUE: 操作成功
                 FALSE: 操作失败
    ====================================================================*/
    BOOL DelAllUser();

};

#endif // !defined(AFX_GKCTESTOPERATE_H__F7A57A67_85AC_45AB_B9B8_85A23B451301__INCLUDED_)
