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
// 9.WAP TO SWAP VARIABLE USING CALL BY VALUE 
void swapUsingCallByValue(int firstValue, int secondValue) {
    int temporaryHolder = firstValue;
    firstValue = secondValue;
    secondValue = temporaryHolder;
    cout << "\n[Inside Function] Swapping completed!" << endl;
    cout << "First Value = " << firstValue << ", Second Value = " << secondValue << endl;
}
int swapUsingCallByValueMainFunction() {
    int firstNumber, secondNumber;
    cout << "Enter the first number: ";
    cin >> firstNumber;
    cout << "Enter the second number: ";
    cin >> secondNumber;
    cout << "\n[Inside Main] Before calling the swap function:" << endl;
    cout << "First Number = " << firstNumber << ", Second Number = " << secondNumber << endl;
    swapUsingCallByValue(firstNumber, secondNumber);
    cout << "\n[Inside Main] After returning from the swap function:" << endl;
    cout << "First Number = " << firstNumber << ", Second Number = " << secondNumber << endl;

    return 0;
}

// 10.WAP TO SWAP VARIABLES USING CALL BY REFERENCE
void swapUsingCallByReference(int &firstReference, int &secondReference) {
    int temporaryHolder = firstReference;
    firstReference = secondReference;
    secondReference = temporaryHolder;
    cout << "\n[Inside Function] Swapping completed!" << endl;
    cout << "First Reference = " << firstReference << ", Second Reference = " << secondReference << endl;
}
int swapUsingCallByReferenceFunctionToCall() {
    int firstNumber, secondNumber;
    cout << "Enter the first number: ";
    cin >> firstNumber;
    cout << "Enter the second number: ";
    cin >> secondNumber;
    cout << "\n[Inside Main] Before calling the swap function:" << endl;
    cout << "First Number = " << firstNumber << ", Second Number = " << secondNumber << endl;
    swapUsingCallByReference(firstNumber, secondNumber);
    cout << "\n[Inside Main] After returning from the swap function:" << endl;
    cout << "First Number = " << firstNumber << ", Second Number = " << secondNumber << endl;

    return 0;
}
// 11.WAP TO FIND THE SUM OF THREE NUMBERS USING POINTER TO FUNCTION METHOD
int calculateSumOfThreeNumbers(int firstNumber, int secondNumber, int thirdNumber) {
    return firstNumber + secondNumber + thirdNumber;
}

int calculateSumOfThreeNumbersOuputFunction() {
    int firstNumber, secondNumber, thirdNumber;
    cout << "Enter the first number: ";
    cin >> firstNumber;
    cout << "Enter the second number: ";
    cin >> secondNumber;
    cout << "Enter the third number: ";
    cin >> thirdNumber;
    int (*sumOperationPointer)(int, int, int) = calculateSumOfThreeNumbers;
    int totalSumResult = sumOperationPointer(firstNumber, secondNumber, thirdNumber);
    cout << "\nThe sum of the three numbers calculated via function pointer is: " << totalSumResult << endl;
    return 0;
}

// 12.WAP TO DISPLAY CONTENT OF AN ARRAY USING POINTER ARITHMETIC.
int displayArray(void) {
    const int MAXIMUM_CAPACITY = 100;
    int numbersArray[MAXIMUM_CAPACITY];
    int totalElements;

    cout << "Enter the number of elements you want to store (Maximum " << MAXIMUM_CAPACITY << "): ";
    cin >> totalElements;

    if (totalElements <= 0 || totalElements > MAXIMUM_CAPACITY) {
        cout << "Error: Invalid size. Must be between 1 and " << MAXIMUM_CAPACITY << "." << endl;
        return 1;
    }

    cout << "Enter " << totalElements << " numbers:" << endl;
    for (int elementIndex = 0; elementIndex < totalElements; ++elementIndex) {
        cout << "Element " << (elementIndex + 1) << ": ";
        cin >> numbersArray[elementIndex];
    }

    cout << "\nDisplaying array elements using pointer arithmetic:" << endl;

    int* arrayElementPointer = numbersArray;

    for (int trackingCounter = 0; trackingCounter < totalElements; ++trackingCounter) {
        cout << "Address: " << arrayElementPointer 
             << " -> Value: " << *arrayElementPointer << endl;

        arrayElementPointer++;
    }

    return 0;
}
// 13.WAP TO FIND AREA OF CIRCLE, RECTANGLE, SQUARE & TRIANGLE USING FUNCTION OVERLOADING
const double PI_VALUE = 3.141592653589793;
double calculateArea(double radius) {
    return PI_VALUE * radius * radius;
}
float calculateArea(float side) {
    return side * side;
}
double calculateArea(double length, double width) {
    return length * width;
}
float calculateArea(float base, float height) {
    return 0.5f * base * height;
}
int TheMainOutputFunction() {
    int userChoice;
    cout << "Geometric Area Calculator" << endl;
    cout << "1. Circle\n2. Rectangle\n3. Square\n4. Triangle" << endl;
    cout << "Select a shape (1-4): ";
    cin >> userChoice;
    cout << "\n";
    switch (userChoice) {
        case 1: {
            double circleRadius;
            cout << "Enter the radius of the circle: ";
            cin >> circleRadius;
            cout << "Area of the Circle: " << calculateArea(circleRadius) << endl;
            break;
        }
        case 2: {
            double rectangleLength, rectangleWidth;
            cout << "Enter the length of the rectangle: ";
            cin >> rectangleLength;
            cout << "Enter the width of the rectangle: ";
            cin >> rectangleWidth;
            cout << "Area of the Rectangle: " << calculateArea(rectangleLength, rectangleWidth) << endl;
            break;
        }
        case 3: {
            float squareSide;
            cout << "Enter the side length of the square: ";
            cin >> squareSide;
            cout << "Area of the Square: " << calculateArea(squareSide) << endl;
            break;
        }
        case 4: {
            float triangleBase, triangleHeight;
            cout << "Enter the base of the triangle: ";
            cin >> triangleBase;
            cout << "Enter the perpendicular height of the triangle: ";
            cin >> triangleHeight;
            cout << "Area of the Triangle: " << calculateArea(triangleBase, triangleHeight) << endl;
            break;
        }
        default:
            cout << "Error: Invalid menu selection." << endl;
            return 1;
    }
    return 0;
}
// 14. WAP TO DEFINE NESTED CLASS 'STUDENT_INFO' WHICH CONTAINS DATA MEMBERS SUCH AS NAME, ROLL NUMBER AND SEX AND ALSO CONSISTS OF ONE MORE CLASS 'DATE' WHOSE DATA MEMBERS ARE DAY, MONTH AND YEAR. THIS DATA IS TO BE READ FROM THE KEYBOARD & DISPLAYED ON THE SCREEN.
class StudentInfo {
public:
    class Date {
    private:
        int day;
        int month;
        int year;
    public:
        void readDate() {
            cout << "  Enter Day (DD): ";
            cin >> day;
            cout << "  Enter Month (MM): ";
            cin >> month;
            cout << "  Enter Year (YYYY): ";
            cin >> year;
        }
        void displayDate() const {
            cout << (day < 10 ? "0" : "") << day << "/"
                 << (month < 10 ? "0" : "") << month << "/"
                 << year;
        }
    };
private:
    string name;
    int rollNumber;
    char sex;
    Date genericDate;
public:
    void readStudentData() {
        cout << "Enter Student Name: ";
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cout << "Enter Sex (M/F/O): ";
        cin >> sex;
        cout << "\n[Entering Date Details]" << endl;
        genericDate.readDate();
    }
    void displayStudentData() const {
        cout << "\n================ Student Record ================" << endl;
        cout << "Name:        " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Sex:         " << sex << endl;
        cout << "Stored Date: ";
        genericDate.displayDate();
        cout << "\n================================================" << endl;
    }
};
int StudentInfoFunctionToCall() {
    StudentInfo studentRecord;
    cout << "--- Student Information Entry System ---" << endl;
    studentRecord.readStudentData();
    studentRecord.displayStudentData();
    return 0;
}
int main(void){

    // printFibonacciSeriesOfNTerm();
    // printFibonacciSeriesOfNTerm(); 
    // checkIfGivenNumberIsPrime();
    // countTotalCharactersInGivenString();
    // findLargestNumberInGivenArray();
    // swapUsingCallByValueMainFunction();
    // swapUsingCallByReferenceFunctionToCall;
    // StudentInfoFunctionToCall();
    // TheMainOutputFunction();
    // displayArray();
    // calculateSumOfThreeNumbersOuputFunction();
    
    return 0;
}
