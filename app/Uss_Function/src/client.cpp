/*
 * client.cpp
 *
 *  Created on: Jun 5, 2023
 *      Author: moxiaopeng
 */
#include "../include/client.h"
void Client::getdata(g_Input &input)
{
    input = g_input;
}

/**
 * @brief get now time function
 */
std::string Client::gettime()
{
    time_t t = time(NULL);
    struct tm *stime = localtime(&t);
    std::string nowtime = to_string(1900 + stime->tm_year) + to_string(1 + stime->tm_mon) + to_string(stime->tm_mday)+to_string(stime->tm_hour)+to_string(stime->tm_min);
    return nowtime;
}

/**
 * @brief initial function
 */
void Client::client_initial()
{
    g_input.uss_echo_txt = "USS_Echo" + gettime() + ".txt";
    GAC_USS_DATA::Data_Sub::USS_ECHO_TITLE_SETTING(g_input.uss_echo_txt);
}
/**
 * @brief message callback
 */
void Client::message_callback(int topicid, int cmdid, int size, char *pdata)
{
    g_input.ussinfo_flag = false;
    g_input.apastate_flag = false;
    g_input.caninfo_flag = false;
    std::string strLog = "";
    char chBuffer[256] = {0};
    if (topicid == TOPICID_FVUSS_DATA_APP && cmdid == CMDID_USS_USS_ALL_DATA)
    {
        g_input.ussinfo_flag = true;
        std::cout << "(call back)g_input.ussinfo_flag is " << g_input.ussinfo_flag << std::endl;
        DesayInterface_pps_USSDistForControl *uss_pdc = nullptr;
        uss_pdc = (DesayInterface_pps_USSDistForControl *)pdata;
        memcpy(&g_input.usspdc, uss_pdc, sizeof(DesayInterface_pps_USSDistForControl));
        strLog += "rec ussDistForControl Msg\n";
        sprintf(chBuffer, "MCU21STimeus:%llu\n", uss_pdc->MCU21STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30RTimeus:%llu\n", uss_pdc->MCU30RTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30STimeus:%llu\n", uss_pdc->MCU30STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCUSocTimeus:%llu\n", uss_pdc->MCUSocTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceRRS:%u\n", uss_pdc->USSDistanceRRS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceRR:%u\n", uss_pdc->USSDistanceRR);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceRRM:%u\n", uss_pdc->USSDistanceRRM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceRLM:%u\n", uss_pdc->USSDistanceRLM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceRL:%u\n", uss_pdc->USSDistanceRL);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceRLS:%u\n", uss_pdc->USSDistanceRLS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceFRS:%u\n", uss_pdc->USSDistanceFRS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceFR:%u\n", uss_pdc->USSDistanceFR);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceFRM:%u\n", uss_pdc->USSDistanceFRM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceFLM:%u\n", uss_pdc->USSDistanceFLM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceFL:%u\n", uss_pdc->USSDistanceFL);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceFLS:%u\n", uss_pdc->USSDistanceFLS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelRRS:%u\n", uss_pdc->USSDistanceLevelRRS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelRR:%u\n", uss_pdc->USSDistanceLevelRR);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelRRM:%u\n", uss_pdc->USSDistanceLevelRRM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelRLM:%u\n", uss_pdc->USSDistanceLevelRLM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelRL:%u\n", uss_pdc->USSDistanceLevelRL);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelRLS:%u\n", uss_pdc->USSDistanceLevelRLS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelFRS:%u\n", uss_pdc->USSDistanceLevelFRS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelFR:%u\n", uss_pdc->USSDistanceLevelFR);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelFRM:%u\n", uss_pdc->USSDistanceLevelFRM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelFLM:%u\n", uss_pdc->USSDistanceLevelFLM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelFL:%u\n", uss_pdc->USSDistanceLevelFL);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelFLS:%u\n", uss_pdc->USSDistanceLevelFLS);
        strLog += chBuffer;
        printf("%s", strLog.c_str());

        DesayInterface_pps_USSOBSInfo *uss_obs = nullptr;
        uss_obs = (DesayInterface_pps_USSOBSInfo *)pdata;

        strLog += "rec ussOBSInfo Msg\n";
        sprintf(chBuffer, "MCU21STimeus:%llu\n", uss_obs->MCU21STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30RTimeus:%llu\n", uss_obs->MCU30RTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30STimeus:%llu\n", uss_obs->MCU30STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCUSocTimeus:%llu\n", uss_obs->MCUSocTimeus);
        strLog += chBuffer;
        for (size_t i = 0; i < sizeof(uss_obs->USSOBSInfoArray) / sizeof(USSOBSInfoItem); i++)
        {
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjP1X:%d\n", i, uss_obs->USSOBSInfoArray[i].USSObjP1X);
            strLog += chBuffer;
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjP1Y:%d\n", i, uss_obs->USSOBSInfoArray[i].USSObjP1Y);
            strLog += chBuffer;
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjP2X:%d\n", i, uss_obs->USSOBSInfoArray[i].USSObjP2X);
            strLog += chBuffer;
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjP2Y:%d\n", i, uss_obs->USSOBSInfoArray[i].USSObjP2Y);
            strLog += chBuffer;
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjProb:%u\n", i, uss_obs->USSOBSInfoArray[i].USSObjProb);
            strLog += chBuffer;
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjType:%u\n", i, uss_obs->USSOBSInfoArray[i].USSObjType);
            strLog += chBuffer;
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjHeightStatus:%u\n", i, uss_obs->USSOBSInfoArray[i].USSObjHeightStatus);
            strLog += chBuffer;
        }
        printf("%s", strLog.c_str());

        DesayInterface_pps_USSEchoInfo *uss_echo = nullptr;
        uss_echo = (DesayInterface_pps_USSEchoInfo *)pdata;
        memcpy(&g_input.ussecho, uss_echo, sizeof(DesayInterface_pps_USSEchoInfo));

        sprintf(chBuffer, "rec ussEchoInfo Msg, size = %d\n", size);
        strLog += chBuffer;
        sprintf(chBuffer, "DesayInterface_pps_USSEchoInfo's size:%lu\n", sizeof(DesayInterface_pps_USSEchoInfo));
        strLog += chBuffer;
        sprintf(chBuffer, "MCU21STimeus:%llu\n", uss_echo->MCU21STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30RTimeus:%llu\n", uss_echo->MCU30RTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30STimeus:%llu\n", uss_echo->MCU30STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCUSocTimeus:%llu\n", uss_echo->MCUSocTimeus);
        strLog += chBuffer;
        for (size_t i = 0; i < sizeof(uss_echo->USSEchoInfoArray) / sizeof(USSEchoInfoItem); i++)
        {
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSDEFirstTimestamp:%llu\n", i, uss_echo->USSEchoInfoArray[i].USSDEFirstTimestamp);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSDEFirst:%d\n", i, uss_echo->USSEchoInfoArray[i].USSDEFirst);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSDEFirstLevel:%d\n", i, uss_echo->USSEchoInfoArray[i].USSDEFirstLevel);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSDESecondTimestamp:%llu\n", i, uss_echo->USSEchoInfoArray[i].USSDESecondTimestamp);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSDESecond:%d\n", i, uss_echo->USSEchoInfoArray[i].USSDESecond);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCELeftFirstTimestamp:%llu\n", i, uss_echo->USSEchoInfoArray[i].USSCELeftFirstTimestamp);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCELeftFirst:%d\n", i, uss_echo->USSEchoInfoArray[i].USSCELeftFirst);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCELeftFirstLevel:%d\n", i, uss_echo->USSEchoInfoArray[i].USSCELeftFirstLevel);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCELeftSecondTimestamp:%llu\n", i, uss_echo->USSEchoInfoArray[i].USSCELeftSecondTimestamp);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCELeftSecond:%d\n", i, uss_echo->USSEchoInfoArray[i].USSCELeftSecond);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCERightFirstTimestamp:%llu\n", i, uss_echo->USSEchoInfoArray[i].USSCERightFirstTimestamp);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCERightFirst:%d\n", i, uss_echo->USSEchoInfoArray[i].USSCERightFirst);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCERightFirstLevel:%d\n", i, uss_echo->USSEchoInfoArray[i].USSCERightFirstLevel);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCERightSecondTimestamp:%llu\n", i, uss_echo->USSEchoInfoArray[i].USSCERightSecondTimestamp);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCERightSecond:%d\n", i, uss_echo->USSEchoInfoArray[i].USSCERightSecond);
            strLog += chBuffer;
        }
        printf("%s", strLog.c_str());
    }
    // else if (topicid == TOPICID_FVUSS_DATA_APP && cmdid == CMDID_USS_USS_ALL_DATA)
    // {
    //     DesayInterface_pps_USSParkSlotInfo *sample = nullptr;
    //     sample = (DesayInterface_pps_USSParkSlotInfo *)pdata;

    //     strLog += "rec ussParkSlotInfo Msg\n";
    //     sprintf(chBuffer, "MCU21STimeus:%llu\n", sample->MCU21STimeus);
    //     strLog += chBuffer;
    //     sprintf(chBuffer, "MCU30RTimeus:%llu\n", sample->MCU30RTimeus);
    //     strLog += chBuffer;
    //     sprintf(chBuffer, "MCU30STimeus:%llu\n", sample->MCU30STimeus);
    //     strLog += chBuffer;
    //     sprintf(chBuffer, "MCUSocTimeus:%llu\n", sample->MCUSocTimeus);
    //     strLog += chBuffer;

    //     for (size_t i = 0; i < sizeof(sample->USSParkSlotArray) / sizeof(USSParkSlotInfoItem); i++)
    //     {
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotId:%u\n", i, sample->USSParkSlotArray[i].SlotId);
    //         strLog += chBuffer;
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotType:%u\n", i, sample->USSParkSlotArray[i].SlotType);
    //         strLog += chBuffer;
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotDepthReferance:%u\n", i, sample->USSParkSlotArray[i].SlotDepthReferance);
    //         strLog += chBuffer;
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj1X:%d\n", i, sample->USSParkSlotArray[i].SlotObj1X);
    //         strLog += chBuffer;
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj1Y:%d\n", i, sample->USSParkSlotArray[i].SlotObj1Y);
    //         strLog += chBuffer;
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj1Type:%u\n", i, sample->USSParkSlotArray[i].SlotObj1Type);
    //         strLog += chBuffer;
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj1Depth:%u\n", i, sample->USSParkSlotArray[i].SlotObj1Depth);
    //         strLog += chBuffer;
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj1Angle:%d\n", i, sample->USSParkSlotArray[i].SlotObj1Angle);
    //         strLog += chBuffer;
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj2X:%d\n", i, sample->USSParkSlotArray[i].SlotObj2X);
    //         strLog += chBuffer;
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj2Y:%d\n", i, sample->USSParkSlotArray[i].SlotObj2Y);
    //         strLog += chBuffer;
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj2Type:%u\n", i, sample->USSParkSlotArray[i].SlotObj2Type);
    //         strLog += chBuffer;
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj2Depth:%u\n", i, sample->USSParkSlotArray[i].SlotObj2Depth);
    //         strLog += chBuffer;
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj2Angle:%d\n", i, sample->USSParkSlotArray[i].SlotObj2Angle);
    //         strLog += chBuffer;
    //         sprintf(chBuffer, "USSParkSlotArray[%lu].SlotLength:%u\n", i, sample->USSParkSlotArray[i].SlotLength);
    //         strLog += chBuffer;
    //     }
    //     printf("%s", strLog.c_str());
    // }
    else if (topicid == TOPICID_GAC_APA_DR && cmdid == CMDID_APA_VEHPOS)
    {
        AlgInterface_VehPos *sample;
        sample = (AlgInterface_VehPos *)pdata;
        memcpy(&g_input.drinfo, sample, sizeof(AlgInterface_VehPos));
        g_input.dr_flag = true;
        sprintf(chBuffer, "MCU1RTimeus:%llu\n", sample->MCU1RTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCUSocTimeus:%llu\n", sample->MCUSocTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "Curv:%llu\n", sample->Curv);
        strLog += chBuffer;
        sprintf(chBuffer, "VehPosX:%llu\n", sample->VehPosX);
        strLog += chBuffer;
        sprintf(chBuffer, "VehPosY:%llu\n", sample->VehPosY);
        strLog += chBuffer;
        sprintf(chBuffer, "VehPosYaw:%llu\n", sample->VehPosYaw);
        strLog += chBuffer;
        printf("%s", strLog.c_str());
    }
    else if (topicid == TOPICID_GAC_VEH_STATE_EST && cmdid == CMDID_ESTVEHSTATE)
    {
        AlgInterface_EstVehState *sample;
        sample = (AlgInterface_EstVehState *)pdata;
        sprintf(chBuffer, "EstFLSpd:%llu\n", sample->EstFLSpd);
        strLog += chBuffer;
        sprintf(chBuffer, "EstFRSpd:%llu\n", sample->EstFRSpd);
        strLog += chBuffer;
        sprintf(chBuffer, "EstRLSpd:%llu\n", sample->EstRLSpd);
        strLog += chBuffer;
        sprintf(chBuffer, "EstRRSpd:%llu\n", sample->EstRRSpd);
        strLog += chBuffer;
        printf("%s", strLog.c_str());
    }
    else if (topicid == TOPICID_APA_STATE_MACHINE && cmdid == CMDID_APASM_APA_ST)
    {
        AlgInterface_APASMAPASt *sample;
        sample = (AlgInterface_APASMAPASt *)pdata;
        memcpy(&g_input.apastate, sample, sizeof(AlgInterface_APASMAPASt));
        g_input.apastate_flag = true;
        sprintf(chBuffer, "APAState:%llu\n", sample->APAState);
        strLog += chBuffer;
        printf("%s", strLog.c_str());
    }
    else if (topicid == TOPICID_GAC_CAN_RX && cmdid == CMDID_GAC_CAN_RX_20_MS)
    {
        AlgInterface_IdtCanSignalRx20ms *sample;
        sample = (AlgInterface_IdtCanSignalRx20ms *)pdata;
        memcpy(&g_input.caninfo, sample, sizeof(AlgInterface_IdtCanSignalRx20ms));
        g_input.caninfo_flag = true;
        strLog += "rec CAC_CAN_RX Msg\n";
        sprintf(chBuffer, "MCU1RTimeus:%llu\n", sample->MCU1RTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU1STimeus:%llu\n", sample->MCU1STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU3RTimeus:%llu\n", sample->MCU3RTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU3STimeus:%llu\n", sample->MCU3STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCUSocTimeus:%llu\n", sample->MCUSocTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "SteeringAngleVD:%llu\n", sample->SteeringAngleVD);
        strLog += chBuffer;
        sprintf(chBuffer, "SteeringAngle:%llu\n", sample->SteeringAngle);
        strLog += chBuffer;
        sprintf(chBuffer, "CurrentGearStVD:%llu\n", sample->CurrentGearStVD);
        strLog += chBuffer;
        sprintf(chBuffer, "CurrentGearSt:%llu\n", sample->CurrentGearSt);
        strLog += chBuffer;
        sprintf(chBuffer, "FLWheelSpdVD:%llu\n", sample->FLWheelSpdVD);
        strLog += chBuffer;
        sprintf(chBuffer, "FLWheelSpd:%llu\n", sample->FLWheelSpd);
        strLog += chBuffer;
        sprintf(chBuffer, "FRWheelSpdVD:%llu\n", sample->FRWheelSpdVD);
        strLog += chBuffer;
        sprintf(chBuffer, "FRWheelSpd:%llu\n", sample->FRWheelSpd);
        strLog += chBuffer;
        sprintf(chBuffer, "RLWheelSpdVD:%llu\n", sample->RLWheelSpdVD);
        strLog += chBuffer;
        sprintf(chBuffer, "RLWheelSpd:%llu\n", sample->RLWheelSpd);
        strLog += chBuffer;
        sprintf(chBuffer, "RRWheelSpdVD:%llu\n", sample->RRWheelSpdVD);
        strLog += chBuffer;
        sprintf(chBuffer, "RRWheelSpd:%llu\n", sample->RRWheelSpd);
        strLog += chBuffer;
        sprintf(chBuffer, "BrkPedalSt:%llu\n", sample->BrkPedalSt);
        strLog += chBuffer;
    }
}
