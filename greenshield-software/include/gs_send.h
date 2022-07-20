#ifndef GSSEND_H
#define GSSEND_H

void send_ok();

void send_relay(uint8_t relay_num);
void send_temp();
void send_humidity();
void send_analog(uint8_t channel);

void send_humid_max();
void send_humid_min();
void send_light_max();
void send_light_min();
void send_moist_max();
void send_moist_min();
void send_temp_max();
void send_temp_min();

#endif