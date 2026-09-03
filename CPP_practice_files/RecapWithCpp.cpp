#include <iostream> // for Input output cin>> and <<cout
#include <algorithm> // Required for std::max
#include <cmath> // Required for the sqrt() function
#include <string> // Required for using the std::string class
#include <vector>    // Required for dynamic arrays (vectors)
#include <memory> // Required for smart pointers (std::unique_ptr)
#include <cstring> //C-style strings and raw memory blocks replacement of C-style strings and raw memory blocks
#include <iomanip> // (input/output manipulator) header in C++
#include <fstream> // header in C++ is essential for file input and output operations

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
// 15.WAP TO GENERATE A SERIES OF FIBONACCI NUMBERS USING COPY CONSTRUCTOR WHERE IT IS DEFINED THE CLASS USING SCOPE RESOLUTION OPERATOR.
class FibonacciGenerator {
private:
    int limit;
    std::unique_ptr<std::vector<int>> series;

public:
    FibonacciGenerator(int n);
    FibonacciGenerator(const FibonacciGenerator& other);
    void generate();
    void display() const;
    ~FibonacciGenerator() = default;
};
FibonacciGenerator::FibonacciGenerator(int n) : limit(n) {
    series = std::make_unique<std::vector<int>>();
}
FibonacciGenerator::FibonacciGenerator(const FibonacciGenerator& other) {
    this->limit = other.limit;
    if (other.series) {
        this->series = std::make_unique<std::vector<int>>(*other.series);
    } else {
        this->series = std::make_unique<std::vector<int>>();
    }
}

void FibonacciGenerator::generate() {
    if (limit <= 0) return;
    series->clear();
    if (limit >= 1) series->push_back(0);
    if (limit >= 2) series->push_back(1);
    for (int i = 2; i < limit; ++i) {
        int nextTerm = series->at(i - 1) + series->at(i - 2);
        series->push_back(nextTerm);
    }
}
void FibonacciGenerator::display() const {
    if (!series || series->empty()) {
        std::cout << "Series is empty." << std::endl;
        return;
    }
    for (int num : *series) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int FibonacciOutput() {
    int terms;
    std::cout << "Enter the number of terms for the Fibonacci series: ";
    if (!(std::cin >> terms) || terms < 0) {
        std::cerr << "Invalid input!" << std::endl;
        return 1;
    }
    FibonacciGenerator original(terms);
    original.generate();
    std::cout << "Original Series: ";
    original.display();
    FibonacciGenerator clone = original; 
    std::cout << "Cloned Series (via Copy Constructor): ";
    clone.display();

    return 0;
}
// 16.WAP TO ADD TWO COMPLEX NUMBERS WITH A FRIEND FUNCTION
class Complex {
private:
    std::unique_ptr<double> real;
    std::unique_ptr<double> imag;

public:
    Complex(double r = 0.0, double i = 0.0);
    Complex(const Complex& other);
    void display() const;
    friend Complex add(const Complex& c1, const Complex& c2);
    ~Complex() = default;
};

Complex::Complex(double r, double i) {
    real = std::make_unique<double>(r);
    imag = std::make_unique<double>(i);
}

Complex::Complex(const Complex& other) {
    this->real = std::make_unique<double>(*other.real);
    this->imag = std::make_unique<double>(*other.imag);
}

void Complex::display() const {
    std::cout << *real << " + " << *imag << "i" << std::endl;
}
Complex add(const Complex& c1, const Complex& c2) {
    double totalReal = *(c1.real) + *(c2.real);
    double totalImag = *(c1.imag) + *(c2.imag);
    return Complex(totalReal, totalImag);
}

int Add2ComplexNumber() {
    double r1, i1, r2, i2;
    std::cout << "Enter Real and Imaginary part for Number 1: ";
    if (!(std::cin >> r1 >> i1)) return 1;
    std::cout << "Enter Real and Imaginary part for Number 2: ";
    if (!(std::cin >> r2 >> i2)) return 1;
    Complex num1(r1, i1);
    Complex num2(r2, i2);
    std::cout << "\nNumber 1: ";
    num1.display();
    std::cout << "Number 2: ";
    num2.display();
    Complex result = add(num1, num2);
    std::cout << "Sum     : ";
    result.display();

    return 0;
}
// 17. WRITE A CLASS STRING TO COMPARE TWO STRINGS, OVERLOAD(==) OPERATOR.
class String {
private:
    std::unique_ptr<char[]> data;
    size_t length;
public:
    String(const char* str = "");
    String(const String& other);
    bool operator==(const String& other) const;
    void display() const;
    ~String() = default;
};
String::String(const char* str) {
    if (str == nullptr) {
        length = 0;
        data = std::make_unique<char[]>(1);
        data[0] = '\0';
    } else {
        length = std::strlen(str);
        data = std::make_unique<char[]>(length + 1);
        std::strcpy(data.get(), str);
    }
}
String::String(const String& other) {
    this->length = other.length;
    this->data = std::make_unique<char[]>(this->length + 1);
    std::strcpy(this->data.get(), other.data.get());
}
bool String::operator==(const String& other) const {
    if (this->length != other.length) {
        return false;
    }
    return std::strcmp(this->data.get(), other.data.get()) == 0;
}
void String::display() const {
    if (data) {
        std::cout << data.get();
    }
}

int StringToCompare2Strings() {
    char buffer1[256];
    char buffer2[256];
    std::cout << "Enter the first string: ";
    std::cin.getline(buffer1, 256);
    std::cout << "Enter the second string: ";
    std::cin.getline(buffer2, 256);
    String s1(buffer1);
    String s2(buffer2);
    std::cout << "\nString 1: \""; s1.display(); std::cout << "\"\n";
    std::cout << "String 2: \""; s2.display(); std::cout << "\"\n";
    if (s1 == s2) {
        std::cout << "\nResult: The strings are EQUAL." << std::endl;
    } else {
        std::cout << "\nResult: The strings are NOT EQUAL." << std::endl;
    }

    return 0;
}
// 19.CREATE A CLASS ITEM, HAVING TWO DATA MEMBERS X & Y, OVERLOAD '-'(UNARY OPERATOR) TO CHANGE THE SIGN OF X AND Y.

class Item {
private:
    int x;
    int y;
public:
    Item(int initialX, int initialY) : x(initialX), y(initialY) {}

    void operator-() {
        x = -x;
        y = -y;
    }

    void display() const {
        std::cout << "X = " << x << ", Y = " << y << "\n";
    }
};
int ChangeTheSign() {
    Item myItem(15, -30);
    std::cout << "Original values:\n";
    myItem.display();
    -myItem;
    std::cout << "\nAfter applying unary '-' operator:\n";
    myItem.display();
    return 0;
}
// 20. CREATE A CLASS EMPLOYEE. DERIVE 3 CLASSES FROM THIS CLASS NAMELY, PROGRAMMER, ANALYST & PROJECT LEADER. TAKE ATTRIBUTES AND OPERATIONS ON YOUR OWN. WAP TO IMPLEMENT THIS WITH ARRAY OF POINTERS.



class Employee {
protected:
    int empID;
    std::string name;
    double basicSalary;

public:
    Employee(int id, const std::string& empName, double salary)
        : empID(id), name(empName), basicSalary(salary) {}

    virtual ~Employee() {}

    virtual void displayDetails() const = 0;
    virtual double calculateTotalSalary() const = 0;
};

class Programmer : public Employee {
private:
    std::string primaryLanguage;
    double codingAllowance;

public:
    Programmer(int id, const std::string& empName, double salary, 
               const std::string& lang, double allowance)
        : Employee(id, empName, salary), primaryLanguage(lang), codingAllowance(allowance) {}

    double calculateTotalSalary() const override {
        return basicSalary + codingAllowance;
    }

    void displayDetails() const override {
        std::cout << "[Programmer] ID: " << empID << " | Name: " << name 
                  << " | Lang: " << primaryLanguage 
                  << " | Total Salary: $" << std::fixed << std::setprecision(2) 
                  << calculateTotalSalary() << std::endl;
    }
};

class Analyst : public Employee {
private:
    std::string specialization;
    double dataBonus;

public:
    Analyst(int id, const std::string& empName, double salary, 
            const std::string& spec, double bonus)
        : Employee(id, empName, salary), specialization(spec), dataBonus(bonus) {}

    double calculateTotalSalary() const override {
        return basicSalary + dataBonus;
    }

    void displayDetails() const override {
        std::cout << "[Analyst]    ID: " << empID << " | Name: " << name 
                  << " | Spec: " << specialization 
                  << " | Total Salary: $" << std::fixed << std::setprecision(2) 
                  << calculateTotalSalary() << std::endl;
    }
};

class ProjectLeader : public Employee {
private:
    int teamSize;
    double leadershipStipend;

public:
    ProjectLeader(int id, const std::string& empName, double salary, 
                  int size, double stipend)
        : Employee(id, empName, salary), teamSize(size), leadershipStipend(stipend) {}

    double calculateTotalSalary() const override {
        return basicSalary + leadershipStipend;
    }

    void displayDetails() const override {
        std::cout << "[Leader]     ID: " << empID << " | Name: " << name 
                  << " | Team: " << teamSize << " members"
                  << " | Total Salary: $" << std::fixed << std::setprecision(2) 
                  << calculateTotalSalary() << std::endl;
    }
};

int employeeDataDisplay() {
    const int NUM_EMPLOYEES = 3;

    Employee* team[NUM_EMPLOYEES];

    team[0] = new Programmer(101, "Alice Smith", 60000, "C++", 5000);
    team[1] = new Analyst(102, "Bob Jones", 65000, "System Architecture", 6000);
    team[2] = new ProjectLeader(103, "Carol Danvers", 80000, 8, 12000);

    std::cout << "================= EMPLOYEE DIRECTORY =================\n";
    
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        team[i]->displayDetails();
    }
    std::cout << "======================================================\n";

    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        delete team[i]; 
        team[i] = nullptr;
    }

    return 0;
}
// 21.CREATE TWO CLASSES NAMELY EMPLOYEE AND QUALIFICATION. USING MULTIPLE INHERITANCE DERIVE TWO CLASSES SCIENTIST AND MANAGER. TAKE SUITABLE ATTRIBUTES & OPERATIONS. WAP TO IMPLEMENT THIS CLASS HIERARCHY same as above
class Employee2 {
protected:
    int empID;
    std::string name;
    double basicSalary;
public:
    Employee2(int id, const std::string& empName, double salary)
        : empID(id), name(empName), basicSalary(salary) {}
    virtual ~Employee2() {}
    virtual void displayDetails() const = 0;
};
class Qualification {
protected:
    std::string highestDegree;
    std::string institute;
    int passingYear;

public:
    Qualification(const std::string& degree, const std::string& inst, int year)
        : highestDegree(degree), institute(inst), passingYear(year) {}

    virtual ~Qualification() {}

    void displayQualification() const {
        std::cout << "  -> Academic: " << highestDegree << " from " 
                  << institute << " (" << passingYear << ")\n";
    }
};
class Scientist : public Employee2, public Qualification {
private:
    std::string researchDomain;
    int publicationsCount;

public:
    Scientist(int id, const std::string& empName, double salary,
              const std::string& degree, const std::string& inst, int year,
              const std::string& domain, int publications)
        : Employee2(id, empName, salary),          // Initialize Base 1
          Qualification(degree, inst, year),       // Initialize Base 2
          researchDomain(domain), publicationsCount(publications) {}

    void displayDetails() const override {
        std::cout << "[Scientist] ID: " << empID << " | Name: " << name 
                  << " | Salary: $" << std::fixed << std::setprecision(2) << basicSalary << "\n";
        displayQualification(); // Calling method from Base 2
        std::cout << "  -> Research: " << researchDomain 
                  << " | Publications: " << publicationsCount << "\n\n";
    }
};
class Manager : public Employee2, public Qualification {
private:
    std::string department;
    int teamSize;

public:
    Manager(int id, const std::string& empName, double salary,
            const std::string& degree, const std::string& inst, int year,
            const std::string& dept, int team)
        : Employee2(id, empName, salary),          // Initialize Base 1
          Qualification(degree, inst, year),       // Initialize Base 2
          department(dept), teamSize(team) {}

    void displayDetails() const override {
        std::cout << "[Manager]   ID: " << empID << " | Name: " << name 
                  << " | Salary: $" << std::fixed << std::setprecision(2) << basicSalary << "\n";
        displayQualification(); // Calling method from Base 2
        std::cout << "  -> Dept: " << department 
                  << " | Team Size: " << teamSize << " members\n\n";
    }
};
int employeeHIERARCHY() {
    const int SIZE = 2;
    Employee2* staff[SIZE];
    staff[0] = new Scientist(201, "Dr. Aris Thorne", 95000, 
                             "Ph.D. in Astrophysics", "MIT", 2018, 
                             "Quantum Cosmology", 14);

    staff[1] = new Manager(202, "Elena Rostova", 88000, 
                           "MBA", "Harvard Business School", 2015, 
                           "R&D Operations", 25);

    std::cout << "================ MULTIPLE INHERITANCE DIRECTORY ================\n\n";
    for (int i = 0; i < SIZE; ++i) {
        staff[i]->displayDetails();
    }
    std::cout << "================================================================\n";
    for (int i = 0; i < SIZE; ++i) {
        delete staff[i]; 
        staff[i] = nullptr;
    }

    return 0;
}
// 22.WAP TO READ DATA FROM FROM KEYWORD & WRITE IT TO THE FILE. AFTER WRITING IS COMPLETED, THE FILE IS CLOSED. THE PROGRAM AGAIN OPENS THE SAME FILE, READS.same as above

int dataToFileAndRead() {

    const std::string filename = "user_data.txt";
    std::string inputData;

    std::cout << "\n--- STEP 1: WRITE TO FILE ---\n";
    std::cout << "Enter a sentence or paragraph to save to the file:\n> ";
    
    std::getline(std::cin, inputData);

    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file for writing!\n";
        return 1;
    }

    outFile << inputData << std::endl;

    outFile.close();
    std::cout << "Data successfully saved to '" << filename << "' and file closed.\n\n";

    std::cout << "--- STEP 2: READ FROM FILE ---\n";
    
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file for reading!\n";
        return 1;
    }

    std::cout << "Contents read from '" << filename << "':\n";
    std::cout << "----------------------------------------\n";

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
    std::cout << "----------------------------------------\n";

    inFile.close();
    std::cout << "File read complete and file closed.\n";

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
    // Add2ComplexNumber() ;
    // StringToCompare2Strings();
    //  FibonacciOutput();
    // ChangeTheSign();
    // employeeDataDisplay();
    // employeeHIERARCHY();
    // dataToFileAndRead();
    
    return 0;
}
