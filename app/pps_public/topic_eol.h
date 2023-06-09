#ifndef _TOPIC_EOL_H_
#define _TOPIC_EOL_H_

#include "app_pps_protocal.h"
// #include "pps_protocal.h"
#include "ppscontrol.h"

class TopicEolResponse {
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub) {
        DESY::PPS_CFG_STRU cfg = {TOPICID_eol_mcu_data, "eol_mcu_data", 4, issub, ispub, 4, 5120};
        return cfg;
    }
};

class TopicEolRequest {
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub) {
        DESY::PPS_CFG_STRU cfg = {TOPICID_eol_app_data, "eol_app_data", 4, issub, ispub, 4, 5120};
        return cfg;
    }
};

/*begin TOPICID_eol_mcu_data cmdid and cmddata define.*/
class DesayInterface_pps_MCUEolResponse 
{
public:
    DEY_Octet   source ;
    DEY_Octet   destination ;
    DEY_Octet   resp_EolModuleID ;
    DEY_Octet   resp_EolCommandID ;
    DEY_UnsignedShort   resp_EolCommandLength ;
    DEY_Octet   resp_EolCommandData [512];
    DEY_Octet   resp_EolCommandCS ;

};

class DesayInterface_pps_AppEolRequest 
{
public:
    DEY_Octet   source ;
    DEY_Octet   destination ;
    DEY_Octet   req_EolModuleID ;
    DEY_Octet   req_EolCommandID ;
    DEY_UnsignedShort   req_EolCommandLength ;
    DEY_Octet   req_EolCommandData [512];
    DEY_Octet   req_EolCommandCS ;

};

class DesayInterface_pps_DsvIpcSpiData 
{
public:
    DEY_Octet   FlcSpiNum ;
    DEY_Octet   SpiDataFromIpc [1000];

};

typedef enum CMDID_IN_TOPICID_eol_mcu_data
{
    CMDID_eol_mcu_data		= 0,
    CMDID_eol_mcu_ver       = 1
} CMDID_IN_TOPICID_eol_mcu_data_ENUM;
	
typedef struct DesayInterface_pps_TOPICID_eol_mcu_data_u 
{
	DesayInterface_pps_MCUEolResponse	eol_mcu_data;
}DesayInterface_pps_TOPICID_eol_mcu_data_stru;
/*end TOPICID_eol_mcu_data*/


/*begin TOPICID_eol_app cmdid and cmddata define.*/
typedef enum CMDID_IN_TOPICID_eol_app_data
{
    CMDID_eol_app_data		= 0
} CMDID_IN_TOPICID_eol_app_data_ENUM;
	
typedef struct DesayInterface_pps_TOTOPICID_eol_app_data_u 
{
	DesayInterface_pps_AppEolRequest	eol_app_data;
}DesayInterface_pps_TOPICID_eol_app_data_stru;
/*end TOPICID_eol_app*/

/*TOPICID_EOL_AVM_APP*/
typedef enum CMDID_IN_EOL_APP
{
    CMDID_EOL_AVM_REQ ,
//    CMDID_EOL_AVM_RESP ,
    CMDID_EOL_VER_REQ
//    CMDID_EOL_VER_RESP
} CMDID_IN_EOL_APP_ENUM;

/*TOPICID_APP_RESP_EOL*/
typedef enum CMDID_IN_EOL_RESP_APP
{
    CMDID_EOL_AVM_RESP ,
    CMDID_EOL_VER_RESP
} CMDID_IN_EOL_RESP_APP_ENUM;

class EolAvmRequest {
public:
    // 0 :    no request
    // 1 :    2D Front
    // 2 :    2D Rear
    // 3 :    Front Wide
    // 4 :    Rear Wide
    // 5 :    Left Wide
    // 6 :    Right Wide
    // 7 :    Close Wide Angle View
    char avmViewReq;
    EolAvmRequest()
    {
        avmViewReq=0;
    }
};

// AVM --> eol_app
// topic: "eol_avm_response"
class EolAvmResponse {
public:
    // 0 :    no request
    // 1 :    2D Front
    // 2 :    2D Rear
    // 3 :    Front Wide
    // 4 :    Rear Wide
    // 5 :    Left Wide
    // 6 :    Right Wide
    // 7 :    Close Wide Angle View
    char avmViewReq;
    // 0 : Success
    // 1 : Failure
    char avmSwitchResp;
    EolAvmResponse()
    {
        avmViewReq=0;
        avmSwitchResp=0;
    }
};

// eol_app --> avm3d_app
// topic: "eol_ver_request"
class EolVerRequest {
public:
    // 0 :    no request
    // 1 :    MCU3_0 version request
    char versionReq;
    EolVerRequest()
    {
        versionReq=0;
    }
};

// avm3d_app --> eol_app
// topic: "eol_ver_response"
class EolVerResponse {
public:
    char versionMCU3_0[32];
    EolVerResponse()
    {
        memset(versionMCU3_0,0x0,sizeof(versionMCU3_0));
    }
    const EolVerResponse& operator =(EolVerResponse & data)
    {
        memcpy(versionMCU3_0,data.versionMCU3_0,sizeof(versionMCU3_0));
        return *this;
    }
};

static const char * const  DDS_TOPIC_EOL_REQUEST = "eol_request";
static const char * const  DDS_TOPIC_EOL_RESPONSE = "eol_response";
static const char * const  DDS_TOPIC_UDS_COMMON_REQUEST = "app_uds_common_request";
static const char * const  DDS_TOPIC_UDS_COMMON_RESPONSE = "app_uds_common_response";

const unsigned short EOL_MAX_DATA_LEN = 512;

#pragma pack(push, 1)
class EolCmdData {
public:
    uint8_t mainCmd;
    uint8_t subCmd;
    uint16_t dataLength;
    uint8_t data[EOL_MAX_DATA_LEN];
    uint8_t cs;
    EolCmdData() {
        mainCmd = 0;
        subCmd = 0;
        dataLength = 0;
        memset(data, 0x0, sizeof(data));
        cs = 0;
    }
    const EolCmdData& operator=(const EolCmdData& msg) {
        mainCmd = msg.mainCmd;
        subCmd = msg.subCmd;
        dataLength = msg.dataLength;
        memcpy(data, msg.data, sizeof(data));
        cs = msg.cs;
        return *this;
    }
};
#pragma pack(pop)


#endif  // _TOPIC_EOL_H_
