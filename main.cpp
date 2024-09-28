// Kit pollinger
//  210 | Lab 9 | Movie Class

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Movie
{
public:
    Movie() {}
    Movie(string title, int yearRealsed, string screenWriter)
    {
        this->title = title;
        this->yearReleased = yearRealsed;
        this->screenWriter = screenWriter;
    }
    string getTitle() const
    {
        return title;
    }
    void setTitle(string title)
    {
        this->title = title;
    }

private:
    string title;
    int yearReleased;
    string screenWriter;
};

int main()
{

    vector<Movie> movies;
    // File Checker
    ifstream inFile("C:/Lab210/lab15-input.txt"); // Change Path if placed somewhere else and not at "C:"
    if (!inFile.is_open())
    {
        string title, screenWriter;
        int yearReleased;

        while (inFile >> title >> yearReleased >> screenWriter)
        {
            Movie movie(title, yearReleased, screenWriter);
            movies.push_back(movie);
        }
        inFile.close();
    }
    else
    {
        cout << "Error Can't open file" << endl;
        return 1;
    }

    cout << "Movies in the container: " << endl;
    for (const Movie& movie : movies){
        
    }

    return 0;
}
