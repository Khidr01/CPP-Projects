#include <iostream>
/* Tic tac toe game */
/* Khidr which is me is the creator of this cpp file */
/* Feel free to use and edit it. */

void update(char _table[3][3], int updateVal, char role);
void draw_table(char table_arr[3][3]);
int checkWinner(int checkTable[4]);
void bubbleSort(int arr[], int reachPoint);

// Playing table
char table[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };

// Winning situations
int winningSituations[7][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9},
        {1, 5, 9},
        /*
        Those are all possibilities to win in 
        the game, but since I implemented a sort
        algorithm. There is no need for all these
        possibilities again.
        {3, 5, 7},
        {3, 2, 1},
        {6, 5, 4},
        {9, 8, 7},
        {7, 4, 1},
        {8, 5, 2},
        {9, 6, 3},
        {9, 5, 1},
        {7, 5, 3}
        */
};
int xRecords[5] = { 0, 0 ,0 , 0, 0 }, iX = 0;
int oRecords[5] = { 0, 0 ,0 , 0, 0 }, iO = 0;

int main(void)
{
    char xRole = 'x', oRole = 'o', currentRole = ' ';
    // Stands for choice
    int ch = 0;
    // check for the winner 1 means true, 0 means false
    int xWinner = 0, oWinner = 0;
    // Initializate the array
    // which represents the table of the tic tac toe
    for (int i = 0; i <= 8; i++)
    {
        draw_table(table);
        if (i % 2 == 0) {
            std::cout << xRole <<" role" << std::endl;
            std::cout << "Enter your choice: " << std::endl;
            std::cin >> ch;
            currentRole = xRole;
            xRecords[iX] = ch;
            ++iX;
        }
        else {
            std::cout << oRole << " role" << std::endl;
            std::cout << "Enter your choice: " << std::endl;
            std::cin >> ch;
            currentRole = oRole;
            oRecords[iO] = ch;
            ++iO;
        }
        // update the values first, then check for the winner
        update(table, ch, currentRole);

        // Check for the winner after the 5th iteration
        if (i >= 4)
        {
            bubbleSort(xRecords, iX);
            bubbleSort(oRecords, iO);
            xWinner = checkWinner(xRecords);
            oWinner = checkWinner(oRecords);
            if (xWinner == 1)
            {
                std::cout << "Player X won" << std::endl;
                break;
            }
            if (oWinner == 1)
            {
                std::cout << "Player O won" << std::endl;
                break;
            }
        }
        /*
        * Those two for loops were created, to keep
        * tracking of how the steps of x and o are being
        * placed and sort. Remember that the sorting process
        * start with the 4th step in programming, which means 
        * the 5th in real world. Because x player can win in the
        * fifth step as o played 2 and x 3 times = 5.
        for (int m = 0; m <= 4; m++)
        {
            std::cout << "\t\t" << m + 1 << " xRecords:\t";
            std::cout << "\t\t" << xRecords[m] << std::endl;
        }
        for (int m = 0; m <= 4; m++)
        {
            std::cout << "\t\t" << m + 1 << " oRecords:\t";
            std::cout << "\t\t" << oRecords[m] << std::endl;
        }
        */
        // resetting the choice variabale to 0
        ch = 0;
    }
    if (xWinner == 0 && oWinner == 0)
    {
        std::cout << "No winner" << std::endl;
    }
    std::cout << "Result: " << std::endl;
    draw_table(table);
    return 0;
    
}

void update(char _table[3][3], int updateVal, char role)
{
    switch (updateVal)
    {
    case 1:
        _table[0][0] = role;
        break;
    case 2:
        _table[0][1] = role;
        break;
    case 3:
        _table[0][2] = role;
        break;
    case 4:
        _table[1][0] = role;
        break;
    case 5:
        _table[1][1] = role;
        break;
    case 6:
        _table[1][2] = role;
        break;
    case 7:
        _table[2][0] = role;
        break;
    case 8:
        _table[2][1] = role;
        break;
    case 9:
        _table[2][2] = role;
        break;
    }
}

void draw_table(char table_arr[3][3])
{
    std::cout << "\t\t[" << table_arr[0][0] << "]|[" << table_arr[0][1] << "]|[" << table_arr[0][2] << "]" << std::endl;
    std::cout << "\t\t---|---|---" << std::endl;
    std::cout << "\t\t[" << table_arr[1][0] << "]|[" << table_arr[1][1] << "]|[" << table_arr[1][2] << "]" << std::endl;
    std::cout << "\t\t---|---|---" << std::endl;
    std::cout << "\t\t[" << table_arr[2][0] << "]|[" << table_arr[2][1] << "]|[" << table_arr[2][2] << "]" << std::endl;
}

int checkWinner(int checkTable[4])
{
    int check = 0;
    for (int i = 0; i <= 15; i++)
    {
        if (winningSituations[i][0] == checkTable[check])
        {
            if (winningSituations[i][1] == checkTable[check + 1])
            {
                if (winningSituations[i][2] == checkTable[check + 2])
                {
                    return 1;
                }
            }
        }
        if (winningSituations[i][0] == checkTable[check + 1])
        {
            if (winningSituations[i][1] == checkTable[check + 2])
            {
                if (winningSituations[i][2] == checkTable[check + 3])
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void bubbleSort(int arr[], int reachPoint)
{
    int temp;
    for (int i = 0; i <= reachPoint - 1; i++)
    {
        for (int j = 0; j <= reachPoint - 2; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
        /*
        This section was used for testing purposes
        I wanted to see how the sort algorithm is working
        on the array of x and o records.
    std::cout << "\t\t\t\tLooping throw the record after sorting it" << std::endl;
    for (int k = 0; k <= 4; k++)
    {
        std::cout << "\t\t\t\t" << arr[k] << " " << std::endl;
    }
        */
}
