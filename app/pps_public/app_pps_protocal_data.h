
#pragma once
#include <stdint.h>
#include <unistd.h>
#include <mutex>
#include <map>
#include <fcntl.h>
#include <sys/mman.h>
#include <vector>
#include <string>
#include <string.h>
#include <mem.h>
// #include "pps_protocol_data.h"

#define STR_BUF_NUM 32

//#define STR_CPY(a,b)  strncpy(a,b,strlen(b)<sizeof(a)?strlen(b)+1:sizeof(a))
//rj_
//avm3d_app internal start


class CameraSt{
public:
    bool frontCam;
    bool rearCam;
    bool leftCam;
    bool rightCam;
    CameraSt()
    {
        frontCam=false;
        rearCam=false;
        leftCam=false;
        rightCam=false;
    }

};

class ModSt{
public:
    bool frontModSt;
    bool rearModSt;
    bool leftModSt;
    bool rightModSt;
    ModSt()
    {
        frontModSt=false;
        rearModSt=false;
        leftModSt=false;
        rightModSt=false;
    }
};

//avp->gui
class AvpLPViewSt{
public:
    char avpLPSearchSt[40];
    char avpLPParkingSt[40];
    char avpLPBuildMapSt[40];
    char avpLPParkOutSt[40];
    char curViewSt[40];
    AvpLPViewSt()
    {
        memset(avpLPSearchSt,0x0,sizeof(avpLPSearchSt));
        memset(avpLPParkingSt,0x0,sizeof(avpLPParkingSt));
        memset(avpLPBuildMapSt,0x0,sizeof(avpLPBuildMapSt));
        memset(avpLPParkOutSt,0x0,sizeof(avpLPParkOutSt));
        memset(curViewSt,0x0,sizeof(curViewSt));
    }
    const AvpLPViewSt& operator =(const AvpLPViewSt& data)
    {
        memcpy(avpLPSearchSt,data.avpLPSearchSt,sizeof(avpLPSearchSt));
        memcpy(avpLPParkingSt,data.avpLPParkingSt,sizeof(avpLPParkingSt));
        memcpy(avpLPBuildMapSt,data.avpLPBuildMapSt,sizeof(avpLPBuildMapSt));
        memcpy(avpLPParkOutSt,data.avpLPParkOutSt,sizeof(avpLPParkOutSt));
        memcpy(curViewSt,data.curViewSt,sizeof(curViewSt));
        return *this;
    }
};

class AvpViewSt{
public:
        AvpLPViewSt avpLPSt;
    char avpMPSt[40];
    char curViewSt[40];
    AvpViewSt()
    {
        memset(avpMPSt,0x0,sizeof(avpMPSt));
        memset(curViewSt,0x0,sizeof(curViewSt));
    }
    const AvpViewSt& operator =(const  AvpViewSt &data)
    {
        avpLPSt=data.avpLPSt;
        memcpy(avpMPSt,data.avpMPSt,sizeof(avpMPSt));
        memcpy(curViewSt,data.curViewSt,sizeof(curViewSt));
        return *this;
    }
};

class VersionSt{
public:
    char sysMCU1Version[32];
    char sysMCU3Version[32];
    char sysLateapp2[32];
    char sysMCU2_0[32];
    char sysMCU2_1[32];
    char sysMCU2_1Uss[32];
    char sysNXP_Boot[32];
    char sysNXP_App[32];
    VersionSt()
    {
        memset(sysMCU1Version,0x0,sizeof(sysMCU1Version));
        memset(sysMCU3Version,0x0,sizeof(sysMCU3Version));
        memset(sysLateapp2,0x0,sizeof(sysLateapp2));
        memset(sysMCU2_0,0x0,sizeof(sysMCU2_0));
        memset(sysMCU2_1,0x0,sizeof(sysMCU2_1));
        memset(sysMCU2_1Uss,0x0,sizeof(sysMCU2_1Uss));
        memset(sysNXP_Boot,0x0,sizeof(sysNXP_Boot));
        memset(sysNXP_App,0x0,sizeof(sysNXP_App));
    }
    const VersionSt& operator =(const VersionSt& data)
    {
        memcpy(sysMCU1Version,data.sysMCU1Version,sizeof(sysMCU1Version));
        memcpy(sysMCU3Version,data.sysMCU3Version,sizeof(sysMCU3Version));
        memcpy(sysLateapp2,data.sysLateapp2,sizeof(sysLateapp2));
        memcpy(sysMCU2_0,data.sysMCU2_0,sizeof(sysMCU2_0));
        memcpy(sysMCU2_1,data.sysMCU2_1,sizeof(sysMCU2_1));
        memcpy(sysMCU2_1Uss,data.sysMCU2_1Uss,sizeof(sysMCU2_1Uss));
        memcpy(sysNXP_Boot,data.sysNXP_Boot,sizeof(sysNXP_Boot));
        memcpy(sysNXP_App,data.sysNXP_App,sizeof(sysNXP_App));
        return *this;
    }
};

//gui->avm
class DevKey{
public:
    char mainDevKey[32];
    char devViewMode[32];
    char command[32];
    char cfgName[32];
    DevKey()
    {
        memset(mainDevKey,0x0,sizeof(mainDevKey));
        memset(devViewMode,0x0,sizeof(devViewMode));
        memset(command,0x0,sizeof(command));
        memset(cfgName,0x0,sizeof(cfgName));
    }
    const DevKey& operator =(const DevKey &data)
    {
        memcpy(mainDevKey,data.mainDevKey,sizeof(mainDevKey));
        memcpy(devViewMode,data.devViewMode,sizeof(devViewMode));
        memcpy(command,data.command,sizeof(command));
        memcpy(cfgName,data.cfgName,sizeof(cfgName));
        return *this;
    }
};

class RotateConfig{
public:
    short dirH;
    float degreeH;
    short dirV;
    float degreeV;
    RotateConfig()
    {
        dirH=0;
        degreeH=0.0f;
        dirV=0;
        degreeV=0.0f;
    }
    const RotateConfig& operator =(const RotateConfig&data)
    {
        dirH=data.dirH;
        degreeH=data.degreeH;
        dirV=data.dirV;
        degreeV=data.degreeV;
        return *this;
    }
};

class DatalogSetting
{
public:
    bool changeFlag;
    bool enableApsLeft;
    bool enableApsRight;
    bool enableApsBoth;
    bool enableLdw;
    bool enableMod;
    bool enablePd;
    bool enableBsdLeft;
    bool enableBsdRight;
    bool enableCameraDirtyDetect;
    bool enableRadar;
    bool enableBaf;
    bool enableDynamicCalib;
    bool enableRelocation;
    bool enableFreespace;
    DatalogSetting()
    {
        changeFlag=false;
        enableApsLeft=false;
        enableApsRight=false;
        enableApsBoth=false;
        enableLdw=false;
        enableMod=false;
        enablePd=false;
        enableBsdLeft=false;
        enableBsdRight=false;
        enableCameraDirtyDetect=false;
        enableRadar=false;
        enableBaf=false;
        enableDynamicCalib=false;
        enableRelocation=false;
        enableFreespace=false;
    }
    const DatalogSetting& operator =(const DatalogSetting &data)
    {
        changeFlag=data.changeFlag;
        enableApsLeft=data.enableApsLeft;
        enableApsRight=data.enableApsRight;
        enableApsBoth=data.enableApsBoth;
        enableLdw=data.enableLdw;
        enableMod=data.enableMod;
        enablePd=data.enablePd;
        enableBsdLeft=data.enableBsdLeft;
        enableBsdRight=data.enableBsdRight;
        enableCameraDirtyDetect=data.enableCameraDirtyDetect;
        enableRadar=data.enableRadar;
        enableBaf=data.enableBaf;
        enableDynamicCalib=data.enableDynamicCalib;
        enableRelocation=data.enableRelocation;
        enableFreespace=data.enableFreespace;
        return *this;
    }
};

class TestDebugSetting
{
public:
    long debugMsgId;
    long debugMsgType;
    long debugMsgValue;
    TestDebugSetting()
    {
        debugMsgId=0;
        debugMsgType=0;
        debugMsgValue=0;
    }
    const TestDebugSetting& operator =(const TestDebugSetting& data)
    {
        debugMsgId=data.debugMsgId;
        debugMsgType=data.debugMsgType;
        debugMsgValue=data.debugMsgValue;
        return *this;
    }
};

class Gui2Apa
{
public:
    char apaFuncName[32];
    char apaParam0;
    char apaParam1;
    char apaParam2;
    char apaParam3;
    char apaParam4;
    char apaParam5;
    char apaParam6;
    char apaParam7;
    Gui2Apa()
    {
        memset(apaFuncName,0x0,sizeof(apaFuncName));
        apaParam0=0;
        apaParam1=0;
        apaParam2=0;
        apaParam3=0;
        apaParam4=0;
        apaParam5=0;
        apaParam6=0;
        apaParam7=0;
    }
    const Gui2Apa& operator !=(const Gui2Apa& data)
    {
        memcpy(apaFuncName,data.apaFuncName,sizeof(apaFuncName));
        apaParam0=data.apaParam0;
        apaParam1=data.apaParam1;
        apaParam2=data.apaParam2;
        apaParam3=data.apaParam3;
        apaParam4=data.apaParam4;
        apaParam5=data.apaParam5;
        apaParam6=data.apaParam6;
        apaParam7=data.apaParam7;
        return *this;
    }
};

class UIGen{
public:
    char viewMode[32];
    char channel[32];
    char factoryFunc[32];
    char calibCmd[32];
    DevKey devKey;
    RotateConfig rotatevalue;
    DatalogSetting datalogSW;
    TestDebugSetting testDbgMsgSet;
    Gui2Apa gui2Apa;
    UIGen()
    {
        memset(viewMode,0x0,sizeof(viewMode));
        memset(channel,0x0,sizeof(channel));
        memset(factoryFunc,0x0,sizeof(factoryFunc));
        memset(calibCmd,0x0,sizeof(calibCmd));
    }

    const UIGen & operator = (const UIGen & data)
    {
        memcpy(viewMode,data.viewMode,sizeof(viewMode));
        memcpy(channel,data.channel,sizeof(channel));
        memcpy(factoryFunc,data.factoryFunc,sizeof(factoryFunc));
        memcpy(calibCmd,data.calibCmd,sizeof(calibCmd));
        devKey=data.devKey;
        rotatevalue=data.rotatevalue;
        datalogSW=data.datalogSW;
        testDbgMsgSet=data.testDbgMsgSet;
        gui2Apa=data.gui2Apa;
        return *this;
    }
};

class Otherst{
public:
    bool CalibHisSt;
    short ipSpeed;
    short steerWheelAngle;
    Otherst()
    {
        CalibHisSt=false;
        ipSpeed=0;
        steerWheelAngle=0;
    }
};

//gui->avp
class AvpEvent{
public:
    char avpMainViewBtn[32];
    char avpLPSearchViewBtn[32];
    char avpLPParkingViewBtn[32];
    char avpLPBuildMapViewBtn[32];
    char avpLPParkOutViewBtn[32];
    AvpEvent()
    {
        memset(avpMainViewBtn,0x0,sizeof(avpMainViewBtn));
        memset(avpLPSearchViewBtn,0x0,sizeof(avpLPSearchViewBtn));
        memset(avpLPParkingViewBtn,0x0,sizeof(avpLPParkingViewBtn));
        memset(avpLPBuildMapViewBtn,0x0,sizeof(avpLPBuildMapViewBtn));
        memset(avpLPParkOutViewBtn,0x0,sizeof(avpLPParkOutViewBtn));
    }
    const AvpEvent &  operator = (const AvpEvent &data)
    {
        memcpy(avpMainViewBtn,data.avpMainViewBtn,sizeof(avpMainViewBtn));
        memcpy(avpLPSearchViewBtn,data.avpLPSearchViewBtn,sizeof(avpLPSearchViewBtn));
        memcpy(avpLPParkingViewBtn,data.avpLPParkingViewBtn,sizeof(avpLPParkingViewBtn));
        memcpy(avpLPBuildMapViewBtn,data.avpLPBuildMapViewBtn,sizeof(avpLPBuildMapViewBtn));
        memcpy(avpLPParkOutViewBtn,data.avpLPParkOutViewBtn,sizeof(avpLPParkOutViewBtn));
        return *this;
    }
};

//avp->avm
class AvpReqAvm{
public:
    char                        avpEnterReq;
    char                        avpViewModeReq;
    char                        avpSearchAlgoReq;
    char                        avpSearchDirReq;
    char                        avpSearchTypeReq;
    char                        avpConfirmSlot;
    short                       avpConfirmMatchSlotIndex;
    char                        avpRelocationReq;
    char                        avpRemoteNetSrvReq;
    char                        hppRemoteNetSrvReq;
    long                        avpConfirmManuSlot_type;
    long                        avpConfirmManuSlot_x;
    long                        avpConfirmManuSlot_y;
    long                        avpConfirmManuSlot_angle;
    char                        hppSaveMapIndexReq;
    AvpReqAvm()
    {
        avpEnterReq=0;
        avpViewModeReq=0;
        avpSearchAlgoReq=0;
        avpSearchDirReq=0;
        avpSearchTypeReq=0;
        avpConfirmSlot=0;
        avpConfirmMatchSlotIndex=0;
        avpRelocationReq=0;
        avpRemoteNetSrvReq=0;
        hppRemoteNetSrvReq=0;
        avpConfirmManuSlot_type=0;
        avpConfirmManuSlot_x=0;
        avpConfirmManuSlot_y=0;
        avpConfirmManuSlot_angle=0;
        hppSaveMapIndexReq=0;
    }
};

//avm->avp
class ApaTargetSlotPlaceExTest
{
public:
    unsigned long long  ullCameraFrameNo;//picture frame No
    unsigned long    	ulAlgStartTime;//alg start time
    unsigned long        ulAlgEndTime;//alg end time
    unsigned long        ulApsSlotInfoFrameNo; //aps slot info frame No
    long  			    iRecommedLable;//aps recommend label No, -1: NO recommend slot
    ApaTargetSlotPlaceExTest()
    {
        ullCameraFrameNo=0;
        ulAlgStartTime=0;
        ulAlgEndTime=0;
        ulApsSlotInfoFrameNo=0;
    }
};
class ApaTargetSlotPlace {
public:
    char                        apaSlotStatus;//0:invalid,1:valid
    char                        apaSlotType;//0:PERPENDICULAR,1:PARALLEL,2:DIAGONAL,3:MAXTYPE
    short                       apaSlotA_x;//unit:mm, target slot A point x coordinate
    short                       apaSlotA_y;//unit:mm, target slot A point y coordinate
    short                       apaSlotB_x;//unit:mm, target slot B point x coordinate
    short                       apaSlotB_y;//unit:mm, target slot B point y coordinate
    short                       apaSlotC_x;//unit:mm, target slot C point x coordinate
    short                       apaSlotC_y;//unit:mm, target slot C point y coordinate
    short                       apaSlotD_x;//unit:mm, target slot D point x coordinate
    short                       apaSlotD_y;//unit:mm, target slot D point y coordinate
    char                        apaSlotIndex;//slot index
    char                        apaSlotFusionType;//0:AVM_ONLY,1:ULTRA_ONLY,2:AVM_ULTRA,3:MAX
    char                        apaSlotDownSlotSOD;//0:up unknown and down unknown
                                                   //1:up unknown and down null
                               //2:up unknown and down SOD
                               //3:up null and down unknown
                               //4:up null and down null
                               //5:up null and down SOD
                               //6:up SOD and down unknown
                               //7:up SOD and down null
                               //8:up SOD and down SOD
    short                       apaSlotDriveSpaceEnough;
    short                       apaSlotLevel;//Sort by distance from smallest to largest
    short                       apaSlotMinOtherSideDist;//Min other side distance
    short                       apaSlotRoadEdgeDist;//Road edge distance
    char                        apaSlotSceneType;//Scene type:2:Floor tile scenario, others:No Floor tile scenario
    short                       apaSlotLabel;
    ApaTargetSlotPlace()
    {
        apaSlotStatus=0;//0:inva
        apaSlotType=0;//0:PERPEN
        apaSlotA_x=0;//unit:mm,
        apaSlotA_y=0;//unit:mm,
        apaSlotB_x=0;//unit:mm,
        apaSlotB_y=0;//unit:mm,
        apaSlotC_x=0;//unit:mm,
        apaSlotC_y=0;//unit:mm,
        apaSlotD_x=0;//unit:mm,
        apaSlotD_y=0;//unit:mm,
        apaSlotIndex=0;//slot in
        apaSlotFusionType=0;//0:
        apaSlotDownSlotSOD=0;//0
        apaSlotDriveSpaceEnough=0;
        apaSlotLevel=0;//Sort by
        apaSlotMinOtherSideDist=0;
        apaSlotRoadEdgeDist=0;//
        apaSlotSceneType=0;//Sce
        apaSlotLabel=0;
    }
};

class ApaRelocationExTest{
public:
    unsigned long long	    	ullCameraFrameNo;//picture frame No
    unsigned long    	    	ulAlgStartTime;//Reloc start time
    unsigned long               ulAlgEndTime;//Reloc end time
    unsigned long               ulRelocFrameNo;//Reloc frame No
    ApaRelocationExTest()
    {
        ullCameraFrameNo=0;
        ulAlgStartTime=0;
        ulAlgEndTime=0;
        ulRelocFrameNo=0;
    }
};

class ApaRelocationInfo {
public:
    char                        apaVerSlotLeftLine;//0:no detected, 1:vertical slot left line detected laterally, 2:vertical slot left line detected longitudinally
    char                        apaVerSlotRightLine;//0:no detected, 1:vertical slot right line detected laterally, 2:vertical slot right line detected longitudinally
    float                       apaVerSlotLeftLineTheta;//Angle between vertical slot left line and Y axis, unit:degree, range:-90.000~90.000 degree
    float                       apaVerSlotRightLineTheta;//Angle between vertical slot right line and Y axis, unit:degree, range:-90.000~90.000 degree
    float                       apaVerSlotDistL;//if apaVerSlotLeftLine == 1, lateral distance between vertical slot left line and left rear point of car, unit:mm
                                                    //if apaVerSlotLeftLine == 2, longitudinal distance between vertical slot left line and left rear point of car, unit:mm
    float                       apaVerSlotDistR;//if apaVerSlotRightLine == 1, lateral distance between vertical slot right line and right rear point of car, unit:mm
                                                    //if apaVerSlotRightLine == 2, longitudinal distance between vertical slot right line and right rear point of car, unit:mm
    char                        apaParSlotUpLine;//0:no detected
                                                    //3:the x-direction distance between parallel slot upper shot line and left rear point of car, unit:mm
                                                    //4:the x-direction distance between parallel slot upper shot line and right rear point of car, unit:mm
                                                    //5:the y-direction distance between parallel slot upper shot line and left rear point of car, unit:mm
                                                    //6:the y-direction distance between parallel slot upper shot line and right rear point of car, unit:mm
    char                        apaParSlotDownLine;//0:no detected
                                                    //3:the x-direction distance between parallel slot lower shot line and left rear point of car, unit:mm
                                                    //4:the x-direction distance between parallel slot lower shot line and right rear point of car, unit:mm
                                                    //5:the y-direction distance between parallel slot lower shot line and left rear point of car, unit:mm
                                                    //6:the y-direction distance between parallel slot lower shot line and right rear point of car, unit:mm
    float                       apaParSlotUpTheta;//Angle between parallel slot upper line and Y axis, positive number in the first quadrant, negative numbers in the fourth quadrant
                                                    //unit:degree, range:-90.000~90.000 degree
    float                       apaParSlotDownTheta;//Angle between parallel slot lower line and Y axis, positive number in the first quadrant, negative numbers in the fourth quadrant
                                                    //unit:degree, range:-90.000~90.000 degree
    float                       apaParSlotUpLineDist;//parallel slot upper shot line distance, unit:mm
    float                       apaParSlotDownLineDist;//parallel slot lower shot line distance, unit:mm
    long                        apaAbsoluteDeltaX;//unit:mm,The DR corresponding to the relocation data at the current moment is used to remove transmission delay
    long                        apaAbsoluteDeltaY;//unit:mm,The DR corresponding to the relocation data at the current moment is used to remove transmission delay
    short                       apaAbsoluteAngle;//unit:0.1 degree,The DR corresponding to the relocation data at the current moment is used to remove transmission delay
    char                        apaLeftResultSource;//1:Left camera detected, 2:Front and Rear camera detected;3.Fuse
    char                        apaRightResultSource;//1:Right camera detected, 2:Front and Rear camera detected;3.Fuse
    ApaRelocationInfo()
    {
        apaVerSlotLeftLine=0;//0:no d
        apaVerSlotRightLine=0;//0:no
        apaVerSlotLeftLineTheta=0.0f;//A
        apaVerSlotRightLineTheta=0.0f;//
        apaVerSlotDistL=0.0f;//if apaVer
                            //if ap
        apaVerSlotDistR=0.0f;//if apaVer
                            //if ap
        apaParSlotUpLine=0;//0:no det

        apaParSlotDownLine=0;//0:no d

        apaParSlotUpTheta=0.0f;//Angle b

        apaParSlotDownTheta=0.0f;//Angle

        apaParSlotUpLineDist=0.0f;//
        apaParSlotDownLineDist=0.0f;//
        apaAbsoluteDeltaX=0;//
        apaAbsoluteDeltaY=0;//
        apaAbsoluteAngle=0;//
        apaLeftResultSource=0;//
        apaRightResultSource=0;//
    }
};

class AvpSimCmd{
public:
    short                       avpSysSts;
    short                       avpAlgoSts;
    short                       avpSoftKey;
    short                       avpRemoteReq;
    short                       avpParkingPercent;
    AvpSimCmd()
    {
        avpSysSts=0;
        avpAlgoSts=0;
        avpSoftKey=0;
        avpRemoteReq=0;
        avpParkingPercent=0;
    }
};

class AvmRespAvp{
public:
    AvpSimCmd                   avpSimCmd;
    char                        avpSearchAlgoState;
    char                        avpSearchOrParkSlot;
    ApaTargetSlotPlace          avpSlotInfo;
    ApaRelocationInfo           avpRelocationInfo;
    char                        hppSaveMapIndexResp;
    char                        hppCSDState;
    AvmRespAvp()
    {
        avpSearchAlgoState=0;
        avpSearchOrParkSlot=0;
        hppSaveMapIndexResp=0;
        hppCSDState=0;
    }
};

class AvmRespAvpEx{
public:
    AvmRespAvp avmRespAvp;
    ApaTargetSlotPlaceExTest targetSlotTest;
    ApaRelocationExTest		 relocaTest;
    AvmRespAvpEx()
    {

    }
};

//update_service->gui
class UpdateMsg{
public:
    char updateModul[32];
    unsigned short updateProcess;
    UpdateMsg()
    {
        memset(updateModul,0x0,sizeof(updateModul));
        updateProcess=0;
    }
    const UpdateMsg & operator =(const UpdateMsg& data)
    {
        memcpy(updateModul,data.updateModul,sizeof(updateModul));
        updateProcess=data.updateProcess;
        return *this;
    }
};

class EolAvmRequest {
public:
	// 0 :    no request
	// 1 :    2D Rear
	// 2 :    2D Front
	// 3 :    Front Wide
	// 4 :    Rear Wide
	// 5 :    Left Wide
	// 6 :    Right Wide
	// 7 :    3D Left Front View
	// 8 :    3D Right Front View
	// 9 :    Front Round View 
    char avmViewReq;
    EolAvmRequest()
    {
        avmViewReq = 0;
    }
};

// AVM --> eol_app
// topic: "eol_avm_response"
class EolAvmResponse {
public:
	// 0 :    no request
	// 1 :    2D Rear
	// 2 :    2D Front
	// 3 :    Front Wide
	// 4 :    Rear Wide
	// 5 :    Left Wide
	// 6 :    Right Wide
	// 7 :    3D Left Front View
	// 8 :    3D Right Front View
	// 9 :    Front Round View 
    char avmViewReq;
    // 0 : Failure
    // 1 : Success
    char avmSwitchResp;
    EolAvmResponse()
    {
        avmViewReq = 0;
        avmSwitchResp = 0;
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

class EthCmdData {
public:
	EthCmdData():
		sid(0)
	  , oid(0)
	  , opType(0)
	  , dataType(0)
	  , proc(false)
	  , payload{0}
	  , payloadSize(0)
	  , errorCode(0)
	  , senderHandleID(0)
	{

	}

	EthCmdData(const EthCmdData& msg)
	{
		sid = msg.sid;
		oid = msg.oid;
		opType = msg.opType;
		dataType = msg.dataType;
		proc = msg.proc;
		memcpy(payload,msg.payload,msg.payloadSize);
		payloadSize = msg.payloadSize;
		errorCode = msg.errorCode;
		senderHandleID = msg.senderHandleID;
	}
	EthCmdData(const EthCmdData&& msg)
	{
		sid = msg.sid;
		oid = msg.oid;
		opType = msg.opType;
		dataType = msg.dataType;
		proc = msg.proc;
		memcpy(payload,msg.payload,msg.payloadSize);
		payloadSize = msg.payloadSize;
		errorCode = msg.errorCode;
		senderHandleID = msg.senderHandleID;
	}

	const EthCmdData& operator = (const EthCmdData& msg)
	{
		sid = msg.sid;
		oid = msg.oid;
		opType = msg.opType;
		dataType = msg.dataType;
		proc = msg.proc;
		memcpy(payload,msg.payload,msg.payloadSize);
		payloadSize = msg.payloadSize;
		errorCode = msg.errorCode;
		senderHandleID = msg.senderHandleID;
                return *this;
	}

public:
    /************************************************
    * Variable "sid"
    * Its value is the enumerated type "SrvId_e" defined in the file "DataDefine.h".
    * Choose different sid according to different functions:
    * DVR SID: SRV_ID_DVR
    * AVP SID: SRV_ID_AVP
    * HPP SID: SRV_ID_HPP
    * Image transmission SID: SRV_ID_IMG_TRANSMISSION
    * Testapp SID: SRV_ID_TEST_SERVICE

    * Note: For detailed function corresponding sid values,
    *	    please refer to "SWRS", "GEEA2.0 IP Communication Message PAS_V10_Release_20200711"
    *	    and "EthServicesInfo-TestService-V0.1".
    *************************************************/
	uint16_t sid;  // The service id.

    /************************************************
    * Variable "oid"
    * Its value is the enumerated type "OpImgT_e", "OpAVP_e", "OpHPP_e", "OpId_e"
    * defined in the file "DataDefine.h".
    * Choose different oid according to different functions:
    * AVP OID: OpAVP_e
    * HPP OID: OpHPP_e
    * Image transmission OID: OpImgT_e
    * Testapp OID: OpId_e

    * Note: For detailed function corresponding Oid values,
    *	    please refer to "SWRS", "GEEA2.0 IP Communication Message PAS_V10_Release_20200711"
    *	    and "EthServicesInfo-TestService-V0.1".
    *************************************************/
	uint16_t oid; // The operation id.

    /************************************************
    * Variable "opType"
    * REQUEST:		    0x00
    * SETREQUEST_NORETURN:  0x01
    * SETREQUEST:	    0x02
    * NOTIFICATION_REQUEST: 0x03
    * RESPONSE:		    0x04
    * NOTIFICATION:	    0x05
    * NOTIFICATION_CYCLIC:  0x06
    * ERROR:		    0xE0

    * Note: For specific service corresponding message types,
    *	    please refer to "SWRS", "GEEA2.0 IP Communication Message PAS_V10_Release_20200711"
    *	    and "EthServicesInfo-TestService-V0.1".
    *************************************************/
	uint8_t opType;

    /************************************************
    * Variable "dataType"
    * Encoded message:	0x00 (Indicates that the payload (data) is encoded(ASN.1) according to requirement.)
    * Normal message:	0x01 (The payload (data) is send without any encoding(ASN.1).)

    * Note: For specific service corresponding message types,
    *	    please refer to "SWRS", "GEEA2.0 IP Communication Message PAS_V10_Release_20200711"
    *	    and "EthServicesInfo-TestService-V0.1".
    *************************************************/
	uint8_t dataType;

    /************************************************
    * Variable "proc"

    * The proc -flag is 1 bit and shall have the default value 0x0. It defines an alternative handling
    * procedure by a server. Messages (with operationIDs) that initiate a time consuming process at
    * the server shall have this flag set to 1 to make the server keep track of the message. The proc -
    * flag applies only for messages with operation types Request and SetRequest, since the
    * message flows includes a Response that may take more or less time for the server to send
    * back to the client. Only the function designer shall decide if this flag should be set to 0x1 for a
    * particular message. If a message of a type other than Request or SetRequest in combination
    * with proc-flag set to 0x1 is received the server shall continue processing the message as if the
    * proc-flag was set 0.

    * A state Processing shall be defined for the alternative handling process of messages where the
    * proc -flag is relevant. The handling process shall enter this state when the message has been
    * acknowledged and exit when the Response message has been sent. While in this state the
    * server shall responde with an ERROR message with error code processing.

    * If the server is busy processing an operationID requested with the proc -flag
    * set to 0x1 and the same operationID is requested within a new message,
    * it shall drop the newly received message and respond with an ERROR message using the ErrorCode processing.
    *	Note: This error mechanism is implemented by the protocol stack.
    *************************************************/
    bool proc;

    /************************************************
    * Variable "payload"
    * user's data
    *************************************************/
	uint8_t payload[128];// The payload which is the user's data.
	uint8_t payloadSize;

    /************************************************
    * Variable "errorCode"
    * 0x00: Not Ok - An unspecified error occurred
    * 0x01: ServiceID not available - The Service is not available or does not exist
    * 0x02: OperationID not available - The Operation is not available or does not exist
    * 0x03: OperationType is not available - Invalid OperationType
    * 0x04: Invalid protocol version - Invalid protocol version, return the supported Protocol Version
    * 0x05: Processing - This error code indicates that the requested operation ID is already processing a previous request.
    * 0x06: Invalid Length - The length of the message is not correct
    * 0x07: Application Error - Application not ready
    * 0x08: Timeout - Timeout occurred
    * 0x09: Busy - The server is concurrenty handling maximum number of messages and cannot process the message.
    * 0x0A – 0x1f: RESERVED Reserved for generic errors.
    * 0x20 – 0x3f: RESERVED Reserved for specific errors of services and operations.
    *	Note: The above error message types are generated by the protocol stack.

    * 0x20: IncorrectState - Operation or OpType not valid in the current state.
    * 0x23: Asn1decodeError - ASN.1 could not be decoded. Possible for all operations.
    * 0x24: ParameterInvalid - Possible for all operations.
    *	Note: The above three types of error messages are generated by the application.

    * Note: If and only when opType is 0xE0 (ERROR), the content of this variable is valid.
    *************************************************/
	uint8_t errorCode;

    /************************************************
    * Variable "senderHandleID"

    * |---------------------|---------------------|--------------------|---------------------|
    * |  ServiceID[8 bits]  | OperationID[8 bits] |   OpType[8 bits]   |    SeqNr[8 bits]    |
    * |---------------------|---------------------|--------------------|---------------------|

    *The picture above illustrates the way the SenderHandleID shall be constructed to fulfill the required behavior.
    *ServiceID shall consist of the last byte of the 16 bit ServiceID.
    *OperationID shall consist of the last byte of the 16 bit OperationID.
    *OpType shall use the same value as the OpType.
    *SeqNr is a sequence number shall be locally unique in the client application for each message to be sent.

    * Note: The senderHandleID is used by the protocol stack.
    *       The application only needs to copy the senderHandleID to the corresponding response message when receiving the request or set request message.
    *       In other cases, the content of the senderHandleID variable can be ignored.
    *************************************************/
	uint32_t senderHandleID;
};
//http && rtp
/*
enum Https_HttpsStatus {
    STATUS_POST_SUCCESS = 0,
    STATUS_POST_FAIL = 1,
    STATUS_DOWNLOAD_SUCCESS = 2,
    STATUS_DOWNLOAD_FAIL = 3,
    STATUS_HTTPS_RESERVE = 4
};

class Https_HttpsStatusReport {
public:
    Https_HttpsStatus httpsStatus;
    Https_HttpsStatusReport()
    {
        httpsStatus=STATUS_POST_SUCCESS;
    }
};

class Https_HttpsReq {
public:
    char    name[128];
    char    url[128];
    char    token[128];
    char    pem[128];
    Https_HttpsReq()
    {
        memset(name,0,sizeof(name));
        memset(url,0,sizeof(url));
        memset(token,0,sizeof(token));
        memset(pem,0,sizeof(pem));
    }
    const Https_HttpsReq& operator =(const Https_HttpsReq& data)
    {
        memcpy(name,data.name,sizeof(name));
        memcpy(url,data.url,sizeof(url));
        memcpy(token,data.token,sizeof(token));
        memcpy(pem,data.pem,sizeof(pem));
        return *this;
    }
};

enum Https_HttpsKinds {
    POSTREQ,
    DOWNLOADREQ
};
class Https_HttpsTypes_stru
{
public:
    Https_HttpsReq   postReq ;
    Https_HttpsReq   downloadReq ;
    Https_HttpsTypes_stru()
    {

    }
};
*/
/************************************************************************************************
* LmIPActivityReqData
*
*  variable: resourceGroupX
*  ranges:   true/false
*            true:  Request RGX.
*            false: Release RGX.
*  brief:    Whether to request RGX.
*
*  variable: prioX
*  Ranges:   0x00-0x01
*            0x00: The priority of the request to RGX is PRIO_NORM.
*            0x01: The priority of the request to RGX is PRIO_HIGH.
*  brief:    Priority of requests to RGX. Valid when resourceGroupX is true.
*
*  variable: lsc
*  Ranges:   0x00-0x04
*            0x00: AVM
*            0x01: AVP
*            0x02: HPP
*            0x03: network
*            0x04: ipcp_testapp
*  brief:    Which LSC issued the current request.
*
* Note: APP -> LM
*       When the application needs to send an RG request,
*       it is sent to the LM through this data type.
*************************************************************************************************/
class LmIPActivityReqData {
public:
	const LmIPActivityReqData& operator = (const LmIPActivityReqData& data)
	{
		resourceGroup1 = data.resourceGroup1;
		prio1 = data.prio1;

		resourceGroup2 = data.resourceGroup2;
		prio2 = data.prio2;

		resourceGroup3 = data.resourceGroup3;
		prio3 = data.prio3;

		resourceGroup4 = data.resourceGroup4;
		prio4 = data.prio4;

		resourceGroup5 = data.resourceGroup5;
		prio5 = data.prio5;

		resourceGroup6 = data.resourceGroup6;
		prio6 = data.prio6;

		resourceGroup7 = data.resourceGroup7;
		prio7 = data.prio7;

		lsc = data.lsc;
                return *this;
	}

public:
    bool resourceGroup1;
    char prio1;

    bool resourceGroup2;
    char prio2;

    bool resourceGroup3;
    char prio3;

    bool resourceGroup4;
    char prio4;

    bool resourceGroup5;
    char prio5;

    bool resourceGroup6;
    char prio6;

    bool resourceGroup7;
    char prio7;

    char lsc;
};

/************************************************************************************************
* LmExternalReqStatusData
*
*  variable: resourceGroupX
*  ranges:   true/false
*            true:  Request RGX.
*            false: Release RGX.
*  brief:    Whether to request RGX.
*
*  variable: prioX
*  Ranges:   0x00-0x01
*            0x00: The priority of the request to RGX is PRIO_NORM.
*            0x01: The priority of the request to RGX is PRIO_HIGH.
*  brief:    Priority of requests to RGX. Valid when resourceGroupX is true.
*
* Note: LM -> APP
*       When an external RG requests an update, the LM sends an external RG request to the
*       application through this data type.
*************************************************************************************************/
class LmExternalReqStatusData {
public:
    bool resourceGroup1;
    char prio1;

    bool resourceGroup2;
    char prio2;

    bool resourceGroup3;
    char prio3;

    bool resourceGroup4;
    char prio4;

    bool resourceGroup5;
    char prio5;

    bool resourceGroup6;
    char prio6;

    bool resourceGroup7;
    char prio7;
};

class LmRG4DvrIpActive {
public:
    bool req;
};

/************************************************************************************************
* LmTestSuspendData
*
*  variable: StartTime
*  ranges:   0x0000-0xFFFF
*  brief:    The time when the LM message is suspended.
*
*  variable: DurationTime
*  ranges:   0x0000-0xFFFF
*  brief:    The duration of the LM message suspension.
*
*
* Note: ipcp_testapp -> LM
*       Used for LM testing.
*       Pause/resume sending of LM messages.
*************************************************************************************************/
class LmTestSuspendData {
public:
    short StartTime;
    short DurationTime;
};

/************************************************************************************************
* LmTestCheckARS
*
* Note: ipcp_testapp -> LM
*************************************************************************************************/
class LmTestCheckARS {
public:
	char ipAddress[12];
    unsigned long senderHandleID;
};
const uint8_t lmTestCheckARSBaseLength = (sizeof(LmTestCheckARS) - sizeof(LmTestCheckARS::ipAddress));

/************************************************************************************************
* LmTestARSStaResp
*
* Note: LM -> ipcp_testapp
*************************************************************************************************/
class LmTestARSStaResp {
public:
    bool status;
    unsigned long senderHandleID;
};

/************************************************************************************************
* LmTestCheckOR
*
* Note: ipcp_testapp -> LM
*************************************************************************************************/
class LmTestCheckOR {
public:
    bool check;
    unsigned long senderHandleID;
};

/************************************************************************************************
* LmTestORStaResp
*
* Note: LM -> ipcp_testapp
*************************************************************************************************/
class LmTestORStaResp {
public:
    bool status;
    unsigned long senderHandleID;
};
//POWERM
enum PowerMOpType {
	DDS_POWER_OP_TYPE_UNKNOW=0,
	DDS_POWER_OP_TYPE_REQ,
	DDS_POWER_OP_TYPE_REQRSP,
	DDS_POWER_OP_TYPE_IND,
	DDS_POWER_OP_TYPE_INDRSP,
	DDS_POWER_OP_TYPE_INIT
};
enum PowerMReqType {
	DDS_POWER_REQ_UNKNOW=0,
	DDS_POWER_REQ_OPEN,
	DDS_POWER_REQ_CLOSE,
	DDS_POWER_REQ_ON,
	DDS_POWER_REQ_OFF ,
	DDS_POWER_REQ_WAKEUP,
	DDS_POWER_REQ_SLEEP,
	DDS_POWER_REQ_SUSPEND,
	DDS_POWER_REQ_RESUME,
	DDS_POWER_REQ_FUSA = 0xFF
};
enum PowerMRespStaType {
	DDS_POWER_STATUS_UNKNOW = 0,
	DDS_POWER_STATUS_OPEN_ING,
	DDS_POWER_STATUS_OPEN_TIMEOUT,
	DDS_POWER_STATUS_OPEN_END,
	DDS_POWER_STATUS_CLOSE_ING,
	DDS_POWER_STATUS_CLOSE_TIMEOUT,
	DDS_POWER_STATUS_CLOSE_END,
	DDS_POWER_STATUS_ON_ING,
	DDS_POWER_STATUS_ON_TIMEOUT,
	DDS_POWER_STATUS_ON_END,
	DDS_POWER_STATUS_OFF_ING,
	DDS_POWER_STATUS_OFF_TIMEOUT,
	DDS_POWER_STATUS_OFF_END,
	DDS_POWER_STATUS_WAKEUP_ING,
	DDS_POWER_STATUS_WAKEUP_TIMEOUT,
	DDS_POWER_STATUS_WAKEUP_END,
	DDS_POWER_STATUS_SLEEP_ING,
	DDS_POWER_STATUS_SLEEP_TIMEOUT,
	DDS_POWER_STATUS_SLEEP_END,
	DDS_POWER_STATUS_SUSPEND_ING,
	DDS_POWER_STATUS_SUSPEND_TIMEOUT,
	DDS_POWER_STATUS_SUSPEND_END,
	DDS_POWER_STATUS_RESUME_ING,
	DDS_POWER_STATUS_RESUME_TIMEOUT,
	DDS_POWER_STATUS_RESUME_END,
	DDS_POWER_STATUS_FUSA_END = 0xFF
};

class PowerMToCom {
public:
	long pid;
	PowerMOpType opType;
	PowerMReqType req;
	PowerMRespStaType ind;
	unsigned long indResp; //1:success;0:fail;
	PowerMToCom()
	{
		pid=0;
		opType=DDS_POWER_OP_TYPE_UNKNOW;
		req=DDS_POWER_REQ_UNKNOW;
		ind=DDS_POWER_STATUS_UNKNOW;
		indResp=0;
	}
};

class PowerMToSrv {
public:
	long pid;
	PowerMOpType opType;
	PowerMReqType req;
	PowerMRespStaType reqResp;
	PowerMRespStaType ind;
	PowerMToSrv()
	{
		pid=0;
		opType=DDS_POWER_OP_TYPE_UNKNOW;
		req=DDS_POWER_REQ_UNKNOW;
		reqResp=DDS_POWER_STATUS_UNKNOW;
		ind=DDS_POWER_STATUS_UNKNOW;
	}
};
/*
//RTP
class Rtp_RtpOnReq {
public:
    bool rtpOnReq;
    Rtp_RtpOnReq()
    {
        rtpOnReq=false;
    }
};

enum Rtp_RTPStatus {
    STATUS_RTP_OFF = 0,
    STATUS_RTP_STANDBY = 1,
    STATUS_RTP_SENDING = 2,
    STATUS_RTP_FAILURE = 3
};

class Rtp_RtpStatusReport {
public:
    Rtp_RTPStatus rtpStatus;
    Rtp_RtpStatusReport()
    {
        rtpStatus=STATUS_RTP_OFF;
    }
};

class Rtp_RtpSettingReq {
public:
    char    ip_[128];
    unsigned short port_;
    long           SSRC_;
    unsigned short fps_;
    Rtp_RtpSettingReq()
    {
        memset(ip_,0x0,sizeof(ip_));
        port_=0;
        SSRC_=0;
        fps_=0;
    }
    const Rtp_RtpSettingReq& operator =(const Rtp_RtpSettingReq& data)
    {
        memcpy(ip_,data.ip_,sizeof(ip_));
        port_=data.port_;
        SSRC_=data.SSRC_;
        fps_=data.fps_;
        return *this;
    }
};

enum Rtp_RtpKinds {
    RTPONREQ,
    RTPSETREQ
};

class Rtp_RtpTypes_stru
{
public:
    Rtp_RtpOnReq   onReq ;
    Rtp_RtpSettingReq   setReq ;
};
*/

static const char * const  DDS_TOPIC_EOL_REQUEST = "eol_request";
static const char * const  DDS_TOPIC_EOL_RESPONSE = "eol_response";
static const char * const  DDS_TOPIC_UDS_COMMON_REQUEST = "app_uds_common_request";
static const char * const  DDS_TOPIC_UDS_COMMON_RESPONSE = "app_uds_common_response";

const unsigned short EOL_MAX_DATA_LEN = 512;
const unsigned short UDS_MAX_DATA_LEN = 512;

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

//uds
class UdsCommonMessage {
public:
    char sid;
    char subFunction;
    unsigned short dataLength;
    char data[UDS_MAX_DATA_LEN];
    UdsCommonMessage()
    {
        sid=0;
        subFunction=0;
        dataLength=0;
        memset(data,0x0,sizeof(data));
    }
    const UdsCommonMessage& operator =(const UdsCommonMessage& msg)
    {
        sid=msg.sid;
        subFunction=msg.subFunction;
        dataLength=msg.dataLength;
        memcpy(data,msg.data,sizeof(data));
        return *this;
    }
};

//rid request

class SetAvmButtonStatus{
public:
    char prkgIndcrLineReqSt;
    char surrndgsObjDetnReqSt;
    char thrDTouringViewReqSt;
    char topVisnDispExtnReqSt;
    char turnEntryAgWideVisReqSt;
    char vehMdlClrReqSt;
    char visnAgExtnReqSt;
    SetAvmButtonStatus()
    {
        prkgIndcrLineReqSt=0;
        surrndgsObjDetnReqSt=0;
        thrDTouringViewReqSt=0;
        topVisnDispExtnReqSt=0;
        turnEntryAgWideVisReqSt=0;
        vehMdlClrReqSt=0;
        visnAgExtnReqSt=0;
    }
};
class AppRidRequest{
public:
    char cameraFactoryCalibration;
    char factoryMode;
    char shift2DView;
    char shift3DView;
    SetAvmButtonStatus setAvmButtonSt;
    char enterExitAVM;
    char outputImage;
    AppRidRequest()
    {
        cameraFactoryCalibration=0;
        factoryMode=0;
        shift2DView=0;
        shift3DView=0;
        enterExitAVM=0;
        outputImage=0;
    }
};

class AppRidResponse{
public:
    char cameraFactoryCalibration;
    char factoryMode;
    char shift2DView;
    char shift3DView;
    char setAvmButtonSt;
    char enterExitAVM;
    char outputImage;
    AppRidResponse()
    {
        cameraFactoryCalibration=0;
        factoryMode=0;
        shift2DView=0;
        shift3DView=0;
        setAvmButtonSt=0;
        enterExitAVM=0;
        outputImage=0;
    }
};

//dtc status
class AppDtcStatus{
public:
    char dtc_D03600;
    char dtc_D09000;
    char dtc_E40057;
    char dtc_EF0148;
    char dtc_EF0800;
    char dtc_EF0A46;
    char dtc_EF0C46;
    char dtc_EF0D04;
    char dtc_EF2076;
    char dtc_EF2176;
    char dtc_EF2276;
    char dtc_EF2376;
    char dtc_EF5400;
    char dtc_EF5500;
    char dtc_EF5900;
    char dtc_EF8100;
    AppDtcStatus()
    {
        dtc_D03600=0;
        dtc_D09000=0;
        dtc_E40057=0;
        dtc_EF0148=0;
        dtc_EF0800=0;
        dtc_EF0A46=0;
        dtc_EF0C46=0;
        dtc_EF0D04=0;
        dtc_EF2076=0;
        dtc_EF2176=0;
        dtc_EF2276=0;
        dtc_EF2376=0;
        dtc_EF5400=0;
        dtc_EF5500=0;
        dtc_EF5900=0;
        dtc_EF8100=0;
    }
};

class CalibPhyData{
public:
    unsigned short front_CoordinateX;
    unsigned short front_DegreeX;
    unsigned short front_DegreeY;
    unsigned short front_DegreeZ;
    unsigned short rear_CoordinateX;
    unsigned short rear_DegreeX;
    unsigned short rear_DegreeY;
    unsigned short rear_DegreeZ;
    unsigned short left_CoordinateX;
    unsigned short left_DegreeX;
    unsigned short left_DegreeY;
    unsigned short left_DegreeZ;
    unsigned short right_CoordinateX;
    unsigned short right_DegreeX;
    unsigned short right_DegreeY;
    unsigned short right_DegreeZ;
    CalibPhyData()
    {
        front_CoordinateX=0;
        front_DegreeX=0;
        front_DegreeY=0;
        front_DegreeZ=0;
        rear_CoordinateX=0;
        rear_DegreeX=0;
        rear_DegreeY=0;
        rear_DegreeZ=0;
        left_CoordinateX=0;
        left_DegreeX=0;
        left_DegreeY=0;
        left_DegreeZ=0;
        right_CoordinateX=0;
        right_DegreeX=0;
        right_DegreeY=0;
        right_DegreeZ=0;
    }
};

class AppDidData{
public:
    unsigned short sysUsgModSts;
    unsigned short sysCarModSts;
    char PwrLvlElecMai;
    unsigned short vehicleSpeed;
    AppDidData()
    {
        sysUsgModSts=0;
        sysCarModSts=0;
        PwrLvlElecMai=0;
        vehicleSpeed=0;
    }
};

// app --> udsapp
// topic: "app2uds"
enum AppMsgKinds {
    APPRIDRESPONSE,
    APPDTCRESPONSE,
    CALIBPHYDATA,
    APPDIDDATA,
    UDSCOMMONMESSAGE
};

/****************apbsd_result*********************/
    const short aroundview_apbsd_result_msg_EAGLE_AV_MAX_APBSD_OBJECT = 400;

class aroundview_apbsd_result_msg_APillar_DetResult{
public:
    long classid; //类型
    float score;// 0.0 ~ 1.0
    long camerid; //哪个相机检出
     /* object position in input image [px] */
    /* trace */
    long trackingId;
    long x;
    long y;
    long width;
    long height;
    /* object position in the real world */
    float groundX[3];    // [m] 框底边中点，起点，终点
    float groundY[3];    // [m]
    float distance;   // [m]
    float speed;      // [km/h]
    float speedX;
    float speedY;
    float obj_width;
    long    direction;  // -180 ~ 180 [deg]
    short movement;//0-��ֹ 2-Զ��  3-����
    char selected;
} ; //A柱输出结果

class aroundview_apbsd_result_msg_apbsd_result_info {
public:
    long DetNums;
    aroundview_apbsd_result_msg_APillar_DetResult ApbsdResult[aroundview_apbsd_result_msg_EAGLE_AV_MAX_APBSD_OBJECT];
    unsigned long	  AbsoluteDeltaX;
    unsigned long    AbsoluteDeltaY;
    unsigned short    AbsoluteDeltaAngle;
    unsigned long long time_stamp;
    unsigned long long frame_id;
    unsigned long long start_time_stamp;
    unsigned long long finish_time_stamp;
    long RollingCouter;
} ;

/****************freespace_result*********************/
const short aroundview_freespace_result_msg_EAGLE_AV_FREESPACE_MAX_FUSION_OBJECT = 360;
const short aroundview_freespace_result_msg_EAGLE_AV_FREESPACE_CH = 4;
class aroundview_freespace_result_msg_msg_POINT_s{
public:
    short x;
    short y;
    short type;
} ;
class aroundview_freespace_result_msg_msg_FS_Fusion_Result{
public:
    unsigned long     	frameID;
    unsigned long long time_stamp;
    unsigned long	  AbsoluteDeltaX;
    unsigned long    AbsoluteDeltaY;
    unsigned short    AbsoluteDeltaAngle;
    unsigned long            iPointNum;
    aroundview_freespace_result_msg_msg_POINT_s      sPoint[aroundview_freespace_result_msg_EAGLE_AV_FREESPACE_MAX_FUSION_OBJECT];
} ;

class aroundview_freespace_result_msg_freespace_result_info {
public:
    char channel_enable[aroundview_freespace_result_msg_EAGLE_AV_FREESPACE_CH];
    aroundview_freespace_result_msg_msg_FS_Fusion_Result FreeSpaceFusionResult;
    unsigned long long start_time_stamp;
    unsigned long long finish_time_stamp;
    long RollingCouter;
} ;

const short aroundview_od_result_msg_EAGLE_AV_MAX_OD_OBJECT = 400;

class aroundview_od_result_msg_Object_DetResult{

    long classid; //����
    float score;		// 0.0 ~ 1.0
    long camerid; //�ĸ���������
    /* object position in input image [px] */
    /* trace */
    long trackingId;
    long x;
    long y;
    long width;
    long height;
    /* object position in the real world */
    float groundX[3];    // [m] ���ױ��е㣬���㣬�յ�
    float groundY[3];    // [m]
    float distance;   // [m]
    float speed;      // [km/h]
    float speedX;
    float speedY;
    float obj_width;
    long    direction;  // -180 ~ 180 [deg]
} ; //A柱输出结果

class aroundview_od_result_msg_od_result_info {
    long OdMode;	//0 park  1 search
    long DetNums;
    aroundview_od_result_msg_Object_DetResult OdResult[aroundview_od_result_msg_EAGLE_AV_MAX_OD_OBJECT];
    unsigned long	  AbsoluteDeltaX;
    unsigned long    AbsoluteDeltaY;
    unsigned short    AbsoluteDeltaAngle;
    unsigned long long time_stamp;
    unsigned long long frame_id;
    unsigned long long start_time_stamp;
    unsigned long long finish_time_stamp;
    long RollingCouter;
} ;

/****************pd_result*********************/
const short aroundview_pd_result_msg_EAGLE_AV_MAX_PD_OBJECT = 10;
class aroundview_pd_result_msg_Pd_World_Position{
public:
    long groundX;
    long groundY;
    long distance;
} ;
class aroundview_pd_result_msg_Pd_Position{
public:
    long x;
    long y;
    long width;
    long height;
} ;
class aroundview_pd_result_msg_msg_Pd_Result_Object{
public:
    long		id;//type
    float	score;		// 0.0 ~ 1.0
    float	speed;
    long direction;
    float speedX;
    float speedY;
    long trackingId;
    aroundview_pd_result_msg_Pd_World_Position world_Position;
    aroundview_pd_result_msg_Pd_Position distrotion_Position;
    aroundview_pd_result_msg_Pd_Position undistrotion_Position;
} ;
class aroundview_pd_result_msg_msg_Pd_Result{
public:
    char channel;
    char result_num;
    aroundview_pd_result_msg_msg_Pd_Result_Object pd_result_object[aroundview_pd_result_msg_EAGLE_AV_MAX_PD_OBJECT];
} ;
class aroundview_pd_result_msg_pd_result_info {
public:
    aroundview_pd_result_msg_msg_Pd_Result PdResult;
    unsigned long long time_stamp;
    unsigned long frame_id;
    unsigned long long start_time_stamp;
    unsigned long long finish_time_stamp;
    long RollingCouter;
} ;

/****************multi_camera*********************/
/*
const short aroundview_capture_with_carinfo_EAGLE_AV_MAX_PLANES = 3;
const short aroundview_capture_with_carinfo_EAGLE_AV_MAX_CAM_BUF = 10;
const short aroundview_capture_with_carinfo_EAGLE_AV_MAX_CAM_CH = 4;
const short aroundview_capture_with_carinfo_EAGLE_AV_MAX_CAR_INFO_BUFFER_NUM = 256;
class aroundview_capture_with_carinfo_multi_cam_buf_desc{
public:
    unsigned long long phy_addr[aroundview_capture_with_carinfo_EAGLE_AV_MAX_CAM_CH][aroundview_capture_with_carinfo_EAGLE_AV_MAX_PLANES];
    unsigned long size[aroundview_capture_with_carinfo_EAGLE_AV_MAX_CAM_CH][aroundview_capture_with_carinfo_EAGLE_AV_MAX_PLANES];
} ;
class aroundview_capture_with_carinfo_multi_cam_info {
public:
    aroundview_capture_with_carinfo_multi_cam_buf_desc desc[aroundview_capture_with_carinfo_EAGLE_AV_MAX_CAM_BUF];
    unsigned long long time_stamp;
    unsigned long cur_desc_idx;
    unsigned long width;
    unsigned long height;
    unsigned long format;
    unsigned long counter;
    char car_info[aroundview_capture_with_carinfo_EAGLE_AV_MAX_CAR_INFO_BUFFER_NUM];
} ;
*/

/**
* @brief class of millimeter wave radar data input
*
**/

const unsigned short DesayInterface_pps_MAVP_RADAR_OBJECT_MAX_NUM = 30;   // Number of radar Object.
const unsigned short DesayInterface_pps_MAVP_RADAR_NUM = 5;                    // FLR, FSRSOD

class DesayInterface_pps_RadarDetections
{
public:
    float           RdrDetnAzi;     /*Azimuth Angle 方位角 range -90 ~ 90 Factor:0.1 */
    unsigned short  RdrDetnConf;    /*Quality range：0~100 */
    short           RdrDetnElevn;   /*Elevation Angle -15 ~15*/
    float           RdrDetnRng;     /*Range  range: -1~ 200  Factor:0.02*/
    float           RdrDetnRngV;    /*Range velocity range -128 ~ 128 Factor:0.02  */
    unsigned short  RdrDetnSts;     /*Detection type→请描述实际发出的内容 range: 0~3*/
};

class DesayInterface_pps_RadarDetectionObjs
{
public:
    float RdrObjAx;          /*Longitudinal acceleration  range: -12.8 ~12.7 Factor: 0.01 */
    float RdrObjAy;          /*Lateral acceleration  range: -12.8 ~12.7 Factor: 0.01 */
    unsigned short RdrObjConf;      /*Confidence  range: 0 ~ 105 */
    float RdrObjDx;          /*Longitudinal position range: -200 ~ 200 Factor: 0.05*/
    float RdrObjDxStdDe;     /*Standard deviation longitudinal position range: 0 ~ 12.7 Factor: 0.05*/
    float RdrObjDy;          /*Lateral position range: -200 ~ 200 Factor: 0.05*/
    float RdrObjDyStdDe;     /*Standard deviation Lateral position range: 0 ~ 12.7 Factor: 0.05*/
    unsigned short RdrObjElevnConf; /*Elevation confidence range:0 ~ 105*/
    unsigned short RdrObjElevnSts;  /*Elevation Status  0:ObjElevnSts_Ukwn 1:ObjElevnSts_Overridable 2:ObjElevnSts_Rlv 3:ObjElevnSts_Underridable*/
    float ObjBoxCenterLat;   /*Object extension (for moving objects) - lateral range:-25 ~ 25 Factor:0.1*/
    float RdrObjBoxWidth;    /*Object extension (for moving objects) - lateral range:0 ~ 51 Factor:0.1*/
    float ObjBoxCenterLgt;   /*Object extension (for moving objects) - longitudinal  range:-25 ~ 25 Factor:0.1*/
    float RdrObjBoxLength;   /*Object extension (for moving objects) - longitudinal range:0 ~ 51 Factor:0.1*/
    unsigned short RdrObjID;        /*Object ID   range:0 ~255*/
    unsigned short RdrObjMirrProblty;/*Probability of mirrored object Range: 0 ~ 105 */
    unsigned short RdrObjNotRealProblty;/*Probability of ghost track Range: 0 ~ 105*/
    unsigned short RdrObjStatyCnt;  /*Stationary Count  range:0 ~ 127*/
    unsigned short RdrObjTrackSts;  /*Track status   0:ObjTrackSts_Invld 1:ObjTrackSts_Updated 2:ObjTrackSts_New 3:ObjTrackSts_Coasted*/
    unsigned short RdrObjTyp;
    /* Classification object
            0:ObjTyp_Ukwn
            1:ObjTyp_Car
            2:ObjTyp_Motorcycle
            3:ObjTyp_Truck
            4:ObjTyp_Ped
            5:ObjTyp_ObstdVert1
            6:ObjTyp_ObstdVert2
            7:ObjTyp_Anim
            8:ObjTyp_ObjGen
            9:ObjTyp_Bicycle
            10:ObjTyp_VehofUkwnClass
            11:Reserved */
    unsigned short RdrObjTypConfBike; /*Confidence of tracked object type classification bike Range:0 ~ 105*/
    unsigned short RdrObjTypConfPed;  /*Confidence of tracked object type classification pedestrian range:0 ~ 105*/
    unsigned short RdrObjTypConfVeh;  /*Confidence of tracked object type classification  Range: 0 ~ 105*/
    unsigned short RdrObjTiAlv;       /*Lifetime Range: 0 ~ 127*/
    float RdrObjVx;            /*Longitudinal velocity  Range:-128 ~ 128 Factor:0.02*/
    float RdrObjVxStdDe;       /* Standard deviation longitudinal velocity Range:0 ~ 2 Factor:0.05*/
    float RdrObjVy;            /*Lateral velocity  Range:-128 ~ 128 Factor:0.02*/
    float RdrObjVyStdDe;       /* Standard deviation lateral velocity Range:0 ~ 2 Factor:0.05*/
    float Heading;             /*Heading angle Range:-180 ~ 180 Factor:0.1*/
    float Rel_Vx;              /*Relative velocity in X Range:-35.6~35.6 Factor:0.02*/
    float Rel_Vy;              /*Relative velocity in Y Range:-35.6~35.6 Factor:0.02*/
    unsigned long long observationHist;  /*The result of target association in each cycle,
                                        if target is associated,the bit value should be 1,
                                        if not,the bit value should be 0.there are 32 bits
                                        Range:0 ~ 0xffffffff*/
    unsigned short RdrObjUsedTracker;
    /*  the tracker model to which the targets belongs
            0:Stationary
            1:Moving CV model
            2:Moving CT model
            3:Undefined */
};

/**
 * @brief class of millimeter wave radar data
 *
**/
class DesayInterface_pps_RadarDetData
{
public:
    unsigned short RdrType;         /*radar type 0: FLR  1: FSRSOD FL 2: FSRSOD FR 3: FSRSOD RL 4: FSRSOD RR*/
    unsigned short RdrNrObj;        /*Number of objects  range:  for FLR:0~30, for FSRSOD: 0~15 */
    DesayInterface_pps_RadarDetectionObjs RdrDetectionObj[DesayInterface_pps_MAVP_RADAR_OBJECT_MAX_NUM]; /*list of Radar detection Object*/
};

// mcu --> bridge --> hpp_service
// topic: "mil_radar_data"
class DesayInterface_pps_MavpRadarData {
public:
    // TODO: add radar data here
    unsigned long long timestamp;
    DesayInterface_pps_RadarDetData  RadarDetData_Result[DesayInterface_pps_MAVP_RADAR_NUM];
};

/*
//hpp
typedef enum DesayInterface_pps_MavpCmdType
{
    _MAVP_CMD_UNKNOWN  = 0,
    _MAVP_CMD_ABORT_CREATE ,
    _MAVP_CMD_SELECT_PARKING_SLOT ,
    _MAVP_CMD_FINISH_MAPPING ,
    _MAVP_CMD_TYPE_NUM ,
    _MAVP_CMD_MAXSIZE  = -1
} DesayInterface_pps_MavpCmdType;

typedef enum DesayInterface_pps_MavpStatus
{
    _MAVP_OK  = 0,
    _MAVP_INVALID_ARGUMENT ,
    _MAVP_FAILURE
} DesayInterface_pps_MavpStatus;

class DesayInterface_pps_MavpCommand
{
  public:

    unsigned long long   timestamp ;
    unsigned long long   cmd_seq_id ;
    DesayInterface_pps_MavpCmdType   cmd_type ;
    DesayInterface_pps_MavpStatus   status ;
    DesayInterface_pps_MavpLocalizationPose   parking_slot_points [DesayInterface_pps_MAVP_VEHICLE_CORNER_NUM];
    unsigned long long   parking_lot_side ;
    unsigned long long   parking_lot_type ;
    DesayInterface_pps_MavpCommand()
    {
        timestamp=0 ;
        cmd_seq_id =0;
        cmd_type =_MAVP_CMD_UNKNOWN;
        status =_MAVP_OK;
        memset(parking_slot_points,0x0,sizeof(parking_slot_points));
        parking_lot_side=0;
        parking_lot_type=0;
    }
    const DesayInterface_pps_MavpCommand& operator =(const DesayInterface_pps_MavpCommand& data)
    {
        timestamp=data.timestamp ;
        cmd_seq_id =data.cmd_seq_id;
        cmd_type =data.cmd_type;
        status =data.status;
        memcpy(parking_slot_points,data.parking_slot_points,sizeof(parking_slot_points));
        parking_lot_side=data.parking_lot_side;
        parking_lot_type=data.parking_lot_type;
        return *this;
    }
};

class DesayInterface_pps_AppHppRequest {
public:
    // 0:no request, 1:Get map info request
    unsigned short              hppGetMapInfoReq;

    // 0:no request, 1:Start hpp, 2:End hpp
    unsigned short              hppCtrReq;

    // 0:no request, 1:Map building, 2:Park in, 3:Park out
    unsigned short              hppType;

    // if hppType = 1, hppMapFilePath means map save path and file name;
    // if hppType = 2/3 or hppGetMapInfoReq = 1, hppMapFilePath means map file path and name
    char                      hppMapFilePath[128];

    // The config file of Mavp sdk
    char                      hppConfigFilePath[128];

    // hpp cmd
    DesayInterface_pps_MavpCommand                 hppCmdReq;

    // 0:no request, 1:request ODD check
    unsigned short              hppODDCheckReq;
    DesayInterface_pps_AppHppRequest()
    {
        hppGetMapInfoReq=0;
        hppCtrReq=0;
        hppType=0;
        memset(hppMapFilePath,0x0,sizeof(hppMapFilePath));
        memset(hppConfigFilePath,0x0,sizeof(hppConfigFilePath));
        hppODDCheckReq=0;
    }
    const DesayInterface_pps_AppHppRequest& operator =(const DesayInterface_pps_AppHppRequest& data)
    {
        hppGetMapInfoReq=data.hppGetMapInfoReq;
        hppCtrReq=data.hppCtrReq;
        hppType=data.hppType;
        memcpy(hppMapFilePath,data.hppMapFilePath,sizeof(hppMapFilePath));
        memcpy(hppConfigFilePath,data.hppConfigFilePath,sizeof(hppConfigFilePath));
        hppODDCheckReq=data.hppODDCheckReq;
        return *this;
    }
};

class DesayInterface_pps_AppHppCalibReq {
public:
    // 0:no request, 1:Start calib, 2:Cancel calib, 3:Apply calib result, 4:Abandon calib result
    unsigned short              hppCalibCmdReq;
    DesayInterface_pps_AppHppCalibReq()
    {
        hppCalibCmdReq=0;
    }
};
*/

// app --> hpp_service
// topic: "app_hpp_req"

/**
 * @brief A58诊断需算法反馈的DTC&DID信息
 *
**/
class DesayInterface_pps_did_dtc_data
{
public:
    unsigned short sourceID;    // 代表发送方
    unsigned short targetID;    // 代表接收目标方
    unsigned short cmdType;     // 命令类型
    unsigned char sn;           // 序列号，接收方相应的序列号和发送方保持一致，每个CommandType的SN单独计数
    unsigned short dataLength;  // data的数据长度
    unsigned char data[1024];   // 数据
};


