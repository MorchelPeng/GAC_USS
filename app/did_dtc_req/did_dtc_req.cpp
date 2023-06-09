#include <unistd.h>
#include <iostream>
#include <thread>
#include <string.h>
#include "../pps_public/topic_did_dtc_req.h"
#include "../pps_public/app_pps_protocal.h"
#include "../pps_public/ppscontrol.h"
#include "../pps_public/topic_power_management.h"

extern "C"{
    int32_t appLogGlobalTimeInit();
    uint64_t appLogGetGlobalTimeInUsec();
}

static DESY::ppscontrol  *m_ppsctrl;
static DESY::PPS_CFG_STRU g_ppscfg[] = {
    Topic_Did_Dtc_Req_class::cfg(1,1),
    TopicPowerOffDelayManagement::cfg(1,1)
};

static void message_callback(int topicid,int cmdid,int size,char *pdata);
void PPSSendDtcData();
void PPSSendPowerOffDelayData();

int main() {
    m_ppsctrl = DESY::ppscontrol::Instance(g_ppscfg,sizeof(g_ppscfg)/sizeof(g_ppscfg[0]));
    // A72->算法->算法处理完成->A72
    DESY::ppscontrol::Instance()->registerCallback(message_callback);
    // 算法->A72
    
    while (true)
    {
        #if 1
        // PPSSendDtcData();
        #endif
        sleep(3);//休眠3秒
    }
    
    return 0;
    
}

void message_callback(int topicid, int cmdid, int size, char *pdata) {  
    printf("Enter message_callback()\n");
    // 接收到DID请求
    if (topicid == TOPICID_DID_DTC_REQ_APP && cmdid == CMDID_DID_REQ)
    {
        DesayInterface_pps_did_req* pDidReq = (DesayInterface_pps_did_req*)pdata;

        if (pDidReq->ucharDidNumber == 0x033801)
        {
            /***************************************/
            /*            此处添加算法实现            */
            /***************************************/
            //实现后填充结果
            pDidReq->ucharlength = 4;
            pDidReq->ucharData[0] = 0x00;
            pDidReq->ucharData[1] = 0x01;
            pDidReq->ucharData[2] = 0x00;
            pDidReq->ucharData[3] = 0x00;
        }
        else if (pDidReq->ucharDidNumber == 0x013801)
        {
            /***************************************/
            /*            此处添加算法实现            */
            /***************************************/
            //实现后填充结果
            pDidReq->ucharlength = 4;
            pDidReq->ucharData[0] = 0x00;
            pDidReq->ucharData[1] = 0x01;
            pDidReq->ucharData[2] = 0x02;
            pDidReq->ucharData[3] = 0x03;
        }
        else if (pDidReq->ucharDidNumber == 0x033802)
        {
            /***************************************/
            /*            此处添加算法实现            */
            /***************************************/
            //实现后填充结果
            pDidReq->ucharlength = 4;
            pDidReq->ucharData[0] = 0x01;
            pDidReq->ucharData[1] = 0x02;
            pDidReq->ucharData[2] = 0x03;
            pDidReq->ucharData[3] = 0x04;
        }  
        else if (pDidReq->ucharDidNumber == 0x2E0308)
        {
            /***************************************/
            /*            此处添加算法实现            */
            /***************************************/
            //实现后填充结果
            pDidReq->ucharlength = 0;           
        }
        else if (pDidReq->ucharDidNumber == 0x220304)
        {
            /***************************************/
            /*            此处添加算法实现            */
            /***************************************/
            //实现后填充结果
            pDidReq->ucharlength = 8;
            pDidReq->ucharData[0] = 0x00;
            pDidReq->ucharData[1] = 0x01;
            pDidReq->ucharData[2] = 0x00;
            pDidReq->ucharData[3] = 0x01;
            pDidReq->ucharData[4] = 0x00;
            pDidReq->ucharData[5] = 0x01;
            pDidReq->ucharData[6] = 0x00;
            pDidReq->ucharData[7] = 0x01;
        }
        else if (pDidReq->ucharDidNumber == 0x22F184)
        {
            /***************************************/
            /*            此处添加算法实现            */
            /***************************************/
            //实现后填充结果
            pDidReq->ucharlength = 10;
            pDidReq->ucharData[0] = 0x00;
            pDidReq->ucharData[1] = 0x01;
            pDidReq->ucharData[2] = 0x02;
            pDidReq->ucharData[3] = 0x03;
            pDidReq->ucharData[4] = 0x04;
            pDidReq->ucharData[5] = 0x05;
            pDidReq->ucharData[6] = 0x06;
            pDidReq->ucharData[7] = 0x07;
            pDidReq->ucharData[8] = 0x08;
            pDidReq->ucharData[9] = 0x09;
        }
        else if (pDidReq->ucharDidNumber == 0x222100)
        {
            /***************************************/
            /*            此处添加算法实现            */
            /***************************************/
            //实现后填充结果
            pDidReq->ucharlength = 1;
            pDidReq->ucharData[0] = 0x01;
        }
        else if (pDidReq->ucharDidNumber == 0x220300)
        {
            /***************************************/
            /*            此处添加算法实现            */
            /***************************************/
            //实现后填充结果
            pDidReq->ucharlength = 60;
            for (size_t i = 0; i < pDidReq->ucharlength; i++)
            {
                pDidReq->ucharData[i] = i;
            }      
        }   
        else
        {
            printf("Unknowned DID number:0x%X\n", pDidReq->ucharDidNumber);
            printf("Exit message_callback()\n");
            return;
        }
        printf("Publish data\n");
        m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DID_REQ_2,sizeof(DesayInterface_pps_did_req), (char*)pDidReq);
        //sleep(1);//休眠一秒
    }
    else if (topicid == TOPICID_DID_DTC_REQ_APP && cmdid == CMDID_DID_REQ_REPO_COUNTER)
    {
        DesayInterface_pps_did_req_repo_counter* pRepoCounter = (DesayInterface_pps_did_req_repo_counter*)pdata;
        pRepoCounter->ushortData = 1000;
        m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DID_REQ_REPO_COUNTER,sizeof(DesayInterface_pps_did_req_repo_counter), (char*)pRepoCounter);
    }
    else if (topicid == TOPICID_POWER_OFF_DELAY && cmdid == CMDID_POWER_OFF_DELAY_RESPOND)
    {
        printf("Receive TOPICID_POWER_OFF_DELAY CMDID_POWER_OFF_DELAY_RESPOND\n");
        DesayInterface_pps_PowerOffDelayManagement* pPowerOffDelay = (DesayInterface_pps_PowerOffDelayManagement*)pdata;
        if (pPowerOffDelay->pwroff_delay_respond == 1)// 即将断电
        {  
            DesayInterface_pps_PowerOffDelayManagement powerOffDelayData = { 0 };
            for (size_t i = 0; i < 10; i++)
            {
                if (i < 5)
                {
                    powerOffDelayData.pwroff_delay_request = 1;
                }
                else if (i >= 5)
                {
                    powerOffDelayData.pwroff_delay_request = 0;
                }
                
                m_ppsctrl->publish(TOPICID_POWER_OFF_DELAY, CMDID_POWER_OFF_DELAY_REQUEST,
                                    sizeof(DesayInterface_pps_PowerOffDelayManagement), (char*)&powerOffDelayData);
                sleep(1);
            }
        }
    }
    printf("Exit message_callback()\n");
}

void PPSSendDtcData() 
{
    printf("Enter PPSSendDtcData()\n");

    /***************************************/
    /*            此处添加算法实现            */
    /***************************************/
    //实现后填充DTC数据
    DesayInterface_pps_dtc_req dtcTestData;
    
    memccpy(dtcTestData.ucharDtcNumber, "B272305", 0, sizeof("B272305"));
    dtcTestData.ucharData = 0;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272306", 0, sizeof("B272306"));
    dtcTestData.ucharData = 1;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272307", 0, sizeof("B272307"));
    dtcTestData.ucharData = 2;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272308", 0, sizeof("B272308"));
    dtcTestData.ucharData = 0;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272309", 0, sizeof("B272309"));
    dtcTestData.ucharData = 1;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272E20", 0, sizeof("B272E20"));
    dtcTestData.ucharData = 2;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272E21", 0, sizeof("B272E21"));
    dtcTestData.ucharData = 0;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272E22", 0, sizeof("B272E22"));
    dtcTestData.ucharData = 1;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272E23", 0, sizeof("B272E23"));
    dtcTestData.ucharData = 2;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272E24", 0, sizeof("B272E24"));
    dtcTestData.ucharData = 0;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272E25", 0, sizeof("B272E25"));
    dtcTestData.ucharData = 1;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272E26", 0, sizeof("B272E26"));
    dtcTestData.ucharData = 2;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272E27", 0, sizeof("B272E27"));
    dtcTestData.ucharData = 0;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272E28", 0, sizeof("B272E28"));
    dtcTestData.ucharData = 1;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B272E29", 0, sizeof("B272E29"));
    dtcTestData.ucharData = 2;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B270120", 0, sizeof("B270120"));
    dtcTestData.ucharData = 2;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    memset(&dtcTestData, 0, sizeof(DesayInterface_pps_dtc_req));
    memccpy(dtcTestData.ucharDtcNumber, "B273350", 0, sizeof("B273350"));
    dtcTestData.ucharData = 2;
    m_ppsctrl->publish(TOPICID_DID_DTC_REQ_APP, CMDID_DTC_REQ,sizeof(DesayInterface_pps_dtc_req), (char*)&dtcTestData);
    sleep(1);//休眠一秒

    printf("Exit PPSSendDtcData()\n");
}
