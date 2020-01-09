/*=============================================================================  
|   Source code:  cardHeader.h
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
|  +---------------------------------------------------------------------------  
|  
|  Description: Header file for the Stud Poker program. It includes the 
|				headers used in the programs, defined constants, enums, 
|				the card struct, and the function prototypes.
|                  
|  *=========================================================================*/

#include <stdio.h>
#include <stdlib.h>		//Used to verify input
#include <time.h>		//Used for random number generator

#define DECK_SIZE 52
#define FACES 13
#define SUITS 4
#define NUM_OF_RANKS 9
#define CARDS_IN_HAND 5	//Set number of cards in each players' hand
#define NUM_HANDS 1		//Index for the hand input in argv[]
#define NUM_PLAYERS 2	//Index for the player input in argv[]
#define FUNCTION_COMPLETE 0	//Ends the function
#define TOTAL_INPUTS 3	//Should only include function and two inputs from user
#define MIN_PLAYERS 1	//Minimum number of players allowed
#define MAX_PLAYERS 10	//Maximum number of players allowed

//Structure definition for card
struct card
{
	const char* suit;

	const char* face;

	//Integer value for the face
	int rank;

	//Integer value for the suit
	int symbol;
};

typedef struct card Card;

//Converts the suits to an integer value
enum suits {DIAMONDS, HEARTS, CLUBS, SPADES};
	
//Converts the faces to an integer value
enum faces {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, 
		    NINE, TEN, JACK, QUEEN, KING, ACE};

//Index values for each card in the hand
enum cardIndex {CARD_ONE, CARD_TWO, CARD_THREE, CARD_FOUR, 
				CARD_FIVE};
	
//Gives points to each type of hand
enum handRank {HIGH_CARD, ONE_PAIR, TWO_PAIR, THREE_OF_A_KIND,
			   STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND,
			   STRAIGHT_FLUSH};

//Function Prototypes
int validate(int argumentCount, char *arguments[]);

void makeDeck(Card* const deck);

void showCards(const Card* const deck, size_t size);

void showHands(size_t row, size_t col, Card hands[row][col]);

void shuffle(Card* const deck);

void swap(Card* const deck, int firstCard, int secondCard);

void removeCards(Card* const deck, size_t size, int players, int hands);

void deal(size_t players, size_t hand, Card* const deck, 
		  Card hands[players][hand], size_t size);

void sortHands(size_t players, size_t hand, Card hands[players][hand]);

void findRank(size_t players, size_t hand, Card hands[players][hand]);

void findWinner(size_t players, int points[players]);

void rankTester();