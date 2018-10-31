#include<iostream>
#include"_string.h"
_string::_string()
{
	len = 0;
	str = nullptr;
}
_string::_string(const char *s)
{
	len = _strlen(s);
	str = new char[len+1];
	_strcpy(str, s);
}
_string::_string(const _string &s)
{
	len = s.len;
	str = new char[len+1];
	_strcpy(str, s.str);
}
_string::~_string()
{
	len = 0;
	if (str != nullptr)delete[] str;
}
int _string::size()
{
	return len;
}
_string& _string::operator = (const _string &s)
{
	if (str != nullptr)
		delete[] str;
	len = s.len;
	str = new char[len+1];
	_strcpy(str, s.str);
	return *this;
}
_string& _string::operator+=(const _string& s)
{
	len = len + s.len;
	char *tmp = new char[len+1];
	_strcpy(tmp, str);
	_strcat(tmp, s.str);
	if (str != nullptr)
		delete[] str;
	str = tmp;
	return *this;
}

bool _string::operator==(const _string &s)
{
	return !_strcmp(str, s.str);
}
bool _string::operator!=(const _string& s)
{
	return _strcmp(str, s.str);
}
bool _string::operator<(const _string& s)
{
	return strcmp(str, s.str) == -1;
}
bool _string::operator>(const _string& s)
{
	return strcmp(str, s.str) == 1;
}
_string _string::operator + (const _string& s)
{
	char *tmp = new char[len + s.len+1];
	_strcpy(tmp, str);
	_strcat(tmp, s.str);
	_string tmpStr(tmp);
	delete[] tmp;
	return tmpStr;
}
std::istream& operator>>(std::istream& is, _string& s)
{
	char buf[1 << 10];
	is >> buf;
	s = _string(buf);
	return is;
}
std::ostream& operator<<(std::ostream& os, const _string& s)
{
	os << s.str;
	return os;
}

