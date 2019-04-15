#include "stdafx.h"
#include "basic_string.h"
#include <string.h>
#include <iostream>


basic_string::basic_string(void)
{
	m_ptr = new char[1];
	m_ptr ='\0';
	m_Length =0;
}
void basic_string::Allocate(const char *pstr){
	size_t newLen= strlen(pstr);
	m_ptr = new char[newLen+1];
	strcpy(m_ptr,pstr);
	m_Length = newLen;
}
basic_string::basic_string(const char* ptr){
	Allocate(ptr);
}

basic_string::basic_string(const basic_string & other){
	Allocate(other.m_ptr);
}
basic_string& basic_string::operator=(const basic_string &other){
	if(this!=&other){
		Allocate(other.m_ptr);
	}
	return *this;
}

basic_string basic_string::operator+(const basic_string &other){
	Insert(other.m_ptr,m_Length);
	return *this;
}
void basic_string::Insert(const char* str, size_t index){
	size_t newLength = strlen(str)+m_Length;
	char* temp = new char[newLength+1];
	if(index == 0){
		if(m_ptr == '\0'){
			Allocate(str);
			return;
		}
		strcpy(temp,str);
		strcat(temp,m_ptr);
	}else if( index == m_Length){
		strcpy(temp,m_ptr);
		strcat(temp,str);
	}else if( index < m_Length){
		strncpy(temp,m_ptr,index);
		strcpy(temp+index,str);
		strcpy(temp,m_ptr+index);
	}
	delete[] m_ptr;
	m_ptr = temp;
	m_Length = newLength;	
}

basic_string::~basic_string(void)
{
	delete[] m_ptr;
}

void StringOPs(){
	basic_string s("SHIFA ");
	basic_string s1("HOW ARE YOU?");
	s.Insert("HELLO! ",0);
	s.Insert("SABHA ",s.getLength());
	std::cout<<s.getString()<<std::endl;
	basic_string s2 = s+s1;
	std::cout<<s2.getString()<<std::endl;

}