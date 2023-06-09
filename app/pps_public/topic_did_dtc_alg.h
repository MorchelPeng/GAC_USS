#pragma once
#include "ppscontrol.h"
#include "app_pps_protocal.h"

class Topic_Did_Dtc_Req_ALG_class {
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
        DESY::PPS_CFG_STRU cfg={TOPICID_DID_DTC_REQ_ALG,"DID_DTC_Alg_Data",16,issub,ispub,15,300};
        return cfg;
    }
};

typedef enum {
    CMDID_DTC_REQ_HOLO = 0,          // Alg_pps_dtc_req
    CMDID_DID_REQ_HOLO = 1,           // Alg_pps_did_req
    CMDID_DTC_REQ_MOTOVIS = 2,          // Alg_pps_dtc_req
    CMDID_DID_REQ_MOTOVIS = 3,           // Alg_pps_did_req
    CMDID_DID_DTC_REQ_ENUM_MAX

} CMDID_DID_DTC_REQ_ALG_ENUM;

class Alg_pps_dtc_req{
public:
	DEY_Octet ucharDtcNumber[8];		//DTC number
    DEY_Octet ucharData;				//data
};

class Alg_pps_did_req{
public:
	DEY_Long  ucharDidNumber;		    //DID number
    DEY_Octet ucharlength;				//data length
    DEY_Octet ucharData[128];			//data JIANXIAO
};

