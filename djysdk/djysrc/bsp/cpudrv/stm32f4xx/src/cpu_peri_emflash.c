//-----------------------------------------------------------------------------
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

#include <string.h>
#include <stdlib.h>
#include <driver.h>
#include <driver/flash/flash.h>
#include <cpu_peri.h>
#include <int.h>

static struct EmbdFlashDescr{
	u16     BytesPerPage;      		     // ҳ�а������ֽ���
	u16     PagesPerSmallSect;      	 // small sector��ҳ��
	u16 	PagesPerLargeSect;           // large sector��ҳ��
	u16     PagesPerNormalSect;          // Normal sector��ҳ��
	u16     SmallSectorsPerPlane;        // ÿplane��small sector��
	u16     LargeSectorsPerPlane;        // ÿplane��large sector��
	u16     NormalSectorsPerPlane;       // ÿplane��normal sector��
	u16 	Planes;                      // plane��
	u32     MappedStAddr;
} *s_ptEmbdFlash;
extern u32 gc_ptIbootSize;
//-----------------------------------------------------------------------------
//����: ����FLASH��ʼ��
//����:
//����:
//��ע:
//-----------------------------------------------------------------------------
static s32 EmFlash_Init(struct EmbdFlashDescr *Description)
{
	Description->BytesPerPage = 512;
	Description->PagesPerSmallSect = 32;
	Description->PagesPerLargeSect = 128;
	Description->PagesPerNormalSect = 256;
	Description->SmallSectorsPerPlane = 4;
	Description->LargeSectorsPerPlane = 1;
	Description->NormalSectorsPerPlane = 7;
	Description->Planes = 1;
	Description->MappedStAddr = 0x08000000;
	return (0);
}

//-----------------------------------------------------------------------------
//����: ��ȡ����FLASH����Ϣ
//����:
//����:
//��ע:
//-----------------------------------------------------------------------------
static s32 EmFlash_GetDescr(struct EmFlashDescr *Description)
{
	Description->BytesPerPage = s_ptEmbdFlash->BytesPerPage;
	Description->TotalPages = (s_ptEmbdFlash->PagesPerSmallSect *
							   s_ptEmbdFlash->SmallSectorsPerPlane +
							   s_ptEmbdFlash->PagesPerLargeSect *
							   s_ptEmbdFlash->LargeSectorsPerPlane +
							   s_ptEmbdFlash->PagesPerNormalSect *
							   s_ptEmbdFlash->NormalSectorsPerPlane) *
					          s_ptEmbdFlash->Planes;
	Description->ReservedPages = gc_ptIbootSize / s_ptEmbdFlash->BytesPerPage;
	Description->MappedStAddr = s_ptEmbdFlash->MappedStAddr;
	return (0);
}
//-----------------------------------------------------------------------------
//����: ������
//����: BlkNo -- ���;
//����: "0" -- �ɹ�;"-1" -- ʧ��;
//��ע:
//-----------------------------------------------------------------------------
static s32 EmFlash_SectorEarse(u32 SectorNo)
{
	s32 Ret;
	u32 SECTORError=0;//�������������Ϣ
	static FLASH_EraseInitTypeDef EraseInitStruct;

	HAL_FLASH_Unlock();

	EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
	EraseInitStruct.Sector        = SectorNo;
	EraseInitStruct.NbSectors     = 1;

	if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK)
	 	Ret=-1;
	else
		Ret=0;
	HAL_FLASH_Lock();
	return Ret;
}
//-----------------------------------------------------------------------------
//����: дĳҳ
//����: PageNo -- ҳ��;
//      Data -- д����;
//      Flags -- д��������λ;
//����: ">0" -- ������д����ֽ���;
//      "-1" -- ��������;
//      "-2" -- дʧ��;
//��ע:
//-----------------------------------------------------------------------------
static s32 EmFlash_PageProgram(u32 Page, u8 *Data, u32 Flags)
{
	u32 Ret,i;
	u32 *pData = (u32*)Data;

	u32 Addr = Page * s_ptEmbdFlash->BytesPerPage + s_ptEmbdFlash->MappedStAddr;

	if(!Data)
		return (-1);

	HAL_FLASH_Unlock();

	for(i = 0; i < s_ptEmbdFlash->BytesPerPage;)
	{
    	if(*(u32*)Addr != *pData)
    	{
    		Ret = HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,Addr,*pData);
    		if(Ret != HAL_OK)
    			break;
    	}
		pData++;
		i += 4;
		Addr += 4;
	}

	HAL_FLASH_Lock();

	return i;
}
//-----------------------------------------------------------------------------
//����:
//����:
//����:
//��ע:
//-----------------------------------------------------------------------------
static s32 EmFlash_PageRead(u32 Page, u8 *Data, u32 Flags)
{
	u32 Addr = Page * s_ptEmbdFlash->BytesPerPage + s_ptEmbdFlash->MappedStAddr;

	if(!Data)
		return (-1);

	memcpy(Data, (u8*)Addr, s_ptEmbdFlash->BytesPerPage);
	return (s_ptEmbdFlash->BytesPerPage);

}

//-----------------------------------------------------------------------------
//����:
//����:
//����:
//��ע:
//-----------------------------------------------------------------------------
static s32 EmFlash_PageToSector(u32 PageNo, u32 *Remains, u32 *SectorNo)
{

	u32 PagesLeft, PagesDone;
	u32 i;
	u32 Sector;

	if((!Remains) || (!SectorNo))
		return (-1);

	Sector = 0;
	PagesDone = 0;
	PagesLeft = s_ptEmbdFlash->PagesPerSmallSect -
			   (PageNo % s_ptEmbdFlash->PagesPerSmallSect);
	for(i = 1; i <= s_ptEmbdFlash->SmallSectorsPerPlane; i++)
	{
		if(PageNo < (PagesDone + s_ptEmbdFlash->PagesPerSmallSect * i))
			goto DONE;
		Sector++;
	}

	PagesDone += s_ptEmbdFlash->SmallSectorsPerPlane *
				 s_ptEmbdFlash->PagesPerSmallSect;
	PagesLeft = s_ptEmbdFlash->PagesPerLargeSect -
				   (PageNo % s_ptEmbdFlash->PagesPerLargeSect);
	for(i = 1; i <= s_ptEmbdFlash->LargeSectorsPerPlane; i++)
	{
		if(PageNo < (PagesDone + s_ptEmbdFlash->PagesPerLargeSect * i))
			goto DONE;
		Sector++;
	}

	PagesDone += s_ptEmbdFlash->LargeSectorsPerPlane *
					 s_ptEmbdFlash->PagesPerLargeSect;
	PagesLeft = s_ptEmbdFlash->PagesPerNormalSect -
				   (PageNo % s_ptEmbdFlash->PagesPerNormalSect);
	for(i = 1; i <= s_ptEmbdFlash->NormalSectorsPerPlane; i++)
	{
		if(PageNo < (PagesDone + s_ptEmbdFlash->PagesPerNormalSect * i))
			goto DONE;
		Sector++;
	}

	return (-1);

DONE:
	*SectorNo = Sector; // ��sector���
	*Remains = PagesLeft; //
	return (0);
}

//-----------------------------------------------------------------------------
//����:
//����:
//����:
//��ע:
//-----------------------------------------------------------------------------
s32 ModuleInstall_EmbededFlash(const char *ChipName, u32 Flags, u16 ResPages)
{
	u32 Len;
    struct FlashChip *Chip;
    struct EmFlashDescr FlashDescr;
	struct MutexLCB *EmFlashLock;
	u8 *Buf;
	s32 Ret = 0;

	if (!ChipName)
		return (-1);

	if(s_ptEmbdFlash)
		return (-4); // �豸��ע��

	s_ptEmbdFlash = malloc(sizeof(*s_ptEmbdFlash));
	if(!s_ptEmbdFlash)
		return (-1);

	EmFlash_Init(s_ptEmbdFlash);

    EmFlash_GetDescr(&FlashDescr);// ��ȡFLASH��Ϣ
   	if(ResPages > FlashDescr.TotalPages)
   	{
   		Ret = -1;
   		goto FAILURE;
   	}

   	FlashDescr.ReservedPages += ResPages;
    Len = strlen (ChipName) + 1;
    Chip = (struct FlashChip*)malloc(sizeof(struct FlashChip) + Len);
	if (NULL == Chip)
	{
		TraceDrv(FLASH_TRACE_ERROR, "out of memory!\r\n");
		Ret = -2;
		goto FAILURE;
	}

	memset(Chip, 0x00, sizeof(*Chip));
	Chip->Type                    = F_ALIEN;
	Chip->Descr.Embd              = FlashDescr;
	Chip->Ops.ErsBlk              = EmFlash_SectorEarse;
	Chip->Ops.WrPage              = EmFlash_PageProgram;
	Chip->Ops.RdPage              = EmFlash_PageRead;
	Chip->Ops.PageToBlk			  = EmFlash_PageToSector;
	Chip->Ops.PageToBlk			  = EmFlash_PageToSector;
	strcpy(Chip->Name, ChipName); // �豸��
	if(Flags & FLASH_BUFFERED)
	{
		Buf = (u8*)malloc(s_ptEmbdFlash->BytesPerPage); // NAND�ײ㻺��
		if(!Buf)
		{
			TraceDrv(FLASH_TRACE_ERROR, "out of memory!\r\n");
			Ret = -2;
			goto FAILURE;
		}

		EmFlashLock = Lock_MutexCreate("Embedded Flash Lock");
		if(!EmFlashLock)
		{
			Ret = -3;
			goto FAILURE;
		}

		Chip->Buf = Buf;
		Chip->Lock =(void*)EmFlashLock;
	}

    Driver_DeviceCreate(NULL, Chip->Name, NULL, NULL, NULL, NULL, NULL, NULL, (ptu32_t)Chip); // �豸����"/dev"
    if(Flags & FLASH_ERASE_ALL)
		EarseWholeChip(Chip);

FAILURE:
	if(Ret)
	{
		if(s_ptEmbdFlash)
			free(s_ptEmbdFlash);
		if(EmFlashLock)
			Lock_MutexDelete(EmFlashLock);
		if(Buf)
			free(Buf);
		if(Chip)
			free(Chip);
	}
	return (Ret);
}