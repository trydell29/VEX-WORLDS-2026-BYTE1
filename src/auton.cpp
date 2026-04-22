#include "main.h"
#include "intake.h"

lemlib::Pose rightStartPose(-46.345, -14.4625, 90);
lemlib::Pose leftStartPose(-46.345, 14.4625, 90);
lemlib::Pose rightLongGoalPose(-24.395, -47.5, 90);
lemlib::Pose leftLongGoalPose(-24.395, 47.125, 90);
lemlib::Pose midGoalPose(-7.990, 7.990, 45);
lemlib::Pose lowGoalPose(-7.990, -7.990, -45);
lemlib::Pose prepRightLoaderPose(-46.345, -50, 180);
lemlib::Pose finalRightLoaderPose(-56.5, -50, 270);
lemlib::Pose leftLoaderPose(-65.559, 46.765, 270);

void rightAuton(){
    chassis.setPose(rightStartPose);
    liftState.store(true);
    loaderState.store(false);
    chassis.moveToPose(prepRightLoaderPose.x, prepRightLoaderPose.y, prepRightLoaderPose.theta, 3000);
    chassis.waitUntilDone();
    chassis.moveToPose(finalRightLoaderPose.x, finalRightLoaderPose.y, finalRightLoaderPose.theta, 3000);
    chassis.waitUntilDone();
    intakeRunning.store(true); outtakeRunning.store(false); intakeSpitRunning.store(false);
    pros::delay(5000);
    intakeRunning.store(false); outtakeRunning.store(false); intakeSpitRunning.store(false);
    loaderState.store(true);
    chassis.moveToPose(rightLongGoalPose.x, rightLongGoalPose.y, rightLongGoalPose.theta, 3000);
    chassis.waitUntilDone();
    doorState.store(true);
    outtakeRunning.store(true); intakeRunning.store(false); intakeSpitRunning.store(false);
    pros::delay(5000);
    doorState.store(false);
    /*outtakeRunning.store(false); intakeRunning.store(false); intakeSpitRunning.store(false);
    chassis.moveToPose(rightLoaderPose.x, rightLoaderPose.y, rightLoaderPose.theta, 5000);
    chassis.waitUntilDone();
    intakeRunning.store(true); outtakeRunning.store(false); intakeSpitRunning.store(false);
    pros::delay(5000);
    intakeRunning.store(false); outtakeRunning.store(false); intakeSpitRunning.store(false);
    chassis.moveToPose(rightLongGoalPose.x, rightLongGoalPose.y, rightLongGoalPose.theta, 5000);
    chassis.waitUntilDone();
    outtakeRunning.store(true); intakeRunning.store(false); intakeSpitRunning.store(false);
    pros::delay(5000);
    outtakeRunning.store(false); intakeRunning.store(false); intakeSpitRunning.store(false);*/
}

void leftAuton();
