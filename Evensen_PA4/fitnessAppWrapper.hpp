#pragma once

/*******************************************************************************
 * Programmer: Drew Evensen		                                               *
 * Class: CptS 122; Lab Section 7                                              *
 * Programming Assignment: 4	                                               *
 * Date: 9/29/22                                                               *
 *                                                                             *
 * Description: Simulates a Fitness App where the user may load, store,		   *
 *				display, and edit daily and weekly fitness plans.			   *
 ******************************************************************************/

#include "dietPlan.hpp"
#include "exercisePlan.hpp"
#include <fstream>

using std::fstream;

// Class to act as the fitness app
class FitnessAppWrapper {
public:
	// Default Constructor
	FitnessAppWrapper();

	// Writes a weekly plan to the screen
	// Takes an array of plans
	void displayWeeklyPlan(DietPlan* plans);
	void displayWeeklyPlan(ExercisePlan* plans);

	// Getters
	DietPlan* getDietPlan();
	ExercisePlan* getExercisePlan();
private:
	// Data Members
	DietPlan diPlan[7];
	ExercisePlan exPlan[7];

	// File Stream
	fstream file;

	// Writes a daily plan to the screen
	// Takes a plan
	void displayDailyPlan(DietPlan& plan);
	void displayDailyPlan(ExercisePlan& plan);
};