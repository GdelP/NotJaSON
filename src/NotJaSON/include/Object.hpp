#pragma once
#include "Configuration.hpp"

namespace NotJaSON {
  /// A JSON Object is an ordered list of members. Every member is a key:value pair. Key is always an string. Value can be of different types.
  /// We decide NOT to renounce to strict static typing: we won't use a "value" concept anywhere.
  /// We decide to use maps from key(string) to value and position.
  /// Invariant: there can't be two different values on the same position.
  /// Order is important. However, we decide to use maps from keys to {position,value} tuples in order to improve efficiency for the ones who do not care about positions but about keys, the most usual use I've seen.
  /// @warning Note: remember NOT to import this into global namespace.
  struct Object {
    /// Number of members of this object
    std::size_t size() const;

    /// Number of string members of the object. Offered for completion and pseudo type-checking.
    std::size_t size_strings() const;

    /// Quantity of numbers that aare members of this subobject. It's not recursive.
    /// TODO: Differentiate between integers and floating point values.
    std::size_t size_numbers() const;
    
    /// Quantity of members that are objects
    std::size_t size_objects() const;

    /// Quantity of members that are arrays
    std::size_t size_arrays() const;

    /// Quantity of members that are bools
    std::size_t size_bools() const;

    /// Quantity of nulls
    std::size_t size_nulls() const;
    
    /// Functions that return if the indicated position is of the indicated type.
    /// @warning It's less efficient consult by position than consult by key.
    bool is_string(std::size_t const aPosition) const;
    bool is_number(std::size_t const aPosition) const;
    bool is_object(std::size_t const aPosition) const;
    bool is_array(std::size_t const aPosition) const;
    bool is_bool(std::size_t const aPosition) const;
    bool is_null(std::size_t const aPosition) const;

    bool is_string(String const& aKey) const;
    bool is_number(String const& aKey) const;
    bool is_object(String const& aKey) const;
    bool is_array(String const& aKey) const;
    bool is_bool(String const& aKey) const;
    bool is_null(String const& aKey) const;


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
    /// This would not work. member can be a string or an integer. I don't want something like boost::any
    //std::vector<Member> mMembers;
    std::map<String, std::tuple<std::size_t, String>> mMemberStrings;
    std::map<String, std::tuple<std::size_t, Number>> mMemberNumbers;
    /// A JSON Object member may be a subobject.
    std::map<String, std::tuple<std::size_t, Object>> mMemberObjects;
    /// A JSON Object member may be an array of non-uniform values.
    std::map<String, std::tuple<std::size_t, Array>> mMemberArrays;
    /// A JSON Object member may be true or false.
    std::map<String, std::tuple<std::size_t, Bool>> mMemberBools;
    /// A JSON Object member may be a null value. We count them non-explicitly. We should be able to disallow null values.
    std::map<String, std::size_t> mMemberNulls;
  };
}
