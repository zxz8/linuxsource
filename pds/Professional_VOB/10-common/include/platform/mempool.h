/***************************************************************
模块名	    ：MManage                       
文件名	    ：mempool.h
相关文件    ：mempool.c
文件实现功能：
作者	    ：付江涛
版本	    ：1.0  2005/04/30
-----------------------------------------------------------------
修改记录:
日  期		版本		修改人		修改内容
2005/05/25      1.0             付江涛          创建
*****************************************************************/
#ifndef  MEMPOOL_H_
#define  MEMPOOL_H_

/*#include "algorithmtype.h"*/
typedef unsigned long int u32Mem;
typedef unsigned char     u8Mem;
typedef char              s8Mem; 
#define  MMANAGE_OK                 0
#define  MMANAGE_ERROR              1

/***************************************************************
函数名      ：MempoolInit
功能        ：初始化
算法实现    ：（可选项）
引用全局变量：g_MempoolInitFlag
输入参数说明：无
返回值说明  : MMANAGE_OK 表明初始化成功；MMANAGE_ERROR 表示初始化失败
**************************************************************/
u32Mem  MempoolInit();


/***************************************************************
函数名      ：MempoolMalloc
功能        ：分配内存
算法实现    ：（可选项）
引用全局变量：g_MempoolInitFlag
输入参数说明：size要分配的内存大小
返回值说明  ：分配的内存指针
**************************************************************/
void * MempoolMalloc(u32Mem u32AllocSize);

/***************************************************************
函数名	    ：MempoolAlign
功能	    ：实现要求指针对齐的内存分配
算法实现    ：（可选项）
引用全局变量：无
输入参数说明：AlignBit对齐位， AllocSize内存块尺寸
返回值说明  ：内存指针
**************************************************************/
void   * MempoolAlign( u32Mem u32AlignBit , u32Mem u32AllocSize);


/***************************************************************
函数名	    ：MempoolFree
功能	    ：释放内存单元
算法实现    ：（可选项）
引用全局变量：无
输入参数说明：freePt释放内存指针
返回值说明  ：MMANAGE_OK 表示成功；MMANAGE_ERROR 表示失败
**************************************************************/
u32Mem   MempoolFree(void   *pFreePt);



/***************************************************************
函数名      ：MempoolClose
功能	    ：释放内存资源
算法实现    ：（可选项）
引用全局变量：g_MempoolInitFlag
输入参数说明：无
返回值说明  ：MMANAGE_OK 表示成功；MMANAGE_ERROR表示失败
**************************************************************/
u32Mem   MempoolClose();

/***************************************************************
函数名      ：MempoolShow
功能        ：显示内存管理中的内存使用详细情况
算法实现    ：（可选项）
引用全局变量：
输入参数说明：无
返回值说明  ：
**************************************************************/
void MempoolShow();

#endif
