//  The following are callibration variables to be used
// callibrate according to the application area

// todo: create an interface for user to callibrate these values

#include "gs.h"
#include <dht11>

dht11 *DHT = new dht11();

uint8_t dht_status = NOERR;
uint8_t tmode = TC;
uint8_t tmpF_off = 2; // todo: change offset values
uint8_t tmpC_off = 2;
uint8_t hum_off = 5;

uint8_t current_humidity;
uint8_t current_temperature;
uint8_t current_moisture;
uint8_t current_light;

// setpoint values
uint8_t maxhum = 60; //% relative humidity
uint8_t minhum = 40;
uint8_t maxlite = 90; // relative illumination
uint8_t minlite = 10; 
uint8_t maxmoist = 70; // % estimate
uint8_t minmoist = 20;
uint8_t maxtemp = 30; // given in deg Celcius
uint8_t mintemp = 20;

// callibration values derived from measurements
uint8_t cal_moist_min = 40;
uint8_t cal_moist_max = 400;
uint8_t cal_light_min = 50;
uint8_t cal_light_max = 300;
uint8_t cal_light_min = 30;

// relay control variables
uint8_t relay_state[2] = {0, 0};
uint8_t relay_last[2] = {0, 0};
uint8_t relay_map[2];
uint8_t relay_num = 0;

