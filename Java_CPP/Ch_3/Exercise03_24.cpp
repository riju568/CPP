#include <iostream>
#include <random>
#include <string>
#include <stdexcept>
/**

 * **3.24 (Game: pick a card)

 * Write a program that simulates picking a card from a deck

 * of 52 cards. Your program should display the rank (Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10,

 * Jack, Queen, King) and suit (Clubs, Diamonds, Hearts, Spades) of the card.

 * <p>

 * Here is a sample run of the program:

 * <p>

 * The card you picked is Jack of Hearts

 */
std::string getCardValue(int randomCardNumber)
{
    int cardValue = randomCardNumber % 13; // Remove the suit from the card number
    if (cardValue == 1)
    {
        return "Ace";
    }
    else if (cardValue == 11)
    {
        return "Jack";
    }
    else if (cardValue == 12)
    {
        return "Queen";
    }
    else if (cardValue == 0)
    { // 13 % 13 = 0
        return "King";
    }
    else
    {
        return std::to_string(cardValue);
    }
}

void setCardFromRandomNumber(int randomCardNumber, std::string &card, std::string &suit)
{
    if (randomCardNumber <= 13)
    {
        suit = "Clubs";
    }
    else if (randomCardNumber <= 26)
    {
        suit = "Diamonds";
    }
    else if (randomCardNumber <= 39)
    {
        suit = "Hearts";
    }
    else
    {
        suit = "Spades";
    }

    card = getCardValue(randomCardNumber);
}

int main()
{
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 52);
        int randomCardNumber = dis(gen);
        std::cout << "Random card whole number is: " << randomCardNumber << "\n";
        std::string card = "";
        std::string suit = "";
        setCardFromRandomNumber(randomCardNumber, card, suit);
        std::cout << "The card you picked is " << card << " of " << suit << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}