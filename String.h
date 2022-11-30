#pragma once
#include <iostream>
#include <string>
#pragma warning (disable : 4996)
#pragma warning (disable : 6031)

class String
{
	char* buffer;

public:

	String();

	String(const char*);

	String(const String&);

	~String();

	String& operator=(const String&);

	int getLength() const;

	int compare(const String&) const;

	void pushBack(const char&);

	void popBack();

	bool empty() const;

	void swap(String&);

	int findChar(const char&) const;

	int countChar(const char&) const;

	bool findString(const String&) const;

	friend std::istream& operator>>(std::istream&, String&);

	friend std::ostream& operator<<(std::ostream&, const String&);
};