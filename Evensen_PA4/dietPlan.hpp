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

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

// Class to represent a diet plan
class DietPlan {
public: 
	// Default Constructor
	DietPlan();

	// Copy Constructor
	DietPlan(DietPlan& diPlan);

	// Getters
	int getCalorieGoal();
	string getName();
	string getDate();

	// Setters < Returns true if value was changed >
	bool setCalorieGoal(int& goal);
	void setName(string& name);
	void setDate(string& date);
private:
	// Data Members
	int calorieGoal;
	string name;
	string date;
};

// Stream insertion overload
ostream& operator<< (ostream& lhs, DietPlan& rhs);

// Stream extraction overload
istream& operator>> (istream& lhs, DietPlan& rhs);