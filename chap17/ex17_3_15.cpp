/*
3. Write a function, void to_lower(char* s), that replaces all uppercase
 characters in the C-style string s with their lowercase equivalents. For
 example, Hello, World! becomes hello, world!. Do not use any standard library
 functions. A C-style string is a zero-terminated array of characters, so if
 you find a char with the value 0 you are at the end.
4. Write a function, char* strdup(const char*), that copies a C-style string
 into memory it allocates on the free store. Do not use any standard library
 functions.
5. Write a function, char* findx(const char* s, const char* x), that finds the
 first occurrence of the C-style string x in s.
*/

#include <iostream>

using namespace std;

/*Ex17.3*/
void to_lower(char* s) {
    char *p = s;
    while(*p != '\0'){
        // if ('A' <= *p && *p <= 'Z')
        //     *p += 32;
        if(*p == 'A') *p = 'a';
        p++;
    }
}

int main(int argc, char const *argv[]) {
    char* s = "ABCD";
    to_lower(s);
    cout << s << endl;
    return 0;
}
