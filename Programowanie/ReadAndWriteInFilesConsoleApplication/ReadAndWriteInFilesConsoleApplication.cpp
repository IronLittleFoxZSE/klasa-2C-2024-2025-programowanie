// ReadAndWriteInFilesConsoleApplication.cpp 

#include <iostream>
#include <fstream>


//zapis do pliku
void task1()
{
    std::string name;
    int age;
    
    std::cout << "Podaj imie\n";
    std::cin >> name;

    std::cout << "Podaj wiek\n";
    std::cin >> age;

    std::ofstream writeToFile;
    writeToFile.open("c:\\plik2C.txt", std::ios_base::app);

    if (writeToFile.is_open() == true)
    {
        //prace na pliku
        writeToFile << name << "\n" << age << "\n";
        writeToFile.flush();
        //writeToFile << age;

        writeToFile.close();
    }
}

void task2()
{
    std::ifstream readFromFile;
    readFromFile.open("c:\\plik2C.txt");
    if (readFromFile.is_open())
    {
        std::string name;
        int age;

        //while (readFromFile.eof() == false)
        while(readFromFile >> name)
        {
            //readFromFile >> name;
            readFromFile >> age;

            std::cout << "Imie " << name << " wiek " << age << "\n";
        }

        readFromFile.close();
    }
}

int main()
{
    task2();
}

