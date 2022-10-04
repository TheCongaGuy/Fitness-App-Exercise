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

// Setters < Returns true if value was changed >
bool ExercisePlan::setStepGoal(int& goal)
{
	// Do not change the value if it is non-positive
	if (goal < 0)
		return false;

	stepGoal = goal;
	return true;
}
void ExercisePlan::setName(string& newName)
{ name = newName; }
void ExercisePlan::setDate(string& newDate)
{ date = newDate; }

// Stream insertion overload
ostream& operator<< (ostream& lhs, ExercisePlan& rhs)
{
	lhs << rhs.getName() << std::endl << rhs.getStepGoal() << std::endl << rhs.getDate() << std::endl;

	return lhs;
}

// Stream extraction overload
istream& operator>> (istream& lhs, ExercisePlan& rhs)
{
	// Data extractors
	char name[100], stepGoal[100], date[15]; // getline works with c_strings

	// Extract lines individually
	lhs.getline(name, INT_MAX);
	lhs.getline(stepGoal, INT_MAX);
	lhs.getline(date, INT_MAX);

	// Skip the empty line
	lhs.ignore(INT_MAX, '\n');

	// Convert values
	string newName = (string)name, newDate = (string)date;
	int newGoal = atoi(stepGoal);

	// Insert data into the exercise plan
	rhs.setName(newName);
	rhs.setDate(newDate);
	rhs.setStepGoal(newGoal);

	return lhs;
}