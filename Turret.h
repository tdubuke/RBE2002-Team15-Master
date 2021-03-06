// Turret.h
// H file to hold all class information of the air turret

#include <Servo.h>
#include <Arduino.h>
#include "myStepper.h"

#ifndef TURRET_H
#define TURRET_H

#define LEFT true //CCW direction is LOW
#define RIGHT false //CW direction is HIGH

#define UP true
#define DOWN false

#define STEP_ANGLE 1.8

#define SIXTEENTH_STEP_ANGLE 0.2

#define ERROR_BAND 28 //amount of tolerance on the flame read value

#define TILT_ANGLE 0.087890625 //degrees per step on the tilt stepper

class Turret{
public:
  //initialize the turret with
  // - Fan Pin
  // - Pan Step Pin
  // - Pan Direction Pin
  // - Tilt Step Pin //wip
  // - Tilt Direction Pin //wip
  
  Turret(int iFanPin, int iPanStep, int iPanDir, int ms1, int ms2, int ms3, int tilt1, int tilt2, int tilt3, int tilt4);
  void initTurret();
  void ArmFan();
  double doTilt(boolean goDirection);

  void spinFan();
  void stopFan();

  void doSweep();
  boolean alignPan(int flameRead);
  
  double getAngle();

  double getTiltAngle();

  double alignToZero();

  boolean alignTilt(int flameRead);

  double getAdjustedAngle();

  void calcTiltAdjust(double flameHeight);

  boolean tiltToAngle(double inputAngle);

  void doUpDown();
  
private:
  Servo sESC;

  int tilt1, tilt2, tilt3, tilt4;

  myStepper sTilt;
  
  int iFanMotor;
  int iPanStep;
  int iPanDir;
  int ms1;
  int ms2;
  int ms3;

  boolean dir; // false is CCW, true is CW
  //will compare this to LEFT or RIGHT

  boolean tiltDir;

  double iAngle;//angle of PAN stepper

  double doStep(boolean dir);
  double doSixteenthStep(boolean dir);

  double iTiltAngle;//angle of TILT stepper

  double distToFlame; //distance to Flame, for use later

  double adjustedAngle; //angle to set stepper to compensate for camera and fan at different height
};

#endif
