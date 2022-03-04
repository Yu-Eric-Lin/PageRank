#include <queue>
#include <algorithm>
#include <cmath>
#include "Graph.h"
#include "Node.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <list>

using namespace std;

// how does this work?
void Graph::PageRank()
{
    unsigned size = adj.size();
    // cout << setprecision(3) << fixed;

    float M[size][size];
    vector<int> node_list;

    // Populate array with <node id, adjacency list size> pairs
    for(std::map<int, vector<int> >::iterator it = adj.begin(); it != adj.end(); it++)
    {
        node_list.push_back(it->first);
    }

    for (unsigned i = 0; i < size; i++)
    {
        for (unsigned k = 0; k < size; k++)
        {
            M[k][i] = 0.0;
        }
    }

    // Create markov matrix
    for(unsigned i = 0; i < size; i++)
    {
        vector<int> & nodes = adj[node_list[i]];

        for (unsigned k = 0; k < nodes.size(); k++)
        {
            if (nodes.size())
            {
                vector<int>::iterator it = find(node_list.begin(), node_list.end(), nodes[k]);
                int j = distance(node_list.begin(), it);

                M[j][i] = 1.0 / nodes.size();
            }
        }

        for (unsigned k = 0; k < size; k++)
        {
            if (!(M[k][i]))
                M[k][i] = 0.0;
        }
    }

    // perform power iteration to converge upon dominant eigenvector
    double prev[size];
    double sum = 0.0;
    double curr[size];
    double delta_norm;
    double norm;
    int z = 0;

    // set random seed
    srand(time(NULL));

    // populate starting vector in prev
    for (unsigned i = 0; i < size; i++)
    {
        
        prev[i] = ((float) rand());
        sum += prev[i];
    }

    // normalize the vector
    for (unsigned i = 0; i < size; i++)
    {
        prev[i] /= sum;
        curr[i] = prev[i];
    }

    float tol = pow(10, -6);

    do {
        delta_norm = 0.0;
        norm = 0.0;
        
        for (unsigned i = 0; i < size; i++) {
            curr[i] = 0.0;

            for (unsigned k = 0; k < size; k++) {
                curr[i] += M[i][k] * prev[k];
                delta_norm += pow(curr[i], 2);
            }
            delta_norm = sqrt(delta_norm);
        }

        if(delta_norm <= 0.0)
        {
            cout << "failed sorry" << endl;
            exit(-2);
        }

        for (unsigned k = 0; k < size; k++)
        {   
            curr[k] /= delta_norm;
            norm += pow((curr[k] - prev[k]), 2);
        }

        norm = sqrt(norm);

        for (unsigned i = 0; i < size; i++) {
            prev[i] = curr[i];
        }
        z++;
        
    } while (norm > tol && z < 1000);
    
    // sum up percentages to normalize them
    sum = 0.0;
    for (unsigned i = 0; i < size; i++)
    {
        sum += curr[i];
    }

    // display percentages by first adding to a list
    vector<pair<int, double> > result;

    for (unsigned i = 0; i < size; i++)
    {
        result.push_back(pair <int, double> (node_list[i], curr[i]/sum));
    }

    std::sort(result.begin(), result.end(), [](const std::pair<int, double> &x,
                                       const std::pair<int, double> &y)
    {
        return x.second > y.second;
    });

    cout << "[Node "<< result[0].first << ": " << result[0].second * 100.0 << "%, " << endl;
    for (unsigned i = 1; i < (size - 1)/10; i++)
    {
        cout << " Node "<< result[i].first << ": " << result[i].second * 100.0 << "%, " << endl;
    }

    cout << "........" << endl;

    for (unsigned i = 9*(size-1)/10; i < size -1; i++)
    {
        cout << " Node "<< result[i].first << ": " << result[i].second * 100.0 << "%, " << endl;
    }
    curr[size-1] /= sum;
    cout << " Node "<< result[size - 1].first << ": " << result[size - 1].second * 100.0 << "%]\n" << endl;

    cout << "The most popular user is user " << result[0].first << "!" << endl;;
}
