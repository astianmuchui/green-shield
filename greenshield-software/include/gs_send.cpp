#include <Arduino.h>
#include "gs_gv.h"
#include "gs_send.h"


void send_ok()
{
    Serial.println("OK");
}

void send_relay(uint8_t relay_num)
{
    Serial.print("RY:");
    Serial.print(relay_num);
    Serial.print(":");
    Serial.print(relay_state[relay_num]);
    Serial.println();
}


void send_temp()
{
    Serial.print("TM");
    Serial.print(":");
    Serial.print(current_humidity);
    Serial.println;
}

void send_analog(uint8_t channel)
{
    Serial.print("AN:");
    Serial.print(channel);
    Serial.print(":");
    Serial.print(analogRead(channel));
    Serial.println();
}

void send_humid_max()
{
    Serial.print("GT:HMX:");
    Serial.println(maxhum);
}

void send_humid_min()
{
    Serial.print("GT:HMN:");
    Serial.println(minhum);
}

void send_light_max()
{
    Serial.print("GT:LMX:");
    Serial.println(maxlite);
}

void send_light_min()
{
    Serial.print("GT:LMX:");
    Serial.println(minlite);
}

void send_moist_max()
{
    Serial.print("GT:MMX:");
    Serial.println(maxmoist);
}

void send_moist_min(){
    Serial.print("GT:MMN:");
    Serial.println(minmoist);
}

void send_temp_max()
{
    Serial.print("GT:TMX:");
    Serial.println(max_temp);
}

void send_temp_min(){
    Serial.print("GT:TMP:");
    Serial.println(min_temp);
}

