#include <iostream>
#include <vector>
#include <string>
#include "hands.cpp"
#include "recommendation.cpp"

using namespace std;

void Recommend(string curr_user) 
{
    system("cls");
    Recommendation obj;
    vector<string> following;

    vector<string> vertices;
    string filename = "registrationdata/"+curr_user+".txt";
    following = obj.getFollowingInfo(filename); // profile
    vector<vector<string>> ffUsers;

    for (const auto& user : following) {
        string fileName ="registrationdata/"+ user + ".txt";   //profile used
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
        // cout << user[0] << " "<<user[1]<<endl;
        string temp = user[0];
        for (int i = 1; i < user.size(); i++) {
            graph.addEdge(temp, user[i]);
            cout << user[i] << ' ';
        }
    }

    graph.displayDisconnectedVertices(curr_user);
    // graph.printAllEdges();

    cout << "done\n";
}

int main()
{
    Recommend("bhowmik123");
    return 0;
}