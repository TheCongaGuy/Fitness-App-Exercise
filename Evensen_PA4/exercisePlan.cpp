#include "exercisePlan.hpp"

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
ExercisePlan::ExercisePlan()
{
	stepGoal = 0;
	name = "N/A";
	date = "N/A";
}

// Copy Constructor
ExercisePlan::ExercisePlan(ExercisePlan& exPlan)
{
	stepGoal = exPlan.stepGoal;
	name = exPlan.name;
	date = exPlan.date;
}

// Getters
int ExercisePlan::getStepGoal()
{ return stepGoal; }

string ExercisePlan::getName()
{ return name; }

string ExercisePlan::getDate()
{ return date; }

ostream& operator<< (ostream& lhs, ExercisePlan& rhs)
{
	lhs << rhs.getName() << std::endl << rhs.getStepGoal() << std::endl << rhs.getDate() << std::endl;

	return lhs;
}