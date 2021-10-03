#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int nrows = 3;
    int ncols = 4;

    // Option 1
    int *mat = (int *) malloc(nrows*ncols*sizeof(int));
    for (int i=0; i<nrows*ncols; i++) {
        *(mat+i) = i;
    }
    printf("mat[1] = %d\n", mat[1]);
    //mat[1][2] //can't do this
    // Important conversion from 2d to 1d index
    printf("mat[1][2] = %d\n", *(mat+1*ncols + 2));

    // Option 2
    int **mat = (int **) malloc(nrows*size(int *));
    for (int i=0; i<nrows; i++) {
        *(mat+i) = (int *) malloc(ncols*sizeof(int));
    }


    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // 1D Array Recap
    int arr[7] = {1,2,3,4,5,6,7};
    // standard [] notation
    printf("arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);
    // pointer notation
    printf("arr = %p, *arr = %d, arr+1 = %p, *(arr+1) = %d\n", arr, *arr, arr+1, *(arr+1));

    // 2D array o
    int mat[3][4] = {{1,3,4,8},{10,9,7,2},{5,6,11,12}};

    printf("mat[2][3] = %d\n", mat[2][3]);

    int *pm;
    pm = &mat[0][0];
    printf("pm = %p, mat = %p, mat[0] = %p\n", pm, mat, mat[0]);
    printf("mat[1] = %p, &mat[1] = %p mat+1 = %p *(mat+i) = %p\n", mat[1], &mat[1], mat+1, *(mat+1));
    
    // pointer arithmetic to access columns
    printf("*(mat[2] + 3) = %d\n", *(mat[2]+3));
    printf("*(*(mat+2) + 3) = %d\n", *(*(mat+2)+3));
    
    // careful: not the same thing
    // kept advancing by rows
    printf("*((mat+2) +3) = %d\n", *((mat+2)+3)); 
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    float sum = 0;
    for (int i=1; i<argc; i++) {
        sum += atoi(argv[i]);
    }
    printf("%f\n", sum/(argc-1));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char *name;
    double *scores;
    int grad_year;
};

typedef union idc {
    int i;
    double d;
    char c;
} idc;

typedef enum type {INT, CHAR, DOUBLE} type;

typedef struct EU {
    type ty;
    idc var;
} EU;

typedef struct Student Stdnt;

typedef enum day_of_week {Mon, Tue, Wed, Thu, Fri, Sat, Sun, HumpDay=2} day_of_week;

int main(void) {
    enum day_of_week day = Wed;
    printf("%d\n", day);

    idc temp;
    temp.d = 15.3;
    idc temp2;
    temp2.i = 4;

    EU random;
    random.ty = INT;
    random.var.i = 15;

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

double sum(double, double);
void pointerfun(int *);

int main(void) {

    double d1 = 10.0;
    double d2 = 4.5;
    double tot = sum(d1,d2);
    printf("d1 = %f, d2 = %f, sum = %f\n", d1, d2, tot);

    int *p = (int *) malloc(sizeof(int));
    *p = 4;
    printf("p val before = %d\n", *p);
    printf("p before = %p\n", p);
    pointerfun(p);
    printf("p after = %p\n", p);
    printf("p val after = %d\n", *p);

    free(p);
    return 0;
}

double sum(double a, double b) {
    return a+b;
}

void pointerfun(int *p) {
    *p = *p * 2;
    printf("p val in fun = %d\n", *p);
    p = p+1;
    printf("p in fun= %p\n", p);
}
#include <stdio.h>

int main(void) {

    int arr1[10];
    int arr0[3] = {2,4,5};

    char arr2[4];
    char arr3[] = "hello";

    int i;

    for(i=0; i<10; i++) {
        arr1[i] = 0;
    }

    int num = 1;
    while (num < 300) {
        printf("num = %d\n", num);
        num *= 2;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int size = 10;
    int *arr1 = (int *) malloc(sizeof(int)*size);

    memset(arr1, 1, sizeof(int)*size);
    printf("%d\n", *arr1);

    char *s = (char *) malloc(sizeof(char)*2);
    char *s2 = (char *) malloc(sizeof(char)*27);

    // fills s2 with A-Z, null terminated
    for(int i=0; i<26; i++) {
        *(s2+i) = 65 + i;
    }
    *(s2+26) = '\0';
    printf("%s\n", s2);

    memcpy(s, s2, 2);
    printf("%c\n", *s);
    printf("%s\n", s2);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // don't have the right to memory it points to yet
    int *p;
    printf("p before malloc = %p\n", p);
    
    // malloc - asks for memory for single int
    p = (int *) malloc(sizeof(int));
    
    printf("p after malloc = %p\n", p);
    printf("value at p before setting = %d\n", *p);
    *p = 10; // changes value stored at emmory
    printf("value at p after setting = %d\n", *p);

    // malloc - asking for memory for many ints
    int *p3 = (int *) malloc(sizeof(int)*10);
    printf("p3 after malloc = %p\n", p3);

    // calloc - initialized to 0
    int *p2;
    p2 = (int *) calloc(100, sizeof(int));
    printf("p2 after calloc = %p\n", p2);
    printf("value at p2 before setting = %d\n", *p2);
    *p2 = 80;
    printf("value at p2 after setting = %d\n", *p2);

    char *pc;
    pc = (char *) malloc(20*sizeof(char));
    printf("pc after malloc = %p\n", pc);

    // realloc - try with 12 to see difference
    p3 = (int *) realloc(p3, sizeof(int)*1000);
    printf("p3 after realloc = %p\n", p3);

    // can't forget to free!
    free(p);
    free(p2);
    free(p3);
    free(pc);

    return 0;
}
#include <stdio.h>
#include <stdbool.h>
int main(void) {
    // Booleans
    bool b = true;
    bool b2 = 0;
    bool eq = (b==b2);
    printf("%d\n", eq);

    // Implicit type conversion
    int x = 70.0;
    double y = 1000.0/2;
    char c = 65;
    printf("x = %d, y = %f\n", x, y);
    printf("char = %c\n", c);
    printf("y casted to int = %d\n", (int)y);
    printf("x converted to char = %c\n", (char)x);

    // Operators
    x *= 2;
    printf("x = %d\n", x);

    // Conditionals
    if (x > y) {
        printf("x is greater\n");
    }
    else if (x < y) {
        printf("x is less\n");
    }
    else {
        printf("they are equal\n");
    }

    // Ternary operator
    double z = x>y ? x : y;
    printf("%f\n", z);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int arr[10]; // on the stack
    for (int i=0; i<10; i++) {
        arr[i] = i;
    }

    // array name is just pointer
    printf("&arr[0] = %p\n", &arr[0]);
    printf("arr = %p\n", arr);
    printf("arr+1 = %p\n", arr+1);

    // indexing vs pointer arithmetic notation
    arr[2] = 80;
    printf("arr[2] = %d\n", arr[2]);
    *(arr+2) = 90;
    printf("arr[2] = %d\n", arr[2]);

    int *p1 = (int *) malloc(sizeof(int)*7);
    int *p2 = (int *) malloc(sizeof(int)*7);

    *(p1+1) = 80;
    for (int i=0; i<7; i++) {
        p2[i] = i; //array access notation
        *(p1+i) = i; // pointer arithmetic notation
    }
    printf("*(p1+5) = %d\n", *(p1+5));
    printf("*(p2+5) = %d\n", *(p2+5));
    
    // walking off the end -- BAD, DON'T DO THIS!
    printf("p1 = %p\n", p1);
    printf("p2 = %p\n", p2);
    printf("p1+9 = %p\n", p1+9);
    *(p1+9) = 800;
    printf("*(p2+1) = %d\n", *(p2+1));
    printf("p2+1 = %p\n", p2+1);
    return 0;
}
#include <stdio.h>

int main(void) {
    /*
    int *iptr;
    char *cptr;
    float *fptr;
    */

    int a = 5;
    int b = 6;
    int c;
    int *iptr;
    int *jptr;

    //*jptr = 80; //this is bad!

    printf("iptr before initializing = %p\n", iptr);
    printf("jptr before initializing = %p\n", jptr);

    jptr = &a;
    iptr = &c;

    *iptr = 100;

    printf("iptr = %p\n", iptr);
    printf("value at iptr = %d\n", *iptr);
    printf("jptr = %p\n", jptr);
    printf("value at jptr = %d\n", *jptr);

    printf("address of b = %p\n", &b);
    printf("b = %d\n", b);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int tot;
    int a, b, c;


    // scanf - example of accepting input and outputting
    /*
    scanf("%d %d %d", &a, &b, &c);
    tot = a + b + c;
    printf("you entered: %d %d %d, total = %d\n", a, b, c, tot);
    */



    // scanf - loop
    /*
    int num;
    int sum = 0;
    int ret = EOF + 1;

    while (ret != EOF) {
        printf("current sum = %d\n", sum);
        ret = scanf("%d", &num);
        sum += num;
    }
    */

    // fgets
    /*
    int maxn = 10;
    char *p = (char *) malloc(sizeof(char)*maxn);

    p = fgets(p, maxn, stdin);
    if (p != NULL) {
        printf("you entered %s\n", p);
    }
    free(p);
    */

    


    // getline
    char *s;
    int nread;
    size_t maxn = 10;

    s = (char *) malloc(sizeof(char)*maxn);
    nread = getline(&s, &maxn, stdin);
    printf("you entered %d characters\n", nread);
    printf("you entered %s\n", s);

    free(s);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char s2[] = "hello darkness my old friend";

    char *s3 = (char *) malloc(sizeof(char)*10);

    int sn = 5;
    char *s = (char *) malloc(sizeof(char)*sn);
    *s = 'y';
    *(s+1) = 'o';
    *(s+2) = 'd';
    *(s+3) = 'a';
    *(s+4) = '\0';
    // bad - walks off end, demnonstrates issue with strlen
    /*
    *(s+4) = 'b';
    *(s+5) = 'a';
    *(s+6) = '\0';
    */

    printf("%s\n", s);

    //Unsafe
    /*
    strcpy(s3, s2);
    printf("%s\n", s3);
    printf("%s\n", s);
    */

    // Safe
    strncpy(s3, s2, 9);
    printf("%s\n", s3);
    printf("%s\n", s);

    int n = strlen(s);
    printf("%d\n", n);
    n = strnlen(s, sn);
    printf("%d\n", n);

    char *member = strchr(s2, 'l');
    printf("%p, %p\n", s2, member);


    return 0;
}
#include <stdio.h>
#include <stdlib.h>


// typical way
typedef struct Coord {
    double x;
    double y;
    int *list;
} Coord;


/*
// define coord struct
struct Coord {
    double x;
    double y;
};

// after the fact typedef
typedef struct Coord Coord;
*/

int main(void) {
    int a;
    Coord c;
    c.x = 10;
    c.y = 5;
    c.list = (int *) malloc(sizeof(int)*5);

    printf("(%f,%f)\n", c.x, c.y);
  
    Coord *cp;
    cp = (Coord *) malloc(sizeof(Coord));
    cp->x = 12;
    cp->y = 8;
    cp->list = (int *) malloc(sizeof(int)*5);
    //(*cp).x = 12;
    //(*cp).y = 8;

    printf("(%f,%f)\n", cp->x, cp->y);
    
    free(c.list);
    free(cp->list);
    free(cp);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char c = '+';
    int x = 4;

    printf("x = %d\n", x);
    switch(c) {
        case '+':
            x++;
            // need to break or it falls into everything after
            break;
        case '-':
            x--;
            // need to break or it falls into everything after
            break;
        default:
            x *= 2;
    }
    printf("x = %d\n", x);
    
    return 0;
}
#include <stdio.h>
int main(void) {
    int x = 5;
    long l = 134903;
    long long ll = 390839829902920993;
    float f = 837.89;
    double num = 89481231.0990208;
    char c = 'h';
    char s[] = "hello";

    printf("hello world\n");
    printf("my int = %-5d\n", x);
    printf("%20.3f %15.2e %g\n", num, num, num);
    printf("my char = %c\n", c);
    printf("my msg = %s\n", s);
    return 0;
}
