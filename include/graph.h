#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include "vertex.h"

template <class DataType>
class Graph{
public:
    Graph(): numberOfVertexes(0){}
    void addVertex(DataType);
    void addEdge(Vertex<DataType>, Vertex<DataType>);
    void removeEdge(Vertex<DataType>, Vertex<DataType>);
private:
    std::vector<Vertex<DataType>> vertexes;
    std::vector< std::vector<int> > adjacentList;
    int numberOfVertexes;

    bool isEdge(int firstIndex, int secondIndex);
    bool isVertex(DataType);//TO DO
    void removeEdgeFromVector(int firstIndex, int secondIndex);
};

#endif
