#include <iostream>

//сравнение символов
char compare(char symF, char symS, char symT) {
    char wonChar = 'N';
    if (symF == 'X' && symS == 'X' && symT == 'X') {
        wonChar = 'X';
    } else if (symF == 'O' && symS == 'O' && symT == 'O') {
        wonChar = 'O';
    }
    return wonChar;
}

//проверка на кол-во побед в игре и определение победителя
char checkWin(int countX, int countO) {
    char wonChar = 'N';
    if (countX > 1 || countO > 1 || ((countX == countO) && countX != 0)) {
        wonChar = 'I';
    } else if (countX == 1) {
        wonChar = 'X';
    } else if (countO == 1) {
        wonChar = 'O';
    }
    return wonChar;
}

//проверка диагонали на победителя
char checkDiag(std::string str) {
    char wonChar;
    //кол-во побед Х
    int countX = 0;
    //кол-во побед О
    int countO = 0;

    for (int i = 0; i <= 2; i += 2) {
        if (i == 0) {
            char tmp = compare(str[i], str[i + 4], str[i + 8]);
            if (tmp == 'X') {
                countX++;
            } else if (tmp == 'O') {
                countO++;
            }
        }
        if (i == 2) {
            char tmp = compare(str[i], str[i + 2], str[i + 4]);
            if (tmp == 'X') {
                countX++;
            } else if (tmp == 'O') {
                countO++;
            }
        }
    }
    wonChar = checkWin (countX, countO);
    return wonChar;
}

//проверка столбцов на победителя
char checkWonCol(std::string str) {
    char wonChar;
    //кол-во побед Х
    int countX = 0;
    //кол-во побед О
    int countO = 0;
    for (int i = 0; i < 3; i++) {
        char tmp = compare(str[i], str[i + 4], str[i + 8]);
        if (tmp == 'X') {
            countX++;
        } else if (tmp == 'O') {
            countO++;
        }
    }
    wonChar = checkWin (countX, countO);
    return wonChar;
}

//проверка строки на победителя
char checkWonStr(std::string str) {
    char wonChar;
    //кол-во побед Х
    int countX = 0;
    //кол-во побед О
    int countO = 0;
    for (int i = 0; i <= 6 ; i += 3) {
        char tmp = compare(str[i], str[i + 4], str[i + 8]);
        if (tmp == 'X') {
            countX++;
        } else if (tmp == 'O') {
            countO++;
        }
    }
    wonChar = checkWin (countX, countO);
    return wonChar;
}

//проверка строки на общие требования
bool checkStringTotal(std::string str) {
    //кол-во Х
    int countX = 0;
    //кол-во О
    int countO = 0;
    if (str.length() != 9) {
        return false;
    } else {
        for (char i : str) { //сравниваем введённые символы с допустимыми символами
            if (i == 'X') {
                countX++;
            } else if (i == 'O') {
                countO++;
            } else if (i != '.') {
                return false;
            }
        }

        if (countX < countO) { //кол-во Х должно быть больше или равно кол-ву О
            return false;
        }
        return true;
    }
}

void checkTotal(std::string fStr, std::string sStr, std::string tStr) {

    std::string totalStr = fStr + sStr + tStr;

    //проверка строк на общие требования
    bool checkStrTotal = checkStringTotal(totalStr);

    //получение победителя по строкам
    char checkWonStrings = checkWonStr(totalStr);

    //получение победителя по столбцам
    char checkWonColumns = checkWonCol(totalStr);

    //получение победителя по диагоналям
    char checkDiagWon = checkDiag(totalStr);


    if (checkStrTotal) {
        if (checkWonStrings == 'X' || checkWonColumns == 'X' || checkDiagWon == 'X') {
            std::cout << "Petya\n";
        } else if (checkWonStrings == 'O' || checkWonColumns == 'O' || checkDiagWon == 'O') {
            std::cout << "Vanya\n";
        } else if (checkWonStrings == 'N' || checkWonColumns == 'N' || checkDiagWon == 'N') {
            std::cout << "Nobody\n";
        }
    } else {
        std::cout << "Incorrect\n";
    }
}

int main() {
    std::string fStr, sStr, tStr;
//    std::cout << "Enter result of game:" << std::endl;
//    std::cin >> fStr >> sStr >> tStr;

    checkTotal("X..",
               "OXO",
               "OOO");
    checkTotal("X..",
               ".X.",
               "OO.");
    checkTotal("XXO",
               "OOX",
               "XOX");
    checkTotal("XO.",
               "XO.",
               "X.O");
    checkTotal("OX.",
               "XOX",
               "X.O");
    checkTotal("..X",
               "OX.",
               "X.O");
    checkTotal("0..",
               "...",
               "...");

    return 0;
}