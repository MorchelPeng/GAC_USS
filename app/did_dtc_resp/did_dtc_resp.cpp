#include <unistd.h>
#include <iostream>
#include "topic_did_dtc_resp.h"
#include "app_pps_protocal.h"
#include "ppscontrol.h"

extern "C"{
    int32_t appLogGlobalTimeInit();
    uint64_t appLogGetGlobalTimeInUsec();
}

static DESY::ppscontrol  *m_ppsctrl;
static DESY::PPS_CFG_STRU g_ppscfg[] = {
    Topic_Did_Dtc_Resp_class::cfg(1,1),
};

static void message_callback(int topicid,int cmdid,int size,char *pdata);

int main() {

    m_ppsctrl = DESY::ppscontrol::Instance(g_ppscfg,sizeof(g_ppscfg)/sizeof(g_ppscfg[0]));
    DESY::ppscontrol::Instance()->registerCallback(message_callback);
    printf("Did_Dtc_Respond pps receive thread start...\n");
    appLogGlobalTimeInit();

    for (size_t i = 0; i < 15; i++)
    {
        DesayInterface_pps_DIDUDSdata data = { 0 };
        m_ppsctrl->publish(TOPICID_DID_DTC_RESP_APP, CMDID_DID_UDS_DATA_2, sizeof(data), (char*)&data);
        sleep(3);
        //pause();
    }
    return 0;
}


void message_callback(int topicid, int cmdid, int size, char *pdata) 
{
    if(topicid == TOPICID_DID_DTC_RESP_APP && cmdid == CMDID_IDT_UDS_DATA)
    {
        DesayInterface_pps_IdtUDSdata* pPpsReceive = (DesayInterface_pps_IdtUDSdata*)pdata;
        printf("Receive CMDID_IDT_UDS_DATA start\n");

        printf("a72a10:%d\r\n",pPpsReceive->a72a10);
        printf("a72a11:%d\r\n",pPpsReceive->a72a11);
        printf("a72a20:%d\r\n",pPpsReceive->a72a20);
        printf("a72a21:%d\r\n",pPpsReceive->a72a21);
        printf("a72a22:%d\r\n",pPpsReceive->a72a22);
        printf("a72a60:%d\r\n",pPpsReceive->a72a60);
        printf("a72a61:%d\r\n",pPpsReceive->a72a61);
        printf("a72b10:%d\r\n",pPpsReceive->a72b10);
        printf("a72b11:%d\r\n",pPpsReceive->a72b11);
        printf("a72b20:%d\r\n",pPpsReceive->a72b20);
        printf("a72b21:%d\r\n",pPpsReceive->a72b21);
        printf("a72b22:%d\r\n",pPpsReceive->a72b22);
        printf("a72b60:%d\r\n",pPpsReceive->a72b60);
        printf("a72b61:%d\r\n",pPpsReceive->a72b61);
        printf("a72c10:%d\r\n",pPpsReceive->a72c10);
        printf("a72c11:%d\r\n",pPpsReceive->a72c11);
        printf("a72c20:%d\r\n",pPpsReceive->a72c20);
        printf("a72c21:%d\r\n",pPpsReceive->a72c21);
        printf("a72c22:%d\r\n",pPpsReceive->a72c22);
        printf("a72c60:%d\r\n",pPpsReceive->a72c60);
        printf("a72c61:%d\r\n",pPpsReceive->a72c61);
        printf("a72d10:%d\r\n",pPpsReceive->a72d10);
        printf("a72d11:%d\r\n",pPpsReceive->a72d11);
        printf("a72d20:%d\r\n",pPpsReceive->a72d20);
        printf("a72d21:%d\r\n",pPpsReceive->a72d21);
        printf("a72d22:%d\r\n",pPpsReceive->a72d22);
        printf("a72d60:%d\r\n",pPpsReceive->a72d60);
        printf("a72d61:%d\r\n",pPpsReceive->a72d61);
        printf("a7101c:%d\r\n",pPpsReceive->a7101c);
        printf("a7111c:%d\r\n",pPpsReceive->a7111c);
        printf("a7121c:%d\r\n",pPpsReceive->a7121c);
        printf("a7131c:%d\r\n",pPpsReceive->a7131c);
        printf("a70016:%d\r\n",pPpsReceive->a70016);
        printf("a70017:%d\r\n",pPpsReceive->a70017);
        printf("a71002:%d\r\n",pPpsReceive->a71002);
        printf("a71003:%d\r\n",pPpsReceive->a71003);
        printf("a71004:%d\r\n",pPpsReceive->a71004);
        printf("a71005:%d\r\n",pPpsReceive->a71005);
        printf("a71102:%d\r\n",pPpsReceive->a71102);
        printf("a71103:%d\r\n",pPpsReceive->a71103);
        printf("a71104:%d\r\n",pPpsReceive->a71104);
        printf("a71105:%d\r\n",pPpsReceive->a71105);
        printf("a71202:%d\r\n",pPpsReceive->a71202);
        printf("a71203:%d\r\n",pPpsReceive->a71203);
        printf("a71204:%d\r\n",pPpsReceive->a71204);
        printf("a71205:%d\r\n",pPpsReceive->a71205);
        printf("a71302:%d\r\n",pPpsReceive->a71302);
        printf("a71303:%d\r\n",pPpsReceive->a71303);
        printf("a71304:%d\r\n",pPpsReceive->a71304);
        printf("a71305:%d\r\n",pPpsReceive->a71305);
        printf("a72010:%d\r\n",pPpsReceive->a72010);
        printf("a72011:%d\r\n",pPpsReceive->a72011);
        printf("a72012:%d\r\n",pPpsReceive->a72012);
        printf("a72110:%d\r\n",pPpsReceive->a72110);
        printf("a72111:%d\r\n",pPpsReceive->a72111);
        printf("a72112:%d\r\n",pPpsReceive->a72112);
        printf("a72210:%d\r\n",pPpsReceive->a72210);
        printf("a72211:%d\r\n",pPpsReceive->a72211);
        printf("a72220:%d\r\n",pPpsReceive->a72220);
        printf("a72221:%d\r\n",pPpsReceive->a72221);
        printf("a72222:%d\r\n",pPpsReceive->a72222);
        printf("a72260:%d\r\n",pPpsReceive->a72260);
        printf("a72261:%d\r\n",pPpsReceive->a72261);
        printf("a72310:%d\r\n",pPpsReceive->a72310);
        printf("a72311:%d\r\n",pPpsReceive->a72311);
        printf("a72320:%d\r\n",pPpsReceive->a72320);
        printf("a72321:%d\r\n",pPpsReceive->a72321);
        printf("a72322:%d\r\n",pPpsReceive->a72322);
        printf("a72360:%d\r\n",pPpsReceive->a72360);
        printf("a72361:%d\r\n",pPpsReceive->a72361);
        printf("a72410:%d\r\n",pPpsReceive->a72410);
        printf("a72411:%d\r\n",pPpsReceive->a72411);
        printf("a72420:%d\r\n",pPpsReceive->a72420);
        printf("a72421:%d\r\n",pPpsReceive->a72421);
        printf("a72422:%d\r\n",pPpsReceive->a72422);
        printf("a72460:%d\r\n",pPpsReceive->a72460);
        printf("a72461:%d\r\n",pPpsReceive->a72461);
        printf("a72510:%d\r\n",pPpsReceive->a72510);
        printf("a72511:%d\r\n",pPpsReceive->a72511);
        printf("a72520:%d\r\n",pPpsReceive->a72520);
        printf("a72521:%d\r\n",pPpsReceive->a72521);
        printf("a72522:%d\r\n",pPpsReceive->a72522);
        printf("a72560:%d\r\n",pPpsReceive->a72560);
        printf("a72561:%d\r\n",pPpsReceive->a72561);
        printf("a72610:%d\r\n",pPpsReceive->a72610);
        printf("a72611:%d\r\n",pPpsReceive->a72611);
        printf("a72620:%d\r\n",pPpsReceive->a72620);
        printf("a72621:%d\r\n",pPpsReceive->a72621);
        printf("a72622:%d\r\n",pPpsReceive->a72622);
        printf("a72660:%d\r\n",pPpsReceive->a72660);
        printf("a72661:%d\r\n",pPpsReceive->a72661);
        printf("a72710:%d\r\n",pPpsReceive->a72710);
        printf("a72711:%d\r\n",pPpsReceive->a72711);
        printf("a72720:%d\r\n",pPpsReceive->a72720);
        printf("a72721:%d\r\n",pPpsReceive->a72721);
        printf("a72722:%d\r\n",pPpsReceive->a72722);
        printf("a72760:%d\r\n",pPpsReceive->a72760);
        printf("a72761:%d\r\n",pPpsReceive->a72761);
        printf("a72810:%d\r\n",pPpsReceive->a72810);
        printf("a72811:%d\r\n",pPpsReceive->a72811);
        printf("a72820:%d\r\n",pPpsReceive->a72820);
        printf("a72821:%d\r\n",pPpsReceive->a72821);
        printf("a72822:%d\r\n",pPpsReceive->a72822);
        printf("a72860:%d\r\n",pPpsReceive->a72860);
        printf("a72861:%d\r\n",pPpsReceive->a72861);
        printf("a72910:%d\r\n",pPpsReceive->a72910);
        printf("a72911:%d\r\n",pPpsReceive->a72911);
        printf("a72920:%d\r\n",pPpsReceive->a72920);
        printf("a72921:%d\r\n",pPpsReceive->a72921);
        printf("a72922:%d\r\n",pPpsReceive->a72922);
        printf("a72960:%d\r\n",pPpsReceive->a72960);
        printf("a72961:%d\r\n",pPpsReceive->a72961);
        printf("a73349:%d\r\n",pPpsReceive->a73349);
        printf("a73449:%d\r\n",pPpsReceive->a73449);
        printf("a76400:%d\r\n",pPpsReceive->a76400);
        printf("a78187:%d\r\n",pPpsReceive->a78187);
        printf("c07388:%d\r\n",pPpsReceive->c07388);
        printf("c10087:%d\r\n",pPpsReceive->c10087);
        printf("c10187:%d\r\n",pPpsReceive->c10187);
        printf("c12987:%d\r\n",pPpsReceive->c12987);
        printf("c13187:%d\r\n",pPpsReceive->c13187);
        printf("c14087:%d\r\n",pPpsReceive->c14087);
        printf("c14687:%d\r\n",pPpsReceive->c14687);
        printf("c15187:%d\r\n",pPpsReceive->c15187);
        printf("c15587:%d\r\n",pPpsReceive->c15587);
        printf("c18487:%d\r\n",pPpsReceive->c18487);
        printf("c19987:%d\r\n",pPpsReceive->c19987);
        printf("c41881:%d\r\n",pPpsReceive->c41881);
        printf("c42081:%d\r\n",pPpsReceive->c42081);
        printf("c42881:%d\r\n",pPpsReceive->c42881);
        printf("c44781:%d\r\n",pPpsReceive->c44781);
        printf("c48581:%d\r\n",pPpsReceive->c48581);
        printf("d2c081:%d\r\n",pPpsReceive->d2c081);
        printf("d2c087:%d\r\n",pPpsReceive->d2c087);
        printf("e01181:%d\r\n",pPpsReceive->e01181);
        printf("c16487:%d\r\n",pPpsReceive->c16487);
        printf("d4c081:%d\r\n",pPpsReceive->d4c081);
        printf("d4c087:%d\r\n",pPpsReceive->d4c087);
        printf("a72d7a:%d\r\n",pPpsReceive->a72d7a);
        printf("a72d7b:%d\r\n",pPpsReceive->a72d7b);
        printf("a72d7c:%d\r\n",pPpsReceive->a72d7c);
        printf("a72d70:%d\r\n",pPpsReceive->a72d70);
        printf("a72d71:%d\r\n",pPpsReceive->a72d71);
        printf("a72d72:%d\r\n",pPpsReceive->a72d72);
        printf("a72d73:%d\r\n",pPpsReceive->a72d73);
        printf("a72d74:%d\r\n",pPpsReceive->a72d74);
        printf("a72d75:%d\r\n",pPpsReceive->a72d75);
        printf("a72d77:%d\r\n",pPpsReceive->a72d77);
        printf("a72d78:%d\r\n",pPpsReceive->a72d78);
        printf("a72d79:%d\r\n",pPpsReceive->a72d79);
        printf("a72e20:%d\r\n",pPpsReceive->a72e20);
        printf("a72e21:%d\r\n",pPpsReceive->a72e21);
        printf("a72e22:%d\r\n",pPpsReceive->a72e22);
        printf("a72e23:%d\r\n",pPpsReceive->a72e23);
        printf("a72e24:%d\r\n",pPpsReceive->a72e24);
        printf("a72e25:%d\r\n",pPpsReceive->a72e25);
        printf("a72e26:%d\r\n",pPpsReceive->a72e26);
        printf("a72e27:%d\r\n",pPpsReceive->a72e27);
        printf("a72e28:%d\r\n",pPpsReceive->a72e28);
        printf("a72e29:%d\r\n",pPpsReceive->a72e29);
        printf("a7111e:%d\r\n",pPpsReceive->a7111e);
        printf("a7111f:%d\r\n",pPpsReceive->a7111f);
        printf("a7121d:%d\r\n",pPpsReceive->a7121d);
        printf("a7121e:%d\r\n",pPpsReceive->a7121e);
        printf("a7121f:%d\r\n",pPpsReceive->a7121f);
        printf("a7131d:%d\r\n",pPpsReceive->a7131d);
        printf("a7131e:%d\r\n",pPpsReceive->a7131e);
        printf("a7131f:%d\r\n",pPpsReceive->a7131f);
        printf("a70120:%d\r\n",pPpsReceive->a70120);
        printf("a70121:%d\r\n",pPpsReceive->a70121);
        printf("a70122:%d\r\n",pPpsReceive->a70122);
        printf("a70123:%d\r\n",pPpsReceive->a70123);
        printf("a70124:%d\r\n",pPpsReceive->a70124);
        printf("a71020:%d\r\n",pPpsReceive->a71020);
        printf("a71021:%d\r\n",pPpsReceive->a71021);
        printf("a71022:%d\r\n",pPpsReceive->a71022);
        printf("a72306:%d\r\n",pPpsReceive->a72306);
        printf("a72307:%d\r\n",pPpsReceive->a72307);
        printf("a72308:%d\r\n",pPpsReceive->a72308);
        printf("a72309:%d\r\n",pPpsReceive->a72309);
        printf("a73350:%d\r\n",pPpsReceive->a73350);
        printf("a73455:%d\r\n",pPpsReceive->a73455);
        printf("a73456:%d\r\n",pPpsReceive->a73456);
        printf("a73457:%d\r\n",pPpsReceive->a73457);
        printf("a73458:%d\r\n",pPpsReceive->a73458);
        printf("a78130:%d\r\n",pPpsReceive->a78130);
        printf("c40181:%d\r\n",pPpsReceive->c40181);
        printf("c40481:%d\r\n",pPpsReceive->c40481);
        printf("c41781:%d\r\n",pPpsReceive->c41781);
        printf("c42381:%d\r\n",pPpsReceive->c42381);
        printf("c42481:%d\r\n",pPpsReceive->c42481);
        printf("c49981:%d\r\n",pPpsReceive->c49981);
        printf("d88087:%d\r\n",pPpsReceive->d88087);
        printf("e03b81:%d\r\n",pPpsReceive->e03b81);
        printf("a7001c:%d\r\n",pPpsReceive->a7001c);
        printf("a7414a:%d\r\n",pPpsReceive->a7414a);
        printf("a7416a:%d\r\n",pPpsReceive->a7416a);
        printf("a7416f:%d\r\n",pPpsReceive->a7416f);
        printf("a7424a:%d\r\n",pPpsReceive->a7424a);
        printf("a7434a:%d\r\n",pPpsReceive->a7434a);
        printf("a7444a:%d\r\n",pPpsReceive->a7444a);
        printf("a71111:%d\r\n",pPpsReceive->a71111);
        printf("a74562:%d\r\n",pPpsReceive->a74562);
        printf("a74662:%d\r\n",pPpsReceive->a74662);
        printf("a74762:%d\r\n",pPpsReceive->a74762);
        printf("a74862:%d\r\n",pPpsReceive->a74862);
        printf("a74954:%d\r\n",pPpsReceive->a74954);
        printf("c42281:%d\r\n",pPpsReceive->c42281);
        printf("a71454:%d\r\n",pPpsReceive->a71454);
        printf("a74a11:%d\r\n",pPpsReceive->a74a11);
        printf("a74b11:%d\r\n",pPpsReceive->a74b11);
        printf("a74c11:%d\r\n",pPpsReceive->a74c11);

        printf("Receive CMDID_IDT_UDS_DATA end.\n");
    }
    else if (topicid == TOPICID_DID_DTC_RESP_APP && cmdid == CMDID_DID_UDS_DATA)
    {
        DesayInterface_pps_DIDUDSdata* pDIDUDSdata = (DesayInterface_pps_DIDUDSdata*)pdata;
        printf("DesayInterface_pps_DIDUDSdata.VIN = %s\n", pDIDUDSdata->VIN);
        printf("DesayInterface_pps_DIDUDSdata.ECUSerialNumberData = %s\n", pDIDUDSdata->ECUSerialNumberData);
    }
    // else
    // {
    //     printf("Unknown TopicID:%d\r\n", topicid);
    //     printf("Unknown CMDID:%d\r\n", cmdid);
    // }
}


