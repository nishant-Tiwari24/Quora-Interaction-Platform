#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
#include<windows.h>
#include "feeds.cpp"    // display the feeds of the users 
#include "UserProfile.cpp"  // play with user profile
#include "recommendation.cpp"   // recommend users
#include "hands.cpp"
#include "AddingPost.cpp"
#include "allUsers.h"
#include "loginregister.cpp"
//colors
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
//font size
#define LARGER  "\033[1m"
#define NORMAL  "\033[0m"

using namespace std;

void MainDashboard(void);
void showProfile(void); // part of user profile
void update(Profile &N, string user); // part of user profile
void showFeed(void);    // part of show feed
void Recommend(void);   // part of search
void AddPost(Profile &N);// adding post
void search();
void displayDetails(string user);
// void Dashboard(Profile &N);
string login_register();


int main(void) {

    string current_user = login_register();
    
    if(current_user.length() == 0)
    {
        return 0;
    }
    int choice;
    Profile N;
    N.getDetails(current_user);
    int flag = 0;

    do {
        system("cls");
        MainDashboard();
        cout << endl;
        cout <<"\t\t\t\t\t\t\t"<< GREEN << "Enter Your choice:  " << RESET;
        cin >> choice;

        switch (choice) {
            case 1: // profile
                system("cls");
                // cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
                // cout << "\t\t\t\t\t\t\033[1;36m*                                    \033[0m"<<MAGENTA<<"Profile"<<RESET<<"\033[1;36m                                 *\033[0m" << endl;
                // cout << "\t\t\t\t\t\t\033[1;36m*                            `````````````````````                           *\033[0m" << endl;
                // cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
                // cout<<endl;
                // cout << "\t\t\t\t\t\t\t1." << BLUE<< "View Profile" << RESET << endl;
                // cout << "\t\t\t\t\t\t\t2." << RED << "Update Profile"<< RESET << endl;
                // cout << "\t\t\t\t\t\t\t" << CYAN<<"Enter 0 to go back: "<<RESET;

                cout << "1. View Profile"<<endl;
                cout << "2. Update Profile"<<endl;
                cout << "Enter 0 to go back";
                int profile_choice;
                cin >> profile_choice;

                while (true) 
                {

                    if(profile_choice == 1)
                    {
                        system("cls");
                        cout << "User Details" << endl << endl;
                        N.display();
                        cout << endl << endl;
                        cout << "(Press 0 to go back)";
                    }
                    else if(profile_choice == 2)
                    {
                        update(N, current_user);
                        cout << "(Press 0 to go back)";
                    }
                    else if(profile_choice == 0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input!";
                    }
                    cin >> profile_choice;
                }
                break;

            case 2: // searching
                    system("cls");
                    cout << "1. Search people" << endl;
                    cout << "2. Recommendation" << endl;
                    cout << "(Press 0 to go back)"<< endl;
                int ch;
                cin>>ch;
                while(true)
                {   
                    // cin >> ch;

                    if(ch == 1)
                    {
                        search();
                        // break;
                        cout << "(Press 0 to go back)"<< endl;
                    }
                    else if(ch == 2)
                    {
                        Recommend();
                        // break;
                        cout << "(Press 0 to go back)"<< endl;
                    }
                    else if(ch == 0)
                    {
                        break;
                    }
                    else{
                        cout << "Invalid Input";
                    }
                    cin >> ch;
                }

                break;

            case 3: // adding posts
                system("cls");
                AddPost(N);
                break;

            case 4: // show the feeds
                system("cls");
                showFeed();
                break;

            case 5: // settings
                system("cls");
    
                int ch1;
                while(true)
                {
                    cout << "1. Log out"<<endl;
                    cout << "(Press 0 to go back )"<< endl;
                    cin>>ch1;
                    if(ch1 == 1)
                    {
                        //call the login and register function
                        flag++;
                        break;
                    }
                    else if(ch1 == 0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input";
                    }
                    
                }
                break;

            default:
            cout << "Invalid choice";
            cin >> choice;
                break;
        }
        if(flag)
        {
            break;
        }
    } while (true);  // Loop until user chooses to exit
    login_register();

    return 0;
}

// display main dashboard
void MainDashboard(void)
{
    cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
    cout << "\t\t\t\t\t\t\033[1;36m*                               \033[0m"<<MAGENTA<<"Main Dashboard"<<RESET<<"\033[1;36m                               *\033[0m" << endl;
    cout << "\t\t\t\t\t\t\033[1;36m*                            `````````````````````                           *\033[0m" << endl;
    cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
    cout<<endl;
    // cout << MAGENTA << "Main Dashboard" << RESET << endl;
    cout << "\t\t\t\t\t\t\t1. " << YELLOW << "Your Profile" << RESET << endl;  // view and update
    cout << "\t\t\t\t\t\t\t2. " << BLUE << "Search People" << RESET << endl; // search other people and follow
    cout << "\t\t\t\t\t\t\t3. " << GREEN << "Add Post" << RESET << endl;
    cout << "\t\t\t\t\t\t\t4. " << CYAN << "Show Feeds" << RESET << endl;
    cout << "\t\t\t\t\t\t\t5. " << RED << "Settings" << RESET << endl;    // logout
}

// register and login
string login_register(){
    system("cls");
    int choice;
    string a;
    do {
        cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
        cout << "\t\t\t\t\t\t\033[1;36m*                              Q&A PLATFORM                                  *\033[0m" << endl;
        cout << "\t\t\t\t\t\t\033[1;36m*                            `````````````````````                           *\033[0m" << endl;
        cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
        cout<<endl;
        cout << "\t\t\t\t\t\t\t\033[1;33m1. Login\033[0m" << endl;
        cout << "\t\t\t\t\t\t\t\033[1;33m2. Sign up\033[0m" << endl;
        cout << "\t\t\t\t\t\t\t\033[1;33m3. Exit\033[0m" << endl;
        cout<<endl;
        cout << "\t\t\t\t\t\t\t\033[1;32mEnter your choice: \033[0m";
        cin >> choice;
        page p;

        if(choice == 1)
        {
            cout << "Loading LOGIN page" << endl;
            Sleep(1000);
            a = p.login();
            if(a.length() != 0)
                break;
        }
        else if(choice == 2)
        {
            cout << "Loading SIGN-UP page" << endl;
            Sleep(2000);
            p.signup();   
        }
        else if(choice == 3)
        {
            cout << "Exiting the program. Goodbye!" << endl;
            Sleep(2000);
        }
        else
        {
            cout << "\033[1;31mInvalid choice. Please try again.\033[0m" << endl;
        }

    } while (choice != 3);
    return a;
}


// setting to logout from quora
void settings(void)
{
    
}

// Searching user profile
void search(void)
{
    system("cls");
    SearchingPanel obj;
    unordered_map<int, vector<string>> user;
    user = obj.detailsToHashTable();
    
    string c;
    cout << "Enter the Username to Search: ";
    cin.ignore();
    getline(cin, c);
    // cout << obj.searchUser(c);
    if (obj.searchUser(c) == 1)
    {
        
        displayDetails(c);
    }
    else
    {
        cout << "User not found";
    }
}

// display searched user profile
void displayDetails(string user)
{
    system("cls");
    cout << "Searched User Details" << endl<<endl;
    string file = user + ".txt";
    string following, followers;
    ifstream read(file);
    if (read.is_open())
    {
        string str;

        getline(read, str);
        cout << "Name: " << str << endl;
        getline(read, str);
        cout << "User Name: " << str << endl;
        getline(read, str);
        cout << "DOB: " << str << endl;
        getline(read, str);
        getline(read, str);
        cout << "Profession: " << str << endl;
        getline(read, str);
        cout << "Decription : " << str << endl;
        getline(read, str);

        getline(read, following);
        cout << "Following: " << following << endl;
        getline(read, followers);
    }
}




// add new post to feed
void AddPost(Profile &N)
{
    POST obj;
    obj.ReadFeed();
    int Id = obj.addingPost();
    N.addPostToProfile(Id);

}

// shows the feeds
void showFeed(void)
{
    FEEDS obj;
    obj.ReadFeed();
    obj.displayNext();

    char choice;

    cout << "Press D to go forward : Press A to fo backward (Press 0 to go back)" << endl ;
    cin >> choice;
    // choice = 1;
    choice = tolower(choice);
    while (choice != '0')
    {
        system("cls");
        if (choice == 'd')
        {
            obj.displayNext();
            if (obj.isAnswerGiven() == 0)
            {
                cout << "Want to answer(Press: Y/N): ";
                cin >> choice;
                cin.ignore();
                cout << choice;
                choice = tolower(choice);
                if (choice == 'N' || choice == 'n')
                {
                    choice = 'd';
                    continue;
                }
                else if (choice == 'Y' || choice == 'y')
                {
                    obj.TypeAnswer();
                    obj.displayCurrent();
                    cout << endl;
                }
                else
                {
                    cout << "Invalid input";
                }
            }
        }
        else if (choice == 'a')
        {
            obj.displayPrevious();
            if (!obj.isAnswerGiven())
            {
                cout << "Want to answer(Press: Y/N): ";
                cin >> choice;
                cin.ignore();
                choice = tolower(choice);
                if (choice == 'N' || choice == 'n')
                {
                    choice = 'd';
                    continue;
                }
                else if (choice == 'Y' || choice == 'y')
                {
                    obj.TypeAnswer();
                    obj.displayCurrent();
                    cout << endl;
                }
                else
                {
                    cout << "Invalid input"; // ask again for invlaid input
                }
            }
        }
        cout << endl;
        cout << "Press D to go forward : Press A to fo backward (Press 0 to go back)" << endl ;
        cin >> choice;
    }
}

// Recommend other people to the users`
void Recommend() 
{
    system("cls");
    Recommendation obj;
    vector<string> following;

    vector<string> vertices;

    following = obj.getFollowingInfo("Profile.txt");
    vector<vector<string>> ffUsers;

    for (const auto& user : following) {
        string fileName = user + ".txt";
        vector<string> temp = obj.getFollowingInfo(fileName);
        temp.insert(temp.begin(), user);  
        ffUsers.push_back(temp);
    }

    for (const auto& user : ffUsers) {
        for (const auto& followingUser : user) {

            vertices.push_back(followingUser);
        }
    }

    Graph graph(vertices);

    for (const auto& user : ffUsers) {
        graph.addEdge("praveen", user[0]);
        string temp = user[0];
        for (int i = 1; i < user.size(); i++) {
            graph.addEdge(temp, user[i]);
        }
    }

    graph.displayDisconnectedVertices("Main");

    cout << "done\n";
}

void update(Profile &N, string user)
{
        system("cls");
        cout << "1. User name"<<endl;
        cout << "2. Mail"<<endl;
        cout << "3. description"<<endl;
        int choice;
        string changing_string;
        cin>>choice;
        system("cls");
        cout << "Enter the Details" <<endl<<endl;
        switch(choice)
        {
            case 1:
                cout << "Enter the User Name: ";
                cin.ignore();
                getline(cin, changing_string);
                N.updateUser(changing_string, 1, user);
                break;
            case 2:
                cout << "Enter the Mail: ";
                cin >> changing_string;
                N.updateUser(changing_string, 2, user);
                break;
            case 3:
                cout << "Enter about Yourself: ";
                cin >> changing_string;
                N.updateUser(changing_string, 3, user);
                break;
        }
        
}



// show use profile
void showProfile(void)
{
    ifstream read;
    string str;
    read.open("profile.txt");
    getline(read, str);
    cout << "ID: " << str << endl;
    getline(read, str);
    cout << "Name: " << str << endl;
    getline(read, str);
    cout << "User Name: " << str << endl;
    getline(read, str);
    cout << "DOB: " << str << endl;
    getline(read, str);
    cout << "Decription : " << str << endl;
    getline(read, str);
    cout << "Mail: " << str << endl;
    getline(read, str);
    cout << "Profession: " << str << endl;
}




// shuffle in vector
// vector<int> arr;
//     for(int i=0; i< 20; i++)
//     {
//         arr.push_back(i);
//     }
//     random_device rd;
//     mt19937 gen(rd());
//     shuffle(arr.begin(), arr.end(), gen);

//     for(int i: arr)
//     {
//         cout << i<<" ";
//     }