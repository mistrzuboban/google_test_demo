//
// Created by U203872 on 12/29/17.
//

#ifndef GOOGLE_TEST_DEMO_DUMMYARRAYITERATOR_H
#define GOOGLE_TEST_DEMO_DUMMYARRAYITERATOR_H

#include <cstddef>
#include "DummyArray.h"

template <typename T, typename C, size_t const _size>
class DummyArrayIterator {

public:
    explicit DummyArrayIterator(C& collection, size_t const index) : collection(collection), index(index) {}

    // should be "explicit" but old gcc returns an error
    bool operator!= (DummyArrayIterator const & other) const {
        return index != other.index;
    }

    const T& operator* () const {
        return collection.getAt(index);
    }

    const DummyArrayIterator& operator++ () {
        ++index;
        return *this;
    }


private:
    size_t index {0};
    C& collection {};

};

template <typename T, size_t const _size>
using _DummyArrayIterator = DummyArrayIterator<T, DummyArray<T, _size>, _size>;

template<typename T, size_t const _size>
using _DummyArrayConstIterator = DummyArrayIterator<T, DummyArray<T, _size> const, _size>;

template<typename T, size_t const _size>
inline _DummyArrayIterator<T, _size> begin(DummyArray<T, _size>& collection) {
    return _DummyArrayIterator<T, _size>(collection, 0);
}

template<typename T, size_t const _size>
inline _DummyArrayIterator<T, _size> end(DummyArray<T, _size>& collection) {
    return _DummyArrayIterator<T, _size>(collection, collection.getSize());
}

template<typename T, size_t const _size>
inline _DummyArrayConstIterator<T, _size> begin(DummyArray<T, _size> const & collection) {
    return _DummyArrayConstIterator<T, _size>(collection, 0);
}

template<typename T, size_t const _size>
inline _DummyArrayConstIterator<T, _size> end(DummyArray<T, _size> const & collection) {
    return _DummyArrayConstIterator<T, _size>(collection, collection.getSize());
}


#endif //GOOGLE_TEST_DEMO_DUMMYARRAYITERATOR_H
