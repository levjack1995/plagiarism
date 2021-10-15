#include <iostream>
#include "md5.h"

using namespace std;

int calculateCountOfWords(string str);
double calculateCoincidence(string wordsOfText[], string wordsOfFragment[], int arrSizeOfText, int arrSizeOfFragment);
int strLen(char str[]);
int strCmp(char destStr[], char srcStr[]);

bool isSeparator(char ch);

double antiPlagiarism(string text, string fragment);

void putWordsInArray(string text, string strArray[]);

const int N = 128;

int main()
{
    string str = "AW 2 3242 fdf, fdf";
    string strCmp = "AW 2 3242 fdf, fdf";

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

// по фрагмент
double calculateCoincidence(string wordsOfText[], string wordsOfFragment[], int arrSizeOfText, int arrSizeOfFragment)
{
    MD5 md5;
    int i = 0;
    int j = 0;
    int counterOfCoincidence = 0;

    int quantityOfTextSelections = arrSizeOfText - 2;
    int quantityOfFragmentSelections = arrSizeOfFragment - 2;

    for (i = 0; i < quantityOfFragmentSelections; i++)
    {
        string hashOfFragment = md5.digestString(wordsOfFragment[i]) + md5.digestString(wordsOfFragment[i + 1]) + md5.digestString(wordsOfFragment[i + 2]);
        for (j = 0; i < quantityOfTextSelections; j++)
        {
            string hashOfText = md5.digestString(wordsOfText[j]) + md5.digestString(wordsOfText[j + 1]) + md5.digestString(wordsOfText[j + 2]);
            if (hashOfFragment == hashOfText)
                counterOfCoincidence++;
        }
        j = 0;
    }
    return ((double)counterOfCoincidence / quantityOfFragmentSelections);
}
// int i = 0 ;
// int j = 0;
// int counterOfCoincidence = 0;
// while (str[i+2] != '0')
// str hash = md5.digetsString(str[i]) + md5.digetsString(str[i+1]) + md5.digetsString(str[i+2]);
//{ по текст
// while (str[j+2] != '0')
// str hashCmp = md5.digetsString(strCmp[j]) + md5.digetsString(strCmp[j+1]) + md5.digetsString(strCmp[j+2]);
//   }
// j = 0 ;
// if (hash == hashCmp){counterOfCoincidence++;}
//}
// return counterOfCoincidence;
double antiPlagiarism(string text, string fragment)
{
    int arrSizeOfText = calculateCountOfWords(text);
    int arrSizeOfFragment = calculateCountOfWords(fragment);

    string wordsOfText[arrSizeOfText];
    string wordsOfFragment[arrSizeOfFragment];

    putWordsInArray(text, wordsOfText);
    putWordsInArray(fragment, wordsOfFragment);

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

int strCmp(char destStr[], char srcStr[])
{
    int i = 0, flag = 0;
    while (flag == 0)
    {
        if (destStr[i] > srcStr[i])
        {
            flag = 1;
        }
        else if (destStr[i] < srcStr[i])
        {
            flag = -1;
        }
        else
        {
            i++;
        }
    }

    return flag;
}