#include <dataObject.hpp>

using namespace dataObject;

template <class T>
List<T>::List(){}

template <class T>
List<T>::~List(){}

template <class T>
int List<T>::getSize() const{
    return 0;
}

template <class T>
const char *List<T>::getType() const{
    return "List";
}