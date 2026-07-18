#include <iostream> // for Input output cin>> and <<cout
#include <algorithm> // Required for std::max
#include <cmath> // Required for the sqrt() function
#include <string> // Required for using the std::string class
#include <vector>    // Required for dynamic arrays (vectors)
#include <memory> // Required for smart pointers (std::unique_ptr)

using namespace std;
// 1.WAP TO FIND THE GREATEST OF 3 NUMBERS.
int GreatestOf3Numbers(void) {
    int firstNumber, secondNumber, thirdNumber;
    cout << "Enter the first number: ";
    cin >> firstNumber;
    cout << "Enter the second number: ";
    cin >> secondNumber;
    cout << "Enter the third number: ";
    cin >> thirdNumber;
    int greatestNumber = max({firstNumber, secondNumber, thirdNumber});
    cout << "The greatest of the three numbers is: " << greatestNumber << endl;

    return 0;


}
// 2. WAP TO CALCULATE FACTORIAL OF A NUMBER
int calculateFactorialOfNumber(void) {
    int inputNumber;
    cout << "Enter a non-negative integer: ";
    cin >> inputNumber;
    if (inputNumber < 0) {
        cout << "Error: Factorial is not defined for negative numbers." << endl;
        return 1; 
    }
    unsigned long long factorialResult = 1;
    for (int counter = 1; counter <= inputNumber; ++counter) {
        factorialResult *= counter;
    }
    cout << "The factorial of " << inputNumber << " is: " << factorialResult << endl;
    return 0;
}
// 3.WAP TO PRINT FIBONACCI SERIES OF 'n' NUMBERS, WHERE N IS GIVEN BY THE PROGRAMMER
int printFibonacciSeriesOfNTerm(void) {
int numberOfTerms;
    cout << "Enter the number of terms you want to generate: ";
    cin >> numberOfTerms;
    if (numberOfTerms <= 0) {
        cout << "Error: The number of terms must be greater than 0." << endl;
        return 1; 
    }
    cout << "Fibonacci series for the first " << numberOfTerms << " terms:" << endl;
    unsigned long long firstTerm = 0;
    unsigned long long secondTerm = 1;
    if (numberOfTerms >= 1) {
        cout << firstTerm;
    }
    if (numberOfTerms >= 2) {
        cout << ", " << secondTerm;
    }
    for (int termCounter = 3; termCounter <= numberOfTerms; ++termCounter) {
        unsigned long long nextTerm = firstTerm + secondTerm;
        cout << ", " << nextTerm;
        firstTerm = secondTerm;
        secondTerm = nextTerm;
    }
    cout << endl;
    return 0;
}
// 4.WAP TO CHECK WHETHER A NUMBER IS PRIME OR NOT
int checkIfGivenNumberIsPrime(void){
   int inputNumber;
    cout << "Enter a positive integer to check: ";
    cin >> inputNumber;
    if (inputNumber <= 1) {
        cout << inputNumber << " is not a prime number." << endl;
        return 0;
    }
    bool isPrime = true;
    for (int currentDivisor = 2; currentDivisor <= sqrt(inputNumber); ++currentDivisor) {
        if (inputNumber % currentDivisor == 0) {
            isPrime = false;
            break;
        }
    }
    if (isPrime) {
        cout << inputNumber << " is a prime number." << endl;
    } else {
        cout << inputNumber << " is not a prime number." << endl;
    }
    return 0;
}
// 5. WAP TO COUNT CHARACTERS IN A STRING.
int countTotalCharactersInGivenString(void) {
    string inputString;
    cout << "Enter a line of text: ";
    getline(cin, inputString);
    int totalCharacterCount = inputString.length();
    cout << "The total number of characters (including spaces) is: " << totalCharacterCount << endl;
    return 0;
}
// 6.WAP TO READ A SET OF NUMBERS IN AN ARRAY AND TO FIND THE LARGEST OF THEM.
int findLargestNumberInGivenArray(void) {
    int totalElements;
    cout << "Enter the number of elements you want to store: ";
    cin >> totalElements;

    if (totalElements <= 0) {
        cout << "Error: The number of elements must be greater than 0." << endl;
        return 1; 
    }
    vector<int> numbersList(totalElements);
    cout << "Enter " << totalElements << " numbers:" << endl;
    for (int elementIndex = 0; elementIndex < totalElements; ++elementIndex) {
        cout << "Element " << (elementIndex + 1) << ": ";
        cin >> numbersList[elementIndex];
    }
    auto largestElementIterator = max_element(numbersList.begin(), numbersList.end());
    int largestNumber = *largestElementIterator; // Dereference the iterator to get the actual value
    cout << "\nThe largest number in the array is: " << largestNumber << endl;
    return 0;
}
// 7.WAP TO IMPLEMENT BUBBLE SORT USING ARRAYS.
int sortArrayUsingBubbleSortAlgorithm(void) {
    const int MAXIMUM_CAPACITY = 100;
    int numbersArray[MAXIMUM_CAPACITY];
    int totalElements;
    cout << "Enter the number of elements to sort (Maximum " << MAXIMUM_CAPACITY << "): ";
    cin >> totalElements;
    if (totalElements <= 0 || totalElements > MAXIMUM_CAPACITY) {
        cout << "Error: Invalid number of elements. Must be between 1 and " << MAXIMUM_CAPACITY << "." << endl;
        return 1;
    }
    cout << "Enter " << totalElements << " numbers to populate the array:" << endl;
    for (int elementIndex = 0; elementIndex < totalElements; ++elementIndex) {
        cout << "Element " << (elementIndex + 1) << ": ";
        cin >> numbersArray[elementIndex];
    }
    for (int passCounter = 0; passCounter < totalElements - 1; ++passCounter) {
        bool isSwapped = false;

        for (int elementIndex = 0; elementIndex < totalElements - passCounter - 1; ++elementIndex) {
            if (numbersArray[elementIndex] > numbersArray[elementIndex + 1]) {
                int temporaryHolder = numbersArray[elementIndex];
                numbersArray[elementIndex] = numbersArray[elementIndex + 1];
                numbersArray[elementIndex + 1] = temporaryHolder;
                
                isSwapped = true; 
            }
        }
        if (!isSwapped) {
            break;
        }
    }
    cout << "\nThe array sorted in ascending order is:" << endl;
    for (int elementIndex = 0; elementIndex < totalElements; ++elementIndex) {
        cout << numbersArray[elementIndex] << " ";
    }
    cout << endl;
    return 0;
}
// 8.WAP TO READ A SET OF NUMBERS FROM KEYBOARD AND TO FIND SUM OF ALL ELEMENTS OF THE GIVEN ARRAY USING A FUNCTION
int calculateSumOfElements(const int numbersArray[], int totalElements) {
    int totalSum = 0;
    for (int elementIndex = 0; elementIndex < totalElements; ++elementIndex) {
        totalSum += numbersArray[elementIndex];
    }
    return totalSum;
}

int calculateSumOfElementsFunctionToCall() {
    int totalElements;
    cout << "Enter the number of elements you want to store: ";
    cin >> totalElements;
    if (totalElements <= 0) {
        cout << "Error: The number of elements must be greater than 0." << endl;
        return 1;
    }
    unique_ptr<int[]> userNumbers = make_unique<int[]>(totalElements);
    cout << "Enter " << totalElements << " numbers:" << endl;
    for (int elementIndex = 0; elementIndex < totalElements; ++elementIndex) {
        cout << "Element " << (elementIndex + 1) << ": ";
        cin >> userNumbers[elementIndex]; // Smart pointers support standard array indexing
    }
    int finalSumResult = calculateSumOfElements(userNumbers.get(), totalElements);
    cout << "\nThe sum of all elements in the array is: " << finalSumResult << endl;
    return 0;
}
int main(void){

    // printFibonacciSeriesOfNTerm();
    // printFibonacciSeriesOfNTerm(); 
    // checkIfGivenNumberIsPrime();
    // countTotalCharactersInGivenString();
    // findLargestNumberInGivenArray();
    return 0;
}
