
#include "Arduino.h"
#include "gs.h"
#include "gs_gv.h"
#include "gs_mapping.h"
#include <dht11.h>

void read_dht()
{
    int chk = DHT->read_dht(DHT22);

    switch(chk){
        case DHT_OK:
        dht_status = NOERR;
        break;

        case DHT_CHKSUM_ERR:
            dht_status = CHKSUM;
            break;

        case DHT_TIMEOUT_ERR:
            dht_status = TIMEOUT;
            break;

        case DHT_INVALID_VAL;
            dht_status = BADVAL;
            break;

        default:
            dht_status = UNKERR;
            break;
    }
}

uint8_t read_temp(){
    int rval = 0;

    // get data from dht sensor
    if(tmode == TF){
        rval = DHT->tmpF + tmpF_off;
    }else{
        rval = DHT->tmpC + tmpC_off;
    }

    return rval;
}

uint8_t read_humidity()
{
    int rval = 0;

    // get data from dht temperature
    rval = DHT->humR + hum_off;

    return rval;
}

uint8_t read_moisture()
{
    rval = 0;

    rval = analogRead(MOIST_PROBE);
    if(rval <= cal_moist_min){
        rval = 0;
    }else if(rval >= cal_moist_max){
        rval = maxmoist;
    }

    return rval;
}

uint8_t read_light()
{
    int rval = 0;

    // read LDR sensor analog input
    rval = analogRead(LDRIN);

    if(rval <= cal_light_min){
        rval = 0;
    } else if(rval >= cal_light_max){
        rval = maxlite;
    }

    return rval;
}

uint8_t relay_get(uint8_t relay)
{
    return relay_state[relay];
}

void relay_set(uint8_t relay, uint8_t state)
{
    relay_state = state;
}

void relay_all(uint8_t state)
{
    relay_state[0] = state;
    relay_state[1] = state;
}

void relay_update()
{
    if (relay_state[0] == 1)
    {   
        digitalWrite(RELAY1, HIGH);
    }

    if (relay_state[0] == 0)
    {   
        digitalWrite(RELAY1, LOW);
    }

    if (relay_state[1] == 1)
    {   
        digitalWrite(RELAY2, HIGH);
    }

    if (relay_state[0] == 0)
    {   
        digitalWrite(RELAY2, LOW);
    }
    
}

void led_control(uint8_t led_id)
{
    switch (led_id)
    {
    case 0:
        break;

    case 1:
        break;

    case 2:
        break;

    case 3:
        break;
    }
}

void scan_map()
{
    /*
     each relay is mapped to the possible 8 operational modes
     Determine the mapping for a specific relay and see if the enable condition has been met.
     This is extensible to any number of relays
     */

    for (uint8_t i = 0; i < MAXRY; i++) {
        if(rymap[i] != MAP_NONE){

            switch (rymap[i])  {
                case MAP_TEMPMIN:
                    if(current_temp < mintemp){
                        relay_set(i, 1);
                    }else{
                        relay_set(i, 0);
                    }
                    break;

            case MAP_TEMPMAX:
                if(current_temp > max_temp){
                    relay_set(i, 1);
                }else{
                    relay_set(i, 0);
                }
                break;

            case MAP_HUMIDMIN:
                if(current_humid < min_humid){
                    relay_set(i, 1);
                }else{
                    relay_set(i, 0);
                }
                break;

            case MAP_HUMIDMAX:
                if(current_humid > max_humid){
                    relay_set(i, 1);
                }else{
                    relay_set(i, 0);
                }
                break;

                case MAP_MOISTMIN:
                    if(current_moist < minmoist){
                        relay_set(i, 1);
                    }else{
                        relay_set(i, 0);
                    }
                    break;

                case MAP_MOISTMAX:
                    if(current_moist > maxmoist){
                        relay_set(i, 1);
                    }else{
                        relay_set(i, 0);
                    }
                    break;

                case MAP_LIGHTMIN:
                    if(current_light < minlight){
                        relay_set(i, 1);
                    }else{
                        relay_set(i, 0);
                    }
                    break;

                default:
                    // do nothing
                    break;
            }

            }
    }
}

