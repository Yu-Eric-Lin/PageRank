// main file
#include "Graph.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    // Create Twitter Data Files
    // User ID 12831 
    string edges("data/12831.edges");
    string feat("data/12831.feat");
    string featnames("data/12831.featnames");

    // User ID 13212502 (uncomment this and comment the other data files to test)
    // string edges("data/13212502.edges");
    // string feat("data/13212502.feat");
    // string featnames("data/13212502.featnames");

    // User ID 14836915 (uncomment this and comment the other data files to test)
    // string edges("data/14836915.edges");
    // string feat("data/14836915.feat");
    // string featnames("data/14836915.featnames");


    // Create a graph of the data

    Graph test(edges);
    // test.BFS(22253); //return bfs
    // //test.BFS(12345); //return "invalid node"

    // std::cout << std::endl << "Shortest Path:" << std::endl;
    // Graph test2(edges);
    // //test2.ShortestPath(14305022, 8479062); //return shortest path
    // test2.ShortestPath(12,34); // return invalid node


    // Test our Algorithms

    // Graph test("test_data/test.edges");
    test.PageRank();
    // test.addFeatures(circles, egofeat, feat, featnames);

}