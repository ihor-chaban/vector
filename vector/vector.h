#ifndef _vector_h
#define _vector_h

class vector {
	int *mData;
	size_t mSize;

public:
	vector();
	vector(size_t, int = 0);
	vector(const vector&);

	void push_back(int);
	void insert(size_t, int);
	void erase(size_t);
	void clear();
	int find(int) const;
	int find(size_t, size_t, int) const;

	void print() const;

	int &operator[] (size_t) const;
	void operator=(const vector&);
	virtual ~vector();
};

#endif