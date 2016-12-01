# sda5708_siemens
LPC1114 library to drive the SDA5708 from Siemens
using SPI0 

check please [1] for more informations.

[1] http://www.sbprojects.com/knowledge/footprints/sda5708/index.php

Pin 1. Vcc
Pin 1 is connected to the Vcc supply (+5V).

Pin 2. Load / SS
The Load pin is an active low input used to enable data transfer into the display. When Load is low, data is clocked into the 8 bit serial data register. When Load goes high, the contents of the 8 bit serial data register are evaluated by the display controller.
While Load remains high the Data and SDCLK pins may be used to control other serial devices on the same bus.

Pin 3. Data
The Data pin holds the bits to be clocked into the serial data register whenever the SDCLK line goes high. The least significant bit D0 is loaded first.

Pin 4. SDCLK
SDCLK is the serial clock line. Data is accepted by the display's serial data register when the SDCLK line goes high. The Load pin must be low for the serial data register to accept any data.
The minimum clock period is 200ns. Setup time, the time between a stable Data line and a rising SDCLK signal, should be a minimum of 50ns.

Pin 5. Reset
When the Reset pin is held low, the display will be reset. The multiplex counter, the address register, the control word and the display bit patterns are all cleared. This means that the display will be blank and the display is set to 100% brightness and maximum peak current.
During normal operation the Reset pin is only made low for a short period when power is applied to the circuit and is left at high level from then on.

Pin 6. GND
This is simply the ground connection. 