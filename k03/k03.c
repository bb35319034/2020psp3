#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
    int start, pos;
    int text_len;
    int key_len;

    text_len = strlen(text);
    key_len = strlen(key);

    for(start=0; start<(text_len - key_len); start++)
    {
        for(pos=0; pos<key_len; pos++)
        {
            if(text[start + pos] == key[pos])
            {
                if(key_len == pos+1)
                {
                    return &text[start];
                }
            }
            else
            {
                break;
            }
            
        }
    }
    return NULL;
}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
    int start, start2, pos;
    char table[256];
    int i;
    int text_len = strlen(text);
    int key_len = strlen(key);


    for(i = 0; i < 256; i++)
    {
        table[i] = strlen(StrKey);
    }

    for(i = 0; i<=strlen(StrKey); i++)
    {
        table[StrKey[i]] = strlen(StrKey) - (i+1);
    }


    start = key_len-1;

    while(start < text_len)
    {
        start2 = start;
        for(pos = key_len-1; pos >= 0; pos--)
        {
            if(text[start] == key[pos])
            {
                start--;

                if(pos==0)
                {
                    return &text[start];
                }
            }
            else 
            {
                break;
            }
        }

        start += table[text[start]];

        if(start <= start2)
        {
            start = start2 + 1;
        }
    
    }
    return NULL;
}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}