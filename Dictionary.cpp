
#include "HashTable.h"


std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
	str.erase(0, str.find_first_not_of(chars));
	return str;
}

std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}

std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
	return ltrim(rtrim(str, chars), chars);
}

int main(){
	HashTable hash_table; // create hash table for dictionary

	vector<string> words;

	//read file for testing
	string line;
	ifstream test_file("dictionary.txt");
	if (test_file.is_open())
	{
		while (getline(test_file, line))
		{
			istringstream f(line);
			string s;
			vector<string> strings;
			while (getline(f, s, ':')) {
				strings.push_back(trim(s)); // token string and save
			}
			if (strings.size() == 2){
				// built dictionary
				hash_table.put(strings[0], strings[1]);
				words.push_back(strings[0]); // save word list
			}
		}
		test_file.close();
	}
	else {
		cout << "Unable to open test file";
		return -1;
	}

	//print dictionary
	cout << "****** Dictionary ********" << endl;
	hash_table.printDict();

	//get all definitions
	cout << endl;
	cout << "****** All Definitions ********" << endl;
	if (words.empty()){
		cout << "Empty dictionary" << endl;
	}
	else{
		for (int i = 0; i < words.size(); i++){
			cout << words[i] << " --> " << hash_table.get(words[i]) << endl;
		}
	}
}
