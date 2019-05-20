
#include <list>
#include <iostream>
#include <functional>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//data class that represents each row in hash table
struct HashData{
	size_t key;
	string definition;

	bool operator ==(HashData data){
		if (key == data.key) return true;
		return false;
	}
};

//hashtable class thats comprised of a list of hash data objects called dictionary
class HashTable
{
	list<HashData> dictionary;

	public:
		size_t getHash(string value); //get hash value
		void put(string key, string content); // inserts a key into hash table
		void remove(string key); // deletes a key from hash table
		void replace(string key, string definition); //replace definition in hash table
		bool checkKeyExist(string key);
		void printDict();
		string get(string key); // get definition
};
