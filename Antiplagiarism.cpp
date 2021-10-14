#include <iostream>
#include "md5.h"

using namespace std;

int calculateCountOfWords(string str);
int strLen(char str[]);

bool isSeparator(char ch);

double antiPlagiarism(string text, string fragment);

void putWordsInArray(string text, string strArray[]);

const int N = 128;

int main()
{
    string str = "AW 2 3242 fdf, fdf";
    string strCmp = "AW 2 3242 fdf, fdg";

    double b = antiPlagiarism(str, str);

    return 0;
}

// определить количество слов в тексте - метод , он же и будет считать количество выборок ++
// string word[words] = {text...}; Создаём массив
// int main(int argc, const char **argv)
// {
//     char text[N];
//     char word[N];
//     int i = 0;
//     int iw = 0;
//     // int wCounter = 0;

//     cout << "input text" << endl;
//     cin.getline(text, N);
//     // AW H
//     // i = 3 iw = 3

//     for (i = 0; text[i] != '\0'; i++)
//     {
//         if (!isSeparator(text[i])){
// 			word[iw] = text[i];
// 			iw++;
// 			if (isSeparator(text[i+1]) or text[i+1] == '\0'){
// 				word[iw] = '\0';
// 				// string str[wCounter++] = word;
// 				cout << word << endl;
// 				iw = 0;
// 			}
//     }
// }
//     return 0;
// }

// for (проверка выборки , равны ли хеши.)
// >> 2 массива строк.

// AW 2;
double antiPlagiarism(string text, string fragment)
{
    int arrSizeOfText = calculateCountOfWords(text);
    int arrSizeOfFragment = calculateCountOfWords(fragment);

    string str[arrSizeOfText];
    string fragmentStr[arrSizeOfFragment];

    putWordsInArray(text, str);
    putWordsInArray(fragment, fragmentStr);

    return 0;
}
int calculateCountOfWords(string str)
{
    int i = 0;
    int counter = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (!isSeparator(str[i]))
            if (isSeparator(str[i + 1]) or str[i + 1] == '\0')
                counter++;
    }
    return counter;
}

bool isSeparator(char ch)
{
    char separator[] = {'/', '.', ',', ';', '!', '?', ':', ' '};
    for (int i = 0; separator[i] != 0; i++)
    {
        if (ch == separator[i])
            return true;
    }
    return false;
}

void putWordsInArray(string text, string strArray[])
{
    char word[N];
    int i = 0;
    int iw = 0;
    int wCounter = 0;

    // AW H
    // i = 3 iw = 3

    for (i = 0; text[i] != '\0'; i++)
    {
        if (!isSeparator(text[i]))
        {
            word[iw] = text[i];
            iw++;
            if (isSeparator(text[i + 1]) or text[i + 1] == '\0')
            {
                word[iw] = '\0';
                strArray[wCounter++] = word;
                cout << word << endl;
                iw = 0;
            }
        }
    }
}

int strLen(char str[])
{
    int i = 0;
    int ch = str[i];

    while (ch != 0)
    {
        ch = str[++i];
    }
    return i;
}