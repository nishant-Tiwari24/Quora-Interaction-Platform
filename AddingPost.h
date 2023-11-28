#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"

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
            try
            {
                num = stoi(Number);  
            }
            catch (const std::invalid_argument& e)
            {
                cerr << "Invalid argument: " << e.what() << endl;
                continue;
            }
            getline(read, Question);
            getline(read, Answer);

            arr.push_back(make_pair(num, make_pair(Question, Answer)));
        }

        read.close();
    }

    string addingPost(void)
    {
        string Question, Answer;
        int ID = arr.size();
        ID++;
        cout << YELLOW<<"Type your Question:"<<RESET <<endl;
        cin.ignore();
        getline(cin, Question);
        cout << YELLOW<<"Type your Answer: (If Not want to write the answer just Press Enter) "<<RESET << endl;
        getline(cin, Answer);

        arr.push_back(make_pair(ID, make_pair(Question, Answer)));

        reWriteToFile();
        if(Answer.length() > 0)
            return to_string(ID);
        return "";
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




// size_t pos;
//         try
//         {
//             num = stoi(Number, &pos);
//             if (pos != Number.size())
//             {
//                 // The entire string was not converted to a number
//                 cerr << "Invalid argument: Not a valid number." << endl;
//                 continue;
//             }
//         }
//         catch (const std::invalid_argument&)
//         {
//             // Handle the invalid argument exception (e.g., print an error message)
//             cerr << "Invalid argument: Not a valid number." << endl;
//             continue;
//         }
//         catch (const std::out_of_range&)
//         {
//             // Handle the out-of-range exception (e.g., print an error message)
//             cerr << "Out of range: Number is too large or too small." << endl;
//             continue;
//         }