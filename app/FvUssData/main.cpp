
#include <thread>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include "topic_fvUssData.h"


extern "C"{
	int32_t appLogGlobalTimeInit();
	uint64_t appLogGetGlobalTimeInUsec();
}


static DESY::ppscontrol  *m_ppsctrl;
static DESY::PPS_CFG_STRU g_ppscfg[] = {
    TopicFvUssData::cfg(1,0),
};
static void message_callback(int topicid,int cmdid,int size,char *pdata);

int main() 
{
    appLogGlobalTimeInit();

    m_ppsctrl = DESY::ppscontrol::Instance(g_ppscfg,sizeof(g_ppscfg)/sizeof(g_ppscfg[0]));
    DESY::ppscontrol::Instance()->registerCallback(message_callback);

    for (;;) {
        pause();
    }
}

void message_callback(int topicid, int cmdid, int size, char *pdata) 
{
    std::string strLog = "";
    char chBuffer[256] = { 0 };
    if(topicid == TOPICID_FVUSS_DATA_APP && cmdid == CMDID_USS_DIST_FOR_CONTROL)
    {
        DesayInterface_pps_USSDistForControl* sample = nullptr;
        sample = (DesayInterface_pps_USSDistForControl*)pdata;
        
        strLog += "rec ussDistForControl Msg\n";
        sprintf(chBuffer, "MCU21STimeus:%llu\n", sample->MCU21STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30RTimeus:%llu\n", sample->MCU30RTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30STimeus:%llu\n", sample->MCU30STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCUSocTimeus:%llu\n", sample->MCUSocTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceRRS:%u\n", sample->USSDistanceRRS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceRR:%u\n", sample->USSDistanceRR);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceRRM:%u\n", sample->USSDistanceRRM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceRLM:%u\n", sample->USSDistanceRLM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceRL:%u\n", sample->USSDistanceRL);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceRLS:%u\n", sample->USSDistanceRLS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceFRS:%u\n", sample->USSDistanceFRS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceFR:%u\n", sample->USSDistanceFR);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceFRM:%u\n", sample->USSDistanceFRM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceFLM:%u\n", sample->USSDistanceFLM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceFL:%u\n", sample->USSDistanceFL);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceFLS:%u\n", sample->USSDistanceFLS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelRRS:%u\n", sample->USSDistanceLevelRRS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelRR:%u\n", sample->USSDistanceLevelRR);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelRRM:%u\n", sample->USSDistanceLevelRRM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelRLM:%u\n", sample->USSDistanceLevelRLM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelRL:%u\n", sample->USSDistanceLevelRL);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelRLS:%u\n", sample->USSDistanceLevelRLS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelFRS:%u\n", sample->USSDistanceLevelFRS);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelFR:%u\n", sample->USSDistanceLevelFR);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelFRM:%u\n", sample->USSDistanceLevelFRM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelFLM:%u\n", sample->USSDistanceLevelFLM);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelFL:%u\n", sample->USSDistanceLevelFL);
        strLog += chBuffer;
        sprintf(chBuffer, "USSDistanceLevelFLS:%u\n", sample->USSDistanceLevelFLS);
        strLog += chBuffer;
        printf("%s", strLog.c_str());
    }
    else if (topicid == TOPICID_FVUSS_DATA_APP && cmdid == CMDID_USS_OBS_INFO)
    {
        DesayInterface_pps_USSOBSInfo* sample = nullptr;
        sample = (DesayInterface_pps_USSOBSInfo*)pdata;

        strLog += "rec ussOBSInfo Msg\n";
        sprintf(chBuffer, "MCU21STimeus:%llu\n", sample->MCU21STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30RTimeus:%llu\n", sample->MCU30RTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30STimeus:%llu\n", sample->MCU30STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCUSocTimeus:%llu\n", sample->MCUSocTimeus);
        strLog += chBuffer;
        for (size_t i = 0; i < sizeof(sample->USSOBSInfoArray) / sizeof(USSOBSInfoItem); i++)
        {
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjP1X:%d\n", i, sample->USSOBSInfoArray[i].USSObjP1X);
            strLog += chBuffer;
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjP1Y:%d\n", i, sample->USSOBSInfoArray[i].USSObjP1Y);
            strLog += chBuffer;
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjP2X:%d\n", i, sample->USSOBSInfoArray[i].USSObjP2X);
            strLog += chBuffer;
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjP2Y:%d\n", i, sample->USSOBSInfoArray[i].USSObjP2Y);
            strLog += chBuffer;
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjProb:%u\n", i, sample->USSOBSInfoArray[i].USSObjProb);
            strLog += chBuffer;
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjType:%u\n", i, sample->USSOBSInfoArray[i].USSObjType);
            strLog += chBuffer;
            sprintf(chBuffer, "USSOBSInfoArray[%lu].USSObjHeightStatus:%u\n", i, sample->USSOBSInfoArray[i].USSObjHeightStatus);
            strLog += chBuffer;
        }
        printf("%s", strLog.c_str());
    }
    else if (topicid == TOPICID_FVUSS_DATA_APP && cmdid == CMDID_USS_PARK_SLOT_INFO)
    {
        DesayInterface_pps_USSParkSlotInfo* sample = nullptr;
        sample = (DesayInterface_pps_USSParkSlotInfo*)pdata;

        strLog += "rec ussParkSlotInfo Msg\n";
        sprintf(chBuffer, "MCU21STimeus:%llu\n", sample->MCU21STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30RTimeus:%llu\n", sample->MCU30RTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30STimeus:%llu\n", sample->MCU30STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCUSocTimeus:%llu\n", sample->MCUSocTimeus);
        strLog += chBuffer;

        for (size_t i = 0; i < sizeof(sample->USSParkSlotArray) / sizeof(USSParkSlotInfoItem); i++)
        {
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotId:%u\n", i, sample->USSParkSlotArray[i].SlotId);
            strLog += chBuffer;
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotType:%u\n", i, sample->USSParkSlotArray[i].SlotType);
            strLog += chBuffer;
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotDepthReferance:%u\n", i, sample->USSParkSlotArray[i].SlotDepthReferance);
            strLog += chBuffer;
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj1X:%d\n", i, sample->USSParkSlotArray[i].SlotObj1X);
            strLog += chBuffer;
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj1Y:%d\n", i, sample->USSParkSlotArray[i].SlotObj1Y);
            strLog += chBuffer;
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj1Type:%u\n", i, sample->USSParkSlotArray[i].SlotObj1Type);
            strLog += chBuffer;
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj1Depth:%u\n", i, sample->USSParkSlotArray[i].SlotObj1Depth);
            strLog += chBuffer;
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj1Angle:%d\n", i, sample->USSParkSlotArray[i].SlotObj1Angle);
            strLog += chBuffer;
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj2X:%d\n", i, sample->USSParkSlotArray[i].SlotObj2X);
            strLog += chBuffer;
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj2Y:%d\n", i, sample->USSParkSlotArray[i].SlotObj2Y);
            strLog += chBuffer;
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj2Type:%u\n", i, sample->USSParkSlotArray[i].SlotObj2Type);
            strLog += chBuffer;
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj2Depth:%u\n", i, sample->USSParkSlotArray[i].SlotObj2Depth);
            strLog += chBuffer;
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotObj2Angle:%d\n", i, sample->USSParkSlotArray[i].SlotObj2Angle);
            strLog += chBuffer;
            sprintf(chBuffer, "USSParkSlotArray[%lu].SlotLength:%u\n", i, sample->USSParkSlotArray[i].SlotLength);
            strLog += chBuffer;
        }
        printf("%s", strLog.c_str());
    }
    else if (topicid == TOPICID_FVUSS_DATA_APP && cmdid == CMDID_USS_ECHO_INFO)
    {
        DesayInterface_pps_USSEchoInfo* sample = nullptr;
        sample = (DesayInterface_pps_USSEchoInfo*)pdata;

        sprintf(chBuffer, "rec ussEchoInfo Msg, size = %d\n", size);
        strLog += chBuffer;
        sprintf(chBuffer, "DesayInterface_pps_USSEchoInfo's size:%lu\n", sizeof(DesayInterface_pps_USSEchoInfo));
        strLog += chBuffer;
        sprintf(chBuffer, "MCU21STimeus:%llu\n", sample->MCU21STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30RTimeus:%llu\n", sample->MCU30RTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30STimeus:%llu\n", sample->MCU30STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCUSocTimeus:%llu\n", sample->MCUSocTimeus);
        strLog += chBuffer;
        for (size_t i = 0; i < sizeof(sample->USSEchoInfoArray) / sizeof(USSEchoInfoItem); i++)
        {
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSDEFirstTimestamp:%llu\n", i, sample->USSEchoInfoArray[i].USSDEFirstTimestamp);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSDEFirst:%d\n", i, sample->USSEchoInfoArray[i].USSDEFirst);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSDEFirstLevel:%d\n", i, sample->USSEchoInfoArray[i].USSDEFirstLevel);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSDESecondTimestamp:%llu\n", i, sample->USSEchoInfoArray[i].USSDESecondTimestamp);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSDESecond:%d\n", i, sample->USSEchoInfoArray[i].USSDESecond);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCELeftFirstTimestamp:%llu\n", i, sample->USSEchoInfoArray[i].USSCELeftFirstTimestamp);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCELeftFirst:%d\n", i, sample->USSEchoInfoArray[i].USSCELeftFirst);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCELeftFirstLevel:%d\n", i, sample->USSEchoInfoArray[i].USSCELeftFirstLevel);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCELeftSecondTimestamp:%llu\n", i, sample->USSEchoInfoArray[i].USSCELeftSecondTimestamp);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCELeftSecond:%d\n", i, sample->USSEchoInfoArray[i].USSCELeftSecond);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCERightFirstTimestamp:%llu\n", i, sample->USSEchoInfoArray[i].USSCERightFirstTimestamp);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCERightFirst:%d\n", i, sample->USSEchoInfoArray[i].USSCERightFirst);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCERightFirstLevel:%d\n", i, sample->USSEchoInfoArray[i].USSCERightFirstLevel);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCERightSecondTimestamp:%llu\n", i, sample->USSEchoInfoArray[i].USSCERightSecondTimestamp);
            strLog += chBuffer;
            sprintf(chBuffer, "USSEchoInfoArray[%lu].USSCERightSecond:%d\n", i, sample->USSEchoInfoArray[i].USSCERightSecond);
            strLog += chBuffer;
        }
        printf("%s", strLog.c_str());
    }
    else if (topicid == TOPICID_FVUSS_DATA_APP && cmdid == CMDID_USS_Refresh_ABPiont)
    {
        DesayInterface_pps_USSRefreshABPiont* sample = nullptr;
        sample = (DesayInterface_pps_USSRefreshABPiont*)pdata;
        
        strLog += "rec ussRefreshABPiont Msg\n";
        sprintf(chBuffer, "SlotUpdatePtAFlag:%u\n", sample->SlotUpdatePtAFlag);
        strLog += chBuffer;
        sprintf(chBuffer, "SlotUpdatePtAx:%.2f\n", sample->SlotUpdatePtAx);
        strLog += chBuffer;
        sprintf(chBuffer, "SlotUpdatePtAy:%.2f\n", sample->SlotUpdatePtAy);
        strLog += chBuffer;
        sprintf(chBuffer, "SlotUpdatePtBFlag:%u\n", sample->SlotUpdatePtBFlag);
        strLog += chBuffer;
        sprintf(chBuffer, "SlotUpdatePtBx:%.2f\n", sample->SlotUpdatePtBx);
        strLog += chBuffer;
        sprintf(chBuffer, "SlotUpdatePtBy:%.2f\n", sample->SlotUpdatePtBy);
        strLog += chBuffer;
        
        printf("%s", strLog.c_str());
    }
    else if (topicid == TOPICID_FVUSS_DATA_APP && cmdid == CMDID_USS_USSGLOOBSRangeInfo)
    {
        DesayInterface_pps_USSGLOOBSRangeInfo* sample = nullptr;
        sample = (DesayInterface_pps_USSGLOOBSRangeInfo*)pdata;

        sprintf(chBuffer, "rec USSGLOOBSRangeInfo Msg, size = %u\n", size);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU21STimeus:%llu\n", sample->MCU21STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30RTimeus:%llu\n", sample->MCU30RTimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCU30STimeus:%llu\n", sample->MCU30STimeus);
        strLog += chBuffer;
        sprintf(chBuffer, "MCUSocTimeus:%llu\n", sample->MCUSocTimeus);
        strLog += chBuffer;
        for (size_t i = 0; i < GLO_MAX; i++)
        {
            sprintf(chBuffer, "GLOSnsObj[%lu].num:%u\n", i, sample->GLOSnsObj[i].num);
            strLog += chBuffer;
            for (size_t j = 0; j < sizeof(sample->GLOSnsObj[i].point) / sizeof(USSGLOOBSPoint); j++)
            {
                sprintf(chBuffer, "GLOSnsObj[%lu].point[%lu].x:%.02f\n", i, j, sample->GLOSnsObj[i].point[j].x);
                strLog += chBuffer;
                sprintf(chBuffer, "GLOSnsObj[%lu].point[%lu].y:%.02f\n", i, j, sample->GLOSnsObj[i].point[j].y);
                strLog += chBuffer;
                sprintf(chBuffer, "GLOSnsObj[%lu].point[%lu].type:%u\n", i, j, sample->GLOSnsObj[i].point[j].type);
                strLog += chBuffer;
            }
        }
        printf("%s", strLog.c_str());
    }
}


