/*
 * data_sub.cpp
 *
 *  Created on: Jun 5, 2023
 *      Author: moxiaopeng
 */
#include "../include/data_sub.h"
#include <vector>
#include <string.h>
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <thread>
#include <unistd.h>
#include <stdio.h>

/**
 * @brief sub uss_info and transform into txt
 */
void GAC_USS_DATA::Data_Sub::USS_TO_TXT(DesayInterface_pps_USSEchoInfo ussecho, std::string txt_name)
{
        std::cout << "USS_TO_TXT start" << std::endl;
        ofstream outfile;
        outfile.open(txt_name, ios::binary | ios::app | ios::in | ios::out);
        for (size_t i = 0; i < 12; i++)
        {
                outfile << (unsigned long long)ussecho.MCU21STimeus << " "
                        << (unsigned long long)ussecho.MCU30RTimeus << " "
                        << (unsigned long long)ussecho.MCU30STimeus << " "
                        << (unsigned long long)ussecho.MCUSocTimeus << " "
                        << i << " "
                        << (signed short)ussecho.USSEchoInfoArray[i].USSDEFirst << " "
                        << (unsigned long long)ussecho.USSEchoInfoArray[i].USSDEFirstTimestamp << " "
                        << (signed short)ussecho.USSEchoInfoArray[i].USSDEFirstLevel << " "
                        << (signed short)ussecho.USSEchoInfoArray[i].USSDESecond << " "
                        << (unsigned long long)ussecho.USSEchoInfoArray[i].USSDESecondTimestamp << " "
                        << (signed short)ussecho.USSEchoInfoArray[i].USSCELeftFirst << " "
                        << (unsigned long long)ussecho.USSEchoInfoArray[i].USSCELeftFirstTimestamp << " "
                        << (signed short)ussecho.USSEchoInfoArray[i].USSCELeftFirstLevel << " "
                        << (signed short)ussecho.USSEchoInfoArray[i].USSCELeftSecond << " "
                        << (unsigned long long)ussecho.USSEchoInfoArray[i].USSCELeftSecondTimestamp << " "
                        << (signed short)ussecho.USSEchoInfoArray[i].USSCERightFirst << " "
                        << (unsigned long long)ussecho.USSEchoInfoArray[i].USSCERightFirstTimestamp << " "
                        << (signed short)ussecho.USSEchoInfoArray[i].USSCERightFirstLevel << " "
                        << (signed short)ussecho.USSEchoInfoArray[i].USSCERightSecond << " "
                        << (unsigned long long)ussecho.USSEchoInfoArray[i].USSCERightSecondTimestamp << " ";
                outfile << "\n";
        }
        outfile << "\n";
        outfile.close();
}
/**
 * @brief sub uss_txt title
 */
void GAC_USS_DATA::Data_Sub::USS_ECHO_TITLE_SETTING(std::string txt_name)
{
        ofstream outfile;
        outfile.open(txt_name, ios::binary | ios::app | ios::in | ios::out);
        outfile << "MCU21STimeus "
                << "MCU30RTimeus "
                << "MCU30STimeus "
                << "MCUSocTimeus ";
        outfile << "USSEchoInfoArray_Seq ";
        outfile << "USSEchoInfoArray.DEFirst "
                << "USSEchoInfoArray.DEFirstTimestamp "
                << "USSEchoInfoArray.DEFirstLevel ";
        outfile << "USSEchoInfoArray.DESecond "
                << "USSEchoInfoArray.DESecondTimestamp ";
        outfile << "USSEchoInfoArray.CELeftFirst "
                << "USSEchoInfoArray.CELeftFirstTimestamp "
                << "USSEchoInfoArray.CELeftFirstLevel ";
        outfile << "USSEchoInfoArray.CELeftSecond "
                << "USSEchoInfoArray.CELeftSecondTimestamp ";
        outfile << "USSEchoInfoArray.CERightFirst "
                << "USSEchoInfoArray.CERightFirstTimestamp "
                << "USSEchoInfoArray.CERightFirstLevel ";
        outfile << "USSEchoInfoArray.CERightSecond "
                << "USSEchoInfoArray.CERightSecondTimestamp ";
        outfile << "\n";
        outfile.close();
}
