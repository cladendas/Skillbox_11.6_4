#include <iostream>

//сравнение символов
bool compare(char valid, char sym) {
    return valid == sym;
}

//проверка диагонали на победителя
std::string checkDiag(std::string str) {
    std::string win = "";

    for (int i = 0; i <= 2; i += 2) {
        if (compare('X', str[i])
            && compare('X', str[i + 4])
            && compare('X', str[i + 8])) {

            win = "Petya";
        } else if (compare('O', str[i])
                   && compare('O', str[i + 4])
                   && compare('O', str[i + 8])) {

            win = "Vanya";
        }
    }
    return win;
}

//проверка столбцов на победителя
std::string checkWonCol(std::string str) {
    std::string win = "";
    for (int i = 0; i < 3; i++) {
        if (compare('X', str[i])
            && compare('X', str[i + 3])
            && compare('X', str[i + 6])) {

            win = "Petya";
        } else if (compare('O', str[i])
                   && compare('O', str[i + 3])
                   && compare('O', str[i + 6])) {

            win = "Vanya";
        }
    }
    return win;
}

//проверка строки на победителя
std::string checkWonStr(std::string str) {
    std::string win = "";
    for (int i = 0; i <= 6 ; i += 3) {
        if (compare('X', str[i])
            && compare('X', str[i + 1])
            && compare('X', str[i + 2])) {

            win = "Petya";
        } else if (compare('O', str[i])
                   && compare('O', str[i + 1])
                   && compare('O', str[i + 2])) {

            win = "Vanya";
        }
    }
    return win;
}

//проверка строки на общие требования
bool checkStringTotal(std::string str) {
    if (str.length() != 3) {
        return false;
    } else {
        for (int i = 0; i < str.length(); i++) {
            if (compare('X', str[i])
                || compare('O', str[i])
                || compare('.', str[i])) {
                    return false;
            } else {
                    return true;
            }
        }
    }
}

void checkTotal(std::string fStr, std::string sStr, std::string tStr) {

    std::string totalStr = fStr + sStr + tStr;

    //проверка первой строки на общие требования
    bool checkStringTotalF = checkStringTotal(totalStr);

    //получение победителя по строкам
    std::string checkWonStrings = checkWonStr(totalStr);

    //получение победителя по столбцам
    std::string checkWonColumns = checkWonCol(totalStr);

    //получение победителя по диагоналям
    std::string checkDiagWon = checkDiag(totalStr);


    if () {


        std::cout << "Incorrect";
    } else if () {
        std::cout << "Vanya won";
    } else if () {

        std::cout << "Petya won";
    } else if () {
        std::cout << "Nobody";
    }
}

void checkAll() {

}

int main() {
    std::string fStr, sStr, tStr;
    std::cout << "Enter result of game:" << std::endl;
    std::cin >> fStr >> sStr >> tStr;

    return 0;
}