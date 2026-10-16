#include "tree.h"

int main() {
    setlocale(LC_ALL, "ru");

    string line;
    cout << "Введите строку: ";
    getline(cin, line);
    tree t;
    for (unsigned char ch : line) {
        if (isalpha(ch)) {
            char lower = tolower(ch);
            t.insert(lower); 
        }
    }
    if (t.empty()) cout << "В строке не найдено букв." << endl;
    t.print();
    char tar = tolower(cin.get());
    if (t.contains(tar))
        cout << "Символ '" << tar << "' найден в дереве." << endl;
    else
        cout << "Символ '" << tar << "' НЕ найден в дереве." << endl;
    char a = t.min();
    cout << a;
    int b = t.count();
    cout << b;
}