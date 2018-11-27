#pragma config(Sensor, in6,    potentiometer,  sensorPotentiometer)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl6,  frontTouch,     sensorTouch)
#pragma config(Sensor, dgtl8,  sonarCM,        sensorSONAR_cm)
#pragma config(Motor,  port2,           Right,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           Left,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LiftL,         tmotorNone, openLoop)
#pragma config(Motor,  port9,           LiftR,         tmotorNone, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	motor[Right]=127;
	motor[Left]=127;
	// go forward

	motor[Claw]=-127;

	wait10Msec (5);

	motor[Right]=0;
	motor[Left]=0;
	motor[Claw]=0;
	// intake drops

	wait10Msec (5);
	//wait one twentieth of a second or 0.05 or 50 ms

	motor[Right]=0;
	motor[Left]=0;
	motor[Claw]=0;
	// all motors stop

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	while (true)
  {
  	int ClawUp = vexRT(Btn6U);
 		int ClawDown = vexRT(Btn6D);
 		int LiftUp = vexRT(Btn5U);
 		int LiftDown = vexRT(Btn5D);
 		int leftstickX;
 		int leftstickY;
 		int deadzone = 5;

 //////////////////Arcade Drive/////////////////////////////
	if (abs(vexRT[Ch4]) > deadzone)
 		{leftstickY = vexRT[Ch4];}

	else
		{leftstickY = 0;}

	if (abs(vexRT[Ch3]) > deadzone)
		{leftstickX = vexRT[Ch3];}

	else
		{leftstickX =0 ;}

	motor[Left]  = leftstickY + leftstickX;
	motor[Right] = leftstickY - leftstickX;
 //////////////////Arcade Drive/////////////////////////////

//////////////////Lift///////////////////////////////

if (LiftUp == 1)
		{
			motor[LiftR] = 127;
			motor[LiftL] = 127;
		}

	else if (LiftDown == 1)
		{
			motor[LiftR] = -127;
			motor[LiftL] = -127;
		}
	else
		{
			motor[LiftR] = 0;
			motor[LiftL] = 0;
		}
///////////////////Lift//////////////////////////////

//////////////////Claw////////////////////////////////
	if (ClawUp == 1 )
		{
			motor [Claw] = 127;
			motor [Claw] = 127;
		}

	else if (ClawDown == 1)
		{
			motor [Claw] = -127;
			motor [Claw] = -127;
		}

	else
		{
			motor [Claw] = 0;
			motor [Claw] = 0;
//////////////////Claw////////////////////////////////
		}
  }
}
