#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int row, int col, int height, int width)
{
    for(int i = row; i < row + height && i < ROWS; i++)
    {
        for(int j = col; j < col + width && j < COLS; j++)
        {
            canvas[i][j] = '*';
        }
    }
}

int main()
{
    int choice;
    int row, col, height, width;

    initializeCanvas();

    while(1)
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Display Canvas\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter starting row: ");
                scanf("%d", &row);

                printf("Enter starting column: ");
                scanf("%d", &col);

                printf("Enter height: ");
                scanf("%d", &height);

                printf("Enter width: ");
                scanf("%d", &width);

                drawRectangle(row, col, height, width);
                printf("Rectangle added successfully!\n");
                break;

            case 2:
                displayCanvas();
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}