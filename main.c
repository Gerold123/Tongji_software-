#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMBER_MAX 100
#define NUMBER_MIN 0
#define MAX_NUM_OPERATOR 5
#define MIN_NUM_OPERATOR 3

int Compute_Num_Operators(int num1,int max,int min); // compute the number of the operators
char Do_Operation(float *results,int currents_num);  // do one operation between only two numbers and print on the screen

int main(int argc,char* argv[])
{

    // my variables
 int first_number=0,current_number=0,number_operations=0,i=0,j=0;
 int n_operators=0;
 char Operator=' ';// can assume (+) (-) (/) (*)
 float result=0;


 // create the file to save the n-channel operations
 FILE *file=fopen("result.txt","w");
 if(file==NULL)
 {
     printf("cannot read file !!! \n");
     return -2;
 }
  fprintf(file,"1756142\n");// insert my id the new file
 printf("1756142\n");

  // if there are the parameter n in command-line
 if(argc!=2)
 {
     // if there are not the parameter n in the command-line
     printf("error in command-line ,please insert an number!!\n");
     return -1;
 }
 number_operations=atoi(argv[1]);     // convert the argument from command-line (char => integer)

srand(time(NULL));   // initialize the random distributions  for not have the same value during the next run
 // we print and solve  n equations
 for(j=0;j<number_operations;j++)
 {

first_number=rand()%(NUMBER_MAX+1); // TO HAVE RANDOM  NUMBER IN [0,100]

 n_operators=Compute_Num_Operators(first_number,MAX_NUM_OPERATOR,MIN_NUM_OPERATOR);

 result=first_number;
 fprintf(file,"%d",first_number);
 printf("\n%d",first_number);

 // solving an equation
 for(i=0;i<n_operators;i++)
 {
     current_number=rand()%(NUMBER_MAX+1);
     Operator=Do_Operation(&result,current_number);
     fprintf(file,"%c",Operator);
     fprintf(file,"%d",current_number);
 }

 fprintf(file,"%c",'=');
 fprintf(file,"%f",result);
 printf("=%f\n",result);
 fprintf(file,"\n");
 }
 fclose(file);
    return 0;
}

int  Compute_Num_Operators(int num1,int max,int min)
{
    int i=0;
    for(i=0;i<max-min;i++)
    {
      if(num1%(max-i)!=0)
       return num1%(max-i);
    }
    return MIN_NUM_OPERATOR;
}

char Do_Operation(float* results,int currents_num)
{
    int value=0;
    value=(int)results%2;
    if(currents_num==0)
    {
        if(value==0){
     printf("+0");
     return '+';
     }
     if(currents_num%2!=0){
        printf("-0");
        return '-';
     }

    }

    if(currents_num%2==0)
    {
        printf("+%d",currents_num);
        *results=(float)*results+currents_num;
        return '+';
    }
    if(currents_num%2!=0)
    {
         printf("/%d",currents_num);
       *results=(float)*results/currents_num;
       return '/';
    }
    else if(currents_num<*results)
    {
         printf("-%d",currents_num);
        *results=(float)*results-currents_num;
        return '-';
    }
    else
    {
         printf("*%d",currents_num);
        *results=(float)*results*currents_num;
        return '*';
    }
}
