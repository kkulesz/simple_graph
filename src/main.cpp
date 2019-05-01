#include <iostream>
#include <string.h>
#include "graph.tcc"//need to be this way in order to compilator know the implementation



int main(){
    Graph<int> int_graph;
    int a =5;
    int_graph.addVertex(a);
    std::cout<<int_graph[0]<<std::endl;
    int_graph.addVertex(a);
    std::cout<<int_graph[1]<<std::endl;
    //std::cout<<int_graph[2]<<std::endl;

    return 0;
}
