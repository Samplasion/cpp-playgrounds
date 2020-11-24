#include <iostream>
#include <string>
#include <cmath>
#include <iterator>
#include <map>
#include <sstream>

using namespace std;

const map<string, string> DELIMITERS = {
        {"H", "━"},
        {"V", "┃"},
        {"TL", "┏"},
        {"TR", "┓"},
        {"BL", "┗"},
        {"BR", "┛"},
};

string repeat(string s, int n) {
    ostringstream os;
    for(int i = 0; i < n; i++)
        os << s;
    return os.str();
}

string boxHeader(string header[], int size) {
    string output = "";

    size_t width = 0,
           height = size + 2;

    for (int i = 0; i < size; i++)
        if (header[i].size() > width)
            width = header[i].size() + 4;

    output += DELIMITERS.at("TL") + repeat(DELIMITERS.at("H"), width - 2) + DELIMITERS.at("TR") + "\n";

    for (int index = 0; index < size; index++) {
        size_t s = header[index].size();
        int spacesBefore = floor(((double)width - 2.0 - (double)s) / 2.0),
            spacesAfter  =  ceil(((double)width - 2.0 - (double)s) / 2.0);
        output += DELIMITERS.at("V") +
                repeat(" ", spacesBefore) +
                header[index] +
                repeat(" ", spacesAfter) +
                DELIMITERS.at("V") +
                "\n";
    }

    output += DELIMITERS.at("BL") + repeat(DELIMITERS.at("H"), width - 2) + DELIMITERS.at("BR") + "\n";

    return output;
}

int main() {
    string header[] = {
            "Welcome",
            "This is the string header generator."
    };
    string boxed = boxHeader(header, size(header));
    cout << boxed;
    return 0;
}