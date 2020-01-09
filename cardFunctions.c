/*=============================================================================  
|   Source code:  cardFunctions.c
|        Author:  Ali Mohammad
|
|	I hereby certify that this collective work is my own
|	and none of it is the work of any other person or entity.
|	______________________________________
|  
|        Language:  C
|
|  +---------------------------------------------------------------------------  
|  
|  Description: Functions used to run the Stud Poker program
|                  
|  *=========================================================================*/

#include "cardHeader.h"

/*---------------------------- validate ---------------------------------------
|  Function: validate(argumentCount, arguments)
|
|  Purpose : Checks if the input is valid
|
|  @param   Number of arguments passed
|  @param   Array of the arguments
|
|  @return  True or false value
*----------------------------------------------------------------------------*/
int validate(int argumentCount, char *arguments[])
{
	int const false = 0;
	int const true = 1;

	//Checks if the total number of inputs is correct
	if(argumentCount != TOTAL_INPUTS)
	{
		return false;
	}
	else
	{
		//Converts inputs to integers
		long hand = strtol(arguments[NUM_HANDS], NULL, 0);
		
		long players = strtol(arguments[NUM_PLAYERS], NULL, 0);
		
		//Checks if the number of players is a valid input and checks
		//if the hand input is an integer
		if(players >= MIN_PLAYERS && players <= MAX_PLAYERS && hand != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

/*---------------------------- makeDeck ---------------------------------------
|  Function: makeDeck(deck[])
|
|  Purpose : Fills the array with cards
|
|  @param   The deck to be filled with cards
|
|  @return  none
*----------------------------------------------------------------------------*/
void makeDeck(Card* const deck)
{
	//Used to swap the suit integer with the appropriate string
	const char *suits_string[SUITS] = {"Diamonds", "Hearts", "Clubs", 
										"Spades"};
	
	//Used to swap the face integer with the appropriate string
	const char *faces_string[FACES] = {"2", "3", "4", "5", "6", "7", "8", "9",
					   "10", "Jack", "Queen", "King", "Ace"};
	
	int suitIndex = 0;
	
	int faceIndex = 0;
	
	int positionOfCard = 0;
	
	//Build thirteen cards for each suit
	for(suitIndex = DIAMONDS; suitIndex <= SPADES; suitIndex++)
	{
		//Create a card of the suit stated above from two to ace
		for(faceIndex = TWO; faceIndex <= ACE; faceIndex++)
		{
			deck[positionOfCard].face = faces_string[faceIndex];
			
			deck[positionOfCard].suit = suits_string[suitIndex];

			//Place the integer value of the face in the rank value
			deck[positionOfCard].rank = faceIndex;

			//Place the integer value of the suit in the symbol value
			deck[positionOfCard].symbol = suitIndex;
			
			positionOfCard++;
		}
	}
}

/*---------------------------- showCards --------------------------------------
|  Function: showCards(Card* deck, size)
|
|  Purpose : Reveals the cards of the deck from the range given
|
|  @param   The deck of cards
|  @param   Number of cards in the deck to be printed
|
|  @return  none
*----------------------------------------------------------------------------*/
void showCards(const Card* const deck , size_t size)
{
	int card = 0;
	
	int cardsInRow = 0;
	
	//Maximum number of cards printed in each row.
	int maxInRow = 3;
	
	//Goes through each card and prints the string values of the face and suit
	for(card = 0; card < size; card++)
	{
		printf("%5s%s%-8s%s", deck[card].face, " of ", deck[card].suit, "   ");
		
		cardsInRow++;
		
		//Checks if the cards must be put in the next line
		if(cardsInRow == maxInRow)
		{
			printf("\n");
		
			cardsInRow = 0;
		}
	}
	
	printf("%s", "\n\n");
}

/*---------------------------- showHands --------------------------------------
|  Function: showHands(numOfPlayers, numInHand, hands[][])
|
|  Purpose : Prints the cards in each hand
|
|  @param   Number of players
|  @param   Number of cards for each player
|  @param   Array that hold the cards for each player
|
|  @return  none
*----------------------------------------------------------------------------*/
void showHands(size_t numOfPlayers, size_t numInHand, 
			   Card hands[numOfPlayers][numInHand])
{
	//Player being printed
	int player = 0;
	
	//Index of the card in the player's hand
	int card = 0;
	
	//Number of cards allowed in the row
	int const maxInRow = 3;
	
	printf("%s", "All Hands:\n");
	
	for(player = 0; player < numOfPlayers; player++)
	{
		//Since the player's number starts at zero and not one,
		//one is added to shift all the players to their proper identity
		printf("%s%d%s", "Player ", player + 1, " :");
		
		for(card = 0;  card < numInHand; card++)
		{
			printf("%s%5s%s%-8s", "  ", 
			  hands[player][card].face, " of ", hands[player][card].suit);

			//Makes a new line and shifts the card if the maxInRow is reached
			if(card == maxInRow)
			{
				printf("%s", "\n\t  ");
			}
		}
		
		printf("%s", "\n\n");
	}
}

/*---------------------------- shuffle ----------------------------------------
|  Function: shuffle(deck[])
|
|  Purpose : Goes through each index of the array and swaps the 
|			 contents with another random index in the array. 
|
|  @param   Array that holds all the cards
|
|  @return  none
*----------------------------------------------------------------------------*/
void shuffle(Card* const deck)
{
	int card = 0;
	
	//Index of card that will be swapped with
	int replace = 0;
	
	//Starts shuffling from the bottom
	for(card = DECK_SIZE - 1; card > 1; card--)
	{
		//Spot the card in the current index will be swapped with
		replace = rand() % card;
		
		swap(deck, card, replace);
	}
}

/*---------------------------- swap -------------------------------------------
|  Function: swap(deck[], firstCard, secondCard)
|
|  Purpose : Swaps the contents of the first card with 
|			 second card.
|
|  @param   Array that holds all the cards
|  @param   Index of the firstCard that swaps with secondCard
|  @param   Index of the secondCard that swaps with firstCard
|
|  @return  none
*----------------------------------------------------------------------------*/
void swap(Card* const deck, int firstCard, int secondCard)
{
	Card temp = deck[firstCard];
	
	deck[firstCard] = deck[secondCard];
	
	deck[secondCard] = temp;
}

/*---------------------------- deal -------------------------------------------
|  Function: deal(players, hand, deck[], hands[][], size)
|
|  Purpose : Swaps the contents of the first card with 
|			 second card.
|
|	@param   Number of players playing
|	@param   Number of cards in each hand
|	@param   The deck of cards
|	@param	 Array made to hold the cards for each player
|	@param	 The size of the deck
|
|  @return  none
*----------------------------------------------------------------------------*/
void deal(size_t players, size_t hand, Card* const deck, 
		  Card hands[players][hand], size_t size)
{
	//Current player taking cards
	int playerNumber = 0;
	
	//Current card being given
	int cardNumber = 0;
	
	//Number of cards given
	int cardGiven = 0;
	
	for(playerNumber = 0; playerNumber < players; playerNumber++)
	{
		for(cardNumber = 0; cardNumber < CARDS_IN_HAND; cardNumber++)
		{
			//Sets the players hand with a card from the deck
			hands[playerNumber][cardNumber] = deck[cardGiven];
			
			cardGiven++;
		}
	}

	//Removes the cards given from the deck
	removeCards(deck, size, players, hand);
}

/*---------------------------- removeCards ------------------------------------
|  Function: removeCards(deck[], size, players, hand)
|
|  Purpose : Swaps the contents of the first card with 
|			 second card.
|
|	@param   Number of players playing
|	@param   Number of cards in each hand
|	@param   The deck of cards
|	@param	 Array made to hold the cards for each player
|	@param	 The size of the deck
|
|  @return  none
*----------------------------------------------------------------------------*/
void removeCards(Card* const deck, size_t size, int players, int hand)
{
	//Calculates the number of cards given
	int cardsGiven = players * hand;
	
	//Card to be replaced in the deck
	int replaceCard = 0;

	//Replaces the cards given away and with cards left
	for(replaceCard = 0; replaceCard < size  - cardsGiven; replaceCard++)
	{
		deck[replaceCard] = deck[replaceCard + cardsGiven];
	}
}

/*---------------------------- sortHands --------------------------------------
|  Function: sortHands(players, hand, hands[][])
|
|  Purpose : Sorts the hands of each player by face rank
|
|	@param   Number of players playing
|	@param   Number of cards in each hand
|	@param	 Array that holds the cards for each player
|
|  @return  none
*----------------------------------------------------------------------------*/
void sortHands(size_t players, size_t hand, Card hands[players][hand])
{
	int thePlayer = 0;
	
	int nextCard = 0;
	
	int currentCard = 0;
	
	int nextRank = 0;
	
	Card replace = hands[0][0];
	
	//Selection sort algorithm
	for(thePlayer = 0; thePlayer < players; thePlayer++)
	{
		for(nextCard = 1; nextCard < hand; nextCard++)
		{
			nextRank = hands[thePlayer][nextCard].rank;

			replace = hands[thePlayer][nextCard];
			
			currentCard = nextCard - 1;

			while( currentCard >= 0 && 
				   hands[thePlayer][currentCard].rank > nextRank)
			{
				hands[thePlayer][currentCard + 1] = 
									hands[thePlayer][currentCard];

				currentCard = currentCard - 1;
			}
			
			hands[thePlayer][currentCard + 1] = replace;
		}
	}
}


/*---------------------------- findRank ---------------------------------------
|  Function: findRank(players, hand, hands[][])
|
|  Purpose : Finds what type of hand each player has and assigns
|			 points to them. Then the winner is found through 
|			 the findWinner function and the winner is printed.
|			 The points added are the value of the type of hand
|			 and the value of the highest card of that type.
|
|  @param   Number of players recorded into the array
|  @param   Number of cards in each hand
|  @param   Array that holds the cards that each player has
|
|  @return  none
*----------------------------------------------------------------------------*/
void findRank(size_t players, size_t hand, Card hands[players][hand])
{
	//Holds the index of the player
	int thePlayer = 0;

	//Array to hold the points the player gets
	int points[players];
	int initialize = 0;
	
	//Initialize points array
	for(initialize = 0; initialize < players; initialize++)
	{
		points[initialize] = 0;
	}

	//Values of each card in the hand
	int rankOne = 0;
	int suitOne = 0;	
	
	int rankTwo = 0;
	int suitTwo = 0;

	int rankThree = 0;
	int suitThree = 0;
	
	int rankFour = 0;
	int suitFour = 0;
	
	int rankFive = 0;
	int suitFive = 0;


	for(thePlayer = 0; thePlayer < players; thePlayer++)
	{
		//Values of each card the player has is retrieved
		rankOne = hands[thePlayer][CARD_ONE].rank;
		suitOne = hands[thePlayer][CARD_ONE].symbol;
		
		rankTwo = hands[thePlayer][CARD_TWO].rank;
		suitTwo = hands[thePlayer][CARD_TWO].symbol;

		rankThree = hands[thePlayer][CARD_THREE].rank;
		suitThree = hands[thePlayer][CARD_THREE].symbol;

		rankFour = hands[thePlayer][CARD_FOUR].rank;
		suitFour = hands[thePlayer][CARD_FOUR].symbol;

		rankFive = hands[thePlayer][CARD_FIVE].rank;
		suitFive = hands[thePlayer][CARD_FIVE].symbol;
		
		printf("%s%d%s", "Player ", thePlayer + 1, " : ");
		
		//Checks for straights
		if((rankOne == TEN && rankTwo == JACK && rankThree == QUEEN && 
			rankFour == KING && rankFive == ACE) || (rankOne == TWO &&
			rankTwo == THREE && rankThree == FOUR && rankFour == FIVE &&
			rankFive == ACE) || (rankOne == (rankTwo + 1) && 
			rankTwo == (rankThree + 1) && rankThree == (rankFour + 1) && 
			rankFour == (rankFive + 1)))
		{
			printf("%s", "Straight ");
			
			points[thePlayer] = STRAIGHT;
		}
		
		//Checks for flush
		if(suitOne == suitTwo && suitTwo == suitThree && 
		   suitThree == suitFour && suitFour == suitFive)
		{
			printf("%s", "Flush");
			
			//Checks if it is a straight flush
			if(points[thePlayer] == STRAIGHT)
			{
				points[thePlayer] = STRAIGHT_FLUSH;
			}
			else
			{
				points[thePlayer] = FLUSH;
			}
		}

		//Checks for at least one pair
		else if(rankOne == rankTwo  || rankTwo == rankThree || 
				rankThree == rankFour || rankFour == rankFive)
		{
			//Check for at least two sets of matches
			if((rankOne == rankTwo && rankThree == rankFour)
			   || (rankOne == rankTwo && rankFour == rankFive)
			   || (rankTwo == rankThree && rankFour == rankFive))
			{
				//Four cards match
				if(rankOne == rankFour || rankTwo == rankFive)
				{
					printf("%s", "Four Of A Kind");
					
					points[thePlayer] = FOUR_OF_A_KIND;
				}
				
				//Full House
				else if(rankOne == rankTwo && rankFour == rankFive &&
						(rankOne == rankThree || rankThree == rankFive))
				{
					printf("%s", "Full House");
					
					points[thePlayer] = FULL_HOUSE;
				}
				
				//Two set of matches 
				else
				{
					printf("%s", "Two Pairs");
					
					points[thePlayer] = TWO_PAIR;
				}
			}
			
			//Checks if three cards match
			else if((rankOne == rankTwo && rankTwo == rankThree)
					|| (rankThree == rankFour && rankFour == rankFive))
			{
				//Three Of A Kind
				printf("%s", "Three Of A Kind");
					
				points[thePlayer] = THREE_OF_A_KIND;
			}
			
			//One Pair
			else
			{
				printf("%s", "One Pair");
				
				points[thePlayer] = ONE_PAIR;
			}
		}
		
		//Cards are not a straight, flush, or a pair
		//so no points were given
		else if(points[thePlayer] == 0)
		{
			printf("%s", "High Card");
			
			points[thePlayer] = HIGH_CARD;
			
		}
		
		printf("%s", "\n");
	}

	//Find who has the best hand
	findWinner(players, points);
}

/*---------------------------- findWinner -------------------------------------
|  Function: findWinner(players, points[])
|
|  Purpose : Searches through the array to find which player 
|			 has the best hand
|
|  @param   Number of players recorded into the array
|  @param   Array that holds the accumulated points for each player
|
|  @return  none
*----------------------------------------------------------------------------*/
void findWinner(size_t players, int points[players])
{
	const char *ranks_string[NUM_OF_RANKS] = 
		{"High Card", "One Pair", "Two Pairs", "Three Of A Kind",
		"Straight", "Flush", "Full House", "Four Of A Kind",
		"Straight Flush"};
	
	printf("%s", "\nWinner(s)\n");

	int count = 0;
	
	//Number of players with the highest number of points
	int winner = 0;
	
	//Highest number of points so far
	int max = 0;
	
	//Current player
	int thePlayer = 0;	

	//Array to hold multiple winners
	int multiWin[players];
	
	int initialize = 0;
	
	//Initialize points array
	for(initialize = 0; initialize < players; initialize++)
	{
		multiWin[initialize] = 0;
	}
	
	
	//Compares the points of each player
	for(thePlayer = 0; thePlayer < players; thePlayer++)
	{
		//Compares player's points to highest number of points so far
		if(points[thePlayer] > max)
		{
			max = points[thePlayer];
		
			count = 0;

			multiWin[count] = thePlayer;
		}
		
		//Multiple winners so they are recorded
		else if(points[thePlayer] == max)
		{
			count++;

			multiWin[count] = thePlayer;
		}
	}

	//Prints the winner or winners
	for(winner = 0; winner <= count; winner++)
	{
		//Since the player's number starts at zero and not one,
		//one is added to display their proper identity
		printf("%s%d  ","Player ", multiWin[winner] + 1);
		printf("%s%s", ranks_string[max], "\n");
	}
}
