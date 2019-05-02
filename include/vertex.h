#ifndef _VERTEX_H_
#define _VERTEX_H_

template <class DataType>
class Vertex{
public:
    Vertex(DataType newData, int initIndex): data(newData), index(initIndex){}
    DataType& getData(){ return data; }
    DataType getConstData() const { return data; }
    int getIndex() const { return index; }
private:
    DataType data;
    int index;
};

#endif
