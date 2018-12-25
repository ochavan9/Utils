
class DataReader
{
    unsigned char* pdata;
    unsigned int datalen;
    unsigned int offset;
    bool deepCopy;

    DataReader& operator=(const DataReader&);
    void _clear();
public:
    DataReader(unsigned char* pbuff, unsigned int size, bool copyPtrOnly = true);
    ~DataReader();

    bool getByte(unsigned char& byte);      //Get single byte from buffer
    bool getWord(unsigned short& word);     //Get word from buffer
    bool getData(void *data, int len);      //get 'len' size data
    unsigned char* getDataPtr();	        //Get current buffer address
	int getDataSize();			            //Get len of data not read
    bool skipBytes(int bytesToSkip);        //skip n bytes from buffer
    bool changeByte(const unsigned char& newVal, unsigned int position);  //change single byte in buffer
};
