#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t * hand){
unsigned N=hand->n_cards;
  for (int i=0;i<N;i++){
    print_card(*(hand->cards[i]));
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  size_t N = d->n_cards;
  for(int i=0;i<N;i++){
    if (d->cards[i]->value == c.value
	&& d->cards[i]->suit == c.suit){
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  size_t N=d->n_cards;
  if (N>1)
    for (size_t i=0;i<N-1;i++){
      size_t index = i+rand()/(RAND_MAX/(N-i)+1);
      card_t *temp = d->cards[index];
      d->cards[index] = d->cards[i];
      d->cards[i] = temp;
    }
  
}

void assert_full_deck(deck_t * d) {
  unsigned N = d->n_cards;
  for (int i=0;i<N;i++){
    if (deck_contains(d,*(d->cards[i]))){
      for (int j=i+1;j<N;j++){
	if (d->cards[j]->value == d->cards[i]->value
	&& d->cards[j]->suit == d->cards[i]->suit)
	  assert(0);
      }
    }
  }
}
