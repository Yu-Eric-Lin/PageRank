// Node class
#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Node {
    private:
    std::vector<std::string> features;
    int id;

    public:

    // Constructor
    Node(int newId, std::vector<std::string> allFeatures, std::string featureList):id(newId)
    {
        istringstream checks(featureList);
        string check;
        string feature;

        for (unsigned i = 0; i < allFeatures.size(); i++)
        {
            checks >> check;
            feature = allFeatures[i];

            if (check == "1")
                features.push_back(feature);
        }
    }

    // gets the id of the node
    int getId()
    {
        return id;
    }

    // gets list of features of string
    std::vector<std::string> getFeatures() 
    {
        return features;
    }

    // checks if feature is present in Node
    bool hasFeature(std::string feature) 
    {
        for (unsigned i = 0; i < features.size(); i++)
        {
            if (features[i] == feature)
                return true;
        }

        return false;
    }
};