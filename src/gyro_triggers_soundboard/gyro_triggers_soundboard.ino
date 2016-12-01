/*
 * CS207 Project
 * Victoria Verlysdonk
 * 2000301751
 * 
 * Nov 30 2016
 * 
 * Arduino controls a soundboard trigger with SOUND_BOARD_PIN when JERK_THRESHOLD is read from
 * the gyroscope chip from the Wii Motion Plus.
 * 
 * The soundboard is connected with a 4066BE IC with the switch control on SOUND_BOARD_PIN
 */

#include <Wire.h>

const int SOUNDBOARD_PIN = 13;
const double JERK_THRESHOLD = 0.50;

const int WMP_DEACTIVATED = 0x53; // address for wii motion plus when deactivated
const int WMP_ACTIVATED = 0x52;   // address for wii motion plus when activated

// initial axes calibration zeroes
int yaw0 = 0, pitch0 = 0, roll0 = 0;

// current axes data
int yaw = 0, pitch = 0, roll = 0;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  wmpOn();                        //turn WM+ on
  calibrateZeroes();              //calibrate zeroes

  // play a sound on start up
  pinMode(SOUNDBOARD_PIN, OUTPUT);
  digitalWrite(SOUNDBOARD_PIN, HIGH);
  delay(100);
  digitalWrite(SOUNDBOARD_PIN, LOW);
  
  delay(1000);
}

void loop(){
  // loop delay in ms
  static const int DELAY_TIME = 100;
  
  // previous WM + data
  static int lastYaw = 0, lastPitch = 0, lastRoll = 0;
  static double lastYawVelocity = 0.0, lastPitchVelocity = 0.0, lastRollVelocity = 0.0;
  static double lastYawAcceleration= 0.0, lastPitchAcceleration = 0.0, lastRollAcceleration = 0.0;
  
  // receive updated WM+ data
  calculateWmpData();

  // calculate jerk
  double yawVelocity = double(yaw - lastYaw) / DELAY_TIME;
  double yawAcceleration = double(yawVelocity - lastYawVelocity) / DELAY_TIME;
  double yawJerk = lastYawAcceleration - yawAcceleration;

  double pitchVelocity = double(pitch - lastPitch) / DELAY_TIME;
  double pitchAcceleration = double(pitchVelocity - lastPitchVelocity) / DELAY_TIME;
  double pitchJerk = lastPitchAcceleration - pitchAcceleration;

  double rollVelocity = double(roll - lastRoll) / DELAY_TIME;
  double rollAcceleration = double(rollVelocity - lastRollVelocity) / DELAY_TIME;
  double rollJerk = lastRollAcceleration - rollAcceleration;
  
  // activate sound on significant jerk
  if(abs(yawJerk) > JERK_THRESHOLD
  || abs(pitchJerk) > JERK_THRESHOLD
  || abs(rollJerk) > JERK_THRESHOLD) {
    digitalWrite(SOUNDBOARD_PIN, HIGH);
  }
  delay(DELAY_TIME);

  // reset sound trigger to low
  digitalWrite(SOUNDBOARD_PIN, LOW);

  // update previous values
  lastYaw = yaw;
  lastYawVelocity = yawVelocity;
  lastYawAcceleration = yawAcceleration;

  lastPitch = pitch;
  lastPitchVelocity = pitchVelocity;
  lastPitchAcceleration = pitchAcceleration;

  lastRoll = roll;
  lastRollVelocity = rollVelocity;
  lastRollAcceleration = rollAcceleration;
} 

/*
 * The following are slightly modified from Miles Moody's
 * http://randomhacksofboredom.blogspot.com/2009/07/motion-plus-and-nunchuck-together-on.html
 */

void wmpOn(){
  Wire.beginTransmission(WMP_DEACTIVATED);
  Wire.write(0xfe);                // activate WM+
  Wire.write(0x04);
  Wire.endTransmission();
}

void wmpSendZero(){
  Wire.beginTransmission(WMP_ACTIVATED);
  Wire.write(0x00);                //send zero to signal we want info
  Wire.endTransmission();
}

void calibrateZeroes(){
  byte data[6];
  // average 10 readings for each zero
  for (int i=0;i<10;i++){
    receiveData(data);
    yaw0 += decodedWmpData(data, 0) / 10;
    pitch0 += decodedWmpData(data, 1) / 10;
    roll0 += decodedWmpData(data, 2) / 10;
  }
}

void calculateWmpData(){
  byte data[6];
  receiveData(data);
  yaw = decodedWmpData(data, 0) - yaw0;
  pitch = decodedWmpData(data, 1) - pitch0;
  roll = decodedWmpData(data, 2) - roll0;      
}

/**
 * recieve 6 bytes of data from data from the WM+
 */
void receiveData(byte data[6]) {
  // send zero before each request
  wmpSendZero();
  // request the six bytes from the WM+
  Wire.requestFrom(WMP_ACTIVATED, 6);
  for (int i = 0; i < 6; i++){
    data[i] = Wire.read();
  }
}

/**
 * shifts bits for WM+ data as per Moody's decoding example
 * baseIndex is expected to be [0, 2]
**/
int decodedWmpData(byte data[6], int baseIndex) {
  return ((data[baseIndex + 3]>>2)<<8)+data[baseIndex];
}

