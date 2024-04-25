// Warframes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Warframes.h"

Warframes::~Warframes() {
    closefile();
};

Warframes::Warframes() {
    if (warframefile.is_open()) {
        cout << "it's open";
        //warframefile.close();
    }
    openfile(wfile);
}

vector<string> Warframes::getstring(int position) {
    Warframes _Warframes;
    string line;
    warframefile.seekg(position, ios::beg);
    warframefile.seekp(position, ios::beg);
    vector<string> lines;
    getline(warframefile, line);
    do {
        lines.push_back(line);
    } while (getline(warframefile, line));
    if (warframefile.bad()) {
        //warframefile.close();
        exit(121);
    }
    return lines;
}

void Warframes::closefile() {
    if (!warframefile.is_open()) {
        cout << "no file to close \n";
        return;
    }
    else {
        ////warframefile.close();
        return;
    }
}

void Warframes::openfile(string filename) {
    if (!warframefile.is_open()) {
        warframefile.open(filename);
    }
    
    if (!warframefile.is_open()) {
        cout << "why";
        exit(404);
    }
        warframefile.seekg(1, ios::beg);
        warframefile.seekp(1, ios::beg);
    return;
}

void Warframes::add(char* name[]) {
    Warframes _Warframes;
    if (!warframefile.is_open()) {
        exit(001);
    }

    string line;
    int count = 0;
    warframefile.seekg(1, ios::beg);
    warframefile.seekp(1, ios::beg);
    getline(warframefile, line);
    while (line != "Listed end:") {
        getline(warframefile, line);
        count++;
        if (count > 5000) {
            exit(204);
        }
    }
    warframefile.seekp(-13, ios::cur);
    warframefile.write("             ", 13);
    warframefile.seekp(-13, ios::cur);
    for (int i = 2; name[i] != nullptr; i++) {
        int j = 0;
        while ((name)[i][j] != NULL) {
            char* pont = &(name)[i][j];
            warframefile.write(pont, 1);
            j++;
        }
        warframefile.write("\n", 1);
    }
    warframefile.write("Listed end:\n", 13);

    if (warframefile.bad()) {
        //warframefile.close();
        exit(120);
    }
    //warframefile.close();
    cout << count << "\n";
    vector<string> print = _Warframes.getstring(0);
    for (auto& a : print) {
        cout << a << "\n";
    }
}

void Warframes::remove(char* name[]) {
    Warframes _Warframes;
    string _name = (string)name[2];

    vector<string> search = _Warframes.getstring(0);
    _Warframes.closefile();
    ofstream replace(wfile, ios::trunc);
    if (!replace.is_open()) {
        cout << "failed to open trunc";
        exit(404);
    }

    int i = 0;
    cout << sizeof(search);
    for (auto& a : search) {
        if ((string)a != _name) {
            replace << a << "\n";
            cout << "writing";
        }
        i++;
        cout << "not writing";
    }
    if (replace.bad()) {
        cout << "trunc is bad";
        exit(121);
    }

}

void Warframes::see() {
    Warframes _Warframes;
    vector<string> print = _Warframes.getstring(0);
    for (auto& a : print) {
        cout << a << "\n";
    }
}

int main(int argc, char* argv[])
{
    //Sleep(5000);
    string line;
    bool ran = false;
    int first = 0;
    Warframes _Warframes;
    

    for (int i = 0; (*argv)[i] != '\0'; i++) {
        first++;
    }



    switch ((*argv)[1 + first]) {
    case ('-'):
        switch ((*argv)[2 + first]) {
        case ('a'):
            _Warframes.add(argv);
            ran = true;
            break;
            
        case('r'):
            _Warframes.remove(argv);
            break;

        case('s'):
            _Warframes.see();
            break;
        }
        break;
    default:
        break;
        }

    _Warframes.closefile();
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
