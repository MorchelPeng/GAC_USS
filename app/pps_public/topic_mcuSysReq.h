#ifndef TOPIC_MCUSYSREQ_H
#define TOPIC_MCUSYSREQ_H

#include "ppscontrol.h"
#include "app_pps_protocal.h"


class TopicMcuSysReqApp
{
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
        DESY::PPS_CFG_STRU cfg={TOPICID_MCUSYSREQ_APP,"mcuSysReq",16,issub,ispub,15,300};
        return cfg;
    }
};

typedef enum
{
    CMDID_MCU_SYS_REQ_APP	= 0, //DesayInterface_pps_mcuSysReq_APP
    CMDID_MCU_SYS_REQ_APP_MAX
} CMDID_IN_MCUSYSREQ_APP_ENUM;

 class DesayInterface_pps_mcuSysReq_APP
 {
 public:
         //0:Normal Mode, 1:Factory Mode
         DEY_UnsignedShort sysFactoryModeReq;

         //debug menu show version
         DEY_Octet sysVersionMCU1[32];
         DEY_Octet sysVersionMCU3_0[32];
         DEY_Octet sysVersionLateAPP[32];
         DEY_Octet sysVersionMCU2_0[32];
         DEY_Octet sysVersionMCU2_1[32];
         DEY_Octet sysVersionMCU2_1Uss[32];
         DEY_Octet sysVersionReverse[32];
         DEY_Octet sysVersionReverse1[32];

         //0:"CarModSts1_CarModNorm", 1:"CarModSts1_CarModTrnsp",
         //2:"CarModSts1_CarModFcy", 3:"CarModSts1_CarModCrash", 5:"CarModSts1_CarModDyno"
         DEY_UnsignedShort sysCarModSts;

         //0:"UsgModSts1_UsgModAbdnd", 1:"UsgModSts1_UsgModInActv",
         //2:"UsgModSts1_UsgModCnvinc", 11:"UsgModSts1_UsgModActv", 13:"UsgModSts1_UsgModDrvg"
         DEY_UnsignedShort sysUsgModSts;

         //0:default, 1:normal, 2:off
         DEY_UnsignedShort sysPowerStateReq;
         DEY_Octet   sysTjpSts;//0:default, 1:open, 2:close
         DEY_Octet   sysSelfSearchReq;//0:not click 1:click
 };

#endif
