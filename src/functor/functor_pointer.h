//
// Created by marti on 09/04/2017.
//

#ifndef FINANCE_FUNCTOR_POINTER_H
#define FINANCE_FUNCTOR_POINTER_H

template <class T>
class Functor {

    public:

        Functor();

        /*T add(T left, T right);
        T multiply(T left, T right);
        T binary_op(T left, T right, T (*f)(T, T));*/
        virtual double operator() (T left, T right) = 0;
        T binary_op(T left, T right, Functor* f);

        virtual ~Functor();
};

#include "functor_pointer.cpp"
#endif //FINANCE_FUNCTOR_POINTER_H
