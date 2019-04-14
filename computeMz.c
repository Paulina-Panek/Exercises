/*************
// Paulina Panek
// 4/13/2019
//
// Protein Metrics interview exercise
//
// Simple program that calculates possible m/z for preprogrammed masses and charges
**************/


#include <stdio.h>

void computeMz(double * MassList, int MassListSize, int * chargeList, int chargeListSize, double * mzListOut, int *mzListOutSize);

int main()

{
    int MassListSize, chargeListSize, *mzListOutSize, i, j;
    double MassList[3] = {22783.0, 22807.2, 500505.7};
    int chargeList[5] = {10, 11, 12, 13, 14};
    double mzListOut[1000];
 
    chargeListSize = 5;
    MassListSize = 3;

    /* initializing array & size, so if sth goes wrong we will notice */
    for (i = 0; i < 1000; i++)
    {
        mzListOut[i] = 0.0;
    }
    mzListOutSize = &i;
 
    computeMz(MassList, MassListSize, chargeList, chargeListSize, mzListOut,mzListOutSize);  

    printf("You should see \t%d results\n", *mzListOutSize);

    for (j = 0; j < *mzListOutSize; j++)
    {
        printf("%d\t%f\n", j+1,  mzListOut[j]);
    }

    return(0);
}

void computeMz(double * MassList, int MassListSize, int * chargeList, int chargeListSize, double * mzListOut, int *mzListOutSize)
{
    int k, l, counter;

    counter = 0;

    for (k = 0; k < MassListSize; k++)
    {
        for (l = 0; l < chargeListSize; l++)
	{
            mzListOut[counter] = (MassList[k] - chargeList[l]) / chargeList[l];  /* Assumption: charge caused by loss of proton, so change in mass = # lost protons */
	    counter++;
	}      
    }

    *mzListOutSize = counter;
}
