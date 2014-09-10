#include<iostream>

struct MPQHASHTABLE 
{
     bool bExists;
     unsigned long nHashA;
     unsigned long nHashB;
};

unsigned long cryptTable[0x500];

void PrepareCryptTable()
{
    unsigned long seed = 0x00100001;
    unsigned long index1 = 0;
    unsigned long index2 = 0;
    unsigned long i;

    for(index1 = 0; index1 < 0x100; index1++)
    {
        for(index2 = index1, i = 0; i < 5; i++, index2 += 0x100)
        {
            unsigned long temp1, temp2;

            seed = (seed * 125 + 3) % 0x2AAAAB;
            temp1 = (seed & 0xFFFF) << 0x10;

            seed = (seed * 125 + 3) % 0x2AAAAB;
            temp2 = (seed & 0xFFFF);

            cryptTable[index2] = (temp1 | temp2);
        }
    }
}

unsigned long HashString(const char *lpszFileName, unsigned long dwHashType)
{
    unsigned char *key = (unsigned char *)lpszFileName;
    unsigned long seed1 = 0x7FED7FED;
    unsigned long seed2 = 0xEEEEEEEE;
    int ch;

    while(*key != 0)
    {
        ch = toupper(*key++);

        seed1 = cryptTable[(dwHashType << 8) + ch] ^ (seed1 + seed2);
        seed2 = ch + seed1 + seed2 + (seed2 << 5) + 3;
    }
    return seed1;
}

const int HASH_OFFSET = 0, HASH_A = 1, HASH_B = 2;

int GetHashTablePos(char *lpszString, MPQHASHTABLE *lpTable, int nTableSize)
{
    int nHash = HashString(lpszString, HASH_OFFSET); 
    int nHashA = HashString(lpszString, HASH_A); 
    int nHashB = HashString(lpszString, HASH_B);  
    int nHashStart = nHash % nTableSize; 
    int nHashPos = nHashStart;

    while (lpTable[nHashPos].bExists)
    {
        if (lpTable[nHashPos].nHashA == nHashA && lpTable[nHashPos].nHashB == nHashB)
            return nHashPos;
        else
            nHashPos = (nHashPos + 1) % nTableSize;
         
        if (nHashPos == nHashStart)
            break;
    }

    return -1; //Error value
}

int main(int argc, char **argv)
{
    const int hashA = 1;
    const int hashB = 2;
    const char * str[4] = {"name", "robbie", "sorry", "a"};
    MPQHASHTABLE table[4];
    for(int i = 0; i < 4; ++i)
    {
        int hashpos = HashString(str[i], HASH_OFFSET)%4;
        int startpos = hashpos;
        while(1)
        {
            if(table[hashpos].bExists == false)
            {
                std::cout<<str[i]<<" : "<<hashpos<<std::endl;
                table[hashpos].bExists = true;
                table[hashpos].nHashA = HashString(str[i], hashA);
                table[hashpos].nHashB = HashString(str[i], hashB);

                break;
            }
            else
            {
                hashpos = (hashpos+1)%4;
                if(hashpos == startpos)
                {
                    std::cout<<"no space for "<<str[i]<<std::endl;
                    break;
                }
            }
        }
    }  
    return 0;
}
