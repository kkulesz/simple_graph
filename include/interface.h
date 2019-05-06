#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "string"
#include "graph.h"

class Interface{
public:
    void printOptions();

    template <class DataType>
    void manageGraph( Graph<DataType>& );

private:
    int userInputInt();
    std::string userInputString();
    void userIndexesInput(int& firstIndex, int& secondIndex);

    template<class DataType>
    void printVertexes( const Graph<DataType> );

    static const int LEAVE = 0;
    static const int ADD_VERTEX = 1;
    static const int ADD_EDGE = 2;
    static const int PRINT_VERTEXES = 3;
    static const int ARE_CONNECTED = 4;
    static const int REMOVE_EDGE = 5;

};

#include "interface.tcc"

#endif
