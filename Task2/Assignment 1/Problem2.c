#include<stdio.h>

int main(){
    int hexNum = 0x123;
    int *ptr = &hexNum;

    printf("1 --> %x\n2 --> %x\n3 --> %x\n", *ptr++, *++ptr, ++*ptr);
    printf("In the first it ncrements the pointer ptr, not the value it points to. but because of the postfix ++ operator,"
    " the increment happens after the current statement. So, it should print the value pointed by ptr (which is 0x123), and then increments the pointer."
    " But due to the order of evaluation in printf, it might print a random value instead. "
    "int the second one it increments the pointer ptr first, and then dereferences it. Since ptr was incremented in the previous statement,"
    " this will now point to some random memory location, leading to undefined behavior. So, it will print a random value."
    "in the third it increments the value that the pointer ptr points to which is hexNum,"
    " Since ptr was not incremented in the second statement (due to undefined behavior) so it incremented to be 124.");

    return 0;
}