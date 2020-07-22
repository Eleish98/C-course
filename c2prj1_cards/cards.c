#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <=VALUE_ACE &&
	 c.suit >= SPADES && c.suit <= CLUBS); 

}

const char * ranking_to_string(hand_ranking_t r) {
  switch (r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH"; break;
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND"; break;
  case FULL_HOUSE: return "FULL_HOUSE"; break;
  case FLUSH: return "FLUSH"; break;
  case STRAIGHT: return "STRAIGHT"; break;
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND"; break;
  case TWO_PAIR: return "TWO_PAIR" ; break;
  case PAIR: return "PAIR"; break;
  case NOTHING: return "NOTHING"; break;
  default: return ""; break;
  }
}

char value_letter(card_t c) {
  if (c.value >=2 && c.value <=9)
    return c.value +'0';
  switch(c.value){
  case  10:
    return '0';
  case VALUE_ACE:
      return 'A';
  case VALUE_KING:
      return 'K';
  case VALUE_QUEEN:
      return 'Q';
  case VALUE_JACK:
      return 'J';
  default:
    return 0;
  }
}

char suit_letter(card_t c) {
  switch (c.suit){
  case SPADES:
    return 's';
  case HEARTS:
    return 'h';
  case DIAMONDS:
    return 'd';
  case CLUBS:
    return 'c';
  default:
    return '\0';
  }
}

void print_card(card_t c) {
  char t = value_letter(c);
  printf("%c",t);
  t = suit_letter(c);
  printf("%c",t);
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  if (value_let >='2' && value_let <='9')
    temp.value = (int)(value_let - '0');
  else{
    switch (value_let){
    case '0':
      temp.value=10;
      break;
    case 'A':
      temp.value = VALUE_ACE;
      break;
    case 'K':
      temp.value = VALUE_KING;
      break;
    case 'Q':
      temp.value = VALUE_QUEEN;
      break;
    case 'J':
      temp.value = VALUE_JACK;
      break;
    default:
      temp.value = -1;
      break;
    }
  }
  switch (suit_let){
  case 's':
    temp.suit = SPADES;
    break;
  case 'h':
    temp.suit = HEARTS;
    break;
  case 'd':
    temp.suit = DIAMONDS;
    break;
  case 'c':
    temp.suit = CLUBS;
    break;
  default:
    temp.value = -1;
    break;
  }
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  switch (c/13){
  case 0:
    temp.suit = SPADES;
    break;
  case 1:
    temp.suit = HEARTS;
    break;
  case 2:
    temp.suit = DIAMONDS;
    break;
  case 3:
    temp.suit = CLUBS;
    break;
  }
  c+=2;
  if (c%13 >=2 && c%13 <=9)
    temp.value = (c%13);
  else if (c%13 == 10)
    temp.value = 10;
  else if (c%13 == 1)
    temp.value = VALUE_ACE;
  else if (c%13 == 11)
    temp.value = VALUE_JACK;
  else if (c%13 == 12)
    temp.value = VALUE_QUEEN;
  else if (c%13 == 0)
    temp.value = VALUE_KING;
  return temp;
}
