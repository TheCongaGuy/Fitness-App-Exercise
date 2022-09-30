#include "fitnessAppWrapper.hpp"

/*******************************************************************************
 * Programmer: Drew Evensen		                                               *
 * Class: CptS 122; Lab Section 7                                              *
 * Programming Assignment: 4	                                               *
 * Date: 9/29/22                                                               *
 *                                                                             *
 * Description: Simulates a Fitness App where the user may load, store,		   *
 *				display, and edit daily and weekly fitness plans.			   *
 ******************************************************************************/

// Default Constructor
FitnessAppWrapper::FitnessAppWrapper()
{
	// Open the fitness app memory file
	file.open("FitnessAppPlans.txt");
}

// Writes a daily plan to the screen
// Takes a plan
void FitnessAppWrapper::displayDailyPlan(DietPlan& plan)
{
	std::cout << plan << std::endl;
}
void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan)
{
	std::cout << plan << std::endl;
}

// Writes a weekly plan to the screen
// Takes an array of plans
void FitnessAppWrapper::displayWeeklyPlan(DietPlan* plans)
{
	for (int i = 0; i < 7; i++)
		displayDailyPlan(plans[i]);
}
void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan* plans)
{
	for (int i = 0; i < 7; i++)
		displayDailyPlan(plans[i]);
}

// Getters
DietPlan* FitnessAppWrapper::getDietPlan()
{ return diPlan; }

ExercisePlan* FitnessAppWrapper::getExercisePlan()
{ return exPlan; }