/**
 *Created by bishan_ on 2/14/24.
 */

#include "c_string.hpp"

#include <cstring>


// --------------------------------------------------------------------------------
// Constructors
// --------------------------------------------------------------------------------

/**
 * This is CString's 'unchecked' constructor, it is unchecked
 * because we are assuming that the source & length are valid, eg.this invariant is true:
 * source is a contiguous sequence of length-number 'chars' in memory that is ended
 * by a null termination character ('\0')
 *
 * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Constructors
 */
CString::CString(const char* source, const usize length)
  : buffer(nullptr), length(length) {
  // create our new buffer for the string contents + null termination
  buffer = new char[length + 1];

  // copy contents of source to our buffer
  std::strcpy(buffer, source);

  // insert null termination
  buffer[length] = '\0';
}

/**
 * This constructor calls CString's unchecked constructor by calculating the length
 * of the source string using std::strlen
 *
 * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Constructors
 */
CString::CString(const char* const source)
  : CString(source, std::strlen(source)) {}

/**
 * This constructor calls CStrings unchecked constructor by trusting that
 * the given CString instance is valid, therefore the invariant of the length matching
 * the buffer's size holds true.
 */
CString::CString(const CString& other)
  : CString(other.get_buffer(), other.size()) {}

/**
 * Delete the memory we allocated.
 * If we allocated this memory, 99% of the time this means that we own this memory, and it
 * is our responsibility to free it.
 *
 * https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/The+Heap
 */
CString::~CString() {
  delete buffer;
}

CString::CString(CString&& other) noexcept: buffer(other.buffer),
                                            length(other.length) {}

// --------------------------------------------------------------------------------
// Operator Overloads
// --------------------------------------------------------------------------------

CString& CString::operator=(const CString& other) {
  // If we are reassigning ourself to ourself, skip
  if (this == &other) return *this;

  buffer = other.buffer;
  length = other.length;

  // Return a reference to ourself
  // If you are unfamiliar with this syntax, read here:
  // https://bishan.app/02+Personal/Me+Bitching+about+C%2B%2B/Reference#A+note+on+Conversion
  return *this;
}

bool CString::operator==(const CString& rhs) const {
  // Ensure that the strings length matches, and then ensure that all contents
  // of the strings are the same using std::strcmp
  return length == rhs.length and std::strcmp(buffer, rhs.buffer) == 0;
}

bool CString::operator!=(const CString& rhs) const {
  // Simply negate our previously overload == operator
  return !(*this == rhs);
}

std::ostream& operator<<(std::ostream& os, const CString& obj) {
  // print out our cstring, length doesnt need to be shown
  return os << obj.buffer;
}

// --------------------------------------------------------------------------------
// Self Explanatory Setters & Getters
// --------------------------------------------------------------------------------

const char* CString::get_buffer() const {
  return buffer;
}

usize CString::size() const {
  return length;
}
