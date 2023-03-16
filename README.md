# Aircon-Power-Saving-System
---
## TODO
- [ ] create a partial system
- [ ] finalize the whole system

## IN PROGRESS

## FOR TESTING

## COMPLETED
- [x] read inputs from the temperature sensor (DHT11)
- [x] create sample code for relay module
- [x] create sample code for push button 
- [x] create sample code for current sensor

## NOTES
- We need to have voltage sensor to accurately measure voltage 
- *push button input* 
  - 1 for unpressed
  - 0 for pressed
- instead of accurate voltage reading, it is being randomly generated between 210V - 240V since the present voltage sensor can only read a maximum voltage of 25V.

## SUGGESTIONS
- Instead of using aircon's thermostat, we create an advanced one with the power saving mode feature.
- The present voltage sensor can only read 25v at most. I recommend using ZMPT101B voltage sensor for accurate and much larger voltage readings.