
#include <iostream>
#include <unistd.h>
#include "topic_power_management.h"
#include "ppscontrol.h"
#include "app_pps_protocal.h"

static DESY::ppscontrol  *m_ppsctrl;
static DESY::PPS_CFG_STRU g_ppscfg[] = {
    TopicSocPowerManagement::cfg(0, 1),
    TopicEcuPowerManagement::cfg(1, 0)
};

static void message_callback(int topicid,int cmdid,int size,char *pdata);

int main() {
    m_ppsctrl = DESY::ppscontrol::Instance(g_ppscfg,sizeof(g_ppscfg)/sizeof(g_ppscfg[0]));
    m_ppsctrl->registerCallback(message_callback);
    DesayInterface_pps_SocPowerManagement data;
    data.SysRebootReq = 0;
    data.SysBootModeReq = 0;
    data.SysSocPowerState = 0;

    while(1) {
        // sleep(5);
        // data.SysRebootReq++;
        // data.SysBootModeReq++;
        // data.SysSocPowerState++;
        // m_ppsctrl->publish(TOPICID_soc_power_management,
        //                    CMDID_soc_power_management,
        //                    sizeof(DesayInterface_pps_SocPowerManagement),
        //                    (char*)&data);

    }
}

void message_callback(int topicid, int cmdid, int size, char *pdata) 
{
    if(topicid == TOPICID_ecu_power_management && cmdid == CMDID_ecu_power_management)
    {
        DesayInterface_pps_EcuPowerManagement* pEcuPowerManagement = (DesayInterface_pps_EcuPowerManagement *)pdata;
        printf("EcuPowerStatus = %d\n", pEcuPowerManagement->EcuPowerStatus);
    }
}
