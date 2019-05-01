#include "assert.h"
#include "graph.h"

template <class DataType>
void Graph<DataType>::addVertex(const DataType& newElement ){
    Vertex<DataType> newVertex(newElement, this->numberOfVertexes);
    this->vertexes.push_back(newVertex);
    ++(this->numberOfVertexes);

    std::vector<int> newAdjacencyList;
    this->adjacencyList.push_back( newAdjacencyList );
}

template <class DataType>
void Graph<DataType>::addEdge( int firstIndex, int secondIndex ){
    if( this->isEdge(firstIndex, secondIndex) ){
        return;
    }else{
        this->adjacencyList[firstIndex].push_back(secondIndex);
        this->adjacencyList[secondIndex].push_back(firstIndex);
    }
}

template <class DataType>
void Graph<DataType>::removeEdge( int firstIndex, int secondIndex ){
    if( this->isEdge(firstIndex, secondIndex) ){
        return;
    }else{
        this->removeEdgeFromVector(firstIndex, secondIndex);
        this->removeEdgeFromVector(secondIndex, firstIndex);
    }
}

template <class DataType>
DataType& Graph<DataType>::operator[]( int vectorIndex ){
//
    assert( vectorIndex < numberOfVertexes );
//
    return this->vertexes[vectorIndex].getData();
}

/*
template <class DataType>
DataType Graph<DataType>::operator[]( int vectorIndex ) const{
    return this->vertexes[vectorIndex].getData();
}
*/
template <class DataType>
bool Graph<DataType>::isEdge(int firstIndex, int secondIndex){
    int size = this->adjacencyList[firstIndex].size();
    for( int i = 0; i<size; ++i ){
        if( this->adjacencyList[firstIndex][i] == secondIndex ){
            return true;
        }
    }
    return false;
}
/*
template <class DataType>
bool Graph<DataType>::isVertex(DataType newElement){
//
    return true;
}
*/
template <class DataType>
void Graph<DataType>::removeEdgeFromVector(int firstIndex, int secondIndex){
    int size = this->adjacencyList[firstIndex].size();
    for( int i=0; i<size; ++i){
        if( this->adjacencyList[firstIndex][i] == secondIndex ){
            this->adjacencyList[firstIndex].erase( this->adjacencyList[firstIndex].begin() + i);
            break;
        }
    }
}
