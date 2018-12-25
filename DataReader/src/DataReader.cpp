#include <iostream>
#include <string.h>
#ifdef _WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#endif
#include "DataReader.h"

DataReader::DataReader(unsigned char* pbuff, unsigned int size, bool copyPtrOnly /*= true*/)
{
    if(copyPtrOnly == true)
    {
        pdata = pbuff;
        deepCopy = false;
    }
    else
    {
        pdata = new unsigned char[size];
        memcpy(pdata, pbuff, size);
        deepCopy = true;
    }
    datalen = size;
    offset = 0;
}

DataReader::~DataReader()
{
	_clear();
}

void DataReader::_clear()
{
	if(deepCopy && pdata != NULL)
    {
        delete[] pdata;
    }
    pdata = NULL;
    datalen = 0;
    offset = 0;
}

bool DataReader::skipBytes(int bytesToSkip)
{
    if((offset + bytesToSkip) > datalen)
    {
        return false;
    }
    offset += bytesToSkip;
    return true;
}

bool DataReader::getData(void *data, int len)
{
    if((offset + len) > datalen)
    {
        return false;
    }
    memcpy(data, (pdata + offset), len);
    offset += len;
    return true;

}

bool DataReader::getByte(unsigned char& byte)
{
    return getData(&byte, sizeof(byte));
}

bool DataReader::getWord(unsigned short& word)
{
    unsigned short w = 0;
    if(!getData(&w, sizeof(w)))
    {
        return false;
    }
    word = ntohs(w);
    return true;
}

int DataReader::getDataSize()
{
    return datalen - offset;
}

unsigned char* DataReader::getDataPtr()
{
    return pdata + offset;
}

bool DataReader::changeByte(const unsigned char& val, unsigned int position)
{
	if (position > datalen)
    {
        return false;
    }
	memcpy((pdata + position), &val, sizeof(unsigned char));
	return true;
}
