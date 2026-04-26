#include "main.h"
#include "intake.h"

lemlib::Pose rightStartPose(-46.345, -14.4625, 90);
lemlib::Pose leftStartPose(-46.345, 14.4625, 90);

lemlib::Pose rightLongGoalPose(-24, -50, 90);
lemlib::Pose rightLoaderPose(-55, -49, 270);
lemlib::Pose rightSpitPose(-40, -49, 135);

lemlib::Pose leftLongGoalPose(-24.395, 50, 90);
lemlib::Pose leftLoaderPose(-55, 49, 270);
lemlib::Pose leftSpitPose(-40, 49, 135);

//lemlib::Pose midGoalPose(-7.990, 7.990, 45);
//lemlib::Pose lowGoalPose(-7.990, -7.990, -45);
//lemlib::Pose prepRightLoaderPose(-46.345, -50, 180);



void rightAuton(){
    chassis.setPose(rightStartPose);
    liftState.store(true);
    loaderState.store(true);
    chassis.turnToHeading(180, 2000);
    chassis.waitUntilDone();
    chassis.moveToPoint(rightStartPose.x, rightLoaderPose.y, 3000);
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(rightLoaderPose.x, rightLoaderPose.y, rightLoaderPose.theta, 2000);
    chassis.waitUntilDone();
    loaderState.store(false);
    intakeRunning.store(true); outtakeRunning.store(false); intakeSpitRunning.store(false);
    pros::delay(2500);
    intakeRunning.store(false); outtakeRunning.store(false); intakeSpitRunning.store(false);
    loaderState.store(true);
    chassis.moveToPoint(-40, -49, 2000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(135, 1000);
    chassis.waitUntilDone();
    intakeSpitRunning.store(true); intakeRunning.store(false); outtakeRunning.store(false);
    pros::delay(800);
    intakeSpitRunning.store(false);
    chassis.moveToPose(rightLongGoalPose.x, rightLongGoalPose.y, rightLongGoalPose.theta, 2000);
    chassis.waitUntilDone();
    doorState.store(true);
    outtakeRunning.store(true); intakeRunning.store(false); intakeSpitRunning.store(false);
    pros::delay(2000);
    outtakeRunning.store(false); intakeRunning.store(false); intakeSpitRunning.store(false);
    doorState.store(false);
    chassis.moveToPoint(-40, -49, 2000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 1000);
    chassis.waitUntilDone();
    chassis.moveToPose(rightLoaderPose.x, rightLoaderPose.y, rightLoaderPose.theta, 2000);
    chassis.waitUntilDone();
    loaderState.store(false);
    intakeRunning.store(true); outtakeRunning.store(false); intakeSpitRunning.store(false);
    pros::delay(2500);
    intakeRunning.store(false); outtakeRunning.store(false); intakeSpitRunning.store(false);
    loaderState.store(true);
    chassis.moveToPoint(-40, -49, 2000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.moveToPose(rightLongGoalPose.x, rightLongGoalPose.y, rightLongGoalPose.theta, 2000);
    chassis.waitUntilDone();
    doorState.store(true);
    outtakeRunning.store(true); intakeRunning.store(false); intakeSpitRunning.store(false);
    pros::delay(2500);
    outtakeRunning.store(false); intakeRunning.store(false); intakeSpitRunning.store(false);
    doorState.store(false);
}

void leftAuton(){
    chassis.setPose(leftStartPose);
    liftState.store(true);
    loaderState.store(true);
    chassis.turnToHeading(0, 2000);
    chassis.waitUntilDone();
    chassis.moveToPoint(leftStartPose.x, leftLoaderPose.y, 3000);
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(leftLoaderPose.x, leftLoaderPose.y, leftLoaderPose.theta, 2000);
    chassis.waitUntilDone();
    loaderState.store(false);
    intakeRunning.store(true); outtakeRunning.store(false); intakeSpitRunning.store(false);
    pros::delay(2500);
    intakeRunning.store(false); outtakeRunning.store(false); intakeSpitRunning.store(false);
    loaderState.store(true);
    chassis.moveToPoint(-40, 49, 2000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(45, 1000);
    chassis.waitUntilDone();
    intakeSpitRunning.store(true); intakeRunning.store(false); outtakeRunning.store(false);
    pros::delay(800);
    intakeSpitRunning.store(false);
    chassis.moveToPose(leftLongGoalPose.x, leftLongGoalPose.y, leftLongGoalPose.theta, 2000);
    chassis.waitUntilDone();
    doorState.store(true);
    outtakeRunning.store(true); intakeRunning.store(false); intakeSpitRunning.store(false);
    pros::delay(2000);
    outtakeRunning.store(false); intakeRunning.store(false); intakeSpitRunning.store(false);
    doorState.store(false);
    chassis.moveToPoint(-40, 49, 2000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 1000);
    chassis.waitUntilDone();
    chassis.moveToPose(leftLoaderPose.x, leftLoaderPose.y, leftLoaderPose.theta, 2000);
    chassis.waitUntilDone();
    loaderState.store(false);
    intakeRunning.store(true); outtakeRunning.store(false); intakeSpitRunning.store(false);
    pros::delay(2500);
    intakeRunning.store(false); outtakeRunning.store(false); intakeSpitRunning.store(false);
    loaderState.store(true);
    chassis.moveToPoint(-40, 49, 2000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.moveToPose(leftLongGoalPose.x, leftLongGoalPose.y, leftLongGoalPose.theta, 2000);
    chassis.waitUntilDone();
    doorState.store(true);
    outtakeRunning.store(true); intakeRunning.store(false); intakeSpitRunning.store(false);
    pros::delay(2500);
    outtakeRunning.store(false); intakeRunning.store(false); intakeSpitRunning.store(false);
    doorState.store(false);
}
