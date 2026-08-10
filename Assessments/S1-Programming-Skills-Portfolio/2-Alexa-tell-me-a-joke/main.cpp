#include <iostream> // Provides input and output functions such as cin and cout
#include <fstream> // Allows the program to read the joke file
#include <string> // Provides the string data type
#include <vector> // Stores the collection of jokes
#include <utility> // Provides pair for storing the setup and punchline together
#include <cstdlib> // Provides rand() and srand() for random selection
#include <ctime> // Provides time() for seeding the random number generator
#include <cctype> // Provides tolower() for converting input to lowercase

using namespace std;

// cleanInput removes extra whitespace and converts the user's command to lowercase.
string cleanInput(string input) // Receives the user's command as a string
{
    size_t start = input.find_first_not_of(" \t\r\n"); // Finds the first non-space character
    size_t end = input.find_last_not_of(" \t\r\n"); // Finds the last non-space character
    if (start == string::npos) // Checks if the input contains only spaces
        return ""; // Returns an empty string if there is no actual input
    input = input.substr(start, end - start + 1); // Removes spaces from the beginning and end
    for (char& c : input) // Goes through each character in the command
        c = static_cast<char>(tolower(static_cast<unsigned char>(c))); // Converts each character to lowercase
    return input; // Returns the cleaned command
}

// loadJokes reads jokes from the file and separates each one into a setup and punchline.
bool loadJokes(const string& filename, vector<pair<string, string>>& jokes) // Loads jokes into the vector
{
    ifstream file(filename); // Opens the joke file for reading
    if (!file.is_open()) // Checks whether the file opened successfully
    {
        cerr << "Error: Could not open jokes file." << endl; // Displays an error if the file cannot be opened
        return false; // Tells the program that loading failed
    }
    string line; // Stores one line from the joke file
    while (getline(file, line)) // Reads the file one line at a time
    {
        if (line.empty()) continue; // Skips empty lines
        size_t questionMark = line.find('?'); // Finds the question mark separating the setup and punchline
        if (questionMark != string::npos && questionMark + 1 < line.length()) // Checks that a valid joke was found
        {
            string setup = line.substr(0, questionMark + 1); // Extracts the setup including the question mark
            string punchline = line.substr(questionMark + 1); // Extracts the punchline after the question mark
            jokes.push_back(make_pair(setup, punchline)); // Stores both parts together in the vector
        }
    }
    file.close(); // Closes the file after all jokes have been loaded
    return !jokes.empty(); // Returns true if at least one joke was loaded
}

// tellRandomJoke selects a random joke and controls the setup and punchline interaction.
void tellRandomJoke(const vector<pair<string, string>>& jokes) // Receives the vector of jokes
{
    int index = rand() % jokes.size(); // Generates a random index within the vector
    cout << jokes[index].first << endl; // Displays the setup of the selected joke
    cout << "(Press Enter for the punchline)"; // Asks the user to press Enter
    cin.get(); // Waits for the user to press Enter
    cout << jokes[index].second << endl << endl; // Displays the punchline
}

int main() // Main function where the program starts
{
    // Initialize random number generator for selecting jokes.
    srand(static_cast<unsigned int>(time(0))); // Uses the current time to create different random results
    vector<pair<string, string>> jokes; // Creates a vector containing setup and punchline pairs

    // Load jokes from the text file before starting the user loop.
    if (!loadJokes("randomJokes.txt", jokes)) // Attempts to load the jokes from the file
    {
        cerr << "Failed to load jokes. Exiting." << endl; // Displays an error if loading failed
        return 1; // Stops the program with an error code
    }

    cout << "Say \"Alexa, tell me a joke\" to hear a joke," // Displays the first part of the instructions
         << " or type \"quit\" to exit." << endl; // Displays the second part of the instructions

    while (true) // Keeps the program running until the user chooses to quit
    {
        cout << "\nYour command: "; // Asks the user to enter a command
        string command; // Stores the command entered by the user
        getline(cin, command); // Reads the complete command including spaces

        // Cleans the command so capital letters and extra spaces do not affect the comparison.
        command = cleanInput(command); // Calls the input-cleaning function
        if (command == "quit") // Checks if the user wants to exit
        {
            cout << "Goodbye!" << endl; // Displays the exit message
            break; // Ends the while loop
        }
        if (command == "alexa, tell me a joke" || // Checks the command with a comma
            command == "alexa tell me a joke") // Also accepts the command without a comma
        {
            tellRandomJoke(jokes); // Calls the function to select and display a random joke
        }
        else // Runs when the command is not recognised
        {
            cout << "I don't understand that command." << endl; // Informs the user of an invalid command
        }
    }
    return 0; // Ends the program successfully
}