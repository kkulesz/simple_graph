#include <iostream>
#include <fstream>

void Interface::printOptions(){
    std::cout<<"["<<Interface::ADD_VERTEX_<<"] dodaj wierzchołek"<<std::endl;
    std::cout<<"["<<Interface::ADD_EDGE_<<"] dodaj krawędź"<<std::endl;
    std::cout<<"["<<Interface::PRINT_VERTEXES_<<"] wypisz wierzchołki"<<std::endl;
    std::cout<<"["<<Interface::ARE_CONNECTED_<<"] sprawdź czy są połączone"<<std::endl;
    std::cout<<"["<<Interface::REMOVE_EDGE_<<"] usuń krawędź"<<std::endl;
    std::cout<<"["<<Interface::REAF_FROM_FILE_<<"] wczytaj z pliku"<<std::endl;
    std::cout<<"["<<Interface::LEAVE_<<"] zakończ"<<std::endl;
}

template<class DataType>
void Interface::manageGraph( Graph<DataType>& graph ){
    int firstIndex, secondIndex;
    printOptions();
    while(true){
        std::cout<<"-----------------"<<std::endl;
        int option = userInputInt_();
        switch(option){
        case Interface::ADD_VERTEX_:{
        //works for graphs containing string
            std::string input = userInputString_();
            graph.addVertex( input );
        }break;
        case Interface::ADD_EDGE_:{
            userIndexesInput_(firstIndex, secondIndex);
            graph.addEdge(firstIndex, secondIndex);
        }break;
        case Interface::PRINT_VERTEXES_:{
            printVertexes_(graph);
        }break;
        case Interface::ARE_CONNECTED_:{
            userIndexesInput_(firstIndex, secondIndex);
            if( graph.areConnected(firstIndex, secondIndex) )
                std::cout<<"TAK"<<std::endl;
            else
                std::cout<<"NIE"<<std::endl;
        }break;
        case Interface::REMOVE_EDGE_:{
            userIndexesInput_(firstIndex, secondIndex);
            graph.removeEdge(firstIndex, secondIndex);
        }break;
        case Interface::REAF_FROM_FILE_:{
        //works for graphs containing string
            readVertexesFromFile_(graph);
        }break;
        case Interface::LEAVE_:{
            return;
        }
        default:{
        }break;
        }
    }
}

template<class DataType>
void Interface::readVertexesFromFile_( Graph<DataType>& graph ){
    std::cout<<"podaj nazwe pliku:"<<std::endl;
    std::string fileNAme = userInputString_();
    std::ifstream readFile;
    readFile.open( fileNAme );
    if( readFile.is_open() ){
        std::string new_vertex_value;
        while( true ){
            getline( readFile,new_vertex_value );
            if( readFile.eof() ){
                break;
            }
            graph.addVertex(new_vertex_value);
        }

    }else{
        std::cout<<"błąd podczas otwierania pliku"<<std::endl;
    }
    readFile.close();
}

int Interface::userInputInt_(){
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

std::string Interface::userInputString_(){
    std::string input;
    std::cin>>input;

    return input;
}

void Interface::userIndexesInput_(int& firstIndex, int& secondIndex){
    std::cout<<"Podaj pierwszy index:"<<std::endl;
    firstIndex = userInputInt_();
    std::cout<<"Podaj drugi index:"<<std::endl;
    secondIndex = userInputInt_();
}
template<class DataType>
void Interface::printVertexes_( const Graph<DataType> graph){
    int graph_size = graph.getSize();
    for( int i = 0; i<graph_size; ++i){
    std::cout<<i<<": "<<graph[i]<<std::endl;
    }
}
