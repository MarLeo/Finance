//
// Created by marti on 08/04/2017.
//

#ifndef FINANCE_FUNCTOR_POINTER_CPP
#define FINANCE_FUNCTOR_POINTER_CPP

#include "functor_pointer.h"

template <typename T>
Functor<T>::Functor() {}

template <typename T>
Functor<T>::~Functor() {}

/*
template <class T> class Add : public Functor {

    public:
        Add() {};
        virtual double operator() (T left, T right) { return left + right; }
};


template <class T> class Multiply : public Functor {

public:
    Multiply() {};
    virtual double operator() (T left, T right) { return left * right; }
};
*/

template <typename T>
T Functor<T>::binary_op(T left, T right, Functor *f) {
    return (*f)(left, right);
}




/*template <typename T>
T Functor<T>::add(T left, T right) {
    return left + right;
}

template <typename T>
T Functor<T>::multiply(T left, T right) {
    return left * right;
}

template <typename T>
T Functor<T>::binary_op(T left, T right, T (*f)(T, T)) {
    return (*f)(left,right);
}*/







#endif





