//Alyssia Bushue
//3-1-2020
//CS 102-03
//This is a program that allows the two players to play the dice game Fifty.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

//Below are the prototypes for the functions that I made.
int rollDice();

int changeScore(int, int);

void displayDiceRoll(int, int);

void displayScore(int, int);


int main()
{
	srand((unsigned)time(NULL)); //Seeding the random number generator with the current time.

	int winningScore = 50; //Value of the winning score. I went with this route to so the winning value isn't hardcoded into the loops and if statements.

	int die1 = 0, die2 = 0, score = 0, player1Score = 0, player2Score = 0; //Declaring and initializing int variables that will be used in the main function.
	char choice = '\0'; //Declaring and initializing the char variable that will be using for user input in the main function

	printf("Welcome to the game Fifty!\nIn this game you and another player will roll a pair of dice.\n");
	printf("Depending on what is rolled you can win or lose points.\n");
	printf("This program will let you and the other player know points earned and points lost.\n");
	printf("Good luck!\n\n");

	do   //This do while loop determines if the game is over or not.
		{
			do   //This do while loop does input validation for the first player's input.
				{
					printf("Player 1 are you ready to roll? (Enter 'r' to roll, 'f' to forfeit): ");
					scanf("%c", &choice);
					fflush(stdin);
				}
			while(choice != 'r' && choice != 'R' && choice != 'f' && choice != 'F');    //They can enter uppercase or lowercase of their input.

			if(choice == 'f' || choice == 'F')   //This if statement checks to see if player 1 forfeited and if so it breaks from the game and goes to the end of the program.
				{
					player1Score = -1; //Player 1's score gets set to -1 so that at the end of the program it can tell if they forfeited.
					break;
				}

			die1 = rollDice(); //The next 2 line set each die to the value that is returned from the roll dice function.
			die2 = rollDice();
			displayDiceRoll(die1, die2); //Calling the function that displays what the player rolled.

			score = changeScore(die1, die2); //This function returns what to change the player's score to.

			if(score < 0)   //The changeScore function returns a negative value if the player rolled double threes.
				{
					player1Score = 0; //Double threes resets the player's score to 0.
				}

			else   //Adds player 1's score to what was returned from the function.
				{
					player1Score += score;
				}

			if(player1Score >= winningScore) //If player 1's score is greater than or equal to the winning score it breaks and goes to the end of the program.
				break;

			displayScore(player1Score, player2Score); //This function displays the current scores.

			system("pause");
			system("CLS");

			do   //This do while loop does input validation for the second player's input.
				{
					printf("Player 2 are you ready to roll? (Enter 'r' to roll, 'f' to forfeit): ");
					scanf("%c", &choice);
					fflush(stdin);
				}
			while(choice != 'r' && choice != 'R' && choice != 'f' && choice != 'F');    //They can enter uppercase or lowercase of their input.

			if(choice == 'f' || choice == 'F')   //This if statement checks to see if player 2 forfeited and if so it breaks from the game and goes to the end of the program.
				{
					player2Score = -1; //Player 2's score gets set to -1 so that at the end of the program it can tell if they forfeited.
					break;
				}

			die1 = rollDice(); //The next 2 line set each die to the value that is returned from the roll dice function.
			die2 = rollDice();
			displayDiceRoll(die1, die2); //Calling the function that displays what the player rolled.

			score = changeScore(die1, die2); //Function return.

			if(score < 0)   //Returns negative value if the player rolled double threes.
				{
					player2Score = 0; //resets the player's score to 0.
				}

			else   //Adds player 2's score to what was returned from the function.
				{
					player2Score += score;
				}

			if(player2Score >= winningScore)   //If player 2's score is greater than or equal to the winning score it breaks and goes to the end of the program.
				{
					break;
				}

			displayScore(player1Score, player2Score); //Displays current scores.

			system("pause");
			system("CLS");

		}
	while(player1Score < winningScore && player2Score < winningScore);   //The loop will continue while neither player has reached the winning score.

	if(player1Score >= winningScore)   //Here are the if else statements to show the congratulatory message for the player that wins.
		{
			printf("\n\nCongratulations Player 1! You have won this match!\n\nFinal Score:\nPlayer 1: %d\nPlayer 2: %d", player1Score, player2Score);
		}

	else if(player2Score >= winningScore)
		{
			printf("\nCongratulations Player 2! You have won this match!\nFinal Score:\nPlayer 1: %d\nPlayer 2: %d", player1Score, player2Score);
		}

	else if(player1Score < 0)
		{
			system("CLS");
			printf("Player 1 has forfeited the game. Congratulations Player 2! You have won!");
		}
	else if(player2Score < 0)
		{
			system("CLS");
			printf("Player 2 has forfeited the game. Congratulations Player 1! You have won!");
		}

	return 0;
}

int rollDice()   //Returns a random value from  1-6.
{
	return (rand() % 6) + 1;;
}

int changeScore(int die1, int die2)   //This function returns how to change the player's score based on the dice that were rolled.
{
	int score = 0;

	if(die1 == die2)
		{
			if(die1 != 3 && die1 != 6)
				{
					printf("\nYou rolled double %d's'! 5 points!\n", die1);
					score += 5;
				}
			else if(die1 == 3)
				{
					printf("\nOh no! You rolled double %d's'! You lost all your points!\n", die1);
					score = -1;
				}
			else if(die1 == 6)
				{
					printf("\nAWESOME! You rolled double %d's'! 25 points!\n", die1);
					score += 25;
				}
		}
	else
		printf("\nAww shucks... Not a double...\n");

	return score;
}

void displayDiceRoll(int die1, int die2)   //Displays the dice being rolled.
{

	for(int i = 0 ; i < 6 ; i++)
		{
			Sleep(250);
			printf("~shake~");
		}
	printf("\nYou rolled a %d ",die1);
	Sleep(500);
	printf("and a %d!\n", die2);
	Sleep(500);
}

void displayScore(int player1Score, int player2Score)   //Displays the score.
{
	printf("\n+---SCORE---+\nPlayer 1: %d\nPlayer 2: %d\n\n",player1Score, player2Score);
}
