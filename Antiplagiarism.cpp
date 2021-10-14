#include <iostream>
#include "md5.h"

using namespace std;

int main()
{

    cout << "Hello world";

    return 0;
}

// определить количество слов в тексте - метод , он же и будет считать количество выборок
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