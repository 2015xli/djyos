//-----------------------------------------------------------------------------
// Copyright (c) 2014, SHENZHEN PENGRUI SOFT CO LTD. All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:

// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
// 3. As a constituent part of djyos,do not transplant it to other software
//    without specific prior written permission.

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
// �����Ȩ�����ʹ���߷��������������������£�����ʹ����ʹ�ü���ɢ����
// ������װԭʼ�뼰����λ��ִ����ʽ��Ȩ�������۴˰�װ�Ƿ񾭸�����Ȼ��
//
// 1. ���ڱ�����Դ�������ɢ�������뱣�������İ�Ȩ���桢�������б�����
//    ������������������
// 2. ���ڱ��׼�����λ��ִ����ʽ����ɢ���������������ļ��Լ�������������
//    ��ɢ����װ�е�ý�鷽ʽ����������֮��Ȩ���桢�������б����Լ�����
//    ������������
// 3. ��������Ϊ�����߲���ϵͳ����ɲ��֣�δ����ǰȡ�õ��������ɣ���������ֲ����
//    �����߲���ϵͳ���������С�

// �����������������Ǳ�������Ȩ�������Լ�����������״��"as is"���ṩ��
// ��������װ�����κ���ʾ��Ĭʾ֮�������Σ������������ھ��������Լ��ض�Ŀ
// �ĵ�������ΪĬʾ�Ե�������Ȩ�����˼�������֮�����ߣ������κ�������
// ���۳�����κ��������塢���۴�����Ϊ���Լ��ϵ���޹�ʧ������������Υ
// Լ֮��Ȩ��������ʧ������ԭ��ȣ����𣬶����κ���ʹ�ñ�������װ��������
// �κ�ֱ���ԡ�����ԡ�ż���ԡ������ԡ��ͷ��Ի��κν�����𺦣�����������
// �������Ʒ������֮���á�ʹ����ʧ��������ʧ��������ʧ��ҵ���жϵȵȣ���
// �����κ����Σ����ڸ���ʹ���ѻ���ǰ��֪���ܻ���ɴ����𺦵���������Ȼ��
//-----------------------------------------------------------------------------


#include <sys/socket.h>

#define CN_DHCP_CLIENT_HOST       "DJYOS_CLIENT"
#define CN_DHCP_CLIENT_VENDOR     "DHCP_CV1.0"
#define CN_DHCP_SERVER_HOST       "DJYOS_SERVER"
#define CN_DHCP_SERVER_VENDOR     "DHCP_SV1.0"

#define CN_DHCP_FLAG_UNICAST      0X0000
#define CN_DHCP_FLAG_BROAD        0X8000
#define CN_DHCP_MAGICCOOKIE       "\x63\x82\x53\x63"
#define ETH_ALEN                  CN_MACADDR_LEN
#define ARPHRD_ETHER              1


/* UDP port numbers for DHCP */
#define DHCP_SERVER_PORT    67  /* from client to server */
#define DHCP_CLIENT_PORT    68  /* from server to client */

/* DHCP message OP code */
#define DHCP_BOOTREQUEST    1
#define DHCP_BOOTREPLY      2

/* DHCP message type */
#define DHCP_DISCOVER       1
#define DHCP_OFFER          2
#define DHCP_REQUEST        3
#define DHCP_DECLINE        4
#define DHCP_ACK            5
#define DHCP_NAK            6
#define DHCP_RELEASE        7
#define DHCP_INFORM         8

/* DHCP option and value (cf. RFC1533) */
enum
{
	padOption                 =   0,
	subnetMask                =   1,
	timerOffset               =   2,
	routersOnSubnet           =   3,
	timeServer                =   4,
	nameServer                =   5,
	dns                       =   6,
	logServer                 =   7,
	cookieServer              =   8,
	lprServer                 =   9,
	impressServer             =   10,
	resourceLocationServer    =   11,
	hostName                  =   12,
	bootFileSize              =   13,
	meritDumpFile             =   14,
	domainName                =   15,
	swapServer                =   16,
	rootPath                  =   17,
	extentionsPath            =   18,
	IPforwarding              =   19,
	nonLocalSourceRouting     =   20,
	policyFilter              =   21,
	maxDgramReasmSize         =   22,
	defaultIPTTL              =   23,
	pathMTUagingTimeout       =   24,
	pathMTUplateauTable       =   25,
	ifMTU                     =   26,
	allSubnetsLocal           =   27,
	broadcastAddr             =   28,
	performMaskDiscovery      =   29,
	maskSupplier              =   30,
	performRouterDiscovery    =   31,
	routerSolicitationAddr    =   32,
	staticRoute               =   33,
	trailerEncapsulation      =   34,
	arpCacheTimeout           =   35,
	ethernetEncapsulation     =   36,
	tcpDefaultTTL             =   37,
	tcpKeepaliveInterval      =   38,
	tcpKeepaliveGarbage       =   39,
	nisDomainName             =   40,
	nisServers                =   41,
	ntpServers                =   42,
	vendorSpecificInfo        =   43,
	netBIOSnameServer         =   44,
	netBIOSdgramDistServer    =   45,
	netBIOSnodeType           =   46,
	netBIOSscope              =   47,
	xFontServer               =   48,
	xDisplayManager           =   49,
	dhcpRequestedIPaddr       =   50,
	dhcpIPaddrLeaseTime       =   51,
	dhcpOptionOverload        =   52,
	dhcpMessageType           =   53,
	dhcpServerIdentifier      =   54,
	dhcpParamRequest          =   55,
	dhcpMsg                   =   56,
	dhcpMaxMsgSize            =   57,
	dhcpRenewTime             =   58,
	dhcpRebindTime            =   59,
	dhcpClassIdentifier       =   60,
	dhcpClientIdentifier      =   61,
	endOption                 =   255
};

#pragma pack(1)
typedef struct DhcpMessage
{
  u8  op;       /* operation type */
  u8  htype;    /* hardware address type */
  u8  hlen;     /* hardware address length */
  u8  hops;     /* should be zero in client's message */
  u32 xid;      /* transaction id */
  u16 secs;     /* elapsed time in sec. from trying to boot */
  u16 flags;
  u32 ciaddr;   /* (previously allocated) client IP address */
  u32 yiaddr;   /* 'your' client IP address */
  u32 siaddr;   /* should be zero in client's messages */
  u32 giaddr;   /* should be zero in client's messages */
  u8  chaddr[16];   /* client's hardware address */
  u8  sname[64];    /* server host name, null terminated string */
  u8  file[128];    /* boot file name, null terminated string */
  u8  options[312]; /* message options */
}tagDhcpMsg;

typedef struct
{
    u8 type;
    u8 len;
    u8 data[0];
}tagDhcpOpt;

#pragma pack()

#define CN_MSGMAX_LEN    (sizeof(tagDhcpMsg))
#define CN_DHCP_STRLEN   16

//used for the discover and request message
typedef struct
{
	u8   optype;
	u8   msgtype;
	u32  reqip;
	u32  dhcpserver;
	u8   clientmac[CN_MACADDR_LEN];
	u32  transaction;
}tagDhcpRequestPara;
//used for the offer and ack message
typedef struct
{
	u8   optype;
	u8   msgtype;
	u32  transaction;
	u32  offerip;
	u32  dhcpservernxt;
	u32  relayagent;
	u8   clientmac[CN_MACADDR_LEN];
	u32  renewtime;
	u32  bindtime;
	u32  leasetime;
	u32  dhcpserver;
	u32  ipmask;
	u32  router;
	char domainname[CN_DHCP_STRLEN];
	u32  dns1;
	u32  dns2;
}tagDhcpReplyPara;


void makeDhcpRequestMsg(tagDhcpMsg *msg,tagDhcpRequestPara *para);
void showDhcpRequestMsg(tagDhcpRequestPara *para);
bool_t pasteDhcpReplyMsg(tagDhcpReplyPara *para,tagDhcpMsg *msg);
void makeDhcpReplyMsg(tagDhcpMsg *msg,tagDhcpReplyPara *para);
bool_t pasteDhcpRequestMsg(tagDhcpRequestPara *para,tagDhcpMsg *msg);


