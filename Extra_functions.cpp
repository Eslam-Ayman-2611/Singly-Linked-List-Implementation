#include"Header.h"

void clear_Terminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void typeText(const string& text) {
    for (char ch : text) 
    {
        cout << ch << flush;
        this_thread::sleep_for(chrono::milliseconds(DELAY_MS));
    }
}

void typeCText(const string& text, const string& color) {
    cout << color;
    for (char ch : text) {
        cout << ch << flush;
        this_thread::sleep_for(chrono::milliseconds(20));
    }
    cout << RESET;
}
void Continue(void)
{
    out = 0 ;
    while (out!=1)
              {
                typeText("press 1 to continue... \n");
                cin>>out;
              }
          clear_Terminal();
}
