//
// Created by xiaowei on 2018/9/19.
//
#include <iostream>
#include <vector>

class Iterator{
public:
    virtual bool HasMore() = 0;
    virtual int Next() = 0;
};

class IDatasource
{
public:
    virtual Iterator * getIterator() = 0;

};

class DatasourceIterator : public Iterator
{
public:
    DatasourceIterator()
    {

    }
    virtual ~DatasourceIterator()
    {

    }
    bool HasMore() {
        return _datasouce.size() > index;
    }
    int Next() {
        return _datasouce[index++];
    }

public:
    int index = 0;
    std::vector<int> _datasouce = {1,2,3,4,5,6};
};

class Datasource:public IDatasource
{
public:
    Datasource() {

    }
    virtual ~ Datasource() {

    }
    Iterator * getIterator() {
        return new DatasourceIterator();
    }
};


int main()
{
    Datasource das;
    Iterator * iter = das.getIterator();
    while(iter->HasMore()) {
        std::cout << iter->Next() << std::endl;
    }
    delete iter;
    return 0;
}



