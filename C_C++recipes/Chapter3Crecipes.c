
/* This program determines the value of PI using Monte Carlo method. */
//From C Recipes Chapter 3 -- Calculate the value of Pi
                                                                   /* BL */
#include <stdio.h>                                                 /* L1 */
#include <stdlib.h>                                                /* L2 */
#include <math.h>                                                  /* L3 */
                                                                   /* BL */
main()                                                             /* L4 */
{                                                                  /* L5 */
 int intP, intCircle, intSquare, intToss, intRM, i;                /* L6 */
 float  fltPi, fltX, fltY, fltR;                                   /* L7 */
 char ch;                                                          /* L8 */
 intRM = RAND_MAX;                                                 /* L9 */
 do {           /* outer do-while loop begins */                   /* L10 */
     intCircle = 0;                                                /* L11 */
     do {       /* inner do-while loop beginss */                  /* L12 */
       printf("Enter the number of tosses (2 <= N <= 5000) : ");   /* L13 */
       scanf("%d", &intToss);                                      /* L14 */
     } while ((intToss < 2) || (intToss > 5000)); /* inner do-wh loop ends */  /* L15 */
     intSquare = intToss;                                          /* L16 */
     for (i = 0; i < intToss; i++) {                               /* L17 */
     intP = rand();                                                /* L18 */
     fltX = ((float)intP)/intRM;                                   /* L19 */
     intP = rand();                                                /* L20 */
     fltY = ((float)intP)/intRM;                                   /* L21 */
     fltR = sqrt((fltX * fltX) + (fltY * fltY));                   /* L22 */
     if (fltR <= 1)                                                /* L23 */
       intCircle = intCircle + 1;                                  /* L24 */
    }                                                              /* L25 */
   fltPi = 4 * ((float) intCircle) / intSquare ;                   /* L26 */
   printf("\nThe value of pi is : %f\n", fltPi);                   /* L27 */
  printf("Do you want to continue? (Y/N) : ");                     /* L28 */
    scanf(" %c", &ch);                                             /* L29 */
 } while ((ch == 'y') || (ch == 'Y'));   /* outer do-while loop ends */  /* L30 */
                                                                   /* BL  */
 printf("Thank you\n");                                            /* L31 */
 return(0);                                                        /* L32 */
}         