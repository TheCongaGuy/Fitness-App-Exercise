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

// Class to represent an exercise plan
class ExercisePlan {
public:
	// Default Constructor
	ExercisePlan();

	// Copy Constructor
	ExercisePlan(ExercisePlan& exPlan);

	// Object Destructor

	~ExercisePlan() {};

	// Getters
	int getStepGoal();
	string getName();
	string getDate();

	// Setters < Returns true if value was changed >
	bool setStepGoal(int& goal);
	void setName(string& name);
	void setDate(string& date);

	// Sets new values for data members inside the class
	// Takes a new goal, name, and date
	// Returns true if values changed, false otherwise
	bool editGoal(int& goal, string& name, string& date);
	
private:
	// Data Members
	int stepGoal;
	string name;
	string date;
};

// Stream insertion overload
ostream& operator<< (ostream& lhs, ExercisePlan& rhs);

// Stream extraction overload
istream& operator>> (istream& lhs, ExercisePlan& rhs);