/*
* Created by bishan_ on 2/14/24.
*/

#ifndef C_STRING_HPP
#define C_STRING_HPP
#include <memory>
#include <ostream>

#include "utils.hpp"


/**
 * \brief A wrapper around a const char* / C-String with a null termination character
 * to include the length
 */
class CString {
  /**
   * \brief Owned pointer to an array of characters
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Smart+Pointers
   */
  std::unique_ptr<char[]> buffer;
  usize length;


  /**
   * \brief Unchecked CString Creation
   * Pre condition is that the length matches the source
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Constructor
   */
  explicit CString(const char* source, usize length);

public:
  /**
   * \brief Creates a CString from a const char*
   * \param source Null terminated string slice to copy from
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Constructor
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Conversion+Constructor
   */
  explicit CString(const char* source);

  /**
   * \brief Copy data from another cstring
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Constructor
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Copy+Constructor
   */
  CString(const CString& other);

  /**
   * \brief Destructor that is called when a value of type CString is being deleted
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Destructor
   */
  ~CString();

  /**
   * \brief 
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/R+and+L+Values
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Move+Semantics
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Noexcept
   */
  CString(CString&& other) noexcept;

  /**
   * Assignment overload
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Assignment+Overload
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Move+Semantics
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Operator+Overloads
   */
  CString& operator=(CString&& other) noexcept;


  /**
   * Equality overload, to check if two strings are equal
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Operator+Overloads
   */
  bool operator==(const CString& rhs) const;

  /**
   * Inequality overload, to check if two strings are not equal
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Operator+Overloads
   */
  bool operator!=(const CString& rhs) const;

  /**
   * Add overload, for concating two strings
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Operator+Overloads
   */
  CString operator+(const CString& rhs) const;

  /**
   * Add Assign overload, for concating two strings
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Operator+Overloads
   */
  CString& operator+=(const CString& string);


  /**
   * ostream << Operator overload, this simply is defining the behaviour
   * of of what std::cout << my_cstring should do - allowing us to print a instance
   * of our class to the console (or any other stream) easier.
   *
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Friend+Methods
   */
  friend std::ostream& operator<<(std::ostream& os, const CString& obj);

  /**
   * \brief Pointer to CString (const char*)
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Getters
   */
  [[nodiscard]] const char* get_buffer() const;

  /**
   * \brief Length of the string
   * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Getters
   */
  [[nodiscard]] usize size() const;
};


#endif //C_STRING_HPP
