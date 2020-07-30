#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
/*
int card_comp(const void * vp1, const void * vp2) {
  const card_t *   p1=*(card_t**)vp1;
  const card_t *   p2=*(card_t**)vp2;
  if (p1->value) >p2->value)
    return -1;
if ((*(p1))->value < (*(p2))->value)
    return 1;
if ((*(p1))->value == (*(p2))->value){
  if ((*(p1))->suit < (*(p2))->suit)
      return -1;
  if ((*(p1))->suit > (*(p2))->suit)
      return 1;
  if ((*(p1))->suit == (*(p2))->suit)
      return 0;
  }
  return 0;
}
*/
void print_hand(deck_t * hand){
  //card_t * H[hand->n_cards];
  //for (int i=0; i<hand->n_cards;i++)
  // H[i] = hand->cards[i];
  //for (int i=0;i<hand->n_cards;i++)
  // qsort(H,hand->n_cards,sizeof(card_t),card_comp);
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
