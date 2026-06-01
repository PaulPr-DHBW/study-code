#include <iostream>
#include <string>
#include <exception>

class config_loader
{
private:
	std::string filename;
public:

	void print() const
	{
		std::cout << "\nFilename: " << filename << std::endl;

	}

	void load(std::string new_filename)
	{
		//Empty files?
		if(new_filename.empty())
		{ 
			filename = "missing.cfg";
			throw std::invalid_argument("Keine Datei uebergeben");
		}


		//Letzen 4 zeichen
		std::string file_extension = new_filename.substr(new_filename.length() -4);
		if (file_extension != ".cfg")
		{
			filename = "invalid.cfg";
			throw std::invalid_argument("Falscher Dateityp");
		}


	}


};

int main()
{
	std::string file = "yo.cfg";
	config_loader loading;

	try
	{
		loading.load(file);
	}
	catch(std::invalid_argument error)
	{
		std::cout << error.what() << std::endl;
	}

	try
	{
		loading.load("bild.png");
	}
	catch (std::invalid_argument error)
	{
		std::cout << error.what() << std::endl;
	}

	return 0;
}