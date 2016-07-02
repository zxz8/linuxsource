/*****************************************************************************
   ģ����      : Board Agent
   �ļ���      : dsiconfig.h
   ����ļ�    : 
   �ļ�ʵ�ֹ���: ������ú�������
   ����        : jianghy
   �汾        : V0.9  Copyright(C) 2001-2002 KDC, All rights reserved.
-----------------------------------------------------------------------------
   �޸ļ�¼:
   ��  ��      �汾        �޸���      �޸�����
   2003/08/25  1.0         jianghy       ����
   2004/12/05  3.5         �� ��        �½ӿڵ��޸�
******************************************************************************/
#ifndef DSICONFIG_H
#define DSICONFIG_H

#include "mcuconst.h"
#include "vccommon.h"
#include "mcuagtstruct.h"
#include "eqpcfg.h"

class CDsiConfig
{
public:
	CDsiConfig();
	~CDsiConfig();
    friend class CBoardAgent;
	/*====================================================================
	���ܣ���ȡ����Ĳ�λ��
	��������
	����ֵ��IDֵ��0��ʾʧ��
	====================================================================*/
	u8	GetBoardId();

	/*====================================================================
	���ܣ��õ�����IP��ַ
	��������
	����ֵ������IP��ַ(������)
	====================================================================*/
	u32 GetBrdIpAddr( );

	/*====================================================================
	���ܣ���ȡҪ���ӵ�MCU��IP��ַ(������)
	��������
	����ֵ��MCU��IP��ַ(������)��0��ʾʧ��
	====================================================================*/
	u32 GetConnectMcuIpAddr();

	/*====================================================================
	���ܣ���ȡ���ӵ�MCU�Ķ˿ں�
	��������
	����ֵ��MCU�Ķ˿ںţ�0��ʾʧ��
	====================================================================*/
	u16  GetConnectMcuPort();

	/*====================================================================
	���ܣ��Ƿ�����Prs
	��������
	����ֵ�����з���TRUE����֮FALSE
	====================================================================*/
	BOOL IsRunPrs();

	/*====================================================================
	���ܣ���ȡprs������Ϣ
	��������
	����ֵ��MCU�Ķ˿ںţ�0��ʾʧ��
	====================================================================*/
	BOOL GetPrsCfg( TPrsCfg* ptCfg );

	/*====================================================================
	���ܣ�����PRS��������Ϣ
	��������
	����ֵ��TRUE/FALSE
	====================================================================*/
	BOOL SetPrsConfig( TEqpPrsEntry *ptPrsCfg );
	

	/*====================================================================
	���ܣ����ļ���������Ϣ
	��������
	����ֵ��TRUE/FALSE
	====================================================================*/
	BOOL ReadConnectMcuInfo();

	/*====================================================================
	���ܣ����õ���IP��ַ
	��������
	����ֵ��TRUE/FALSE
	====================================================================*/
	BOOL SetBrdIpAddr( u32 dwIp );

	/*====================================================================
	���ܣ�����ʱ���ļ��ָ�E1��RELAY MODE
	��������
	����ֵ��TRUE/FALSE
	====================================================================*/
	BOOL ResumeE1RelayMode();

	/*====================================================================
	���ܣ���E1��RELAY MODE���浽�ļ�
	��������
	����ֵ��TRUE/FALSE
	====================================================================*/
	BOOL SaveE1RelayMode( u8* byInfo, u16 wInfoLen );

public:
    u32	 m_dwDstMcuNode;
    u32  m_dwDstMcuNodeB;

private:
	BOOL    bIsRunPrs;      //�Ƿ�����PRS
	TPrsCfg m_prsCfg;
	u32	m_dwMpcIpAddr;
	u16 m_wMpcPort;

    u32	m_dwMpcIpAddrB;
	u16 m_wMpcPortB;

	u8	m_byBrdId;
	u32 m_dwBrdIpAddr;	
    u8  m_byChoice;
};

#endif      /* DSICONFIG_H */