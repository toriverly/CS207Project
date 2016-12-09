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

Here is where you give specific instructions about how the device is built. The more detail the better -- especially if your build is very complicated. Here you should include schematics of your build: 

If there are any special instructions on how to assemble the hardware, we should note it here as well. For example, if the user should solder things in a specific order, you should give them a heads-up.

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