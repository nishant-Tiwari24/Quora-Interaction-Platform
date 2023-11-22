#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Details
{
    public:
    string Id, name, username, dob, email, profession, description, password, followers, following, blog;

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
        getline(read, Id);
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
        cout << "ID: " << Id << endl;
        cout << "Name: " << name << endl;
        cout << "User Name: " << username << endl;
        cout << "DOB: " << dob << endl;
        cout << "Mail: " << email << endl;
        cout << "Profession: " << profession << endl;
        cout << "Decription : " << description << endl;
    }

    void updateUser(string str, int n)
    {
        switch(n)
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

        updateFile();
    }

    // update for the blogs
     void addPostToProfile(int Id)
    {
        string str = to_string(Id); // chnage it
        blog += str;
        updateFile();
    }

    void updateFile()
    {
        ofstream write;
        write.open("temp.txt");
        write << Id << "\n";
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

// write << email;
        // write << profession;
        // write << description;
        // write << password;
        // write << followers;
        // write << following;
        // write << blog;