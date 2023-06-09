#ifndef TOPIC_IPCADAPTER_H
#define TOPIC_IPCADAPTER_H

#include "ppscontrol.h"
#include "app_pps_protocal.h"
#include "typedef_ipcadapter.h"

// TOPIC ID:1
namespace topicid_motovis_apa_fusion
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_MOTOVIS_APA_FUSION, "topicid_motovis_apa_fusion", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_MOTOVIS_APA_FUSION, "topicid_motovis_apa_fusion", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_MOTOVIS_APA_FUSION, "topicid_motovis_apa_fusion", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

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

}

// TOPIC ID:2
namespace topicid_motovis_apa_plan
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_MOTOVIS_APA_PLAN, "topicid_motovis_apa_plan", 4, 0, 1, 16, DATASIZE_5120};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_MOTOVIS_APA_PLAN, "topicid_motovis_apa_plan", 4, 1, 0, 16, DATASIZE_5120};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_MOTOVIS_APA_PLAN, "topicid_motovis_apa_plan", 4, 1, 1, 16, DATASIZE_5120};

    typedef enum
    {
        CMDID_APA_PATH_ATTRIBUTE = 0, // AlgInterface::APAPathAttribute
        CMDID_APA_PATH           = 1, // AlgInterface::APAPath
        CMDID_MOTOVIS_APA_PLAN_MAX
    } CMDID_MOTOVIS_APA_PLAN;

}

// TOPIC ID:3
namespace topicid_desay_hmi
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_DESAY_HMI, "topicid_desay_hmi", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_DESAY_HMI, "topicid_desay_hmi", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_DESAY_HMI, "topicid_desay_hmi", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_DESAY_APA_UI_INFO  = 0, // AlgInterface::APAUIInfo
        CMDID_DESAY_RA_UI_INFO   = 1, // AlgInterface::RAUIInfo
        CMDID_DESAY_RAEB_UI_INFO = 2, // AlgInterface::RAEBUIInfo
        CMDID_DESAY_HMI_MAX
    } CMDID_DESAY_HMI;

}

// TOPIC ID:5
namespace topicid_holo_func_info
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_HOLO_FUNC_INFO, "topicid_holo_func_info", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_HOLO_FUNC_INFO, "topicid_holo_func_info", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_HOLO_FUNC_INFO, "topicid_holo_func_info", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_FUNC_INFO     = 0, // AlgInterface::FuncInfo
        CMDID_FUNC_TIP_INFO = 1, // AlgInterface::FuncTipInfo
        CMDID_HOLO_FUNC_INFO_MAX
    } CMDID_HOLO_FUNC_INFO;

}

// TOPIC ID:6
namespace topicid_holo_hmi
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_HOLO_HMI, "topicid_holo_hmi", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_HOLO_HMI, "topicid_holo_hmi", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_HOLO_HMI, "topicid_holo_hmi", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_FUNC_REMOTE_CONTROL = 0, // AlgInterface::FuncRemoteControl
        CMDID_FUNC_BEAM_REQ_INFO  = 1, // AlgInterface::FuncBeamReqInfo
        CMDID_FUNC_SM_CAN_OUT     = 2, // AlgInterface::FuncSMCANOut
        CMDID_HPA_INFO            = 3, // AlgInterface::HPAInfo
        CMDID_HOLO_HMI_MAX
    } CMDID_HOLO_HMI;

}

// TOPIC ID:7
namespace topicid_holo_plan_decision
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_HOLO_PLAN_DECISION, "topicid_holo_plan_decision", 4, 0, 1, 16, DATASIZE_5120};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_HOLO_PLAN_DECISION, "topicid_holo_plan_decision", 4, 1, 0, 16, DATASIZE_5120};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_HOLO_PLAN_DECISION, "topicid_holo_plan_decision", 4, 1, 1, 16, DATASIZE_5120};

    typedef enum
    {
        CMDID_HPA_PATH               = 0, // AlgInterface::HPAPath
        CMDID_HPA_DECISION_ATTRIBUTE = 1, // AlgInterface::HPADecisionAttribute
        CMDID_HOLO_PLAN_DECISION_MAX
    } CMDID_HOLO_PLAN_DECISION;

}

// TOPIC ID:8
namespace topicid_holo_fusion_position
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_HOLO_FUSION_POSITION, "topicid_holo_fusion_position", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_HOLO_FUSION_POSITION, "topicid_holo_fusion_position", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_HOLO_FUSION_POSITION, "topicid_holo_fusion_position", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_FUNC_VEHPOS = 0, // AlgInterface::FuncVehPos
        CMDID_HOLO_FUSION_POSITION_MAX
    } CMDID_HOLO_FUSION_POSITION;

}

// TOPIC ID:9
namespace topicid_motovis_avm_resp
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_MOTOVIS_AVM_RESP, "topicid_motovis_avm_resp", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_MOTOVIS_AVM_RESP, "topicid_motovis_avm_resp", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_MOTOVIS_AVM_RESP, "topicid_motovis_avm_resp", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_APA_PARK_INFO       = 0, // AlgInterface::ParkInfo
        CMDID_APA_SLOT_MATCH_INFO = 1, // AlgInterface::SlotMatchInfo
        CMDID_MOTOVIS_AVM_RESP_MAX
    } CMDID_MOTOVIS_AVM_RESP;
}

// TOPIC ID:10
namespace topicid_gac_ra_path_to_mcu
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_RA_PATH_TO_MCU, "topicid_gac_ra_path_to_mcu", 4, 0, 1, 16, DATASIZE_5120};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_RA_PATH_TO_MCU, "topicid_gac_ra_path_to_mcu", 4, 1, 0, 16, DATASIZE_5120};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_RA_PATH_TO_MCU, "topicid_gac_ra_path_to_mcu", 4, 1, 1, 16, DATASIZE_5120};

    typedef enum
    {
        CMDID_RA_PATH_STATE_TO_MCU = 0, // AlgInterface::RAPathState
        CMDID_RA_PATH_POINT_TO_MCU = 1, // AlgInterface::RAPathPoint
        CMDID_GAC_RA_PATH_TO_MCU_MAX
    } CMDID_GAC_RA_PATH_TO_MCU;

}

// TOPIC ID:11
namespace topicid_gac_raeb_decision
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_RAEB_DECISION, "topicid_gac_raeb_decision", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_RAEB_DECISION, "topicid_gac_raeb_decision", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_RAEB_DECISION, "topicid_gac_raeb_decision", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_BRAKE_DECISION = 0, // AlgInterface::BrakeDecision
        CMDID_GAC_RAEB_DECISION_MAX
    } CMDID_GAC_RAEB_DECISION;

}

// TOPIC ID:12
namespace topicid_gac_dbg_ctrl
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_DBG_CTRL, "topicid_gac_dbg_ctrl", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_DBG_CTRL, "topicid_gac_dbg_ctrl", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_DBG_CTRL, "topicid_gac_dbg_ctrl", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_GAC_DIAG_DBG_MODE = 0, // AlgInterface::DiagDebugMode
        CMDID_GAC_DBG_CTRL_MAX
    } CMDID_GAC_DBG_CTRL;

}

// TOPIC ID:16
namespace topicid_gac_app_version
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_APP_VERSION, "topicid_gac_app_version", 4, 0, 1, CMDCNT_DEFAULT, DATASIZE_5120};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_APP_VERSION, "topicid_gac_app_version", 4, 1, 0, CMDCNT_DEFAULT, DATASIZE_5120};
    static DESY::PPS_CFG_STRU cfg_sub_pub   = {TOPICID_GAC_APP_VERSION, "topicid_gac_app_version", 4, 1, 1, CMDCNT_DEFAULT, DATASIZE_5120};

    typedef enum
    {
        CMDID_GAC_APP_VERSION_REQUEST  = 0, // AlgInterface::VersionRequest
        CMDID_GAC_APP_VERSION_RESPONSE = 1, // AlgInterface::VersionResponse
        CMDID_GAC_APP_VERSION_MAX,
    } CMDID_GAC_APP_VERSION_TYPE;

}

// TOPIC ID:150
namespace topicid_gac_veh_state_est
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_VEH_STATE_EST, "topicid_gac_veh_state_est", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_VEH_STATE_EST, "topicid_gac_veh_state_est", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_VEH_STATE_EST, "topicid_gac_veh_state_est", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_ESTVEHSTATE = 0, // AlgInterface::EstVehState
        CMDID_GAC_VEH_STATE_EST_MAX
    } CMDID_GAC_VEH_STATE_EST;

}

// TOPIC ID:151
namespace topicid_gac_apa_dr
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_APA_DR, "topicid_gac_apa_dr", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_APA_DR, "topicid_gac_apa_dr", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_APA_DR, "topicid_gac_apa_dr", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_APA_VEHPOS = 0, // AlgInterface::APAVehPos
        CMDID_GAC_APA_DR_MAX
    } CMDID_GAC_APA_DR;

}

// TOPIC ID:152
namespace topicid_gac_ctrl
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_CTRL, "topicid_gac_ctrl", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_CTRL, "topicid_gac_ctrl", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_CTRL, "topicid_gac_ctrl", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_CTRL_STATE = 0, // AlgInterface::CtrlState
        CMDID_GAC_CTRL_MAX
    } CMDID_GAC_CTRL;

}

// TOPIC ID:153
namespace topicid_gac_handshake
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_HANDSHAKE, "topicid_gac_handshake", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_HANDSHAKE, "topicid_gac_handshake", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_HANDSHAKE, "topicid_gac_handshake", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_HANDSHAKEA_INFO = 0, // AlgInterface::HandShakeInfo
        CMDID_GAC_HANDSHAKE_MAX
    } CMDID_GAC_HANDSHAKE;

}

// TOPIC ID:154
namespace topicid_apa_state_machine
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_APA_STATE_MACHINE, "topicid_apa_state_machine", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_APA_STATE_MACHINE, "topicid_apa_state_machine", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_APA_STATE_MACHINE, "topicid_apa_state_machine", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_APASM_APA_ALG_ENABLE  = 0, // AlgInterface::APASMAPAAlgEnable
        CMDID_APASM_APA_ST          = 1, // AlgInterface::APASMAPASt
        CMDID_APASM_APA_INVOKE_RESP = 2, // AlgInterface::APASMAPAInvokeResp
        CMDID_APASM_PSD_INFO        = 3, // AlgInterface::APASMPSDInfo
        CMDID_APASM_PARKOUT_DIR     = 4, // AlgInterface::APASMParkOutDir
        CMDID_APASM_TIP_INFO        = 5, // AlgInterface::APASMTipInfo
        CMDID_APASM_APA_MODE        = 6, // AlgInterface::APASMAPAMode
        CMDID_APASM_ALL_DATA        = 7, // AlgInterface::APASMAllData
        CMDID_APA_STATE_MACHINE_MAX
    } CMDID_APA_STATE_MACHINE;

}

// TOPIC ID:155
namespace topicid_gac_top_state_machine
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_TOP_STATE_MACHINE, "topicid_gac_top_state_machine", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_TOP_STATE_MACHINE, "topicid_gac_top_state_machine", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_TOP_STATE_MACHINE, "topicid_gac_top_state_machine", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_TOPSM_INVOKE_INFO        = 0, // AlgInterface::TOPSMInvokeInfo
        CMDID_TOPSM_FUNC_RESP_ST       = 1, // AlgInterface::TOPSMFuncRespSt
        CMDID_TOPSM_DECISION_ATTRIBUTE = 2, // AlgInterface::TOPSMDecisionAttribute
        CMDID_TOPSM_ALL_DATA           = 3, // AlgInterface::TOPSMAllData
        CMDID_GAC_TOP_STATE_MACHINE_MAX
    } CMDID_GAC_TOP_STATE_MACHINE;

}

// TOPIC ID:156
namespace topicid_gac_ra_state_machine
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_RA_STATE_MACHINE, "topicid_gac_ra_state_machine", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_RA_STATE_MACHINE, "topicid_gac_ra_state_machine", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_RA_STATE_MACHINE, "topicid_gac_ra_state_machine", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_RA_HMI_REQ = 0, // AlgInterface::RAHMIReq
        CMDID_GAC_RA_STATE_MACHINE_MAX
    } CMDID_GAC_RA_STATE_MACHINE;

}

// TOPIC ID:157
namespace topicid_gac_ra_path_from_mcu
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_RA_PATH_FROM_MCU, "topicid_gac_ra_path_from_mcu", 4, 0, 1, CMDCNT_DEFAULT, DATASIZE_5120};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_RA_PATH_FROM_MCU, "topicid_gac_ra_path_from_mcu", 4, 1, 0, CMDCNT_DEFAULT, DATASIZE_5120};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_RA_PATH_FROM_MCU, "topicid_gac_ra_path_from_mcu", 4, 1, 1, CMDCNT_DEFAULT, DATASIZE_5120};

    typedef enum
    {
        CMDID_RA_PATH_STATE_FROM_MCU = 0, // AlgInterface::RAPathState
        CMDID_RA_PATH_POINT_FROM_MCU = 1, // AlgInterface::RAPathPoint
        CMDID_GAC_RA_PATH_FROM_MCU_MAX
    } CMDID_GAC_RA_PATH_FROM_MCU;

}

// TOPIC ID:158
namespace topicid_gac_raeb_state_machine
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_RAEB_STATE_MACHINE, "topicid_gac_raeb_state_machine", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_RAEB_STATE_MACHINE, "topicid_gac_raeb_state_machine", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_RAEB_STATE_MACHINE, "topicid_gac_raeb_state_machine", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_RAEB_HMI_FUNC_ST = 0, // AlgInterface::RAEBHMIFuncSt
        CMDID_RAEB_SM_SAVE_OUT = 1, // AlgInterface::RAEBSMSaveOut
        CMDID_GAC_RAEB_STATE_MACHINE_MAX
    } CMDID_GAC_RAEB_STATE_MACHINE;

}

// TOPIC ID:159
namespace topicid_gac_diag_info
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_DIAG_INFO, "topicid_gac_diag_info", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_DIAG_INFO, "topicid_gac_diag_info", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_DIAG_INFO, "topicid_gac_diag_info", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_HPA_DIAG_INFO = 0, // AlgInterface::HPADiagInfo
        CMDID_HMI_DIAG_INFO = 1, // AlgInterface::HMIDiagInfo
        CMDID_GAC_DIAG_INFO_MAX
    } CMDID_GAC_DIAG_INFO;

}

// TOPIC ID:160
namespace topicid_gac_colli_avoid
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_COLLI_AVOID, "topicid_gac_colli_avoid", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_COLLI_AVOID, "topicid_gac_colli_avoid", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_COLLI_AVOID, "topicid_gac_colli_avoid", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_COLLI_DECISION_ATTRIBUTE = 0, // AlgInterface::ColliAvoidDecisionAttribute
        CMDID_COLLI_AVOID_OBS_INFO     = 1, // AlgInterface::ColliAvoidObsInfo
        CMDID_COLLI_AVOID_2_IPC        = 2, // AlgInterface::ColliAvoid2IPC
        CMDID_COLLI_AVOID_ALL_DATA     = 3, // AlgInterface::ColliAvoidAllData
        CMDID_GAC_COLLI_AVOID_MAX
    } CMDID_GAC_COLLI_AVOID;

}

// TOPIC ID:170
namespace topicid_gac_can_rx
{

    static DESY::PPS_CFG_STRU cfg_publish   = {TOPICID_GAC_CAN_RX, "topicid_gac_can_rx", BUFCNT_DEFAULT, 0, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subscribe = {TOPICID_GAC_CAN_RX, "topicid_gac_can_rx", BUFCNT_DEFAULT, 1, 0, CMDCNT_DEFAULT, DATASIZE_DEFAULT};
    static DESY::PPS_CFG_STRU cfg_subpub    = {TOPICID_GAC_CAN_RX, "topicid_gac_can_rx", BUFCNT_DEFAULT, 1, 1, CMDCNT_DEFAULT, DATASIZE_DEFAULT};

    typedef enum
    {
        CMDID_GAC_CAN_RX_EVENT  = 0, // AlgInterface::CANRxEvent
        CMDID_GAC_CAN_RX_20_MS  = 1, // AlgInterface::CANRx20ms
        CMDID_GAC_CAN_RX_100_MS = 2, // AlgInterface::CANRx100ms
        CMDID_GAC_CAN_RX_500_MS = 3, // AlgInterface::CANRx500ms
        CMDID_GAC_CAN_RX_MAX
    } CMDID_GAC_CAN_RX;

}

#endif