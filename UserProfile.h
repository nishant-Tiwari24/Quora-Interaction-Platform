#ifndef USERPROFILE_H
#define USERPROFILE_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include "feeds.h"

using namespace std;

class Details
{
public:
    string name, username, dob, email, profession, description, password, followers, following, blog;
};

class Profile : public Details
{
public:
    void getDetails(string user)
    {

        ifstream read;
        string filename = "registrationdata/" + user + ".txt";
        read.open(filename);
        string str;
        getline(read, name);
        getline(read, username);
        getline(read, dob);
        getline(read, email);
        getline(read, profession);
        getline(read, description);
        getline(read, password);
        getline(read, following);
        getline(read, followers);
        getline(read, blog);

        read.close();
    }

    void display()
    {
        // Set the width for each column
        const int columnWidth = 15;

        // Display top border
        cout << "\t\t\t\t\t\t+" << string(columnWidth * 2 + 10, '-') << "+" << endl;

        // Display user information
        cout << "\t\t\t\t\t\t|" << left << setw(columnWidth) << "Name"
             << "|" << left << setw(columnWidth) << name << "\t|" << endl;
        cout << "\t\t\t\t\t\t|" << left << setw(columnWidth) << "User Name"
             << "|" << left << setw(columnWidth) << username << "\t|" << endl;
        cout << "\t\t\t\t\t\t|" << left << setw(columnWidth) << "DOB"
             << "|" << left << setw(columnWidth) << dob << "\t|" << endl;
        cout << "\t\t\t\t\t\t|" << left << setw(columnWidth) << "Mail"
             << "|" << left << setw(columnWidth) << email << "\t|" << endl;
        cout << "\t\t\t\t\t\t|" << left << setw(columnWidth) << "Profession"
             << "|" << left << setw(columnWidth) << profession << "\t|" << endl;
        cout << "\t\t\t\t\t\t|" << left << setw(columnWidth) << "Description"
             << "|" << left << setw(columnWidth) << description << "\t|" << endl;
        cout << "\t\t\t\t\t\t|" << left << setw(columnWidth) << "Following"
             << "|" << left << setw(columnWidth) << following << "\t|" << endl;
        cout << "\t\t\t\t\t\t|" << left << setw(columnWidth) << "Followers"
             << "|" << left << setw(columnWidth) << followers << "\t|" << endl;

        // Display middle border
        cout << "\t\t\t\t\t\t+" << string(columnWidth * 2 + 10, '-') << "+" << endl;

        // Display blog information
        stringstream ss(blog);
        string num;
        vector<int> blog_id;
        while (ss >> num)
        {
            int id = stoi(num);
            blog_id.push_back(id);
        }
        cout << "\t\t\t\t\t\t|" << left << setw(columnWidth) << "Feeds Answered"
             << "|"
             << left << setw(columnWidth) << blog_id.size() << "\t|" << endl;

        // Display bottom border
        cout << "\t\t\t\t\t\t+" << string(columnWidth * 2 + 10, '-') << "+" << endl;
    }

    void updateUser(string str, int n, string user)
    {
        switch (n)
        {
        case 1:
            username = str;
            break;
        case 2:
            email = str;
            break;
        case 3:
            description = str;
            break;
        }

        updateFile(user);
    }

    // update for the blogs
    void addPostToProfile(string Id, string user)
    {
        cout << blog;
        cout << "done";
        if (Id.length() > 0)
        {
            Id = Id + " " + blog;
            blog = Id;
            updateFile(user);
        }
    }

    void updateFile(string user)
    {
        ofstream write;
        string filename = "registrationdata/" + user + ".txt";
        write.open(filename);
        write << name << "\n";
        write << username << "\n";
        write << dob << "\n";
        write << email << "\n";
        write << profession << "\n";
        write << description << "\n";
        write << password << "\n";
        write << following << "\n";
        write << followers << "\n";
        write << blog << "\n";

        write.close();
    }
};

#endif