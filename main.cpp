#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Setting up the class
class Movie
{
public:
    Movie() {}

    Movie(string title, int yearReleased, string screenwriter)
    {
        this->title = title;
        this->yearReleased = yearReleased;
        this->screenwriter = screenwriter;
    }

    string getTitle() const
    {
        return title;
    }
    void setTitle(string title)
    {
        this->title = title;
    }

    int getYearReleased() const
    {
        return yearReleased;
    }
    void setYearReleased(int yearReleased)
    {
        this->yearReleased = yearReleased;
    }
    string getScreenwriter() const
    {
        return screenwriter;
    }
    void setScreenwriter(string screenwriter)
    {
        this->screenwriter = screenwriter;
    }
    void print() const
    {
        cout << "Movie: " << title << endl;
        cout << "\tYear released: " << yearReleased << endl;
        cout << "\tScreenwriter: " << screenwriter << endl;
    }

private:
    string title;
    int yearReleased;
    string screenwriter;
};

int main()
{
    vector<Movie> movies;
    ifstream inFile("C:/Lab210/210lab15.txt");

    //Finile Checker
    if (!inFile.is_open())
    {
        cout << "Error Can't Open File" << endl;
        return 1;
    }

    string title, screenwriter;
    int yearReleased;

    while (getline(inFile, title)) // Read entire Title Line
    {
        if (inFile >> yearReleased)
        {
            inFile.ignore();
            getline(inFile, screenwriter);                              // Read entire Screenwriter Line
            movies.push_back(Movie(title, yearReleased, screenwriter)); // Push the movie class to the vector
        }
    }
    inFile.close(); // Closing File

    // Output File
    cout << "Movies in File: " << endl;
    for (const Movie &movie : movies)
    {
        movie.print();
    }

    return 0;
}