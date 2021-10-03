#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int globalCount = 0;
int dummy = 2;

void pointers4(){
	int num = 300;
	int* p = &num;
	int** p2 = &p;
	int*** p3 = &p2;
	int**** p4 = &p3;
	int***** p5 = &p4;
	printf("num = %d\n", *****p5 );
}

void pointers3(){
	char mArr[] = "abcdefghij";
	char* p = mArr;
	printf("mArr[0] = %c memLoc = %p\n", *p, p);
	printf("mArr[1] = %c memLoc = %p\n", *(p+1), p+1);
	printf("\n");
	for (int i = 0; i < sizeof(mArr)/sizeof(char) - 1; i++){
		printf("mArr[%d] = %c memLoc = %p\n",i ,*(p+i), p+i);
	}
	printf("mArr = %s\n", p);
	
}

void stringsArray(){
	char string[100];
	char c;
	scanf("%c",&c);
	c = '@';
  	int i = 0;
 	printf("Enter the string: ");
 	//scanf("%s", string);
  	//i = strlen(string);
  	while (c != '\n')
  	{
  	  	scanf("%c", &c);
   	 	string[i] = c;
   	 	i++;
  	}     
  	string[i - 1] = 0;

	printf("%s\n", string);
	for (int j = 0; j < i - 1; j++){
		printf("char %d = %c\n", j, string[j]);
	}
}

void pointers2(){

	// 1D Array Recap
    int arr[7] = {1,2,3,4,5,6,7};
    // standard [] notation
    printf("arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);
    // pointer notation
    printf("arr = %p, *arr = %d, arr+1 = %p, *(arr+6) = %d\n", arr, *arr, arr+1, *(arr+6));


	int var = 789;
  
    // pointer for var
    int *ptr2;
  
    // double pointer for ptr2
    int **ptr1;
  
    // storing address of var in ptr2
    ptr2 = &var;
      
    // Storing address of ptr2 in ptr1
    ptr1 = &ptr2;

	int p = 10;
	int * pPtr;
	pPtr = &p;
	
	//puts('"%d\t%d\n%p\n",p+i,*(pPtr+i),pPtr+i');
	
	for (int i= 0;i<10;i++){
		printf("%d\t%d\n%p\n",p+i,*(pPtr+i),pPtr+i);
	}
	
	//printf("%d  %d\n%d  %d\n",p,*pPtr,p+1,*(pPtr+1));
}

void readFromFile(){
	char *buffer = 0;
	long length;
	FILE *f = fopen("emails1.txt", "rb");

	if (f){	
  		fseek(f, 0, SEEK_END);
  		length = ftell(f);
  		fseek(f, 0, SEEK_SET);
  		buffer = malloc(length);
  		if (buffer){
    		fread(buffer, 1, length, f);
  		}
  		fclose(f);
	}

	if (buffer){
  		printf("%s\n",buffer);		
  	}
  	
  	char *buf = buffer;
    int i = 0;
    char *p = strtok (buf, ".");
    char *array[20];

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, ".");
    }

    for (int j = 0; j < i; ++j) 
        printf("%s\n", array[j]);
  	
  	
  	
}

void arrayExamples(){
	int a,b;
    printf("enter rows and columns:\n");
    scanf("%d %d", &a, &b);
    int nrows = a;
    int ncols = b;
	    	
    //int nrows = (int) atoi(argv[1]);
    //int ncols = (int) atoi(argv[2]);
    
    //char *str = argv[3];
    //printf("%s %d %p\n", str, *str, &str);
    
    // Option 1
    int *mat = (int *) malloc(nrows*ncols*sizeof(int));
    for (int i=0; i<nrows*ncols; i++) {
        *(mat+i) = i;
    }
    printf("mat[1] = %d\n", mat[1]);
    //mat[1][2] //can't do this
    // Important conversion from 2d to 1d index
    //printf(*mat);
    for (int i=0; i<nrows; i++) {
    	for (int j=0; j<ncols; j++) {
    		printf("mat[%d][%d] = %d ",i,j, *(mat+i*ncols + j));
    	}
    	printf("\n");
    }
    printf("\n");
    // Option 2
    //int **mat = (int **) malloc(nrows*size(int *));
    //for (int i=0; i<nrows; i++) {
       // *(mat+i) = (int *) malloc(ncols*sizeof(int));
    //}

}

void pointerfun(int *p) {
    *p = *p * 2;
    printf("p val in fun = %d\n", *p);
    p = p+1;
    printf("p in fun= %p\n", p);
}

void pointerExamples(){
	int var = 789;
  
    // pointer for var
    int *ptr2;
  
    // double pointer for ptr2
    int **ptr1;
  
    // storing address of var in ptr2
    ptr2 = &var;
      
    // Storing address of ptr2 in ptr1
    ptr1 = &ptr2;
      
    // Displaying value of var using
    // both single and double pointers
    printf("Value of var = %d %p\n", var ,&var);
    printf("Value of var using single pointer = %d %p\n", *ptr2 , ptr2);
    printf("Value of var using double pointer = %d %p\n", **ptr1,*ptr1);
    
    
    int *p = (int *) malloc(sizeof(int));
    *p = 4;
    printf("p val before = %d\n", *p);
    printf("p before = %p\n", p);
    pointerfun(p);
    printf("p after = %p\n", p);
    printf("p val after = %d\n", *p);

    free(p);

}



void loopingExamples(){
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
}
void randomGenerator(){
	globalCount++;
	double sum = 0;
	double repeatCount = 200.0;
	while (repeatCount > 0) {
	    int num = rand()%100 + 1;
	    printf("%d ", num);
	    sum += num;
	    repeatCount--;
	} 
	printf("\n");
	double average = sum/200.0;
	printf("average = %f\n",average);
	if (average < 49.99 || average > 50.01){
		randomGenerator();
	} else {
	printf("average = %f\n",average);
	printf("count = %d\n", globalCount);
	}
}

void start(){
	char *choices[] = {
	"s = stringsArray",
	"p2 = pointers2",
	"f  = readFromFile",
	"a  = arrayExamples",
	"p  = pointerExamples",
	"l  = loopingExamples",
	"r  = randomGenerator",
	"p3 = pointers3",
	"p4 = pointers4"};
	printf("\nenter choice\n");
	
	int length = (int)( sizeof(choices) / sizeof(choices[0]) );
	//printf("length = %d\n",length);
	
	for (int i = 0;i<length;i++){
		printf("%s\n",choices[i]);
	}
	
	
    char s[5];
    scanf(" %s",s);
    if (strcmp(s,"p2") == 0){
    	pointers2();
    } else if (strcmp(s,"f") == 0){
    	readFromFile();
    } else if (strcmp(s,"a") == 0){
    	arrayExamples();
    } else if (strcmp(s,"p") == 0){
    	pointerExamples();
    } else if (strcmp(s,"l") == 0){
    	loopingExamples();
    } else if (strcmp(s,"r") == 0){
    	globalCount = 0;
        randomGenerator();
    } else if (strcmp(s,"s") == 0){
        stringsArray();
    } else if (strcmp(s,"p3") == 0){
        pointers3();
    } else if (strcmp(s,"p4") == 0){
        pointers4();
    } else {
    	printf("error try again");
    }
    
    start();
}


int main(void) {
	srand(time(NULL));
    start();
    return 0;
}
