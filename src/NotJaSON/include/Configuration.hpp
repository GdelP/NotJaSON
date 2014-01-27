#pragma once
#include <map>
#include <tuple>
#include <string>
#include <vector>
#include <exception>
#include <stdexcept>

/// We recommend to use namespace explicitly: naming inside the namespace is not redundantly putting "JSON" everywhere
/// JSON is a lightweight data-interchange format. It's easy for humans to read nd write. It's standardized. More information can be found on www.json.org
namespace NotJaSON {
  // Predeclarations
  struct Object;
  struct Array;
  /// TODO: generalize numbers.
  /// Nowadays we are limited to double numerical range. A JSON may represent an arbitrary precision number according to the standard. It would be useful to encode high-valued integers which are not represented accurately by double. It will suffice for first commit ;-)
  /// TODO: Parsing of numbers should be made in a correct way by standard library. Check it complies with JSON standard.
  typedef double Number;
  /// We need to configurate which is the input, maybe conversor, and storage.
  /// For example, we may input data from a pure ASCII stream, convert it to UTF-16 and store it as UTF16. It should be extensible enough to use all possible combinations.
  /// So, typedef is not the correct solution.
  /// We need to use codecvt and locale for parsing.
  /// On original JSON strings are enclosed within quotation marks.
  /// The following characters must be scaped:
  /// " U+0022 
  /// \ U+005C
  /// U+0000 to U+001F
  /// scape character \ U+005C
  /// Also there are special two-character escape sequence representations of \@ \\ \/ \b \f \n \r \t that may not be scaped
  /// Also, it is permitted the following representation for unicode codepoints in the Basic Multilingual Plane : "\u002F" and we encode other characters encoding the UTF-16 surrogate pair.
  typedef std::string String;

  /// We map this to bool C++ data type. This is not expected to change nor be configurable.
  /// On JSON we write in simple text "true" or "false" withouth the double commas.
  typedef bool Bool;

  /// Whitespaces characters are tabulation, line feed, carriage return and space:
  /// U+0009 U+000a U+000D U+0020
  /// Whitespace can be before or after any token. That's to say, almost in any place. Prettyprinting will take care of that correctly.
}
