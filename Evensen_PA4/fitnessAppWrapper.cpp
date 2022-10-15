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

	// Open files
	dFile.open("DietPlans.txt");
	eFile.open("ExercisePlans.txt");

	// Load plans
	loadWeeklyPlan(dFile, diPlan);
	loadWeeklyPlan(eFile, exPlan);

	// Close files
	dFile.close();
	eFile.close();
}

// Object Destructor
FitnessAppWrapper::~FitnessAppWrapper()
{
	// Open files
	dFile.open("DietPlans.txt");
	eFile.open("ExercisePlans.txt");

	// Save plans
	storeWeeklyPlan(diPlan);
	storeWeeklyPlan(exPlan);

	// Close files
	dFile.close();
	eFile.close();
}

// Run the main application
void FitnessAppWrapper::runApp()
{
	// Catches user's choice
	int choice = 0;

	// Run member methods while the user has not quit
	while (choice != 9)
	{
		system("cls");
		switch (displayMenu(choice))
		{
			// Load Diet Plans
			case 1:
				system("cls");
				std::cout << "Loading Plans. . ." << std::endl;

				dFile.open("DietPlans.txt");
				loadWeeklyPlan(dFile, diPlan);
				dFile.close();
				
				std::cout << "Loaded" << std::endl;
				system("pause");
				break;

			// Load Exercise Plans
			case 2:
				system("cls");
				std::cout << "Loading Plans. . ." << std::endl;
				
				eFile.open("ExercisePlans.txt");
				loadWeeklyPlan(eFile, exPlan);
				eFile.close();

				std::cout << "Loaded" << std::endl;
				system("pause");
				break;

			// Save Diet Plans
			case 3:
				system("cls");
				std::cout << "Saving Plans. . ." << std::endl;

				dFile.open("DietPlans.txt");
				storeWeeklyPlan(diPlan);
				dFile.close();

				std::cout << "Saved" << std::endl;
				system("pause");
				break;

			// Save Exercise Plans
			case 4:
				system("cls");
				std::cout << "Saving Plans. . ." << std::endl;

				eFile.open("ExercisePlans.txt");
				storeWeeklyPlan(exPlan);
				eFile.close();

				std::cout << "Saved" << std::endl;
				system("pause");
				break;

			// Print Diet Plans
			case 5:
				system("cls");
				std::cout << "Diet Plan for the Week" << std::endl;
				displayWeeklyPlan(diPlan);
				system("pause");
				break;

			// Print Exercise Plans
			case 6:
				system("cls");
				std::cout << "Exercise Plan for the Week" << std::endl;
				displayWeeklyPlan(exPlan);
				system("pause");
				break;

			// Edit Diet Plan
			case 7:
				system("cls");
				editPlan(diPlan);
				break;

			// Edit Exercise Plan
			case 8:
				system("cls");
				editPlan(exPlan);
				break;
		}
	}
}

// Displays nine menu options to choose from
// Takes a integer variable to save the user's choice to
// Returns a copy of the user's choice
int FitnessAppWrapper::displayMenu(int& choice)
{
	std::cout << "Please select an option:" << std::endl
		<< "1) Load weekly diet plan" << std::endl
		<< "2) Load weekly exercise plan" << std::endl
		<< "3) Save weekly diet plan" << std::endl
		<< "4) Save weekly exercise plan" << std::endl
		<< "5) Display weekly diet plan" << std::endl
		<< "6) Display weekly exercise plan" << std::endl
		<< "7) Edit diet plan" << std::endl
		<< "8) Edit exercise plan" << std::endl
		<< "9) Quit App" << std::endl;

	getInt(choice);

	return choice;
}

// Reads one record from the given stream
// Takes an open file stream and a reference to a plan
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, DietPlan& plan)
{ fileStream >> plan; }
void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, ExercisePlan& plan)
{ fileStream >> plan; }

// Reads in all seven daily plans from the given stream
// Takes an open file stream and an array of data plans
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, DietPlan weeklyPlan[])
{
		for (int i = 0; i < 7; i++)
			loadDailyPlan(fileStream, diPlan[i]);
}
void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, ExercisePlan weeklyPlan[])
{
		for (int i = 0; i < 7; i++)
			loadDailyPlan(fileStream, exPlan[i]);
}

// Writes a daily plan to the screen
// Takes a plan
void FitnessAppWrapper::displayDailyPlan(DietPlan& plan)
{ std::cout << plan << std::endl; }
void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan)
{ std::cout << plan << std::endl; }

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

// Writes a daily plan to a file
// Tase a plan
void FitnessAppWrapper::storeDailyPlan(DietPlan& plan)
{ dFile << plan << std::endl; }
void FitnessAppWrapper::storeDailyPlan(ExercisePlan& plan)
{ eFile << plan << std::endl; }

// Writes a weekly plan to a file
// Takes an array of plans
void FitnessAppWrapper::storeWeeklyPlan(DietPlan* plans)
{
	for (int i = 0; i < 7; i++)
		storeDailyPlan(plans[i]);
}
void FitnessAppWrapper::storeWeeklyPlan(ExercisePlan* plans)
{
	for (int i = 0; i < 7; i++)
		storeDailyPlan(plans[i]);
}

// Find a plan from an array by date
// Takes an array of plans and the desired date
// Returns a pointer to the corresponding plan < NULL if none were found >
DietPlan* FitnessAppWrapper::find(DietPlan* plans, string date)
{
	for (int i = 0; i < 7; i++)
		if (plans[i].getDate() == date)
			return &plans[i];

	return NULL;
}
ExercisePlan* FitnessAppWrapper::find(ExercisePlan* plans, string date)
{
	for (int i = 0; i < 7; i++)
		if (plans[i].getDate() == date)
			return &plans[i];

	return NULL;
}

// Edit a plan entry
// Takes an array of plans
// Returns true if value was changed
bool FitnessAppWrapper::editPlan(DietPlan* plans)
{
	// Catches data from the user
	char Date[15], Name[100];
	int newGoal;

	// Display current plans
	displayWeeklyPlan(plans);

	// Get the requested plan
	std::cout << "Which date would you like to modify?: ";
	std::cin.ignore(INT_MAX, '\n'); // Skip the already written line above
	std::cin.getline(Date, INT_MAX, '\n');
	DietPlan* reqPlan = find(diPlan, (string)Date);

	// Get new values from the user
	if (reqPlan != NULL)
	{
		system("cls");
		std::cout << "Title: ";
		std::cin.getline(Name, INT_MAX, '\n');

		std::cout << std::endl << "Goal: ";
		getInt(newGoal);

		std::cout << std::endl << "Date: ";
		std::cin.ignore(INT_MAX, '\n'); // Skip the already written line above
		std::cin.getline(Date, INT_MAX, '\n');

		// Convert values
		string newName = (string)Name, newDate = (string)Date;

		// Set the new values
		if (!reqPlan->setCalorieGoal(newGoal))
		{
			reqPlan->setName(newName);
			reqPlan->setDate(newDate);
			return true;
		}
	}
	
	// Do not set values if no plan exists
	return false;
}
bool FitnessAppWrapper::editPlan(ExercisePlan* plans)
{
	// Catches data from the user
	char Date[15], Name[100];
	int newGoal;

	// Display current plans
	displayWeeklyPlan(plans);

	// Get the requested plan
	std::cout << "Which date would you like to modify?: ";
	std::cin.ignore(INT_MAX, '\n'); // Skip the already written line above
	std::cin.getline(Date, INT_MAX, '\n');
	ExercisePlan* reqPlan = find(exPlan, (string)Date);

	// Get new values from the user
	if (reqPlan != NULL)
	{
		std::cout << std::endl << "Title: ";
		std::cin.getline(Name, INT_MAX, '\n');

		std::cout << std::endl << "Goal: ";
		getInt(newGoal);

		std::cout << std::endl << "Date: ";
		std::cin.ignore(INT_MAX, '\n'); // Skip the already written line above
		std::cin.getline(Date, INT_MAX, '\n');

		// Convert values
		string newName = (string)Name, newDate = (string)Date;

		// Set the new values
		if (reqPlan->setStepGoal(newGoal))
		{
			reqPlan->setName(newName);
			reqPlan->setDate(newDate);
			return true;
		}
	}

	// Do not set values if no plan exists
	return false;
}

// Input Validation
void getInt(int& var)
{
	std::cin >> var;

	// Clear invalid input
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
}