
#include <thread>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include "topic_ipcadapter.h"


extern "C"{
	int32_t appLogGlobalTimeInit();
	uint64_t appLogGetGlobalTimeInUsec();
}


static DESY::ppscontrol  *m_ppsctrl;
static DESY::PPS_CFG_STRU g_ppscfg[] = {
    topicid_apa_state_machine::cfg_publish,
};
static void message_callback(int topicid,int cmdid,int size,char *pdata);

int main() 
{
    appLogGlobalTimeInit();

    m_ppsctrl = DESY::ppscontrol::Instance(g_ppscfg,sizeof(g_ppscfg)/sizeof(g_ppscfg[0]));
    DESY::ppscontrol::Instance()->registerCallback(message_callback);

    AlgInterface_APASMAPASt APASMAPASt = { 2 };

    m_ppsctrl->publish(TOPICID_APA_STATE_MACHINE, topicid_apa_state_machine::CMDID_APASM_APA_ST, sizeof(APASMAPASt), (char*)&APASMAPASt);
    return 0;

    for (;;) {
        pause();
    }
}

void message_callback(int topicid, int cmdid, int size, char *pdata) 
{
    
}



