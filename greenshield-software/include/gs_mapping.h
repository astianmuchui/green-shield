#ifndef GSMAP_H
#define GSMAP_H

void read_dht();
uint8_t read_temp();
uint8_t read_humidity();
uint8_t read_moisture();
uint8_t read_light();

uint8_t relay_get(uint8_t relay);
uint8_t relay_set(uint8_t relay, uint8_t state);
void relay_all(uint8_t state);
void relay_update();

void led_control(uint8_t ledx);
void scan_map();

#endif