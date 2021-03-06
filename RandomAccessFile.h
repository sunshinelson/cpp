#pragma once
#include <fstream>
using namespace std;

class RandomAccessFile {
	fstream m_file;
	string m_fileName;

public:
	struct IOException : public exception {
		IOException(const char* msg) : exception(msg) {}
	};

	RandomAccessFile(const string& fileName);
	virtual ~RandomAccessFile() = default;

	streamsize length();
	operator bool() const { return m_file.good(); }
	bool truncate(streamsize s);

	// generic methods
	template<class T> T read(streampos pos = -1);
	template<class T> void write(const T& data, streampos pos = -1);


};