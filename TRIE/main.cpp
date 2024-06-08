#include <iostream>
#include <algorithm>
using namespace std;
#include "trie.h"
int main()
{
	Trie<int> trie{};
	string s = "chandan";
	trie.insert(s);
	s = "mittal";
	trie.insert(s);
	s = "chirag";
	trie.insert(s);
	s = "shashank";
	trie.insert(s);
	s = "abhinav";
	trie.insert(s);
	s = "arun";
	trie.insert(s);
	s = "abhishek";
	trie.insert(s);


	if(trie.search("chandan")) cout << "found chandan" << endl;		
	if(trie.search("arun")) cout << "found arun" << endl;		
	if(trie.search("abhi")) cout << "found abhi" << endl;	
	else cout << "not found abhi" << endl;	

	cout <<"no of words with prefix abhi: "<< trie.wordsWithPrefix("abhi") << endl;
	cout <<"no of words with prefix ch: " << trie.wordsWithPrefix("ch") << endl;
	cout <<"no of words with prefix k: "<< trie.wordsWithPrefix("k") << endl;
	return 1;
}
