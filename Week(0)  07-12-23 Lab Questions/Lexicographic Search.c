#include<stdio.h>
void sorting(int n,char Array[][50])
{
    char temp[50];
    for(int j = 0;j < n-1; j++)
    {
        for(int i = 0;i < n-1;i++)
        {
            if (strcmp(Array[i] , Array[i+1]) < 0)
            {
                strcpy(temp, Array[i]);
                strcpy(Array[i], Array[i+1]);
                strcpy(Array[i+1], temp);
            }
        }
    }
    printf("Array after sorting lexicographically is\n");
    for(int i=0; i<n; i++)
    {
        printf("%s\n",Array[i]);
    }


}


void main()
{
    int n;

    printf("Enter the size of the array\n");
    scanf("%d",&n);

    char Array[n][50];

    printf("Enter the elements of string array: \n");
    for(int i=0;i < n; i++)
    {
        scanf("%s",&Array[i]);
    }

    sorting(n, Array);

}
