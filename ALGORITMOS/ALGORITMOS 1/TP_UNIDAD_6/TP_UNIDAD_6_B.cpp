#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const short int max_words = 30;
typedef string tListWord[max_words][2];
tListWord words;

void ShowPhraseAsColumn(string phrase);

int main()
{
    string phrase;
    cout << "introduzca una frase:" << endl;
    getline(cin, phrase);
    ShowPhraseAsColumn(phrase);
}

void ShowPhraseAsColumn(string phrase)
{
    int phrase_position = 0;
    string word = "";
    string spaces = "";

   for (;phrase_position < phrase.size();phrase_position ++)
    {
        if (phrase[phrase_position] != ' ')
        {
            word += phrase[phrase_position];

        }
        else if (phrase_position != 0)
        {
            for (int i = word.size(); i <= 8; i++)
            {
                spaces += " ";
            }
            cout << word << spaces << word.size() << endl;
            word = "";
            spaces = "";
        }
    }
    for (int i = word.size(); i <= 8; i++)
    {
        spaces += " ";
    }
    cout << word << spaces << word.size() << endl;
    
}