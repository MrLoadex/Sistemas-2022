/*
Para el Archivo del ejercicio (a) 
contar la cantidad de palabras que hay x línea, luego
mostrar la cantidad total y el promedio de palabras x línea.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string ReadFile(string nameFile)
{
    string stringFile;
    ifstream in;
    in.open(nameFile);
    if (!in){ cerr << "Error opening file" << endl; exit(EXIT_FAILURE); }
    while (!in.eof())
    {
        string sentence;
        getline(in, sentence);
        stringFile += sentence + "\n";
    }
    in.close();
    return stringFile;
}

int CountSentences(string text)
{
    int count = 0;
    for (int i = 0; i < text.size() ; i++)
    {
        if (text[i] == '\n') {count ++;}
    }
    return count;
}

int CountWords(string text,int sentenceSelect)
{
    int i = 0; 
    int counterWords = 1;
    int counterSentence = 0;
    while (i < text.length())
    {
        if (sentenceSelect == -1 || counterSentence == sentenceSelect)
        {
            if (text[i] == ' ')
            {
                counterWords ++;
            }
        }
        if (sentenceSelect != -1 && text[i] == '\n')
        {
            counterSentence ++;
        }
        else if ( sentenceSelect == -1  && text[i] == '\n' && text[i+1] != 0)
        {
            counterWords++;
        }
        i++;
    }
    return counterWords;
}

int main()
{
    string text = ReadFile("QuotesOfBjarne.txt"); //Creo un string en base al archivo
    int countSentences = CountSentences(text); //Total de lineas en el archivo
    int countTotalWords = CountWords(text, -1); //Total de palabras en el archivo
    float wordAvarage = float(countTotalWords) / float(countSentences);//Promedio de palabras
    for(int i = 0; i < countSentences ; i++) //Imprimo cantidad de palabras por linea
    {
        int countWords = CountWords(text, i);
        cout << "En la linea " << i+1 << " hay " << countWords << " palabras." << endl;
    }
    cout << 
    "En total hay " << countSentences << " frases y " << countTotalWords << " palabras." << endl <<
    "Dando un promedio de " << wordAvarage << " por frase.";

    return 0;
}