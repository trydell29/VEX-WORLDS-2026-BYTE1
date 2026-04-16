#include "main.h"
#include "intake.h"

lemlib::Pose rightStartPose(-46.345, -14.4625, 90);
lemlib::Pose leftStartPose(-46.345, 14.4625, 90);
lemlib::Pose rightLongGoalPose(-24.395, -47.125, 90);
lemlib::Pose leftLongGoalPose(-24.395, 47.125, 90);
lemlib::Pose midGoalPose(-7.990, 7.990, 45);
lemlib::Pose lowGoalPose(-7.990, -7.990, -45);
lemlib::Pose rightLoaderPose(-65.559, -46.765, 270);
lemlib::Pose leftLoaderPose(-65.559, 46.765, 270);

void rightAuton(){
    chassis.setPose(rightStartPose);
    chassis.moveToPose(rightLoaderPose.x, rightLoaderPose.y, rightLoaderPose.theta, 5000);
    chassis.waitUntilDone();
    chassis.moveToPose(rightLongGoalPose.x, rightLongGoalPose.y, rightLongGoalPose.theta, 5000);
    chassis.waitUntilDone();
    runOuttake();
    pros::delay(5000);
    stopIndexer();
    chassis.moveToPose(rightLoaderPose.x, rightLoaderPose.y, rightLoaderPose.theta, 5000);
    chassis.waitUntilDone();
    runIntake();
    pros::delay(5000);
    stopIndexer();
    chassis.moveToPose(rightLongGoalPose.x, rightLongGoalPose.y, rightLongGoalPose.theta, 5000);
    chassis.waitUntilDone();
    runOuttake();
    pros::delay(5000);
    stopIndexer();
}

void leftAuton();
