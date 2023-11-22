#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

#define piss pair<int, pair<string, string>> // piqa stands for pair of (integer question answer)
#define ff first
#define ss second

class FEEDS
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
            num = stoi(Number);
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
        cout << arr[i].ff << endl;
        cout << arr[i].ss.ff << endl<<endl;
        if (arr[i].ss.ss != "")
        {
            cout << "Answer: "<<arr[i].ss.ss << endl;
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
        cout << arr[i].ff << endl;
        cout << arr[i].ss.ff << endl<<endl;
        if (arr[i].ss.ss != "")
        {
            cout << "Answer: "<<arr[i].ss.ss << endl;
        }
        cout << endl;
    }

    void displayCurrent(void)
    {
        system("cls");
        cout << arr[i].ff << endl;
        cout <<arr[i].ss.ff << endl<<endl;
        cout << "Answer: "<<arr[i].ss.ss << endl;
    }

    int isAnswerGiven(void)
    {
        if ((arr[i].ss.ss).length() == 0)
            return 0;
        else
            return 1;
    }

    void TypeAnswer(void)
    {
        system("cls");
        string type_answer;
        cout << arr[i].ss.ff << endl;
        cout << "Type your answer here: " << endl;
        getline(cin, type_answer);
        arr[i].ss.ss += type_answer;
        addingAnswer();
    }

    void addingAnswer(void)
    {
        ofstream write;
        string str;
        write.open("feed.txt");

        for(auto i: arr)
        {
            write<<i.ff<<"\n";
            write<<i.ss.ff<<"\n";
            write<<i.ss.ss<<"\n";
            // write<<"\n";
        }

        write.close();
    }
};
