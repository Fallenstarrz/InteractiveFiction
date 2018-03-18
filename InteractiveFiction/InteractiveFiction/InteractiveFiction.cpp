// InteractiveFiction.cpp : Defines the entry point for the console application.
//

//Header files
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
//Namespace
using namespace std;
//Functions: These tell the program there are functions with their corrisponding name later in the program. Everything in parenthesis is what we want the program to call the variables they're being handed.
string GetTextFromUser(string prompt);
int GetNumbersFromUser(string prompt); 
void OutputStory(string name, string food, string weapon, string limb, int luckyNumber, int randomNumber);
bool CheckVictory(int luckyNumber, int randomNumber);
//main function
void main()
{
	srand(static_cast<unsigned int>(time(0))); // seeds random number generator
	int randomNumber = rand() % 100+1; // stores a random number between 1 and 100 into randomNumber variable
	string name = GetTextFromUser("Enter the name of your character! \n"); // stores the return of GetTextFromUser into a variable
	string food = GetTextFromUser("What is their favorite food? \n"); // stores the return of GetTextFromUser into a variable
	string weapon = GetTextFromUser("What is their weapon of choice? \n"); // Stores the return of GetTextFromUser into a variable
	string limb = GetTextFromUser("What is their favorite body part? \n"); // Stores the return of GetTextFromUser into a variable
	int luckyNumber = GetNumbersFromUser("What is their lucky number? \n"); // Stores the return of GetNumbersFromUser into a variable
	OutputStory(name, food, weapon, limb, luckyNumber, randomNumber); // Calls the OutputStory function and sends all your variables into it as parameters
	system("pause"); // pause system when program finishes all tasks
}

string GetTextFromUser(string prompt) // This is the body of the GetTextFromUser function, it takes a string as its parameter, and calls it prompt
{
	string text; // this is a new variable used to store the user input
	cout << prompt; // output prompt
	cin >> text; // get input from user to store in text variable
	return text; // Return the variable, this can only be a string, because function is of type string
}

int GetNumbersFromUser(string prompt) // This is the body of the GetNumbersFromUser function, it takes a string as its parameter, and calls it prompt
{
	int num;
	cout << prompt;
	cin >> num;
	return num; // Return the variable, this can only be an int, because function is of type int
}
void OutputStory(string name, string food, string weapon, string limb, int luckyNumber, int randomNumber) // This is the body of OutputStory, it takes all the main function variables as parameters
{
	// Output story
	cout << "As you walk down the stone corridore you approach a giant steel gate forged 2 feet thick. You hear the roar of the crowd chanting your name... ";
	cout << name << "! " << name << "! " << name << "! ";
	cout << "Nervously you vomit the " << food << " you enjoyed earlier that morning. ";
	cout << "You step forward from the gate into the bright light of the sun to find yourself standing at one end of a massive colosseum. ";
	cout << "You reach down to wash your hands in the bloodstained sand, and draw your "<< weapon<<" to prepare for combat. ";
	cout << "At the other end of the arena you spot your opponent. He stands 2 meters tall, and must weigh nearly 16 stones. ";
	cout << "You decide to make the first move and charge at him, but he quickly tosses you to the side. \n";

	if 	(CheckVictory(luckyNumber, randomNumber) == true) // This is the call for check victory if the return is true do the below
	{
		//Story below
		cout << "You quickly bounce back to your feet no more than a meter from your opponent. Taking the opportunity while be beacons the crowd for cheers, you lunge at him with your " << weapon;
		cout << " and with a mighty blow you remove his " << limb << ". While he is screaming in agony you approach him and point your "<< weapon << "at his throat. ";
		cout << "He begs for his life, but the the crowds cheers are so loud that you decide to remove his head to show to your loyal fans. \n Victory is yours! Congradulations!\n";
	}
	else // if the checkvictory return was anything but true do the below
	{
		//Story below
		cout << "Unable to react quick enough your opponent takes advantage of the fact that you are down, and swings his giant blade in a massive arch removing your "<< limb;
		cout << " The crowd changes tune in a hurry and chant, Kill, Kill, Kill over and over. You look to your opponent astounded at his strength, as he thrusts his blade through your chest!\n";
		cout << "You've lost your life. Better luck next time!\n";
	}
}

bool CheckVictory(int luckyNumber, int randomNumber) // This function checks if the player won by comparing a random number to the players lucky number chosen in main()
{
	if (luckyNumber >= randomNumber) // This is the same luckyNumber and randomNumber from main!
	{
		return true;
	}
	else
	{
		return false;
	}
}

// So a few things to remember with functions:
// A function must always return something of its own type, unless it is void, in which it won't return anything.
// Function names must be unique, unless overloading, in which case the type changes
// When a function is made it is given a number of parameters, these can be anything, the body holds the actions the function needs to perform, the declaration just prevents the program from throwing errors
// When a function is called it is given variables to use as those parameters.
// For example: 
// void Something (int This, float Can, string Be, char Anything);
// void main()
// {
//    int i = 1
//    float am = 1.1
//    string sending = "Hello"
//    char stuff = 'A'
//    Something(i, am, sending, stuff)
// }
// void Something (int This, float Can, string Be, char Anything)
// {
//    cout << This << Can << Be << Anything;
// }
// This above function is given i, am, sending, stuff
// The function assigns the outcome of i to This, am to can, etc...
// So the outcome is the same as if I were going to print those variables directly
// Output:: 11.1HelloA