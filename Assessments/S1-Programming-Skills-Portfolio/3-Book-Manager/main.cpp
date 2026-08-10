#include <iostream> // Provides input and output functions such as cout and cin
#include <fstream> // Allows the program to read from and write to files
#include <sstream> // Allows each line from the file to be split into separate values
#include <string> // Provides the string data type
#include <vector> // Provides the vector container used to store the books
using namespace std;
class Book // Class used to store and manage information about one book
{
private:
    string title, author, id; // Stores the book title, author and unique ID
    int pages; // Stores the number of pages in the book
    bool borrowed; // Stores whether the book is currently borrowed
public:
    Book(string t, string a, int p, string i, bool b = false) // Constructor used to create a Book object
        : title(t), author(a), pages(p), id(i), borrowed(b) {} // Initialises all book attributes
    string getId() const // Returns the ID so a book can be searched
    {
        return id; // Sends the book ID back to the calling function
    }
    void display() const // Displays all information about the book
    {
        cout << "ID: " << id // Displays the unique book ID
             << " | " << title // Displays the book title
             << " by " << author // Displays the author's name
             << " (" << pages << " pages) - " // Displays the number of pages
             << (borrowed ? "[BORROWED]" : "[AVAILABLE]") // Displays the current availability
             << endl; // Moves the output to a new line
    }
    bool borrow() // Attempts to borrow the book
    {
        if (borrowed)return false; // Prevents a book from being borrowed twice
        borrowed = true; // Changes the book status to borrowed
        return true; // Confirms that the borrowing was successful
    }
    bool returnBook() // Attempts to return the book
    {
        if (!borrowed) // Checks if the book is already available
            return false; // Prevents returning a book that was not borrowed
        borrowed = false; // Changes the book status back to available
        return true; // Confirms that the return was successful
    }
    void save(ofstream& file) const // Saves this book's information to the file
    {
        file << title << "," << author << "," // Writes title and author separated by commas
             << pages << "," << id << "," // Writes pages and ID
             << (borrowed ? 1 : 0) << endl; // Writes 1 for borrowed or 0 for available
    }
};
bool loadBooks(vector<Book>& library) // Loads all books from the external file into the vector
{
    ifstream file("resources/bookData.txt"); // Opens the book data file for reading
    if (!file.is_open()) // Checks whether the file was opened successfully
    {
        cerr << "Error: Could not open bookData.txt." << endl; // Displays an error if the file cannot be opened
        return false; // Stops the loading process
    }
    string line; // Stores one complete line from the file
    while (getline(file, line)) // Reads the file one line at a time
    {
        if (line.empty())continue; // Skips empty lines in the file
        stringstream ss(line); // Allows the line to be separated using commas
        string title, author, pages, id, status; // Temporary variables for the file data
        getline(ss, title, ','); // Reads the title from the line
        getline(ss, author, ','); // Reads the author from the line
        getline(ss, pages, ','); // Reads the page count as a string
        getline(ss, id, ','); // Reads the book ID
        getline(ss, status, ','); // Reads the borrowing status
        try // Attempts to convert the page and status values to integers
        {
            library.push_back( // Adds the new Book object to the vector
                Book(title, author, stoi(pages), // Converts pages from string to integer
                     id, stoi(status) != 0) // Converts status to true or false
            );
        }
        catch (...) // Handles invalid numerical data in the file
        {
            cout << "Invalid book data skipped." << endl; // Ignores invalid book entries
        }
    }
    return !library.empty(); // Returns true if at least one book was loaded
}
void saveBooks(const vector<Book>& library) // Saves all current books back to the file
{
    ofstream file("resources/bookData.txt"); // Opens the file for writing
    if (!file.is_open()) // Checks whether the file can be opened
    {
        cerr << "Error: Could not save book data." << endl; // Displays an error if saving fails
        return; // Stops the function
    }
    for (const Book& book : library) // Loops through every book in the vector
        book.save(file); // Saves each individual book to the file
}
Book* findBook(vector<Book>& library, string id) // Searches for a book using its ID
{
    for (Book& book : library) // Checks each book in the vector
    {
        if (book.getId() == id) // Compares the current book ID with the searched ID
            return &book; // Returns the address of the matching book
    }
    return nullptr; // Returns nothing if no matching book was found
}
void viewAll(const vector<Book>& library) // Displays every book in the library
{
    cout << "\n========== LIBRARY BOOKS ==========\n"; // Prints a heading for the book list
    for (const Book& book : library) // Loops through all books
        book.display(); // Displays each book's details
    cout << "===================================\n"; // Prints the bottom of the heading
}
void viewDetails(vector<Book>& library) // Allows the user to view one specific book
{
    string id; // Stores the ID entered by the user
    cout << "Enter Book ID: "; // Asks the user for a book ID
    cin >> id; // Reads the ID
    Book* book = findBook(library, id); // Searches the vector for that ID
    if (book) // Checks whether a matching book was found
        book->display(); // Displays the selected book
    else
        cout << "Book ID not found." << endl; // Displays an error if no book was found
}
void borrowBook(vector<Book>& library) // Handles the borrowing of a book
{
    string id; // Stores the ID entered by the user
    cout << "Enter Book ID to borrow: "; // Asks which book should be borrowed
    cin >> id; // Reads the book ID
    Book* book = findBook(library, id); // Searches for the selected book
    if (!book) // Checks whether the book exists
    {
        cout << "Book ID not found." << endl; // Tells the user the ID does not exist
        return; // Ends the function
    }
    if (book->borrow()) // Attempts to change the book to borrowed
    {
        cout << "Book successfully borrowed." << endl; // Confirms the operation
        saveBooks(library); // Saves the updated status to the file
    }
    else
        cout << "Book is already borrowed." << endl; // Prevents double borrowing
}
void returnBook(vector<Book>& library) // Handles returning a borrowed book
{
    string id; // Stores the ID entered by the user
    cout << "Enter Book ID to return: "; // Asks which book should be returned
    cin >> id; // Reads the book ID
    Book* book = findBook(library, id); // Searches for the selected book
    if (!book) // Checks whether the book exists
    {
        cout << "Book ID not found." << endl; // Tells the user the ID does not exist
        return; // Ends the function
    }
    if (book->returnBook()) // Attempts to change the book to available
    {
        cout << "Book successfully returned." << endl; // Confirms the operation
        saveBooks(library); // Saves the updated status to the file
    }
    else
        cout << "Book is already available." << endl; // Prevents returning an available book
}
int main() // Main function where the program starts
{
    vector<Book> library; // Creates a vector to store all Book objects
    if (!loadBooks(library)) // Loads the books and checks if loading was successful
    {
        cerr << "Failed to load books. Exiting." << endl; // Displays an error if books could not be loaded
        return 1; // Ends the program with an error code
    }
    int choice; // Stores the user's menu selection
    do // Repeats the menu until the user chooses Exit
    {
        cout << "\n========== LIBRARY SYSTEM ==========\n" // Displays the main menu
             << "1. View All Books\n" // Menu option to display all books
             << "2. View Book Details\n" // Menu option to find one book
             << "3. Borrow Book\n" // Menu option to borrow a book
             << "4. Return Book\n" // Menu option to return a book
             << "5. Exit\n" // Menu option to close the program
             << "Enter choice: "; // Asks the user to select an option
        cin >> choice; // Reads the selected menu option
        switch (choice) // Performs an action based on the selected option
        {
        case 1:
            viewAll(library); // Calls the function that displays all books
            break; // Stops this case
        case 2:
            viewDetails(library); // Calls the function to search for one book
            break; // Stops this case
        case 3:
            borrowBook(library); // Calls the function to borrow a book
            break; // Stops this case
        case 4:
            returnBook(library); // Calls the function to return a book
            break; // Stops this case
        case 5:
            saveBooks(library); // Saves the final book statuses before exiting
            cout << "Saving data and exiting..." << endl; // Informs the user the program is closing
            break; // Stops this case
        default:
            cout << "Invalid choice. Try again." << endl; // Handles an invalid menu selection
        }
    } while (choice != 5); // Continues displaying the menu until option 5 is selected
    return 0; // Ends the program successfully
}