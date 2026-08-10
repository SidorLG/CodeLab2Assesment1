#include <iostream> // Provides input and output operations such as cin and cout
#include <iomanip> // Provides fixed and setprecision for formatting the result
#include <string> // Provides the string data type
#include <cctype> // Provides tolower for converting characters to lowercase

using namespace std;

// Gets the distance travelled from the user.
// The input must be a valid non-negative number.
double getDistance()
{
    double miles;

    cout << "Enter distance travelled (miles): ";

    // Keep asking until the user enters a valid number.
    while (true)
    {
        if (cin >> miles && miles >= 0)
            return miles;

        cout << "Invalid distance. Please enter a positive number: ";

        // Clears the input error so another value can be entered.
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// Gets the fuel type from the user.
// Both the full fuel names and their first letters are accepted.
string getFuelType()
{
    string fuel;

    cout << "Enter fuel type (diesel/petrol): ";
    cin >> fuel;

    // Convert the input to lowercase so capital letters do not matter.
    for (char& c : fuel)
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));

    // Keep asking until a recognised fuel type is entered.
    while (fuel != "diesel" && fuel != "petrol" &&
           fuel != "d" && fuel != "p")
    {
        cout << "Please enter diesel or petrol: ";
        cin >> fuel;

        // Convert the new input to lowercase as well.
        for (char& c : fuel)
            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }

    // Allow the shorter D and P inputs as alternatives.
    if (fuel == "d")
        return "diesel";

    if (fuel == "p")
        return "petrol";

    return fuel;
}

// Calculates the estimated CO2 emissions based on
// the distance travelled and the selected fuel type.
double calculateCO2(double miles, string fuel)
{
    // Convert the distance into litres of fuel used
    // using the fuel consumption formula.
    double litres = (miles / 100.0) * 9.66;

    // Diesel and petrol have different CO2 emission factors.
    if (fuel == "diesel")
        return litres * 2.68;
    else
        return litres * 2.31;
}

int main()
{
    // Get and validate the distance entered by the user.
    double distance = getDistance();

    // Get and validate the selected fuel type.
    string fuel = getFuelType();

    // Format the final result to exactly two decimal places.
    cout << fixed << setprecision(2);

    // Calculate and display the estimated CO2 emissions.
    cout << "Estimated CO2 emissions: "
         << calculateCO2(distance, fuel)
         << " kg" << endl;

    return 0; // End the program successfully
}