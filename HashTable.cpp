
#include "HashTable.h"

size_t HashTable::getHash(string value){
	hash<std::string> hasher;
	return hasher(value); //computes hash values
}
//insert key into hash table
void HashTable::put(string key, string definition)
{
	if (checkKeyExist(key)){
		//if same key is exist, replace value in hashtable
		replace(key, definition);
	}
	else{
		size_t hash_key = getHash(key); //assigns getHash function to hash_key
		//insert data to dictionary
		HashData data;
		data.key = hash_key;
		data.definition = definition;
		dictionary.push_back(data);
	}
}

void HashTable::remove(string key)
{
	if (checkKeyExist(key)){
		HashData data;
		size_t hash_key = getHash(key);
		for (auto it = this->dictionary.begin(); it != this->dictionary.end(); it++) {
			if (it->key == hash_key) {
				data = *it;
				break;
			}
		}
		dictionary.remove(data);
	}
}
string HashTable::get(string key){
	if (checkKeyExist(key)){
		size_t hash_key = getHash(key);
		for (auto it = this->dictionary.begin(); it != this->dictionary.end(); it++) {
			if (it->key == hash_key) {
				return it->definition;
			}
		}
	}
}
//computes hashkey value, loops through list to find if theres a matching key, if key exists, take definition and swap with new definition
void HashTable::replace(string key, string definition){
	size_t hash_key = getHash(key);
	for (auto it = this->dictionary.begin(); it != this->dictionary.end(); it++) {
		if (it->key == hash_key) {
			it->definition = definition;
			return;
		}
	}
}
//loops to find key, if finds key, returns true. Else false
bool HashTable::checkKeyExist(string key){
	if (this->dictionary.empty()) return false;
	size_t hash_key = getHash(key);
	for (auto it = this->dictionary.begin(); it != this->dictionary.end(); it++) {
		if (it->key == hash_key) {
			return true;
		}
	}
	return false;
}
//loops through and prints every value in the dictionary
void HashTable::printDict(){
	if (dictionary.empty()){
		cout << "Dictionary is empty !" << endl;
		return;
	}
	for (auto it = this->dictionary.begin(); it != this->dictionary.end(); it++) {
		cout << it->key << " --> " << it->definition << endl;
	}
}
