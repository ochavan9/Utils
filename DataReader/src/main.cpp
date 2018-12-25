#include <iostream>
#include "DataReader.h"

using namespace std;

int main()
{
    unsigned char b[] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38};
    unsigned int sz = *(&b + 1) - b;
    DataReader m(b, sz);
    unsigned char c = '\0';
    unsigned short w = 0;
    m.getByte(c);
    m.getWord(w);
    cout << m.getDataSize() << endl;
    cout << c <<endl;
    cout << w << endl;
    m.skipBytes(2);
    unsigned char d[4] = {0};
    m.getData(d, 4);
    for (int i = 0; i<4; i++)
    {
        cout << i << "=" ;
        cout << d[i] << '\n';
    }
    cout << endl;
    return 0;
}
