#include "dietPlan.hpp"

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
DietPlan::DietPlan()
{
	calorieGoal = 0;
	name = "N/A";
	date = "N/A";
}

// Copy Constructor
DietPlan::DietPlan(DietPlan& diPlan)
{
	calorieGoal = diPlan.calorieGoal;
	name = diPlan.name;
	date = diPlan.date;
}

// Getters
int DietPlan::getCalorieGoal()
{ return calorieGoal; }

string DietPlan::getName()
{ return name; }

string DietPlan::getDate()
{ return date; }

// Stream insertion overload
ostream& operator<< (ostream& lhs, DietPlan& rhs)
{
	lhs << rhs.getName() << std::endl << rhs.getCalorieGoal() << std::endl << rhs.getDate() << std::endl;

	return lhs;
}