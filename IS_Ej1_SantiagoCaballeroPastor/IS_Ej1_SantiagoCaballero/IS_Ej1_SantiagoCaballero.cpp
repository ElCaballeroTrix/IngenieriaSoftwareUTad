// IS_Ej1_SantiagoCaballero.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <windows.h>
#include  <stdlib.h>

//The player can move left or right, shoot left or right but only a single bullet will be in the game
//Enemies come from the left and right to kill you
//If an enemy hits you, Game Over. If you hit an enemy with a bullet, the score will increase
const int sizeOfTerrain = 41;
const char salidaOriginal[sizeOfTerrain] = { '_','_','_','_','_','_','_','_','_','_',
                                '_','_','_','_','_','_','_','_','_','_',
                                '_','_','_','_','_','_','_','_','_','_',
                                '_','_','_','_','_','_','_','_','_', '_','\0' };

int playerPosition = 20;
int enemyLeftPosition = 0, enemyRightPosition = sizeOfTerrain-2;
bool enemyLeftDead = false, enemyRightDead = false;
int bulletLeftPosition = -1, bulletRightPosition = -1;
bool bulletLeftExists = false, bulletRightExists = false;
int score = 0;
char salida[sizeOfTerrain];

void GetInputs();
void BulletMovement();
void EnemyMovement();
void PrintConsole();

int main()
{
    /*const char salidaOriginal[41] = {'_','_','_','_','_','_','_','_','_','_',
                                '_','_','_','_','_','_','_','_','_','_',
                                '_','_','_','_','_','_','_','_','_','_',
                                '_','_','_','_','_','_','_','_','_', '_','\0' };

    int playerPosition = 20;
    int enemyLeftPosition = 0, enemyRightPosition = 39;
    bool enemyLeftDead = false, enemyRightDead = false;
    int bulletLeftPosition = -1, bulletRightPosition = -1;
    bool bulletLeftExists = false, bulletRightExists = false;
    int score = 0;
    char salida[41];*/
    while (true) {
        strncpy_s(salida, 41, salidaOriginal, 41);
        //************************************Messy Code********************************************************************************
        /*
        if (((GetAsyncKeyState(0x25) & 0x8000) != 0) && !bulletLeftExists && !bulletRightExists) {
            bulletLeftExists = true;
            bulletLeftPosition = playerPosition;
        }
        else if (((GetAsyncKeyState(0x27) & 0x8000) != 0) && !bulletRightExists && !bulletLeftExists) {
            bulletRightExists = true;
            bulletRightPosition = playerPosition;
        }
        if (((GetAsyncKeyState(0x41) && 0x8000) != 0) && bulletLeftPosition != playerPosition) {
            playerPosition--;
        }
        else if (((GetAsyncKeyState(0x44) && 0x8000) != 0) && bulletRightPosition != playerPosition) {
            playerPosition++;
        }
        if (bulletLeftExists) {
            bulletLeftPosition--;
            salida[bulletLeftPosition] = 'o';
            if (bulletLeftPosition == enemyLeftPosition || bulletLeftPosition - 1 == enemyLeftPosition) {
                score++;
                enemyLeftDead = true;
                bulletLeftExists = false;
                salida[bulletLeftPosition] = '_';
                salida[enemyLeftPosition] = '_';
            }
        }
        if (bulletRightExists) {
            bulletRightPosition++;
            salida[bulletRightPosition] = 'o';
            if (bulletRightPosition == enemyRightPosition || bulletRightPosition + 1 == enemyRightPosition) {  
                score++;
                enemyRightDead = true;
                bulletRightExists = false;
                salida[bulletRightPosition] = '_';
                salida[enemyRightPosition] = '_';
            }
        }

        if (!enemyLeftDead) {
            enemyLeftPosition++;
            salida[enemyLeftPosition] = 'E';
            if (enemyLeftPosition == playerPosition) {
                printf("GAME OVER\n");
                exit(0);
            }
        }
        else {
            enemyLeftPosition = 0;
            salida[enemyLeftPosition] = 'E';
            enemyLeftDead = false;
        }
        if (!enemyRightDead) {
            enemyRightPosition--;
            salida[enemyRightPosition] = 'E';
            if (enemyRightPosition == playerPosition) {
                printf("GAME OVER\n");
                exit(0);
            }
        }
        else {
            enemyRightPosition = 39;
            salida[enemyRightPosition] = 'E';
            enemyRightDead = false;
        }
        salida[playerPosition] = 'A';
        printf("Score: %d\n", score);
        printf("%s\n", salida);
        Sleep(500);
        system("CLS");
        */
        //******************************************************************************************************************************
        //*******************************************Clean Code*************************************************************************
        GetInputs();
        BulletMovement();
        EnemyMovement();
        PrintConsole();
        //******************************************************************************************************************************
    }

}

//Function that detects player inputs for bullet and movement of player
void GetInputs() {
    
    //Input Left Key Shoot Left
    if (((GetAsyncKeyState(0x25) & 0x8000) != 0) && !bulletLeftExists && !bulletRightExists) {
        bulletLeftExists = true;
        bulletLeftPosition = playerPosition;
    }
    //Input Right Key Shoot Right
    else if (((GetAsyncKeyState(0x27) & 0x8000) != 0) && !bulletRightExists && !bulletLeftExists) {
        bulletRightExists = true;
        bulletRightPosition = playerPosition;
    }
    //Input A Move Left
    if (((GetAsyncKeyState(0x41) && 0x8000) != 0) && bulletLeftPosition != playerPosition) {
        playerPosition--;
    }
    //Input D Move Right
    else if (((GetAsyncKeyState(0x44) && 0x8000) != 0) && bulletRightPosition != playerPosition) {
        playerPosition++;
    }
}

//Movement of bullet
void BulletMovement() {
    //**Left Bullet Movement**
    if (bulletLeftExists) {
        bulletLeftPosition--;
        salida[bulletLeftPosition] = 'o';
        if (bulletLeftPosition == enemyLeftPosition || bulletLeftPosition - 1 == enemyLeftPosition) {
            score++;
            enemyLeftDead = true;
            bulletLeftExists = false;
            salida[bulletLeftPosition] = '_';
            salida[enemyLeftPosition] = '_';
        }
    }
    //**Right Bullet Movement**
    if (bulletRightExists) {
        bulletRightPosition++;
        salida[bulletRightPosition] = 'o';
        if (bulletRightPosition == enemyRightPosition || bulletRightPosition + 1 == enemyRightPosition) {
            score++;
            enemyRightDead = true;
            bulletRightExists = false;
            salida[bulletRightPosition] = '_';
            salida[enemyRightPosition] = '_';
        }
    }
}
void EnemyMovement() {
    //**Left Enemy Movement**
    if (!enemyLeftDead) {
        enemyLeftPosition++;
        salida[enemyLeftPosition] = 'E';
        if (enemyLeftPosition == playerPosition) { //Player is Killed
            printf("GAME OVER\n");
            exit(0);
        }
    }
    else {
        //Spawn Enemy Left
        enemyLeftPosition = 0;
        salida[enemyLeftPosition] = 'E';
        enemyLeftDead = false;
    }
    //**Right Enemy Movement**
    if (!enemyRightDead) {
        enemyRightPosition--;
        salida[enemyRightPosition] = 'E';
        if (enemyRightPosition == playerPosition) { //Player is Killed
            printf("GAME OVER\n");
            exit(0);
        }
    }
    else {
        //Spawn Enemy Right
        enemyRightPosition = sizeOfTerrain-2;
        salida[enemyRightPosition] = 'E';
        enemyRightDead = false;
    }
}
void PrintConsole(){
    //Prints in console the terrain with the bullets, player and enemies
    salida[playerPosition] = 'A';
    printf("Score: %d\n", score);
    printf("%s\n", salida);
    Sleep(500);
    system("CLS");
}

//Aquí esta bien
//ERROR.....ERROR
//¡¡¡¡¡CONFLICTO!!!!!
//Aquí esta bien otra vez




//Nuevo contenido en la rama secundaria
//Estoy en la rama main y no quiero ningun conflicto