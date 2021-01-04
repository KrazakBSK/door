#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;



void displayPrompt(){
	 cout << "Welcome to Door!" << endl;
	 cout << "Simply choose a number associated with a door." << endl;
         cout << "Survive as long as you can :)." << endl;
	 cout << "Good Luck!" << endl;
}

void displayDoors(){
	cout << "+---+   +---+" << endl;
	cout << "|   |   |   |" << endl;
	cout << "| 1 |   | 2 |" << endl;
	cout << "|   |   |   |" << endl;
	cout << "+---+   +---+" << endl;
}

bool choiceChk(int choice, int live){
	if(choice == live){
		return true;
	}	
	else{
	       	return false;
	}
}

void saveScore(string name, int score){
	ofstream scoresFile;
	scoresFile.open("scores.txt", ios::out | ios::app);
	scoresFile << name << ": " << score << endl;
	scoresFile.close();
}

int main(){

	int choice, live;
  	int score = 0;
	string name;

	displayPrompt();
	displayDoors();

	cout << "Name: ";
	cin >> name;

	srand(time(NULL));

	live = (rand() % 2) + 1;	

	cout << "Enter a number: ";
	cin >> choice;
	
	while(choiceChk(choice, live) == true)
	{
		cout << "You lived!" << endl;
		score++;
		live = (rand() % 2) + 1;
		cout << "Enter a number: ";
		cin >> choice;
	}
	
	cout << "Oof, Final Score: " << score << endl;
	saveScore(name, score);
	return 0;
}
