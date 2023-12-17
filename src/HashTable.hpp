#include <list>
#include <vector>
#include <string>
#include <fstream>

class HashTable
{
private:
	const int START_CAPACITY = 16;
	const std::string delimiters = ".,\"";

	std::vector <std::list<std::string>> data;
public:
	HashTable(const std::string& filepath)
		: data(START_CAPACITY)
	{
		std::fstream file;
		file.exceptions(std::fstream::badbit);
		file.open(filepath);

		for (std::string buffer; !file.eof(); )
		{
			file >> buffer;
			for (auto it : delimiters)
				buffer.erase(std::remove(buffer.begin(), buffer.end(), it), buffer.end());
			insert(buffer);
		}
		file.close();
	}
	void insert(const std::string& value)
	{
		int key = hash_func(value);
		if (key < 0 || key >= data.size())
			return;

		data[key].push_back(value);
	}
	bool contains(const std::string& value) const
	{
		for (auto& it : data[hash_func(value)])
			if (it == value)
				return true;
		return false;
	}
	int hash_func(const std::string& value) const
	{
		int i = 0;
		for (auto it : value)
			i += it;
		return i % data.size();
	}
};