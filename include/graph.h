#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include "vertex.h"

template <class DataType>
class Graph{
public:

    Graph<DataType>(): numberOfVertexes(0){}
    ~Graph<DataType>(){}
    void addVertex(const DataType&);
    bool addEdge( int firstIndex, int secondIndex );
    bool removeEdge( int firstIndex, int secondIndex );
    DataType& operator[](int vertexIndex);
    DataType operator[](int vertexIndex) const;
    int getSize() const {return numberOfVertexes;}

    bool areConnected( int firstIndex, int secondIndex);


private:
    std::vector<Vertex<DataType>> vertexes;
    std::vector< std::vector<int> > adjacencyList;
    int numberOfVertexes;

    bool isEdge(int firstIndex, int secondIndex);
    bool removeEdgeFromVector(int firstIndex, int secondIndex);
    bool BFS( int startIndex, std::vector<int>& visitedIndexes );
    bool checkIndex( int indexToCheck );
};

#include "graph.tcc"
#include "bfs.tcc"

#endif
