#ifndef GSDEFS_H
#define GSDEFS_H

#define MAXINPUTSIZE        12  // input buffer size
#define NOERR               0   // error codes
#define TIMEOUT             1
#define BADCHAR             2
#define BADVAL              3

#define LED1                2
#define LED2                3
#define LED3                4
#define LED4                5
#define RELAY1              6   // REL_11relay pins
#define RELAY2              7   // REL_12

#define DHT22               8
#define MOIST_PROBE         A0
#define LDRIN               A1

#define MAXRY               2   // max number of relayS

#define MAP_NONE            0   // mapping vectors
#define MAP_TEMPMIN         1
#define MAP_TEMPMAX         2
#define MAP_HUMIDMIN        3
#define MAP_HUMIDMAX        4
#define MAP_MOISTMIN        5
#define MAP_MOISTMAX        6
#define MAP_LIGHTMIN        7
#define MAP_LIGHTMAX        8

#endif