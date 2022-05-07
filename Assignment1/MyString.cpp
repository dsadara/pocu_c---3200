#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		: mSize(myStrlen(s))
	{
		mString = new char[mSize + 1];
		//memset(mString, 0, mSize + 1);
		//memcpy(mString, s, mSize + 1);
		myMemcpy(mString, s, mSize + 1);
	}

	MyString::MyString(const MyString& other)
		: mSize(other.mSize)
	{
		mString = new char[mSize + 1];
		//memset(mString, 0, mSize + 1);
		//memcpy(mString, other.mString, mSize + 1);
		myMemcpy(mString, other.mString, mSize + 1);
	}

	MyString::~MyString()
	{
		delete[] mString;   // 생성할 때 배열로 생성했으므로 배열표시[]를 넣어줌
	}

	unsigned int MyString::GetLength() const
	{
		return mSize;
	}

	const char* MyString::GetCString() const
	{
		return mString;
	}

	void MyString::Append(const char* s)
	{
		int sSize = myStrlen(s);
		char* result = new char[mSize + sSize + 1];
		//memcpy(result, mString, mSize + 1);
		myMemcpy(result, mString, mSize + 1);
		delete[] mString;   // 이전 mString 메모리 해제
		//strncat(result, s, sSize + 1);
		myStrncat(result, s, sSize + 1);
		mSize = mSize + sSize + 1;
		mString = result;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		//int size = mSize + other.GetLength() + 1;
		//char* result = new char[size];
		////memset(result, 0, size);
		////memcpy(result, mString, mSize + 1);
		//myMemcpy(result, mString, mSize + 1);
		//strncat(result, other.GetCString(), other.GetLength() + 1);
		//return MyString(result);
		MyString result(this->GetCString());
		result.Append(other.GetCString());
		return result;
	}

	int MyString::IndexOf(const char* s)
	{
		return 0;
	}

	int MyString::LastIndexOf(const char* s)
	{
		return 0;
	}

	void MyString::Interleave(const char* s)
	{
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		return false;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
	}

	void MyString::PadRight(unsigned int totalLength)
	{
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
	}

	void MyString::Reverse()
	{
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		return false;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		return *this;
	}

	void MyString::ToLower()
	{
	}

	void MyString::ToUpper()
	{
	}

	int MyString::myStrlen(const char* s)
	{
		const char* ptr = s;
		int count = 0;
		while (*ptr != 0)
		{
			ptr++;
			count++;
		}

		return count;
	}

	void MyString::myMemcpy(char* dst, const char* src, int size)
	{
		for (int i = 0; i < size; i++)
		{
			*dst = *src;
			dst++;
			src++;
		}
	}

	void MyString::myStrncat(char* dst, const char* src, int size)
	{
		// find null character
		char* ptr = dst;
		while (*ptr != 0) 
		{
			ptr++;
		}
		// memcpy from null character
		myMemcpy(ptr, src, size);
	}

}