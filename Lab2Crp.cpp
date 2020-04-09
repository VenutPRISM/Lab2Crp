// Lab2Crp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//написать программу, осуществляющую шифрование и дешифрование
//произвольных файлов при помощи четырех примитивных криптоалгоритмов.Допускается как
//реализация всех криптоалгоритмов в разных программах, так и в одной программе,
//запускаемой в разных режимах.Программа должна генерировать ключ, сохранять его в
//ключевом файле, считывать ключ из ключевого файла, шифровать данный файл по ключу и
//расшифровывать закрытый файл
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Функция открытия файла ключей
void OpenKeyFile() {
    const string PathOpenKeyFile = "KeyStore.txt";
    setlocale(LC_ALL, "rus");
    ifstream input(PathOpenKeyFile);
    string line;
    if (input.is_open()) {
        while (getline(input, line)) {
            cout << line << endl;

        }

    }
    else {
        cout << "Error open Key File" << endl;
    }

    getline(input, line);
    cout << line << endl;
} // Функция открытия файла ключей

void WriteKeyFile() {
    const string PathWriteFile = "DecryptKeys.txt";
    ofstream output(PathWriteFile);
    output << "Тут должен быть ключи для декрпитора" << endl;



}

class vernam
{
public:
    string s, k;
    char enc[1000], dec[1000];
    vernam(string a, string b)
    {
        s = a;
        k = b;
    }
    void encrypt()
    {
        int i, j = 0;
        for (i = 0; i < s.size(); i++)
        {
            enc[i] = s[i] ^ k[j];
            j++;
            if (j >= k.size())
            {
                j = 0;
            }
        }
    }
    void decrypt()
    {
        int i, j = 0;
        for (i = 0; i < s.size(); i++)
        {
            dec[i] = enc[i] ^ k[j];
            j++;
            if (j >= k.size())
            {
                j = 0;
            }
        }
    }
    void printenc()
    {
        int i;
        char c;
        for (i = 0; i < s.size(); i++)
        {
            c = enc[i] % 74 + 48;
            cout << c;
        }
        cout << endl;
    }
    void printdec()
    {
        int i;
        for (i = 0; i < s.size(); i++)
        {
            cout << dec[i];
        }
        cout << endl;
    }
};



int main()
{
    OpenKeyFile();
    WriteKeyFile();
    ifstream input("DecryptKeys.txt");
    if (input) {
        string line;
        while (getline(input, line))
        {
            cout << line << endl;

        }
    }
    //Для Вернама
    string s, k;
    cout << "Enter the Plain Text Message" << endl;
    getline(cin, s);
    cout << "Enter the Key" << endl;
    getline(cin, k);

    vernam v(s, k);

    v.encrypt();
    cout << "Encrypted Message : ";
    v.printenc();
    cout << endl;

    v.decrypt();
    cout << "Decrypted Message : ";
    v.printdec();






    return 0;



}

