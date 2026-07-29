#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <exception>
#include <cstdlib>

/**
 * 7.24 (Simulation: coupon collector’s problem) Simulates picking cards from a 
 * shuffled deck until one card from each of the four suits has been found.
 */

// Determines the suit index for a given card number (1 to 52).
int get_suit_index(int card)
{
    if (card >= 1 && card <= 13) return 0;      // Hearts
    if (card >= 14 && card <= 26) return 1;    // Diamonds
    if (card >= 27 && card <= 39) return 2;    // Clubs
    return 3;                                  // Spades (40 to 52)
}

// Prints the name and suit of the card.
void print_card(int card)
{
    std::string suit = "";
    int suit_index = get_suit_index(card);
    
    switch (suit_index)
    {
        case 0: suit = "Hearts"; break;
        case 1: suit = "Diamonds"; break;
        case 2: suit = "Clubs"; break;
        case 3: suit = "Spades"; break;
    }

    // Calculate face value (1 to 13)
    int rank = card % 13;
    if (rank == 0)
    {
        rank = 13; // Multiples of 13 represent Kings
    }

    std::string value = "";
    switch (rank)
    {
        case 1: value = "Ace of "; break;
        case 11: value = "Jack of "; break;
        case 12: value = "Queen of "; break;
        case 13: value = "King of "; break;
        default: value = std::to_string(rank) + " of "; break;
    }

    std::cout << value << suit << '\n';
}

// Picks a random card from the deck array.
int pick_a_card(const std::vector<int> &deck, std::mt19937 &gen)
{
    std::uniform_int_distribution<> dis(0, static_cast<int>(deck.size()) - 1);
    return deck[dis(gen)];
}

// Generates and returns a shuffled deck of 52 cards.
std::vector<int> get_shuffled_deck(std::mt19937 &gen)
{
    std::vector<int> dck(52);

    for (int i = 0; i < 52; ++i)
    {
        dck[i] = i + 1; // 1 to 52
    }
    
    // Shuffle the deck using random swaps
    std::uniform_int_distribution<> dis(0, 51);
    for (int i = 0; i < 260; ++i)
    {
        int random1 = dis(gen);
        int random2 = dis(gen);
        int temp = dck[random1];
        dck[random1] = dck[random2];
        dck[random2] = temp;
    }

    return dck;
}

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::vector<int> deck = get_shuffled_deck(gen);
        std::vector<bool> found_suits(4, false);
        int suits_found_count = 0;
        int num_picks = 0;

        while (suits_found_count < 4)
        {
            int card = pick_a_card(deck, gen);
            num_picks++;

            int suit_index = get_suit_index(card);

            // If this suit hasn't been picked yet, record it and print the card
            if (!found_suits[suit_index])
            {
                found_suits[suit_index] = true;
                suits_found_count++;
                print_card(card);
            }
        }
        
        std::cout << "Number of picks: " << num_picks << '\n';

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An unexpected error occurred during execution: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}