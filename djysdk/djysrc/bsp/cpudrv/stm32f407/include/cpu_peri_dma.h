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
//����ģ��:���豸����ģ��
//���ߣ�lst
//�汾��V1.0.0
//�ļ�����:stm32 cpu��dma�Ĵ�������
//����˵��:
//�޶���ʷ:
//2. ...
//1. ����: 2009-09-10
//   ����: lst
//   �°汾��: V1.0.0
//   �޸�˵��: ԭʼ�汾
//------------------------------------------------------
#ifndef __CPU_PERI_DMA_H__
#define __CPU_PERI_DMA_H__

#ifdef __cplusplus
extern "C" {
#endif

//dmaλ���壬bo_Ϊλƫ�ƣ�1λ����λ����ַ��bb_ǰ׺����λ�����룬bm_ǰ׺
#define bb_dma1_ch1_ccr_base   (0x42000000 + 0x20008*32)            //λ����ַ
#define bb_dma1_ch1_ccr_en     (*(vu32*)(bb_dma1_ch1_ccr_base+4*0))
#define bb_dma1_ch1_ccr_tcie   (*(vu32*)(bb_dma1_ch1_ccr_base+4*1))
#define bb_dma1_ch1_ccr_htie   (*(vu32*)(bb_dma1_ch1_ccr_base+4*2))
#define bb_dma1_ch1_ccr_teie   (*(vu32*)(bb_dma1_ch1_ccr_base+4*3))
#define bb_dma1_ch1_ccr_dir    (*(vu32*)(bb_dma1_ch1_ccr_base+4*4))
#define bb_dma1_ch1_ccr_circ   (*(vu32*)(bb_dma1_ch1_ccr_base+4*5))
#define bb_dma1_ch1_ccr_pinc   (*(vu32*)(bb_dma1_ch1_ccr_base+4*6))
#define bb_dma1_ch1_ccr_minc   (*(vu32*)(bb_dma1_ch1_ccr_base+4*7))
#define bb_dma1_ch1_ccr_m2m    (*(vu32*)(bb_dma1_ch1_ccr_base+4*14))
#define bm_dma1_ch1_ccr_psize  0x00000300
#define bm_dma1_ch1_ccr_msize  0x00000c00
#define bm_dma1_ch1_ccr_pl     0x00003000
#define bo_dma1_ch1_ccr_en     0    //1=ͨ������
#define bo_dma1_ch1_ccr_tcie   1    //1=������������ж�
#define bo_dma1_ch1_ccr_htie   2    //1=�����봫���ж�
#define bo_dma1_ch1_ccr_teie   3    //1=������������ж�
#define bo_dma1_ch1_ccr_dir    4    //0=���������1=�Ӵ洢����
#define bo_dma1_ch1_ccr_circ   5    //0=ִ��ѭ��������1��֮
#define bo_dma1_ch1_ccr_pinc   6    //0=�����ַ��������1��֮
#define bo_dma1_ch1_ccr_minc   7    //0=�洢����ַ��������1��֮
#define bo_dma1_ch1_ccr_m2m    14   //0=�Ǵ洢�����洢��ģʽ��1=���ô洢�����洢��ģʽ
#define bo_dma1_ch1_ccr_psize  8    //�������ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch1_ccr_msize  10   //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch1_ccr_pl     12   //ͨ�����ȼ���00��ͣ�11���

#define bb_dma1_ch2_ccr_base   (0x42000000 + 0x2001c*32)            //λ����ַ
#define bb_dma1_ch2_ccr_en     (*(vu32*)(bb_dma1_ch2_ccr_base+4*0))
#define bb_dma1_ch2_ccr_tcie   (*(vu32*)(bb_dma1_ch2_ccr_base+4*1))
#define bb_dma1_ch2_ccr_htie   (*(vu32*)(bb_dma1_ch2_ccr_base+4*2))
#define bb_dma1_ch2_ccr_teie   (*(vu32*)(bb_dma1_ch2_ccr_base+4*3))
#define bb_dma1_ch2_ccr_dir    (*(vu32*)(bb_dma1_ch2_ccr_base+4*4))
#define bb_dma1_ch2_ccr_circ   (*(vu32*)(bb_dma1_ch2_ccr_base+4*5))
#define bb_dma1_ch2_ccr_pinc   (*(vu32*)(bb_dma1_ch2_ccr_base+4*6))
#define bb_dma1_ch2_ccr_minc   (*(vu32*)(bb_dma1_ch2_ccr_base+4*7))
#define bb_dma1_ch2_ccr_m2m    (*(vu32*)(bb_dma1_ch2_ccr_base+4*14))
#define bm_dma1_ch2_ccr_psize  0x00000300
#define bm_dma1_ch2_ccr_msize  0x00000c00
#define bm_dma1_ch2_ccr_pl     0x00003000
#define bo_dma1_ch2_ccr_en     0    //1=ͨ������
#define bo_dma1_ch2_ccr_tcie   1    //1=������������ж�
#define bo_dma1_ch2_ccr_htie   2    //1=�����봫���ж�
#define bo_dma1_ch2_ccr_teie   3    //1=������������ж�
#define bo_dma1_ch2_ccr_dir    4    //0=���������1=�Ӵ洢����
#define bo_dma1_ch2_ccr_circ   5    //0=ִ��ѭ��������1��֮
#define bo_dma1_ch2_ccr_pinc   6    //0=�����ַ��������1��֮
#define bo_dma1_ch2_ccr_minc   7    //0=�洢����ַ��������1��֮
#define bo_dma1_ch2_ccr_m2m    14   //0=�Ǵ洢�����洢��ģʽ��1=���ô洢�����洢��ģʽ
#define bo_dma1_ch2_ccr_psize  8    //�������ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch2_ccr_msize  10   //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch2_ccr_pl     12   //ͨ�����ȼ���00��ͣ�11���

#define bb_dma1_ch3_ccr_base   (0x42000000 + 0x20030*32)            //λ����ַ
#define bb_dma1_ch3_ccr_en     (*(vu32*)(bb_dma1_ch3_ccr_base+4*0))
#define bb_dma1_ch3_ccr_tcie   (*(vu32*)(bb_dma1_ch3_ccr_base+4*1))
#define bb_dma1_ch3_ccr_htie   (*(vu32*)(bb_dma1_ch3_ccr_base+4*2))
#define bb_dma1_ch3_ccr_teie   (*(vu32*)(bb_dma1_ch3_ccr_base+4*3))
#define bb_dma1_ch3_ccr_dir    (*(vu32*)(bb_dma1_ch3_ccr_base+4*4))
#define bb_dma1_ch3_ccr_circ   (*(vu32*)(bb_dma1_ch3_ccr_base+4*5))
#define bb_dma1_ch3_ccr_pinc   (*(vu32*)(bb_dma1_ch3_ccr_base+4*6))
#define bb_dma1_ch3_ccr_minc   (*(vu32*)(bb_dma1_ch3_ccr_base+4*7))
#define bb_dma1_ch3_ccr_m2m    (*(vu32*)(bb_dma1_ch3_ccr_base+4*14))
#define bm_dma1_ch3_ccr_psize  0x00000300  //�������ݿ��ȣ�00=8��01=16��10=32
#define bm_dma1_ch3_ccr_msize  0x00000c00  //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bm_dma1_ch3_ccr_pl     0x00003000  //ͨ�����ȼ���00��ͣ�11���
#define bo_dma1_ch3_ccr_en     0    //1=ͨ������
#define bo_dma1_ch3_ccr_tcie   1    //1=������������ж�
#define bo_dma1_ch3_ccr_htie   2    //1=�����봫���ж�
#define bo_dma1_ch3_ccr_teie   3    //1=������������ж�
#define bo_dma1_ch3_ccr_dir    4    //0=���������1=�Ӵ洢����
#define bo_dma1_ch3_ccr_circ   5    //0=ִ��ѭ��������1��֮
#define bo_dma1_ch3_ccr_pinc   6    //0=�����ַ��������1��֮
#define bo_dma1_ch3_ccr_minc   7    //0=�洢����ַ��������1��֮
#define bo_dma1_ch3_ccr_m2m    14   //0=�Ǵ洢�����洢��ģʽ��1=���ô洢�����洢��ģʽ
#define bo_dma1_ch3_ccr_psize  8    //�������ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch3_ccr_msize  10   //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch3_ccr_pl     12   //ͨ�����ȼ���00��ͣ�11���

#define bb_dma1_ch4_ccr_base   (0x42000000 + 0x20044*32)            //λ����ַ
#define bb_dma1_ch4_ccr_en     (*(vu32*)(bb_dma1_ch4_ccr_base+4*0))
#define bb_dma1_ch4_ccr_tcie   (*(vu32*)(bb_dma1_ch4_ccr_base+4*1))
#define bb_dma1_ch4_ccr_htie   (*(vu32*)(bb_dma1_ch4_ccr_base+4*2))
#define bb_dma1_ch4_ccr_teie   (*(vu32*)(bb_dma1_ch4_ccr_base+4*3))
#define bb_dma1_ch4_ccr_dir    (*(vu32*)(bb_dma1_ch4_ccr_base+4*4))
#define bb_dma1_ch4_ccr_circ   (*(vu32*)(bb_dma1_ch4_ccr_base+4*5))
#define bb_dma1_ch4_ccr_pinc   (*(vu32*)(bb_dma1_ch4_ccr_base+4*6))
#define bb_dma1_ch4_ccr_minc   (*(vu32*)(bb_dma1_ch4_ccr_base+4*7))
#define bb_dma1_ch4_ccr_m2m    (*(vu32*)(bb_dma1_ch4_ccr_base+4*14))
#define bm_dma1_ch4_ccr_psize  0x00000300  //�������ݿ��ȣ�00=8��01=16��10=32
#define bm_dma1_ch4_ccr_msize  0x00000c00  //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bm_dma1_ch4_ccr_pl     0x00003000  //ͨ�����ȼ���00��ͣ�11���
#define bo_dma1_ch4_ccr_en     0    //1=ͨ������
#define bo_dma1_ch4_ccr_tcie   1    //1=������������ж�
#define bo_dma1_ch4_ccr_htie   2    //1=�����봫���ж�
#define bo_dma1_ch4_ccr_teie   3    //1=������������ж�
#define bo_dma1_ch4_ccr_dir    4    //0=���������1=�Ӵ洢����
#define bo_dma1_ch4_ccr_circ   5    //0=ִ��ѭ��������1��֮
#define bo_dma1_ch4_ccr_pinc   6    //0=�����ַ��������1��֮
#define bo_dma1_ch4_ccr_minc   7    //0=�洢����ַ��������1��֮
#define bo_dma1_ch4_ccr_m2m    14   //0=�Ǵ洢�����洢��ģʽ��1=���ô洢�����洢��ģʽ
#define bo_dma1_ch4_ccr_psize  8    //�������ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch4_ccr_msize  10   //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch4_ccr_pl     12   //ͨ�����ȼ���00��ͣ�11���

#define bb_dma1_ch5_ccr_base   (0x42000000 + 0x20058*32)            //λ����ַ
#define bb_dma1_ch5_ccr_en     (*(vu32*)(bb_dma1_ch5_ccr_base+4*0))
#define bb_dma1_ch5_ccr_tcie   (*(vu32*)(bb_dma1_ch5_ccr_base+4*1))
#define bb_dma1_ch5_ccr_htie   (*(vu32*)(bb_dma1_ch5_ccr_base+4*2))
#define bb_dma1_ch5_ccr_teie   (*(vu32*)(bb_dma1_ch5_ccr_base+4*3))
#define bb_dma1_ch5_ccr_dir    (*(vu32*)(bb_dma1_ch5_ccr_base+4*4))
#define bb_dma1_ch5_ccr_circ   (*(vu32*)(bb_dma1_ch5_ccr_base+4*5))
#define bb_dma1_ch5_ccr_pinc   (*(vu32*)(bb_dma1_ch5_ccr_base+4*6))
#define bb_dma1_ch5_ccr_minc   (*(vu32*)(bb_dma1_ch5_ccr_base+4*7))
#define bb_dma1_ch5_ccr_m2m    (*(vu32*)(bb_dma1_ch5_ccr_base+4*14))
#define bm_dma1_ch5_ccr_psize  0x00000300  //�������ݿ��ȣ�00=8��01=16��10=32
#define bm_dma1_ch5_ccr_msize  0x00000c00  //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bm_dma1_ch5_ccr_pl     0x00003000  //ͨ�����ȼ���00��ͣ�11���
#define bo_dma1_ch5_ccr_en     0    //1=ͨ������
#define bo_dma1_ch5_ccr_tcie   1    //1=������������ж�
#define bo_dma1_ch5_ccr_htie   2    //1=�����봫���ж�
#define bo_dma1_ch5_ccr_teie   3    //1=������������ж�
#define bo_dma1_ch5_ccr_dir    4    //0=���������1=�Ӵ洢����
#define bo_dma1_ch5_ccr_circ   5    //0=ִ��ѭ��������1��֮
#define bo_dma1_ch5_ccr_pinc   6    //0=�����ַ��������1��֮
#define bo_dma1_ch5_ccr_minc   7    //0=�洢����ַ��������1��֮
#define bo_dma1_ch5_ccr_m2m    14   //0=�Ǵ洢�����洢��ģʽ��1=���ô洢�����洢��ģʽ
#define bo_dma1_ch5_ccr_psize  8    //�������ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch5_ccr_msize  10   //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch5_ccr_pl     12   //ͨ�����ȼ���00��ͣ�11���

#define bb_dma1_ch6_ccr_base   (0x42000000 + 0x2006c*32)            //λ����ַ
#define bb_dma1_ch6_ccr_en     (*(vu32*)(bb_dma1_ch6_ccr_base+4*0))
#define bb_dma1_ch6_ccr_tcie   (*(vu32*)(bb_dma1_ch6_ccr_base+4*1))
#define bb_dma1_ch6_ccr_htie   (*(vu32*)(bb_dma1_ch6_ccr_base+4*2))
#define bb_dma1_ch6_ccr_teie   (*(vu32*)(bb_dma1_ch6_ccr_base+4*3))
#define bb_dma1_ch6_ccr_dir    (*(vu32*)(bb_dma1_ch6_ccr_base+4*4))
#define bb_dma1_ch6_ccr_circ   (*(vu32*)(bb_dma1_ch6_ccr_base+4*5))
#define bb_dma1_ch6_ccr_pinc   (*(vu32*)(bb_dma1_ch6_ccr_base+4*6))
#define bb_dma1_ch6_ccr_minc   (*(vu32*)(bb_dma1_ch6_ccr_base+4*7))
#define bb_dma1_ch6_ccr_m2m    (*(vu32*)(bb_dma1_ch6_ccr_base+4*14))
#define bm_dma1_ch6_ccr_psize  0x00000300  //�������ݿ��ȣ�00=8��01=16��10=32
#define bm_dma1_ch6_ccr_msize  0x00000c00  //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bm_dma1_ch6_ccr_pl     0x00003000  //ͨ�����ȼ���00��ͣ�11���
#define bo_dma1_ch6_ccr_en     0    //1=ͨ������
#define bo_dma1_ch6_ccr_tcie   1    //1=������������ж�
#define bo_dma1_ch6_ccr_htie   2    //1=�����봫���ж�
#define bo_dma1_ch6_ccr_teie   3    //1=������������ж�
#define bo_dma1_ch6_ccr_dir    4    //0=���������1=�Ӵ洢����
#define bo_dma1_ch6_ccr_circ   5    //0=ִ��ѭ��������1��֮
#define bo_dma1_ch6_ccr_pinc   6    //0=�����ַ��������1��֮
#define bo_dma1_ch6_ccr_minc   7    //0=�洢����ַ��������1��֮
#define bo_dma1_ch6_ccr_m2m    14   //0=�Ǵ洢�����洢��ģʽ��1=���ô洢�����洢��ģʽ
#define bo_dma1_ch6_ccr_psize  8    //�������ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch6_ccr_msize  10   //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch6_ccr_pl     12   //ͨ�����ȼ���00��ͣ�11���

#define bb_dma1_ch7_ccr_base   (0x42000000 + 0x20080*32)            //λ����ַ
#define bb_dma1_ch7_ccr_en     (*(vu32*)(bb_dma1_ch7_ccr_base+4*0))
#define bb_dma1_ch7_ccr_tcie   (*(vu32*)(bb_dma1_ch7_ccr_base+4*1))
#define bb_dma1_ch7_ccr_htie   (*(vu32*)(bb_dma1_ch7_ccr_base+4*2))
#define bb_dma1_ch7_ccr_teie   (*(vu32*)(bb_dma1_ch7_ccr_base+4*3))
#define bb_dma1_ch7_ccr_dir    (*(vu32*)(bb_dma1_ch7_ccr_base+4*4))
#define bb_dma1_ch7_ccr_circ   (*(vu32*)(bb_dma1_ch7_ccr_base+4*5))
#define bb_dma1_ch7_ccr_pinc   (*(vu32*)(bb_dma1_ch7_ccr_base+4*6))
#define bb_dma1_ch7_ccr_minc   (*(vu32*)(bb_dma1_ch7_ccr_base+4*7))
#define bb_dma1_ch7_ccr_m2m    (*(vu32*)(bb_dma1_ch7_ccr_base+4*14))
#define bm_dma1_ch7_ccr_psize  0x00000300  //�������ݿ��ȣ�00=8��01=16��10=32
#define bm_dma1_ch7_ccr_msize  0x00000c00  //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bm_dma1_ch7_ccr_pl     0x00003000  //ͨ�����ȼ���00��ͣ�11���
#define bo_dma1_ch7_ccr_en     0    //1=ͨ������
#define bo_dma1_ch7_ccr_tcie   1    //1=������������ж�
#define bo_dma1_ch7_ccr_htie   2    //1=�����봫���ж�
#define bo_dma1_ch7_ccr_teie   3    //1=������������ж�
#define bo_dma1_ch7_ccr_dir    4    //0=���������1=�Ӵ洢����
#define bo_dma1_ch7_ccr_circ   5    //0=ִ��ѭ��������1��֮
#define bo_dma1_ch7_ccr_pinc   6    //0=�����ַ��������1��֮
#define bo_dma1_ch7_ccr_minc   7    //0=�洢����ַ��������1��֮
#define bo_dma1_ch7_ccr_m2m    14   //0=�Ǵ洢�����洢��ģʽ��1=���ô洢�����洢��ģʽ
#define bo_dma1_ch7_ccr_psize  8    //�������ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch7_ccr_msize  10   //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bo_dma1_ch7_ccr_pl     12   //ͨ�����ȼ���00��ͣ�11���


#define bb_dma2_ch1_ccr_base   (0x42000000 + 0x20408*32)            //λ����ַ
#define bb_dma2_ch1_ccr_en     (*(vu32*)(bb_dma2_ch1_ccr_base+4*0))
#define bb_dma2_ch1_ccr_tcie   (*(vu32*)(bb_dma2_ch1_ccr_base+4*1))
#define bb_dma2_ch1_ccr_htie   (*(vu32*)(bb_dma2_ch1_ccr_base+4*2))
#define bb_dma2_ch1_ccr_teie   (*(vu32*)(bb_dma2_ch1_ccr_base+4*3))
#define bb_dma2_ch1_ccr_dir    (*(vu32*)(bb_dma2_ch1_ccr_base+4*4))
#define bb_dma2_ch1_ccr_circ   (*(vu32*)(bb_dma2_ch1_ccr_base+4*5))
#define bb_dma2_ch1_ccr_pinc   (*(vu32*)(bb_dma2_ch1_ccr_base+4*6))
#define bb_dma2_ch1_ccr_minc   (*(vu32*)(bb_dma2_ch1_ccr_base+4*7))
#define bb_dma2_ch1_ccr_m2m    (*(vu32*)(bb_dma2_ch1_ccr_base+4*14))
#define bm_dma2_ch1_ccr_psize  0x00000300  //�������ݿ��ȣ�00=8��01=16��10=32
#define bm_dma2_ch1_ccr_msize  0x00000c00  //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bm_dma2_ch1_ccr_pl     0x00003000  //ͨ�����ȼ���00��ͣ�11���
#define bo_dma2_ch1_ccr_en     0    //1=ͨ������
#define bo_dma2_ch1_ccr_tcie   1    //1=������������ж�
#define bo_dma2_ch1_ccr_htie   2    //1=�����봫���ж�
#define bo_dma2_ch1_ccr_teie   3    //1=������������ж�
#define bo_dma2_ch1_ccr_dir    4    //0=���������1=�Ӵ洢����
#define bo_dma2_ch1_ccr_circ   5    //0=ִ��ѭ��������1��֮
#define bo_dma2_ch1_ccr_pinc   6    //0=�����ַ��������1��֮
#define bo_dma2_ch1_ccr_minc   7    //0=�洢����ַ��������1��֮
#define bo_dma2_ch1_ccr_m2m    14   //0=�Ǵ洢�����洢��ģʽ��1=���ô洢�����洢��ģʽ
#define bo_dma2_ch1_ccr_psize  8    //�������ݿ��ȣ�00=8��01=16��10=32
#define bo_dma2_ch1_ccr_msize  10   //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bo_dma2_ch1_ccr_pl     12   //ͨ�����ȼ���00��ͣ�11���

#define bb_dma2_ch2_ccr_base   (0x42000000 + 0x2041c*32)           //λ����ַ
#define bb_dma2_ch2_ccr_en     (*(vu32*)(bb_dma2_ch2_ccr_base+4*0))
#define bb_dma2_ch2_ccr_tcie   (*(vu32*)(bb_dma2_ch2_ccr_base+4*1))
#define bb_dma2_ch2_ccr_htie   (*(vu32*)(bb_dma2_ch2_ccr_base+4*2))
#define bb_dma2_ch2_ccr_teie   (*(vu32*)(bb_dma2_ch2_ccr_base+4*3))
#define bb_dma2_ch2_ccr_dir    (*(vu32*)(bb_dma2_ch2_ccr_base+4*4))
#define bb_dma2_ch2_ccr_circ   (*(vu32*)(bb_dma2_ch2_ccr_base+4*5))
#define bb_dma2_ch2_ccr_pinc   (*(vu32*)(bb_dma2_ch2_ccr_base+4*6))
#define bb_dma2_ch2_ccr_minc   (*(vu32*)(bb_dma2_ch2_ccr_base+4*7))
#define bb_dma2_ch2_ccr_m2m    (*(vu32*)(bb_dma2_ch2_ccr_base+4*14))
#define bm_dma2_ch2_ccr_psize  0x00000300  //�������ݿ��ȣ�00=8��01=16��10=32
#define bm_dma2_ch2_ccr_msize  0x00000c00  //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bm_dma2_ch2_ccr_pl     0x00003000  //ͨ�����ȼ���00��ͣ�11���
#define bo_dma2_ch2_ccr_en     0    //1=ͨ������
#define bo_dma2_ch2_ccr_tcie   1    //1=������������ж�
#define bo_dma2_ch2_ccr_htie   2    //1=�����봫���ж�
#define bo_dma2_ch2_ccr_teie   3    //1=������������ж�
#define bo_dma2_ch2_ccr_dir    4    //0=���������1=�Ӵ洢����
#define bo_dma2_ch2_ccr_circ   5    //0=ִ��ѭ��������1��֮
#define bo_dma2_ch2_ccr_pinc   6    //0=�����ַ��������1��֮
#define bo_dma2_ch2_ccr_minc   7    //0=�洢����ַ��������1��֮
#define bo_dma2_ch2_ccr_m2m    14   //0=�Ǵ洢�����洢��ģʽ��1=���ô洢�����洢��ģʽ
#define bo_dma2_ch2_ccr_psize  8    //�������ݿ��ȣ�00=8��01=16��10=32
#define bo_dma2_ch2_ccr_msize  10   //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bo_dma2_ch2_ccr_pl     12   //ͨ�����ȼ���00��ͣ�11���

#define bb_dma2_ch3_ccr_base   (0x42000000 + 0x20430*32)            //λ����ַ
#define bb_dma2_ch3_ccr_en     (*(vu32*)(bb_dma2_ch3_ccr_base+4*0))
#define bb_dma2_ch3_ccr_tcie   (*(vu32*)(bb_dma2_ch3_ccr_base+4*1))
#define bb_dma2_ch3_ccr_htie   (*(vu32*)(bb_dma2_ch3_ccr_base+4*2))
#define bb_dma2_ch3_ccr_teie   (*(vu32*)(bb_dma2_ch3_ccr_base+4*3))
#define bb_dma2_ch3_ccr_dir    (*(vu32*)(bb_dma2_ch3_ccr_base+4*4))
#define bb_dma2_ch3_ccr_circ   (*(vu32*)(bb_dma2_ch3_ccr_base+4*5))
#define bb_dma2_ch3_ccr_pinc   (*(vu32*)(bb_dma2_ch3_ccr_base+4*6))
#define bb_dma2_ch3_ccr_minc   (*(vu32*)(bb_dma2_ch3_ccr_base+4*7))
#define bb_dma2_ch3_ccr_m2m    (*(vu32*)(bb_dma2_ch3_ccr_base+4*14))
#define bm_dma2_ch3_ccr_psize  0x00000300  //�������ݿ��ȣ�00=8��01=16��10=32
#define bm_dma2_ch3_ccr_msize  0x00000c00  //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bm_dma2_ch3_ccr_pl     0x00003000  //ͨ�����ȼ���00��ͣ�11���
#define bo_dma2_ch3_ccr_en     0    //1=ͨ������
#define bo_dma2_ch3_ccr_tcie   1    //1=������������ж�
#define bo_dma2_ch3_ccr_htie   2    //1=�����봫���ж�
#define bo_dma2_ch3_ccr_teie   3    //1=������������ж�
#define bo_dma2_ch3_ccr_dir    4    //0=���������1=�Ӵ洢����
#define bo_dma2_ch3_ccr_circ   5    //0=ִ��ѭ��������1��֮
#define bo_dma2_ch3_ccr_pinc   6    //0=�����ַ��������1��֮
#define bo_dma2_ch3_ccr_minc   7    //0=�洢����ַ��������1��֮
#define bo_dma2_ch3_ccr_m2m    14   //0=�Ǵ洢�����洢��ģʽ��1=���ô洢�����洢��ģʽ
#define bo_dma2_ch3_ccr_psize  8    //�������ݿ��ȣ�00=8��01=16��10=32
#define bo_dma2_ch3_ccr_msize  10   //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bo_dma2_ch3_ccr_pl     12   //ͨ�����ȼ���00��ͣ�11���

#define bb_dma2_ch4_ccr_base   (0x42000000 + 0x20444*32)            //λ����ַ
#define bb_dma2_ch4_ccr_en     (*(vu32*)(bb_dma2_ch4_ccr_base+4*0))
#define bb_dma2_ch4_ccr_tcie   (*(vu32*)(bb_dma2_ch4_ccr_base+4*1))
#define bb_dma2_ch4_ccr_htie   (*(vu32*)(bb_dma2_ch4_ccr_base+4*2))
#define bb_dma2_ch4_ccr_teie   (*(vu32*)(bb_dma2_ch4_ccr_base+4*3))
#define bb_dma2_ch4_ccr_dir    (*(vu32*)(bb_dma2_ch4_ccr_base+4*4))
#define bb_dma2_ch4_ccr_circ   (*(vu32*)(bb_dma2_ch4_ccr_base+4*5))
#define bb_dma2_ch4_ccr_pinc   (*(vu32*)(bb_dma2_ch4_ccr_base+4*6))
#define bb_dma2_ch4_ccr_minc   (*(vu32*)(bb_dma2_ch4_ccr_base+4*7))
#define bb_dma2_ch4_ccr_m2m    (*(vu32*)(bb_dma2_ch4_ccr_base+4*14))
#define bm_dma2_ch4_ccr_psize  0x00000300  //�������ݿ��ȣ�00=8��01=16��10=32
#define bm_dma2_ch4_ccr_msize  0x00000c00  //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bm_dma2_ch4_ccr_pl     0x00003000  //ͨ�����ȼ���00��ͣ�11���
#define bo_dma2_ch4_ccr_en     0    //1=ͨ������
#define bo_dma2_ch4_ccr_tcie   1    //1=������������ж�
#define bo_dma2_ch4_ccr_htie   2    //1=�����봫���ж�
#define bo_dma2_ch4_ccr_teie   3    //1=������������ж�
#define bo_dma2_ch4_ccr_dir    4    //0=���������1=�Ӵ洢����
#define bo_dma2_ch4_ccr_circ   5    //0=ִ��ѭ��������1��֮
#define bo_dma2_ch4_ccr_pinc   6    //0=�����ַ��������1��֮
#define bo_dma2_ch4_ccr_minc   7    //0=�洢����ַ��������1��֮
#define bo_dma2_ch4_ccr_m2m    14   //0=�Ǵ洢�����洢��ģʽ��1=���ô洢�����洢��ģʽ
#define bo_dma2_ch4_ccr_psize  8    //�������ݿ��ȣ�00=8��01=16��10=32
#define bo_dma2_ch4_ccr_msize  10   //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bo_dma2_ch4_ccr_pl     12   //ͨ�����ȼ���00��ͣ�11���

#define bb_dma2_ch5_ccr_base   (0x42000000 + 0x20458*32)           //λ����ַ
#define bb_dma2_ch5_ccr_en     (*(vu32*)(bb_dma2_ch5_ccr_base+4*0))
#define bb_dma2_ch5_ccr_tcie   (*(vu32*)(bb_dma2_ch5_ccr_base+4*1))
#define bb_dma2_ch5_ccr_htie   (*(vu32*)(bb_dma2_ch5_ccr_base+4*2))
#define bb_dma2_ch5_ccr_teie   (*(vu32*)(bb_dma2_ch5_ccr_base+4*3))
#define bb_dma2_ch5_ccr_dir    (*(vu32*)(bb_dma2_ch5_ccr_base+4*4))
#define bb_dma2_ch5_ccr_circ   (*(vu32*)(bb_dma2_ch5_ccr_base+4*5))
#define bb_dma2_ch5_ccr_pinc   (*(vu32*)(bb_dma2_ch5_ccr_base+4*6))
#define bb_dma2_ch5_ccr_minc   (*(vu32*)(bb_dma2_ch5_ccr_base+4*7))
#define bb_dma2_ch5_ccr_m2m    (*(vu32*)(bb_dma2_ch5_ccr_base+4*14))
#define bm_dma2_ch5_ccr_psize  0x00000300  //�������ݿ��ȣ�00=8��01=16��10=32
#define bm_dma2_ch5_ccr_msize  0x00000c00  //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bm_dma2_ch5_ccr_pl     0x00003000  //ͨ�����ȼ���00��ͣ�11���
#define bo_dma2_ch5_ccr_en     0    //1=ͨ������
#define bo_dma2_ch5_ccr_tcie   1    //1=������������ж�
#define bo_dma2_ch5_ccr_htie   2    //1=�����봫���ж�
#define bo_dma2_ch5_ccr_teie   3    //1=������������ж�
#define bo_dma2_ch5_ccr_dir    4    //0=���������1=�Ӵ洢����
#define bo_dma2_ch5_ccr_circ   5    //0=ִ��ѭ��������1��֮
#define bo_dma2_ch5_ccr_pinc   6    //0=�����ַ��������1��֮
#define bo_dma2_ch5_ccr_minc   7    //0=�洢����ַ��������1��֮
#define bo_dma2_ch5_ccr_m2m    14   //0=�Ǵ洢�����洢��ģʽ��1=���ô洢�����洢��ģʽ
#define bo_dma2_ch5_ccr_psize  8    //�������ݿ��ȣ�00=8��01=16��10=32
#define bo_dma2_ch5_ccr_msize  10   //�洢�����ݿ��ȣ�00=8��01=16��10=32
#define bo_dma2_ch5_ccr_pl     12   //ͨ�����ȼ���00��ͣ�11���
//dma1 channel1:0x40020008
//dma1 channel2:0x4002001c
//dma1 channel3:0x40020030
//dma1 channel4:0x40020044
//dma1 channel5:0x40020058
//dma1 channel6:0x4002006c
//dma1 channel7:0x40020080
//dma2 channel1:0x40020408
//dma2 channel2:0x4002041c
//dma2 channel3:0x40020430
//dma2 channel4:0x40020444
//dma2 channel5:0x40020458
struct DMA_StChannelReg
{
  vu32 CCR;
  vu32 CNDTR;
  vu32 CPAR;
  vu32 CMAR;
};

#define bb_dma1_isr_base    (0x42000000 + 0x20000*32)           //λ����ַ
#define bb_dma1_isr_gif1    (*(vu32*)(bb_dma1_isr_base+4*0))    //ȫ���жϱ�־
#define bb_dma1_isr_tcif1   (*(vu32*)(bb_dma1_isr_base+4*1))    //������ɱ�־
#define bb_dma1_isr_htif1   (*(vu32*)(bb_dma1_isr_base+4*2))    //�봫����ɱ�־
#define bb_dma1_isr_teif1   (*(vu32*)(bb_dma1_isr_base+4*3))    //��������־
#define bb_dma1_isr_gif2    (*(vu32*)(bb_dma1_isr_base+4*4))    //ȫ���жϱ�־
#define bb_dma1_isr_tcif2   (*(vu32*)(bb_dma1_isr_base+4*5))    //������ɱ�־
#define bb_dma1_isr_htif2   (*(vu32*)(bb_dma1_isr_base+4*6))    //�봫����ɱ�־
#define bb_dma1_isr_teif2   (*(vu32*)(bb_dma1_isr_base+4*7))    //��������־
#define bb_dma1_isr_gif3    (*(vu32*)(bb_dma1_isr_base+4*8))    //ȫ���жϱ�־
#define bb_dma1_isr_tcif3   (*(vu32*)(bb_dma1_isr_base+4*9))    //������ɱ�־
#define bb_dma1_isr_htif3   (*(vu32*)(bb_dma1_isr_base+4*10))   //�봫����ɱ�־
#define bb_dma1_isr_teif3   (*(vu32*)(bb_dma1_isr_base+4*11))   //��������־
#define bb_dma1_isr_gif4    (*(vu32*)(bb_dma1_isr_base+4*12))   //ȫ���жϱ�־
#define bb_dma1_isr_tcif4   (*(vu32*)(bb_dma1_isr_base+4*13))   //������ɱ�־
#define bb_dma1_isr_htif4   (*(vu32*)(bb_dma1_isr_base+4*14))   //�봫����ɱ�־
#define bb_dma1_isr_teif4   (*(vu32*)(bb_dma1_isr_base+4*15))   //��������־
#define bb_dma1_isr_gif5    (*(vu32*)(bb_dma1_isr_base+4*16))   //ȫ���жϱ�־
#define bb_dma1_isr_tcif5   (*(vu32*)(bb_dma1_isr_base+4*17))   //������ɱ�־
#define bb_dma1_isr_htif5   (*(vu32*)(bb_dma1_isr_base+4*18))   //�봫����ɱ�־
#define bb_dma1_isr_teif5   (*(vu32*)(bb_dma1_isr_base+4*19))   //��������־
#define bb_dma1_isr_gif6    (*(vu32*)(bb_dma1_isr_base+4*10))   //ȫ���жϱ�־
#define bb_dma1_isr_tcif6   (*(vu32*)(bb_dma1_isr_base+4*11))   //������ɱ�־
#define bb_dma1_isr_htif6   (*(vu32*)(bb_dma1_isr_base+4*22))   //�봫����ɱ�־
#define bb_dma1_isr_teif6   (*(vu32*)(bb_dma1_isr_base+4*23))   //��������־
#define bb_dma1_isr_gif7    (*(vu32*)(bb_dma1_isr_base+4*24))   //ȫ���жϱ�־
#define bb_dma1_isr_tcif7   (*(vu32*)(bb_dma1_isr_base+4*25))   //������ɱ�־
#define bb_dma1_isr_htif7   (*(vu32*)(bb_dma1_isr_base+4*26))   //�봫����ɱ�־
#define bb_dma1_isr_teif7   (*(vu32*)(bb_dma1_isr_base+4*27))   //��������־

#define bb_dma1_ifcr_base   (0x42000000 + 0x20004*32)           //λ����ַ
#define bb_dma1_ifcr_cgif1  (*(vu32*)(bb_dma1_ifcr_base+4*0))   //��ȫ���жϱ�־
#define bb_dma1_ifcr_ctcif1 (*(vu32*)(bb_dma1_ifcr_base+4*1))   //�崫����ɱ�־
#define bb_dma1_ifcr_chtif1 (*(vu32*)(bb_dma1_ifcr_base+4*2))   //��봫����ɱ�־
#define bb_dma1_ifcr_cteif1 (*(vu32*)(bb_dma1_ifcr_base+4*3))   //�崫������־
#define bb_dma1_ifcr_cgif2  (*(vu32*)(bb_dma1_ifcr_base+4*4))   //��ȫ���жϱ�־
#define bb_dma1_ifcr_ctcif2 (*(vu32*)(bb_dma1_ifcr_base+4*5))   //�崫����ɱ�־
#define bb_dma1_ifcr_chtif2 (*(vu32*)(bb_dma1_ifcr_base+4*6))   //��봫����ɱ�־
#define bb_dma1_ifcr_cteif2 (*(vu32*)(bb_dma1_ifcr_base+4*7))   //�崫������־
#define bb_dma1_ifcr_cgif3  (*(vu32*)(bb_dma1_ifcr_base+4*8))   //��ȫ���жϱ�־
#define bb_dma1_ifcr_ctcif3 (*(vu32*)(bb_dma1_ifcr_base+4*9))   //�崫����ɱ�־
#define bb_dma1_ifcr_chtif3 (*(vu32*)(bb_dma1_ifcr_base+4*10))  //��봫����ɱ�־
#define bb_dma1_ifcr_cteif3 (*(vu32*)(bb_dma1_ifcr_base+4*11))  //�崫������־
#define bb_dma1_ifcr_cgif4  (*(vu32*)(bb_dma1_ifcr_base+4*12))  //��ȫ���жϱ�־
#define bb_dma1_ifcr_ctcif4 (*(vu32*)(bb_dma1_ifcr_base+4*13))  //�崫����ɱ�־
#define bb_dma1_ifcr_chtif4 (*(vu32*)(bb_dma1_ifcr_base+4*14))  //��봫����ɱ�־
#define bb_dma1_ifcr_cteif4 (*(vu32*)(bb_dma1_ifcr_base+4*15))  //�崫������־
#define bb_dma1_ifcr_cgif5  (*(vu32*)(bb_dma1_ifcr_base+4*16))  //��ȫ���жϱ�־
#define bb_dma1_ifcr_ctcif5 (*(vu32*)(bb_dma1_ifcr_base+4*17))  //�崫����ɱ�־
#define bb_dma1_ifcr_chtif5 (*(vu32*)(bb_dma1_ifcr_base+4*18))  //��봫����ɱ�־
#define bb_dma1_ifcr_cteif5 (*(vu32*)(bb_dma1_ifcr_base+4*19))  //�崫������־
#define bb_dma1_ifcr_cgif6  (*(vu32*)(bb_dma1_ifcr_base+4*10))  //��ȫ���жϱ�־
#define bb_dma1_ifcr_ctcif6 (*(vu32*)(bb_dma1_ifcr_base+4*11))  //�崫����ɱ�־
#define bb_dma1_ifcr_chtif6 (*(vu32*)(bb_dma1_ifcr_base+4*22))  //��봫����ɱ�־
#define bb_dma1_ifcr_cteif6 (*(vu32*)(bb_dma1_ifcr_base+4*23))  //�崫������־
#define bb_dma1_ifcr_cgif7  (*(vu32*)(bb_dma1_ifcr_base+4*24))  //��ȫ���жϱ�־
#define bb_dma1_ifcr_ctcif7 (*(vu32*)(bb_dma1_ifcr_base+4*25))  //�崫����ɱ�־
#define bb_dma1_ifcr_chtif7 (*(vu32*)(bb_dma1_ifcr_base+4*26))  //��봫����ɱ�־
#define bb_dma1_ifcr_cteif7 (*(vu32*)(bb_dma1_ifcr_base+4*27))  //�崫������־

#define bb_dma2_isr_base    (0x42000000 + 0x20400*32)           //λ����ַ
#define bb_dma2_isr_gif1    (*(vu32*)(bb_dma2_isr_base+4*0))    //ȫ���жϱ�־
#define bb_dma2_isr_tcif1   (*(vu32*)(bb_dma2_isr_base+4*1))    //������ɱ�־
#define bb_dma2_isr_htif1   (*(vu32*)(bb_dma2_isr_base+4*2))    //�봫����ɱ�־
#define bb_dma2_isr_teif1   (*(vu32*)(bb_dma2_isr_base+4*3))    //��������־
#define bb_dma2_isr_gif2    (*(vu32*)(bb_dma2_isr_base+4*4))    //ȫ���жϱ�־
#define bb_dma2_isr_tcif2   (*(vu32*)(bb_dma2_isr_base+4*5))    //������ɱ�־
#define bb_dma2_isr_htif2   (*(vu32*)(bb_dma2_isr_base+4*6))    //�봫����ɱ�־
#define bb_dma2_isr_teif2   (*(vu32*)(bb_dma2_isr_base+4*7))    //��������־
#define bb_dma2_isr_gif3    (*(vu32*)(bb_dma2_isr_base+4*8))    //ȫ���жϱ�־
#define bb_dma2_isr_tcif3   (*(vu32*)(bb_dma2_isr_base+4*9))    //������ɱ�־
#define bb_dma2_isr_htif3   (*(vu32*)(bb_dma2_isr_base+4*10))   //�봫����ɱ�־
#define bb_dma2_isr_teif3   (*(vu32*)(bb_dma2_isr_base+4*11))   //��������־
#define bb_dma2_isr_gif4    (*(vu32*)(bb_dma2_isr_base+4*12))   //ȫ���жϱ�־
#define bb_dma2_isr_tcif4   (*(vu32*)(bb_dma2_isr_base+4*13))   //������ɱ�־
#define bb_dma2_isr_htif4   (*(vu32*)(bb_dma2_isr_base+4*14))   //�봫����ɱ�־
#define bb_dma2_isr_teif4   (*(vu32*)(bb_dma2_isr_base+4*15))   //��������־
#define bb_dma2_isr_gif5    (*(vu32*)(bb_dma2_isr_base+4*16))   //ȫ���жϱ�־
#define bb_dma2_isr_tcif5   (*(vu32*)(bb_dma2_isr_base+4*17))   //������ɱ�־
#define bb_dma2_isr_htif5   (*(vu32*)(bb_dma2_isr_base+4*18))   //�봫����ɱ�־
#define bb_dma2_isr_teif5   (*(vu32*)(bb_dma2_isr_base+4*19))   //��������־

#define bb_dma2_ifcr_base   (0x42000000 + 0x20404*32)           //λ����ַ
#define bb_dma2_ifcr_cgif1  (*(vu32*)(bb_dma2_ifcr_base+4*0))   //��ȫ���жϱ�־
#define bb_dma2_ifcr_ctcif1 (*(vu32*)(bb_dma2_ifcr_base+4*1))   //�崫����ɱ�־
#define bb_dma2_ifcr_chtif1 (*(vu32*)(bb_dma2_ifcr_base+4*2))   //��봫����ɱ�־
#define bb_dma2_ifcr_cteif1 (*(vu32*)(bb_dma2_ifcr_base+4*3))   //�崫������־
#define bb_dma2_ifcr_cgif2  (*(vu32*)(bb_dma2_ifcr_base+4*4))   //��ȫ���жϱ�־
#define bb_dma2_ifcr_ctcif2 (*(vu32*)(bb_dma2_ifcr_base+4*5))   //�崫����ɱ�־
#define bb_dma2_ifcr_chtif2 (*(vu32*)(bb_dma2_ifcr_base+4*6))   //��봫����ɱ�־
#define bb_dma2_ifcr_cteif2 (*(vu32*)(bb_dma2_ifcr_base+4*7))   //�崫������־
#define bb_dma2_ifcr_cgif3  (*(vu32*)(bb_dma2_ifcr_base+4*8))   //��ȫ���жϱ�־
#define bb_dma2_ifcr_ctcif3 (*(vu32*)(bb_dma2_ifcr_base+4*9))   //�崫����ɱ�־
#define bb_dma2_ifcr_chtif3 (*(vu32*)(bb_dma2_ifcr_base+4*10))  //��봫����ɱ�־
#define bb_dma2_ifcr_cteif3 (*(vu32*)(bb_dma2_ifcr_base+4*11))  //�崫������־
#define bb_dma2_ifcr_cgif4  (*(vu32*)(bb_dma2_ifcr_base+4*12))  //��ȫ���жϱ�־
#define bb_dma2_ifcr_ctcif4 (*(vu32*)(bb_dma2_ifcr_base+4*13))  //�崫����ɱ�־
#define bb_dma2_ifcr_chtif4 (*(vu32*)(bb_dma2_ifcr_base+4*14))  //��봫����ɱ�־
#define bb_dma2_ifcr_cteif4 (*(vu32*)(bb_dma2_ifcr_base+4*15))  //�崫������־
#define bb_dma2_ifcr_cgif5  (*(vu32*)(bb_dma2_ifcr_base+4*16))  //��ȫ���жϱ�־
#define bb_dma2_ifcr_ctcif5 (*(vu32*)(bb_dma2_ifcr_base+4*17))  //�崫����ɱ�־
#define bb_dma2_ifcr_chtif5 (*(vu32*)(bb_dma2_ifcr_base+4*18))  //��봫����ɱ�־
#define bb_dma2_ifcr_cteif5 (*(vu32*)(bb_dma2_ifcr_base+4*19))  //�崫������־

struct DMA_StReg      //dma1 base 0x40020000,dma2 base 0x40020400
{
  vu32 ISR;
  vu32 IFCR;
};

extern struct DMA_StReg volatile * const pg_dma1_reg;
extern struct DMA_StReg volatile * const pg_dma2_reg;

extern struct DMA_StChannelReg volatile * const pg_dma1_channel1_reg;
extern struct DMA_StChannelReg volatile * const pg_dma1_channel2_reg;
extern struct DMA_StChannelReg volatile * const pg_dma1_channel3_reg;
extern struct DMA_StChannelReg volatile * const pg_dma1_channel4_reg;
extern struct DMA_StChannelReg volatile * const pg_dma1_channel5_reg;
extern struct DMA_StChannelReg volatile * const pg_dma1_channel6_reg;
extern struct DMA_StChannelReg volatile * const pg_dma1_channel7_reg;

extern struct DMA_StChannelReg volatile * const pg_dma2_channel1_reg;
extern struct DMA_StChannelReg volatile * const pg_dma2_channel2_reg;
extern struct DMA_StChannelReg volatile * const pg_dma2_channel3_reg;
extern struct DMA_StChannelReg volatile * const pg_dma2_channel4_reg;
extern struct DMA_StChannelReg volatile * const pg_dma2_channel5_reg;

// ============================================================================
#define DMA1_CH0    0
#define DMA1_CH1    1
#define DMA1_CH2    2
#define DMA1_CH3    3
#define DMA1_CH4    4
#define DMA1_CH5    5
#define DMA1_CH6    6
#define DMA1_CH7    7

#define DMA2_CH0    8
#define DMA2_CH1    9
#define DMA2_CH2    10
#define DMA2_CH3    11
#define DMA2_CH4    12
#define DMA2_CH5    13
#define DMA2_CH6    14
#define DMA2_CH7    15

// DMA��������ݿ���
#define DMA_DATABITS_8  0
#define DMA_DATABITS_16 1
#define DMA_DATABITS_32 2

// DMA���ݴ��䷽��
#define DMA_DIR_P2M     0
#define DMA_DIR_M2P     1
#define DMA_DIR_M2M     2

// DMA�ж�
#define DMA_INT_TCIE   (1<<4)
#define DMA_INT_HTIE   (1<<3)
#define DMA_INT_TEIE   (1<<2)
#define DMA_INT_DMEIE  (1<<1)

// DMA����API
u32 DMA_Config(DMA_Stream_TypeDef *DMA_Streamx,u8 chx,u32 par,u32 mar,
        u8 dir,u8 msize,u8 psize,u16 ndtr);
void DMA_Enable(DMA_Stream_TypeDef *DMA_Streamx,u32 mar,u16 ndtr);
void DMA_Disable(DMA_Stream_TypeDef *DMA_Streamx);
void DMA_ClearIntFlag(DMA_Stream_TypeDef *DMA_Streamx);
void DMA_IntEnable(DMA_Stream_TypeDef *DMA_Streamx,u8 SrcInt);
void DMA_IntDisable(DMA_Stream_TypeDef *DMA_Streamx,u8 SrcInt);


#ifdef __cplusplus
}
#endif
#endif //__CPU_PERI_DMA_H__
