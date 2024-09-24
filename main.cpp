#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <cctype>  // Dla funkcji toupper()

// Litery zapisane w tablicach znaków na 7 wierszy
const char* letterA[] = {
    "     __      ",
    "   /    \\    ",
    "  /  /\\  \\   ",
    " /  /__\\  \\  ",
    "/  /    \\  \\ ",
    "\\_/      \\_/ ",
    "              "
};

const char* letterB[] = {
    "  ____   ",
    " |  _ \\  ",
    " | |_| | ",
    " |  _  { ",
    " | |_| | ",
    " |____/  ",
    "         "
};

const char* letterC[] = {
    "   ____   ",
    "  / __ \\  ",
    " / /  \\_| ",
    "| |       ",
    "| \\____   ",
    " \\_____|  ",
    "          "
};

const char* letterD[] = {
    "  _____   ",
    " |  __ \\  ",
    " | |  \\ \\ ",
    " | |   | |",
    " | |__/ / ",
    " |_____/  ",
    "          "
};

const char* letterE[] = {
    "  ______  ",
    " |  ____| ",
    " | |___   ",
    " |  ___|  ",
    " | |____  ",
    " |______| ",
    "          "
};

const char* letterF[] = {
    "  ______  ",
    " |  ____| ",
    " | |___   ",
    " |  ___|  ",
    " | |      ",
    " |_|      ",
    "          "
};

const char* letterG[] = {
    "   _____  ",
    "  / ___ \\ ",
    " | |  __  ",
    " | | |_ | ",
    " | |___| |",
    " \\_____/  ",
    "          "
};

const char* letterH[] = {
    "  _    _  ",
    " | |  | | ",
    " | |__| | ",
    " |  __  | ",
    " | |  | | ",
    " |_|  |_| ",
    "          "
};

const char* letterI[] = {
    "   ____   ",
    "  |_  _|  ",
    "    ||    ",
    "    ||    ",
    "  __||__  ",
    " |_____|  ",
    "          "
};

const char* letterJ[] = {
    "      ___ ",
    "     |_  |",
    "       | |",
    "       | |",
    "  /\\   | |",
    "  \\_\\__/ /",
    "      |_| "
};

const char* letterK[] = {
    "  _   __  ",
    " | | / /  ",
    " | |/ /   ",
    " |   <    ",
    " | |\\ \\   ",
    " |_| \\_\\  ",
    "          "
};

const char* letterL[] = {
    "  _       ",
    " | |      ",
    " | |      ",
    " | |      ",
    " | |____  ",
    " |______| ",
    "          "
};

const char* letterM[] = {
    "  __    __  ",
    " |  \\  /  | ",
    " |   \\/   | ",
    " | |\\  /| | ",
    " | | \\/ | | ",
    " |_|    |_| ",
    "            "
};

const char* letterN[] = {
    "  _    _  ",
    " | \\  | | ",
    " |  \\ | | ",
    " |   \\| | ",
    " | |\\   | ",
    " |_| \\__| ",
    "          "
};

const char* letterO[] = {
    "   ____   ",
    "  / __ \\  ",
    " | |  | | ",
    " | |  | | ",
    " | |__| | ",
    "  \\____/  ",
    "          "
};

const char* letterP[] = {
    "  _____   ",
    " |  __ \\  ",
    " | |__) | ",
    " |  ___/  ",
    " | |      ",
    " |_|      ",
    "          "
};

const char* letterQ[] = {
    "   ____   ",
    "  / __ \\  ",
    " | |  | | ",
    " | |  | | ",
    " | |__| | ",
    "  \\_\\__\\_\\",
    "          "
};

const char* letterR[] = {
    "  _____   ",
    " |  __ \\  ",
    " | |__) | ",
    " |  _  /  ",
    " | | \\ \\  ",
    " |_|  \\_\\ ",
    "          "
};

const char* letterS[] = {
    "   _____  ",
    "  / ___ | ",
    " | (___   ",
    "  \\___ \\  ",
    "  ____| | ",
    " |_____/  ",
    "          "
};

const char* letterT[] = {
    "  _______  ",
    " |__   __| ",
    "    | |    ",
    "    | |    ",
    "    | |    ",
    "    |_|    ",
    "           "
};

const char* letterU[] = {
    " _     _  ",
    "| |   | | ",
    "| |   | | ",
    "| |   | | ",
    "| |___| | ",
    " \\_____/  ",
    "          "
};

const char* letterV[] = {
    "  _       _ ",
    " \\ \\     / /",
    "  \\ \\   / / ",
    "   \\ \\_/ /  ",
    "    \\   /   ",
    "     \\_/    ",
    "            "
};

const char* letterW[] = {
    " _        _  ",
    " \\ \\  /\\  / /",
    "  \\ \\/  \\/ / ",
    "   \\  /\\  /  ",
    "    \\    /   ",
    "     \\__/    ",
    "             "
};

const char* letterX[] = {
    "  _    _  ",
    "  \\ \\ / / ",
    "   \\ V /  ",
    "    > <   ",
    "   / . \\  ",
    "  /_/ \\_\\ ",
    "          "
};

const char* letterY[] = {
    " _     _  ",
    " \\ \\   / /",
    "  \\ \\_/ / ",
    "   \\   /  ",
    "    | |   ",
    "    |_|   ",
    "          "
};

const char* letterZ[] = {
    "  _______ ",
    " |_   __ \\",
    "   | |__) |",
    "   |  __ / ",
    "  _| |  \\ \\",
    " |_____|  \\",
    "           "
};

std::map<char, const char**> letterMap = {
    {'A', letterA},
    {'B', letterB},
    {'C', letterC},
    {'D', letterD},
    {'E', letterE},
    {'F', letterF},
    {'G', letterG},
    {'H', letterH},
    {'I', letterI},
    {'J', letterJ},
    {'K', letterK},
    {'L', letterL},
    {'M', letterM},
    {'N', letterN},
    {'O', letterO},
    {'P', letterP},
    {'Q', letterQ},
    {'R', letterR},
    {'S', letterS},
    {'T', letterT},
    {'U', letterU},
    {'V', letterV},
    {'W', letterW},
    {'X', letterX},
    {'Y', letterY},
    {'Z', letterZ}
};

// Funkcja do łączenia liter ASCII art w poziomie
std::string combineLetters(const std::vector<const char**>& letters, int letterHeight) {
    std::string combinedText;

    // Dla każdej linii (przy założeniu, że każda litera ma taką samą liczbę linii)
    for (int i = 0; i < letterHeight; ++i) {
        for (size_t j = 0; j < letters.size(); ++j) {
            combinedText += letters[j][i];  // Pobieramy linię z odpowiedniej litery
            combinedText += "  ";           // Dodajemy odstęp między literami
        }
        combinedText += "\n";               // Przechodzimy do nowej linii po każdej iteracji
    }

    return combinedText;
}

// Funkcja do zapisu tekstu do pliku
void saveToFile(const std::string& text, const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << text;
        outFile.close();
    } else {
        std::cerr << "Nie można otworzyć pliku!" << std::endl;
    }
}

int main() {
    // Wysokość każdej litery (7 wierszy)
    int letterHeight = 7;

    // Odczytaj tekst od użytkownika
    std::string inputText;
    std::cout << "Podaj tekst: ";
    std::getline(std::cin, inputText);

    // Zmieniamy na wielkie litery
    std::vector<const char**> letters;
    for (char c : inputText) {
        c = toupper(c);  // Zamieniamy na wielkie litery
        if (letterMap.find(c) != letterMap.end()) {
            letters.push_back(letterMap[c]);  // Dodajemy odpowiednią literę do wektora
        }
    }

    // Połączenie liter ASCII art
    std::string result = combineLetters(letters, letterHeight);


    // Wyświetlenie napisu w konsoli
    std::cout << result << std::endl;

    // Zapis napisu do pliku
    saveToFile(result, "ascii_art.txt");

    return 0;
}

