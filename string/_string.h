
#ifndef ___STRING_H__
#define ___STRING_H__
class _string
{
private:
	int len;
	char *str;
	int _strlen(const char *s)
	{
		int i=0;
		while (s[i] != '\0')i++;
		return i;
	}
	int _strcmp(const char *s1, const char *s2)
	{
		int i;
		for (i = 0; s1[i] != '\0'; i++)
		{
			if (s1[i] < s2[i])return -1;
			else if (s1[i] > s2[i])return 1;
		}
		return s1[i] == s2[i] ? 0 : -1;
	}
	void _strcpy(char *s1, const char *s2)
	{
		int i;
		for (i = 0; s2[i] != '\0'; i++)s1[i] = s2[i];
		s1[i] = '\0';
	}
	void _strcat(char *s1, const char *s2)
	{
		int i = _strlen(s2);
		int j = 0;
		while (s2[j] != '\0')s1[i++] = s2[j++];
		s1[i] = '\0';
	}
public:
	_string();
	_string(const char *s);
	_string(const _string& s);
	~_string();
	int size();
	_string& operator=(const _string& s);
	_string& operator+=(const _string& s);
	bool operator==(const _string& s);
	bool operator!=(const _string& s);
	bool operator < (const _string& s);
	bool operator > (const _string& s);
	_string operator +(const _string& s);
	friend std::istream& operator >>(std::istream& is,  _string& s);
	friend std::ostream& operator<<(std::ostream& os, const _string& s);
};



#endif