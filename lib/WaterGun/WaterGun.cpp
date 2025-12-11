#include "WaterGun.h"
#include <Arduino.h>  

// Uses pin 22 and 23 (PA0 and PA1) for the water gun

namespace WaterGun {

    // Bit positions on PORTA
    constexpr uint8_t FWD_BIT  = PA0;  // bit 0
    constexpr uint8_t BACK_BIT = PA1;  // bit 1

    bool shot = false;

    void setup() {
        // Set PA0 and PA1 as outputs: DDRA |= (1 << PA0) | (1 << PA1);
        DDRA |= _BV(FWD_BIT) | _BV(BACK_BIT);

        // Initialize outputs:
        // FWD low, BACK high
        PORTA &= ~_BV(FWD_BIT);   // FWD = LOW
        PORTA |=  _BV(BACK_BIT);  // BACK = HIGH
    }

    bool shoot() {
        if (!shot) {

            // both are low to avoid shorts
            PORTA &= ~(_BV(BACK_BIT) | _BV(FWD_BIT));  // BACK = LOW, FWD = LOW

            unsigned long startTime = millis();
            while (millis() - startTime < 500) {
                // busy-wait 500 ms
            }

            // Drive forward line HIGH
            PORTA |= _BV(FWD_BIT);

            shot = true;
        }
        return shot;
    }

}
