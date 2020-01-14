#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

#include <vector>
#include <initializer_list>
#include <ostream>

template <typename T>
class Less
{
private:

public:
  bool Compare(T, T);
};


template <typename T>
class Distance{
public:
  Distance(T val)
  : center{val}{}
  bool Compare(T, T);
private:
  T center{};

};



template <typename T>
class Sorted_Array
{
public:

    Sorted_Array() = default;
    Sorted_Array(std::initializer_list<T> list);

    Sorted_Array& operator=(std::initializer_list<T> list);

    void insert(T value);
    T erase(int index);

    T & operator[](int index);
    T operator[](int index) const;

    T & at(int index);
    T at(int index) const;

    int size() const;

private:

    std::vector<T> data{};
    Less<T> comp{};
    Distance<T> dist{10};

};


template <typename T>
std::ostream & operator<<(std::ostream & os, Sorted_Array<T> const & array);

#include "sorted_array.tcc"
#endif//SORTED_ARRAY_H
