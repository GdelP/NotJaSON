#include "Array.hpp"

namespace NotJaSON {
  /// Number of members of this object. In case type is indicated it talks about those who have that type.
  std::size_t Array::size() const {
    return size_strings() + size_numbers() + size_objects() + size_arrays() + size_bools() + size_nulls(); }
  std::size_t Array::size_strings() const {
    return mMemberStrings.size(); }
  /// TODO: Differentiate between integers and floating point values.
  std::size_t Array::size_numbers() const {
    return mMemberNumbers.size(); }
  std::size_t Array::size_objects() const {
    return mMemberObjects.size(); }
  std::size_t Array::size_arrays() const {
    return mMemberArrays.size(); }
  std::size_t Array::size_bools() const {
    return mMemberBools.size(); }
  std::size_t Array::size_nulls() const {
    return mMemberNulls.size(); }
    
  /// Functions that return if the indicated position is of the indicated type.
  /// @warning It's less efficient consult by position than consult by key.
  bool Array::is_string(std::size_t const aPosition) const {
    return mMemberStrings.count(aPosition)>0;}
  bool Array::is_number(std::size_t const aPosition) const {
    return mMemberNumbers.count(aPosition)>0;}
  bool Array::is_object(std::size_t const aPosition) const {
    return mMemberObjects.count(aPosition)>0;}
  bool Array::is_array(std::size_t const aPosition) const {
    return mMemberArrays.count(aPosition)>0;}
  bool Array::is_bool(std::size_t const aPosition) const {
    return mMemberBools.count(aPosition)>0;}
  bool Array::is_null(std::size_t const aPosition) const {
    return mMemberNulls.count(aPosition)>0;}


  /// Retrieve members
  String const& Array::string_at(std::size_t const aPosition) const throw(std::out_of_range) {
    return mMemberStrings.at(aPosition); }
  String& Array::string_at(std::size_t const aPosition) throw(std::out_of_range) {
    return mMemberStrings.at(aPosition); }
  Number const& Array::number_at(std::size_t const aPosition) const throw(std::out_of_range) {
    return mMemberNumbers.at(aPosition); }
  Number& Array::number_at(std::size_t const aPosition) throw(std::out_of_range) {
    return mMemberNumbers.at(aPosition); }
  Object const& Array::object_at(std::size_t const aPosition) const throw(std::out_of_range) {
    return mMemberObjects.at(aPosition); }
  Object& Array::object_at(std::size_t const aPosition) throw(std::out_of_range) {
    return mMemberObjects.at(aPosition); }
  Array const& Array::array_at(std::size_t const aPosition) const throw(std::out_of_range) {
    return mMemberArrays.at(aPosition); }
  Array& Array::array_at(std::size_t const aPosition) throw(std::out_of_range) {
    return mMemberArrays.at(aPosition); }
  Bool const& Array::bool_at(std::size_t const aPosition) const throw(std::out_of_range) {
    return mMemberBools.at(aPosition); }
  Bool& Array::bool_at(std::size_t const aPosition) throw(std::out_of_range) {
    return mMemberBools.at(aPosition); }
}
