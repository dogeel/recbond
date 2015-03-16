#define BON_CHANNEL		0
#define ARIB_GROUND		1
#define ARIB_CATV		2
#define ARIB_BS			3
#define ARIB_BS_SID		4
#define ARIB_CS			5
#define ARIB_TSID		6
#define ARIB_CH_ERROR	0x7FFFFFFFU

#define ISDB_T_NODE_LIMIT 24        // 32:ARIB limit 24:program maximum
#define ISDB_T_SLOT_LIMIT 8

#ifndef _BONDRIVER_DVB_H_
#ifndef _BONDRIVER_LINUXPT_H_

// linux環境下で標準的なチャンネル指定をSetChannel()に渡せる形に変換
// チューナードライバー直下のBonDriverに追加したchannelLinuxToBon()でBonDriverチャンネル番号へ変換される
// "nn"		地デジ(n=1-63)
// "Cnn"	CATV(n=13-63)
// "nnn"	BSサービスID指定(n=101-999)
// "BSnn_s"	BSトラポン指定(n=node,s=slot DVBでは動作不良の可能性有り)
// "CSnn"	CSトラポン指定(n=2-24)
// "0xhhhh"	BS/CS TSID指定(h=0x4010-0x7fff)
// "Bnn"	BonDriverチャンネル番号(n=0-)
DWORD channelAribToBon(char *channel)
{
	DWORD tsid;
	DWORD node = 0;
	DWORD slot;
	DWORD freqno;

	if (channel[0] == '0' && (channel[1] == 'X' || channel[1] == 'x'))
	{
		tsid = strtoul(channel, NULL, 16);
		channel += strlen(channel);
	}
	else
	{
		int ch_type = 0;

		if (*channel == 'B')
		{
			channel++;
			ch_type++;
			if (*channel == 'S')
			{
				channel++;
				ch_type++;
			}
		}
		else if (*channel == 'C')
		{
			channel++;
			ch_type = 10;
			if (*channel == 'S')
			{
				channel++;
				ch_type++;
			}
		}
		while (isdigit((int)*channel))
		{
			node *= 10;
			node += (DWORD)(*channel++ - '0');
		}
		switch (ch_type)
		{
		case 1:	// BonDriver Channel No
			if (*channel == '\0')
				return node;
		default:
			return ARIB_CH_ERROR;
		case 2:	// "BSnn_n"指定
			if (*channel == '_' && (node & 0x01) && node < ISDB_T_NODE_LIMIT)
			{
				if (isdigit((int)*++channel))
				{
					slot = *channel - '0';
					if (*++channel == '\0' && slot < ISDB_T_SLOT_LIMIT)
						return (ARIB_BS << 16) | (node << 4) | slot;
				}
			}
			return ARIB_CH_ERROR;
		case 11:	// CS
			if (*channel == '\0' && 2 <= node && node <= ISDB_T_NODE_LIMIT)
				return (ARIB_CS << 16) | (node / 2 + 11);
			return ARIB_CH_ERROR;
		case 10:	// CATV
			if (*channel == '\0' && 13 <= node && node <= 63)
			{
				if (node >= 23)
					freqno = node - 1;
				else
					freqno = node - 10;
				return (ARIB_CATV << 16) | freqno;
			}
			return ARIB_CH_ERROR;
		case 0:	// number
			if (*channel == '\0' && node)
			{
				if (node <= 63)
				{
					// 地上波
					if (node <= 3)
						freqno = node - 1;
					else if (node <= 12)
						freqno = node + 9;
					else
						freqno = node + 50;
					return (ARIB_GROUND << 16) | freqno;
				}
				else if (101 <= node && node <= 999)
				{
					// BS sid指定(あくまでチャンネル指定でありTS分離指示は別)
					return (ARIB_BS_SID << 16) | node;
				}
				tsid = node;
			}
			else
				return ARIB_CH_ERROR;
		}
	}
	// TransportStreamID指定
	if (*channel == '\0' && 0x4010U <= tsid && tsid <= 0x7fffU)
	{
		node = (tsid & 0x01f0U) >> 4;
		slot = tsid & 0x0007U;
		switch (tsid & 0xf008U)
		{
		case 0x4000U:	// BS
			if (node == 15)
			{
				if (slot > 0)
					slot--;
				else
					return ARIB_CH_ERROR;
			}
			if ((node & 0x0001) && node < ISDB_T_NODE_LIMIT && slot < ISDB_T_SLOT_LIMIT)
				return (ARIB_TSID << 16) | tsid;
			break;
		case 0x6000U:	// CS
		case 0x7000U:
			if ((node & 0x0001) == 0 && 2 <= node && node <= ISDB_T_NODE_LIMIT && slot == 0)
				return (ARIB_TSID << 16) | tsid;
			break;
		}
	}
	return ARIB_CH_ERROR;
}

#endif	// _BONDRIVER_LINUXPT_H_
#endif	// _BONDRIVER_DVB_H_
