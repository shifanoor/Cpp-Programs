#pragma once
class basic_string
{
	char* m_ptr;
	size_t m_Length;
	void Allocate(const char *pstr);
public:
	basic_string(void);
	basic_string(const char* ptr);
	basic_string(const basic_string & other);
	basic_string& operator=(const basic_string &other);
	~basic_string(void);
	basic_string operator+(const basic_string &other);
	void Insert(const char* str, size_t index);
	char* getString()const{
		return m_ptr;
	}
	size_t getLength()const{
		return m_Length;
	}
};

void StringOPs();

