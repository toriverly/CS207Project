# Gyroscopic Lightsaber with Sound 
[![License](https://poser.pugx.org/phpunit/phpunit/license)](https://packagist.org/packages/phpunit/phpunit)

The objective of this project is to construct a low cost but satisfying lightsaber model comprised of a light up blade fixed to a hilt that emits sounds when the blade is swung. We accomplish this by using the gyroscopic sensor from a Wii MotionPlus adapter communicating with an Ardweeny to trigger a push button bigDAWGS sound module. The blade is lit by a string of LEDs (taken from Christmas lights) and the components are housed in the plastic body of an existing toy.

![alt text][completed]

[completed]: https://github.com/toriverly/CS207Project/blob/master/img/complete.jpg "Completed lightsaber"

Repository Contents
===================
* **/src** - software (.ino)
* **/examples** - example software that can be run on the hardware
* **/img** - image files for this readme
* **/README.md** - The file you're reading now! :-D


Requirements and Materials
============
Dependencies:
* Wire.h

Bill of Materials:
* 3 x ~7' Christmas lights
![alt text][lights]

[lights]: https://github.com/toriverly/CS207Project/blob/master/img/lights.jpg "Christmas lights"

* 2 x 560 ohm resistor
* 1 x toggle switch
* 1 x CMOS quad analog switch (https://www.digchip.com/datasheets/parts/datasheet/397/SCL4066BE-pdf.php)
* 1 x battery holder
* 1 x breadboard (rails removed)
* 1 x Ardweeny
![alt text][ardweeny]

[ardweeny]: https://github.com/toriverly/CS207Project/blob/master/img/ardweeny.jpg "Ardweeny"

* 1 x Wii MotionPlus gyro pcb
![alt text][gyro_pcb]

[gyro_pcb]: https://github.com/toriverly/CS207Project/blob/master/img/gyro_pcb.jpg "Wii MotionPlus gyro pcb"

* 1 x bigDAWGS push button sound module
![alt text][sound_module]

[sound_module]: https://github.com/toriverly/CS207Project/blob/master/img/sound_module.jpg "bigDAWGS push button sound module"

* 1 x toy lightsaber (hilt and blade, hollow plastic)
![alt text][hilt]

[hilt]: https://github.com/toriverly/CS207Project/blob/master/img/hilt.jpg "toy lightsaber hilt"

Build Instructions
==================

The Ardweeny needs to be soldered and assembled as per the instructions that come with it.

The housing (toy) needs to be dismantled. In my case, the blade comes off and the hilt pulls apart with some elbow grease and leverage from a screwdriver. I also drilled holes in the bottom cap of the hilt and used an exacto knife to wittle away plastic from the switch hole (because my switch was really big).

We removed the push button switch from the sound module, connecting those wires to the CMOS quad switch instead (pins 8 and 9). The button batteries are removed and a ground and Vin wire should be soldered in their place, to connect to the Ardweeny.

The control pin for the CMOS quad switch connects to the Ardweeny on pin 13.

The Wii MotionPlus is easy to take apart (provided you have a triwing screwdriver). We only need the pcb board containing the gyroscope, as pictured. There are some excellent instructions here:

http://makezine.com/projects/hacking-the-wii-motionplus-to-talk-to-the-arduino/

that illustrate which pins are 3V, GND, SDA and SCL. Note that the gyroscope cannot be connected to +5V!

The LED strings are connected directly to the power supply as they are not to be controlled by any programming on the Ardweeny. All other components receive current through the 3.3V pin on the Ardweeny.

The following illustrates the basic setup. Note that the diagram shows an Arduino Uno, a 4.5V battery pack, and a single LED, but the actual hardware is an Ardweeny, 6V battery pack and a string of LEDs.

![alt text][breadboard]

[breadboard]: https://github.com/toriverly/CS207Project/blob/master/img/project_bb.png "breadboard"

Firmware Installation
=====================
Upload sketch in src using Arduino IDE.


Usage
=====
Operating the lightsaber is intuitive and straightforward. The toggle switch is flicked up into the ON position, the blade lights up, and the sound board is triggered (the lightsaber should be held steady until the sound plays so as to allow the gyroscope to calibrate correctly). Thereafter, the soundboard is triggered when the lightsaber is swung such that its acceleration changes abruptly.

Team
=====
The build team consists of: 
* Tori Verlysdonk -- I did everything.
* Riley Boynton -- He consoled me when I cried and panicked.

Credits
=======

* Miles Moody - basis for code reading from Wii MotionPlus. http://randomhacksofboredom.blogspot.ca/2009/07/motion-plus-and-nunchuck-together-on.html