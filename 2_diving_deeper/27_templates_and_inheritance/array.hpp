#pragma once

template<typename T, int size = 10>
class Array {
    T value[size];
};

// inheriting from a template base
template <typename T>
class NewArray : public Array<T> {
};

NewArray<int> na;

// inheriting from a specialization
// this is not a template type
class IntArray : public NewArray<int> {
};


template<int size>
class IntArrayExtended : public Array<int, size> {
};