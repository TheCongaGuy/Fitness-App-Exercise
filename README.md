# Fitness App Exercise

This program was an exercise in working with classes, and overloaded operators. It's nice moving back to C++ after teaching myself C for the past month, though learning C gave me a lot of insight on how C++ operates, and the similarities between them. It also really helped my understanding of C++ and my appreciation of the glorious `std::string` data type!

## Layout

This program is made of three different classes; a `DietPlan` class, an `ExercisePlan` class, and a `FitnessAppWrapper` class. While the first two classes deal with the data and data operations, the wrapper (as the name implies) wraps both of those classes together into one neat package that you can run through the `.runApp()` member method. The two data classes house the overloaded `operator<<` and `operator>>` methods for data extraction which the wrapper class utilizes to save and load the fitness plans to and from a text file.
```
        main()
          |
          v
  FitnessAppWrapper()  ----------------------------
  |               |                               ^
  v               v                             /   \
DietPlan()   ExercisePlan()         DietPlans.txt    ExercisePlans.txt
```

## DataPlan Classes

For the `DietPlan()` and `ExercisePlan()` classes inheritance could have been used but for the purposes of this exercise, inheritance was off the table. Each of these classes holds very similar data and member methods. They hold a `std::string name`, `std::string date`, and `int goal` as their data members, and each have respective constructors, copy constructors, destructors, getters, setters, and overloaded operators.
