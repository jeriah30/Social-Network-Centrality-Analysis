/* 
    Name: Jeriah Garcia
    Date: 12/9/24
    Description of Code: My code implements a system for processing and analyzing a directed social graph based on user connections, focusing on the relationships 
    between followers and following. The program identifies a root user with the highest in-degree centrality, then goes through the graph nodes using 
    Breadth-First Search (BFS) up to a depth of two, and outputs the results in a format that includes user depths and alphabetical sorting. This sorting approach 
    first organizes the internal nodes alphabetically, and once the first internal node is identified, its leaf nodes are sorted and processed before moving on to 
    the next internal nodes. The first file "main.cpp" reads input from a file, analyzes the data by adding edges between users, calculates centrality to 
    determine the root user, performs BFS, and displays results. The Graph class, defined in "Graph.h" and implemented in "Graph.cpp", serves as the foundational 
    class for the graph structure, storing users as dynamically allocated Username objects and maintaining relationships through adjacenct mappings. The Username 
    class, defined in "Project4b.h" and implemented in "Project4b.cpp". It represents individual users, managing follower and following relationships while 
    performing operations such as adding connections and sorting followers alphabetically. The CentralityGraph class, defined in "Project4a.h" and implemented in 
    "Project4a.cpp", extends the Graph class to introduce functionality for calculating centrality, performing BFS, and formatting the output. The code's purpose is 
    to analyze social network relationships, where you analyze users connected to a root user, including depth-based sorting and proper alphabetical ordering. 
    Additionally, the program ensures handling duplicate user appearances at different depths. 
*/

//include libraries that your code uses
#include "Project4a.h"
#include <iostream>
#include <sstream>
#include <fstream> 
#include <cctype>
#include <map>
#include <vector>

using namespace std;

string toLowerCase(string userStr) {
    for (char &chr : userStr) {
        chr = tolower(static_cast<unsigned char>(chr)); 
    }
    return userStr;
}

void readFile(const string &fileName, CentralityGraph &graph) {
    ifstream inFS(fileName);
    string line, user, follower;
    
    if (!inFS.is_open()) {
        cout << "Could not open input file: " << fileName << endl;
        return;
    }

    while (getline(inFS, line)) {
        istringstream inSS(line);
        inSS >> user >> follower;

        user = toLowerCase(user);
        follower = toLowerCase(follower);

        graph.addEdge(user, follower);
    }
    inFS.close();
}
///////////////// Before submitting your code
//1) uncomment this part since zyBooks use it.
int main(int argc, const char* argv[]) {
    if (argc != 2)
    {
        std::cout << "./project4 inputFile" << std::endl;
        return EXIT_FAILURE;
    }
    string inputFileName = argv[1];
    
///////////////////// uncomment above befofre submitting on zyBooks /////////////////
//2) Comment the next 2 lines below
//int main(void) {
    //string inputFileName = "input1.txt";    //Do NOT change the name "inputFileName" since used above

    //Add your code //
    
    //Reads the input file
    CentralityGraph graph;
    readFile(inputFileName, graph);
    
    //Calls the graph functions 
    graph.calcCentrality();
    string rootUser = graph.getUserRoot();
    graph.BFS(rootUser);

    //Displays the results.
    graph.printResults(rootUser);
    
    return 0;   
}