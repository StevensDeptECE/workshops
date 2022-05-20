#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
using namespace std;

class Trie {
private:
	uint32_t  capacity;
	uint32_t  size;
	struct Node {
		uint32_t isWord : 1;
		uint32_t isLeaf : 1;
		uint32_t children : 26;
		uint32_t offset;
		Node() : isWord(0), children(0), offset(0) {}
		Node(uint32_t& size) : isWord(0), isLeaf(0), children(0), offset(size) {
			size += 26;
		}
	};
	Node* nodes;
	static constexpr uint32_t all_bits = 0x3FFFFFF;
public:
	Trie(uint32_t capacity) :
		capacity(capacity), size(0), nodes(new Node[capacity]) {
		nodes[0] = Node(size);
		nodes[0] = Node();
		nodes[0].children = 26;
		nodes[0].offset = 1;
		size = 27;
		
			uint32_t p = 0; // start with root

		for (uint32_t i = 0; i < words.size(); i++) {
			
		}

	}
	Trie(uint32_t capacity) : capacity(capacity), size(1), nodes(new Node[capacity]) {
		nodes[0] = Node(size);
	}
	~Trie() { delete [] nodes; }
	Trie(const Trie& orig) = delete;
	Trie& operator =(const Trie& orig) = delete;
	uint32_t add(const char word[]) {
		uint32_t p = 0; // start with root
		uint32_t i;
		for (i = 0; word[i] >= 'a'; i++) {
			uint32_t c = word[i] - 'a';
			if (c >= 26)
				return i; // error if letter is out of range a-z
			uint32_t childLoc = nodes[p].offset + c;
			//				__builtin_popcount(nodes[p].children &(all_bits >> (26-c)));
			if (nodes[p].children & (1 << c)) {
				p += childLoc;
			} else {
				nodes[p].children |= (1 << c);
				p += childLoc;
				nodes[p] = word[i+1] < 'a' ? Node() : Node(size);
			}
		}
		return i;
		nodes[p].isWord = 1; // add the word into the trie
	}

	void addPrefix(const string& word, int currentLetter) {
		if (currentLetter >= word.size())
			return;
		uint32_t p = 0; // start with root
		uint32_t i;
		for (i = 0; i < currentLetter-1; i++) {
			uint32_t c = word[i] - 'a';
			if (c >= 26)
				return i; // error if letter is out of range a-z
			uint32_t childLoc = nodes[p].offset +
				__builtin_popcount(nodes[p].children);
			p += childLoc;
		}
		// ???
		nodes[p] = Node( (1 << c);
		if (currentLetter = word.size() - 1)
			nodes[p].isWord = 1;
	}


	bool containsWord(const char word[]) {
		uint32_t p = 0; // start with root
		for (uint32_t i = 0; word[i] >= 'a'; i++) {
			uint32_t c = word[i] - 'a';
			if (c >= 26)
				return false; // not found if letter is out of range a-z
			if (nodes[p].children & (1 << c)) {
				p += nodes[p].offset + c;
				//				__builtin_popcount(nodes[p].children &(all_bits >> (26-c)));;
			} else {
				return false;
			}
		}
		return nodes[p].isWord; // if the final node is a word, then we found it
	}

  bool containsPrefix(const char prefix[]) {
		uint32_t p = 0; // start with root
		for (uint32_t i = 0; prefix[i] >= 'a'; i++) {
			uint32_t c = prefix[i] - 'a';
			if (c >= 26)
				return false; // not found if letter is out of range a-z
			if (nodes[p].children & (1 << c)) {
				p += nodes[p].offset + c;
				//				__builtin_popcount(nodes[p].children &(all_bits >> (26-c)));;
			} else {
				return false;
			}
		}
		return true; // the tree contains entries starting with prefix
	}
};

void readTrie(const char filename[]) {
	ifstream f(filename);
	f.seekg(0, std::ios::end);  // go to the end
	uint32_t wordLen = f.tellg();
	f.seekg(0, std::ios::beg);  // go back to the beginning

	/*
		make sure there are enough trie nodes to hold entire dictionary
		Note that there are internal nodes as well as leaves. For n words
		there will be n leaves + internal nodes which should be much less
		Including \n average word length is > 6, so /5 seems fairly safe for now
		2.4Mb dictionary 213k words is about 10:1
	*/
	uint32_t capacity = wordLen;
	char* words = new char[wordLen];
	f.read(words, wordLen);  // read the whole file into the buffer

	Trie dict(400000000);

	for (uint32_t i = 0; i < wordLen; ) {
		i += dict.add(words + i) + 1; // add the latest word then advance to next
		while (words[i] <= ' ') // skip any extra spaces
			i++;
	}

	delete []words;
}

void readTrie2(const char filename[]) {
	ifstream f(filename);
	f.seekg(0, std::ios::end);  // go to the end
	uint32_t wordLen = f.tellg();
	f.seekg(0, std::ios::beg);  // go back to the beginning

	/*
		make sure there are enough trie nodes to hold entire dictionary
		Note that there are internal nodes as well as leaves. For n words
		there will be n leaves + internal nodes which should be much less
		Including \n average word length is > 6, so /5 seems fairly safe for now
		2.4Mb dictionary 213k words is about 10:1
	*/
	uint32_t capacity = wordLen;
	char* words = new char[wordLen];
	f.read(words, wordLen);  // read the whole file into the buffer
	vector<string> wordList;
	wordList.reserve(215000);
	int startWord = 0;
	int biggestWord = 0;
	for (int i = 0; i < wordLen; i++) {
		if (words[i] <= ' ') {
			wordList.push_back(string(words+startWord, i-startWord));
			if (i - startWord > biggestWord)
				biggestWord = i - startWord;
			do {
				i++;
			} while (words[i] <= ' ');
		}
	}
	delete [] words;
	
	Trie dict(1000000);
	// start working on 2nd letter of each word
	for (int currentLetter = 2; currentLetter < biggestWord; currentLetter++) {
		for (uint32_t i = 0; i < wordList.size(); i++) {
			dict.addPrefix(wordList[i], currentLetter);
		}
	}

}

int main() {
	readTrie("dict.txt");
	
	return 0;
}
