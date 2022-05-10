#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

double pct(int count, int total) {
  return 100.0 * (double)count / (double)total;
}

int main(int argc, char *argv[]) {
  using std::fixed;
  using std::string;
  using std::map;
  using std::cin;
  using std::cout;
  using std::endl;
  using std::setw;

  map<char, int> raw;
  map<char, int> inwords;

  int total_words = 0;
  int total_letters = 0;

  string line;
  while (std::getline(cin, line)) {
    for (auto c : line) {
      raw[c] = raw[c] + 1;
      total_letters++;
    }
    for (char c = 'a'; c <= 'z'; c++) {
      if (line.find(c) != string::npos) {
        inwords[c] = inwords[c] + 1;
      }
    }
    total_words++;
  }

  // cout << "Raw distribution of lettters (" << total_letters << ")" << endl;
  // for(auto &[c,n]: raw) {
  //   cout << c << " -->" << setw(5) << n << fixed << setw(10) <<
  //   pct(n,total_letters) << endl;
  // }

  // cout << "Words (" << total_words << ") containing given letter" << endl;
  for (auto &[c, n] : inwords) {
    cout << setw(2) << n << " " << c << " --> " << setw(3) << n << " " << fixed << setw(10)
         << pct(n, total_words) << endl;
  }

  return 0;
}
