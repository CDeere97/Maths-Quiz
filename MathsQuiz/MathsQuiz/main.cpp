#include <iostream>
#include <conio.h>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	const int MAX_NUMS = 10;
	const int MAX_OPS = 4;

	char operations[MAX_OPS] = { '+','-','*','/' };
	float nums[MAX_NUMS] = { 0,1,2,3,4,5,6,7,8,9 }; // using float to prevent errors

	bool quit = false; // player quit
	bool gameOver = false; // game over or not

	int score = 0; // player score

	cout << "Welcome to the Maths Quiz! Answer as many questions right as you can." << endl;
	cout << "You score one point for each correct answer." << endl;
	cout << "The game when you get a question wrong." << endl;
	cout << "type 'quit' to end the game." << endl << endl;

	while (!quit && !gameOver)
	{
		// pick random numbers within the bounds of the array
		srand(static_cast<unsigned int>(time(0)));
		int numChoice1 = (rand() % MAX_NUMS);
		int numChoice2 = (rand() % MAX_NUMS);
		int opChoice = (rand() % MAX_OPS);

		// prevent division by zero by selecting num2 again until it is not 0 
		if (opChoice == 3)
		{
			while (numChoice2 == 0)
			{
				numChoice2 = (rand() % MAX_NUMS);
			}
		}

		// choose numbers and operation
		float num1 = nums[numChoice1];
		float num2 = nums[numChoice2];
		char operation = operations[opChoice];

		cout << "What is " << num1 << " " << operation << " " << num2 << " ?" << endl;
		string guess; // guess is string as player can enter quit
		cin >> guess;
		
		if (guess == "quit")
		{
			// quit game
			quit = true;
		}
		else
		{
			// convert back to float if 'quit' hasn't been entered
			float floatGuess = 0;
			try
			{
				floatGuess = stof(guess); 
			}
			catch (const std::exception&) // exception handler incase user does not enter a number
			{
				
			}
			
			float answer = 0; // answer to question

			if (operation == '+')
			{
				answer = num1 + num2;
			}
			else if (operation == '-')
			{
				answer = num1 - num2;
			}
			else if (operation == '*')
			{
				answer = num1 * num2;
			}
			else
			{
				answer = num1 / num2;
			}

			if (floatGuess == answer)
			{
				cout << "Correct! It is " << answer << endl << endl;
				score += 1;
			}
			else
			{
				cout << "Incorrect. The answer is " << answer << endl;
				gameOver = true;
			}
		}
	}

	cout << endl << "You scored " << score << " points"; // display score
	_getch();

	return 0;
}