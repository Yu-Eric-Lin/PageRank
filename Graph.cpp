// Graph class
#include <queue>
#include <algorithm>
#include "Graph.h"
#include "Node.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <list>

using namespace std;

// Constructor for simple edgelist
Graph::Graph(string edgeListPath):hasFeatures(false)
{
    ifstream edgeList(edgeListPath.c_str());
    string line;

	// vector of distinct node IDs
    while (edgeList.good()) {
    	std::getline(edgeList, line);
    	istringstream ss(line);
    	int x, y;
    	ss >> x >> y;
	
    	if(adj.find(x) != adj.end())
    	{
			// adj contains the key x
			adj.insert(std::pair<int,vector<int> >(x, {}));
    	}
    	if(adj.find(y) != adj.end())
    	{
			// adj contains the key y
			adj.insert(std::pair<int,vector<int> >(y, {}));
    	}

        if (find(adj[x].begin(), adj[x].end(), y) == adj[x].end())
		    adj[x].push_back(y);
        if (find(adj[y].begin(), adj[y].end(), x) == adj[y].end())
		    adj[y].push_back(x);
    }

    cout << "The Graph has " << adj.size() << " nodes.\n";

}

// BFS using queue
void Graph::BFS(int start)
{

    queue<int> q;
    list<int> used;
    vector<int> path(adj.size());

    q.push(start);
    used.push_back(start);
    // path[] = 0
    while(!q.empty())
    {
        start = q.front();
        cout << start << " ";
        q.pop();

        for(unsigned i = 0; i < adj[start].size(); i++)
        {
            if (find(used.begin(), used.end(), adj[start][i]) == used.end())
            {
                q.push(adj[start][i]);
                used.push_back(adj[start][i]);
            }
        }
    }

    cout << endl;    
}

// Shortest path using bfs
void Graph::ShortestPath(int start, int end)
{
    queue<int> q;
    list<int> used;
    vector<int> path(adj.size());
    q.push(start);
    used.push_back(start);
    while(!q.empty())
    {
        start = q.front();
        cout << start << " ";
        if(start == end) break;
        q.pop();

        for(unsigned i = 0; i < adj[start].size(); i++)
        {
            if (find(used.begin(), used.end(), adj[start][i]) == used.end())
            {
                q.push(adj[start][i]);
                used.push_back(adj[start][i]);
            }
        }
    }

    cout << endl;
}

void Graph::addFeatures(string featPath, string featnamesPath) 
{
    
    ifstream featNameList(featnamesPath.c_str());
    string line;
	// vector of names of features in order of data
    while (featNameList.good()) {
    	std::getline(featNameList, line);
    	istringstream ss(line);
    	int x;
        string y;
    	ss >> x >> y;

        features.push_back(y);
    }

    ifstream featureList(featPath.c_str());
    // parse each line of features file into Node ID (x) and string of bools corresponding to featNames (y)
    while (featureList.good()) {
    	std::getline(featureList, line);
    	istringstream ss(line);
    	int id;
    	ss >> id;

        // remove spaces in each string of bools corresponding to featNames
        string featureBools;
        for (auto chr : line) {
            if (chr == '0' || chr == '1') {
                featureBools = featureBools + chr;
            }
        }

        // create new vector of allFeatures and insert into new Node
        vector<string> allFeats;
        for (unsigned i = 0; i < features.size(); i++) {
            if (featureBools[i] == '1') {
                allFeats.push_back(features[i]);
            }
        }

        // insert new Node into vector of featureNodes
        featureNodes.push_back(Node(id, allFeats, featureBools));
    }
    
}