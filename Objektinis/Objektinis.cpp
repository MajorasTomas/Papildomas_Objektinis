#include "libraries.h"

int main() {

    std::locale::global(std::locale("lt_LT.UTF-8"));
    std::wifstream fin("txt_files/straipsnis.txt");
    fin.imbue(std::locale());

    std::map<std::wstring, vector<int>> wordCount;

    wstringstream buffer;
    buffer << fin.rdbuf();

    wstring line;
	int lineNumber = 1;
	while (getline(buffer, line)) {

		wistringstream eilute(line);
		wstring word;

        while (eilute >> word) {

            wstring result;
            for (wchar_t c : word) {
                if (!iswpunct(c) && !iswdigit(c)) {
                    result += towlower(c);
                }
            }
            if (!result.empty()) {
				wordCount[result].push_back(lineNumber);
            }
        }
		lineNumber++;
    }

	fin.close();

    vector<pair<wstring, vector<int>>> array(wordCount.begin(), wordCount.end());
    sort(array.begin(), array.end(), [](auto a, auto b) {
        return a.second.size() < b.second.size();
        });

    wofstream fout("txt_files/word_output.txt");
	fout.imbue(std::locale());

    for (auto pair : array) {
        if (pair.second.size() == 1) continue;
        fout << setw(15) << left << pair.first << L"pasikartoja: " << setw(2) << left << pair.second.size() << L" kartus, eilutėse: ";
		for (auto num : pair.second) {
            fout << num << " ";
		}
        fout << endl;
    }

	fout.close();

	wifstream fin2("txt_files/nuorodos_tekstas.txt");
	fin2.imbue(std::locale());
	wstringstream buffer2;
	buffer2 << fin2.rdbuf();
    wstring line2;

    set<wstring> linkai;

	while (getline(buffer2, line2)) {
		wistringstream eilute2(line2);
		wstring word2;
		while (eilute2 >> word2) {
            bool raide=false;
			wstring link;
			for (auto it = word2.begin(); it != word2.end(); it++) {
				if (iswalpha(*it)) {
					raide = true;
					continue;
				}
                if (raide && *it=='.') {
					for (auto j = it; j != word2.end(); j++) {
						if (iswalpha(*j)) {
							link += towupper(*j);
						}
					}
					wifstream fin3("txt_files/urlai.txt");
					fin3.imbue(std::locale());
					wstring word3;
					while (fin3 >> word3) {
						if (word3 == link) {
							if (iswpunct(word2.back())) word2.pop_back();
							linkai.insert(word2);
							break;
						}
					}
					fin3.close();
					break;
                }
            }
		}
	}

	fin2.close();

	wofstream fout2("txt_files/url_output.txt");
	fout2.imbue(std::locale());

	for (auto link : linkai) {
		fout2 << left << setw(20) << link << endl;
	}
	fout2.close();

}