#include <iostream>

void Interface::printOptions(){
    std::cout<<"["<<Interface::ADD_VERTEX<<"] dodaj wierzchołek"<<std::endl;
    std::cout<<"["<<Interface::ADD_EDGE<<"] dodaj krawędź"<<std::endl;
    std::cout<<"["<<Interface::PRINT_VERTEXES<<"] wypisz wierzchołki"<<std::endl;
    std::cout<<"["<<Interface::ARE_CONNECTED<<"] sprawdź czy są połączone"<<std::endl;
    std::cout<<"["<<Interface::REMOVE_EDGE<<"] usuń krawędź"<<std::endl;
    std::cout<<"["<<Interface::LEAVE<<"] zakończ"<<std::endl;
}

template<class DataType>
void Interface::manageGraph( Graph<DataType>& graph ){
    int firstIndex, secondIndex;
    printOptions();
    while(true){
         int option = userInputInt();
        switch(option){
        case Interface::ADD_VERTEX:{//so far only works for graphs containing string
            std::string input = userInputString();
            graph.addVertex( input );
            }break;
        case Interface::ADD_EDGE:{
            userIndexesInput(firstIndex, secondIndex);
            graph.addEdge(firstIndex, secondIndex);
            }break;
        case Interface::PRINT_VERTEXES:{
            printVertexes(graph);
            }break;
        case Interface::ARE_CONNECTED:{
            userIndexesInput(firstIndex, secondIndex);
            if( graph.areConnected(firstIndex, secondIndex) )
                std::cout<<"TAK"<<std::endl;
            else
                std::cout<<"NIE"<<std::endl;
            }break;
        case Interface::REMOVE_EDGE:{
            userIndexesInput(firstIndex, secondIndex);
            graph.removeEdge(firstIndex, secondIndex);
            }break;
        case Interface::LEAVE:{
            return;
            }
        default:{
            }break;
        }
    }
}

int Interface::userInputInt(){
	int input;
	std::cin>>input;

	while(std::cin.fail()){
		std::cin.clear();
		std::cin.ignore();
		std::cin>>input;
	}
	std::cin.clear();

	return input;
}

std::string Interface::userInputString(){
    std::string input;
    std::cin>>input;

    return input;
}

void Interface::userIndexesInput(int& firstIndex, int& secondIndex){
    std::cout<<"Podaj pierwszy index:"<<std::endl;
    firstIndex = userInputInt();
    std::cout<<"Podaj drugi index:"<<std::endl;
    secondIndex = userInputInt();
}
template<class DataType>
void Interface::printVertexes( const Graph<DataType> graph){
    int graph_size = graph.getSize();
    for( int i = 0; i<graph_size; ++i){
    std::cout<<i<<": "<<graph[i]<<std::endl;
    }
}
