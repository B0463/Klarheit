/* Program */
#pragma once

class Program {
    /* Required Packs */
    MenuMgr OMenuMgr;
private:
    /* Private */
    /* Functions */
    
public:
    /* Public */
    /* Functions */
    int Main(void) {
        return OMenuMgr.CreateMenu("MainMenu");
    }
};