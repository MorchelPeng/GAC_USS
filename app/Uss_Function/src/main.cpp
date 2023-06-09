/*
 * main.cpp
 *
 *  Created on: Jun 5, 2023
 *      Author: moxiaopeng
 */
#include "../../pps_public/app_pps_protocal.h"
#include "../../pps_public/ppscontrol.h"
#include "../../gac_inc/topic_ipcadapter.h"
#include "../../gac_inc/typedef_ipcadapter.h"
#include <thread>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include "topic_fvUssData.h"
#include "topic_canSignalRx.h"
#include "../include/uss_obs.h"
#include "../include/client.h"
extern "C"
{
    int32_t appLogGlobalTimeInit();
    uint64_t appLogGetGlobalTimeInUsec();
}

static DESY::ppscontrol *m_ppsctrl;
static DESY::PPS_CFG_STRU g_ppscfg[] = {
    TopicFvUssData::cfg(1, 0),
    topicid_gac_apa_dr::cfg_subscribe,
    topicid_gac_veh_state_est::cfg_subscribe,
    topicid_apa_state_machine::cfg_subscribe,
    topicid_gac_can_rx::cfg_subscribe,
};

int main()
{
    appLogGlobalTimeInit();
    Client::client_initial();
    g_Input input_data;
    m_ppsctrl = DESY::ppscontrol::Instance(g_ppscfg, sizeof(g_ppscfg) / sizeof(g_ppscfg[0]));
    DESY::ppscontrol::Instance()->registerCallback(Client::message_callback);
    for (;;)
    {
        Client::getdata(input_data);
        usleep(1 * 100); // unit is 10^-6 sec
        // put the main funtion here
        std::cout << "input_data.ussinfo_flag is " << input_data.ussinfo_flag << std::endl;
        if (input_data.ussinfo_flag)
        {
            std::cout << "Rec uss to txt info" << std::endl;
            GAC_USS_DATA::Data_Sub::USS_TO_TXT(input_data.ussecho, input_data.uss_echo_txt);
            input_data.ussinfo_flag = false;
        }
    }
}
