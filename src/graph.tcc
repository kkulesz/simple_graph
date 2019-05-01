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
bool Graph<DataType>::addEdge( int firstIndex, int secondIndex ){
    if( firstIndex == secondIndex || firstIndex >= numberOfVertexes || secondIndex >= numberOfVertexes){
        return false;
    }
    if( this->isEdge(firstIndex, secondIndex) ){
        return true;
    }else{
        this->adjacencyList[firstIndex].push_back(secondIndex);
        this->adjacencyList[secondIndex].push_back(firstIndex);
    }

    return true;
}

template <class DataType>
bool Graph<DataType>::removeEdge( int firstIndex, int secondIndex ){
    if( firstIndex >= numberOfVertexes || secondIndex >= numberOfVertexes){
        return false;
    }
    if( this->isEdge(firstIndex, secondIndex) ){
        return true;
    }else{
        this->removeEdgeFromVector(firstIndex, secondIndex);
        this->removeEdgeFromVector(secondIndex, firstIndex);
    }
    return true;
}

template <class DataType>
DataType& Graph<DataType>::operator[]( int vertexIndex ){
    if(vertexIndex >= numberOfVertexes){
        return NULL;
    }
    return this->vertexes[vertexIndex].getData();
}

/*
template <class DataType>
DataType Graph<DataType>::operator[]( int vectorIndex ) const{
    return this->vertexes[vectorIndex].getData();
}
*/
template <class DataType>
bool Graph<DataType>::isEdge(int firstIndex, int secondIndex){
    if( firstIndex >= numberOfVertexes || secondIndex >= numberOfVertexes){
        return true;;
    }
    int size = this->adjacencyList[firstIndex].size();
    for( int i = 0; i<size; ++i ){
        if( this->adjacencyList[firstIndex][i] == secondIndex ){
            return true;
        }
    }
    return false;
}

template <class DataType>
bool Graph<DataType>::removeEdgeFromVector(int firstIndex, int secondIndex){
    if( firstIndex >= numberOfVertexes || secondIndex >= numberOfVertexes){
        return false;
    }
    int size = this->adjacencyList[firstIndex].size();
    for( int i=0; i<size; ++i){
        if( this->adjacencyList[firstIndex][i] == secondIndex ){
            this->adjacencyList[firstIndex].erase( this->adjacencyList[firstIndex].begin() + i);
            break;
        }
    }

    return true;
}
