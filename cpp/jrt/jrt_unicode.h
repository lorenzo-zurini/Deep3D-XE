// java.lang.Character / String Unicode behaviour, from tables generated
// from the JDK (jrt_unicode.cpp, tools/unicode/GenUnicode.java).
#pragma once
#include <cstdint>
#include <string>

namespace jrt::unicode {

struct Range { char16_t lo, hi; };
struct CharMap { char16_t from, to; };
struct DigitEntry { char16_t c; int8_t value; };
struct StringMap { char32_t cp; const char16_t* to; };

bool isDigit(char16_t c);
bool isLetter(char16_t c);
bool isLetterOrDigit(char16_t c);
bool isWhitespace(char16_t c);
bool isUpperCase(char16_t c);
bool isLowerCase(char16_t c);
char16_t toUpperCase(char16_t c);
char16_t toLowerCase(char16_t c);
/** Character.digit(c, radix): -1 when c is no digit in that radix. */
int32_t digit(char16_t c, int32_t radix);
/** String.toUpperCase() / toLowerCase() (root locale). */
std::u16string toUpperCase(const std::u16string& s);
std::u16string toLowerCase(const std::u16string& s);

}  // namespace jrt::unicode
