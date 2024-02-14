/*
* Created by bishan_ on 2/14/24.
*/

#ifndef C_STRING_HPP
#define C_STRING_HPP
#include <ostream>
#include <utility>

#include "utils.hpp"


/**
 * \brief A wrapper around a const char* / C-String with a null termination character
 * to include the length
 */
class CString {
  char* buffer;
  usize length;


  /**
   * \brief Unchecked CString Creation
   * Pre condition is that the length matches the source
   */
  explicit CString(const char* source, usize length);

public:
  /**
   * \brief Creates a CString from a const char*
   * \param source Null terminated string slice to copy from
   */
  explicit CString(const char* source);

  /**
   * \brief Copy data from another cstring
   */
  CString(const CString& other);

  ~CString();

  CString(CString&& other) noexcept;

  /**
   * Assignment overload
   */
  CString& operator=(const CString& other);

  /**
   * Equality overload, to check if two strings are equal
   */
  bool operator==(const CString& rhs) const;

  /**
   * Inequality overload, to check if two strings are not equal
   */
  bool operator!=(const CString& rhs) const;

  /**
   * ostream << Operator overload, this simply is defining the behaviour
   * of of what std::cout << my_cstring should do - allowing us to print a instance
   * of our class to the console (or any other stream) easier.
   *
   * The 'friend' keyword in this case is just referring to how we are defining behaviour
   * to a class that isnt the one we are defining, eg. defining what << to a String is for std::ostream
   */
  friend std::ostream& operator<<(std::ostream& os, const CString& obj) {
    // print out our cstring, length doesnt need to be shown
    return os << obj.buffer;
  }

  /**
   * \brief Pointer to CString (const char*)
   */
  [[nodiscard]] const char* get_buffer() const;

  /**
   * \brief Length of the string
   */
  [[nodiscard]] usize size() const;
};


#endif //C_STRING_HPP
