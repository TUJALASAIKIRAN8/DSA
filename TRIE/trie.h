template<class T> struct Node
{
	Node<T> *mPtr[26];
	bool mEnd;
	char mChar;
	int mPrefixCount;
	Node() : mEnd{false}, mChar{'/'}, mPrefixCount{}
	{
		fill_n(mPtr, 26, nullptr);
	}
};

template<typename T>class Trie
{
	Node<T> *mHead;
	public:
		Trie() : mHead{new Node<T>{}} {} 
		void insert(const string &str);
		bool search(const string &str);
		int wordsWithPrefix(const string &);

};

template<class T> int Trie<T> ::  wordsWithPrefix(const string &prefix)
{
	Node<T> *current = mHead;
	for(const auto &ch : prefix)
        {
		int index = ch - 'a'; 
		if( current->mPtr[index] == nullptr ) return 0;
		current = current->mPtr[index];
	}
	return current->mPrefixCount;
}
template<class T> void Trie<T> :: insert(const string &str)
{
	Node<T> *current = mHead;

	for(const auto &ch : str)
	{
		int index = ch - 'a';
		if( current->mPtr[index] == nullptr ) current->mPtr[index] = new Node<T>{};
		current->mPtr[index]->mChar = ch;

		current = current->mPtr[index];
		++current->mPrefixCount;
	}
	current->mEnd = true;
}
template<class T> bool Trie<T> ::  search(const string &str)
{
	Node<T> *current = mHead;
	for(const auto &ch : str)
        {
		int index = ch - 'a';
		if(current->mPtr[index] == nullptr) return false;
		current = current->mPtr[index];
	}
	return current->mEnd;
}
