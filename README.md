# spooky-projects
I made some arduino-powered ghosts to put in my windows


## Parts List
### Essential
- 1x [Adafruit Metro Mini](https://www.adafruit.com/product/2590) -- Compatible with Arduino Uno; any Arduino could be used but might require pin changes.
- 2x [8x8 LED Matrix with I2C Backpack](https://www.adafruit.com/product/1051) -- Comes in multiple colors, but the blue can be hard to resolve from a distance.
- [Common Cathode LEDs](https://www.sparkfun.com/products/9853) -- Could be replaced with single-color LEDs. I use about six per ghost.

### Optional
- [Weatherproof Enclosure](https://www.adafruit.com/product/3931)
- [Push Button](https://www.adafruit.com/product/1505) - Fits in one of the enclosure's openings with a little bit of reaming
- [Jumper cables](https://www.adafruit.com/product/266)
- [Male headers](https://www.adafruit.com/product/2671)
- [Protoboard](https://www.adafruit.com/product/589)

## Construction



> ### Warning About the Shape Files
> The inset shapes are not sized to account for cutting kerf, so you will have to handle that. The service I used for cutting, [Send Cut Send](https://sendcutsend.com/) does it for you, but other services may not.



![Construction Overview](https://i.imgur.com/3eMJmzB.jpg)

![Diffuser](https://i.imgur.com/Mn5IlGe.jpg)

![Back](https://i.imgur.com/mN3oWJs.jpg)

### Pinouts

Each eye needs four out pins. The eyes are not individually controlled
- I2C pins (A4 and A5 on Uno-compatible boards)
- 5V pin
- Ground pin

![Wiring diagram](https://i.imgur.com/6cDhRwq.jpg)

The backlight uses four out pins:
- Red on pin 6
- Green on pin 9
- Blue on pin 10
- Ground

The push button to change the backlight color uses pins 7 and 8
