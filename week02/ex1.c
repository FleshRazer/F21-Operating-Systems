#include <stdio.h>
#include <limits.h>
#include <float.h>


int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;
    
    printf("   int max value: %d\n", a);
    printf(" float max value: %f\n", b);
    printf("double max value: %f\n", c);
    printf("\n");
    
    printf("   int size in bytes: %ld\n", sizeof a);
    printf(" float size in bytes: %ld\n", sizeof b);
    printf("double size in bytes: %ld\n", sizeof c);
        
    return 0;
}
