/*=============================================================================  
|   Source code:  cardRankTest.c
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
|  Description: Functions used to test ranking system.
|                  
|  *=========================================================================*/

#include "cardHeader.h"

void rankTester()
{
	//Holds all the hand types
	Card hands[NUM_OF_RANKS][CARDS_IN_HAND];
	
	//High Card
	hands[HIGH_CARD][CARD_ONE].suit = "Spades";
	hands[HIGH_CARD][CARD_ONE].face = "2";
	hands[HIGH_CARD][CARD_ONE].rank = TWO;
	hands[HIGH_CARD][CARD_ONE].symbol = SPADES;
	
	hands[HIGH_CARD][CARD_TWO].suit = "Hearts";
	hands[HIGH_CARD][CARD_TWO].face = "3";
	hands[HIGH_CARD][CARD_TWO].rank = THREE;
	hands[HIGH_CARD][CARD_TWO].symbol = HEARTS;
	
	hands[HIGH_CARD][CARD_THREE].suit = "Clubs";
	hands[HIGH_CARD][CARD_THREE].face = "8";
	hands[HIGH_CARD][CARD_THREE].rank = EIGHT;
	hands[HIGH_CARD][CARD_THREE].symbol = CLUBS;
	
	hands[HIGH_CARD][CARD_FOUR].suit = "Clubs";
	hands[HIGH_CARD][CARD_FOUR].face = "6";
	hands[HIGH_CARD][CARD_FOUR].rank = SIX;
	hands[HIGH_CARD][CARD_FOUR].symbol = CLUBS;
	
	hands[HIGH_CARD][CARD_FIVE].suit = "Diamonds";
	hands[HIGH_CARD][CARD_FIVE].face = "King";
	hands[HIGH_CARD][CARD_FIVE].rank = KING;
	hands[HIGH_CARD][CARD_FIVE].symbol = DIAMONDS;
	
	//One Pair
	hands[ONE_PAIR][CARD_ONE].suit = "Spades";
	hands[ONE_PAIR][CARD_ONE].face = "4";
	hands[ONE_PAIR][CARD_ONE].rank = FOUR;
	hands[ONE_PAIR][CARD_ONE].symbol = SPADES;
	
	hands[ONE_PAIR][CARD_TWO].suit = "Hearts";
	hands[ONE_PAIR][CARD_TWO].face = "Ace";
	hands[ONE_PAIR][CARD_TWO].rank = ACE;
	hands[ONE_PAIR][CARD_TWO].symbol = HEARTS;
	
	hands[ONE_PAIR][CARD_THREE].suit = "Hearts";
	hands[ONE_PAIR][CARD_THREE].face = "10";
	hands[ONE_PAIR][CARD_THREE].rank = TEN;
	hands[ONE_PAIR][CARD_THREE].symbol = HEARTS;
	
	hands[ONE_PAIR][CARD_FOUR].suit = "Diamonds";
	hands[ONE_PAIR][CARD_FOUR].face = "Jack";
	hands[ONE_PAIR][CARD_FOUR].rank = JACK;
	hands[ONE_PAIR][CARD_FOUR].symbol = DIAMONDS;
	
	hands[ONE_PAIR][CARD_FIVE].suit = "Clubs";
	hands[ONE_PAIR][CARD_FIVE].face = "10";
	hands[ONE_PAIR][CARD_FIVE].rank = TEN;
	hands[ONE_PAIR][CARD_FIVE].symbol = CLUBS;
	
	//Two Pairs
	hands[TWO_PAIR][CARD_ONE].suit = "Diamonds";
	hands[TWO_PAIR][CARD_ONE].face = "2";
	hands[TWO_PAIR][CARD_ONE].rank = TWO;
	hands[TWO_PAIR][CARD_ONE].symbol = DIAMONDS;
	
	hands[TWO_PAIR][CARD_TWO].suit = "Hearts";
	hands[TWO_PAIR][CARD_TWO].face = "7";
	hands[TWO_PAIR][CARD_TWO].rank = SEVEN;
	hands[TWO_PAIR][CARD_TWO].symbol = HEARTS;
	
	hands[TWO_PAIR][CARD_THREE].suit = "Clubs";
	hands[TWO_PAIR][CARD_THREE].face = "Jack";
	hands[TWO_PAIR][CARD_THREE].rank = JACK;
	hands[TWO_PAIR][CARD_THREE].symbol = CLUBS;
	
	hands[TWO_PAIR][CARD_FOUR].suit = "Spades";
	hands[TWO_PAIR][CARD_FOUR].face = "2";
	hands[TWO_PAIR][CARD_FOUR].rank = TWO;
	hands[TWO_PAIR][CARD_FOUR].symbol = SPADES;
	
	hands[TWO_PAIR][CARD_FIVE].suit = "Spades";
	hands[TWO_PAIR][CARD_FIVE].face = "Jack";
	hands[TWO_PAIR][CARD_FIVE].rank = JACK;
	hands[TWO_PAIR][CARD_FIVE].symbol = SPADES;
	
	//Three Of A Kind
	hands[THREE_OF_A_KIND][CARD_ONE].suit = "Clubs";
	hands[THREE_OF_A_KIND][CARD_ONE].face = "3";
	hands[THREE_OF_A_KIND][CARD_ONE].rank = THREE;
	hands[THREE_OF_A_KIND][CARD_ONE].symbol = CLUBS;
	
	hands[THREE_OF_A_KIND][CARD_TWO].suit = "Hearts";
	hands[THREE_OF_A_KIND][CARD_TWO].face = "5";
	hands[THREE_OF_A_KIND][CARD_TWO].rank = FIVE;
	hands[THREE_OF_A_KIND][CARD_TWO].symbol = HEARTS;
	
	hands[THREE_OF_A_KIND][CARD_THREE].suit = "Diamonds";
	hands[THREE_OF_A_KIND][CARD_THREE].face = "3";
	hands[THREE_OF_A_KIND][CARD_THREE].rank = THREE;
	hands[THREE_OF_A_KIND][CARD_THREE].symbol = DIAMONDS;
	
	hands[THREE_OF_A_KIND][CARD_FOUR].suit = "Hearts";
	hands[THREE_OF_A_KIND][CARD_FOUR].face = "8";
	hands[THREE_OF_A_KIND][CARD_FOUR].rank = EIGHT;
	hands[THREE_OF_A_KIND][CARD_FOUR].symbol = HEARTS;
	
	hands[THREE_OF_A_KIND][CARD_FIVE].suit = "Spades";
	hands[THREE_OF_A_KIND][CARD_FIVE].face = "3";
	hands[THREE_OF_A_KIND][CARD_FIVE].rank = THREE;
	hands[THREE_OF_A_KIND][CARD_FIVE].symbol = SPADES;

	//Straight
	hands[STRAIGHT][CARD_ONE].suit = "Spades";
	hands[STRAIGHT][CARD_ONE].face = "5";
	hands[STRAIGHT][CARD_ONE].rank = FIVE;
	hands[STRAIGHT][CARD_ONE].symbol = SPADES;
	
	hands[STRAIGHT][CARD_TWO].suit = "Diamonds";
	hands[STRAIGHT][CARD_TWO].face = "2";
	hands[STRAIGHT][CARD_TWO].rank = TWO;
	hands[STRAIGHT][CARD_TWO].symbol = DIAMONDS;
	
	hands[STRAIGHT][CARD_THREE].suit = "Clubs";
	hands[STRAIGHT][CARD_THREE].face = "4";
	hands[STRAIGHT][CARD_THREE].rank = FOUR;
	hands[STRAIGHT][CARD_THREE].symbol = CLUBS;
	
	hands[STRAIGHT][CARD_FOUR].suit = "Hearts";
	hands[STRAIGHT][CARD_FOUR].face = "Ace";
	hands[STRAIGHT][CARD_FOUR].rank = ACE;
	hands[STRAIGHT][CARD_FOUR].symbol = HEARTS;
	
	hands[STRAIGHT][CARD_FIVE].suit = "Hearts";
	hands[STRAIGHT][CARD_FIVE].face = "3";
	hands[STRAIGHT][CARD_FIVE].rank = THREE;
	hands[STRAIGHT][CARD_FIVE].symbol = HEARTS;
	
	//Flush
	hands[FLUSH][CARD_ONE].suit = "Clubs";
	hands[FLUSH][CARD_ONE].face = "4";
	hands[FLUSH][CARD_ONE].rank = FOUR;
	hands[FLUSH][CARD_ONE].symbol = CLUBS;
	
	hands[FLUSH][CARD_TWO].suit = "Clubs";
	hands[FLUSH][CARD_TWO].face = "8";
	hands[FLUSH][CARD_TWO].rank = EIGHT;
	hands[FLUSH][CARD_TWO].symbol = CLUBS;
	
	hands[FLUSH][CARD_THREE].suit = "Clubs";
	hands[FLUSH][CARD_THREE].face = "Ace";
	hands[FLUSH][CARD_THREE].rank = ACE;
	hands[FLUSH][CARD_THREE].symbol = CLUBS;
	
	hands[FLUSH][CARD_FOUR].suit = "Clubs";
	hands[FLUSH][CARD_FOUR].face = "Queen";
	hands[FLUSH][CARD_FOUR].rank = QUEEN;
	hands[FLUSH][CARD_FOUR].symbol = CLUBS;
	
	hands[FLUSH][CARD_FIVE].suit = "Clubs";
	hands[FLUSH][CARD_FIVE].face = "9";
	hands[FLUSH][CARD_FIVE].rank = NINE;
	hands[FLUSH][CARD_FIVE].symbol = CLUBS;
	
	//Full House
	hands[FULL_HOUSE][CARD_ONE].suit = "Clubs";
	hands[FULL_HOUSE][CARD_ONE].face = "6";
	hands[FULL_HOUSE][CARD_ONE].rank = SIX;
	hands[FULL_HOUSE][CARD_ONE].symbol = CLUBS;
	
	hands[FULL_HOUSE][CARD_TWO].suit = "Diamonds";
	hands[FULL_HOUSE][CARD_TWO].face = "Queen";
	hands[FULL_HOUSE][CARD_TWO].rank = QUEEN;
	hands[FULL_HOUSE][CARD_TWO].symbol = DIAMONDS;
	
	hands[FULL_HOUSE][CARD_THREE].suit = "Hearts";
	hands[FULL_HOUSE][CARD_THREE].face = "6";
	hands[FULL_HOUSE][CARD_THREE].rank = SIX;
	hands[FULL_HOUSE][CARD_THREE].symbol = HEARTS;
	
	hands[FULL_HOUSE][CARD_FOUR].suit = "Spades";
	hands[FULL_HOUSE][CARD_FOUR].face = "Queen";
	hands[FULL_HOUSE][CARD_FOUR].rank = QUEEN;
	hands[FULL_HOUSE][CARD_FOUR].symbol = SPADES;
	
	hands[FULL_HOUSE][CARD_FIVE].suit = "Spades";
	hands[FULL_HOUSE][CARD_FIVE].face = "6";
	hands[FULL_HOUSE][CARD_FIVE].rank = SIX;
	hands[FULL_HOUSE][CARD_FIVE].symbol = SPADES;
	
	//Four Of A Kind
	hands[FOUR_OF_A_KIND][CARD_ONE].suit = "Diamonds";
	hands[FOUR_OF_A_KIND][CARD_ONE].face = "Ace";
	hands[FOUR_OF_A_KIND][CARD_ONE].rank = ACE;
	hands[FOUR_OF_A_KIND][CARD_ONE].symbol = DIAMONDS;
	
	hands[FOUR_OF_A_KIND][CARD_TWO].suit = "Hearts";
	hands[FOUR_OF_A_KIND][CARD_TWO].face = "Ace";
	hands[FOUR_OF_A_KIND][CARD_TWO].rank = ACE;
	hands[FOUR_OF_A_KIND][CARD_TWO].symbol = HEARTS;
	
	hands[FOUR_OF_A_KIND][CARD_THREE].suit = "Spades";
	hands[FOUR_OF_A_KIND][CARD_THREE].face = "Ace";
	hands[FOUR_OF_A_KIND][CARD_THREE].rank = ACE;
	hands[FOUR_OF_A_KIND][CARD_THREE].symbol = SPADES;
	
	hands[FOUR_OF_A_KIND][CARD_FOUR].suit = "Hearts";
	hands[FOUR_OF_A_KIND][CARD_FOUR].face = "2";
	hands[FOUR_OF_A_KIND][CARD_FOUR].rank = TWO;
	hands[FOUR_OF_A_KIND][CARD_FOUR].symbol = HEARTS;
	
	hands[FOUR_OF_A_KIND][CARD_FIVE].suit = "Clubs";
	hands[FOUR_OF_A_KIND][CARD_FIVE].face = "Ace";
	hands[FOUR_OF_A_KIND][CARD_FIVE].rank = ACE;
	hands[FOUR_OF_A_KIND][CARD_FIVE].symbol = CLUBS;
	
	//Straight Flush
	hands[STRAIGHT_FLUSH][CARD_ONE].suit = "Spades";
	hands[STRAIGHT_FLUSH][CARD_ONE].face = "Jack";
	hands[STRAIGHT_FLUSH][CARD_ONE].rank = JACK;
	hands[STRAIGHT_FLUSH][CARD_ONE].symbol = SPADES;
	
	hands[STRAIGHT_FLUSH][CARD_TWO].suit = "Spades";
	hands[STRAIGHT_FLUSH][CARD_TWO].face = "King";
	hands[STRAIGHT_FLUSH][CARD_TWO].rank = KING;
	hands[STRAIGHT_FLUSH][CARD_TWO].symbol = SPADES;
	
	hands[STRAIGHT_FLUSH][CARD_THREE].suit = "Spades";
	hands[STRAIGHT_FLUSH][CARD_THREE].face = "Queen";
	hands[STRAIGHT_FLUSH][CARD_THREE].rank = QUEEN;
	hands[STRAIGHT_FLUSH][CARD_THREE].symbol = SPADES;
	
	hands[STRAIGHT_FLUSH][CARD_FOUR].suit = "Spades";
	hands[STRAIGHT_FLUSH][CARD_FOUR].face = "Ace";
	hands[STRAIGHT_FLUSH][CARD_FOUR].rank = ACE;
	hands[STRAIGHT_FLUSH][CARD_FOUR].symbol = SPADES;
	
	hands[STRAIGHT_FLUSH][CARD_FIVE].suit = "Spades";
	hands[STRAIGHT_FLUSH][CARD_FIVE].face = "10";
	hands[STRAIGHT_FLUSH][CARD_FIVE].rank = TEN;
	hands[STRAIGHT_FLUSH][CARD_FIVE].symbol = SPADES;

	printf("%s", "\nPoker Hands: Test\n");
	
	sortHands(NUM_OF_RANKS, CARDS_IN_HAND, hands);
	
	showHands(NUM_OF_RANKS, CARDS_IN_HAND, hands);
	
	findRank(NUM_OF_RANKS, CARDS_IN_HAND, hands);
}