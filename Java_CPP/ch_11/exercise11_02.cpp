#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <utility>
#include <exception>


// MyDate Helper Class
class MyDate {
private:
    std::chrono::system_clock::time_point timePoint;

public:
    MyDate() : timePoint(std::chrono::system_clock::now()) {}

    explicit MyDate(std::chrono::system_clock::time_point tp) : timePoint(tp) {}

    [[nodiscard]] std::string toString() const {
        auto timeT = std::chrono::system_clock::to_time_t(timePoint);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&timeT), "%Y-%m-%d");
        return ss.str();
    }
};

// Person Base Class
class Person {
private:
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::string emailAddress;

public:
    Person() = default;

    Person(std::string n, std::string addr, std::string phone, std::string email)
        : name(std::move(n)), address(std::move(addr)),
          phoneNumber(std::move(phone)), emailAddress(std::move(email)) {}

    virtual ~Person() = default;

    [[nodiscard]] std::string getName() const { return name; }
    Person& setName(std::string n) { name = std::move(n); return *this; }

    [[nodiscard]] std::string getAddress() const { return address; }
    Person& setAddress(std::string addr) { address = std::move(addr); return *this; }

    [[nodiscard]] std::string getPhoneNumber() const { return phoneNumber; }
    Person& setPhoneNumber(std::string phone) { phoneNumber = std::move(phone); return *this; }

    [[nodiscard]] std::string getEmailAddress() const { return emailAddress; }
    Person& setEmailAddress(std::string email) { emailAddress = std::move(email); return *this; }

    [[nodiscard]] virtual std::string toString() const {
        return "Person.class: { Name= " + name + " }";
    }
};

// Student Derived Class
class Student : public Person {
private:
    std::string status;

public:
    static inline const std::string FRESHMAN = "freshman";
    static inline const std::string SOPHOMORE = "sophomore";
    static inline const std::string JUNIOR = "junior";
    static inline const std::string SENIOR = "senior";
    explicit Student(std::string st) : status(std::move(st)) {}
    Student(std::string n, std::string addr, std::string phone, std::string email, std::string st)
        : Person(std::move(n), std::move(addr), std::move(phone), std::move(email)), status(std::move(st)) {}

    [[nodiscard]] std::string getStatus() const { return status; }

    [[nodiscard]] std::string toString() const override {
        return "Student.class: { Name= " + getName() + " }";
    }
};

// Employee Derived Class
class Employee : public Person {
private:
    std::string office;
    double salary{0.0};
    MyDate dateHired;

public:
    Employee() = default;

    Employee(std::string off, double sal, MyDate hired)
        : office(std::move(off)), salary(sal), dateHired(std::move(hired)) {}

    Employee(std::string n, std::string addr, std::string phone, std::string email,
             std::string off, double sal, MyDate hired)
        : Person(std::move(n), std::move(addr), std::move(phone), std::move(email)),
          office(std::move(off)), salary(sal), dateHired(std::move(hired)) {}

    [[nodiscard]] std::string getOffice() const { return office; }
    Employee& setOffice(std::string off) { office = std::move(off); return *this; }

    [[nodiscard]] double getSalary() const { return salary; }
    Employee& setSalary(double sal) { salary = std::move(sal); return *this; }

    [[nodiscard]] MyDate getDateHired() const { return dateHired; }
    Employee& setDateHired(MyDate hired) { dateHired = std::move(hired); return *this; }

    [[nodiscard]] std::string toString() const override {
        return "Employee.class: { Name= " + getName() + " }";
    }
};

// Faculty Derived Class
class Faculty : public Employee {
private:
    std::pair<double, double> officeHours{9.0, 17.0};
    int rank{1};

public:
    Faculty(std::pair<double, double> hours, int r)
        : Employee("Philadelphia,PA", 90000.00, MyDate()),
          officeHours(hours), rank(r) {}

    [[nodiscard]] int getRank() const { return rank; }
    Faculty& setRank(int r) { rank = r; return *this; }

    [[nodiscard]] std::pair<double, double> getOfficeHours() const { return officeHours; }
    Faculty& setOfficeHours(std::pair<double, double> hours) { officeHours = hours; return *this; }

    [[nodiscard]] std::string toString() const override {
        return "Faculty.class: { Name= " + getName() + " }";
    }
};


// Staff Derived Class

class Staff : public Employee {
private:
    std::string title;

public:
    Staff(std::string off, double sal, MyDate hired, std::string t)
        : Employee(std::move(off), sal, std::move(hired)), title(std::move(t)) {}

    [[nodiscard]] std::string getTitle() const { return title; }
    Staff& setTitle(std::string t) { title = std::move(t); return *this; }

    [[nodiscard]] std::string toString() const override {
        return "Staff.class: { Name= " + getName() + " }";
    }
};


// Main Function

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        Person person;
        person.setName("Garry Barryman");
        Student student(Student::SENIOR);
        student.setName("Jingle PB&J");
        Employee employee("Delray Beach,FL", 45750.00, MyDate());
        employee.setName("Sarah Stodenbyer");
        Faculty faculty({9.0, 17.0}, 5);
        faculty.setName("Milly Millyman");
        Staff staff("Boston,MA", 750000.00, MyDate(), "CEO");
        staff.setName("Madonna Firehat");
        std::cout << person.toString() << '\n';
        std::cout << student.toString() << '\n';
        std::cout << employee.toString() << '\n';
        std::cout << faculty.toString() << '\n';
        std::cout << staff.toString() << '\n';
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown exception occurred.\n";
        return 2;
    }

    return 0;
}