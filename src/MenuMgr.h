/* MenuMgr */
#pragma once

class MenuMgr {
    /* Required Packs */
private:
    /* Private */
    /* Functions */
    
public:
    /* Public */
    /* Functions */
    int PrintMainMenu(void) {
        string line;
        fstream arq;
        arq.open("../assets/en/menus/MainMenu.assets", fstream::in);
        if(arq.is_open()) {
            while(! arq.eof() ) {
                getline (arq, line);
                cout << line << "\n";
            }
            arq.close();
            return 0;
        } else {
            cout << "[ERROR]: assets file en/menus/MainMenu.assets not found or not accessible\n";
            return -1;
        }
    }
    int PrintOptionsMenu(void) {
        string line;
        fstream arq;
        arq.open("../assets/en/menus/Options.assets", fstream::in);
        if(arq.is_open()) {
            while(! arq.eof() ) {
                getline (arq, line);
                cout << line << "\n";
            }
            arq.close();
            return 0;
        } else {
            cout << "[ERROR]: assets file en/menus/Options.assets not found or not accessible\n";
            return -1;
        }
    }
    int PrintHelpMenu(void) {
        string line;
        fstream arq;
        arq.open("../assets/en/menus/Help.assets", fstream::in);
        if(arq.is_open()) {
            while(! arq.eof() ) {
                getline (arq, line);
                cout << line << "\n";
            }
            arq.close();
            return 0;
        } else {
            cout << "[ERROR]: assets file en/menus/Help.assets not found or not accessible\n";
            return -1;
        }
    }
};