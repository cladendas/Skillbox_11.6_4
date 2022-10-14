#include <iostream>

//проверка соответствия победителя и кол-ва символов
char checkWinCountSym(char wonChar, int countX, int countO) {
    if (wonChar == 'X' && countX > countO) {
        return wonChar;
    } else if (wonChar == 'O' && countX == countO) {
        return wonChar;
    } else if (wonChar == 'I' || (wonChar == 'X' && countX == countO) || (wonChar == 'O' && countX != countO)) {
        wonChar = 'I';
        return wonChar;
    }
}

//сравнение символов: вернёт победителя
char compare(char symF, char symS, char symT) {
    char wonChar = 'N';
    if (symF == 'X' && symS == 'X' && symT == 'X') {
        wonChar = 'X';
    } else if (symF == 'O' && symS == 'O' && symT == 'O') {
        wonChar = 'O';
    }
    return wonChar;
}

//подсчёт кол-ва симоволов в строке
int countSym(std::string str, char sym) {
    int count = 0;
    for (int i : str) {
        if (i == sym) {
            count++;
        }
    }
    return count;
}

//проверка на кол-во побед в игре и определение победителя
char checkWin(int countX, int countO) {
    char wonChar = 'N';
    if (countX > 1 || countO > 1 || ((countX == countO) && countX == 1)) {
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
    int countXWin = 0;
    //кол-во побед О
    int countOWin = 0;
    //кол-во Х
    int countX = countSym(str, 'X');
    //кол-во О
    int countO = countSym(str, 'O');

    for (int i = 0; i <= 2; i += 2) {
        if (i == 0) {
            char tmp = compare(str[i], str[i + 4], str[i + 8]);
            if (tmp == 'X') {
                countXWin++;
            } else if (tmp == 'O') {
                countOWin++;
            }
        }
        if (i == 2) {
            char tmp = compare(str[i], str[i + 2], str[i + 4]);
            if (tmp == 'X') {
                countXWin++;
            } else if (tmp == 'O') {
                countOWin++;
            }
        }
    }
    wonChar = checkWin (countXWin, countOWin);
    return checkWinCountSym(wonChar, countX, countO);;
}

//проверка столбцов на победителя
char checkWonCol(std::string str) {
    char wonChar;
    //кол-во побед Х
    int countXWin = 0;
    //кол-во побед О
    int countOWin = 0;
    //кол-во Х
    int countX = countSym(str, 'X');
    //кол-во О
    int countO = countSym(str, 'O');
    for (int i = 0; i < 3; i++) {
        char tmp = compare(str[i], str[i + 3], str[i + 6]);
        if (tmp == 'X') {
            countXWin++;
        } else if (tmp == 'O') {
            countOWin++;
        }
    }
    wonChar = checkWin (countXWin, countOWin);
    return checkWinCountSym(wonChar, countX, countO);
}

//проверка строки на победителя
char checkWonStr(std::string str) {
    char wonChar;
    //кол-во побед Х
    int countXWin = 0;
    //кол-во побед О
    int countOWin = 0;
    //кол-во Х
    int countX = countSym(str, 'X');
    //кол-во О
    int countO = countSym(str, 'O');
    for (int i = 0; i <= 6 ; i += 3) {
        char tmp = compare(str[i], str[i + 4], str[i + 8]);
        if (tmp == 'X') {
            countX++;
        } else if (tmp == 'O') {
            countO++;
        }
    }
    wonChar = checkWin (countXWin, countOWin);
    return checkWinCountSym(wonChar, countX, countO);
}

//проверка строки на общие требования
bool checkStringTotal(std::string str) {
    //кол-во Х
    int countX = countSym(str, 'X');
    //кол-во О
    int countO = countSym(str, 'O');
    if (str.length() != 9 || countX < countO) { //не более 9 символов, кол-во Х должно быть больше или равно кол-ву О
        return false;
    } else {
        for (char i : str) { //сравниваем введённые символы с допустимыми символами
            if (i != 'X' && i != 'O' && i != '.') {
                return false;
            }
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
        if (checkWonStrings == 'I' || checkWonColumns == 'I' || checkDiagWon == 'I') {
            std::cout << "Incorrect\n";
        } else if (checkWonStrings == 'X' || checkWonColumns == 'X' || checkDiagWon == 'X') {
            std::cout << "Petya\n";
        } else if (checkWonStrings == 'O' || checkWonColumns == 'O' || checkDiagWon == 'O') {
            std::cout << "Vanya\n";
        } else {
            std::cout << "Nobody\n";
        }
    } else {
        std::cout << "Incorrect\n";
    }
}

//проверка всех примеров их задачи
void checkAll() {
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
    std::cout << "*** Хотя бы одна победа для Вани)\n";
    checkTotal("O.X",
               "XOX",
               "..O");
}

int main() {
    std::string fStr, sStr, tStr;
//    std::cout << "Enter result of game:" << std::endl;
//    std::cin >> fStr >> sStr >> tStr;

    //проверка всех примеров из задачи
    checkAll();
    return 0;
}