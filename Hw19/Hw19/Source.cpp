#include <fstream>
#include <iostream> 
#include <map>
#include "words.txt"


int main()
{

	std::ifstream file("words.txt");
	if (file.fail() == true)
	{

		std::cout << "FILE DIDN'T OPEN" << std::endl;
		exit(1);


	}
	
	std::map<std::string, std::string> m;

	while (file.eof() == false)
	{
		std::string a, b;
		file >> a >> b;
		m[a] = b;

	}

	file.close();

	std::string longest;


	for (std::pair<std::string, std::string> p : m)
	{
		std::string phrase = p.first + " ";
		std::string last = p.second;
		std::map<std::string, std::string>:: iterator next = m.find(p.second);
		while (next != m.end())
		{
			phrase += next->first + " ";
			last = next->second;
			next = m.find(next->second);



		}
		phrase += last;
		if (phrase.size() > longest.size())
		{
			longest = phrase;
		}

	}
	std::cout << longest << std::endl;
	

	system("PAUSE");
	return 0;

}