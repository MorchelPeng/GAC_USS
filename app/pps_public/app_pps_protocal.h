#ifndef _APP_PPS_PROTOCOL_H_
#define _APP_PPS_PROTOCOL_H_

#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef SAFE_DELETE
#define SAFE_DELETE(a) \
    if (a)             \
    {                  \
        delete a;      \
        a = NULL;      \
    }
#endif

#ifndef STR_CPY
#define STR_CPY(a, b)                     \
    {                                     \
        if (strlen(b) < sizeof(a))        \
        {                                 \
            strncpy(a, b, strlen(b) + 1); \
        }                                 \
        else                              \
        {                                 \
            strncpy(a, b, sizeof(a) - 1); \
            a[sizeof(a) - 1] = '\0';      \
        }                                 \
    }
#endif

#include <stdint.h>
#include <unistd.h>
#include <mutex>
#include <map>
#include <fcntl.h>
#include <sys/mman.h>

#ifndef DEYCdrChar
typedef char DEYCdrChar;
#endif
#ifndef DEYCdrWchar
typedef unsigned int DEYCdrWchar;
#endif
#ifndef DEYCdrOctet
typedef unsigned char DEYCdrOctet;
#endif
#ifndef DEYCdrShort
typedef short DEYCdrShort;
#endif
#ifndef DEYCdrUnsignedShort
typedef unsigned short DEYCdrUnsignedShort;
#endif
#ifndef DEYCdrLong
typedef int DEYCdrLong;
#endif
#ifndef DEYCdrUnsignedLong
typedef unsigned int DEYCdrUnsignedLong;
#endif
#ifndef DEYCdr8Byte
typedef struct
{
    char bytes[8];
} DEYCdr8Byte;
#endif

typedef signed long long   DEYCdrLongLong;
typedef unsigned long long DEYCdrUnsignedLongLong;

typedef float  DEYCdrFloat;
typedef double DEYCdrDouble;

#if (DEY_CDR_SIZEOF_LONG_DOUBLE == 16)
typedef long double DEYCdrLongDouble;
#else
typedef struct DEYCdrLongDouble
{
    char bytes[16];
} DEYCdrLongDouble;
#endif

typedef unsigned char DEYCdrBoolean;
typedef unsigned int  DEYCdrEnum;

#ifndef DEY_Char
typedef DEYCdrChar DEY_Char;
#endif
#ifndef DEY_Wchar
typedef DEYCdrWchar DEY_Wchar;
#endif
#ifndef DEY_Octet
typedef DEYCdrOctet DEY_Octet;
#endif
#ifndef DEY_Short
typedef DEYCdrShort DEY_Short;
#endif
#ifndef DEY_UnsignedShort
typedef DEYCdrUnsignedShort DEY_UnsignedShort;
#endif
#ifndef DEY_Long
typedef DEYCdrLong DEY_Long;
#endif
#ifndef DEY_UnsignedLong
typedef DEYCdrUnsignedLong DEY_UnsignedLong;
#endif
#ifndef DEY_LongLong
typedef DEYCdrLongLong DEY_LongLong;
#endif
#ifndef DEY_UnsignedLongLong
typedef DEYCdrUnsignedLongLong DEY_UnsignedLongLong;
#endif
#ifndef DEY_Float
typedef DEYCdrFloat DEY_Float;
#endif
#ifndef DEY_Double
typedef DEYCdrDouble DEY_Double;
#endif
#ifndef DEY_LongDouble
typedef DEYCdrLongDouble DEY_LongDouble;
#endif
#ifndef DEY_Boolean
typedef DEYCdrBoolean DEY_Boolean;
#endif
#ifndef DEY_Enum
typedef DEYCdrEnum DEY_Enum;
#endif

// namespace DESY_INTERFACE {

/*
topic id define.
*/
typedef enum TOPIC_ID_DEFINE
{
    // a72 to mcu3 (1-49)
    TOPICID_MOTOVIS_APA_FUSION    = 1,
    TOPICID_MOTOVIS_APA_PLAN      = 2,
    TOPICID_DESAY_HMI             = 3,
    TOPICID_DESAY_APA_HMI         = 4,
    TOPICID_HOLO_FUNC_INFO        = 5,
    TOPICID_HOLO_HMI              = 6,
    TOPICID_HOLO_PLAN_DECISION    = 7,
    TOPICID_HOLO_FUSION_POSITION  = 8,
    TOPICID_MOTOVIS_AVM_RESP      = 9,
    TOPICID_GAC_RA_PATH_TO_MCU    = 10,
    TOPICID_GAC_RAEB_DECISION     = 11,
    TOPICID_GAC_DBG_CTRL          = 12,
    TOPICID_POWER_OFF_DELAY       = 15,
    TOPICID_GAC_APP_VERSION       = 16,
    TOPICID_COMMON_BUFFER_SOC2MCU = 20,
    TOPICID_COMMON_BUFFER_MCU2SOC = 21,

    // motive(50~99)
    TOPICID_MOTOVIS_APA_PARKINGSLOT            = 50,
    TOPICID_MOTOVIS_APA_FREESPACE              = 51,
    TOPICID_MOTOVIS_APA_HMI                    = 52,
    TOPICID_MOTOVIS_AVM_RELEASE_STATUS         = 53,
    TOPICID_MOTOVIS_PSD_RELEASE_STATUS         = 54,
    TOPICID_MOTOVIS_VIEW_MNG_RESP              = 55,
    TOPICID_MOTOVIS_REMOTE_MONITOR             = 56,
    TOPICID_MOTOVIS_REMOTE_MONITOR_IMAGE       = 57,
    TOPICID_MOTOVIS_APA_SLOT_ATTRIBUTE_TO_PLAN = 60,
    TOPICID_MOTOVIS_APA_OBS_GRID_MAP           = 61,
    TOPICID_MOTOVIS_APA_FUSION_SLOT            = 62,
    TOPICID_MOTOVIS_APA_PLAN_INPUTPARKINGIN    = 63,
    TOPICID_MOTOVIS_APA_PLAN_TO_A72            = 64,
    TOPICID_MOTOVIS_APA_PLAN_UPDATE_VALUE      = 65,
    TOPICID_MOTOVIS_APA_PLAN_PATHPLAN_RET      = 66,
    TOPICID_MOTOVIS_APA_PLAN_INPUT_DATA        = 67,
    TOPICID_MOTOVIS_CALIBRA_TO_AVM_COMM        = 68,
    TOPICID_MOTOVIS_AVM_TO_CALIBRA_COMM        = 69,
    TOPICID_MOTOVIS_APA_USER_DRAG_SLOT         = 71,
    TOPICID_MOTOVIS_APA_PARKOUT_DIR_SEL        = 72,
    TOPICID_MOTOVIS_AVM_MODE                   = 73,
    TOPICID_MOTOVIS_AVM_RMS_SYS_FAIL_FLAG      = 74,
    TOPICID_MOTOVIS_APA_MIX_SLOT               = 81,
    TOPICID_MOTOVIS_APA_PARKOUTSPACEDETECT     = 82,
    TOPICID_MOTOVIS_APA_FUSIONRESULTRET        = 83,
    TOPICID_MOTOVIS_APA_MAPINFO                = 84,
    TOPICID_MOTOVIS_APA_INPUTOFGETBOUND        = 85,
    TOPICID_MOTOVIS_APA_OUTPUTOFGETBOUND       = 86,
    TOPICID_MOTOVIS_APA_DRRESETSUCCESSFLAG     = 87,

    // holo(100~149)
    TOPICID_HOLO_PARKING_MANAGER_COMMAND     = 100,
    TOPICID_HOLO_DETECTION                   = 101,
    TOPICID_HOLO_POINT_FEATURE_LIST          = 102,
    TOPICID_HOLO_SRV_NODE_STATE              = 103,
    TOPICID_HOLO_VISION_NODE_STATE           = 105,
    TOPICID_HOLO_FREESPACE_AVM               = 106,
    TOPICID_HOLO_OBS_FUSION                  = 107,
    TOPICID_HOLO_OBS_LOCALIZATION            = 108,
    TOPICID_HOLO_PLANNING_STATE              = 109,
    TOPICID_HOLO_VSLAM_STATE                 = 111,
    TOPICID_HOLO_HMI_CONVERT                 = 112,
    TOPICID_HOLO_PSD_STATE                   = 113,
    TOPICID_HOLO_FUSION_STATE                = 114,
    TOPICID_HOLO_HMI_PARKING_STATE           = 115,
    TOPICID_HOLO_CLOUD_PATH_INFO             = 116,
    TOPICID_HOLO_PARKING_MAP_GRAPH           = 117,
    TOPICID_HOLO_SHARE_ROUTE_STATR_TOPIC_REQ = 118,
    TOPICID_HOLO_MOTOVIS_COMMAND             = 119,
    TOPICID_HOLO_MAP_SERVER                  = 120,
    TOPICID_HOLO_MAP_PARKING                 = 121,
    TOPICID_HOLO_MAP_PARKING_CMW             = 122,
    TOPICID_HOLO_MONITOR_STATUS              = 124,
    TOPICID_HOLO_WINTERFELL_CURRENT_STATE    = 125,
    TOPICID_HOLO_DATABACK_HAUL_UPLOAD_STATUS = 127,
    TOPICID_HOLO_POINT_FEATRUE_STATE         = 128,
    TOPICID_HOLO_MAP_SERVICE_INNER_REQUEST   = 131,
    TOPICID_HOLO_MAP_SERVICE_INNER_RESPONSE  = 132,
    TOPICID_HOLO_MONITOR_APP_STATUS          = 133,
    TOPICID_HOLO_PATH_PROCESS_STATE          = 134,
    TOPICID_HOLO_MAP_STATE                   = 135,
    TOPICID_AVP_EVENT_RESP_APP               = 138,
    TOPICID_AVP_PERIOD_RESP_APP              = 139,
    TOPICID_AVP_EVENT_REQ_APP                = 140,
    TOPICID_HOLO_DYNAMIC_LAYER_REQUEST       = 141,
    TOPICID_HOLO_IMAGE_ENCODE                = 148,

    // gacrnd(150~199) mcu3 to a72
    TOPICID_GAC_VEH_STATE_EST      = 150,
    TOPICID_GAC_APA_DR             = 151,
    TOPICID_GAC_CTRL               = 152,
    TOPICID_GAC_HANDSHAKE          = 153,
    TOPICID_APA_STATE_MACHINE      = 154,
    TOPICID_GAC_TOP_STATE_MACHINE  = 155,
    TOPICID_GAC_RA_STATE_MACHINE   = 156,
    TOPICID_GAC_RA_PATH_FROM_MCU   = 157,
    TOPICID_GAC_RAEB_STATE_MACHINE = 158,
    TOPICID_GAC_DIAG_INFO          = 159,
    TOPICID_GAC_COLLI_AVOID        = 160,
    TOPICID_GAC_CAN_RX             = 170,

    // topic id(400-)
    TOPICID_IMU_APP                     = 400,
    TOPICID_CANSIGNAL_RX_APP            = TOPICID_GAC_CAN_RX,
    TOPICID_CANSIG_TX_FAST_APP          = 402,
    TOPICID_FVUSS_DATA_APP              = 403,
    TOPICID_MCUSYSREQ_APP               = 404,
    TOPICID_UNIVERSALCANSIG_TX_FAST_APP = 405,
    TOPICID_UPDATE_MSG                  = 406,
    TOPICID_soc_power_management        = 407, // soc_power_management
    TOPICID_mcu_power_management        = 408, // mcu_power_management
    TOPICID_UDS_APP                     = 409,
    TOPICID_UDS_MCU                     = 410,
    TOPICID_ecu_power_management        = 411, // ecu_power_management

    // topic id(500-)
    TOPIC_AVMRESPONSE_APP           = 503,
    TOPIC_AVMREQUEST_APP            = 504,
    TOPICID_HPAEVENTREQ_APP         = 506,
    TOPICID_HPAEVENTRESP_APP        = 507,
    TOPICID_HPAINFO_APP             = 508,
    TOPICID_HOLO_VIEWMNG_REQ_APP    = 509,
    TOPICID_HOLO_VIEWMNG_RESP_APP   = 510,
    TOPICID_MOTOVIS_VIEWMNG_REQ_APP = 511,
    TOPICID_ERROR_MANAGE_APP        = 512,
    //TOPICID_CALIBRA_RESP_APP        = 513,
    TOPICID_DID_DTC_REQ_APP         = 514,
    TOPICID_DID_DTC_RESP_APP        = 515,
    TOPICID_DID_DTC_REQ_ALG         = 516,

    // topic id(550-)
    TOPICID_eol_app_data = 551,
    TOPICID_eol_mcu_data = 552,
    TOPICID_FlcDataIpc   = 553,
    TOPICID_EOL_AVM_APP  = 554,
    TOPICID_EOL_APP_REQ  = 555,
    TOPICID_APP_RESP_EOL = 556,
    TOPICID_RA_HMI       = 557,

} TOPIC_ID_DEFINE_ENUM;

#define BUFCNT_DEFAULT   16
#define CMDCNT_DEFAULT   15
#define DATASIZE_DEFAULT 300
#define DATASIZE_5120    5120
#define SUB_TURE         1
#define SUB_FALSE        0
#define PUB_TRUE         1
#define PUB_FALSE        0

// TOPIC ID:1
typedef enum
{
    CMDID_APA_SLOT_ATTRIBUTE      = 0, // AlgInterface::APASlotAttribute
    CMDID_APA_SLOT_INFO           = 1, // AlgInterface::APASlotInfo
    CMDID_APA_FUSION_INFO         = 2, // AlgInterface::APAFusionInfo
    CMDID_APA_COLLISIONAVOID_INFO = 3, // AlgInterface::APACollisionAvoidInfo
    CMDID_APA_DECISION_INFO       = 4, // AlgInterface::APADecisionInfo
    CMDID_APA_FUSION_WAKE_INFO    = 5, // AlgInterface::APAFusionWakeInfo
    CMDID_CAMERA_CLEAN_ST         = 6, // AlgInterface::CameraCleanSt
    CMDID_MOTOVIS_APA_FUSION_MAX
} CMDID_MOTOVIS_APA_FUSION;

// TOPIC ID:2
typedef enum
{
    CMDID_APA_PATH_ATTRIBUTE = 0, // AlgInterface::APAPathAttribute
    CMDID_APA_PATH           = 1, // AlgInterface::APAPath
    CMDID_MOTOVIS_APA_PLAN_MAX
} CMDID_MOTOVIS_APA_PLAN;

// TOPIC ID:3
typedef enum
{
    CMDID_DESAY_APA_UI_INFO  = 0, // AlgInterface::APAUIInfo
    CMDID_DESAY_RA_UI_INFO   = 1, // AlgInterface::RAUIInfo
    CMDID_DESAY_RAEB_UI_INFO = 2, // AlgInterface::RAEBUIInfo
    CMDID_DESAY_HMI_MAX
} CMDID_DESAY_HMI;

// TOPIC ID:5
typedef enum
{
    CMDID_FUNC_INFO     = 0, // AlgInterface::FuncInfo
    CMDID_FUNC_TIP_INFO = 1, // AlgInterface::FuncTipInfo
    CMDID_HOLO_FUNC_INFO_MAX
} CMDID_HOLO_FUNC_INFO;

// TOPIC ID:6
typedef enum
{
    CMDID_FUNC_REMOTE_CONTROL = 0, // AlgInterface::FuncRemoteControl
    CMDID_FUNC_BEAM_REQ_INFO  = 1, // AlgInterface::FuncBeamReqInfo
    CMDID_FUNC_SM_CAN_OUT     = 2, // AlgInterface::FuncSMCANOut
    CMDID_HPA_INFO            = 3, // AlgInterface::HPAInfo
    CMDID_HOLO_HMI_MAX
} CMDID_HOLO_HMI;

// TOPIC ID:7
typedef enum
{
    CMDID_HPA_PATH               = 0, // AlgInterface::HPAPath
    CMDID_HPA_DECISION_ATTRIBUTE = 1, // AlgInterface::HPADecisionAttribute
    CMDID_HOLO_PLAN_DECISION_MAX
} CMDID_HOLO_PLAN_DECISION;

// TOPIC ID:8
typedef enum
{
    CMDID_FUNC_VEHPOS = 0, // AlgInterface::FuncVehPos
    CMDID_HOLO_FUSION_POSITION_MAX
} CMDID_HOLO_FUSION_POSITION;

// TOPIC ID:9
typedef enum
{
    CMDID_APA_PARK_INFO       = 0, // AlgInterface::ParkInfo
    CMDID_APA_SLOT_MATCH_INFO = 1, // AlgInterface::SlotMatchInfo
    CMDID_MOTOVIS_AVM_RESP_MAX
} CMDID_MOTOVIS_AVM_RESP;

// TOPIC ID:10
typedef enum
{
    CMDID_RA_PATH_STATE_TO_MCU = 0, // AlgInterface::RAPathState
    CMDID_RA_PATH_POINT_TO_MCU = 1, // AlgInterface::RAPathPoint
    CMDID_GAC_RA_PATH_TO_MCU_MAX
} CMDID_GAC_RA_PATH_TO_MCU;

// TOPIC ID:11
typedef enum
{
    CMDID_BRAKE_DECISION = 0, // AlgInterface::BrakeDecision
    CMDID_GAC_RAEB_DECISION_MAX
} CMDID_GAC_RAEB_DECISION;

// TOPIC ID:12
typedef enum
{
    CMDID_GAC_DIAG_DBG_MODE = 0, // AlgInterface::DiagDebugMode
    CMDID_GAC_DBG_CTRL_MAX
} CMDID_GAC_DBG_CTRL;

// TOPIC ID:16
typedef enum
{
    CMDID_GAC_APP_VERSION_REQUEST  = 0, // AlgInterface::VersionRequest
    CMDID_GAC_APP_VERSION_RESPONSE = 1, // AlgInterface::VersionResponse
    CMDID_GAC_APP_VERSION_MAX,
} CMDID_GAC_APP_VERSION_TYPE;

// TOPIC ID:20
typedef enum CMDID_IN_TOPICID_COMMON_BUFFER_SOC2MCU
{
    CMDID_COMMON_BUFFER_SOC2MCU = 0
} CMDID_IN_TOPICID_COMMON_BUFFER_SOC2MCU_ENUM;

// TOPIC ID:21
typedef enum CMDID_IN_TOPICID_COMMON_BUFFER_MCU2SOC
{
    CMDID_COMMON_BUFFER_MCU2SOC = 0
} CMDID_IN_TOPICID_COMMON_BUFFER_MCU2SOC_ENUM;

// TOPIC ID:150
typedef enum
{
    CMDID_ESTVEHSTATE = 0, // AlgInterface::EstVehState
    CMDID_GAC_VEH_STATE_EST_MAX
} CMDID_GAC_VEH_STATE_EST;

// TOPIC ID:151
typedef enum
{
    CMDID_APA_VEHPOS = 0, // AlgInterface::APAVehPos
    CMDID_GAC_APA_DR_MAX
} CMDID_GAC_APA_DR;

// TOPIC ID:152
typedef enum
{
    CMDID_CTRL_STATE = 0, // AlgInterface::CtrlState
    CMDID_GAC_CTRL_MAX
} CMDID_GAC_CTRL;

// TOPIC ID:153
typedef enum
{
    CMDID_HANDSHAKEA_INFO = 0, // AlgInterface::HandShakeInfo
    CMDID_GAC_HANDSHAKE_MAX
} CMDID_GAC_HANDSHAKE;

// TOPIC ID:154
typedef enum
{
    CMDID_APASM_APA_ALG_ENABLE  = 0, // AlgInterface::APASMApaAlgEnable
    CMDID_APASM_APA_ST          = 1, // AlgInterface::APASMApaSt
    CMDID_APASM_APA_INVOKE_RESP = 2, // AlgInterface::APASMApaInvokeResp
    CMDID_APASM_PSD_INFO        = 3, // AlgInterface::APASMPSDInfo
    CMDID_APASM_PARKOUT_DIR     = 4, // AlgInterface::APASMParkOutDir
    CMDID_APASM_TIP_INFO        = 5, // AlgInterface::APASMTipInfo
    CMDID_APASM_APA_MODE        = 6, // AlgInterface::APASMApaMode
    CMDID_APASM_ALL_DATA        = 7, // AlgInterface::APASMAllData
    CMDID_APA_STATE_MACHINE_MAX
} CMDID_APA_STATE_MACHINE;

// TOPIC ID:155
typedef enum
{
    CMDID_TOPSM_INVOKE_INFO        = 0, // AlgInterface::TOPSMInvokeInfo
    CMDID_TOPSM_FUNC_RESP_ST       = 1, // AlgInterface::TOPSMFuncRespSt
    CMDID_TOPSM_DECISION_ATTRIBUTE = 2, // AlgInterface::TOPSMDecisionAttribute
    CMDID_TOPSM_ALL_DATA           = 3, // AlgInterface::TOPSMAllData
    CMDID_GAC_TOP_STATE_MACHINE_MAX
} CMDID_GAC_TOP_STATE_MACHINE;

// TOPIC ID:156
typedef enum
{
    CMDID_RA_HMI_REQ = 0, // AlgInterface::RAHMIReq
    CMDID_GAC_RA_STATE_MACHINE_MAX
} CMDID_GAC_RA_STATE_MACHINE;

// TOPIC ID:157
typedef enum
{
    CMDID_RA_PATH_STATE_FROM_MCU = 0, // AlgInterface::RAPathState
    CMDID_RA_PATH_POINT_FROM_MCU = 1, // AlgInterface::RAPathPoint
    CMDID_GAC_RA_PATH_FROM_MCU_MAX
} CMDID_GAC_RA_PATH_FROM_MCU;

// TOPIC ID:158
typedef enum
{
    CMDID_RAEB_HMI_FUNC_ST = 0, // AlgInterface::RAEBHMIFuncSt
    CMDID_RAEB_SM_SAVE_OUT = 1, // AlgInterface::RAEBSMSaveOut
    CMDID_GAC_RAEB_STATE_MACHINE_MAX
} CMDID_GAC_RAEB_STATE_MACHINE;

// TOPIC ID:159
typedef enum
{
    CMDID_HPA_DIAG_INFO = 0, // AlgInterface::HPADiagInfo
    CMDID_HMI_DIAG_INFO = 1, // AlgInterface::HMIDiagInfo
    CMDID_GAC_DIAG_INFO_MAX
} CMDID_GAC_DIAG_INFO;

// TOPIC ID:160
typedef enum
{
    CMDID_COLLI_DECISION_ATTRIBUTE = 0, // AlgInterface::ColliAvoidDecisionAttribute
    CMDID_COLLI_AVOID_OBS_INFO     = 1, // AlgInterface::ColliAvoidObsInfo
    CMDID_COLLI_AVOID_2_IPC        = 2, // AlgInterface::ColliAvoid2IPC
    CMDID_COLLI_AVOID_ALL_DATA     = 3, // AlgInterface::ColliAvoidAllData
    CMDID_GAC_COLLI_AVOID_MAX
} CMDID_GAC_COLLI_AVOID;

// TOPIC ID:170
typedef enum
{
    CMDID_GAC_CAN_RX_EVENT  = 0, // AlgInterface::CANRxEvent
    CMDID_GAC_CAN_RX_20_MS  = 1, // AlgInterface::CANRx20ms
    CMDID_GAC_CAN_RX_100_MS = 2, // AlgInterface::CANRx100ms
    CMDID_GAC_CAN_RX_500_MS = 3, // AlgInterface::CANRx500ms
    CMDID_GAC_CAN_RX_MAX
} CMDID_GAC_CAN_RX;

#endif // _APP_PPS_PROTOCOL_H_
