#ifndef TOPIC_FVUSSDATA_H
#define TOPIC_FVUSSDATA_H

#include "ppscontrol.h"
#include "app_pps_protocal.h"
#include "typedef_ipcadapter.h"

class TopicFvUssData
{
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
        DESY::PPS_CFG_STRU cfg = {TOPICID_FVUSS_DATA_APP, "fvUss_data", 8, issub, ispub, 8, 5120};
        return cfg;
    }
};

typedef enum
{
    CMDID_USS_DIST_FOR_CONTROL   = 0, // DesayInterface_pps_USSDistForControl
    CMDID_USS_OBS_INFO           = 1, // DesayInterface_pps_USSOBSInfo
    CMDID_USS_PARK_SLOT_INFO     = 2, // DesayInterface_pps_USSParkSlotInfo
    CMDID_USS_ECHO_INFO          = 3, // DesayInterface_pps_USSEchoInfo
    CMDID_USS_Refresh_ABPiont    = 4, // DesayInterface_pps_USSRefreshABPiont
    CMDID_USS_USSGLOOBSRangeInfo = 5, // DesayInterface_pps_USSGLOOBSRangeInfo
    CMDID_USS_USS_ALL_DATA       = 6, // DesayInterface_pps_USSAllData
    CMDID_USS_DATA_MAX
} CMDID_USS_DATA_ENUM;

// CMDID:CMDID_USS_DIST_FOR_CONTROL
typedef struct USSDistForControl
{
    uint64 MCU21STimeus;
    uint64 MCU30RTimeus;
    uint64 MCU30STimeus;
    uint64 MCUSocTimeus;
    uint16 USSDistanceRRS;
    uint16 USSDistanceRR;
    uint16 USSDistanceRRM;
    uint16 USSDistanceRLM;
    uint16 USSDistanceRL;
    uint16 USSDistanceRLS;
    uint16 USSDistanceFRS;
    uint16 USSDistanceFR;
    uint16 USSDistanceFRM;
    uint16 USSDistanceFLM;
    uint16 USSDistanceFL;
    uint16 USSDistanceFLS;
    uint8  USSDistanceLevelRRS;
    uint8  USSDistanceLevelRR;
    uint8  USSDistanceLevelRRM;
    uint8  USSDistanceLevelRLM;
    uint8  USSDistanceLevelRL;
    uint8  USSDistanceLevelRLS;
    uint8  USSDistanceLevelFRS;
    uint8  USSDistanceLevelFR;
    uint8  USSDistanceLevelFRM;
    uint8  USSDistanceLevelFLM;
    uint8  USSDistanceLevelFL;
    uint8  USSDistanceLevelFLS;
} DesayInterface_pps_USSDistForControl;

typedef struct
{
    int16 USSObjP1X;
    int16 USSObjP1Y;
    int16 USSObjP2X;
    int16 USSObjP2Y;
    uint8 USSObjProb;
    uint8 USSObjType;
    uint8 USSObjHeightStatus;
} USSOBSInfoItem;

// CMDID:CMDID_USS_OBS_INFO
typedef struct USSOBSInfo
{
    uint64         MCU21STimeus;
    uint64         MCU30RTimeus;
    uint64         MCU30STimeus;
    uint64         MCUSocTimeus;
    USSOBSInfoItem USSOBSInfoArray[50];
} DesayInterface_pps_USSOBSInfo;

typedef struct
{
    uint8  SlotId;
    uint8  SlotType;
    uint8  SlotDepthReferance;
    int16  SlotObj1X;
    int16  SlotObj1Y;
    uint8  SlotObj1Type;
    uint16 SlotObj1Depth;
    int8   SlotObj1Angle;
    int16  SlotObj2X;
    int16  SlotObj2Y;
    uint8  SlotObj2Type;
    uint16 SlotObj2Depth;
    int8   SlotObj2Angle;
    uint16 SlotLength;
} USSParkSlotInfoItem;

// CMDID:CMDID_USS_PARK_SLOT_INFO
typedef struct USSParkSlotInfo
{
    uint64              MCU21STimeus;
    uint64              MCU30RTimeus;
    uint64              MCU30STimeus;
    uint64              MCUSocTimeus;
    USSParkSlotInfoItem USSParkSlotArray[10];
} DesayInterface_pps_USSParkSlotInfo;

typedef struct
{
    uint64 USSDEFirstTimestamp;
    int16  USSDEFirst;
    int16  USSDEFirstLevel;
    uint64 USSDESecondTimestamp;
    int16  USSDESecond;
    uint64 USSCELeftFirstTimestamp;
    int16  USSCELeftFirst;
    int16  USSCELeftFirstLevel;
    uint64 USSCELeftSecondTimestamp;
    int16  USSCELeftSecond;
    uint64 USSCERightFirstTimestamp;
    int16  USSCERightFirst;
    int16  USSCERightFirstLevel;
    uint64 USSCERightSecondTimestamp;
    int16  USSCERightSecond;
} USSEchoInfoItem;

// CMDID:CMDID_USS_ECHO_INFO
typedef struct USSEchoInfo
{
    uint64          MCU21STimeus;
    uint64          MCU30RTimeus;
    uint64          MCU30STimeus;
    uint64          MCUSocTimeus;
    USSEchoInfoItem USSEchoInfoArray[12];
} DesayInterface_pps_USSEchoInfo;

// CMDID:CMDID_USS_Refresh_ABPiont
typedef struct USSRefreshABPiont
{
    uint8   SlotUpdatePtAFlag; // USS车位A点坐标更新标志位
    float32 SlotUpdatePtAx;    // USS车位A点X值坐标，单位mm
    float32 SlotUpdatePtAy;    // USS车位A点y值坐标，单位mm
    uint8   SlotUpdatePtBFlag; // USS车位B点坐标更新标志位
    float32 SlotUpdatePtBx;    // USS车位B点X值坐标，单位mm
    float32 SlotUpdatePtBy;    // USS车位B点y值坐标，单位mm
} DesayInterface_pps_USSRefreshABPiont;

typedef enum
{
    POINT_ERR = 0,            // 错误值
    POINT_TRACK,              // 低矮跟踪类型
    POINT_LFFT_COMPENSATION,  // 左补偿类型
    POINT_RIGHT_COMPENSATION, // 右补偿类型
    POINT_RXTX,               // 自发自收类型
    POINT_SIGNAL_SIDE_LEFT,   // 左定位类型
    POINT_SIGNAL_SIDE_RIGHT,  // 右定位类型
    POINT_TWO_SIDE,           // 双边定位类型（预留）
    POINT_BLIND_ARER          // 盲区类型
} E_UPA_PointType;

typedef enum
{
    GLO_FL = 0, // 前左雷达
    GLO_FLM,    // 前左中雷达
    GLO_FRM,    // 前右中雷达
    GLO_FR,     // 前右雷达
    GLO_RL,     // 后左雷达
    GLO_RLM,    // 后左中雷达
    GLO_RRM,    // 后右中雷达
    GLO_RR,     // 后右雷达
    GLO_MAX     // 雷达最大个数
} E_UPA_ID;

typedef struct
{
    float32         x;
    float32         y;
    E_UPA_PointType type;
} USSGLOOBSPoint;

typedef struct
{
    uint8          num;
    USSGLOOBSPoint point[2];
} USSGLOOBSRangeData;

// CMDID:CMDID_USS_USSGLOOBSRangeInfo
typedef struct USSGLOOBSRangeInfo
{
    uint64             MCU21STimeus;
    uint64             MCU30RTimeus;
    uint64             MCU30STimeus;
    uint64             MCUSocTimeus;
    USSGLOOBSRangeData GLOSnsObj[GLO_MAX];
} DesayInterface_pps_USSGLOOBSRangeInfo;

// CMDID:CMDID_USS_USSALLDATA
// 20230501: 为减少PPS通信频率，新增CmdID:6，结构体包含CmdID:0-5的所有数据，CmdID:0-5不再发送
typedef struct USSAllData
{
    DesayInterface_pps_USSDistForControl  stDistForControl;  // 原 CMDID:0
    DesayInterface_pps_USSOBSInfo         stOBSInfo;         // 原 CMDID:1
    DesayInterface_pps_USSParkSlotInfo    stParkSlotInfo;    // 原 CMDID:2
    DesayInterface_pps_USSEchoInfo        stEchoInfo;        // 原 CMDID:3
    DesayInterface_pps_USSRefreshABPiont  stRefreshABPiont;  // 原 CMDID:4
    DesayInterface_pps_USSGLOOBSRangeInfo stGLOOBSRangeInfo; // 原 CMDID:5
} DesayInterface_pps_USSAllData;

// sizeof(DesayInterface_pps_USSDistForControl);  // 72
// sizeof(DesayInterface_pps_USSOBSInfo);         // 632
// sizeof(DesayInterface_pps_USSParkSlotInfo);    // 296
// sizeof(DesayInterface_pps_USSEchoInfo);        // 1184
// sizeof(DesayInterface_pps_USSRefreshABPiont);  // 24
// sizeof(DesayInterface_pps_USSGLOOBSRangeInfo); // 256
// sizeof(DesayInterface_pps_USSAllData);         // 2464

#endif
