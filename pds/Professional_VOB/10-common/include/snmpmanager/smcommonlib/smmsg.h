/*=============================================================================
模   块   名: 网管服务器
文   件   名: nmsmsg.h
相 关  文 件: 无
文件实现功能: 消息类
作        者: 陆昆朋
版        本: V4.0  Copyright(C) 2003-2005 KDC, All rights reserved.
-------------------------------------------------------------------------------
修改记录:
日      期  版本    修改人      修改内容
=============================================================================*/

#ifndef SM_SMMSG_H
#define SM_SMMSG_H

#include "kdvtype.h"
#include "smmacro.h"

extern u32 g_dwSerialNo;    // 流水号

//子事件编号
#define SM_SUBEV_TYPE_INVALID                  0       // 无效值
#define SM_SUBEV_TYPE_REQ                      1       // 请求类
#define SM_SUBEV_TYPE_ACK                      2       // 确认类
#define SM_SUBEV_TYPE_NACK                     3       // 拒绝类
#define SM_SUBEV_TYPE_NOTIFY                   4       // 通知类
#define SM_SUBEV_TYPE_FINISH                   5       // 批次消息完成确认类

//消息类型
#define SM_MSG_GET                         0       //查询消息
#define SM_MSG_SET                         1       //设置消息
#define SM_MSG_NTF                         2       //通知消息

typedef struct tagSmMsgHead
{
    u32	m_dwSerialNo;	// 流水号, 网络序
    u16	m_wEventID;		// 事件编号, 网络序
    u16	m_wObjectType;	// 对象类型, 网络序
    u32	m_dwObjectID;	// 对象编号, 网络序
    u32	m_dwCbdID;		// 对应的Cbd 任务ID, 网络序
	u8 m_bySubEvent;	// 子事件编号,网络序
	u8 m_byMsgType;		// 消息类型,网络序
    u16	m_wErrorCode;	// 错误码, 网络序
    u16	m_wTimeout;		// 定时时间长度--单位为秒, 网络序
    u16	m_wMsgLength;	// 消息内容长度, 网络序
} TSmMsgHead;

#define MSG_BODY_OFFSET     sizeof(TSmMsgHead) // 消息头为28个子节

//此值可以根据需要定义 (>MSG_BODY_OFFSET)
const s32 SM_SMMSG_LENGTH = 0x7000;

//此值表示从snmpmanager发送给插件时消息体最大不能超过的值极限
//TNM_MSG_LEN = 0x7000
//TNM_MSGHEAD_LEN = 0x20
const u16 SM_MSG_TNM_LENGTH = 0x7000 - 0x20 - MSG_BODY_OFFSET;


//////////////////////////////////////////////////////////
//snmpmanager模块消息类
//请注意,收到消息后的osp消息体，不能直接强转换为CSmMsg指针
//请采用以下方法
//CSmMsg cSmMsg(pcMsg->content, pcMsg->length);
//切记
//此消息传输全部采用只传输m_byContent,而不是类起始指针
//////////////////////////////////////////////////////////

class CSmMsg
{
private:
    u8 m_byContent[SM_SMMSG_LENGTH];	// 消息缓冲区，2k大小

public:
	CSmMsg();

    CSmMsg(const void* pbyMsg, u16 wMsgLen);

    CSmMsg& operator= (const CSmMsg &cMsg);

	//在进行网络传输中，如果传输的是类起始指针，尽量不要用虚函数
	//如果非要用虚函数，并且传类起始指针，传输长度必须用sizeof(CSmMsg),不能用cSmMsg.GetMsgLen().
	virtual ~CSmMsg();

	CSmMsg(const CSmMsg &cMsg);

public:

    /*=============================================================================
    函 数 名:ClearMsgHead
    功    能:清除消息头部
    参    数:无
    注    意:无
    返 回 值:无
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
    void ClearMsgHead(void);

    /*=============================================================================
    函 数 名:ClearMsgBody
    功    能:清除消息内容
    参    数:无
    注    意:无
    返 回 值:无
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
    void ClearMsgBody(void);

    /*=============================================================================
    函 数 名:ClearContent
    功    能:清除消息全部内容
    参    数:无
    注    意:无
    返 回 值:无
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
    void ClearContent(void);

    /*=============================================================================
    函 数 名:GetSerialNo
    功    能:获取流水号
    参    数:无
    注    意:无
    返 回 值:流水号
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
    u32 GetSerialNo(void) const;
    /*=============================================================================
    函 数 名:SetSerialNo
    功    能:设置当前消息的流水号
    参    数:u32 dwSerialNo                 [in]    当前的流水号
    注    意:该方法一般不使用
    返 回 值:无
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	void SetSerialNo(u32 dwSerialNo);

    /*=============================================================================
    函 数 名:SetSerialNo
    功    能:设置消息的流水号
    参    数:无
    注    意:无
    返 回 值:无
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	void SetSerialNo(void);

    /*=============================================================================
    函 数 名:GetObjectID
    功    能:获取对象编号
    参    数:无
    注    意:无
    返 回 值:对象编号
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	u32 GetObjectID(void) const;

    /*=============================================================================
    函 数 名:GetTargetID
    功    能:获取目的对象编号
    参    数:无
    注    意:该函数仅仅用于用户组关系变更的事件，
             如果对象是用户，则目的对象就是组
             否则，目的对象就是用户
    返 回 值:对象编号
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	void SetCbdID(u32 dwCbdID);
	u32 GetCbdID(void) const;

    /*=============================================================================
    函 数 名:SetObject
    功    能:设置目的对象
    参    数:u32 dwObjectID                 [in]    本次消息的对象编号
             u16 wObjectType                [in]    本次消息的对象类型
             u32 dwTargetID                 [in]    本次消息的对象关联的对象编号
    注    意:无
    返 回 值:无
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	void SetObject(u32 dwObjectID, u32 dwCbdID = -1);

    /*=============================================================================
    函 数 名:SetErrorCode
    功    能:设置错误码
    参    数:u32 dwErrorCode                [in]    本次消息的错误码
    注    意:无
    返 回 值:无
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	void SetErrorCode(u16 dwErrorCode);

    /*=============================================================================
    函 数 名:GetErrorCode
    功    能:获取本次消息的错误码
    参    数:无
    注    意:无
    返 回 值:错误码
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	u16 GetErrorCode(void) const;

    /*=============================================================================
    函 数 名:SetEventId
    功    能:设置事件编号
    参    数:u16 wEventId                   [in]    本次消息的事件
    注    意:无
    返 回 值:无
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	void SetEventId(u16 wEventId);

	void SetSubEvent(u8 wSubEvent);

	void SetMsgType(u8 wMsgType);

    /*=============================================================================
    函 数 名:GetEventId
    功    能:获取事件
    参    数:无
    注    意:无
    返 回 值:事件号
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	u16 GetEventId(void) const;

	u8 GetSubEvent(void) const;

	u8 GetMsgType(void) const;

    /*=============================================================================
    函 数 名:SetMsgBody
    功    能:设置消息的内容
    参    数:void* pbyMsgBody              [in]    本次消息的内容
             u16 wBodyLen                   [in]    本次消息的内容长度
    注    意:无
    返 回 值:无
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	void SetMsgBody(const void* pbyMsgBody, u16 wBodyLen);

    /*=============================================================================
    函 数 名:CatMsgBody
    功    能:添加消息内容
    参    数:void* pbyMsgBody              [in]    本次消息的内容
             u16 wBodyLen                   [in]    本次消息的内容长度
    注    意:无
    返 回 值:无
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	void CatMsgBody(const void* pbyMsgBody, u16 wBodyLen);

    /*=============================================================================
    函 数 名:GetMsgBody
    功    能:获取消息内容
    参    数:void* pbyMsgBody              [out]   获取得到的消息内容
             u16 wBodyLen                   [in]    消息的长度
             u16 wOffset                    [in]    消息的偏移
    注    意:无
    返 回 值:无
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	u16 GetMsgBody(void* pbyMsgBody, u16 wBodyLen, u16 wOffset = 0);

    /*=============================================================================
    函 数 名:GetMsgBody
    功    能:获取消息内容
    参    数:u16 wOffset                    [in]    消息的偏移
    注    意:直接返回消息内容指针
    返 回 值:消息内容
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	void* GetMsgBody(u16 wOffset = 0) const;

	void* GetMsg() const;

    /*=============================================================================
    函 数 名:GetMsgBodyLen
    功    能:获取消息体的长度
    参    数:无
    注    意:无
    返 回 值:消息体的长度
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	u16 GetMsgBodyLen(void) const;


	u16 GetMsgLen(void) const;

    /*=============================================================================
    函 数 名:SetTimeout
    功    能:设置定时时间
    参    数:u16 wTimeout                   [in]    定时的时间长度
    注    意:无
    返 回 值:无
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	void SetTimeout(u16 wTimeout);

    /*=============================================================================
    函 数 名:GetTimeout
    功    能:获取定时长度
    参    数:无
    注    意:无
    返 回 值:定时长度
    -------------------------------------------------------------------------------
    修改纪录:
    日      期  版本    修改人  修改内容
    2003/10/23  2.0     wjr     创建
    =============================================================================*/
	u16 GetTimeout(void) const;
};

#endif // SM_SMMSG_H
