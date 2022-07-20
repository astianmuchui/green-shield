#ifndef GSSHIELD_H
#define GSSHIELD_H

#include <dht11.h>

extern dht11 *DHT;

extern uint8_t dht_status;
extern uint8_t tmode;
extern uint8_t tmpF_off; 
extern uint8_t tmpC_off;
extern uint8_t hum_off;

extern uint8_t current_temp;
extern uint8_t current_humidity;
extern uint8_t current_moist;
extern uint8_t current_light;

extern uint8_t maxhum;
extern uint8_t minhum;
extern uint8_t maxlite;
extern uint8_t minlite;
extern uint8_t maxmoist;
extern uint8_t minmoist;
extern uint8_t maxtemp;
extern uint8_t mintemp;

extern uint8_t cal_moist_min;
extern uint8_t cal_moist_max;
extern uint8_t cal_light_min;
extern uint8_t cal_moist_max;

extern uint8_t relay_state[2];
extern uint8_t relay_last[2];
extern uint8_t relay_map[2];
extern uint8_t relay_num;

#endif