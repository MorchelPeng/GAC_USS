#ifndef TOPIC_UNIVERSAL_CAN_SIGNAL_TX_H
#define TOPIC_UNIVERSAL_CAN_SIGNAL_TX_H

#include "ppscontrol.h"
#include "app_pps_protocal.h"

class TopicUniversalCanSignalTx
{
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
        DESY::PPS_CFG_STRU cfg={TOPICID_UNIVERSALCANSIG_TX_FAST_APP,"universalCanSignalTxFast",8,issub,ispub,8,5120};
        return cfg;
    }
};

typedef enum
{
    CMDID_UNIVERSAL_CAN_SIGNAL_TX_FAST	= 0, //DesayInterface_pps_UniversalTxCanSignal
    CMDID_UNIVERSAL_CAN_SIGNAL_TX_FAST_MAX
} CMDID_IN_UNIVERSAL_CAN_SIGNAL_TX_FAST_ENUM;

typedef struct  {
    DEY_Char  name[64];     // 信号名称，比如：DisplayReq
    DEY_Octet type;         // 0：周期报文，会缓存在IpcAdapterSVC；1：事件报文，不会缓存，只会发一次。
    DEY_Octet value[8];     // 信号的值，大多数时候使用value[0]，value[1]~value[7]保留
}SingleCanSignal;



class  DesayInterface_pps_universalCanSignal_txFast{
public:
    SingleCanSignal canSignals_[30];
    DEY_Octet length;//
};


#endif
