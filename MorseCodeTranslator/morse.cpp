#include <iostream>
using namespace std;

// Função que traduz código Morse para letra
char morseToText(const string &code)
{
    char lettersBig[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                           'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                           'U', 'V', 'W', 'X', 'Y', 'Z',
                           '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    char lettersSmall[36] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                             'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                             'u', 'v', 'w', 'x', 'y', 'z',
                             '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    const char *morse[36] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--..",
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

    for (int i = 0; i < 36; i++)
    {
        if (code == morse[i])
            return lettersBig[i]; // retorna letra maiúscula
    }

    return '?'; // retorna '?' se não encontrar
}

const char *textToMorse(char letra)
{
    char lettersBig[36] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                           'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                           'U', 'V', 'W', 'X', 'Y', 'Z',
                           '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char lettersSmall[36] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                             'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                             'u', 'v', 'w', 'x', 'y', 'z',
                             '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    const char *morse[36] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--..",
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

    // Espaço entre palavras
    if (letra == ' ')
        return " ";

    // Procurar letra no array
    for (int i = 0; i < 36; i++)
    {
        if (letra == lettersBig[i] || letra == lettersSmall[i])
        {
            return morse[i]; // Retorna string Morse correspondente
        }
    }

    return ""; // Se não encontrar, retorna string vazia
}

int main()
{
    int opcao = 0;

    cout << "Você quer traduzir: \n"
         << endl
         << "[1]: Texto para Morse Code" << endl
         << "[2]: Morse Code para Texto" << endl;
    cout << "Resposta: ";
    cin >> opcao;

    string sentenca = "";
    char morse;

    if (opcao == 1)
    {
        cout << "Digite a frase para ser traduzida." << endl
             << "Sentença: ";
        cin.ignore();

        getline(cin, sentenca);

        cout << endl
             << "Código Morse: ";

        for (size_t i = 0; i < sentenca.length(); i++)
        {
            char c = sentenca[i];
            cout << textToMorse(c) << " ";
        }

        cout << endl;
    }

    else if (opcao == 2)
    {
        string morseInput;
        cin.ignore();
        getline(cin, morseInput);

        string result = "";
        string letter = "";
        int spaceCount = 0;

        for (size_t i = 0; i <= morseInput.length(); i++)
        {
            char c = (i < morseInput.length()) ? morseInput[i] : ' '; // adiciona espaço final para processar última letra

            if (c != ' ')
            {
                letter += c;
                spaceCount = 0;
            }
            else
            {
                spaceCount++;

                // uma letra terminou
                if (!letter.empty() && spaceCount == 1)
                {
                    result += morseToText(letter);
                    letter = "";
                }

                // palavra terminou (3 espaços consecutivos)
                if (spaceCount == 3)
                {
                    result += ' ';
                    spaceCount = 0;
                }
            }
        }
        cout << "Texto traduzido: " << result << endl;
    }
    return 0;
}