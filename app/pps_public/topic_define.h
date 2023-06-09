#pragma once

#include "ppscontrol.h"
#include "app_pps_protocal.h"

#pragma region TopicErrorManage

// TOPICID_ERROR_MANAGE_APP = 512
// Used for Desay
class TopicErrorManage
{
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
        DESY::PPS_CFG_STRU cfg = {TOPICID_ERROR_MANAGE_APP, "errorManage", 16, issub, ispub, 15, 300};
        return cfg;
    }

    enum
    {
        CMDID_HeartbeatPackage      = 0,    // Struct_HeartbeatPackage
        CMDID_ErrorManage_MAX
    };
};

struct Struct_HeartbeatPackage
{
    DEY_UnsignedShort       FrameHeader;
    DEY_Octet               ID;
    DEY_Octet               FrameCounter;
    DEY_UnsignedShort       BistStatus;
    DEY_UnsignedShort       ProgramFlowValue;
    DEY_Octet               HardwareStatus;
    DEY_Octet               SoftwareStatus;
    DEY_UnsignedShort       HLevelErrID;
    DEY_Octet               Reserve[2];
    DEY_UnsignedShort       Checksum;
};
#pragma endregion

#pragma region TopicCanSignalRx
// TOPICID_CANSIGNAL_RX_APP = 401
// Used for Desay
class TopicCanSignalRx
{
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
        DESY::PPS_CFG_STRU cfg={TOPICID_CANSIGNAL_RX_APP,"canSignalRx_data",16,issub,ispub,15,300};
        return cfg;
    }
};

typedef enum
{
	CMDID_CAN_SIGNAL_RX_AVPMessageSt = 5,   // DesayInterface_pps_IdtCanSignalAVPMessageSt 临时的CMDID，供AVP模拟接收车机的后台泊车推荐信号
    CMDID_CAN_SIGNAL_RX_MAX
}TopicCanSignalRx_CMDID;

// 临时的结构体，供AVP模拟接收车机的后台泊车推荐信号
class DesayInterface_pps_IdtCanSignalAVPMessageSt{
public:
    DEY_Octet   ACU_AVPMessageSt;   //枚举值:    0x1 Show  显示推送消息;
                                    //          0x2 Auto close  消息超时不点击后，自动关闭
	                                //          0x3 Maual close  用户主动点击忽略消息
	                                //          0x4 Maual Active  用户主动点击“好的”/“开始”等
};

#pragma endregion