#ifndef FEEDS_H // Include guard
#define FEEDS_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "UserProfile.h"
using namespace std;

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"

#define piss pair<int, pair<string, string>> // piqa stands for pair of (integer question answer)
#define ff first
#define ss second

class FEEDS : public Profile
{
public:
    vector<piss> arr;
    int i = -1;

    void ReadFeed(void)
    {
        int num;
        string Number;
        string Question;
        string Answer = "";
        // string temp = "";
        ifstream read;
        read.open("feed.txt");

        while (!(getline(read, Number)).eof())
        {
            Answer = "";
            try
            {
                num = stoi(Number); // string to integer
            }
            catch (const std::invalid_argument &e)
            {
                // Handle the invalid argument exception (e.g., print an error message)
                cerr << "Invalid argument: " << e.what() << endl;
                // You might want to decide what to do in case of an error.
                // For example, you could skip this line or terminate the program.
                continue;
            }
            getline(read, Question);
            getline(read, Answer);

            // while (temp.length() != 0)
            // {
            //     Answer.append(temp);
            //     getline(read, temp);
            // }

            arr.push_back(make_pair(num, make_pair(Question, Answer)));
        }

        read.close();
    }

    void displayNext(void)
    {
        i++;
        if (i == arr.size())
        {
            i = 0;
        }
        // cout << arr[i].ff << endl;
        cout << YELLOW << "Q. " << arr[i].ss.ff << RESET << endl
             << endl;
        if (arr[i].ss.ss != "")
        {
            cout << CYAN << "Answer: " << RESET << endl
                 << arr[i].ss.ss << endl;
        }
        cout << endl;
    }

    void displayPrevious(void)
    {
        i--;
        if (i == -1)
        {
            i = arr.size() - 1;
        }
        cout << YELLOW << "Q. " << arr[i].ss.ff << RESET << endl
             << endl;
        if (arr[i].ss.ss != "")
        {
            cout << BLUE << "Answer: " << RESET << arr[i].ss.ss << endl;
        }
        cout << endl;
    }

    void displayCurrent(void)
    {
        system("cls");
        cout << YELLOW << "Q." << arr[i].ss.ff << RESET << endl
             << endl;
        cout << CYAN << "Answer: " << RESET << endl
             << arr[i].ss.ss << endl;
    }

    int isAnswerGiven(void)
    {
        if ((arr[i].ss.ss).length() == 0)
            return 0;
        else
            return 1;
    }

    void TypeAnswer(string user)
    {
        system("cls");
        string type_answer;
        string a = to_string(arr[i].ff);
        cout << arr[i].ss.ff << endl;
        cout << "Type your answer here: " << endl;
        getline(cin, type_answer);
        arr[i].ss.ss += type_answer;
        getDetails(user);
        addPostToProfile(a, user);
        addingAnswer();
    }

    void addingAnswer(void)
    {
        ofstream write;
        string str;
        write.open("feed.txt");

        for (auto i : arr)
        {
            write << i.ff << "\n";
            write << i.ss.ff << "\n";
            write << i.ss.ss << "\n";
        }

        write.close();
    }
};
#endif // FEEDS_H