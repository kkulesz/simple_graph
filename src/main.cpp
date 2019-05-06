#include <iostream>
#include <string.h>
#include "graph.h"

template<class DataType>
void printVertexes(Graph<DataType> graph_to_print);

int main(){
    Graph<int> int_graph;

    int_graph.addVertex(13);
    int_graph.addVertex(10);
    int_graph.addVertex(251);
    int_graph.addEdge(0,1);
    int_graph.addEdge(0,2);
    int_graph.addEdge(1,2);
    int_graph.addVertex(1001);
    int_graph.addEdge(0,3);

    int_graph.addVertex(81);
    int_graph.addVertex(13);
    int_graph.addVertex(98);
    int_graph.addVertex(-10);
    int_graph.addEdge(4,5);
    int_graph.addEdge(5,7);
    int_graph.addEdge(6,7);
    int_graph.addEdge(0,7);

    printVertexes(int_graph);

    Graph<std::string> string_graph;
    string_graph.addVertex("xD");
    string_graph.addVertex("Kasiol");
    string_graph.addVertex(":(");
    string_graph.addVertex(":(");
    string_graph.addVertex(":(");
    string_graph.addEdge(0,1);
    string_graph.addEdge(1,2);
    string_graph.addEdge(2,3);
    string_graph.addEdge(3,4);
    if( string_graph.areConnected(0,4) )
        std::cout<<"TAK"<<std::endl;
    printVertexes(string_graph);


    return 0;
}

template <class DataType>
void printVertexes(Graph<DataType> graph_to_print){
    int graph_size = graph_to_print.getSize();
    for( int i = 0; i<graph_size; ++i){
    std::cout<<i<<": "<<graph_to_print[i]<<std::endl;
    }
}
