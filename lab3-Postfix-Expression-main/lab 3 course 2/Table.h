#pragma once
template<typename T1, typename T2>
class Table
{
private:
	T1* Keys;
	T2* Values;
	size_t size;
	size_t curInd;
public:
	Table(size_t _size = 5) :size(_size), curInd(0) {
		Keys = new T1[size];
		Values = new T2[size];
	}
	Table(const Table& t) :size(t.size), curInd(t.curInd) {
		Keys = new T1[size];
		Values = new T2[size];
		for (size_t i = 0; i < size; i++) {
			Keys[i] = t.Keys[i];
			Values[i] = t.Values[i];
		}
	}
	Table operator=(const Table& t) {
		if (this == &t)
			return *this;
		size = t.size;
		curInd = t.curInd;
		delete[] Keys;
		delete[] Values;
		Keys = new T1[size];
		Values = new T2[size];
		for (size_t i = 0; i < size; i++) {
			Keys[i] = t.Keys[i];
			Values[i] = t.Values[i];
		}
		return *this;
	}
	void Apennd(const T1& key, const T2& value) {
		if (curInd >= size) {
			return;
		}
		Keys[curInd] = key;
		Values[curInd++] = value;
	}
	const T2& operator[](const T1& key) const {
		for (size_t i = 0; i < size; i++) {
			if (Keys[i] == key)
				return Values[i];
		}
		throw "Not found Exception";
	}
	T2& operator[](const T1& key) {
		for (size_t i = 0; i < size; i++) {
			if (Keys[i] == key)
				return Values[i];
		}
		throw "Not found Exception";
	}
	bool keyExist(const T1& key) const {
		for (size_t i = 0; i < size; i++) {
			if (Keys[i] == key)
				return true;
		}
		return false;
	}
	bool valueExist(const T2& value) const {
		for (size_t i = 0; i < size; i++) {
			if (Values[i] == value)
				return true;
		}
		return false;
	}
	T2 maxValue() const {
		T2 tmp = Values[0];
		for (size_t i = 1; i < size; i++) {
			if (Values[i] > tmp)
				tmp = Values[i];
		}
		return tmp;
	}
	~Table() {
		delete[] Keys;
		delete[] Values;
		Keys = nullptr;
		Values = nullptr;
	}
};