#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const char* jed[] { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                    "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
                  };
const char* des[] { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

const char* sto = "hundredand";
const char* hil = "onethousand";

int main() {
    freopen("main.out", "w", stdout);

    int len = strlen(hil);

    for (int idx = 1; idx < 1000; idx ++) {
        int curLen = 0;
        int stotine, desetice, jedinice;
        stotine = idx / 100;
        desetice = (idx % 100) / 10;
        jedinice = idx % 10;
        cout << stotine << " " << desetice << " " << jedinice << " ";
        if (stotine > 0) {
            curLen += strlen(sto) + strlen(jed[stotine]);
            if (desetice == 0 && jedinice == 0)
                curLen -= 3;
        }
        if ( desetice != 1) {
            curLen += strlen(des[desetice]);
            curLen += strlen(jed[jedinice]);
        }
        else {
            curLen += strlen(jed[idx % 100]);
        }
        cout << "Duz" << curLen << endl;;
        len += curLen;
    }
    cout << len;
    return 0;
}
