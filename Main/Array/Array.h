#pragma once

#include <cstdlib>

template <typename T>
class Array
{
    T* data_;
    size_t capacity_;
    size_t size_;

public:
    Array();
    ~Array();
    void push_back(const T& value);
    void reserve(size_t expected_capacity);
    void resize(size_t expected_size);
    void resize(size_t expected_size, const T& value);
    size_t size() const;
    T& operator[](size_t index);
};

template <typename T>
Array<T>::Array() : data_(nullptr), capacity_(0), size_(0) { }

template <typename T>
Array<T>::~Array()
{
    for (size_t x = 0; x < size_; x++)
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
        const size_t new_capacity = (capacity_ + 1) * 2;
    
        reserve(new_capacity);
    }
    
    data_[size_] = value;

    size_++;
}

template <typename T>
void Array<T>::reserve(const size_t expected_capacity)
{
    if(expected_capacity < capacity_) return;

    capacity_ = expected_capacity;

    if(data_ == nullptr)
        data_ = static_cast<T*>(malloc(sizeof(T) * expected_capacity));
    else
        data_ = static_cast<T*>(realloc(data_, sizeof(T) * expected_capacity));
}

template <typename T>
void Array<T>::resize(const size_t expected_size)
{
    if(size_ >= expected_size)
    {
        size_ = expected_size;
    }else
    {
        reserve(expected_size);

        for (size_t x = size_; x < expected_size; x++)
        {
            new ( &data_[x] ) T;
        }
        
        size_ = expected_size;
    }
}

template<typename T>
void Array<T>::resize(size_t expected_size, const T& value)
{
    if(size_ >= expected_size)
    {
        size_ = expected_size;
    }else
    {
        reserve(expected_size);

        for (size_t x = size_; x < expected_size; x++)
        {
            data_[x] = value;
        }
        
        size_ = expected_size;
    }
}

template <typename T>
size_t Array<T>::size() const
{
    return size_;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    return data_[index];
}