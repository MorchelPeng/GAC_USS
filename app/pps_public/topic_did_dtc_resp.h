#pragma once
#include "ppscontrol.h"
#include "app_pps_protocal.h"

class Topic_Did_Dtc_Resp_class {
public:
    static DESY::PPS_CFG_STRU cfg(int issub, int ispub)
    {
        DESY::PPS_CFG_STRU cfg={TOPICID_DID_DTC_RESP_APP,"DID_DTC_Resp_Data",16,issub,ispub,15,300};
        return cfg;
    }
};


typedef enum {
    CMDID_IDT_UDS_DATA = 0,             // DesayInterface_pps_IdtUDSdata
    CMDID_DEVELOPER_MODEL_BUTTON = 1,   // DesayInterface_pps_DevModelBtnMsg DESAY To GAC
    CMDID_DID_UDS_DATA = 2,             // DesayInterface_pps_DIDUDSdata DESAY To GAC
    CMDID_DID_UDS_DATA_2 = 3,           // DesayInterface_pps_DIDUDSdata GAC To DESAY
    CMDID_DEVELOPER_MODEL_Receive = 4   // DesayInterface_pps_DevModelRecvMsg GAC To DESAY
} CMDID_DID_DTC_RESP_ENUM;

class DesayInterface_pps_IdtUDSdata{
public:
    DEY_Octet a72a10;
    DEY_Octet a72a11;
    DEY_Octet a72a20;
    DEY_Octet a72a21;
    DEY_Octet a72a22;
    DEY_Octet a72a60;
    DEY_Octet a72a61;
    DEY_Octet a72b10;
    DEY_Octet a72b11;
    DEY_Octet a72b20;
    DEY_Octet a72b21;
    DEY_Octet a72b22;
    DEY_Octet a72b60;
    DEY_Octet a72b61;
    DEY_Octet a72c10;
    DEY_Octet a72c11;
    DEY_Octet a72c20;
    DEY_Octet a72c21;
    DEY_Octet a72c22;
    DEY_Octet a72c60;
    DEY_Octet a72c61;
    DEY_Octet a72d10;
    DEY_Octet a72d11;
    DEY_Octet a72d20;
    DEY_Octet a72d21;
    DEY_Octet a72d22;
    DEY_Octet a72d60;
    DEY_Octet a72d61;
    DEY_Octet a7101c;
    DEY_Octet a7111c;
    DEY_Octet a7121c;
    DEY_Octet a7131c;
    DEY_Octet a70016;
    DEY_Octet a70017;
    DEY_Octet a71002;
    DEY_Octet a71003;
    DEY_Octet a71004;
    DEY_Octet a71005;
    DEY_Octet a71102;
    DEY_Octet a71103;
    DEY_Octet a71104;
    DEY_Octet a71105;
    DEY_Octet a71202;
    DEY_Octet a71203;
    DEY_Octet a71204;
    DEY_Octet a71205;
    DEY_Octet a71302;
    DEY_Octet a71303;
    DEY_Octet a71304;
    DEY_Octet a71305;
    DEY_Octet a72010;
    DEY_Octet a72011;
    DEY_Octet a72012;
    DEY_Octet a72110;
    DEY_Octet a72111;
    DEY_Octet a72112;
    DEY_Octet a72210;
    DEY_Octet a72211;
    DEY_Octet a72220;
    DEY_Octet a72221;
    DEY_Octet a72222;
    DEY_Octet a72260;
    DEY_Octet a72261;
    DEY_Octet a72310;
    DEY_Octet a72311;
    DEY_Octet a72320;
    DEY_Octet a72321;
    DEY_Octet a72322;
    DEY_Octet a72360;
    DEY_Octet a72361;
    DEY_Octet a72410;
    DEY_Octet a72411;
    DEY_Octet a72420;
    DEY_Octet a72421;
    DEY_Octet a72422;
    DEY_Octet a72460;
    DEY_Octet a72461;
    DEY_Octet a72510;
    DEY_Octet a72511;
    DEY_Octet a72520;
    DEY_Octet a72521;
    DEY_Octet a72522;
    DEY_Octet a72560;
    DEY_Octet a72561;
    DEY_Octet a72610;
    DEY_Octet a72611;
    DEY_Octet a72620;
    DEY_Octet a72621;
    DEY_Octet a72622;
    DEY_Octet a72660;
    DEY_Octet a72661;
    DEY_Octet a72710;
    DEY_Octet a72711;
    DEY_Octet a72720;
    DEY_Octet a72721;
    DEY_Octet a72722;
    DEY_Octet a72760;
    DEY_Octet a72761;
    DEY_Octet a72810;
    DEY_Octet a72811;
    DEY_Octet a72820;
    DEY_Octet a72821;
    DEY_Octet a72822;
    DEY_Octet a72860;
    DEY_Octet a72861;
    DEY_Octet a72910;
    DEY_Octet a72911;
    DEY_Octet a72920;
    DEY_Octet a72921;
    DEY_Octet a72922;
    DEY_Octet a72960;
    DEY_Octet a72961;
    DEY_Octet a73349;
    DEY_Octet a73449;
    DEY_Octet a76400;
    DEY_Octet a78187;
    DEY_Octet c07388;
    DEY_Octet c10087;
    DEY_Octet c10187;
    DEY_Octet c12987;
    DEY_Octet c13187;
    DEY_Octet c14087;
    DEY_Octet c14687;
    DEY_Octet c15187;
    DEY_Octet c15587;
    DEY_Octet c18487;
    DEY_Octet c19987;
    DEY_Octet c41881;
    DEY_Octet c42081;
    DEY_Octet c42881;
    DEY_Octet c44781;
    DEY_Octet c48581;
    DEY_Octet d2c081;
    DEY_Octet d2c087;
    DEY_Octet e01181;
    DEY_Octet c16487;
    DEY_Octet d4c081;
    DEY_Octet d4c087;
    DEY_Octet a72d7a;
    DEY_Octet a72d7b;
    DEY_Octet a72d7c;
    DEY_Octet a72d70;
    DEY_Octet a72d71;
    DEY_Octet a72d72;
    DEY_Octet a72d73;
    DEY_Octet a72d74;
    DEY_Octet a72d75;
    DEY_Octet a72d77;
    DEY_Octet a72d78;
    DEY_Octet a72d79;
    DEY_Octet a72e20;
    DEY_Octet a72e21;
    DEY_Octet a72e22;
    DEY_Octet a72e23;
    DEY_Octet a72e24;
    DEY_Octet a72e25;
    DEY_Octet a72e26;
    DEY_Octet a72e27;
    DEY_Octet a72e28;
    DEY_Octet a72e29;
    DEY_Octet a7111e;
    DEY_Octet a7111f;
    DEY_Octet a7121d;
    DEY_Octet a7121e;
    DEY_Octet a7121f;
    DEY_Octet a7131d;
    DEY_Octet a7131e;
    DEY_Octet a7131f;
    DEY_Octet a70120;
    DEY_Octet a70121;
    DEY_Octet a70122;
    DEY_Octet a70123;
    DEY_Octet a70124;
    DEY_Octet a71020;
    DEY_Octet a71021;
    DEY_Octet a71022;
    // 20221011删除
    //DEY_Octet a72305;
    DEY_Octet a72306;
    DEY_Octet a72307;
    DEY_Octet a72308;
    DEY_Octet a72309;
    DEY_Octet a73350;
    DEY_Octet a73455;
    DEY_Octet a73456;
    DEY_Octet a73457;
    DEY_Octet a73458;
    DEY_Octet a78130;
    DEY_Octet c40181;
    DEY_Octet c40481;
    DEY_Octet c41781;
    DEY_Octet c42381;
    DEY_Octet c42481;
    DEY_Octet c49981;
    DEY_Octet d88087;
    DEY_Octet e03b81;
    DEY_Octet a7001c;
    DEY_Octet a7414a;
    DEY_Octet a7416a;
    DEY_Octet a7416f;
    DEY_Octet a7424a;
    DEY_Octet a7434a;
    DEY_Octet a7444a;
    DEY_Octet a71111;
    DEY_Octet a74562;
    DEY_Octet a74662;
    DEY_Octet a74762;
    DEY_Octet a74862;
    DEY_Octet a74954;
    DEY_Octet c42281;
    // 20221011新增
    DEY_Octet a71454;
    // 20221230新增
    DEY_Octet a74a11;
    DEY_Octet a74b11;
    DEY_Octet a74c11;
};

class DesayInterface_pps_DevModelBtnMsg{    // 开发者模式按键消息
public:
    DEY_Octet   devModelBtnMsg;         // 0：默认；1：自动泊车标定；2：记忆泊车标定; 3：环视影像标定
};

class DesayInterface_pps_DevModelRecvMsg{   // 收到标定程序返回消息
public:
    DEY_Octet   devModelRecvMsg;        // 0：默认；1： 窗口显示
};

class DesayInterface_pps_DIDUDSdata{
public:
    DEY_Octet    VIN[17];
    DEY_Octet    ECUSerialNumberData[20];
};
