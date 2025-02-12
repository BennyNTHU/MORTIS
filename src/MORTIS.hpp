// MORTIS.hpp
// This file defines the MORTISInvariant type which is a std::variant that can hold various
// data structure types implemented in the MORTIS project.

#ifndef MORTIS_HPP
#define MORTIS_HPP

#include <variant>
#include <string>
#include <type_traits>

#include "array/GeneralArray/GeneralArray.hpp"
#include "array/Polynomial/Polynomial.hpp"
#include "array/SparseMatrix/SparseMatrix.hpp"
#include "array/String/String.hpp"
#include "container/Bag/Bag.hpp"

// Define a common variant type that can hold any of the supported data types.
using MORTISInvariant = std::variant<
    int,
    char,
    float,
    bool,
    double,
    std::string,
    GeneralArray<std::variant<int, char, float, bool, double, std::string>>,
    Polynomial, 
    SparseMatrix,
    String
>;

#endif
