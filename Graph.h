// Graph class header
#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class Graph {
    private:
	// dict of adjacent nodes (key node)
    std::map<int, vector<int> > adj;

	// vectore of Nodes with full features
	std::vector<Node> featureNodes;
	
	// features List & flag
	bool hasFeatures;
	std::vector<std::string> features;

	public:

	// Constructor for simple edgelist
	Graph(string edgeListPath);
	
	// BFS(start v)
	void BFS(int start);
	
	// PageRank()
	void PageRank();
	
	// ShortestPath(start v, end v)
	void ShortestPath(int start, int end);
	
	// initialize featureNodes
	void addFeatures(string featPath, string featnamesPath);
};