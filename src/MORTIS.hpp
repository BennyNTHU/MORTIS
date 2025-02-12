// MORTISInvariant.hpp
// This file defines the MORTISInvariant type which is a std::variant that can hold various
// data structure types implemented in the MORTIS project.

#ifndef MORTIS_HPP
#define MORTIS_HPP

#include <variant>
#include <string>
#include <type_traits>

// Include headers for data structures that you want to support.
#include "array/GeneralArray/GeneralArray.hpp"
#include "array/Polynomial/Polynomial.hpp"
#include "array/SparseMatrix/SparseMatrix.hpp"
#include "array/String/String.hpp"
#include "container/Bag/Bag.hpp"

// You can add additional includes here for container, chain, tree, graph, etc.

// Define a common variant type that can hold any of the supported data types.
using MORTISInvariant = std::variant<
    int,
    char,
    float,
    bool,
    double,
    std::string,
    GeneralArray<std::variant<int, char, float, bool, double, std::string>>,   // assuming GeneralArray is defined appropriately
    Polynomial,     // assuming Polynomial is defined appropriately
    SparseMatrix,   // assuming SparseMatrix is defined appropriately
    String          // assuming String is defined appropriately
    // Add additional types here as needed.
>;

#endif // MORTISVARIANT_HPP
