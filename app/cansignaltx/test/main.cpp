#include <unistd.h>

#include <iostream>
#include <thread>

#include "pps_public/topic_canSignlTx.h"
#include "pps_public/topic_universalTxCanSignlTx.h"

static DESY::ppscontrol *m_ppsctrl;
static DESY::PPS_CFG_STRU g_ppscfg[] = {
    TopicUniversalCanSignalTx::cfg(0, 1),
};

int main() {
    m_ppsctrl = DESY::ppscontrol::Instance(
        g_ppscfg, sizeof(g_ppscfg) / sizeof(g_ppscfg[0]));

    DesayInterface_pps_universalCanSignal_txFast
        universalCanSignal_tx;  //这个结构体可以一次性发送30个can信号到ipc处理
    universalCanSignal_tx.length = 30;  //这里值为几就可以一次性发多少个，最多30
    while (1) {
        sprintf(
            universalCanSignal_tx.canSignals_[0].name, "%s",
            "PAS_Mode");  //对第1个can信号取名字，根据自己需求填写名字,名字写在""内
        universalCanSignal_tx.canSignals_[0].type = 0;
        universalCanSignal_tx.canSignals_[0].value[0] = 1;  //对第1个can信号赋值

        sprintf(
            universalCanSignal_tx.canSignals_[1].name, "%s",
            "PCS_SystemSt");  //对第2个can信号取名字，根据自己需求填写名字,名字写在""内,以下类推
        universalCanSignal_tx.canSignals_[1].type = 0;
        universalCanSignal_tx.canSignals_[1].value[0] =
            1;  //对第2个can信号赋值,以下类推

        sprintf(universalCanSignal_tx.canSignals_[2].name, "%s", "PCS_CalibrateSt");
        universalCanSignal_tx.canSignals_[2].type = 0;
        universalCanSignal_tx.canSignals_[2].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[3].name, "%s", "PCS_MirrorPageDownButtonST");
        universalCanSignal_tx.canSignals_[3].type = 0;
        universalCanSignal_tx.canSignals_[3].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[4].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[4].type = 0;
        universalCanSignal_tx.canSignals_[4].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[5].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[5].type = 0;
        universalCanSignal_tx.canSignals_[5].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[6].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[6].type = 0;
        universalCanSignal_tx.canSignals_[6].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[7].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[7].type = 0;
        universalCanSignal_tx.canSignals_[7].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[8].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[8].type = 0;
        universalCanSignal_tx.canSignals_[8].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[9].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[9].type = 0;
        universalCanSignal_tx.canSignals_[9].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[10].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[10].type = 0;
        universalCanSignal_tx.canSignals_[10].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[11].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[11].type = 0;
        universalCanSignal_tx.canSignals_[11].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[12].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[12].type = 0;
        universalCanSignal_tx.canSignals_[12].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[13].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[13].type = 0;
        universalCanSignal_tx.canSignals_[13].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[14].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[14].type = 0;
        universalCanSignal_tx.canSignals_[14].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[15].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[15].type = 0;
        universalCanSignal_tx.canSignals_[15].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[16].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[16].type = 0;
        universalCanSignal_tx.canSignals_[16].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[17].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[17].type = 0;
        universalCanSignal_tx.canSignals_[17].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[18].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[18].type = 0;
        universalCanSignal_tx.canSignals_[18].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[19].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[19].type = 0;
        universalCanSignal_tx.canSignals_[19].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[20].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[20].type = 0;
        universalCanSignal_tx.canSignals_[20].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[21].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[21].type = 0;
        universalCanSignal_tx.canSignals_[21].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[22].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[22].type = 0;
        universalCanSignal_tx.canSignals_[22].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[23].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[23].type = 0;
        universalCanSignal_tx.canSignals_[23].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[24].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[24].type = 0;
        universalCanSignal_tx.canSignals_[24].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[25].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[25].type = 0;
        universalCanSignal_tx.canSignals_[25].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[26].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[26].type = 0;
        universalCanSignal_tx.canSignals_[26].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[27].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[27].type = 0;
        universalCanSignal_tx.canSignals_[27].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[28].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[28].type = 0;
        universalCanSignal_tx.canSignals_[28].value[0] = 1;

        sprintf(universalCanSignal_tx.canSignals_[29].name, "%s", "PAS_Mode");
        universalCanSignal_tx.canSignals_[29].type = 0;
        universalCanSignal_tx.canSignals_[29].value[0] = 1;

        m_ppsctrl->publish(TOPICID_UNIVERSALCANSIG_TX_FAST_APP,
                           CMDID_UNIVERSAL_CAN_SIGNAL_TX_FAST,
                           sizeof(DesayInterface_pps_universalCanSignal_txFast),
                           (char *)&universalCanSignal_tx);
        sleep(1);
    }
}
