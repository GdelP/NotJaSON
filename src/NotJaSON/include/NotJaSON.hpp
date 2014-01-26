#pragma once
#include <map>
#include <tuple>
#include <string>
#include <vector>

/// We recommend to use namespace explicitly: naming inside the namespace is not redundantly putting "JSON" everywhere
/// JSON is a lightweight data-interchange format. It's easy for humans to read nd write. It's standardized. More information can be found on www.json.org
namespace NotJaSON {
  // Predeclarations
  struct Object;
  struct Array;
  /// TODO: generalize numbers.
  /// Nowadays we are limited to double numerical range. A JSON may represent an arbitrary precision number according to the standard. It would be useful to encode high-valued integers which are not represented accurately by double. It will suffice for first commit ;-)
  typedef double Integer;
  /// TODO: Unicode is allowed. Does wstring handle all unicode?
  typedef std::string String;

  /// A JSON Object is an ordered list of members. Every member is a key:value pair. Key is always an string. Value can be of different types.
  /// We decide NOT to renounce to strict static typing: we won't use a "value" concept anywhere.
  /// We decide to use maps from key(string) to value and position.
  /// Invariant: there can't be two different values on the same position.
  /// @warning Note: remember NOT to import this into global namespace.
  struct Object {
  protected:
    /// This would not work. member can be a string or an integer. I don't want something like boost::any
    //std::vector<Member> mMembers;
    std::map<String, std::tuple<std::size_t, String>> mMemberStrings;
    std::map<String, std::tuple<std::size_t, Integer>> mMemberNumbers;
    /// A JSON Object member may be a subobject.
    std::map<String, std::tuple<std::size_t, Object>> mMemberObjects;
    /// A JSON Object member may be an array of non-uniform values.
    std::map<String, std::tuple<std::size_t, Array>> mMemberArrays;
    /// A JSON Object member may be true or false. We map this to bool C++ data type. This is not expected to change nor be configurable.
    std::map<String, std::tuple<std::size_t, bool>> mMemberBool;
    /// A JSON Object member may be a null value. We count them non-explicitly. We should be able to disallow null values.
    std::map<String, std::size_t> mMemberNulls;
  };

  struct Array {
  protected:
    std::map<std::size_t, String> mMemberStrings;
    std::map<std::size_t, Integer> mMemberNumbers;
    /// A JSON Object member may be a subobject.
    std::map<std::size_t, Object> mMemberObjects;
    /// A JSON Object member may be an array of non-uniform values.
    std::map<std::size_t, Array> mMemberArrays;
    /// A JSON Object member may be true or false. We map this to bool C++ data type. This is not expected to change nor be configurable.
    std::map<std::size_t, bool> mMemberBool;
    /// A JSON Object member may be a null value. We count them non-explicitly. We should be able to disallow null values.
    /// Semantically it's a set. We know there will be no repeated elements by definition.
    /// Invariant: there are no repeated elements inside the vector
    std::vector<std::size_t> mMemberNulls;
    
  };
}
