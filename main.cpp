#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Solution {
  struct Symbol {
    Symbol(char c) : type(isdigit(c) ? Type::Digit : Type::Letter) {}

    enum Type { Letter, Digit } type;
  };

  bool sameClassSymbols(char lhs, char rhs) {
    return Symbol(lhs).type == Symbol(rhs).type;
  }

 public:
  string reformat(string s) {
    int digits_count = 0;
    int letters_count = 0;
    bool no_repetitions_found = true;
    int p = -1;
    for (int i = 0; i < s.length(); ++i, ++p) {
      if (isdigit(s[i])) { ++digits_count; }
      else { ++letters_count; }
      if (0 <= p and sameClassSymbols(s[p], s[i])) {
        no_repetitions_found = false;
      }
    }

    if ( abs(digits_count - letters_count) <= 1 ) {
      if (no_repetitions_found) {
        return s;
      } else {
        queue<int> digits;
        queue<int> letters;
        for (const auto &c: s) {
          if (isdigit(c)) { digits.push(c); }
          else { letters.push(c); }
        }

        string result;
        result.reserve(s.length());
        bool is_next_letter = (digits_count < letters_count);
        for (int i = 0; i < s.length(); ++i) {
          if (is_next_letter) {
            result.push_back(letters.front());
            letters.pop();
          } else {
            result.push_back(digits.front());
            digits.pop();
          }
          is_next_letter = not is_next_letter;
        }
        return result;
      }
    }

    return {};
  }
};

void TestReformat() {
  Solution s;
  assert("a0b1c2"s == s.reformat("a0b1c2"s));
  assert(""s == s.reformat("leetcode"s));
  assert(""s == s.reformat("1229857369"s));
  assert("1a2b3"s == s.reformat("ab123"s));
//  assert(""s == s.reformat(""s);
}

int main() {
  TestReformat();
  std::cout << "Ok!" << std::endl;
  return 0;
}
