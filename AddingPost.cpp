#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#define piss pair<int, pair<string, string>> // piqa stands for pair of (integer question answer)
#define ff first
#define ss second

class POST
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

            arr.push_back(make_pair(num, make_pair(Question, Answer)));
        }

        read.close();
    }

    int addingPost(void)
    {
        string Question, Answer;
        int ID = arr.size();
        ID++;
        cout << "Type your Question:" <<endl;
        cin.ignore();
        getline(cin, Question);
        cout << "Type your Answer: (If Not want to write the answer just Press Enter) " << endl;
        getline(cin, Answer);

        arr.push_back(make_pair(ID, make_pair(Question, Answer)));

        reWriteToFile();
        return ID;
    }

    void reWriteToFile(void)
    {
        ofstream write;
        string str;
        write.open("feed.txt");     // change the file name

        for(auto i: arr)
        {
            write<<i.ff<<"\n";
            write<<i.ss.ff<<"\n";
            if((i.ss.ss).length() != 0 )
            {
                write<<i.ss.ss<<"\n";
            }
        }

        write.close();
    }


       
};