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
    void addEdge( int firstIndex, int secondIndex );
    void removeEdge( int firstIndex, int secondIndex );
    DataType& operator[](int vertexIndex);
    DataType operator[](int vertexIndex) const;
private:
    std::vector<Vertex<DataType>> vertexes;
    std::vector< std::vector<int> > adjacencyList;
    int numberOfVertexes;

    bool isEdge(int firstIndex, int secondIndex);
    //bool isVertex(DataType);//TO DO
    void removeEdgeFromVector(int firstIndex, int secondIndex);
};


#endif
