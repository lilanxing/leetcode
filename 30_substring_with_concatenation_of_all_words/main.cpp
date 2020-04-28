/*
 * You are given a string, s, and a list of words, words, that are all of the same length.
 * Find all starting indices of substring(s) in s that is a concatenation of each word in 
 * words exactly once and without any intervening characters.
 *
 * Example 1:
 * Input:
 *   s = "barfoothefoobarman",
 *   words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
 * The output order does not matter, returning [9,0] is fine too.
 *
 * Example 2:
 * Input:
 *   s = "wordgoodgoodgoodbestword",
 *   words = ["word","good","best","word"]
 * Output: []
 */

#include <iostream>
#include <vector>
#include <map>

void outputMap(std::map<std::string, int>& m) {
    std::map<std::string, int>::iterator it = m.begin();
    while (it != m.end()) {
	std::cout << it->first << ": " << it->second << std::endl;
	it++;
    }
}

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
	std::vector<int> res;
	if (words.size() == 0 || (words.size() > 0 && words[0].size() == 0)) return res;

	std::map<std::string, int> words_count;
	for (int i = 0; i < words.size(); ++i) {
	    ++words_count[words[i]];
	}
	
	int s_len = words.size() * words[0].size();
	int e_len = words[0].size();
	for (int i = 0; i <= int(s.size() - s_len); ++i) {
	    if (words_count.find(s.substr(i, e_len)) == words_count.end()) continue;
	    std::string tmp = s.substr(i, s_len);
	    std::map<std::string, int> tmp_map;
	    bool skip = false;
	    for (int j = 0; j < s_len; j += e_len) {
		if (words_count.find(tmp.substr(j, e_len)) == words_count.end()) {
		    skip = true;
		    break;
		}
		++tmp_map[tmp.substr(j, e_len)];
	    }
	    if (skip) continue;
	    if (tmp_map == words_count) {
		res.push_back(i);
	    }
	}
	
	return res;
    }
};

void output(const std::vector<int>& vec) {
    std::vector<int>::const_iterator it = vec.begin();
    while (it != vec.end()) std::cout << *it++ << " ";
    std::cout << std::endl;
}

int main() {
    std::string s = "wordgoodgoodgoodbestword";
    std::vector<std::string> words = {"word", "good", "best", "good"};
    Solution sl;
    output(sl.findSubstring(s, words));
}
