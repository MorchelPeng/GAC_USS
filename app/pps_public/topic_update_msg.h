#ifndef TOPIC_UPDATE_MSG
#define TOPIC_UPDATE_MSG

#include "ppscontrol.h"
#include "app_pps_protocal.h"

//typedef	enum TOPIC_ID_APP_DEFINE
//{
//    // TOPICID_AVM_GUI_APP             = 202,//guiGenMsg
//    TOPICID_UPDATE_MSG              = 213,//updateMsg
//}TOPIC_ID_APP_DEFINE_ENUM;

//TOPICID_UPDATE_MSG = 213

class TopicUptateMsg
{
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
        DESY::PPS_CFG_STRU cfg={TOPICID_UPDATE_MSG,"updateMsg",16,issub,ispub,15,300};
        return cfg;
    }

    static DESY::PPS_CFG_EX cfg_ex(int issub, int ispub)
    {
        DESY::PPS_CFG_EX cfg_ex={TOPICID_UPDATE_MSG,"updateMsg",16,issub,ispub,15,300};
        return cfg_ex;
    }
};

// typedef enum
// {
//     CMDID_UPDATE_MSG	= 0, //DesayInterface_pps_VehicleData
// 	CMDID_UPDATE_MSG_MAX
// } CMDID_IN_UPDATE_MSG_ENUM;

class PPSUpdateMsg{
public:
   char updateModul[32];
   unsigned short updateProcess;
   PPSUpdateMsg()
   {
       memset(updateModul,0x0,sizeof(updateModul));
       updateProcess=0;
   }
   const PPSUpdateMsg & operator =(const PPSUpdateMsg& data)
   {
       memcpy(updateModul,data.updateModul,sizeof(updateModul));
       updateProcess=data.updateProcess;
       return *this;
   }
};

#endif
