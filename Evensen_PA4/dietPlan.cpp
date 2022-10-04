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

// Setters < Returns true if value was changed >
bool DietPlan::setCalorieGoal(int& goal)
{
	// Do not change the value if it is non-positive
	if (goal < 0)
		return false;

	calorieGoal = goal;
	return true;
}
void DietPlan::setName(string& newName)
{ name = newName; }
void DietPlan::setDate(string& newDate)
{ date = newDate; }

// Stream insertion overload
ostream& operator<< (ostream& lhs, DietPlan& rhs)
{
	lhs << rhs.getName() << std::endl << rhs.getCalorieGoal() << std::endl << rhs.getDate() << std::endl;

	return lhs;
}

// Stream extraction overload
istream& operator>> (istream& lhs, DietPlan& rhs)
{
	// Data extractors
	char name[100], calGoal[100], date[15]; // getline works with c_strings

	// Extract lines individually
	lhs.getline(name, INT_MAX);
	lhs.getline(calGoal, INT_MAX);
	lhs.getline(date, INT_MAX);

	// Skip the empty line
	lhs.ignore(INT_MAX, '\n');

	// Convert values
	string newName = (string)name, newDate = (string)date;
	int newGoal = atoi(calGoal);

	// Insert data into the exercise plan
	rhs.setName(newName);
	rhs.setDate(newDate);
	rhs.setCalorieGoal(newGoal);

	return lhs;
}