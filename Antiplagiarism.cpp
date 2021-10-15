#include <iostream>
#include "md5.cpp"

using namespace std;

int calculateCountOfMeanWords(string str);
double calculateCoincidence(string wordsOfText[], string wordsOfFragment[], int arrSizeOfText, int arrSizeOfFragment);
int strLen(char str[]);
int strCmp(char destStr[], char srcStr[]);

bool isSeparator(char ch);
bool isConjuction(string word);

double antiPlagiarism(string text, string fragment);

void putWordsInArray(string text, string strArray[]);

int const N = 128;
int const QUANTITY_OF_CONJUNCTIONS = 15;

string const WORD_CONJUNCTIONS[QUANTITY_OF_CONJUNCTIONS] = {"and", "as", "or", "then", "but", "if", "till", "how", "so", "because", "unless", "until", "although", "however", "whenever"};

int main()
{
    string str = "black year and, man wolf";
    string strCmp = "black year as, man wolf2";

    cout << antiPlagiarism(strCmp, str);

    return 0;
}

double calculateCoincidence(string wordsOfText[], string wordsOfFragment[], int arrSizeOfText, int arrSizeOfFragment)
{
    int i = 0;
    int j = 0;
    int counterOfCoincidence = 0;

    int quantityOfTextSelections = arrSizeOfText - 2;
    int quantityOfFragmentSelections = arrSizeOfFragment - 2;

    for (i = 0; i < quantityOfFragmentSelections; i++)
    {
        string hashOfFragment = md5(wordsOfFragment[i] + wordsOfFragment[i + 1] + wordsOfFragment[i + 2]);
        for (j = 0; j < quantityOfTextSelections; j++)
        {
            string hashOfText = md5(wordsOfText[j] + wordsOfText[j + 1] + wordsOfText[j + 2]);
            if (hashOfFragment == hashOfText)
                counterOfCoincidence++;
        }
        j = 0;
    }
    return ((double)counterOfCoincidence / quantityOfFragmentSelections);
}

double antiPlagiarism(string text, string fragment)
{
    int arrSizeOfText = calculateCountOfMeanWords(text);
    int arrSizeOfFragment = calculateCountOfMeanWords(fragment);

    string wordsOfText[arrSizeOfText];
    string wordsOfFragment[arrSizeOfFragment];

    putWordsInArray(text, wordsOfText);
    putWordsInArray(fragment, wordsOfFragment);

    return calculateCoincidence(wordsOfText, wordsOfFragment, arrSizeOfText, arrSizeOfFragment);
}
int calculateCountOfMeanWords(string str)
{
    char word[N];
    int i = 0;
    int iw = 0;
    int wCounter = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (!isSeparator(str[i]))
        {
            word[iw] = str[i];
            iw++;
            if (isSeparator(str[i + 1]) || str[i + 1] == '\0')
            {
                word[iw] = '\0';
                if (!isConjuction(word))
                    wCounter++;
                //cout << word << endl;
                iw = 0;
            }
        }
    }
    return wCounter;
}

bool isSeparator(char ch)
{
    char separator[] = {'.', ',', ';', '!', '?', ':', ' ', '-', '+', '{', '}', '(', ')', '[', ']', '*', '@', '%', '$', '^', '&', '#', '`', '_', '=', '<', '>', '/', '|', '\'', '\\', '\"'};
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
            if (isSeparator(text[i + 1]) || text[i + 1] == '\0')
            {
                word[iw] = '\0';
                if (!isConjuction(word))
                    strArray[wCounter++] = word;
                //cout << word << endl;
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

bool isConjuction(string word)
{
    for (int i = 0; i < QUANTITY_OF_CONJUNCTIONS; i++)
    {
        if (word == WORD_CONJUNCTIONS[i])
            return true;
    }
    return false;
}