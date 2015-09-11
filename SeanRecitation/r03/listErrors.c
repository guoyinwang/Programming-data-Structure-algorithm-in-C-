//This problem taken from All of Programming exercise 8.8

//For each line that has an error, comment what it is
//and what could be done to fix it.

int f(int a, int* b, int* c){
    a = &b;
    &b = &c;
    *b = a;
    &c = b;
    c = a;
    return b;
    }



