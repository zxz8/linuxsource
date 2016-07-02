/***************************************************************
模块名      ： voutdrv                      
文件名      ： voutdrv.h
相关文件    ： voutdrv.c
文件实现功能： 用户态接口
作者        ： 邵笑杰
版本        ： 1.0   2005/09/6
------------------------------------------------------------------
修改记录:
日  期          版本            修改人          修改内容

*****************************************************************/

#include "vout.h"

/*====================================================================
函数名      ：VoutDrvOpen
功能        ：打开设备
算法实现    ：（可选项）
引用全局变量：无
输入参数说明：pchName设备名，ptHandle vout层设备信息结构
返回值说明  ：Vout错误信息
====================================================================*/
TVoutError VoutDrvOpen(s8 *pchName, TVout **ptHanle);

/*====================================================================
函数名      ：VoutDrvClose
功能        ：关闭设备
算法实现    ：（可选项）
引用全局变量：无
输入参数说明：ptHandle 设备信息
返回值说明  ：Vout错误信息
====================================================================*/
TVoutError VoutDrvClose(TVout *ptHandle);

/*====================================================================
函数名      ：VoutDrvGetSetup
功能        ：得到设置信息
算法实现    ：（可选项）
引用全局变量：无
输入参数说明：ptHandle 设备信息，ptSetup 得到设备信息结构
返回值说明  ：Vout错误信息
====================================================================*/
TVoutError VoutDrvGetSetup(TVout *ptHandle, TVoutSetup *ptSetup);

/*====================================================================
函数名      ：VoutDrvSetup
功能        ：设置信息
算法实现    ：（可选项）
引用全局变量：无
输入参数说明：ptHandle 设备信息，ptSetup 设置设备信息结构
返回值说明  ：Vout错误信息
====================================================================*/	
TVoutError VoutDrvSetup(TVout *ptHandle, TVoutSetup *ptSetup);

/*====================================================================
函数名      ：VoutDrvStart
功能        ：启动设备
算法实现    ：（可选项）
引用全局变量：无
输入参数说明：ptHandle 设备信息
返回值说明  ：Vout错误信息
====================================================================*/
TVoutError VoutDrvStart(TVout *ptHandle);

/*====================================================================
函数名      ：VoutDrvStop
功能        ：停止设备
算法实现    ：（可选项）
引用全局变量：无
输入参数说明：ptHandle 设备信息
返回值说明  ：Vout错误信息
====================================================================*/
TVoutError VoutDrvStop(TVout *ptHandle);
