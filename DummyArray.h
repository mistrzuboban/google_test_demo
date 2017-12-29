//
// Created by U203872 on 12/29/17.
//

#ifndef GOOGLE_TEST_DEMO_DUMMY_ARRAY_H
#define GOOGLE_TEST_DEMO_DUMMY_ARRAY_H


#include <stdexcept>

template<class T, size_t const _size>
class DummyArray {

    T data[_size];

public:

    T const &getAt(int const index) const;

    void setAt(const int index, T const &value) {
        if (index < _size) {
            data[index] = value;
        } else {
            throw std::out_of_range("out of range error");

        }
    }

    const size_t getSize() const {
        return _size;
    }
};

template<class T, size_t _size>
T const & DummyArray<T, _size>::getAt(int const index) const {
    if (index < _size) {
        return data[index];
    } else {
        throw std::out_of_range("error"); // return 0 to see errors;
    }
}

#endif //GOOGLE_TEST_DEMO_DUMMY_ARRAY_H
