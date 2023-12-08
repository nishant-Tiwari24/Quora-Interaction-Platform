#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
// #include "UserProfile.cpp"
using namespace std;

class Recommendation
{
public:
    string str;

    vector<string> getFollowingInfo(string User)
    {
        ifstream read(User);
        vector<string> words;
        if (!read.is_open())
        {
            read.close();
            return words;
        }

        // read.open(User);
        for (int i = 0; i < 7; i++)
        {
            getline(read, str);
        }
        getline(read, str);

        stringstream ss(str);
        string word;
        while (ss >> word)
        {
            words.push_back(word);
        }
        read.close();

        return words;
    }
};