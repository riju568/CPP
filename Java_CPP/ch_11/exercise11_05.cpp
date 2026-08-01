#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <exception>

class Course {
private:
    std::string courseName;
    std::vector<std::string> students;

public:
    explicit Course(std::string name) : courseName(std::move(name)) {}

    void addStudent(const std::string& student) {
        students.push_back(student);
    }

    [[nodiscard]] const std::vector<std::string>& getStudents() const noexcept {
        return students;
    }

    [[nodiscard]] std::size_t getNumberOfStudents() const noexcept {
        return students.size();
    }

    [[nodiscard]] std::string getCourseName() const {
        return courseName;
    }

    void dropStudent(const std::string& student) {
        auto it = std::find(students.begin(), students.end(), student);
        if (it != students.end()) {
            students.erase(it);
            std::cout << "Dropped student: " << student << '\n';
        } else {
            std::cout << "Student not found in course: " << student << '\n';
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(true);
    std::cin.tie(nullptr);

    try {
        Course course("Linear Algebra");
        std::string studentName = "Bob Bobberton";
        std::string studentName2 = "Tori Toriton";
        std::string studentName3 = "Kelly Kellyton";
        std::string studentName4 = "Tod Todderton";
        course.addStudent(studentName);
        course.addStudent(studentName2);
        course.addStudent(studentName3);
        course.addStudent(studentName4);
        std::cout << "Course Name: " << course.getCourseName() << '\n';
        std::cout << "Enrolled students: " << course.getNumberOfStudents() << '\n';
        course.dropStudent(studentName);
        std::cout << "Remaining students (" << course.getNumberOfStudents() << "):\n";
        for (const auto& student : course.getStudents()) {
            std::cout << "- " << student << '\n';
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "An unknown non-standard exception occurred.\n";
        return 2;
    }

    return 0;
}