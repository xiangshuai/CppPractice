#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include "Blowfish/Blowfish.h"

using namespace std;

// Return file size
long GetFileSize(string &filePath)
{
    ifstream infile;
    infile.open(filePath.c_str());

    infile.seekg(0, infile.end);
    long length = infile.tellg();
    infile.seekg(0, infile.beg);

    infile.close();

    return length;
}

char * ReadFile(string &filePath, long pos, long length)
{
    ifstream infile(filePath.c_str(), ifstream::in);
    if(infile.good())
    {
        char *buffer = new char[length];
        infile.read(buffer, length);
        return buffer;
    }
    return NULL;

}

int main()
{
    //string filePath = "c:\\image.jpg";
    string filePath = "d:\\test.txt";

    // Get file size which need to be encrypted
    long originalSize = GetFileSize(filePath);

    cout << originalSize <<endl;

    // Make this size multiple of block size(8 bytes)
    long multipleSize = (originalSize/8 + 1) * 8;
    cout << multipleSize << endl;

    // Store number of bytes that were needed for padding
    int nubPaddingBytes = (int)(multipleSize - originalSize);

    // Now, read the file
    char *content = ReadFile(filePath, 0, originalSize);

    char *buffer = new char[multipleSize];
    memcpy(buffer, content, originalSize);

    delete content;
    content = NULL;

    for(int i=0; i<nubPaddingBytes; i++)
    {
        buffer[originalSize+i] = nubPaddingBytes;
    }
    char *chipertext = new char[multipleSize];

    try
    {
        CBlowFish blowfish((unsigned char*)"defkey00", 8);

        // Do encryption
        blowfish.Encrypt(buffer, chipertext, multipleSize);

        // Do decryption
        blowfish.Decrypt(chipertext, buffer, multipleSize);

        // Check padding byte
        if(buffer[multipleSize-1]<1 || buffer[multipleSize-1]>8)
        {
            exit(1);
        }

        for(int i=1; i<buffer[multipleSize-1]; i++)
        {
            if(buffer[originalSize+i-1]!=buffer[multipleSize-1]
               || buffer[originalSize+i-1] != buffer[originalSize+i])
            {
                exit(1);
            }
        }

        cout << "success" <<endl;

    }


    return 0;
}
