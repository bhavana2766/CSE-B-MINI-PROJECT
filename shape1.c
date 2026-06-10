#include <stdio.h>
#include <stdlib.h>

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

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (1)
    {
        if (x1 >= 0 && x1 < ROWS && y1 >= 0 && y1 < COLS)
        {
            canvas[x1][y1] = '*';
        }

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}
int main()
{
    int choice;
    int row, col, height, width;
    int x1, y1, x2, y2;

    initializeCanvas();

    while(1)
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Display Canvas\n");
        printf("4. Exit\n");
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
                printf("Enter starting row: ");
                scanf("%d", &x1);

                printf("Enter starting column: ");
                scanf("%d", &y1);

                printf("Enter ending row: ");
                scanf("%d", &x2);

                printf("Enter ending column: ");
                scanf("%d", &y2);

                drawLine(x1, y1, x2, y2);
                printf("Line added successfully!\n");
                break;
            case 3:
                displayCanvas();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}