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

int main(int argc, char argv[])
{
	FitnessAppWrapper app;

	app.displayWeeklyPlan(app.getDietPlan());
	app.displayWeeklyPlan(app.getExercisePlan());
}