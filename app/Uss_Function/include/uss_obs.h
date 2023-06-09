/*
 * uss_obs.h
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
#include "../include/client.h"
namespace GAC_USS
{
    class USS_OBS
    {
    public:
    private:
        static void UPA_DE_trans_obs(DesayInterface_pps_USSEchoInfo ussecho, std::vector<LocationPoint> &uss_obs);
        static void APA_DE_trans_obs(DesayInterface_pps_USSEchoInfo ussecho, std::vector<LocationPoint> &uss_obs);
        static void CoordinateTransformationFromBodyToWorldPos(const LocationPoint &body, LocationPoint &object);
        static void obs_track(AlgInterface_VehPos &dr_info, std::vector<LocationPoint> &uss_obs);
        static bool Cal3rdPoint(std::vector<OBS_Point> SensorPoint, std::vector<float> vecDeValue, OBS_Point &thirdPoint);
        static float getDistance(OBS_Point pointA, OBS_Point pointB);
        static float getAngle(OBS_Point pointA, OBS_Point pointB);
    };

}
