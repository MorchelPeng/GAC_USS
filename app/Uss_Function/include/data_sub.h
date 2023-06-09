/*
 * data_sub.h
 *
 *  Created on: Jun 5, 2023
 *      Author: moxiaopeng
 */
#pragma once
#include <vector>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <thread>
#include <unistd.h>
#include <stdio.h>
#include "../../pps_public/app_pps_protocal.h"
#include "../../pps_public/ppscontrol.h"
#include "../../gac_inc/topic_ipcadapter.h"
#include "../../gac_inc/typedef_ipcadapter.h"
#include "topic_fvUssData.h"
#include "topic_canSignalRx.h"
#include "client.h"
using namespace std;
namespace GAC_USS_DATA
{
    class Data_Sub
    {
    public:
        static void USS_TO_TXT(DesayInterface_pps_USSEchoInfo ussecho,std::string txt_name);
        static void USS_ECHO_TITLE_SETTING(std::string txt_name);

    private:
    };
}
