//----------------------------------------------------
// Copyright (c) 2014, SHENZHEN PENGRUI SOFT CO LTD. All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:

// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//-----------------------------------------------------------------------------
// Copyright (c) 2014 ����Ȩ�����������������޹�˾���С�����Ȩ�˱���һ��Ȩ����
//
// �����Ȩ�����ʹ���߷������������������£�����ʹ����ʹ�ü���ɢ����
// ������װԭʼ�뼰����λ��ִ����ʽ��Ȩ�������۴˰�װ�Ƿ񾭸�����Ȼ��
//
// 1. ���ڱ�����Դ�������ɢ�������뱣�������İ�Ȩ���桢�������б�����
//    ������������������
// 2. ���ڱ��׼�����λ��ִ����ʽ����ɢ���������������ļ��Լ�������������
//    ��ɢ����װ�е�ý�鷽ʽ����������֮��Ȩ���桢�������б����Լ�����
//    ������������

// �����������������Ǳ�������Ȩ�������Լ�����������״��"as is"���ṩ��
// ��������װ�����κ���ʾ��Ĭʾ֮�������Σ������������ھ��������Լ��ض�Ŀ
// �ĵ�������ΪĬʾ�Ե�������Ȩ�����˼�������֮�����ߣ������κ�������
// ���۳�����κ��������塢���۴�����Ϊ���Լ��ϵ���޹�ʧ������������Υ
// Լ֮��Ȩ��������ʧ������ԭ��ȣ����𣬶����κ���ʹ�ñ�������װ��������
// �κ�ֱ���ԡ�����ԡ�ż���ԡ������ԡ��ͷ��Ի��κν�����𺦣�����������
// �������Ʒ������֮���á�ʹ����ʧ��������ʧ��������ʧ��ҵ���жϵȵȣ���
// �����κ����Σ����ڸ���ʹ���ѻ���ǰ��֪���ܻ���ɴ����𺦵���������Ȼ��
//-----------------------------------------------------------------------------
//����ģ��:  CPU��ʼ��
//���ߣ�     lst
//�汾��     V1.0.0
//��ʼ�汾������ڣ�2014-1-20
//�ļ�����:  cpuʱ�ӳ�ʼ��
//����˵��:  ��
//�޶���ʷ:
//2. ...
//1. ����: 2014-1-20
//   ����: lst
//   �°汾�ţ�V1.0.0
//   �޸�˵��: ԭʼ�汾
//------------------------------------------------------
#include "os.h"
#include "cpu_peri.h"

#define MASK_STATUS0 0xFFFFFFFC
#define MASK_STATUS1 0xFFFFFFFF


//------ʹ������ʱ��-----------------------------------------------------------
//����: ����ʱ�ӿɵ���ʹ�ܺͳ��ܣ��Խ�Լ�ܺ�
//����: dwId������ID������ID�ɲο��ֲ�39ҳ
//����: ��
//-----------------------------------------------------------------------------
void PMC_EnablePeripheral( uint32_t dwId )
{
    if(dwId >= 46)
    	return;

    PMC_WriteProtectEnable();

    if ( dwId < 32 )
    {
        if ( (PMC->PMC_PCSR0 & ((uint32_t)1 << dwId)) == ((uint32_t)1 << dwId) )
        {
//            djy_printf( "PMC_EnablePeripheral: clock of peripheral"  "
//                        %u is already enabled\n\r", (unsigned int)dwId ) ;
        }
        else
        {
            PMC->PMC_PCER0 = 1 << dwId ;
        }
    }
    else
    {
        dwId -= 32;
        if ((PMC->PMC_PCSR1 & ((uint32_t)1 << dwId)) == ((uint32_t)1 << dwId))
        {
//            djy_printf( "PMC_EnablePeripheral: clock of peripheral"  "
//                    %u is already enabled\n\r", (unsigned int)(dwId + 32) ) ;
        }
        else
        {
            PMC->PMC_PCER1 = 1 << dwId ;
        }
    }
    PMC_WriteProtectDisable();
}

//------��������ʱ��-----------------------------------------------------------
//����: ����ʱ�ӿɵ���ʹ�ܺͳ��ܣ��Խ�Լ�ܺ�
//����: dwId������ID������ID�ɲο��ֲ�39ҳ
//����: ��
//-----------------------------------------------------------------------------
void PMC_DisablePeripheral( uint32_t dwId )
{
    if(dwId >= 46)
    	return;

    PMC_WriteProtectEnable();

    if ( dwId < 32 )
    {
        if ( (PMC->PMC_PCSR0 & ((uint32_t)1 << dwId)) != ((uint32_t)1 << dwId) )
        {
//            djy_printf("PMC_DisablePeripheral: clock of peripheral" "
//                            %u is not enabled\n\r", (unsigned int)dwId ) ;
        }
        else
        {
            PMC->PMC_PCDR0 = 1 << dwId ;
        }
    }
    else
    {
        dwId -= 32 ;
        if ( (PMC->PMC_PCSR1 & ((uint32_t)1 << dwId)) != ((uint32_t)1 << dwId) )
        {
//            djy_printf( "PMC_DisablePeripheral: clock of peripheral" "
//                        %u is not enabled\n\r", (unsigned int)(dwId + 32) ) ;
        }
        else
        {
            PMC->PMC_PCDR1 = 1 << dwId ;
        }
    }
    PMC_WriteProtectDisable();
}

//------ʹ����������ʱ��-------------------------------------------------------
//����: ����ʱ�ӿɵ���ʹ�ܺͳ��ܣ��Խ�Լ�ܺ�
//����: dwId������ID������ID�ɲο��ֲ�39ҳ
//����: ��
//-----------------------------------------------------------------------------
void PMC_EnableAllPeripherals( void )
{
	PMC_WriteProtectEnable();

    PMC->PMC_PCER0 = MASK_STATUS0 ;
    while ( (PMC->PMC_PCSR0 & MASK_STATUS0) != MASK_STATUS0 ) ;

    PMC->PMC_PCER1 = MASK_STATUS1 ;
    while ( (PMC->PMC_PCSR1 & MASK_STATUS1) != MASK_STATUS1 ) ;

    PMC_WriteProtectDisable();
}

//------ʹ������ʱ��-----------------------------------------------------------
//����: ����ʱ�ӿɵ���ʹ�ܺͳ��ܣ��Խ�Լ�ܺ�
//����: dwId������ID������ID�ɲο��ֲ�39ҳ
//����: ��
//-----------------------------------------------------------------------------
void PMC_DisableAllPeripherals( void )
{
	PMC_WriteProtectEnable();
    PMC->PMC_PCDR0 = MASK_STATUS0 ;
    while ( (PMC->PMC_PCSR0 & MASK_STATUS0) != 0 ) ;

    PMC->PMC_PCDR1 = MASK_STATUS1 ;
    while ( (PMC->PMC_PCSR1 & MASK_STATUS1) != 0 ) ;

    PMC_WriteProtectDisable();
}

//------�ж�����ʱ���Ƿ�ʹ��---------------------------------------------------
//����: �ж�ָ��������ID�ŵ�����ʱ���Ƿ�ʹ��
//����: dwId������ID������ID�ɲο��ֲ�39ҳ
//����: 0,����   1,ʹ��
//-----------------------------------------------------------------------------
uint32_t PMC_IsPeriphEnabled( uint32_t dwId )
{
    if(dwId >= 46)
    	return 0xFF;

    if ( dwId < 32 )
    {
        return ( PMC->PMC_PCSR0 & (1 << dwId) ) ;
    }
    else {
        return ( PMC->PMC_PCSR1 & (1 << (dwId - 32)) ) ;
    }
}

void PMC_WriteProtectEnable(void)
{
	PMC->PMC_WPMR = 0x504D4300;
}

void PMC_WriteProtectDisable(void)
{
	PMC->PMC_WPMR = 0x504D4301;
}
