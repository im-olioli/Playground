#pragma once

#include <cstdlib>

template <typename T>
class Array
{
    T* data_;
    long long capacity_;
    long long size_;
public:
    Array();
    ~Array();
    void push_back(const T& value);
    void reserve(long long expected_capacity);
    void resize(long long expected_size);
    void resize(long long expected_size, const T& value);
    void push_front(const T& value);
    void insert(long long before, const T& value);
    void space(long long before, long long count);
    void remove(long long index);
    void remove(long long index, long long count);
    void copy(long long before, Array<T>& copy);
    long long size() const;
    T& operator[](long long index);
};

template <typename T>
Array<T>::Array() : data_(nullptr), capacity_(0), size_(0) { }

template <typename T>
Array<T>::~Array()
{
    for (long long x = 0; x < size_; x++)
    {
        data_[x].~T();
    }
    free(data_);
}

template <typename T>
void Array<T>::push_back(const T& value)
{
    if(capacity_ < (size_ + 1))
    {
        const long long new_capacity = (capacity_ + 1) * 2;
        reserve(new_capacity);
    }
    
    data_[size_] = value;

    size_++;
}

template <typename T>
void Array<T>::reserve(const long long expected_capacity)
{
    if(expected_capacity < capacity_) return;

    capacity_ = expected_capacity;

    if(data_ == nullptr)
        data_ = static_cast<T*>(malloc(sizeof(T) * expected_capacity));
    else
        data_ = static_cast<T*>(realloc(data_, sizeof(T) * expected_capacity));
}

template <typename T>
void Array<T>::resize(const long long expected_size)
{
    if(size_ >= expected_size)
    {
        size_ = expected_size;
    }else
    {
        reserve(expected_size);
        for (long long x = size_; x < expected_size; x++)
        {
            new ( &data_[x] ) T;
        }
        
        size_ = expected_size;
    }
}

template<typename T>
void Array<T>::resize(const long long expected_size, const T& value)
{
    if(size_ >= expected_size)
    {
        size_ = expected_size;
    }else
    {
        reserve(expected_size);
        for (long long x = size_; x < expected_size; x++)
        {
            data_[x] = value;
        }
        
        size_ = expected_size;
    }
}

template <typename T>
void Array<T>::push_front(const T& value)
{
    insert(0, value);
}
template <typename T>
void Array<T>::insert(const long long before, const T& value)
{
    space(before, 1);
    
    data_[before] = value;
}
template <typename T>
void Array<T>::space(const long long before, const long long count)
{
    const long long old_size = size_;
    
    resize(size_ + count);
    
    for(long long i = old_size - 1; i >= before; --i)
    {
        data_[i + count] = data_[i];
    }
}
template <typename T>
void Array<T>::remove(const long long index)
{
    for(int i = index; i < size_ - 1; ++i)
    {
        data_[i] = data_[i + 1];
    }
    
    size_ -= 1;
}

template <typename T>
void Array<T>::remove(const long long index, const long long count)
{
    for(int i = index; i < size_ - count; ++i)
    {
        data_[i] = data_[i + count];
    }
    
    size_ -= count;
}

template <typename T>
void Array<T>::copy(long long before, Array<T>& copy)
{
    space(before, copy.size());
    
    for(int i = before; i < before + copy.size(); i++)
    {
        data_[i] = copy[i - before];
    }
}

template <typename T>
long long Array<T>::size() const
{
    return size_;
}

template <typename T>
T& Array<T>::operator[](long long index)
{
    return data_[index];
}