#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class SearchingPanel
{
public:
    unordered_map<int, vector<string>> Users;

    int returnAscii(const string &str)
    {
        int sum = 0;
        for (char ch : str)
        {
            sum += static_cast<int>(ch);
        }
        return (sum % 10);
    }

    unordered_map<int, vector<string>> detailsToHashTable()
    {
        ifstream read("logindata.txt");
        if (!read.is_open())
        {
            cerr << "Error opening file\n";
            return Users;
        }
        while (!read.eof())
        {
            string username;
            int a;
            getline(read, username);
            a = returnAscii(username);
            Users[a].insert(Users[a].end(), username);
            getline(read, username);
            // getline(read, username);
        }
        read.close();
        return Users;
    }

    bool searchUser(const string &username)
    {
        int key = returnAscii(username);
        auto it = Users.find(key);

        if (it != Users.end())
        {
            const vector<string> &usernames = it->second;
            for (const string &user : usernames)
            {
                if (user == username)
                {
                    return true;
                }
            }
        }
        return false; // Added return statement
    }
};