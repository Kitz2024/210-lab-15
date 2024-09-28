#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Movie
{
private:
    string title;
    int yearReleased;
    string screenwriter;

public:
    Movie()
    {
        title = "";
        yearReleased = 0;
        screenwriter = "";
    }
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
    void setYearReleased(string screenwriter)
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
};

int main()
{
    vector<Movie> movies;
    ifstream inFile("C:\\Lab210\\210lab15.txt");

    if (inFile.is_open())
    {
        string title, screenwriter;
        int yearReleased;

        while (inFile >> title >> yearReleased >> screenwriter)
        {
            Movie *movie = new Movie(title, yearReleased, screenwriter);
            movies.push_back(*movie);
        }
        inFile.close();
    }
    else
    {
        cout << "Error opening File." << endl;
        return 1;
    }
    for (const Movie &movie : movies)
    {
        cout << "Movies in File: " << endl;
        movie.print();
    }

    return 0;
}