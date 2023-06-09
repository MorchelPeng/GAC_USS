/*
 * client.h
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
#include <time.h>
#include "../../pps_public/app_pps_protocal.h"
#include "../../pps_public/ppscontrol.h"
#include "../../gac_inc/topic_ipcadapter.h"
#include "../../gac_inc/typedef_ipcadapter.h"
#include "topic_fvUssData.h"
#include "topic_canSignalRx.h"
#include "../include/data_sub.h"
struct g_Input
{
    DesayInterface_pps_USSDistForControl usspdc;
    DesayInterface_pps_USSEchoInfo ussecho;
    AlgInterface_VehPos drinfo;
    AlgInterface_APASMAPASt apastate;
    AlgInterface_IdtCanSignalRx20ms caninfo;
    bool ussinfo_flag;
    bool dr_flag;
    bool apastate_flag;
    bool caninfo_flag;
    std::string uss_echo_txt;
};

static g_Input g_input;

struct LocationPoint
{
    float x;
    float y;
    float yaw;
};
struct OBS_Point
{
    float x;
    float y;
};
class Client
{
public:
    static void message_callback(int topicid, int cmdid, int size, char *pdata);
    static void client_initial();
    static std::string gettime();
    static void getdata(g_Input &input);

private:
};
