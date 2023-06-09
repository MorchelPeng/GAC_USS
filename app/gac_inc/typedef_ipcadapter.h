#ifndef __TYPEDEF_IPCADAPTER_H__
#define __TYPEDEF_IPCADAPTER_H__

typedef signed char        int8;
typedef unsigned char      uint8;
typedef signed short       int16;
typedef unsigned short     uint16;
typedef signed int         int32;
typedef unsigned int       uint32;
typedef signed long long   int64;
typedef unsigned long long uint64;
typedef float              float32;
typedef double             float64;

#ifdef __cplusplus
extern "C"
{
#endif

    // Topic:1 CmdID:0
    struct AlgInterface_APASlotAttribute
    {
        float32 VehX;                           // 新坐标系下的x
        float32 VehY;                           // 新坐标系下的y
        float32 VehYaw;                         // 新坐标系下的yaw
        float32 SlotDepth;                      //
        float32 SlotWidth;                      //
        float32 SlotYaw;                        //
        float32 DeltaXFCorner;                  // 车位前角点的X坐标偏移量
        float32 DeltaYFCorner;                  // 车位前角点的Y坐标偏移量
        float32 DeltaXRCorner;                  // 车位后角点的X坐标偏移量
        float32 DeltaYRCorner;                  // 车位后角点的Y坐标偏移量
        float32 XSlotInMap;                     // 车位原点在栅格地图的偏移量x
        float32 YSlotInMap;                     // 车位原点在栅格地图的偏移量y
        float32 XUpdatedSlotRotateCoordinate;   // 更新的车位相对原始车位的相对偏移量x
        float32 YUpdatedSlotRotateCoordinate;   // 更新的车位相对原始车位的相对偏移量y
        float32 YawUpdatedSlotRotateCoordinate; // 更新的车位相对原始车位的相对偏移量yaw
        uint8   SlotDetectType;                 // 车位检测类型 svm还是uss还是自选车位
        uint8   SlotType;                       // 垂直/水平/斜列
        uint8   ParkType;                       // 泊入泊出
        uint8   ParkOutDir;                     // 泊出方向
        uint8   USSSideType;                    // 超声波检测单边类型
        uint8   SlotSide;                       // 左侧/右侧车位
        uint8   SlotID;                         // 目标车位编号
        uint8   UserChooseVD;                   // 车位自选框是否可用
    };

    // Topic:1 CmdID:1
    struct AlgInterface_APASlotInfo
    {
        uint8 SlotAvailNum; // 车位可用数量
    };

    // Topic:1 CmdID:2
    struct AlgInterface_APAFusionInfo
    {
        struct
        {
            float32 VehPosX;   // 车辆基于新坐标系x坐标
            float32 VehPosY;   // 车辆基于新坐标Y坐标
            float32 VehPosYaw; // 车辆基于新坐标航向角
        } PosValue;
        uint8 PosReset; // 0=noReset, 1=resetToZero, 2=resetToNew
    };

    // Topic:1 CmdID:3
    struct AlgInterface_APACollisionAvoidInfo
    {
        uint8 WarningType;
    };

    // Topic:1 CmdID:4
    struct AlgInterface_APADecisionInfo
    {
        uint8 SpaceSmall; // 车位空间
    };

    // Topic:1 CmdID:5
    struct AlgInterface_APAFusionWakeInfo
    {
        uint8 FusionWakeup; // 融合恢复使能
    };

    // Topic:1 CmdID:6
    struct AlgInterface_CameraCleanSt
    {
        uint8 FrontCameraSt; // 前视摄像头脏污状态
        uint8 RearCameraSt;  // 后视摄像头脏污状态
        uint8 LeftCameraSt;  // 左视摄像头脏污状态
        uint8 RightCameraSt; // 右视摄像头脏污状态
    };

    // Topic:2 CmdID:0
    struct AlgInterface_APAPathAttribute
    {
        uint8   TotalStep; // 总步数
        uint8   CurStep;   // 当前步数
        float32 CurStepFinalPointX;
        float32 CurStepFinalPointY;
        float32 CurStepFinalPointYaw;
    };

    // Topic:2 CmdID:1
    // Topic:7 CmdID:0
    struct AlgInterface_FuncPath
    {
        uint8 FuncIndex; // 1=RA,2=APA,3=HPA,4=Summon,5=AVP,6=RAEB,7=HPA->APA,8=RPA,9=AVP->APA,10=自选车位SPA
        struct
        {
            uint8   PathGear;     // 规划档位
            uint8   PathID;       // 规划轨迹ID
            uint8   PathType;     // 路径类型
            uint16  PathSize;     // 路径点有效个数
            uint8   PlanComplete; // 是否到达终点
            uint8   PlanError;    // 是否规划错误
            float32 PathLen;      // 总路径长
            float32 RmPathLen;    // 剩余路径长
        } PathAttribute;
        struct
        {
            float32 Vmax;        // 速度
            float32 Curv;        // 曲率
            float32 X;           // X坐标
            float32 Y;           // Y坐标
            float32 Yaw;         // 航向角
            uint8   Lamp;        // 转向灯请求
            uint8   RoadTurning; // 转弯信号
        } PathPoint[40];         // 路点结构体数组
    };

    // Topic:3 CmdID:0
    struct AlgInterface_APAUIInfo
    {
        uint8 APAUIButton; // UI界面所选泊车功能
    };

    // Topic:3 CmdID:1
    struct AlgInterface_RAUIInfo
    {
        uint8 RAUIButton;
    };

    // Topic:3 CmdID:2
    struct AlgInterface_RAEBUIInfo
    {
        uint8 RAEBUIButton;
    };

    // Topic:5 CmdID:0
    struct AlgInterface_FuncInfo
    {
        uint8 FuncIndex;
        uint8 FuncState;
        uint8 ActiveReq;
        uint8 ArbState;
    };

    // Topic:5 CmdID:1
    struct AlgInterface_FuncTipInfo
    {
        uint8 FuncIndex; // 1=RA,2=APA,3=HPA,4=Summon,5=AVP,6=RAEB,7=HPA->APA,8=RPA,9=AVP->APA,10=自选车位SPA
        struct
        {
            uint8 QuitInd; // 退出指示
            uint8 RecInd;  // 恢复指示
            uint8 DrvReq;  // 司机操作提醒
            uint8 ModeInd; // 模式指示
        } TipInfo;
    };

    // Topic:6 CmdID:0
    struct AlgInterface_FuncRemoteControl
    {
        uint8 FuncIndex; // 1=RA,2=APA,3=HPA,4=Summon,5=AVP,6=RAEB,7=HPA->APA,8=RPA,9=AVP->APA,10=自选车位SPA
        struct
        {
            uint8 RearMirrorFoldReq;   // 后视镜折叠请求 1=Request, 0=No request;
            uint8 RearMirrorUnFoldReq; // 后视镜展开请求 1=Request, 0=No request;
            uint8 IGOffReqEnable;      // 请求 IG 关闭 1=Enalbe 0=Disable;
            uint8 DoorsLockReq;        // 锁门请求 1=Request, 0=No request;
            uint8 DoorsUnlockReq;      // 开门请求 1=Command，0=No command;
            uint8 EngSSInhibitReq;     // 启停功能限制请求 1=Inhibit,0=Not Inhibit;
        } RemoteControl;
    };

    // Topic:6 CmdID:1
    struct AlgInterface_FuncBeamReqInfo
    {
        uint8 FuncIndex; // 1=RA,2=APA,3=HPA,4=Summon,5=AVP,6=RAEB,7=HPA->APA,8=RPA,9=AVP->APA,10=自选车位SPA
        struct
        {
            uint8 LowBeamReq;      // 近光灯请求 1=Request, 0=No request;
            uint8 HighBeamLampReq; // 远光灯请求 1=ON,0=OFF;
            uint8 TurnLampReq;     // 转向灯和危险灯请求 0=No request,1=Left TurnLamp Request,2=Right TurnLamp Request;
        } BeamReqInfo;
    };

    // Topic:6 CmdID:2
    struct AlgInterface_FuncSMCANOut
    {
        uint8 FuncIndex; // 1=RA,2=APA,3=HPA,4=Summon,5=AVP,6=RAEB,7=HPA->APA,8=RPA,9=AVP->APA,10=自选车位SPA
        struct
        {
            uint8  BTChallenge1;        // 蓝牙挑战码1 0
            uint8  BTChallenge2;        // 蓝牙挑战码2 0
            uint8  RemoteParkingMode;   // 远程泊车模式 0=Default,1=Remote parking,2=Automatic parking,3=Not used;
            uint8  RemoteParkingEnable; // 远程停车启用 0=Disable,1=Enable;
            uint8  APAActFuncInd;       // 泊车功能模式
            uint8  BTAuthSt;            // 蓝牙握手状态 3=Not used,2=Pass,1=Fail,0=Default;
            uint8  RPAReady;            // RPA 准备就绪 1=Ready,0=Not ready;
            uint8  PGearReq;            // P档请求 1=Request,0=No request;
            uint8  PGearReqEnable;      // P档请求可用性 1=Enable,0=Not enable;
            uint16 VoiceReminder;       // 语音提醒
            uint8  RPAShortPresSuppSt;  // RPA 短按支持状态 1=Support,0=Not support;
        } SMCANOut;
    };

    // Topic:6 CmdID:3
    struct AlgInterface_HPAInfo
    {
        uint8 RemoteParkingMode; //  0=DEFAULT, 1=REMOTE_PARKING(无人泊车),2=AUTOMATIC_PARKING(有人泊车);
    };

    // Topic:7 CmdID:0
    // see struct AlgInterface_FuncPath

    // Topic:7 CmdID:1
    struct AlgInterface_FuncDecisionAttribute
    {
        uint8 FuncIndex; // 1=RA,2=APA,3=HPA,4=Summon,5=AVP,6=RAEB,7=HPA->APA,8=RPA,9=AVP->APA,10=自选车位SPA
        struct
        {
            uint8   BrkFlag; // 刹车标志位
            float32 BrkDist; // 刹车距离,规划模块用
            float32 ExpSpd;  // 车速限值
        } DecisionAttribute;
    };

    // Topic:8 CmdID:0
    struct AlgInterface_FuncVehPos
    {
        uint8 FuncIndex; // 1=RA,2=APA,3=HPA,4=Summon,5=AVP,6=RAEB,7=HPA->APA,8=RPA,9=AVP->APA,10=自选车位SPA
        struct
        {
            float32 Curv;          // 车辆曲率
            float32 VehPosX;       // 车辆X坐标 X(m): 以车头方向为+x轴
            float32 VehPosY;       // 车辆Y坐标 Y(m): 右手坐标系，以车头方向的左边为+y轴
            float32 VehPosYaw;     // 车辆航向角 Yaw(rad): 航向角Yaw为与+x轴的夹角，左边为正（与车辆行驶方向无关）
            float32 VehPosPredX;   // 车辆预测X坐标
            float32 VehPosPredY;   // 车辆预测Y坐标
            float32 VehPosPredYaw; // 车辆预测航向角
        } VehPos;
    };

    // Topic:9 CmdID:0
    struct AlgInterface_ParkInfo
    {
        uint8 APAParkOutDirSel; // 泊出方向选择
    };

    // Topic:9 CmdID:1
    struct AlgInterface_SlotMatchInfo
    {
        uint8 SlotMatchSt; // 匹配车位状态
    };

    // Topic:10 CmdID:0
    // Topic:157 CmdID:0
    struct AlgInterface_RAPathState
    {
        uint8   PathState;   // 路径状态
        uint8   SpliceTimes; // 路径拼接次数
        uint16  PathSize;    // 路径点有效个数
        float32 PathCut;     // 剪裁路径长度
        float32 VehPosX;     // 车辆X坐标
        float32 VehPosY;     // 车辆Y坐标
        float32 VehPosYaw;   // 车辆航向角
        float32 YawRateOffset;
        uint32  CRC;
        uint8   RAPrePathReadOk;
        uint8   RAPathWriteOk;
    };

    // Topic:10 CmdID:1
    // Topic:157 CmdID:1
    struct AlgInterface_RAPathPoint
    {
        uint8 Index;
        struct
        {
            float32 Vmax;        // 速度
            float32 Curv;        // 曲率
            float32 X;           // X坐标
            float32 Y;           // Y坐标
            float32 Yaw;         // 航向角
            uint8   Lamp;        // 转向灯请求
            uint8   RoadTurning; // 转弯信号
        } PathPoint[40];         // 路点结构体数组
    };

    // Topic:11 CmdID:0
    struct AlgInterface_BrakeDecision
    {
        float32 TimeAboutToCollision; // 预计碰撞时间
        uint8   ObjExistFlag;         // 障碍物存在标志
        float32 ObjMinDistance;       // 障碍物最短距离
    };

    // Topic:12 CmdID:0
    struct AlgInterface_DiagDebugMode
    {
        uint64 DiagDisable; // 诊断输出失能,调试用于屏蔽故障,bit x = 0：正常输出,bit x = 1：index为x的输出接口失能，输出0
    };

    // Topic:16 CmdID:0
    struct AlgInterfaceVersionRequst
    {
        uint32 requst; // 保留，暂未使用
    };

    // Topic:16 CmdID:1
    struct AlgInterfaceVersionResponse
    {
        char VersionSource[32];   // 版本信息来源，应用开发方填写自己的名字：MCU3, HPA, APA, HMI
        char VersionSummary[128]; // 大版本信息字符串，显示到HMI工程模式中
        char VersionDetail[1736]; // 开发方内部模块详细信息字符串，应用开发者使用key:value\n形式填写自己各个模块详细信息

        /*
        版本请求响应流程：
        1.应用开发方在应用启动后的第1、4、8、20秒主动通过Topic:16 CmdID:1发送一次自己版本信息
        2.应用开发方方监测Topic:16 CmdID:0的请求，如果监测到请求，则通过Topic:16 CmdID:1发送一次自己的版本信息
        3.VersionSource，VersionSummary，VersionDetail三个字段的字符串必须使用‘\0’作为字符串结束标记
        4.VersionSource:存放开发方名称信息，MCU3表示MCU3上各个模块的版本信息
        5.VersionSummary:存放开发方版本的大版本信息，会在HMI工程模式中显示，如：A58_MCU3_220606_V1.XX
        6.VersionDetail:存放开发方内部模块具体版本信息，使用key:value形式存放，模块之间使用\n分割，如MCU3内部模块信息：
          "APAStateMachine:V1.01_220707\nTopStateMachine:V1.22_220607\n"
        */
    };

    // Topic:150 CmdID:0
    struct AlgInterface_EstVehState
    {
        float32 EstSpd;       // 估计车速
        uint8   EstDir;       // 估计方向
        float32 EstFLSpd;     // 估计前左轮速度
        float32 EstFRSpd;     // 估计前右轮速度
        float32 EstRLSpd;     // 估计后左轮速度
        float32 EstRRSpd;     // 估计后右轮速度
        float32 EstSlope;     // 估计坡度
        float32 EstLongAccel; // 估计纵向加速度
    };

    // Topic:151 CmdID:0
    struct AlgInterface_VehPos
    {
        uint64 MCU1RTimeus;   // MCU1接收轮速传感器脉冲累计总和时间戳
        uint64 MCUSocTimeus;  // SOC侧收到DR数据的时间戳
        float  Curv;          // 车辆曲率
        float  VehPosX;       // 车辆X坐标
        float  VehPosY;       // 车辆Y坐标
        float  VehPosYaw;     // 车辆航向角
        float  VehPosPredX;   // 车辆预测X坐标
        float  VehPosPredY;   // 车辆预测Y坐标
        float  VehPosPredYaw; // 车辆预测航向角
    };

    // Topic:152 CmdID:0
    struct AlgInterface_CtrlState
    {
        uint8 CtrlEndOK;  //发给规划，代表控制走完路径
        uint8 CtrlPathID; //发给规划，代表控制跟踪的路径ID
    };

    // Topic:153 CmdID:0
    struct AlgInterface_HandShakeInfo
    {
        uint8 HandshakeOK; // 握手是否成功 0=默认；1= 握手成功 ；2= 握手失败
        uint8 ArbFault;    // 关联件错误信息 0=normal,1=external ecu fail,
                           // 8=gear intv,17=epb intv,18=veh block,19=unexpected gear pos,21=steer intv
    };

    // Topic:154 CmdID:0
    struct AlgInterface_APASMAPAAlgEnable
    {
        uint8 SVODFDNetEnable;
        uint8 SVODFDEnable;
        uint8 PSDNetEnable;
        uint8 PSDEnable;
        uint8 FusionEnable;
        uint8 PlanEnable;
    };

    // Topic:154 CmdID:1
    struct AlgInterface_APASMAPASt
    {
        uint8 APAState; // 0=Off,1=Standby,2=Searching,3=Guidance active,
                        // 4=Completed,5=Failure,6=Terminated,7=Suspend;
    };

    // Topic:154 CmdID:2
    struct AlgInterface_APASMAPAInvokeResp
    {
        uint8 APAEnableSt;
        uint8 APAFeedBack;
        uint8 SlotReceived;
    };

    // Topic:154 CmdID:3
    struct AlgInterface_APASMPSDInfo
    {
        uint8 PSDOutType; // 1=for HPA, 2=for APA 寻库, 3=for APA 泊入, 4=for APA 泊出
    };

    // Topic:154 CmdID:4
    struct AlgInterface_APASMParkOutDir
    {
        uint8 ParkOutDir; // 0=Default, 1=left, 2=right
    };

    // Topic:154 CmdID:5
    struct AlgInterface_APASMTipInfo
    {
        uint8 QuitInd; // 退出指示
        uint8 RecInd;  // 恢复指示
        uint8 DrvReq;  // 司机操作提醒
        uint8 ModeInd; // 模式指示
    };

    // Topic:154 CmdID:6
    struct AlgInterface_APASMAPAMode
    {
        uint8 RemoteParkingMode;   // 远程泊车模式
        uint8 RemoteParkingEnable; // 远程停车启用
        uint8 APAActFuncInd;       // 泊车功能模式
    };

    // Topic:154 CmdID:7
    // 20230501: 为减少PPS通信频率，新增CmdID:7，结构体包含CmdID:0-6的所有数据，CmdID:0-6不再发送
    struct AlgInterface_APASMAllData
    {
        AlgInterface_APASMAPAAlgEnable  stAlgEnable;  // 原 Topic:154 CmdID:0
        AlgInterface_APASMAPASt         stAPASt;      // 原 Topic:154 CmdID:1
        AlgInterface_APASMAPAInvokeResp stInvokeResp; // 原 Topic:154 CmdID:2
        AlgInterface_APASMPSDInfo       stPSDInfo;    // 原 Topic:154 CmdID:3
        AlgInterface_APASMParkOutDir    stParkOutDir; // 原 Topic:154 CmdID:4
        AlgInterface_APASMTipInfo       stTipInfo;    // 原 Topic:154 CmdID:5
        AlgInterface_APASMAPAMode       stAPAMode;    // 原 Topic:154 CmdID:6
    };

    // Topic:155 CmdID:0
    struct AlgInterface_TOPSMInvokeInfo
    {
        uint8 InvokeResult; // APA调用结果
        uint8 InvokeState;  // APA调用状态
    };

    // Topic:155 CmdID:1
    struct AlgInterface_TOPSMFuncRespSt
    {
        uint8 FuncSelect;            // 当前选择功能
        uint8 FuncActiveSt;          // 功能激活状态
        uint8 VoiceReminderSwitchSt; //语音开关状态
    };

    // Topic:155 CmdID:2
    struct AlgInterface_TOPSMDecisionAttribute
    {
        uint8   BrkFlag; // 刹车标志位
        float32 BrkDist; // 刹车距离，规划模块用
        float32 ExpSpd;  // 车速限值
    };

    // Topic:155 CmdID:3
    // 20230501: 为减少PPS通信频率，新增CmdID:3，结构体包含CmdID:0-2的所有数据，CmdID:0-2不再发送
    struct AlgInterface_TOPSMAllData
    {
        AlgInterface_TOPSMInvokeInfo        stInvokeInfo;        // 原 Topic:155 CmdID:0
        AlgInterface_TOPSMFuncRespSt        stFuncRespSt;        // 原 Topic:155 CmdID:1
        AlgInterface_TOPSMDecisionAttribute stDecisionAttribute; // 原 Topic:155 CmdID:2
    };

    // Topic:156 CmdID:0
    struct AlgInterface_RAHMIReq
    {
        uint8   RAState;
        uint8   RADrvReq;
        uint8   RARecInd;
        uint8   RAQuitInd;
        float32 RARmPathLen;
    };

    // Topic:157 CmdID:0, Same as Topic:10 CmdID:0 struct AlgInterface_RAPathState
    // Topic:157 CmdID:1, Same as Topic:10 CmdID:1 struct AlgInterface_RAPathPoint

    // Topic:158 CmdID:0
    struct AlgInterface_RAEBHMIFuncSt
    {
        uint8 FuncSt;    // RAEB功能父状态
        uint8 DegradeSt; // RAEB功能降级状态
        uint8 SubFuncSt; // RAEB功能子状态
    };

    // Topic:158 CmdID:1
    struct AlgInterface_RAEBSMSaveOut
    {
        uint8 RAEBCfgMemory;
    };

    // Topic:159 CmdID:0
    struct AlgInterface_HPADiagInfo
    {
        uint32 HpaDiagFault; // HPA故障信息
    };

    // Topic:159 CmdID:1
    struct AlgInterface_HMIDiagInfo
    {
        uint8 FrontCamError;
        uint8 FrontFisheyeCamError;
        uint8 RearFisheyeCamError;
        uint8 LeftFisheyeCamError;
        uint8 RightFisheyeCamError;
        uint8 LVDSError;
        uint8 FrontSensorsError;
        uint8 RearSensorsError;
        uint8 LeftFrontSideSensorsError;
        uint8 RightFrontSideSensorsError;
        uint8 LeftFrontCornerSensorsError;
        uint8 RightFrontCornerSensorsError;
        uint8 LeftFrontMiddleSensorsError;
        uint8 RightFrontMiddleSensorsError;
        uint8 LeftRearMiddleSensorsError;
        uint8 RightRearMiddleSensorsError;
        uint8 LeftRearSideSensorsError;
        uint8 RightRearSideSensorsError;
        uint8 LeftRearCornerSensorsError;
        uint8 RightRearCornerSensorsError;
        uint8 CANBusError;
        uint8 ACUError;
        uint8 GWMError;
        uint8 EPSError;
        uint8 BCSError;
        uint8 EPBError;
        uint8 EMSError;
        uint8 GSMError;
        uint8 ICMError;
        uint8 PEPSError;
        uint8 FLDCMError;
        uint8 SBMError;
        uint8 HVACFError;
        uint8 BCMError;
        uint8 TELError;
        uint8 VCUError;
        uint8 SRSError;
        uint8 IMUError;
        uint8 EthernetError;
        uint8 ECUError;
    };

    // Topic:160 CmdID:0, same as Topic:155 CmdID:2
    using AlgInterface_ColliAvoidDecisionAttribute = AlgInterface_TOPSMDecisionAttribute;

    // Topic:160 CmdID:1
    struct AlgInterface_ColliAvoidObsInfo
    {
        uint8 ObsStopWait; //代表障碍物逼停后等待/重规划
        uint8 ObsStopQuit; // 0，default；1，库内，2，库外；
    };

    // Topic:160 CmdID:2
    struct AlgInterface_ColliAvoid2IPC
    {
        uint8 Avoid1signal;       // Avoid_Stop_Wait_Final： 避障方位   Avoid_WarningType_UpperHalf：泊车方位
        uint8 Avoid2signal;       // Avoid_WarningType_LowerHalf：栅格地图障碍物原始信号  isMapWarning：栅格地图障碍物处理后的值
        uint8 Avoid3signal;       // Avoid_CollAvoidEnable：泊车使能  isVehStartUp：是否起步阶段   ParallelKneading：是否水平揉库
                                  // Avoid_EnableOffTrap：是否脱困 Avoid_uDistStatus_noside：前后方距离状态 Avoid_uDistStatus_side：侧边距离状态
        float32 AvoidMapLimSpeed; // 栅格地图障碍物限速
        float32 AvoidVmaxRaw;     // 超声距离限速
        float32 AvoidRunDist;     // 每一步的行驶距离
    };

    // Topic:160 CmdID:3
    // 20230501: 为减少PPS通信频率，新增CmdID:3，结构体包含CmdID:0-2的所有数据，CmdID:0-2不再发送
    struct AlgInterface_ColliAvoidAllData
    {
        AlgInterface_ColliAvoidDecisionAttribute stDecisionAttribute; // 原 Topic:160 CmdID:0
        AlgInterface_ColliAvoidObsInfo           stObsInfo;           // 原 Topic:160 CmdID:1
        AlgInterface_ColliAvoid2IPC              stAvoid2IPC;         // 原 Topic:160 CmdID:2
    };

    // Topic:170 CmdID:0
    // MCU3_0发送到A72的CAN信号,事件型
    struct AlgInterface_IdtCanSignalRxEvent
    {
        uint64 MCU1RTimeus;
        uint64 MCU1STimeus;
        uint64 MCU3RTimeus;
        uint64 MCU3STimeus;
        uint64 MCUSocTimeus;
        uint8  WarnTone_ButtonPress; // 雷达告警音按钮状态
        uint8  ScreenTouchSt;        // 车机屏幕触摸状态
        uint8  CurrentSceenSt;       // 车机当前屏显状态
        uint16 ScreenCoordY;         // 车机屏幕触摸点Y坐标
        uint16 ScreenCoordX;         // 车机屏幕触摸点X坐标
        uint8  SVM_VRSwitch;         // SVM语音控制开关
        uint8  SVM_ButtonPress;      // SVM按钮状态
        uint8  NetHPABtnSt;          // 网络端HPA按钮状态
        uint8  NetHPABtnStVD;        // 网络端HPA按钮状态有效性
        uint8  NetCancelParking;     // 用户通过网络端取消泊车
        uint8  NetHPAPathSelect;     // 用户通过网络端选择的路径编号
        uint8  RPAResponse;          // 蓝牙响应RPA挑战信号
        uint8  BTHPAPathSelect;      // 用户通过蓝牙端选择的路径编号
        uint8  BTComSDKSt;           // 蓝牙和SDK之间的通信状态
        uint8  InitGestureSt;        // 初始化手势的状态
        uint8  RPACancelBtnSt;       // RPA取消按钮状态
        uint8  RPACancelBtnStVD;     // RPA取消按钮状态有效性
        uint8  RPABtnSt;             // RPA按钮状态
        uint8  RPABtnStVD;           // RPA按钮状态有效性
        uint8  FingerPositionX;      // 蓝牙APP手指位置X值
        uint8  FingerPositionY;      // 蓝牙APP手指位置Y值
        uint8  RemoteVideoReqSt;     // TBOX视频推流请求
        uint8  SVMButtonPressHW;     // SVM功能按下状态--硬线信号 1 "Press" 0 "No Press"
        uint8  PCSSVMFunctionCmd;    // PCS停车摄像系统--人机界面指令
    };

    // Topic:170 CmdID:1
    // MCU3_0发送到A72的CAN信号,20ms周期型
    struct AlgInterface_IdtCanSignalRx20ms
    {
        uint64  MCU1RTimeus;
        uint64  MCU1STimeus;
        uint64  MCU3RTimeus;
        uint64  MCU3STimeus;
        uint64  MCUSocTimeus;
        uint8   VehSpdVD;                   // 车速有效性
        float32 VehSpd;                     // 车速
        uint8   SteeringAngleVD;            // 方向盘角度有效性
        uint8   SteAngSen_CalibratedSt;     // 转向角传感器的标定状态
        float32 SteeringAngle;              // 方向盘角度
        uint8   CurrentGearSt;              // 当前档位信息
        uint8   CurrentGearStVD;            // 当前档位信息有效性
        uint8   FLWheelSpdVD;               // 左前轮当前轮速有效性
        uint8   FLWheelRotatedDirection;    // 左前轮旋转方向
        uint8   FLWheelRotatedDirectionVD;  // 左前轮旋转方向有效性
        float32 FLWheelSpd;                 // 左前轮当前轮速
        uint8   FRWheelRotatedDirectionVD;  // 右前轮旋转方向有效性
        uint8   FRWheelRotatedDirection;    // 右前轮旋转方向
        uint8   FRWheelSpdVD;               // 左前轮当前轮速有效性
        float32 FRWheelSpd;                 // 左前轮当前轮速
        uint8   FLWheelRotatedDirectionAPA; // 左前轮旋转方向（APA用）
        uint8   FRWheelRotatedDirectionAPA; // 右前轮旋转方向（APA用）
        uint8   PreVDCActiveSt;             // 在ESP加压时,VDC系统是否干预制动/发动机
        uint8   RLWheelSpdVD;               // 左后轮当前轮速有效性
        uint8   RLWheelRotatedDirection;    // 左后轮旋转方向
        uint8   RLWheelRotatedDirectionVD;  // 左后轮旋转方向有效性
        float32 RLWheelSpd;                 // 左后轮当前轮速
        uint8   RRWheelRotatedDirectionVD;  // 右后轮旋转方向有效性
        uint8   RRWheelRotatedDirection;    // 右后轮旋转方向
        uint8   RRWheelSpdVD;               // 右后轮当前轮速有效性
        float32 RRWheelSpd;                 // 右后轮当前轮速
        uint8   RLWheelRotatedDirectionAPA; // 左后轮旋转方向（APA用）
        uint8   RRWheelRotatedDirectionAPA; // 右后轮旋转方向（APA用）
        uint8   LongContrFailSt;            // 纵向控制器故障
        uint16  FLWheelSpdEdgesSum;         // IGN ON后,左前轮速传感器脉冲累计总和
        uint16  FRWheelSpdEdgesSum;         // IGN ON后,右前轮速传感器脉冲累计总和
        uint16  RLWheelSpdEdgesSum;         // IGN ON后,左后轮速传感器脉冲累计总和
        uint16  RRWheelSpdEdgesSum;         // IGN ON后,右后轮速传感器脉冲累计总和
        uint8   ElePowSte_ReqFeedback;      // 转向器对泊车控制请求的反馈
        uint8   ElePowSte_AbortFeedback;    // 转向器中止泊车的原因
        float32 VehLatrlAccel;              // 车辆横向加速度
        float32 VehLongAccel;               // 车辆纵向加速度
        float32 YawRate;                    // 车辆横摆率
        uint8   BrkPedalSt;                 // 制动踏板状态
        float32 AccelPedalActPstforMRR;     // 当前加速踏板实际位置（MRR用）
        uint8   FLWheelSpdEdgesSumVD;       // 左前轮脉冲总和有效性
        uint8   FRWheelSpdEdgesSumVD;       // 右前轮脉冲总和有效性
        uint8   RLWheelSpdEdgesSumVD;       // 左后轮脉冲总和有效性
        uint8   RRWheelSpdEdgesSumVD;       // 右后轮脉冲总和有效性
        uint8   ParkingLampSt;              // 驻车灯状态
    };

    // Topic:170 CmdID:2
    // MCU3_0发送到A72的CAN信号,100ms周期型
    struct AlgInterface_IdtCanSignalRx100ms
    {
        uint64 MCU1RTimeus;
        uint64 MCU1STimeus;
        uint64 MCU3RTimeus;
        uint64 MCU3STimeus;
        uint64 MCUSocTimeus;
        uint8  LowBeamSt;            // 近光灯状态
        uint8  HighBeamSt;           // 远光灯状态
        uint8  VehKeySt;             // 车钥匙位置状态
        uint8  BonnetAjarSt;         // 发动机罩状态
        uint8  ReverseSwitchSt;      // 倒车开关状态
        uint8  DriverDoorAjarSt;     // 驾驶员车门状态
        uint8  BrakeLightSwitchSt;   // 刹车灯开关状态
        uint8  TrunkAjarSt;          // 后备箱状态
        uint8  PsngrDoorAjarSt;      // 副驾车门状态
        uint8  RLDoorAjarSt;         // 左后门状态
        uint8  RRDoorAjarSt;         // 右后门状态
        uint8  LeftTurnLampSt;       // 左转灯状态
        uint8  LeftTurnLampFaultSt;  // 左转向灯故障状态
        uint8  RightTurnLampSt;      // 右转灯状态
        uint8  RightTurnLampFaultSt; // 右转灯故障状态
        uint8  TurnLightSwitchSt;    // 转向灯开关状态
        uint8  HazardLampSt;         // 危险灯状态
        uint8  ReverseLightSt;       // 倒车灯状态
        uint8  BrakeLightSt;         // 刹车灯状态
        uint8  BrakeLightFaultSt;    // 刹车灯故障状态
        uint8  DriverDoorLockSt;     // 驾驶员车门锁状态
        uint8  PsngrDoorLockSt;      // 乘客门锁状态
        uint8  EngSt;                // 发动机运行状态
        uint8  ElePrkBrk_SysSt;      // EPB系统状态
        uint8  RRMirrorFoldSt;       // 右后视镜折叠状态
        uint8  RLMirrorFoldSt;       // 左后视镜折叠状态
        uint8  DriverSeatBeltSt;     // 驾驶员安全带状态
        uint8  PsngrSeatBeltSt;      // 乘客安全带状态
        uint8  NetErrSt;             // 网络错误状态
        uint8  NetHPADeviceSt;       // 网络端HPA设备状态
        uint8  BTPhoneConnectingSt;  // 手机蓝牙连接状态
        uint8  RPADeviceSt;          // RPA设备状态
        uint8  RPACheckReq;          // RPA检查请求
        uint8  RPADeviceFailReason;  // RPA设备故障原因
        uint8  BTRPAFailReason;      // 蓝牙RPA故障原因
        uint8  VMMWarningType;       // VMM系统的警告类型（哨兵模式状态）
        uint8  RCTAWarnRight;        // RCTA 功能中的车辆右侧警告
        uint8  RCTAWarnLeft;         // RCTA 功能中的车辆左侧警告
        uint8  FCTAWarnL;            // FCTA 警告左
        uint8  FCTAWarnR;            // FCTA 警告右
        uint8  CurrentGearStDisp;    // 当前档位--仪表显示
        uint8  PlgConnSt;            // 枪连接状态
    };

    // Topic:170 CmdID:3
    // MCU3_0发送到A72的CAN信号,500ms周期型
    struct AlgInterface_IdtCanSignalRx500ms
    {
        uint64  MCU1RTimeus;
        uint64  MCU1STimeus;
        uint64  MCU3RTimeus;
        uint64  MCU3STimeus;
        uint64  MCUSocTimeus;
        uint8   ThemeType;     // ACU 主题类型（白天黑夜模式）
        float32 Latitude;      // 纬度
        float32 Longitude;     // 经度
        uint8   TimeDay;       // 天数
        uint8   TimeHour;      // 小时数
        uint8   TimeMin;       // 分钟数
        uint8   TimeMonth;     // 月数
        uint8   TimeSec;       // 秒数
        uint16  TimeYear;      // 年数
        uint8   RainfallLevel; // 降雨量
        uint8   NaviPstVD;     // 导航位置有效性
    };

    // A72发送到MCU3_0的CAN信号,周期20ms,此结构体用户不能直接使用
    // 应用发送CAN信号应使用 DesayInterface_pps_universalCanSignal_txFast结构体
    // 使用对应的信号名字,通过TOPICID:TOPICID_UNIVERSALCANSIG_TX_FAST_APP(405)发送
    struct AlgInterface_IdtCanSignalTx20ms
    {
        uint64 MCU1RTimeus;
        uint64 MCU1STimeus;
        uint64 MCU3RTimeus;
        uint64 MCU3STimeus;
        uint64 MCUSocTimeus;
        uint8  USSWorkMode; // 超声波传感器工作模式
        uint8  PwrOnReq;    // APA上电请求
    };

    // A72发送到MCU3_0的CAN信号,周期100ms,此结构体用户不能直接使用
    // 应用发送CAN信号应使用 DesayInterface_pps_universalCanSignal_txFast结构体
    // 使用对应的信号名字,通过TOPICID:TOPICID_UNIVERSALCANSIG_TX_FAST_APP(405)发送
    struct AlgInterface_IdtCanSignalTx100ms
    {
        uint64  MCU1RTimeus;
        uint64  MCU1STimeus;
        uint64  MCU3RTimeus;
        uint64  MCU3STimeus;
        uint64  MCUSocTimeus;
        uint8   DisplayReq; // 霸屏显示请求
        uint8   WarnTone;   // 雷达告警音
        uint8   HPACtrlSigSrc;
        uint8   HPAResRouteLeg;
        uint8   HPAPath1MatGpsSucces;
        uint8   HPAPath2MatGpsSucces;
        uint8   HPAPath3MatGpsSucces;
        uint8   HPAPath4MatGpsSucces;
        uint8   HPAPath5MatGpsSucces;
        uint8   HPAPath6MatGpsSucces;
        uint8   HPAPath7MatGpsSucces;
        uint8   HPAPath8MatGpsSucces;
        uint8   HPAPath9MatGpsSucces;
        uint8   HPAPath10MatGpsSucces;
        uint8   HPAPath1Src;
        uint8   HPAPath2Src;
        uint8   HPAPath3Src;
        uint8   HPAPath4Src;
        uint8   HPAPath5Src;
        uint8   HPAPath6Src;
        uint8   HPAPath7Src;
        uint8   HPAPath8Src;
        uint8   HPAPath9Src;
        uint8   HPAPath10Src;
        uint8   HPAPathDst1;
        uint8   HPAPathDst2;
        uint8   HPAPathDst3;
        uint8   HPAPathDst4;
        uint8   HPAPathDst5;
        uint8   HPAPathDst6;
        uint8   HPAPathDst7;
        uint8   HPAPathDst8;
        uint8   HPAPathDst9;
        uint8   HPAPathDst10;
        float32 HPAPathLearnRate1;
        float32 HPAPathLearnRate2;
        float32 HPAPathLearnRate3;
        float32 HPAPathLearnRate4;
        float32 HPAPathLearnRate5;
        float32 HPAPathLearnRate6;
        float32 HPAPathLearnRate7;
        float32 HPAPathLearnRate8;
        float32 HPAPathLearnRate9;
        float32 HPAPathLearnRate10;
        uint8   HPAPathSt1;
        uint8   HPAPathSt2;
        uint8   HPAPathSt3;
        uint8   HPAPathSt4;
        uint8   HPAPathSt5;
        uint8   HPAPathSt6;
        uint8   HPAPathSt7;
        uint8   HPAPathSt8;
        uint8   HPAPathSt9;
        uint8   HPAPathSt10;
        uint8   LearningLotType1;
        uint8   LearningLotType2;
        uint8   LearningLotType3;
        uint8   LearningLotType4;
        uint8   LearningLotType5;
        uint8   LearningLotType6;
        uint8   LearningLotType7;
        uint8   LearningLotType8;
        uint8   LearningLotType9;
        uint8   LearningLotType10;
        uint8   LearningPathNum1;
        uint8   LearningPathNum2;
        uint8   LearningPathNum3;
        uint8   LearningPathNum4;
        uint8   LearningPathNum5;
        uint8   LearningPathNum6;
        uint8   LearningPathNum7;
        uint8   LearningPathNum8;
        uint8   LearningPathNum9;
        uint8   LearningPathNum10;
        uint8   LearningPathType1;
        uint8   LearningPathType2;
        uint8   LearningPathType3;
        uint8   LearningPathType4;
        uint8   LearningPathType5;
        uint8   LearningPathType6;
        uint8   LearningPathType7;
        uint8   LearningPathType8;
        uint8   LearningPathType9;
        uint8   LearningPathType10;
        uint8   PASSystemType;       // PAS(停车辅助系统)系统类型
        uint8   WarnToneButtonPress; // 报警开关的开启和关闭情况
        uint8   RRMidDistance;
        uint8   RLMidDistance;
        uint8   RRDistance;
        uint8   RLDistance;
        uint8   RSLSideDistance;
        uint8   RSRSideDistance;
        uint8   FRDistance;
        uint8   FLDistance;
        uint8   FRMidDistance;
        uint8   FLMidDistance;
        uint8   FSRSideDistance;
        uint8   FSLSideDistance;
    };

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

namespace AlgInterface
{
    using APASlotAttribute            = AlgInterface_APASlotAttribute;            // Topic:1 CmdID:0
    using APASlotInfo                 = AlgInterface_APASlotInfo;                 // Topic:1 CmdID:1
    using APAFusionInfo               = AlgInterface_APAFusionInfo;               // Topic:1 CmdID:2
    using APACollisionAvoidInfo       = AlgInterface_APACollisionAvoidInfo;       // Topic:1 CmdID:3
    using APADecisionInfo             = AlgInterface_APADecisionInfo;             // Topic:1 CmdID:4
    using APAFusionWakeInfo           = AlgInterface_APAFusionWakeInfo;           // Topic:1 CmdID:5
    using CameraCleanSt               = AlgInterface_CameraCleanSt;               // Topic:1 CmdID:6
    using APAPathAttribute            = AlgInterface_APAPathAttribute;            // Topic:2 CmdID:0
    using APAPath                     = AlgInterface_FuncPath;                    // Topic:2 CmdID:1
    using APAUIInfo                   = AlgInterface_APAUIInfo;                   // Topic:3 CmdID:0
    using RAUIInfo                    = AlgInterface_RAUIInfo;                    // Topic:3 CmdID:1
    using RAEBUIInfo                  = AlgInterface_RAEBUIInfo;                  // Topic:3 CmdID:2
    using FuncInfo                    = AlgInterface_FuncInfo;                    // Topic:5 CmdID:0
    using FuncTipInfo                 = AlgInterface_FuncTipInfo;                 // Topic:5 CmdID:1
    using FuncRemoteControl           = AlgInterface_FuncRemoteControl;           // Topic:6 CmdID:0
    using FuncBeamReqInfo             = AlgInterface_FuncBeamReqInfo;             // Topic:6 CmdID:1
    using FuncSMCANOut                = AlgInterface_FuncSMCANOut;                // Topic:6 CmdID:2
    using HPAInfo                     = AlgInterface_HPAInfo;                     // Topic:6 CmdID:3
    using HPAPath                     = AlgInterface_FuncPath;                    // Topic:7 CmdID:0
    using HPADecisionAttribute        = AlgInterface_FuncDecisionAttribute;       // Topic:7 CmdID:1
    using FuncVehPos                  = AlgInterface_FuncVehPos;                  // Topic:8 CmdID:0
    using ParkInfo                    = AlgInterface_ParkInfo;                    // Topic:9 CmdID:0
    using SlotMatchInfo               = AlgInterface_SlotMatchInfo;               // Topic:9 CmdID:1
    using RAPathState                 = AlgInterface_RAPathState;                 // Topic:10 CmdID:0, Topic:157 CmdID:0
    using RAPathPoint                 = AlgInterface_RAPathPoint;                 // Topic:10 CmdID:1, Topic:157 CmdID:1
    using BrakeDecision               = AlgInterface_BrakeDecision;               // Topic:11 CmdID:0
    using DiagDebugMode               = AlgInterface_DiagDebugMode;               // Topic:12 CmdID:0
    using VersionRequest              = AlgInterfaceVersionRequst;                // Topic:16 CmdID:0
    using VersionResponse             = AlgInterfaceVersionResponse;              // Topic:16 CmdID:1
    using EstVehState                 = AlgInterface_EstVehState;                 // Topic:150 CmdID:0
    using APAVehPos                   = AlgInterface_VehPos;                      // Topic:151 CmdID:0
    using CtrlState                   = AlgInterface_CtrlState;                   // Topic:152 CmdID:0
    using HandShakeInfo               = AlgInterface_HandShakeInfo;               // Topic:153 CmdID:0
    using APASMAPAAlgEnable           = AlgInterface_APASMAPAAlgEnable;           // Topic:154 CmdID:0
    using APASMAPASt                  = AlgInterface_APASMAPASt;                  // Topic:154 CmdID:1
    using APASMAPAInvokeResp          = AlgInterface_APASMAPAInvokeResp;          // Topic:154 CmdID:2
    using APASMPSDInfo                = AlgInterface_APASMPSDInfo;                // Topic:154 CmdID:3
    using APASMParkOutDir             = AlgInterface_APASMParkOutDir;             // Topic:154 CmdID:4
    using APASMTipInfo                = AlgInterface_APASMTipInfo;                // Topic:154 CmdID:5
    using APASMAPAMode                = AlgInterface_APASMAPAMode;                // Topic:154 CmdID:6
    using APASMAllData                = AlgInterface_APASMAllData;                // Topic:154 CmdID:7
    using TOPSMInvokeInfo             = AlgInterface_TOPSMInvokeInfo;             // Topic:155 CmdID:0
    using TOPSMFuncRespSt             = AlgInterface_TOPSMFuncRespSt;             // Topic:155 CmdID:1
    using TOPSMDecisionAttribute      = AlgInterface_TOPSMDecisionAttribute;      // Topic:155 CmdID:2
    using TOPSMAllData                = AlgInterface_TOPSMAllData;                // Topic:155 CmdID:3
    using RAHMIReq                    = AlgInterface_RAHMIReq;                    // Topic:156 CmdID:0
    using RAEBHMIFuncSt               = AlgInterface_RAEBHMIFuncSt;               // Topic:158 CmdID:0
    using RAEBSMSaveOut               = AlgInterface_RAEBSMSaveOut;               // Topic:158 CmdID:1
    using HPADiagInfo                 = AlgInterface_HPADiagInfo;                 // Topic:159 CmdID:0
    using HMIDiagInfo                 = AlgInterface_HMIDiagInfo;                 // Topic:159 CmdID:1
    using ColliAvoidDecisionAttribute = AlgInterface_ColliAvoidDecisionAttribute; // Topic:160 CmdID:0
    using ColliAvoidObsInfo           = AlgInterface_ColliAvoidObsInfo;           // Topic:160 CmdID:1
    using ColliAvoid2IPC              = AlgInterface_ColliAvoid2IPC;              // Topic:160 CmdID:2
    using ColliAvoidAllData           = AlgInterface_ColliAvoidAllData;           // Topic:160 CmdID:3
    using CANRxEvent                  = AlgInterface_IdtCanSignalRxEvent;         // Topic:170 CmdID:0
    using CANRx20ms                   = AlgInterface_IdtCanSignalRx20ms;          // Topic:170 CmdID:1
    using CANRx100ms                  = AlgInterface_IdtCanSignalRx100ms;         // Topic:170 CmdID:2
    using CANRx500ms                  = AlgInterface_IdtCanSignalRx500ms;         // Topic:170 CmdID:3
}

#endif

#endif // __TYPEDEF_IPCADAPTER_H__
