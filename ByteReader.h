#pragma once

#include <stdio.h>
#include <string>
#include <iostream>

typedef unsigned char BYTE;

using std::string;	using std::ifstream;
using std::cout;	using std::endl;
using std::cin;


class ByteReader
{
public:
	ByteReader(const string& romFilePath);
	~ByteReader();

	BYTE readByte(long loc);
	long getByteNum();

private:
	const char* _filePath;
	BYTE* _fileBuf; // Pointer to buffered data
	FILE* _file = NULL;
	long _fileSize; // File size in bytes
};

