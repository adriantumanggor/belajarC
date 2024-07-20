#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char deck[52] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K',
                 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K',
                 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K',
                 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

void shuffle();

int main() {
    // Shuffle the deck
    srand(time(NULL));
    shuffle();

    // Rest of the code...
}

void shuffle() {
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        char temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Rest of the code...
