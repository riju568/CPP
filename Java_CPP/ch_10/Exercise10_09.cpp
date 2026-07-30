#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <exception>
#include <cstdlib>

/**
 * **10.9 (The Course class) Revise the Course class as follows:
 * ■ The array size is fixed in Listing 10.6. Improve it to automatically increase
 * the array size by creating a new larger array and copying the contents of the
 * current array to it.
 * ■ Implement the dropStudent method.
 * ■ Add a new method named clear() that removes all students from the
 * course.
 */
class Course
{
private:
    std::string course_name;
    std::size_t capacity;
    std::size_t number_of_students;
    std::unique_ptr<std::string[]> students;

    void expand_capacity()
    {
        std::size_t new_capacity = capacity * 2;
        auto new_students = std::make_unique<std::string[]>(new_capacity);

        for (std::size_t i = 0; i < number_of_students; ++i)
        {
            new_students[i] = std::move(students[i]);
        }
        students = std::move(new_students);
        capacity = new_capacity;
    }

public:
    explicit Course(std::string name, std::size_t initial_capacity = 16)
        : course_name(std::move(name)), 
          capacity(initial_capacity), 
          number_of_students(0), 
          students(std::make_unique<std::string[]>(initial_capacity)) {}

    void add_student(const std::string &student)
    {
        if (number_of_students >= capacity)
        {
            expand_capacity();
        }
        students[number_of_students] = student;
        ++number_of_students;
        std::cout << "Added student: " << student << " to the course: " << course_name << '\n';
    }
    void drop_student(const std::string &student)
    {
        for (std::size_t i = 0; i < number_of_students; ++i)
        {
            if (students[i] == student)
            {
                for (std::size_t j = i; j < number_of_students - 1; ++j)
                {
                    students[j] = std::move(students[j + 1]);
                }
                --number_of_students;
                students[number_of_students].clear(); // Reset trailing element
                
                std::cout << "Dropped student: " << student << " from " << course_name << '\n';
                return;
            }
        }
        std::cout << "Student " << student << " not found in " << course_name << '\n';
    }

    void clear() noexcept
    {
        for (std::size_t i = 0; i < number_of_students; ++i)
        {
            students[i].clear();
        }
        number_of_students = 0;
    }
    [[nodiscard]] std::size_t get_number_of_students() const noexcept
    {
        return number_of_students;
    }

    [[nodiscard]] std::string get_course_name() const
    {
        return course_name;
    }
    [[nodiscard]] const std::string* get_students() const noexcept
    {
        return students.get();
    }
};

int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);
        Course statistics("Statistics 341");
        statistics.add_student("Jillian Frometorgai");
        statistics.add_student("Shrezen Maticut");
        statistics.add_student("Phi Wazi");
        statistics.drop_student("Jillian Frometorgai");
        std::cout << "\nStudents in the course " << statistics.get_course_name() << " are:\n";
        const std::string* active_students = statistics.get_students();
        for (std::size_t i = 0; i < statistics.get_number_of_students(); ++i)
        {
            std::cout << active_students[i] << (i + 1 < statistics.get_number_of_students() ? ", " : "\n");
        }
        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
}