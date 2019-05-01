#include <iostream>
#include <string.h>
#include "graph.tcc"//need to be this way in order to compilator know the implementation
#include "bfs.tcc"

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

    std::vector<int> vec;
    int_graph.BFS(3, vec);

    int length = vec.size();
    for( int i=0; i<length; ++i){
        std::cout<<vec[i]<<std::endl;
    }

    return 0;
}

template <class DataType>
void printVertexes(Graph<DataType> graph_to_print){
    int graph_size = graph_to_print.getSize();
    for( int i = 0; i<graph_size; ++i){
    std::cout<<i<<": "<<graph_to_print[i]<<std::endl;
    }
}
