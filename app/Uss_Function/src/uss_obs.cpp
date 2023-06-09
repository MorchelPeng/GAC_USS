/*
 * uss_obs.cpp
 *
 *  Created on: Jun 5, 2023
 *      Author: moxiaopeng
 */
#include "../include/uss_obs.h"

/**
 * @brief obtain UPA obs based on de value
 */
void UPA_DE_trans_obs(DesayInterface_pps_USSEchoInfo ussecho, std::vector<LocationPoint> &uss_obs)
{
    LocationPoint uss_obs_temp;
    int16 DE_FL = ussecho.USSEchoInfoArray[1].USSDEFirst;
    int16 DE_FLM = ussecho.USSEchoInfoArray[2].USSDEFirst;
    int16 DE_FRM = ussecho.USSEchoInfoArray[3].USSDEFirst;
    int16 DE_FR = ussecho.USSEchoInfoArray[4].USSDEFirst;
    int16 DE_RL = ussecho.USSEchoInfoArray[10].USSDEFirst;
    int16 DE_RLM = ussecho.USSEchoInfoArray[9].USSDEFirst;
    int16 DE_RRM = ussecho.USSEchoInfoArray[8].USSDEFirst;
    int16 DE_RR = ussecho.USSEchoInfoArray[7].USSDEFirst;    
    
}
/**
 * @brief obtain APA obs based on de value
 */
void APA_DE_trans_obs(DesayInterface_pps_USSEchoInfo ussecho, std::vector<LocationPoint> &uss_obs)
{
    LocationPoint uss_obs_temp;
    int16 DE_FLS = ussecho.USSEchoInfoArray[11].USSDEFirst;
    int16 DE_RLS = ussecho.USSEchoInfoArray[5].USSDEFirst;
    int16 DE_FRS = ussecho.USSEchoInfoArray[6].USSDEFirst;
    int16 DE_RRS = ussecho.USSEchoInfoArray[0].USSDEFirst;

}
/**
 * @brief vech_coord to world_coord
 */
void CoordinateTransformationFromBodyToWorldPos(const LocationPoint &body, LocationPoint &object)
{
    float fTheta = body.yaw;
    LocationPoint tempObject = object;
    object.x = body.x + cos(fTheta) * tempObject.x - sin(fTheta) * tempObject.y;
    object.y = body.y + sin(fTheta) * tempObject.x + cos(fTheta) * tempObject.y;
}
/**
 * @brief track obs in block area
 */
void obs_track(AlgInterface_VehPos &dr_info,std::vector<OBS_Point> &uss_obs)
{

}
/**
 * @brief calculate third point based on known two points
 */
bool GAC_USS::USS_OBS::Cal3rdPoint(std::vector<OBS_Point> SensorPoint, std::vector<float> vecDeValue, OBS_Point &thirdPoint)
{
    if (SensorPoint.size() < 2)
    {
        return false;
    }
    OBS_Point pointA = SensorPoint[0];
    OBS_Point pointB = SensorPoint[1];
    float dis_AB = getDistance(pointA, pointB);
    // angle between devalue 0 and ab
    float tempValue = (vecDeValue[0]*vecDeValue[0]+dis_AB*dis_AB-vecDeValue[1]*vecDeValue[1])/(2*vecDeValue[0]*dis_AB);

}
/**
 * @brief distance calculation function
 */
float GAC_USS::USS_OBS::getDistance(OBS_Point pointA, OBS_Point pointB)
{
    float x_diff = abs(pointA.x - pointB.x);
    float y_diff = abs(pointA.y - pointB.y);
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}
/**
 * @brief angle calculation function
 */
float getAngle(OBS_Point pointA, OBS_Point pointB)
{

}