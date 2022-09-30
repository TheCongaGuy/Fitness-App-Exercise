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

// Class to represent an exercise plan
class ExercisePlan {
public:
	// Default Constructor
	ExercisePlan();

	// Copy Constructor
	ExercisePlan(ExercisePlan& exPlan);

	// Getters
	int getStepGoal();
	string getName();
	string getDate();
private:
	// Data Members
	int stepGoal;
	string name;
	string date;
};

// Stream insertion overload
ostream& operator<< (ostream& lhs, ExercisePlan& rhs);