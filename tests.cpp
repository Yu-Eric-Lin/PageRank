// #include "cs225/catch/catch.hpp"

// #include "Graph.h"
// #include <iostream>
// #include <fstream>

// using namespace std;

// int main()
// {
//     // Test 1: Constructor
//     Graph test("test_data/test.edges");
//     cout << "This should have 6 nodes.\n" << endl;

//     // Test 2: BFS
//     test.BFS(0);
//     cout << "This should contain the nodes: 0, 1, 2, 3, 4, 5.\n" << endl;

//     // Test 3: shortest path
//     test.ShortestPath(2, 4);
//     cout << "The path is 2 1 0 5 4.\n" << endl;

//     // Test 4: pagerank
//     test.PageRank();
//     cout << "The top node should be node 2 at 33.33%." << endl;

// }