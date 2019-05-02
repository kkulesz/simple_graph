#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "graph.h"


TEST_CASE( "graph", "[graph], [functions]" ){
    Graph<int> int_graph;
    SECTION(" checking if size after initialization is equal 0 "){
        REQUIRE( int_graph.getSize() == 0);
    }

    int_graph.addVertex( 22 );
    int_graph.addVertex( 5 );
    int_graph.addVertex( 13 );
    int_graph.addVertex( 8 );
    int_graph.addVertex( -5 );
    int_graph.addVertex( 0 );

    SECTION(" adding new edge "){
        REQUIRE( int_graph.addEdge( 0,1 ) );
    }
    SECTION(" adding the same edge again "){
        REQUIRE( int_graph.addEdge( 0,1 ) );
    }

    std::vector<int> vec;
    int_graph.addEdge( 0,1 );
    int_graph.addEdge( 1,5 );
    SECTION("BFS"){
        REQUIRE( int_graph.BFS(0, vec) );
        REQUIRE( vec.size() == 3 );
        REQUIRE( vec[0] == 0 );
        REQUIRE( vec[1] == 1 );
        REQUIRE( vec[2] == 5 );
    }

    SECTION(" removing edge "){
        REQUIRE( int_graph.removeEdge( 0,1 ) );
    }
    SECTION(" adding edge between non-existing vertexes "){
        REQUIRE( !int_graph.addEdge( 100,101 ) );
    }
}
