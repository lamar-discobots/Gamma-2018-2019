#pragma config(Motor,  port2,           Left1,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           Left2,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           Right1,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Right2,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           LiftL,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           LiftR,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           ClawL,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           ClawR,         tmotorVex393_MC29, openLoop)
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
	motor[Right1]= 127;
	motor[Right2]= 127;
	motor[Left1]= 127;
	motor[Left2]= 127;
	// go forward

	wait1Msec (1500);
	//wait 1.5 seconds

	motor[Right1]= 0;
	motor[Right2]= 0;
	motor[Left1]= 0;
	motor[Left2]= 0;
	//all motors stop

	motor[LiftL]= 127;
	motor[LiftR]= 127;
	//lift rise

	wait1Msec (750);
	//wait .75 seconds

	motor[LiftL]= 0;
	motor[LiftR]= 0;
	//lift stop

	motor[ClawL]= 127;
	motor[ClawR]= 127;
	//claw comes out

	wait1Msec (750);
	//wait .75 sec

	motor[ClawL]= 0;
	motor[ClawR]= 0;
	//claw stop

	motor[LiftL]= -127;
	motor[LiftR]= -127;
	//lift rise

	wait1Msec (750);
	//wait .75 seconds

	motor[LiftL]= 0;
	motor[LiftR]= 0;
	//lift stop

	motor[Right1]= 127;
	motor[Right2]= 127;
	motor[Left1]= 127;
	motor[Left2]= 127;
	// go forward

	wait1Msec (500);
	//wait .5 seconds

	motor[Right1]= 0;
	motor[Right2]= 0;
	motor[Left1]= 0;
	motor[Left2]= 0;
	//all motors stop

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
  // User control code here, inside the loop

  while (true)
  {


		int ClawUp					=  vexRT(Btn6U);
		int clawDown       =  vexRT(Btn6D);
		int LiftUp 				=	 vexRT(Btn5U);
		int LiftDown 			=  vexRT(Btn5D);
		int leftstickX;
		int leftstickY;
		int deadzone        =5;

		//////////////////Arcade drive/////////////////
		if (abs(vexRT[Ch4]) > deadzone){
			leftstickY = vexRT[Ch4];
		}
		else {
			leftstickY = 0;
		}

		if (abs(vexRT[Ch3]) > deadzone){
			leftstickX = vexRT[Ch3];
		}
		else {
			leftstickX =0 ;
		}

		motor[Left1] = leftstickY + leftstickX;
		motor[Left2] = leftstickY + leftstickX;

		motor[Right1] = leftstickY - leftstickX;
		motor[Right2] = leftstickY - leftstickX;
		/////////////////Arcade drive///////////////////////
		//////////////////Lift///////////////////////////////
		if (LiftUp == 1) {
			motor[LiftR] = 127;
			motor[LiftL] = 127;
		}
		else if (LiftDown == 1){
			motor[LiftR] = -127;
			motor[LiftL] = -127;
		}
		else{
			motor[LiftR] = 0;
			motor[LiftL] = 0;
		}
		//////////////////Lift//////////////////////////////
		//////////////////Claw////////////////////////////////
		if (ClawUp == 1 ) {
			motor[ClawL] = 127;
			motor[ClawR] = 127;
		}
		else if (clawDown == 1) {
			motor[ClawL] = -127;
			motor[ClawR] = -127;
		}
		else {
			motor[ClawL] = 0;
			motor[ClawR] = 0;

		}
  }
}
