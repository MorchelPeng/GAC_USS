#ifndef _TOPIC_POWER_MANAGMENT_H_
#define _TOPIC_POWER_MANAGMENT_H_

#include "app_pps_protocal.h"
#include "ppscontrol.h"

#pragma region TopicSocPowerManagement
class TopicSocPowerManagement {
   public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub) {
        DESY::PPS_CFG_STRU cfg = {TOPICID_soc_power_management,
                                  "soc_power_management",
                                  16,
                                  issub,
                                  ispub,
                                  15,
                                  300};
        return cfg;
    }

    static DESY::PPS_CFG_EX cfg_ex(int issub, int ispub) {
        DESY::PPS_CFG_EX cfg_ex = {TOPICID_soc_power_management,
                                  "soc_power_management",
                                  16,
                                  issub,
                                  ispub,
                                  15,
                                  300, 0, 19};
        return cfg_ex;
    }
};

class DesayInterface_pps_SocPowerManagement
{
public:
    DEY_Octet   SysRebootReq ;
    DEY_Octet   SysBootModeReq ;
    DEY_Octet   SysSocPowerState ;

};

/*begin TOPICID_soc_power_management cmdid and cmddata define.*/
typedef enum CMDID_IN_TOPICID_soc_power_management
{
    CMDID_soc_power_management		= 0,
    CMDID_soc_power_management_MAX
} CMDID_IN_TOPICID_soc_power_management_ENUM;

typedef struct DesayInterface_pps_TOPICID_soc_power_management_u
{
    DesayInterface_pps_SocPowerManagement	soc_power_management;
}DesayInterface_pps_TOPICID_soc_power_management_stru;
/*end TOPICID_soc_power_management*/
#pragma endregion

#pragma region TopicMcuPowerManagement
class TopicMcuPowerManagement {
   public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub) {
        DESY::PPS_CFG_STRU cfg = {TOPICID_mcu_power_management,
                                  "mcu_power_management",
                                  16,
                                  issub,
                                  ispub,
                                  15,
                                  300};
        return cfg;
    }
};

class DesayInterface_pps_McuPowerManagement
{
public:
    DEY_Octet   SysPowerStateReq ;      // 暂时不用
    DEY_Octet   SysCanNetStatus ;       // 0:on   1:sleep
    DEY_Octet   SysVBatStatus ;         // 0:Mode_V_INIT   1:Mode_V_LOW_ABNORMAL   2:Mode_V_LOW   3:Mode_V_NORMAL   4:Mode_V_HIGH   5:Mode_V_HIGH_ABNORMAL

};

/*begin TOPICID_mcu_power_management cmdid and cmddata define.*/
typedef enum CMDID_IN_TOPICID_mcu_power_management
{
    CMDID_mcu_power_management		= 0,
    CMDID_mcu_power_management_MAX
} CMDID_IN_TOPICID_mcu_power_management_ENUM;

typedef struct DesayInterface_pps_TOPICID_mcu_power_management_u
{
    DesayInterface_pps_McuPowerManagement	mcu_power_management;
}DesayInterface_pps_TOPICID_mcu_power_management_stru;
/*end TOPICID_mcu_power_management*/
#pragma endregion

#pragma region TopicEcuPowerManagement
class TopicEcuPowerManagement {
   public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub) {
        DESY::PPS_CFG_STRU cfg = {TOPICID_ecu_power_management,
                                  "ecu_power_management",
                                  16,
                                  issub,
                                  ispub,
                                  15,
                                  300};
        return cfg;
    }
};

/*begin TOPICID_ecu_power_management cmdid and cmddata define.*/
typedef enum CMDID_IN_TOPICID_ecu_power_management
{
    CMDID_ecu_power_management		= 0,        // DesayInterface_pps_EcuPowerManagement
    CMDID_ecu_power_management_MAX
} CMDID_IN_TOPICID_ecu_power_management_ENUM;
/*end TOPICID_ecu_power_management*/

class DesayInterface_pps_EcuPowerManagement
{
public:
    DEY_Octet   EcuPowerStatus ;    // ECU电源状态: 上电为0，下电为1
};
#pragma endregion

#pragma region TopicPowerOffDelayManagement
class TopicPowerOffDelayManagement {
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
        DESY::PPS_CFG_STRU cfg={TOPICID_POWER_OFF_DELAY,"topicid_gac_pwr_manager",10,issub,ispub,5,300};
        return cfg;
    }
};

/*begin TOPICID_DESAY_POWER_MANAGER cmdid define.*/
typedef enum CMDID_IN_TOPICID_POWER_OFF_DELAY
{
    CMDID_POWER_OFF_DELAY_REQUEST = 0,          // DesayInterface_pps_PowerOffDelayManagement HPA to IpcAdapterSVC
    CMDID_POWER_OFF_DELAY_RESPOND = 1,          // DesayInterface_pps_PowerOffDelayManagement IpcAdapterSVC to HPA
    CMDID_topicid_gac_pwr_manager_MAX
} CMDID_IN_TOPICID_POWER_OFF_DELAY_ENUM;
/*end TOPICID_DESAY_POWER_MANAGER*/

//HPA收到CMDID：CMDID_POWER_OFF_DELAY_RESPOND，pwroff_delay_respond = 1 得知即将断电，发送
//CMDID_POWER_OFF_DELAY_REQUEST, pwroff_delay_request = 1请求延时下电，如果不需要延时下电再发pwroff_delay_request = 0
class DesayInterface_pps_PowerOffDelayManagement
{
public:
    DEY_Octet pwroff_delay_request;     //断电延迟请求, 0: 不需要延迟下电; 1: 需要延迟下电;
    DEY_Octet pwroff_delay_respond;     //即将断电通知, 0: 默认; 1: 即将断电;
};

#pragma endregion

#endif // _TOPIC_POWER_MANAGMENT_H_
