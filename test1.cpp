#define _CRT_SECURE_NO_WARNINGS 
#include "Queue.h"
extern const char* TestQueue(int& s);

void test01()
{
    char s[20] = { 0 };
    s[0] = '\0';
    
    
    Queue* p = (Queue*)malloc(sizeof(Queue));
    initQueue(p, 10);
    enter(p, (int)'A');
    enter(p, (int)'B');
    enter(p, (int)'C');
    enter(p, (int)'D');
    enter(p, (int)'E');
    enter(p, (int)'F');
    int e = 0;
    int& pe = e;
    leave(p, pe);
    enter(p, (int)'A');

    print(p, s);
    puts(s);



}
int main(void)
{
    //≥ı ºªØQueue

    //test01();
    int s = 0;
    const char* e = TestQueue(s);
    printf("%s", e);

    return 0;
}