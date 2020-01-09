/*=============================================================================  
|   Source code:  cardMain.c
|        Author:  Ali Mohammad
|    Student ID:  5914999  
|    Assignment:  Program #4 Stud Poker
|  
|        Course:  COP 4338 (Programming III)   
|       Section:  U03
|    Instructor:  William Feild  
|      Due Date:  October 23, 2018, at the beginning of class
|
|	I hereby certify that this collective work is my own
|	and none of it is the work of any other person or entity.
|	______________________________________
|  
|        Language:  C
|
|	Before Compile/Run: Have Makefile, cardMain.c, cardFunctions.c,
|						cardTester.c, and cardHeader.h in the same 
|						directory.
|
|     Compile/Run:  make
|					./card.out @ !
|
|					//Where @ = # of cards per player and ! = # of players.
|
|  +---------------------------------------------------------------------------
|  
|  Description: The program creates a sorted deck of cards in an array.
|				It will then shuffle and distribute cards to each player.
|				Each player will have their hands shown and the remaining
|				cards in the deck will be shown. Each of the player's 
|				hand will be sorted and the player with the highest hand will
|				be declared the winner.
|                  
|        Input: The user must specify the number of players and number of
|				cards each player will have. The number of players must be
|				in the range from one to ten. The input for the number of 
|				cards dealt will be changed to five if the input is
|				valid. If either input is invalid, an message "Invalid
|				Input" will be printed.
|  
|       Output: The output will show the deck in order before the shuffle.
|				Then the deck will be shuffled. The shuffled deck will be 
|				displayed. The five cards will be given to each player and 
|				each player will have their hands shown along with the 
|				remaining cards in the deck. The rank of each hand will be
|				shown and the winner or winners will be declared. If the 
|				input was invalid, an error message will be displayed.
|  
|     Process:  The cards are defined through structs. The card struct will 
|				hold the face, suit, rank of the face as an integer, and the
|				suit as an integer. The two integers are used to help find 
|				what type of hand the player has since its easier to compare
|				integers than it is to compare strings. Enums are made to
|				clarify what values are used in each function. In the main,
|				the input is checked through the validate function. If it is
|				invalid, a message will be shown to the user. If it is valid,
|				an array of Card types is made with the size being the number
|				cards in the deck. A second array is made for the players. The
|				second array will hold the player's identity and their five
|				cards. The size of the array is specified through user input.
|				The random number generator is made for later use. The array
|				for the deck is filled by the use of the makeDeck function.
|				The deck is then displayed. The function deal distributes
|				cards to each player. The function deal takes the shuffled 
|				deck and places each card into the second array for the 
|				players' hands. The players' hand is printed and the remaining
|				cards in the deck is printed. The hands are sorted and printed
|				again. The winner is found by comparing the rank of each hand.
|				The rank is found by comparing each card in the hand and
|				looking for specific patterns. The results have been printed,
|				so the main returns 0 to end. 
|  
|  *=========================================================================*/
#include "cardHeader.h"

int main(int argc, char *argv[])
{	
	//Checks for valid input
	if(validate(argc, argv))
	{
		//Converts user input for number of players to an integer
		long players = strtol(argv[NUM_PLAYERS], NULL, 0);
		
		//Array of Card is made with size being the number of cards in a deck
		Card deck[DECK_SIZE];
		
		//Array of Card for each player
		Card hands[(int)players][CARDS_IN_HAND];
		
		//Random Number generator
		srand( time(NULL) );
		
		//Fill the deck with structs of Card
		makeDeck(deck);
		
		showCards(deck, sizeof(deck) / sizeof(deck[0]));
		
		shuffle(deck);
		
		showCards(deck, sizeof(deck) / sizeof(deck[0]));
		
		deal((int)players, CARDS_IN_HAND, deck, hands, 
			sizeof(deck) / sizeof(deck[0]));
		
		showHands((int)players, CARDS_IN_HAND, hands);
		
		showCards(deck, 
			(sizeof(deck) / sizeof(deck[0]) - (CARDS_IN_HAND * (int)players)));
		
		sortHands((int)players, CARDS_IN_HAND, hands);
		
		showHands((int) players, CARDS_IN_HAND, hands);
		
		//Finds the highest rank between the players and displays it
		findRank((int)players, CARDS_IN_HAND, hands);
		
		rankTester();
	}
	else
	{
		printf("%s", "Invalid Input\n");
	}

	return FUNCTION_COMPLETE;
}