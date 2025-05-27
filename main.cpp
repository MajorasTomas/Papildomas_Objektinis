#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;
using std::map;
using std::sort;
using std::pair;
using std::setw;

int main() {

   ifstream fin("straipsnis.txt");
   map<string, int> wordCount;

  while(fin){
    string word;
    fin>>word;

    string result="";

    for(auto c : word) {
      // Check for ASCII hyphen and Unicode en dash (–, U+2013)
      if(!ispunct(c) && !isdigit(c)) {
      result += tolower(c);
      }
    }

    if(!result.empty()) {
      wordCount[result]++;
    }

  }

  pair<string, int> array[wordCount.size()];

  int index = 0;
  for(auto pair : wordCount) {
    array[index++] = {pair.first, pair.second};
  }


  sort(array, array+wordCount.size(), [](const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
  });

  for(auto pair : array) {
    if(pair.second == 1) continue;
    cout << setw(30)<< std::left<< pair.first << ": " << pair.second << endl;
  }

}