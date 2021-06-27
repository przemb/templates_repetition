#pragma once

// Pair class from partial specialization demo

template <typename T, typename U>
class Pair {
    T a_;
    U b_;
public:
    Pair() : a_{}, b_{} {}
    Pair(const T& a, const U& b) : a_{a}, b_{b} {}

    T first() const { return a_;  } 
    U second() const { return b_; }
};