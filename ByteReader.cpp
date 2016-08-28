#include "stdafx.h"
#include "ByteReader.h"


long getFileSize(FILE *file);


// Initialize ByteReader object to read from the given rom file path.
ByteReader::ByteReader(const string& romFilePath) :
	_filePath(romFilePath.c_str())
{
	// Open file in binary mode using rb format string
	// also, check if file exists and can be opened for reading
	if ((_file = fopen(_filePath, "rb")) == NULL)
	{
		cout << "Could not open specified file" << endl;
	}
	else
	{
		cout << "File opened successfully" << endl;
	}

	// Get size of file in bytes, then allocate memory to buffer,
	// finally read file into buffer for later use.
	_fileSize = getFileSize(_file);
	_fileBuf = new BYTE[_fileSize];
	fread(_fileBuf, _fileSize, 1, _file);
}


ByteReader::~ByteReader()
{
}


// Read byte of data from the file buffer in the given location.
BYTE ByteReader::readByte(long loc)
{
	return _fileBuf[loc];
}


// Non-member functions ========================================

// Get the size of a file in Bytes.
long getFileSize(FILE *file)
{
	long lCurPos, lEndPos;
	lCurPos = ftell(file);
	fseek(file, 0, 2);
	lEndPos = ftell(file);
	fseek(file, lCurPos, 0);
	return lEndPos;
}