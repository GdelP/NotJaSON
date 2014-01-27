#include "NotJaSON.hpp"

namespace NotJaSON {
  std::size_t Object::size() const {
    return size_strings() + size_numbers() + size_objects() + size_arrays() + size_bools() + size_nulls();
  }

  std::size_t Object::size_strings() const {
    return mMemberStrings.size(); }
  std::size_t Object::size_numbers() const {
    return mMemberNumbers.size(); }
  std::size_t Object::size_objects() const {
    return mMemberObjects.size(); }
  std::size_t Object::size_arrays() const {
    return mMemberArrays.size(); }
  std::size_t Object::size_bools() const {
    return mMemberBools.size(); }
  std::size_t Object::size_nulls() const {
    return mMemberNulls.size(); }

  template<typename Container>
  inline bool is_type(Container const& cont, std::size_t const& aPosition){
    for(auto const& tupl : cont)
      if(tupl.first==aPosition) return true;
    return false;
  }
  
  bool Object::is_string(std::size_t const aPosition) const {
    return is_type(mMemberStrings, aPosition); }
  bool Object::is_number(std::size_t const aPosition) const {
    return is_type(mMemberNumbers, aPosition); }
  bool Object::is_object(std::size_t const aPosition) const {
    return is_type(mMemberObjects, aPosition); }
  bool Object::is_array(std::size_t const aPosition) const {
    return is_type(mMemberArrays, aPosition); }
  bool Object::is_bool(std::size_t const aPosition) const {
    return is_type(mMemberBools, aPosition); }
  bool Object::is_null(std::size_t const aPosition) const {
    for(auto const& tupl : cont)
      if(tupl==aPosition) return true;
    return false; }


  bool Object::is_string(String const& aKey) const {
    return mMemberStrings.count(aKey)>0; }
  bool Object::is_number(String const& aKey) const {
    return mMemberNumbers.count(aKey)>0; }
  bool Object::is_object(String const& aKey) const {
    return mMemberObjects.count(aKey)>0; }
  bool Object::is_array(String const& aKey) const {
    return mMemberArrays.count(aKey)>0; }
  bool Object::is_bool(String const& aKey) const {
    return mMemberBools.count(aKey)>0; }
  bool Object::is_null(String const& aKey) const {
    return mMemberNulls.count(aKey)>0; }

  /// Generic implementations. It's repeated for const-correctness. Maybe it's innecessary?
  template<typename Container>
  inline auto type_at(Container const& cont, std::size_t const& aPosition) throw(std::runtime_error) -> decltype( cont.begin()->second ) {
    for(auto const& tupl : cont)
      if(tupl.first==aPosition) return tup.second;
    throw std::runtime_error("JSON::Object: There is no value of the indicated type at position "+aPosition);
  }
  //  template<typename Container>
  //  inline auto type_at(Container& cont, std::size_t const& aPosition) throw(std::runtime_error) -> decltype( cont.begin()->second ) {
  //    for(auto& tupl : cont)
  //      if(tupl.first==aPosition) return tup.second;
  //    throw std::runtime_error("JSON::Object: There is no value of the indicated type at position "+aPosition);
  //  }
  String const& Object::string_at(std::size_t const aPosition) const throw(std::runtime_error) {
    return type_at(mMeberStrings, aPosition);
  }
  String& Object::string_at(std::size_t const aPosition) throw(std::runtime_error) {
    return type_at(mMeberStrings, aPosition); }

  Number const& Object::number_at(std::size_t const aPosition) const throw(std::runtime_error) {
    return type_at(mMeberNumbers, aPosition); }
  Number& Object::number_at(std::size_t const aPosition) throw(std::runtime_error) {
    return type_at(mMeberNumbers, aPosition);} 

  Object const& Object::object_at(std::size_t const aPosition) const throw(std::runtime_error) {
    return type_at(mMeberObjects, aPosition);} 
  Object& Object::object_at(std::size_t const aPosition) throw(std::runtime_error) {
    return type_at(mMeberObjects, aPosition);} 

  Array const& Object::array_at(std::size_t const aPosition) const throw(std::runtime_error) {
    return type_at(mMeberArrays, aPosition);}
  Array& Object::array_at(std::size_t const aPosition) throw(std::runtime_error) {
    return type_at(mMeberArrays, aPosition);}

  Bool const& Object::bool_at(std::size_t const aPosition) const throw(std::runtime_error) {
    return type_at(mMeberBools, aPosition);}
  Bool& Object::bool_at(std::size_t const aPosition) throw(std::runtime_error) {
    return type_at(mMeberBools, aPosition);}
}
