/* MenuMgr */
#pragma once

class MenuMgr {
    /* Required Packs */
    Fs OFs;
    ConfigMgr OConfigMgr;
private:
    /* Private */
    /* Functions */
    int PrintMenu(string menu) {
        cout << OFs.ReadFile("../assets/en/menus/"+menu+".assets");
        return 0;
    }
    string GetChoice() {
        string choice;
        cout << OFs.ReadFile("../assets/en/choicePointers/main.assets");
        getline(cin, choice);
        return choice;
    }
    void ClearConsole(void) {
        #ifndef DISABLE_CONSOLECLEAR
            #if defined(_WIN32) || defined(_WIN64)
                system("cls");
            #else
                system("clear");
            #endif
        #else
            #ifdef DEBUG
                cout << "[Debug]: MenuMgr.hpp\\ClearConsole: emule clear\n";
            #endif
        #endif
    }
public:
    /* Public */
    /* Functions */
    int CreateMenu(string menu) {
        bool continueProgram = true;
        while(continueProgram) {
            ClearConsole();
            #ifdef DEBUG
                cout << "[Debug]: MenuMgr.hpp\\CreateMenu: menu: " << menu << "\n";
            #endif
            PrintMenu(menu);
            string choice = GetChoice();
            #ifdef DEBUG
                cout << "[Debug]: MenuMgr.hpp\\CreateMenu: choice: " << choice << "\n";
            #endif

            if(menu == "MainMenu") {
                #ifdef DEBUG
                    cout << "[Debug]: MenuMgr.hpp\\CreateMenu: MainMenu selected\n";
                #endif
                switch(stoi(choice)) {
                    case 0: continueProgram = false;continue;
                    case 1: CreateMenu("StartNewGame");continue;
                    case 2: CreateMenu("ContinueGame");continue;
                    case 3: CreateMenu("Options");continue;
                    case 4: CreateMenu("Help");continue;
                    case 5: CreateMenu("Author");continue;
                    default: return -1;
                }
            }
            if(menu == "Options") {
                #ifdef DEBUG
                    cout << "[Debug]: MenuMgr.hpp\\CreateMenu: Options selected\n";
                #endif
                switch (stoi(choice)) {
                    case 0: continueProgram = false;continue;
                    case 1: /*OOptionsMgr.SwithDarkMode()*/
                    case 2: CreateMenu("LanguageMenu");continue;
                    default: return -1;
                }
            }
            if(menu == "Help") {
                #ifdef DEBUG
                    cout << "[Debug]: MenuMgr.hpp\\CreateMenu: Help selected\n";
                #endif
                if(choice == "0") {continueProgram = false;continue;}
                else return -1;
            }
            else return -1;
        }
        return 0;
    }
};
