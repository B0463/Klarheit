/* MenuMgr */
#pragma once

class Fs {
    /* Required Packs */
private:
    /* Private */
    /* Functions */
public:
    /* Public */
    /* Functions */
    string ReadFile(string filePath) {
        #ifdef DEBUG
            cout << "[Debug]: Fs.hpp\\ReadFile: filePath: " << filePath << "\n";
        #endif
        string line;
        fstream file;
        string result;
        file.open(filePath, fstream::in);
        if(file.is_open()) {
            while(!file.eof()) {
                getline(file, line);
                result = result + line + "\n";
            }
            file.close();
            if (!result.empty()) {
                result.pop_back();
            }
            return result;
        } else {
            #ifdef DEBUG
                cout << "[Debug]: Fs.hpp\\ReadFile: can't open file\n";
            #endif
            cout << "[ERROR]: can't load file \"" << filePath << "\"\n";
            abort();
        }
    }
    string WriteFile(string filePath) {
        #ifdef DEBUG
            cout << "[Debug]: Fs.hpp\\WriteFile: filePath: " << filePath << "\n";
        #endif
        string line;
        fstream file;
        string result;
        file.open(filePath, fstream::out);
        if(file.is_open()) {
            while(!file.eof()) {
                getline(file, line);
                result = result + line + "\n";
            }
            file.close();
            if (!result.empty()) {
                result.pop_back();
            }
            return result;
        } else {
            #ifdef DEBUG
                cout << "[Debug]: Fs.hpp\\ReadFile: can't open file\n";
            #endif
            cout << "[ERROR]: can't load file \"" << filePath << "\"\n";
            abort();
        }
    }
};
