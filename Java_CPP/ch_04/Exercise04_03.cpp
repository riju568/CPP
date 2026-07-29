#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <exception>
#include <cstdlib>

class Triangle
{
private:
    double side1{0.0};
    double side2{0.0};
    double side3{0.0};
    double area{0.0};

public:
    Triangle(double s1, double s2, double s3)
        : side1(s1), side2(s2), side3(s3), area(0.0) {}

    void computeArea()
    {
        double s = (side1 + side2 + side3) / 2.0;
        area = std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    [[nodiscard]] double getArea() const
    {
        return area;
    }

    void setArea(double a)
    {
        area = a;
    }
};

constexpr double PI = 3.14159265358979323846;

constexpr double to_radians(double degrees)
{
    return degrees * PI / 180.0;
}

double add_two_triangles(const Triangle &t1, const Triangle &t2)
{
    return t1.getArea() + t2.getArea();
}

/**
 * 4.3 (Geography: estimate areas) Find the GPS locations for Atlanta, Georgia;
 * Orlando, Florida; Savannah, Georgia; and Charlotte, North Carolina...
 */
int main()
{
    try
    {
        std::ios_base::sync_with_stdio(true);
        std::cin.tie(nullptr);

        constexpr double RADIUS = 6371.01; // Mean radius of Planet Earth in km

        // Coordinates (Longitude, Latitude) converted to radians
        // Atlanta: (-84.2782200, 33.8901000)
        // Orlando: (-81.5197542, 28.4283959)
        // Savannah: (-81.1746100, 32.1081500)
        // Charlotte: (-80.9567600, 35.2072400)

        double atl_lon1 = to_radians(-84.2782200);
        double atl_lat1 = to_radians(33.8901000);

        double orl_lon = to_radians(-81.5197542);
        double orl_lat = to_radians(28.4283959);

        double sav_lon = to_radians(-81.1746100);
        double sav_lat = to_radians(32.1081500);

        double cha_lon = to_radians(-80.9567600);
        double cha_lat = to_radians(35.2072400);

        // Triangle 1: Atlanta, Charlotte, Savannah
        double atl_to_cha = RADIUS * std::acos(std::sin(atl_lat1) * std::sin(cha_lat) +
                                               std::cos(atl_lat1) * std::cos(cha_lat) * std::cos(atl_lon1 - cha_lon));

        double cha_to_sav = RADIUS * std::acos(std::sin(cha_lat) * std::sin(sav_lat) +
                                               std::cos(cha_lat) * std::cos(sav_lat) * std::cos(cha_lon - sav_lon));

        double sav_to_atl = RADIUS * std::acos(std::sin(sav_lat) * std::sin(atl_lat1) +
                                               std::cos(sav_lat) * std::cos(atl_lat1) * std::cos(sav_lon - atl_lon1));

        Triangle triangle1(atl_to_cha, cha_to_sav, sav_to_atl);
        triangle1.computeArea();

        // Triangle 2: Savannah, Orlando, Atlanta
        double sav_to_orl = RADIUS * std::acos(std::sin(sav_lat) * std::sin(orl_lat) +
                                               std::cos(sav_lat) * std::cos(orl_lat) * std::cos(sav_lon - orl_lon));

        double orl_to_atl = RADIUS * std::acos(std::sin(orl_lat) * std::sin(atl_lat1) +
                                               std::cos(orl_lat) * std::cos(atl_lat1) * std::cos(orl_lon - atl_lon1));

        Triangle triangle2(sav_to_orl, orl_to_atl, sav_to_atl);
        triangle2.computeArea();

        double area_of_polygon = add_two_triangles(triangle1, triangle2);

        std::cout << "Using the Great Circle calculation, the estimated area enclosed by \n"
                  << "Atlanta, Charlotte, Savannah, and Orlando is "
                  << std::fixed << std::setprecision(4) << area_of_polygon << " sq km\n";

        return EXIT_SUCCESS;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Execution error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred during execution.\n";
        return EXIT_FAILURE;
    }
}