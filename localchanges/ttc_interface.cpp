/**
 * ttc_interface.cpp
 * 
 * Copyright (C) 2020, Universidade Federal de Santa Catarina.
 * 
 * This file is part of TTC - 3rdCubeDesing.
 * 
 * TTC code is free source: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * TTC code is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with FloripaSat-Beacon. If not, see <http://www.gnu.org/licenses/>.
 * 
 */

/**
 * \brief Interface for control the TTC interface .
 * 
 * This library suits for RF4463PRO and RF4463F30 in FIFO mode.
 * 
 * \author Bruno Cayres Messias <brunocmessias@hotmail.com>
 * 
 * \version 1.0-dev
 */

#include "RF4463Rasp.h"

using namespace std;
int len_data;
bool tx_flag;

unsigned char rx_buf[20]; // ! change for spi buffer size

RF4463 rf4463;

int initialize_ttc() 
{
    if(!rf4463.init())
    {
     return -1;
    }
    rf4463.rxInit();    // wait for packet from tx
    rf4463.enterStandbyMode(); //enter sleep mode

    return 0;
}

int transmiter_ttc(int *packet_buf)
{
    tx_flag = rf4463.txPacket(packet_buf, sizeof(packet_buf));  //* tx_flag return 1 if ok,
                                                                //* 0 otherwise
    if(tx_flag == 0)
    {
        return -1;
    }
    
    rf4463.enterStandbyMode(); //enter sleep mode

    //TODO:Test a receive confirmation GRS
   

    return 0; 
}

int receiver_ttc()
{
    if(rf4463.waitnIRQ())    // wait for PACKET_RX interrupt
        {
            rf4463.clrInterrupts();
            len_data=rf4463.rxPacket(rx_buf);  // read rx data //! save on rx_buf
            rf4463.rxInit(); //reinitialize rx mode
        }
    return 0;
}

////-------------------------------------------------------------------------------
int create_packet(int data_buf)
{
    //  NGHam protocol packet
}

int decode_packet(int rx_data)
{
    // NGHAm protocol packet;
    //TODO: Decode instructions
    //TODO: Confirmation signals
    //? Need two different functions for confirmaitions signals and instructions?
}

/*
TODO: Make a counter of received and a transmitter packets to know how is going the communications

*/