/* MenuMgr */
#pragma once

class MenuMgr {
    /* Required Packs */
    Fs OFs;
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
                    cout << "[Debug]: MenuMgr.hpp\\CreatemMenu: MainMenu selected\n";
                #endif
                if(choice == "0") {continueProgram = false;continue;}
                if(choice == "1") {CreateMenu("StartNewGame");continue;}
                if(choice == "2") {CreateMenu("ContinueGame");continue;}
                if(choice == "3") {CreateMenu("Options");continue;}
                if(choice == "4") {CreateMenu("Help");continue;}
                else return -1;
            }
            if(menu == "Options") {
                #ifdef DEBUG
                    cout << "[Debug]: MenuMgr.hpp\\CreatemMenu: Options selected\n";
                #endif
                if(choice == "0") {continueProgram = false;continue;}
                if(choice == "1") /*OOptionsMgr.SwithDarkMode()*/
                if(choice == "2") {CreateMenu("LanguageMenu");continue;}
                else return -1;
            }
            if(menu == "Help") {
                #ifdef DEBUG
                    cout << "[Debug]: MenuMgr.hpp\\CreatemMenu: Help selected\n";
                #endif
                if(choice == "0") {continueProgram = false;continue;}
                else return -1;
            }
            else return -1;
        }
        return 0;
    }
};
