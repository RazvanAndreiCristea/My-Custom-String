#include "String.h"

String::String() : buffer(nullptr)
{
	buffer = new char[1];
	buffer[0] = '\0';
}

String::String(const char* buffer)
{
	if (!buffer)
	{
		this->buffer = new char[1];
		this->buffer[0] = '\0';
	}

	else
	{
		this->buffer = new char[strlen(buffer) + 1];
		strcpy(this->buffer, buffer);
		this->buffer[strlen(buffer)] = '\0';
	}
}

String::String(const String& sir)
{
	if (!sir.buffer)
	{
		this->buffer = new char[1];
		this->buffer[0] = '\0';
	}

	else
	{
		this->buffer = new char[strlen(sir.buffer) + 1];
		strcpy(this->buffer, sir.buffer);
		this->buffer[strlen(sir.buffer)] = '\0';
	}
}

String::~String()
{
	if (buffer != nullptr)
		delete[] buffer;
}

String& String::operator=(const String& sir)
{
	if (this != &sir)
	{
		if (this->buffer != nullptr)
			delete[] this->buffer;

		if (!sir.buffer)
		{
			this->buffer = new char[1];
			this->buffer[0] = '\0';
		}

		else
		{
			this->buffer = new char[strlen(sir.buffer) + 1];
			strcpy(this->buffer, sir.buffer);
			this->buffer[strlen(sir.buffer)] = '\0';
		}
	}

	return *this;
}

int String::getLength() const
{
	return strlen(buffer);
}

int String::compare(const String& sir) const
{
	if (strcmp(this->buffer, sir.buffer) > 0)
		return 1;

	else if (strcmp(this->buffer, sir.buffer) == 0)
		return 0;

	else if (strcmp(this->buffer, sir.buffer) < 0)
		return -1;
}

void String::pushBack(const char& caracter)
{
	int lungime = this->getLength();
	char* temp = new char[lungime + 1];

	for (auto j = 0; j < lungime; j++)
		temp[j] = buffer[j];

	delete[] buffer;

	buffer = new char[lungime + 2];

	for (auto j = 0; j < lungime; j++)
		buffer[j] = temp[j];

	buffer[lungime] = caracter;
	buffer[lungime + 1] = '\0';

	delete[] temp;
}

void String::popBack()
{
	int lungime = this->getLength();
	char* temp = new char[lungime + 1];

	for (auto j = 0; j < lungime; j++)
		temp[j] = buffer[j];

	delete[] buffer;

	buffer = new char[lungime];

	for (auto j = 0; j < lungime - 1; j++)
		buffer[j] = temp[j];

	buffer[lungime - 1] = '\0';

	delete[] temp;
}

bool String::empty() const
{
	if (this->getLength() == 0)
		return true;

	return false;
}

void String::swap(String& sir)
{
	String auxiliar(sir);
	sir = *this;
	*this = auxiliar;
}

int String::findChar(const char& caracter) const
{
	for (auto j = 0; j < this->getLength(); j++)
		if (this->buffer[j] == caracter)
			return 1;

	return 0;
}

int String::countChar(const char& caracter) const
{
	int contor(0);

	for (auto j = 0; j < this->getLength(); j++)
		if (this->buffer[j] == caracter)
			contor++;

	if (!contor)
		return 0;

	return contor;
}

bool String::findString(const String& sir) const
{
	if (strstr(this->buffer, sir.buffer) != 0)
		return true;

	return false;
}

std::istream& operator>>(std::istream& intrare, String& sir)
{
	char* aux = nullptr;

	if (sir.buffer != nullptr)
		delete[] sir.buffer;

	aux = new char[200];

	std::cout << "Introduceti un string: ";
	intrare.getline(aux, 200);

	sir.buffer = new char[strlen(aux) + 1];
	strcpy(sir.buffer, aux);

	delete[] aux;

	return intrare;
}

std::ostream& operator<<(std::ostream& iesire, const String& sir)
{
	iesire << "Stringul introdus este: " << sir.buffer;

	return iesire;
}