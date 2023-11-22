#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class page
{
    public:

    void signup()
    {
        string name,userid,prfsn,createpass,email,dob,bio;
        system("cls");
        cout<<"\t\t\tWelecome to SIGN-UP page"<<endl;
        cout<<"\t\t\tCreate a new account"<<endl;
        cout<<"NAME: ";
        cin.ignore();
        getline(cin,name);
        cout<<"USER ID: ";
        getline(cin,userid);
        cout<<"DOB(dd/mm/yy): ";
        getline(cin,dob);
        cout<<"EMAIL: ";
        getline(cin,email);
        cout<<"PROFESSION: ";
        getline(cin,prfsn);
        cout<<"ADD BIO: ";
        getline(cin,bio);
        cout<<"CREATE PASSWORD: ";
        getline(cin,createpass);
        

        string filename="registrationdata/" + userid + ".txt";
        ofstream data(filename,ios::app);
        data<<name<<endl;
        data<<userid<<endl;
        data<<dob<<endl;
        data<<email<<endl;
        data<<prfsn<<endl;
        data<<bio<<endl;
        data<<createpass<<endl;
        data<<endl;
        data<<endl;
        data<<endl;
        ofstream ld("logindata.txt",ios::app);
        ld<<userid<<endl;
        ld<<createpass<<endl;
        ld<<endl;
        cout<<"Signing up......"<<endl;
        cout<<"SIGN-UP completed";
        Sleep(1500);
        system("cls");
        cout<<endl;
    }

    int calculateAsciiSum(const string& str) {
    int sum = 0;
    for (char c : str) {
        sum += static_cast<int>(c);
    }
    return sum;
 }

    string login() 
    {
        string usrname, password;
        system("cls");
        cout << "Please enter your username and password\n";
        cout << "USERNAME: ";
        cin >> usrname;
        cout << "PASSWORD: ";
        cin >> password;

        unordered_map<int, vector<string>> loginData;

        ifstream input("logindata.txt");
        string id, pass;
        while (input >> id >> pass) {
            int asciiSum = calculateAsciiSum(id);
            loginData[asciiSum].push_back(pass);
        }
        input.close();

        int usernameAsciiSum = calculateAsciiSum(usrname);
        auto it = loginData.find(usernameAsciiSum);
        if (it != loginData.end()) {
            vector<string>& passwords = it->second;
            for (const string& storedPass : passwords) {
                if (storedPass == password) {
                    cout<<"Logging in......."<<endl;
                    cout << "LOGIN Successful" << endl;
                    Sleep(1500);
                    system("cls");
                    return usrname;
                }
            }
        }

        cout << "LOGIN ERROR" << endl;
        cout << "Please enter valid username and password" << endl;
        return ""; 
    }
};