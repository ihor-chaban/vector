#include <iostream>
#include "vector.h"

using std::cout;
using std::cerr;

vector::vector() {
	mData = new int[0];
	mSize = 0;
}

vector::vector(size_t size, int value) {
	mData = new int[size];
	for (size_t i = 0; i < size; i++) {
		mData[i] = value;
	}
	this->mSize = size;
}

vector::vector(const vector& obj) {
	mSize = obj.mSize;
	mData = new int[mSize];
	for (size_t i = 0; i < mSize; i++) {
		mData[i] = obj[i];
	}
}

void vector::push_back(int value) {
	int *temp = new int[mSize + 1];
	for (size_t i = 0; i < mSize; i++) {
		temp[i] = mData[i];
	}
	temp[mSize] = value;
	delete[] mData;
	mData = temp;
	mSize++;
}

void vector::insert(size_t pos, int value) {
	try {
		if (pos < mSize) {
			int *temp = new int[mSize + 1];
			for (size_t i = 0; i < pos; i++) {
				temp[i] = mData[i];
			}
			temp[pos] = value;
			for (size_t i = pos; i < mSize; i++) {
				temp[i + 1] = mData[i];
			}
			delete[] mData;
			mData = temp;
			mSize++;
		}
		else {
			throw "Out of range exception";
		}
	}
	catch (char *message) {
		cerr << message;
	}
}

void vector::erase(size_t pos) {
	try {
		if (pos < mSize) {
			int *temp = new int[mSize - 1];
			for (size_t i = 0; i < pos; i++) {
				temp[i] = mData[i];
			}
			for (size_t i = pos + 1; i < mSize; i++) {
				temp[i - 1] = mData[i];
			}
			delete[] mData;
			mData = temp;
			mSize--;
		}
		else {
			throw "Out of range exception";
		}
	}
	catch (char *message) {
		cerr << message;
	}
}

void vector::clear() {
	int *temp = new int[0];
	delete[] mData;
	mData = temp;
	mData = 0;
}

int vector::find(int value) const {
	for (size_t i = 0; i < mSize; i++) {
		if (mData[i] == value) {
			return i;
		}
	}
	return -1;
}

int vector::find(size_t start, size_t end, int value) const {
	try{
		if ((start < end) && (end < mSize)) {
			for (size_t i = start; i < end; i++) {
				if (mData[i] == value) {
					return i;
				}
			}
			return -1;
		}
		else {
			throw "Out of range exception";
		}

	}
	catch (char *message) {
		cerr << message;
	}
}

void vector::print() const {
	for (size_t i = 0; i < mSize; i++) {
		cout << mData[i] << " ";
	}
}

int &vector::operator[] (size_t pos) const {
	try {
		if (pos < mSize) {
			return mData[pos];
		}
		else {
			throw "Out of range exception";
		}
	}
	catch (char *message) {
		cerr << message;
	}
}

void vector::operator= (const vector& obj) {
	int *temp = new int[obj.mSize];
	delete[] mData;
	for (size_t i = 0; i < obj.mSize; i++) {
		temp[i] = obj[i];
	}
	mData = temp;
	mSize = obj.mSize;
}

vector::~vector() {
	delete[] mData;
}