#include <iostream>
#include <iomanip>
#include "cpp_lang_task1.h"
void print_number_table(short col, short row) {
	std::cout << " ";
	std::cout << std::right << std::setfill('*') << std::setw(col * 4 - 1) << "" << " " << '\n';
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			std::cout << '|';
			std::cout << std::right << std::setfill(' ') << std::setw(3) << rand() % 1000;
		}
		std::cout << '|' << '\n';
		if (i == row - 1) break;
		for (int j = 0; j < col; j++) {
			if (j == 0) std::cout << "|---";
			else if (j == col - 1) std::cout << "+---|";
			else std::cout << "+---";
		}
		std::cout << '\n';
	}
	std::cout << " ";
	std::cout << std::right << std::setfill('*') << std::setw(4 * col - 1) << "" << " ";
}

student::string::string() {
	_size = 0;
	_data = new char;
}

student::string::~string() {
	delete[] _data;
}

student::string::string(unsigned int count, char ch) {
	_size = count;
	_data = new char[_size];
	for (int i = 0; i < _size; i++) _data[i] = ch;
}

student::string::string(const char* other) {
	_size = 0;
	_data = new char;
	push_back(*(other));
	while (*(other++) != '\0') push_back(*(other));
	_size = _size - 1;

}

student::string::string(string&& other) {
	_size = other._size;
	_data = other._data;
	other._size = 0;
	other._data = nullptr;
}

student::string::string(const string& other) {
	_size = other._size;
	char* buff = new char[_size];
	for (int i = 0; i < _size; i++) buff[i] = other._data[i];
	delete[] _data;
	_data = buff;
}

student::string::string(const char* other, unsigned int count) {
	_size = 0;
	_data = new char[0];
	int i = 0;
	while (*(other) != '\0') {
		if (i++ >= count) break;
		push_back(*(other));
		other++;
	}
}

unsigned int student::string::size() const {
	return _size;
}

const char* student::string::data() const {
	if (_size != 0) return _data;
	else return "";
}

void student::string::push_back(char ch) {
	char* buff = new char[_size + 1];
	for (int i = 0; i < _size; i++) buff[i] = _data[i];
	buff[_size] = ch;
	delete[] _data;
	_data = buff;
	_size++;
}

char& student::string::operator[](unsigned int pos) {
	if (pos < _size) return _data[pos];
	else return _data[_size];
}

const char& student::string::operator[](unsigned int pos) const {
	if (pos < _size) return _data[pos];
	else return _data[_size];
}

void student::string::pop_back() {
	char* buff = new char[_size - 1];
	for (int i = 0; i < _size - 1; i++) buff[i] = _data[i];
	delete[] _data;
	_data = buff;
	_size--;
}

void student::string::clear() {
	delete[] _data;
	_data = new char[0];
	_size = 0;
}

bool student::string::empty() {
	return _size != 0;
}

student::string& student::string::operator = (const char* other) {
	clear();

}

student::string& student::string::operator = (string&& other) {
	_size = other._size;
	_data = other._data;
	other._size = 0;
	other._data = nullptr;
}

student::string& student::string::operator = (const string& other) {
	_size = other._size;
	char* buff = new char[_size];
	for (int i = 0; i < _size; i++) buff[i] = other._data[i];
	delete[] _data;
	_data = buff;
	return *this;
}

student::string student::string::substr(unsigned int pos, unsigned int count) {
	string ret;
	char* buff = _data;
	for (int i = 0; i < pos; i++) buff++;
	for (int i = 1; i <= count; i++) {
		ret.push_back(*(buff));
		buff++;
	}
	return ret;

}

student::string& student::string::append(const string& other) {
	int sz = other._size;
	for (int i = 0; i < sz; i++) push_back(other[i]);
	return *this;
}

student::string& student::string::append(unsigned int count, const char& c) {
	for (int i = 0; i < count; i++) push_back(c);
	return *this;
}

student::string& student::string::append(const char* other, unsigned int count) {
	for (int i = 0; i < count; i++) push_back(other[i]);
	return *this;
}

template <class T>
student::vector<T>::vector() {
	_size = 0;
	T* _data = new T[_size];
}

template <class T>
student::vector<T>::~vector() {
	_size = 0;
	delete[] _data;

}

template <class T>
student::vector<T>::vector(const vector& other) {
	_size = other._size;
	_data = new T[_size];
	for (int i = 0; i < _size; i++) _data[i] = other._data[i];
}

template <class T>
student::vector<T>::vector(vector&& other) {
	_data = other._data;
	_size = other._size;
	other._size = 0;
	other._data = nullptr;
}

template <class T>
void student::vector<T>::push_back(const T& value) {
	T* buff = new T[_size + 1];
	for (int i = 0; i < _size; i++) buff[i] = _data[i];
	if (_size != 0) delete[] _data;
	_data = buff;
	_data[_size] = value;
	_size = _size + 1;
}

template <class T>
void student::vector<T>::push_back(T&& value) {
	T* buff = new T[_size + 1];
	for (int i = 0; i < _size; i++) buff[i] = _data[i];
	if (_size != 0) delete[] _data;
	_data = buff;
	_data[_size] = value;
	_size = _size + 1;

}

template <class T>
void student::vector<T>::pop_back() {
	T* buff = new T[_size - 1];
	if (_size > 0) {
		for (int i = 0; i < _size - 1; i++) buff[i] = _data[i];
		delete[] _data;
		_data = buff;
		_size = _size - 1;
	}
}

template <class T>
void student::vector<T>::insert(unsigned int pos, unsigned int count, const T& value) {
	T* buff = new T[_size + count];
	for (int i = 0; i != pos; i++) buff[i] = _data[i];
	for (int i = pos; i < pos + count; i++) buff[i] = value;
	for (int i = pos + count; i < count + _size; i++) buff[i] = _data[pos + i - count];
	delete[] _data;
	_data = buff;
	_size = _size + count;
}

template <class T>
T* student::vector<T>::data() {
	return _data;
}

template <class T>
T& student::vector<T>::operator [] (unsigned int pos) {
	return *(_data + pos);
}

template <class T>
const T& student::vector<T>::operator [] (unsigned int pos) const {
	return *(_data + pos);
}

template <class T>
void student::vector<T>::clear() {
	if (_size != 0) {
		delete[] _data;
		_data = new T[0];
		_size = 0;
	}
}

template <class T>
bool student::vector<T>::empty() const {
	return (_size != 0);
}

int main() {
	student::string test1(5, 'd');
	student::string test2("testting_string2");
	student::string test3("dskcmffmk", 4);
	std::cout << test1.data() << " " << test2.data() << " " << test3.data() << std::endl;
	std::cout << "sizeof test1 " << test1.size() << std::endl;
	test1.push_back('f');
	std::cout << test1.data();
	test2.pop_back();
	std::cout << " " << test2.data() << std::endl;
	test2.append(test3);
	std::cout << "test2 + test3 = " << test2.data() << std::endl;
	test1 = test2.append(test2);
	std::cout << "2*(test2+test3) = " << test1.data() << std::endl;
	test1 = test1.append(test1);
	std::cout << test1.data() << std::endl;
	student::vector <double> vec;
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);
	vec.insert(0, 100, 23);
	vec.insert(3, 20, 88);
	vec.pop_back();
	student::vector <double> vec2(vec);
	std::cout << vec2[0] << " " << vec2[3] << " " << vec2[2] << " ";
	std::cout << vec2[15];
	vec.pop_back();
	vec.clear();
	std::cout << vec.empty() << std::endl;
	print_number_table(10, 5);
	return 0;
}
