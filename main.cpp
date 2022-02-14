#include <cassert>
#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string reformat(string s) {
    // FIXME
    return {};
  }
};

void TestReformat() {
  Solution s;
  assert("a0b1c2"s == s.reformat("a0b1c2"s));
  assert(""s == s.reformat("leetcode"s));
  assert(""s == s.reformat("1229857369"s));
//  assert(""s == s.reformat(""s);
}

int main() {
  TestReformat();
  std::cout << "Ok!" << std::endl;
  return 0;
}
