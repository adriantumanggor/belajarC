#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getValue(char card);

int main() {
    // Initialize the deck of cards
    char deck[52] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K',
                     'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K',
                     'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K',
                     'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

    // Shuffle the deck
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        int j = rand() % 52;
        char temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }

    // Deal initial cards to the player and dealer
    int playerScore = 0;
    int dealerScore = 0;

    playerScore += getValue(deck[0]);
    dealerScore += getValue(deck[1]);
    playerScore += getValue(deck[2]);
    dealerScore += getValue(deck[3]);

    // Print the initial cards
    printf("Player's cards: %c %c\n", deck[0], deck[2]);
    printf("Dealer's cards: %c %c\n", deck[1], deck[3]);

    // Game logic
    char choice;
    while (playerScore < 21) {
        printf("Do you want to hit or stand? (h/s): ");
        scanf(" %c", &choice);

        if (choice == 'h') {
            playerScore += getValue(deck[playerScore / 2 + 2]);
            printf("Player's cards: ");
            for (int i = 0; i <= playerScore / 2; i++) {
                printf("%c ", deck[i * 2]);
            }
            printf("\n");
        } else if (choice == 's') {
            break;
        }
    }

    // Dealer's turn
    while (dealerScore < 17) {
        dealerScore += getValue(deck[dealerScore / 2 + 2]);
    }

    // Print final scores
    printf("Player's score: %d\n", playerScore);
    printf("Dealer's score: %d\n", dealerScore);

    // Determine the winner
    if (playerScore > 21) {
        printf("Player busts! Dealer wins.\n");
    } else if (dealerScore > 21) {
        printf("Dealer busts! Player wins.\n");
    } else if (playerScore > dealerScore) {
        printf("Player wins!\n");
    } else if (dealerScore > playerScore) {
        printf("Dealer wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}

int getValue(char card) {
    if (card == 'A') {
        return 11;
    } else if (card == 'T' || card == 'J' || card == 'Q' || card == 'K') {
        return 10;
    } else {
        return card - '0';
    }
}