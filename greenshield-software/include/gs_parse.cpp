#include "Arduino.h"
#include "gs.h"
#include "gs_gv.h"
#include "gs_parse.h"
#include "gs_send.h"
#include "gs_mapping.h"


void parse_cmd()
{
    // collect incoming ASCII characters until a newline is encountered
    uint8_t achan = 0;
    uint8_t inchar = 0;
    uint8_t i = 0;
    uint8_t slen = 0;
    uint8_t ccnt = 0;
    uint8_t ryst = 0;

    char instr[MAXINPUTSIZE]; // input buffer

    if(Serial.available() == 0){
        return;
    }

    while (true)
    {
        if(Serial.available > 0){
            inchar = Serial.read();

            // read incoming data until \n (0x10) char in encountered
            if(inchar == 0x10){
                instr[i] = 0;
                slen = i;
                break;
            }

            // prevent buffer oveflow
            if (i >= MAXINPUTSIZE){
                intstr[i] = 0;
                slen = i;
                break;
            }

            intstr[i] = (char) inchar;
            i++;
            
        }
    }

    switch (instr[0]){
        case 'A':   // AN:n:?
            if (instr[1] == 'N'){
                if (instr[2] == ':'){
                    achan = atoi((char *) &instr[3]);

                    if ((achan >= 0) && (achan < 6)){
                        if (instr[4] == ':'){
                            if (instr[5] == '?'){
                                send_analog(achan);
                                break;
                            }
                        }
                        
                    }else{
                        send_error(BADVAL);
                        break;
                    }
                    
                }
                
            }
            send_error(BADCHAR);        
            break;

        case 'G':
            if(instr[1] == 'T'){
                if (instr[2] == ':'){
                    if((instr[3] == 'H') && (instr[4] == 'M')){
                        if(instr[5] == 'X'){  // GT:HMX
                            send_humid_max();
                        }else if(instr[5] == 'N'){  // GT:HMN
                            send_humid_min();
                            break;
                        }
                    }

                    if((instr[3] == 'L') && (instr[4] == 'M')){
                        if(instr[5] == 'X'){  // GT:LMX
                            send_light_max();
                        }else if(instr[5] == 'N'){  // GT:LMN
                            send_light_min();
                            break;
                        }
                    }

                    if((instr[3] == 'M') && (instr[4] == 'M')){
                        if(instr[5] == 'X'){  // GT:MMX
                            send_moisture_max();
                        }else if(instr[5] == 'N'){  // GT:MMN
                            send_moisture_min();
                            break;
                        }
                    }

                    if((instr[3] == 'T') && (instr[4] == 'M')){
                        if(instr[5] == 'X'){  // GT:TMX
                            send_temp_max();
                        }else if(instr[5] == 'N'){  // GT:TMN
                            send_temp_min();
                            break;
                        }
                    }
                }           
            }

            send_error(BADCHAR);
            break;

        case 'H':
            if(instr[1] == 'M'){
                if(instr[2] == ':'){
                    if (instr[3] == '?'){ // HM:?
                        send_humidity();
                        break;
                    }                
                }
            }

            send_error(BADCHAR);
            break;

        case 'R':
            if(instr[1] == 'Y'){
                if(instr[2] == ':'){
                    if(instr[3] == 'A'){
                        if(instr[4] == ':'){
                            if(instr[5] == '1'){ // RY:A:1
                                relay_all(1);
                                send_ok;
                                break;
                            }else if(instr[5] == '0'){ // RY:A:0
                                relay_all(0);
                                break;
                            }
                        }
                    }else{
                        relay_num = atoi((char *) &instr[3]);   // RY:n:?
                        if ((relay_num >= 0) && (relay_num < 2)){
                            // return relay state
                            if((instr[4] == ':') && (instr[5] == '?')){  
                                send_relay(relay_num);
                                break;
                            } else if(instr[4] == ':'){ // RY:n:1/0
                                // overide relay state
                                if((instr[5] == '0') || (instr[5] == '1')){
                                    ryst = atoi((char *) &instr[5]);
                                    relay_set(relay_num, ryst);
                                    send_ok();
                                    break;
                                }

                                // disable mapping for a specified relay
                                else if(instr[5] == 'N'){
                                    if(instr[6] == 'O'){
                                        if(instr[7] == 'N'){
                                            relay_map[relay_num] = MAP_NONE;
                                            send_ok();
                                        }
                                    }
                                }

                                // assign relay to min or max for a given output
                                else if(instr[5] == 'H'){
                                    if(instr[6] == 'M'){
                                        if(instr[7] == 'N'){
                                            relay_map[relay_num] = MAP_HUMIDMIN;
                                            send_ok();
                                        }
                                        else if(instr[7] == 'X'){
                                            relay_map[relay_num] = MAP_HUMIDMAX;
                                            send_ok();                                        }
                                    } else{
                                        send_error(BADCHAR);
                                    }
                                }
                                break;
                            }

                            else if(instr[5] == 'L'){
                                if(instr[6] == 'M'){
                                    if(instr[7] == 'X'){
                                        relay_map[relay_num] = MAP_LIGHTMIN;
                                        send_ok();
                                    } else if(instr[7] == 'X'){
                                        relay_map[relay_num] = MAP_LIGHTMAX;
                                        send_ok();
                                    } else{
                                        send_error(BADCHAR);
                                    }
                                }
                                break;
                            }

                            else if(instr[5] == 'M'){
                                if(instr[6] == 'M'){
                                    if(instr[7] == 'N'){
                                        relay_map[relay_num] = MAP_MOISTMIN;
                                        send_ok();
                                    }
                                    else if(instr[7] == 'X'){
                                        relay_map[relay_num] = MAP_MOISTMAX;
                                        send_ok();
                                    } else{
                                        send_error(BADCHAR);
                                    }
                                }
                                break;
     }
                                else if (instr[5] == 'T') {
                                    if (instr[6] == 'M') {
                                        if (instr[7] == 'N') {
                                            rymap[rynum] = MAP_TEMPMIN;
                                            SendOK();
                                        }
                                        else if (instr[7] == 'X') {
                                            rymap[rynum] = MAP_TEMPMAX;
                                            SendOK();
                                        }
                                        else {
                                            SendErr(BADCHAR);
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            SendErr(BADCHAR);
            break;

        case 'S':
            if (instr[1] == 'T') {
                if (instr[2] == ':') {
                    if ((instr[3] == 'H') && (instr[4] == 'M')) {
                        if (instr[5] == 'X') {                      // ST:HMX
                            if (instr[6] == ':') {
                                maxhum = CvtInt(instr,7,slen);
                                send_ok();
                                break;
                            }
                        }
                        else if (instr[5] == 'N') {                 // ST:HMN
                            if (instr[6] == ':') {
                                minhum = CvtInt(instr,7,slen);
                                send_ok();
                                break;
                            }
                        }
                    }

                    if ((instr[3] == 'L') && (instr[4] == 'M')) {
                        if (instr[5] == 'X') {                      // ST:LMX
                            if (instr[6] == ':') {
                                maxlite = CvtInt(instr,7,slen);
                                send_ok();
                                break;
                            }
                        }
                        else if (instr[5] == 'N') {                 // ST:LMN
                            if (instr[6] == ':') {
                                minlite = CvtInt(instr,7,slen);
                                send_ok();
                                break;
                            }
                        }
                    }

                    if ((instr[3] == 'M') && (instr[4] == 'M')) {
                        if (instr[5] == 'X') {                      // ST:MMX
                            if (instr[6] == ':') {
                                maxmoist = CvtInt(instr,7,slen);
                                send_ok();
                                break;
                            }
                        }
                        else if (instr[5] == 'N') {                 // ST:MMN
                            if (instr[6] == ':') {
                                minmoist = CvtInt(instr,7,slen);
                                send_ok();
                                break;
                            }
                        }
                    }

                    if ((instr[3] == 'T') && (instr[4] == 'M')) {
                        if (instr[5] == 'X') {                      // ST:TMX
                            if (instr[6] == ':') {
                                maxtemp = CvtInt(instr,7,slen);
                                send_ok();
                                break;
                            }
                        }
                        else if (instr[5] == 'N') {                 // ST:TMN
                            if (instr[6] == ':') {
                                mintemp = CvtInt(instr,7,slen);
                                send_ok();
                                break;
                            }
                        }
                    }
                }
            }
            send_error(BADCHAR);
            break;
        case 'T':                                                   // TM:?
            if (instr[1] == 'M') {
                if (instr[2] == ':') {
                    if (instr[3] = '?') {
                        send_temp();
                        break;
                    }
                }
            }
            send_error(BADCHAR);
            break;
        default:
            send_error(BADCHAR);
            break;
    }

}


void send_error(uint8_t error_type)
{
    Serial.print("ER:");

    switch(error_type){
        case TIMEOUT:
            Serial.print("TO");
            break;
        
        case BADCHAR:
            Serial.print("BC");
            break;

        case BADVAL:
            Serial.print("IV");
            break;
    }

    Serial.println();
    Serial.flush();
}