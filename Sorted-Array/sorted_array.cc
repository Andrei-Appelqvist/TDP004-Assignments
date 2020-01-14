// #include "sorted_array.h"

#include <utility>
#include <stdexcept>

using namespace std;
template <typename T>

Sorted_Array<T>::Sorted_Array(initializer_list <T> list)
    : data{}
{
    for (T val : list)
    {
        insert(val);
    }
}

template <typename T>
Sorted_Array<T> & Sorted_Array<T>::operator=(initializer_list <T> list)
{
    Sorted_Array tmp{list};
    swap(data, tmp.data);
    return *this;
}

template <typename T>
void Sorted_Array<T>::insert(T value)
{
    data.push_back(value);
    for (int i {size() - 1}; i > 0; --i)
    {
        if (data[i] < data[i-1])
        {
            swap(data[i-1], data[i]);
        }
        else
        {
            break;
        }
    }
}

template <typename T>
T Sorted_Array<T>::erase(int index)
{
    if (index < 0 || index >= size())
        throw std::out_of_range{"unable to erase; index is out of bounds."};
    for (int i {index}; i + 1 < size(); ++i)
    {
        swap(data[i], data[i+1]);
    }
    int value {data.back()};
    data.pop_back();
    return value;
}

template <typename T>
T & Sorted_Array<T>::operator[](int index)
{
    return data[index];
}

template <typename T>
T Sorted_Array<T>::operator[](int index) const
{
    return data[index];
}

template <typename T>
T & Sorted_Array<T>::at(int index)
{
    return data.at(index);
}

template <typename T>
T Sorted_Array<T>::at(int index) const
{
    return data.at(index);
}

template <typename T>
int Sorted_Array<T>::size() const
{
    return static_cast<T>(data.size());
}

template <typename T>
ostream & operator<<(ostream & os, Sorted_Array<T> const & array)
{
    if (array.size() == 0)
    {
        os << "{}";
        return os;
    }
    os << '{' << array[0];
    for (int i {1}; i < array.size(); ++i)
    {
        os << ", " << array[i];
    }
    os << '}';
    return os;
}
