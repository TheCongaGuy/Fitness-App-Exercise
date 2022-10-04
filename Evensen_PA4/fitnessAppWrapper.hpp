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

	// Object Destructor
	~FitnessAppWrapper();

	// Run the main application
	void runApp();
private:
	// Data Members
	DietPlan diPlan[7];
	ExercisePlan exPlan[7];

	// File Streams
	fstream dFile;
	fstream eFile;

	// -----------< Member Methods >-----------

	// Displays nine menu options to choose from
	// Takes a integer variable to save the user's choice to
	// Returns a copy of the user's choice
	int displayMenu(int& choice);

	// Reads one record from the given stream
	// Takes an open file stream and a reference to a plan
	void loadDailyPlan(fstream& fileStream, DietPlan& plan);
	void loadDailyPlan(fstream& fileStream, ExercisePlan& plan);

	// Reads in all seven daily plans from the given stream
	// Takes an open file stream and an array of data plans
	void loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[]);

	// Writes a daily plan to a file
	// Takes a plan
	void storeDailyPlan(DietPlan& plan);
	void storeDailyPlan(ExercisePlan& plan);

	// Writes a weekly plan to a file
	// Takes an array of plans
	void storeWeeklyPlan(DietPlan* plans);
	void storeWeeklyPlan(ExercisePlan* plans);

	// Writes a daily plan to the screen
	// Takes a plan
	void displayDailyPlan(DietPlan& plan);
	void displayDailyPlan(ExercisePlan& plan);

	// Writes a weekly plan to the screen
	// Takes an array of plans
	void displayWeeklyPlan(DietPlan* plans);
	void displayWeeklyPlan(ExercisePlan* plans);

	// Find a plan from an array by date
	// Takes an array of plans and the desired date
	// Returns a pointer to the corresponding plan < NULL if none were found >
	DietPlan* find(DietPlan* plans, string date);
	ExercisePlan* find(ExercisePlan* plans, string date);

	// Edit a plan entry
	// Takes an array of plans
	// Returns true if value was changed
	bool editPlan(DietPlan* plans);
	bool editPlan(ExercisePlan* plans);
};

// Input Validation
void getInt(int& var);