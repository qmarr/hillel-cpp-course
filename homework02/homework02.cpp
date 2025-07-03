#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <algorithm>

class BigData {
private:
	int* m_data = nullptr;
	size_t m_size;
public:
	BigData(size_t size) : m_size(size) {
		std::cout << "Constructor called\n";
		
		m_data = new int[m_size];
		for (size_t i = 0; i < m_size; i++)
		{
			m_data[i] = i;
		}
	}
	~BigData() {
		std::cout << "Destructor called\n";
		delete[] m_data;
	}

	// Конструктор копіювання
	BigData(const BigData& other) {

		std::cout << "Copy constructor called\n";
		m_size = other.m_size;

		if (other.m_data) {
			m_data = new int[m_size];
			
			for (size_t i = 0; i < m_size; i++)
			{
				m_data[i] = other.m_data[i];
			}
		}
		else
			m_data = nullptr;
	}

	// Оператор копіювання
	BigData& operator=(const BigData& other) {
		std::cout << "Copy operator called\n";
		if(this == &other) {
			return *this;
		}

		delete[] m_data;

		m_size = other.m_size;

		if (other.m_data) {
			m_data = new int[m_size];

			for (size_t i = 0; i < m_size; i++)
			{
				m_data[i] = other.m_data[i];
			}
		}
		else
			m_data = nullptr;

		return *this;
	}

	// Конструктор переміщення
	BigData(BigData&& other) noexcept : m_data(other.m_data), m_size(other.m_size) {
		std::cout << "Move constructor called\n";
		other.m_data = nullptr;
	}

	// Оператор переміщення
	BigData& operator=(BigData&& other) noexcept {
		std::cout << "Move operator called\n";
		if (this == &other)
			return *this;

		m_size = other.m_size;

		delete[] m_data;

		m_data = other.m_data;
		other.m_data = nullptr;


		return *this;
	}

	void print() const {
		for (size_t i = 0; i < m_size; i++)
		{
			std::cout << m_data[i] << " ";
		}
		std::cout << "\n";
	}

	int& operator*() const { return *m_data; }
	int* operator->() const { return m_data; }
};


BigData& moveObject(BigData& object) {

	return object; // просто для експерименту
}

BigData createObject() {
	BigData tempObj(7);
	return tempObj;
}

int main()
{
	BigData obj(5);
	BigData obj1(4);
	obj1 = obj;

	obj.print();
	obj1.print();

	obj1 = createObject(); 
	obj.print();
	obj1.print();
	std::cout << "\n\n";
	BigData obj2(10);
	//obj1 = std::move(moveObject(obj2)); // просто для експерименту (видає помилку 0хс00000005)
	obj1.print();
	obj2.print();


	std::cout << "\n\nLAMBDAS: \n\n"; // завдання з лямбдою
	std::vector<int> vectorl{ 1,2,3,4,5,6,7,8,9,10 };
	std::for_each(vectorl.begin(), vectorl.end(), [](int& i) { i++; });

	for (auto& i : vectorl)
	{
		std::cout << i << " ";
	}
	
	std::cout << "\n";
	int value = 5;
	auto modifyVector = [&vectorl](int v) {
		for (size_t i = 0; i < vectorl.size(); i++) {
			vectorl[i]+= v;
		}
	};

	modifyVector(value);

	for (auto& i : vectorl)
	{
		std::cout << i << " ";
	}

	std::cout << "\n"; 
	return 0; 
}