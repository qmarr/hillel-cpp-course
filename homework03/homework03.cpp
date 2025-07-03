#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <memory>
#include <vector>

class FileManager
{
public:
	FileManager(const char* filename);
	~FileManager();


	void write(const std::string& string) {
		if (!file) throw std::runtime_error("Couldn't open file");
		file << string << "\n";
	}
private:
	std::ofstream file;
};

FileManager::FileManager(const char* filename)
{
	file.exceptions(std::ofstream::failbit | std::ofstream::badbit);

	try
	{
		file.open(filename);
		std::cout << "Opened succesfully!\n";
	}
	catch (const std::ofstream::failure& e)
	{
		std::cerr << " Couldn't open file " << e.what() << "\n";
		throw;
	}
	
}

FileManager::~FileManager()
{
	std::cout << "desctructor called" << "\n";
	if(file.is_open()) file.close();
}


class Sensor
{
public:
	Sensor(std::shared_ptr<std::vector<int>> dataPtr) :m_ptr(dataPtr) {
	}
	~Sensor();



	void printData() {
		for (size_t i = 0; i < m_ptr->size(); i++)
		{
			std::cout << (*m_ptr)[i] << " ";
		}
		std::cout << "\n";
	}

	void addNumber(int value) {
		m_ptr->push_back(value);
	}
private:
	std::shared_ptr<std::vector<int>> m_ptr;
};

Sensor::~Sensor()
{
	std::cout << "desctructor called\n";
}

int main()
{
	try
	{
		FileManager newfile("/a/a.txt"); //"a.txt" will compile without exceptions
		newfile.write("This is a test text!This is a test text!This is a test text!This is a test text!This is a test text!This is a test text!");

	}
	catch (const std::exception& except)
	{	
		std::cerr << "Caught exception " << except.what() << "\n";
	}

	

	std::shared_ptr<std::vector<int>> ptr = std::make_shared<std::vector<int>>(std::initializer_list<int>{1,2,3,4,5,6,7,8,9,10});

	//std::shared_ptr<std::vector<int>> ptr = std::make_shared<std::vector<int>>(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

	Sensor sensor1(ptr);

	Sensor sensor2(ptr);

	sensor1.printData();
	sensor2.printData();

	sensor1.addNumber(17);

	sensor1.printData();
	sensor2.printData();

	for (auto& i : *ptr)
	{
		std::cout << i << " ";
	}
	std::cout << "\n";

}