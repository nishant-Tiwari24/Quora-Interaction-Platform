#include <iostream>
#include <string>
#include <fstream>
// #include <ctime>
#include <vector>
#include <algorithm>
// #include <random>
#include<windows.h>
#include "feeds.h"    // display the feeds of the users 
#include "UserProfile.h"  // play with user profile
#include "recommendation.h"   // recommend users
#include "hands.cpp"
#include "AddingPost.h"
#include "allUsers.h"
#include "loginregister.h"
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
void update(Profile &N, string current_user); // part of user profile
void showFeed(string user);    // part of show feed
void Recommend(string user);   // part of search
void AddPost(Profile &N, string user);// adding post
// void AddPost(Profile &N);
void search(string currentUser);
void displayDetails(string user);
// void Dashboard(Profile &N);
string login_register();
void noFollowingdisconnectedvertex(void);


int main(void) {

    string current_user = login_register();

        
        if(current_user.length() == 0)
        {
            return 0;
        }
        int choice;
        Profile N;
        int flag = 0;
        N.getDetails(current_user);

        do {
            system("cls");
            MainDashboard();
            cout << endl;
            cout <<"\t\t\t\t\t\t\t"<< GREEN << "Enter Your choice:  " << RESET;
            cin >> choice;

            switch (choice) {
                case 1: // profile
                    system("cls");
                    cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
                    cout << "\t\t\t\t\t\t\033[1;36m*                                    \033[0m"<<MAGENTA<<"Profile"<<RESET<<"\033[1;36m                                 *\033[0m" << endl;
                    cout << "\t\t\t\t\t\t\033[1;36m*                            `````````````````````                           *\033[0m" << endl;
                    cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
                    cout<<endl;
                    cout << "\t\t\t\t\t\t\t1." << BLUE<< "View Profile" << RESET << endl;
                    cout << "\t\t\t\t\t\t\t2." << RED << "Update Profile"<< RESET << endl;
                    cout << "\t\t\t\t\t\t\t" << CYAN<<"Enter 0 to go back: "<<RESET<<endl<<endl;
                    cout << "\t\t\t\t\t\t\t" << GREEN << "Enter Your choice: "<< RESET ;

                    // cout << "1. View Profile"<<endl;
                    // cout << "2. Update Profile"<<endl;
                    // cout << "Enter 0 to go back";
                    int profile_choice;
                    cin >> profile_choice;

                    while (true) 
                    {

                        if(profile_choice == 1)
                        { 
                            system("cls");
                            cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
                            cout << "\t\t\t\t\t\t\033[1;36m*                                 \033[0m"<<MAGENTA<<"User Details"<<RESET<<"\033[1;36m                                 *\033[0m" << endl;
                            cout << "\t\t\t\t\t\t\033[1;36m*                            `````````````````````                           *\033[0m" << endl;
                            cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
                            N.display();
                            cout << endl << endl;
                            cout << "\t\t\t\t\t\t"<<GREEN<<"(Press 0 to go back)"<<RESET;
                        }
                        else if(profile_choice == 2)
                        {
                            update(N, current_user);
                            // cout << "\t\t\t\t\t\t"<<GREEN<<"(Press 0 to go back)"<<RESET;
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
                    cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
                    cout << "\t\t\t\t\t\t\033[1;36m*                                \033[0m"<<MAGENTA<<"Searching"<<RESET<<"\033[1;36m                                 *\033[0m" << endl;
                    cout << "\t\t\t\t\t\t\033[1;36m*                            `````````````````````                           *\033[0m" << endl;
                    cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
                    cout << "\t\t\t\t\t\t\t1." << BLUE<< "Search People" << RESET << endl;
                    cout << "\t\t\t\t\t\t\t2." << RED << "Recommendation"<< RESET << endl;
                    cout << "\t\t\t\t\t\t\t" << CYAN<<"Enter 0 to go back: "<<RESET<<endl<<endl;
                    cout << "\t\t\t\t\t\t\t" << GREEN << "Enter Your choice"<< RESET;
                    int ch;
                    cin>>ch;
                    while(true)
                    {   
                        // cin >> ch;

                        if(ch == 1)
                        {
                            search(current_user);
                            // break;
                            cout << "(Press 0 to go back)"<< endl;
                        }
                        else if(ch == 2)
                        {
                            Recommend(current_user);
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
                    AddPost(N, current_user);
                    break;

                case 4: // show the feeds
                    system("cls");
                    showFeed(current_user);
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

    return 0;
}


// add new post to feed
void AddPost(Profile &N, string user)
{
    POST obj;
    obj.ReadFeed();
    string Id = obj.addingPost();
    N.addPostToProfile(Id, user);

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
            // Sleep(1000);
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
void search(string currentUser)
{
    system("cls");
    SearchingPanel obj;
    unordered_map<int, vector<string>> user;
    user = obj.detailsToHashTable();
    
    string c;
    cin.ignore();
    getline(cin, c);
    // cout << obj.searchUser(c);
    if (obj.searchUser(c) == 1)
    {
        cout << "\t\t\t\t\t\t\t" << GREEN << "Enter the Username to Search: "<< RESET;
        
        displayDetails(c,currentUser);
    }
    else
    {
        cout << "User not found";
    }
}

// display searched user profile
// ------------------------------------- make it --------------------------------
void displayDetails(string user,string currentUser)
{
    system("cls");
    cout << "Searched User Details" << endl<<endl;
    string file = "registrationdata/"+ user + ".txt";
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
        stringstream ss(following);
            vector<string> words;
            string word;
            int i;
            while(ss >> word)
            {
                words.push_back(word);
            }
            for(i=0 ; i<words.size() ; i++ ) {
                if(words[i] == currentUser) {
                    mutual();
                    break;
                }   
            }
            
        getline(read, followers);
        cout << "Followers: " << followers << endl;
        if(i>=words.size()) {
                cout<<"press 1 to follow and 0 to continue"<<endl;
                int choice;
                cin>>choice;
                if(choice == 1) {
                    followUser(current,currentUser);
                }
                else if(choice == 0) {
                    return ;
                }
                
            }
        
    }
}

void followUser(string user,string currUser) {
    string name, username, dob, email, profession, description, password, followers, following, blog;
    ifstream read;
    read.open("registration/" + user + ".txt");
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
        followers = currUser + followers;
        read.close();
        ofstream write;
        write.open("registration/" + user + ".txt");
        write<< name <<"\n" << username <<"\n" << dob <<"\n" <<email <<"\n" <<profession << "\n" <<description << "\n" << password << "\n" <<followers << "\n" <<following << "\n" << blog << "\n";
        write.close();

    read.open("registration/" + cuurUser + ".txt");
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
        following = currUser + following;
        read.close();
        ofstream write;
        write.open("registration/" + currUser + ".txt");
        write<< name <<"\n" << username <<"\n" << dob <<"\n" <<email <<"\n" <<profession << "\n" <<description << "\n" << password << "\n" <<followers << "\n" <<following << "\n" << blog << "\n";
        write.close();
    
}


// shows the feeds
void showFeed(string user)
{
    FEEDS obj;
    obj.ReadFeed();
    cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
    cout << "\t\t\t\t\t\t\033[1;36m*                                \033[0m"<<MAGENTA<<"FEEDS"<<RESET<<"\033[1;36m                               *\033[0m" << endl;
    cout << "\t\t\t\t\t\t\033[1;36m*                            `````````````````````                           *\033[0m" << endl;
    cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
    obj.displayNext();

    char choice;

    cout << GREEN<<"Press D to go forward : Press A to fo backward (Press 0 to go back)" << RESET<<endl ;
    cin >> choice;
    choice = tolower(choice);
    while (choice != '0')
    {
        system("cls");
        cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
        cout << "\t\t\t\t\t\t\033[1;36m*                                \033[0m"<<MAGENTA<<"FEEDS"<<RESET<<"\033[1;36m                               *\033[0m" << endl;
        cout << "\t\t\t\t\t\t\033[1;36m*                            `````````````````````                           *\033[0m" << endl;
        cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
        cout<<endl;
        if (choice == 'd')
        {
            obj.displayNext();
            if (obj.isAnswerGiven() == 0)
            {
                cout <<GREEN<<"Want to answer(Press: Y/N): "<<RESET;
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
                    obj.TypeAnswer(user);
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
                cout << GREEN<<"Want to answer(Press: Y/N): "<<RESET;
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
                    obj.TypeAnswer(user);
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
        cout << GREEN<<"Press D to go forward : Press A to fo backward (Press 0 to go back)"<<RESET << endl ;
        cin >> choice;
    }
}

// Recommend other people to the users`
void Recommend(string curr_user) 
{
    system("cls");
    cout << LARGER<< "Recommended User"<<NORMAL<<endl;
    Recommendation obj;
    vector<string> following;

    vector<string> vertices;
    string filename = "registrationdata/"+curr_user+".txt";
    following = obj.getFollowingInfo(filename); // profile
    if(following.size() == 0)
    {
        noFollowingdisconnectedvertex();
        return ;
    }
    vector<vector<string>> ffUsers;

    for (const auto& user : following) {
        string fileName = "registrationdata/" + user + ".txt";   //profile used
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
        graph.addEdge(curr_user, user[0]);
        string temp = user[0];
        for (int i = 1; i < user.size(); i++) {
            graph.addEdge(temp, user[i]);
        }
    }

    graph.displayDisconnectedVertices(curr_user);

    cout << "done\n";
}

void noFollowingdisconnectedvertex(void)
{
    Recommendation obj;
    vector<string> vertices;
    string filename = "logindata.txt", str;
    ifstream read;
    read.open(filename);
    while(!getline(read, str).eof())
    {
        vertices.push_back(str);
        getline(read, str);
    }

    Graph reccommend_graph(vertices);
    for (const auto& user : vertices) {
        // graph.addEdge(curr_user, user[0]);
        string curr = user;
        vector<string> temp = obj.getFollowingInfo(("registrationdata/" + user + ".txt"));
        for (int i = 0; i < temp.size(); i++) {
            reccommend_graph.addEdge(curr, temp[i]);
        }
    }
    reccommend_graph.displayVerticesWithInwardEdges();
}

// for updating loged in user profile
void update(Profile &N, string user)
{
        system("cls");
        cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
        cout << "\t\t\t\t\t\t\033[1;36m*                                \033[0m"<<MAGENTA<<"Update Profile"<<RESET<<"\033[1;36m                                 *\033[0m" << endl;
        cout << "\t\t\t\t\t\t\033[1;36m*                            `````````````````````                           *\033[0m" << endl;
        cout << "\t\t\t\t\t\t\033[1;36m******************************************************************************\033[0m" << endl;
        cout<<endl;
        cout << "\t\t\t\t\t\t\t1." << BLUE<< "User Name" << RESET << endl;
        cout << "\t\t\t\t\t\t\t2." << RED << "E-Mail"<< RESET << endl;
        cout << "\t\t\t\t\t\t\t3." << YELLOW << "About Yourself"<< RESET << endl<<endl;
        // cout << "\t\t\t\t\t\t\t" << CYAN<<"(Press 0 to go back)"<<RESET<<endl<<endl;
        cout << "\t\t\t\t\t\t\t" << RED << "Enter Your choice: "<< RESET;

        // cout << "1. User name"<<endl;
        // cout << "2. Mail"<<endl;
        // cout << "3. description"<<endl;
        int choice;
        string changing_string;
        cin>>choice;
        system("cls");
        switch(choice)
        {
            cout << CYAN<<"Enter the Details"<<RESET <<endl;
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
                cout << "Enter about Yourself: "<< endl;
                cin.ignore();
                getline(cin, changing_string);
                N.updateUser(changing_string, 3, user);
                break;
            default:
                return;
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
