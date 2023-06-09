#pragma once
#include "ppscontrol.h"
#include "app_pps_protocal.h"

class Topic_Did_Dtc_Req_class {
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
        DESY::PPS_CFG_STRU cfg={TOPICID_DID_DTC_REQ_APP,"DID_DTC_Req_Data",16,issub,ispub,15,300};
        return cfg;
    }
};

typedef enum {
    CMDID_DTC_REQ = 0,              // DesayInterface_pps_dtc_req
    CMDID_DID_REQ = 1,              // DesayInterface_pps_did_req DESAY To GAC
    CMDID_DID_REQ_2 = 2,            // DesayInterface_pps_did_req GAC To DESAY
    CMDID_DID_REQ_REPO_COUNTER = 3  // DesayInterface_pps_did_req_repo_counter
} CMDID_DID_DTC_REQ_ENUM;

class DesayInterface_pps_dtc_req{
public:
	DEY_Octet ucharDtcNumber[8];		//DTC number
    DEY_Octet ucharData;				//data
};

class DesayInterface_pps_did_req{
public:
	DEY_Long  ucharDidNumber;		    //DID number
    DEY_Octet ucharlength;				//data length
    DEY_Octet ucharData[128];			//data
};

class DesayInterface_pps_did_req_repo_counter{
public:
	DEY_Long  ucharDidNumber;		    // DID number
    DEY_UnsignedShort ushortData;       // data
};
