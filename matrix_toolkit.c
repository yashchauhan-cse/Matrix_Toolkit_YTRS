#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void addition(double A1, double A2, double A3, double A4, double B1, double B2, double B3, double B4);
void subtraction(double A1, double A2, double A3, double A4, double B1, double B2, double B3, double B4);
void multiplication(double A1, double A2, double A3, double A4, double B1, double B2, double B3, double B4);
void inverse(double A1, double A2, double A3, double A4);
void power(double A1, double A2, double A3, double A4, int n);
void cht(double A1, double A2, double A3, double A4);
void eigen(double A1, double A2, double A3, double A4);
void lines(double a1, double b1, double c1, double a2, double b2, double c2);

double disc;


int main()
{

    int j=0, n;

    time_t startTime, endTime;
    time(&startTime);

    double A1, A2, A3, A4;
    double B1, B2, B3, B4;
    char choice1, choice2;
    double a1, b1, c1, a2, b2, c2;
    // BASE MATRIX A AND B = [A1,A2,A3,A4] AND [B1,B2,B3,B4]
    
    printf("\n\n=========================================\n");
    printf("||       MATRIX TOOLKIT - YTRS v1.0    ||\n");
    printf("||          Created by: YASH           ||\n");
    printf("=========================================\n\n");

    for (;;)
    {

    printf("\n========MENU========\n");
    printf("\n[A] ADDITION.");
    printf("\n[B] SUBTRACTION.");
    printf("\n[C] MULTIPLICATION.");
    printf("\n[D] INVERSE.");
    printf("\n[E] POWER.");
    printf("\n[F] CHARACTERISTIC EQUATION.");
    printf("\n[G] EIGEN VALUES.");
    printf("\n[H] SOLVE LINES.");
    printf("\n[I] EXIT.");
    printf("\n\n====================\n\n");

    scanf(" %c", &choice1);

    if(choice1=='A' || choice1=='a' || choice1=='B' || choice1=='b' || choice1=='C' || choice1=='c')
    {

        printf("\nENTER ROW1 FOR A: [A1,A2]\t=\t");
        scanf("%lf %lf", &A1, &A2);
        printf("ENTER ROW2 FOR A: [A3,A4]\t=\t");
        scanf("%lf %lf", &A3, &A4);
    
        printf("\nENTER ROW1 FOR B: [B1,B2]\t=\t");
        scanf("%lf %lf", &B1, &B2);
        printf("ENTER ROW2 FOR B: [B3,B4]\t=\t");
        scanf("%lf %lf", &B3, &B4);

        switch (choice1)
    {
        case 'A':
        case 'a':
            addition(A1, A2, A3, A4, B1, B2, B3, B4);
            break;

        case 'B':
        case 'b':
            subtraction(A1, A2, A3, A4, B1, B2, B3, B4);
            break;

        case 'C':
        case 'c':
            multiplication(A1, A2, A3, A4, B1, B2, B3, B4);
            break;

        default:
            printf("INVALID CHOICE.\n");
            break;
    }
    }
    else if(choice1=='D' || choice1=='d')
    {
        printf("\nENTER ROW1 FOR A: [A1,A2]\t=\t");
        scanf("%lf %lf", &A1, &A2);
        printf("ENTER ROW2 FOR A: [A3,A4]\t=\t");
        scanf("%lf %lf", &A3, &A4);

        switch (choice1)
    {
        case 'D':
        case 'd':
            inverse(A1, A2, A3, A4);
            break;

        default:
            printf("INVALID CHOICE.\n");
            break;
    }
    }
    else if(choice1=='E' || choice1=='e')
    {
            printf("\nEnter the power (n>0):\n");
            scanf("%d", &n);


            if(n>0 && n<20)
            {
            printf("\nENTER ROW1 FOR A: [A1,A2]\t=\t");
            scanf("%lf %lf", &A1, &A2);
            printf("ENTER ROW2 FOR A: [A3,A4]\t=\t");
            scanf("%lf %lf", &A3, &A4);

            power(A1,A2,A3,A4,n);
            }
            else if(n>20)
            {
                printf("\nTOO HIGH! PLEASE ENTER A POWER <= 20 TO AVOID MATRIX OVERLOAD.\n");
                printf("\nRETURNING YOU SAFELY TO MENU...\n");
                continue;
            }
            else if(n==0)
            {
                printf("\nA^0 = I (IDENTITY MATRIX)\n");
                printf("====================\n");
                printf("  | 1.00  0.00 |\n");
                printf("  | 0.00  1.00 |\n");
                printf("====================\n");   
            }
            else
            {
                printf("\nNOT BUILT YET.\n");
            }
    }
    else if(choice1=='F' || choice1=='f')
    {
            printf("\nENTER ROW1 FOR A: [A1,A2]\t=\t");
            scanf("%lf %lf", &A1, &A2);
            printf("ENTER ROW2 FOR A: [A3,A4]\t=\t");
            scanf("%lf %lf", &A3, &A4);

            printf("\nTHE CHARACTERISTIC EQUATION: A^2 - (TRACE)A + (DETERMINANT)I = 0\n");

            cht(A1,A2,A3,A4);
    }
    else if(choice1=='G' || choice1=='g')
    {
            printf("\nENTER ROW1 FOR A: [A1,A2]\t=\t");
            scanf("%lf %lf", &A1, &A2);
            printf("ENTER ROW2 FOR A: [A3,A4]\t=\t");
            scanf("%lf %lf", &A3, &A4);

            eigen(A1,A2,A3,A4);
    }
    else if(choice1=='H' || choice1=='h')
    {
            printf("\nENTER LINE1: a1*x + b1*y = c1\n");
            scanf("%lf %lf %lf", &a1, &b1, &c1);
            printf("\nENTER LINE2: a2*x + b2*y = c2\n");
            scanf("%lf %lf %lf", &a2, &b2, &c2);

            lines(a1,b1,c1,a2,b2,c2);
    }
    else 
    {
        break;
    }

    j+=1;


    printf("\n\nDO YOU WANT TO CONTINUE?\n");
    scanf(" %c", &choice2);

    if(choice2=='Y' || choice2=='y')
    {
        printf("\nRETURNING TO MENU...\n");
        continue;
    }
    else if(choice2=='N' || choice2=='n')
    {
        break;
    }
    else
    {
        printf("\nINVALID CHOICE.\n");
        break;
    }

    }
    time(&endTime);

    printf("\n==============================");
    printf("\n||     ! ! ! AAVJO ! ! !    ||");
    printf("\n||  TOOLKIT CLOSED SAFELY   ||");
    printf("\n==============================\n");
    printf("\nPROGRAM RAN %d TIMES.\n\n", j);

    printf("\nSESSION STARTED AT: %s", ctime(&startTime));
    printf("SESSION ENDED AT: %s", ctime(&endTime));

    double duration = difftime(endTime, startTime);
    int mins = duration / 60;
    int secs = (int)duration % 60;
    printf("\nTOTAL SESSION DURATION: %d MINUTES, %d SECONDS.\n", mins, secs);

    printf("\nTHANK YOU FOR USING MATRIX TOOLKIT - YTRS.\n");
    printf("REMEMBER: MATHEMATICS IS POWER.\n\n");

    system("pause");
    getchar();
    getchar();
    return 0;
}

    void addition(double A1,double A2,double A3,double A4, double B1,double B2,double B3,double B4)
    {
        double C1, C2, C3, C4;

        C1=A1+B1;
        C2=A2+B2;
        C3=A3+B3;
        C4=A4+B4;

        printf("\nTHE ADDITION MATRIX C:\n\n");
        printf("====================\n");
        printf("  | %.2lf  %.2lf |\n", C1, C2);
        printf("  | %.2lf  %.2lf |\n", C3, C4);
        printf("====================\n");
    }

    void subtraction(double A1,double A2,double A3,double A4, double B1,double B2,double B3,double B4)
    {
        double C1, C2, C3, C4;

        C1=A1-B1;
        C2=A2-B2;
        C3=A3-B3;
        C4=A4-B4;

        printf("\nTHE SUBTRACTION MATRIX C:\n\n");
        printf("====================\n");
        printf("  | %.2lf  %.2lf |\n", C1, C2);
        printf("  | %.2lf  %.2lf |\n", C3, C4);
        printf("====================\n");
    }
    
    void multiplication(double A1,double A2,double A3,double A4, double B1,double B2,double B3,double B4)
    {
        double C1, C2, C3, C4;

        C1=(A1*B1)+(A2*B3);
        C2=(A1*B2)+(A2*B4);
        C3=(A3*B1)+(A4*B3);
        C4=(A3*B2)+(A4*B4);

        printf("\nTHE MULTIPLICATION MATRIX C:\n\n");
        printf("====================\n");
        printf("  | %.2lf  %.2lf |\n", C1, C2);
        printf("  | %.2lf  %.2lf |\n", C3, C4);
        printf("====================\n");
    }

    void inverse(double A1,double A2,double A3,double A4)
    {
        double C1, C2, C3, C4;
        double determinant;
        
        determinant = (A1*A4)-(A2*A3);

        if(fabs(determinant) < 1e-10)
        {
            printf("\nMATRIX IS NON-INVERTIBLE.\n");
        }
        else
        {
            C1=(A4)/(determinant);
            C2=-(A2)/(determinant);
            C3=-(A3)/(determinant);
            C4=(A1)/(determinant);

            printf("\nTHE INVERSE MATRIX C:\n\n");
            printf("====================\n");
            printf("  | %.2lf  %.2lf |\n", C1, C2);
            printf("  | %.2lf  %.2lf |\n", C3, C4);
            printf("====================\n");
        }

    }    

    void power(double A1,double A2,double A3,double A4, int n)
    {
        int i=1;
        double C1, C2, C3, C4;
        double I1=1, I2=0, I3=0, I4=1;

            for(i=1;i<=n;i++)
            {
                C1=(I1*A1)+(I2*A3);
                C2=(I1*A2)+(I2*A4);
                C3=(I3*A1)+(I4*A3);
                C4=(I3*A2)+(I4*A4);

                I1=C1;
                I2=C2;
                I3=C3;
                I4=C4;

            }
        
            printf("====================\n");
            printf("  | %.2lf  %.2lf |\n", I1, I2);
            printf("  | %.2lf  %.2lf |\n", I3, I4);
            printf("====================\n");
        

    }    

    void cht(double A1,double A2,double A3,double A4)
    {
        double determinant;
        double trace;
        
        determinant = (A1*A4)-(A2*A3);
        trace = A1+A4;

        if(trace>0)
        {
            printf("\nTHE CHT EQUATION IS:  A^2 - %.2lfA + %.2lfI = 0", trace, determinant);
        }
        else if(trace<0)
        {
            printf("\nTHE CHT EQUATION IS:  A^2 + %.2lfA + %.2lfI = 0", (-trace), determinant);
        }
        else if (trace==0 && determinant!=0)
        {
            printf("\nTHE CHT EQUATION IS:  A^2 + %lfI = 0", determinant);
        }
        else if (trace==0 && determinant==0)
        {
            printf("\nTHE CHT EQUATION IS:  A^2 = 0\n");
            printf("\nIT'S A NILPOTENT MATRIX!\n");
        }

    }    
    void eigen(double A1, double A2, double A3, double A4)
    {
        double determinant;
        double trace;
        double e1, e2;
        
        determinant = (A1*A4)-(A2*A3);
        trace = A1+A4;  
        disc = sqrt((trace*trace)-4*determinant);


        if(disc==0)
        {
            e1 = (trace)/2;
            e2 = (trace)/2;
            printf("\n\tEIGEN VALUES ARE REAL AND SAME.\n");
            printf("\tEIGEN1 = %.2lf && EIGEN2 = %.2lf", e1, e2);
        }
        else if(disc>0)
        {
            e1 = (trace+disc)/2;
            e2 = (trace-disc)/2;
            printf("\n\tEIGEN VALUES ARE REAL AND DISTINCT.\n");
            printf("\tEIGEN1 = %.2lf && EIGEN2 = %.2lf", e1, e2);
        }
        else
        {
            e1 = (trace)/2;
            e2 = (trace)/2;

            printf("\n\tEIGEN VALUES ARE COMPLEX CONJUGATE.\n");
            printf("\tEIGEN1 = %.2lf+i%.2lf\n", e1, fabs(disc/2));
            printf("\nEIGEN2 = %.2lf-i%.2lf\n", e2, fabs(disc/2));
        }
    }
    void lines(double a1, double b1, double c1, double a2, double b2, double c2)
    {
        double x, y, D;

        D = a1*b2 - a2*b1;

        if(fabs(D) > 1e-10)
        {
            x = (b2*c1 - b1*c2)/(a1*b2-a2*b1);
            y = (a1*c2 - a2*c1)/(a1*b2-a2*b1);
            printf("\nX = %.2lf && Y = %.2lf", x, y);
        }
        else if(fabs(D) < 1e-10 && (fabs(b2*c1 - b1*c2) < 1e-10) && (fabs(a1*c2 - a2*c1) < 1e-10))
        {
            printf("\nINFINITELY MANY SOLUTIONS EXIST.\n");
        }
        else
        {
            printf("\nNO SOLUTIONS EXIST.\n");
        }
    }
