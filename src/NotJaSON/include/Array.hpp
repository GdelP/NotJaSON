#pragma once
#include "Configuration.hpp"

namespace NotJaSON {
  /// A JSON Array is no more than an object whose members have no keys. We repeat here the implementation with slightly different details for efficiency and extensibility.
  struct Array {
    /// Number of members of this object. In case type is indicated it talks about those who have that type.
    std::size_t size() const;
    std::size_t size_strings() const;
    /// TODO: Differentiate between integers and floating point values.
    std::size_t size_numbers() const;
    std::size_t size_objects() const;
    std::size_t size_arrays() const;
    std::size_t size_bools() const;
    std::size_t size_nulls() const;
    
    /// Functions that return if the indicated position is of the indicated type.
    /// @warning It's less efficient consult by position than consult by key.
    bool is_string(std::size_t const aPosition) const;
    bool is_number(std::size_t const aPosition) const;
    bool is_object(std::size_t const aPosition) const;
    bool is_array(std::size_t const aPosition) const;
    bool is_bool(std::size_t const aPosition) const;
    bool is_null(std::size_t const aPosition) const;


    /// Retrive members
    String const& string_at(std::size_t const aPosition) const throw(std::runtime_error);
    String& string_at(std::size_t const aPosition) throw(std::runtime_error);
    Number const& number_at(std::size_t const aPosition) const throw(std::runtime_error);
    Number& number_at(std::size_t const aPosition) throw(std::runtime_error);
    Object const& object_at(std::size_t const aPosition) const throw(std::runtime_error);
    Object& object_at(std::size_t const aPosition) throw(std::runtime_error);
    Array const& array_at(std::size_t const aPosition) const throw(std::runtime_error);
    Array& array_at(std::size_t const aPosition) throw(std::runtime_error);
    Bool const& bool_at(std::size_t const aPosition) const throw(std::runtime_error);
    Bool& bool_at(std::size_t const aPosition) throw(std::runtime_error);

  protected:
    std::map<std::size_t, String> mMemberStrings;
    std::map<std::size_t, Number> mMemberNumbers;
    std::map<std::size_t, Object> mMemberObjects;
    std::map<std::size_t, Array> mMemberArrays;
    std::map<std::size_t, Bool> mMemberBools;
    /// A JSON Object member may be a null value. We count them non-explicitly. We should be able to disallow null values.
    /// Semantically it's a set. We know there will be no repeated elements by definition.
    /// Invariant: there are no repeated elements inside the vector
    std::vector<std::size_t> mMemberNulls;
    
  };
}
