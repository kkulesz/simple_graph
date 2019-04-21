#include "graph.h"

template <class DataType>
void Graph<DataType>::addVertex( DataType newElement ){
    Vertex<DataType> newVertex(newElement, this->numberOfVertexes);
    this->vertexes.push_back(newVertex);
    ++(this->numberOfVertexes);

    std::vector<int> newAdjacentList;
    this->adjacentList.push_back( newAdjacentList );
}

template <class DataType>
void Graph<DataType>::addEdge(Vertex<DataType> firstVertex, Vertex<DataType> secondVertex){
    int firstIndex = firstVertex.getIndex();
    int secondIndex = secondVertex.getIndex();
    if( this->isEdge(firstIndex, secondIndex) ){
        return;
    }else{
        this->adjacentList[firstIndex].push_back(secondIndex);
        this->adjacentList[secondIndex].push_back(firstIndex);
    }
}

template <class DataType>
void Graph<DataType>::removeEdge( Vertex<DataType> firstVertex, Vertex<DataType> secondVertex){
    int firstIndex = firstVertex.getIndex();
    int secondIndex = secondVertex.getIndex();
    if( this->isEdge(firstIndex, secondIndex) ){
        return;
    }else{
        this->removeEdgeFromVector(firstIndex, secondIndex);
        this->removeEdgeFromVector(secondIndex, firstIndex);
    }
}

template <class DataType>
bool Graph<DataType>::isEdge(int firstIndex, int secondIndex){
    int size = this->adjacentList[firstIndex].size();
    for( int i = 0; i<size; ++i ){
        if( this->adjacentList[firstIndex][i] == secondIndex ){
            return true;
        }
    }
    return false;
}

template <class DataType>
bool Graph<DataType>::isVertex(DataType newElement){
    /*
    TO DO
    */
    return true;
}

template <class DataType>
void Graph<DataType>::removeEdgeFromVector(int firstIndex, int secondIndex){
    int size = this->adjacentList[firstIndex].size();
    for( int i=0; i<size; ++i){
        if( this->adjacentList[firstIndex][i] == secondIndex ){
            this->adjacentList[firstIndex].erase( this->adjacentList[firstIndex].begin() + i);
            break;
        }
    }
}
