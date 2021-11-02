#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dimension;

//method for displaying matrix
void displayMatrix(int **matrix)
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            printf("%d", matrix[i][j]);
            if (j < (dimension - 1))
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
//method to return identity matrix if expo -- 0
void identityMatrix(int **matrix)
{
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 1;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }
    displayMatrix(matrix);
}

int main(int argc, char *argv[])
{

    //open file from
    FILE *fp;
    int val = 0;
    int size;
    while (argv[1][val] != '\0')
    {
        size++;
        val++;
    }

    char *file = (char *)malloc(sizeof(char) * size);
    strcpy(file, argv[1]);

    fp = fopen(file, "r");

    //no file found
    if (!fp)
    {
        printf("No File Found\n");
        return 0;
    }

    // scan dimension from file
    fscanf(fp, "%d\n", &dimension);

    //add elements from input stream into matrix
    int **matrix = (int **)malloc(dimension * sizeof(int *));
    int **product = (int **)malloc(dimension * sizeof(int *));
    int **temp = (int **)malloc(dimension * sizeof(int *));

    // allocate memory for matrices
    for (int size = 0; size < dimension; size++)
    {
        product[size] = (int *)malloc(sizeof(int) * dimension);
        matrix[size] = (int *)malloc(sizeof(int) * dimension);
        temp[size] = (int *)malloc(sizeof(int) * dimension);
    }
    //get matrix values
    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }
    int expo = 0;
    //scan in exponent from file
    fscanf(fp, "%d", &expo);
    //return identity matrix if exponent is 0
    if (expo == 0)
    {
        identityMatrix(product);
    }
    else if (expo == 1)
    {
        displayMatrix(matrix);
    }
    else
    //multiply expo times
    {
        for (int r = 0; r < dimension; r++)
        {
            for (int s = 0; s < dimension; s++)
            {

                product[r][s] = matrix[r][s];
            }
        }
        for (int e = 0; e < expo - 1; e++)
        {
            for (int i = 0; i < dimension; i++)
            {
                for (int j = 0; j < dimension; j++)
                {
                    temp[i][j] = 0;
                    for (int k = 0; k < dimension; k++)
                    {
                        temp[i][j] += product[i][k] * matrix[k][j];
                    }
                }
            }
            for (int f = 0; f < dimension; f++)
            {
                for (int g = 0; g < dimension; g++)
                {

                    product[f][g] = temp[f][g];
                }
            }
        }
        displayMatrix(product);
    }

    // free matrix values
    for (int k = 0; k < dimension; k++)
    {
        free(matrix[k]);
        free(product[k]);
        free(temp[k]);
    }
    //free matrices
    free(matrix);
    free(product);
    free(temp);
    free(file);

    fclose(fp);
    return 0;
}