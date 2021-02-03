#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    FILE *fp_in = NULL;
    FILE *fp_out = NULL;
    char ch = NULL;
    char filename[] = "file.txt";

    fp_in = fopen(filename, "r");
    fp_out = fopen("temp.txt", "w");

    if (fp_in == NULL)
    {
        printf("ERROR, file not found\n");
        return (-1);
    }

    if (fp_out == NULL)
    {
        printf("ERROR, there was an internal error in the code\n");
        return (-1);
    }

    while (ch != EOF)
    {
        ch = fgetc(fp_in);
        if (ch != EOF)
            if (islower(ch) == true)
            {
                fputc(ch - 32, fp_out);
            }
            else
            {
                fputc(ch, fp_out);
            }
    }
    remove(filename);
    rename("temp.txt", filename);

    fclose(fp_in);
    fclose(fp_out);
    fp_in = NULL;
    fp_out = NULL;
    return 0;
}
