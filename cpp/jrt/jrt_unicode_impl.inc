// Lookups over the generated tables (included at the end of jrt_unicode.cpp).

template <size_t N>
bool inRanges(const Range (&r)[N], char16_t c) {
    size_t lo = 0, hi = N;
    while (lo < hi) {
        size_t mid = (lo + hi) / 2;
        if (c < r[mid].lo) hi = mid;
        else if (c > r[mid].hi) lo = mid + 1;
        else return true;
    }
    return false;
}

template <size_t N>
char16_t mapChar(const CharMap (&m)[N], char16_t c) {
    size_t lo = 0, hi = N;
    while (lo < hi) {
        size_t mid = (lo + hi) / 2;
        if (c < m[mid].from) hi = mid;
        else if (c > m[mid].from) lo = mid + 1;
        else return m[mid].to;
    }
    return c;
}

template <size_t N>
const char16_t* mapString(const StringMap (&m)[N], char32_t cp) {
    size_t lo = 0, hi = N;
    while (lo < hi) {
        size_t mid = (lo + hi) / 2;
        if (cp < m[mid].cp) hi = mid;
        else if (cp > m[mid].cp) lo = mid + 1;
        else return m[mid].to;
    }
    return nullptr;
}

bool isDigit(char16_t c) { return inRanges(kDigit, c); }
bool isLetter(char16_t c) { return inRanges(kLetter, c); }
bool isLetterOrDigit(char16_t c) { return inRanges(kLetterOrDigit, c); }
bool isWhitespace(char16_t c) { return inRanges(kWhitespace, c); }
bool isUpperCase(char16_t c) { return inRanges(kUpper, c); }
bool isLowerCase(char16_t c) { return inRanges(kLower, c); }
char16_t toUpperCase(char16_t c) { return mapChar(kToUpper, c); }
char16_t toLowerCase(char16_t c) { return mapChar(kToLower, c); }

int32_t digit(char16_t c, int32_t radix) {
    if (radix < 2 || radix > 36) return -1;
    size_t lo = 0, hi = sizeof(kDigitValue) / sizeof(kDigitValue[0]);
    while (lo < hi) {
        size_t mid = (lo + hi) / 2;
        if (c < kDigitValue[mid].c) hi = mid;
        else if (c > kDigitValue[mid].c) lo = mid + 1;
        else return kDigitValue[mid].value < radix ? kDigitValue[mid].value : -1;
    }
    return -1;
}

namespace {

char32_t codePointAt(const std::u16string& s, size_t i, size_t& n) {
    char16_t a = s[i];
    if (a >= 0xD800 && a <= 0xDBFF && i + 1 < s.size() && s[i + 1] >= 0xDC00 && s[i + 1] <= 0xDFFF) {
        n = 2;
        return 0x10000 + ((char32_t(a) - 0xD800) << 10) + (s[i + 1] - 0xDC00);
    }
    n = 1;
    return a;
}

bool cased(char16_t c) { return isUpperCase(c) || isLowerCase(c) || (toLowerCase(c) != c || toUpperCase(c) != c); }

/* Java's Final_Sigma (ConditionalSpecialCasing.isFinalCased) looks within
   the word: a cased letter before the sigma and none after it. A word here
   is a run of letters, digits and apostrophes. */
bool finalSigma(const std::u16string& s, size_t i) {
    auto inWord = [](char16_t c) { return isLetterOrDigit(c) || c == u'\'' || c == 0x2019; };
    bool before = false;
    for (size_t j = i; j > 0 && inWord(s[j - 1]); j--) {
        if (cased(s[j - 1])) { before = true; break; }
    }
    if (!before) return false;
    for (size_t j = i + 1; j < s.size() && inWord(s[j]); j++) {
        if (cased(s[j])) return false;
    }
    return true;
}

template <size_t N>
std::u16string mapAll(const StringMap (&m)[N], const std::u16string& s, bool lower) {
    std::u16string out;
    out.reserve(s.size());
    for (size_t i = 0; i < s.size();) {
        size_t n;
        char32_t cp = codePointAt(s, i, n);
        if (lower && cp == 0x03A3) {
            out += finalSigma(s, i) ? u'\x03C2' : u'\x03C3';
        } else if (const char16_t* to = mapString(m, cp)) {
            out += to;
        } else {
            out.append(s, i, n);
        }
        i += n;
    }
    return out;
}

}  // namespace

std::u16string toUpperCase(const std::u16string& s) { return mapAll(kStringUpper, s, false); }
std::u16string toLowerCase(const std::u16string& s) { return mapAll(kStringLower, s, true); }
