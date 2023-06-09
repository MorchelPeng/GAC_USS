#ifndef TOPIC_COMMON_BUFFER_MCU2SOC
#define TOPIC_COMMON_BUFFER_MCU2SOC

#include "app_pps_protocal.h"
#include "ppscontrol.h"

//TOPICID_COMMON_BUFFER_MCU2SOC = 21

class TopicCommonBufferMcu2Soc
{
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
		DESY::PPS_CFG_STRU cfg={TOPICID_COMMON_BUFFER_MCU2SOC,"COMM_BUF_MCU2SOC",16,issub,ispub,15,300};
        return cfg;
    }
};
typedef struct SrvCamIspUpgradeInfo2QNX{
	uint32_t ISP_Upgrade_Phyaddr;
	uint32_t ISP_Upgrade_size;
	uint32_t ISP_Upgrade_Md5_value;
	uint32_t ISP_Upgrade_Prog_bar;
	uint8_t ISP_Upgrade_Type;
	SrvCamIspUpgradeInfo2QNX()
	{
		ISP_Upgrade_Phyaddr = 0;
		ISP_Upgrade_size = 0;
		ISP_Upgrade_Md5_value = 0;
		ISP_Upgrade_Prog_bar = 0;
		ISP_Upgrade_Type = 0;
	}
	bool operator!=(const struct SrvCamIspUpgradeInfo2QNX& other) const
	{
		return (this->ISP_Upgrade_Phyaddr != other.ISP_Upgrade_Phyaddr
				|| this->ISP_Upgrade_size != other.ISP_Upgrade_size
				|| this->ISP_Upgrade_Md5_value != other.ISP_Upgrade_Md5_value
				|| this->ISP_Upgrade_Prog_bar != other.ISP_Upgrade_Prog_bar
				|| this->ISP_Upgrade_Type != other.ISP_Upgrade_Type);
	}
	SrvCamIspUpgradeInfo2QNX& operator=(const struct SrvCamIspUpgradeInfo2QNX& other)
	{
		this->ISP_Upgrade_Phyaddr = other.ISP_Upgrade_Phyaddr;
		this->ISP_Upgrade_size = other.ISP_Upgrade_size;
		this->ISP_Upgrade_Md5_value = other.ISP_Upgrade_Md5_value;
		this->ISP_Upgrade_Prog_bar = other.ISP_Upgrade_Prog_bar;
		this->ISP_Upgrade_Type = other.ISP_Upgrade_Type;
		return *this;
	}
} SrvCamIspUpgradeInfo2QNX;
#endif
