#include "map.h"
#include "GL/glut.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

int mapW[MAP_HEIGHT * MAP_WIDTH];

void generateMap(int map[MAP_HEIGHT][MAP_WIDTH]) {
    // Initialize the map with outer walls
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (y == 0 || y == MAP_HEIGHT - 1 || x == 0 || x == MAP_WIDTH - 1) {
                map[y][x] = 1; // Outer walls
            }
            else {
                map[y][x] = 0; // Inner space
            }
        }
    }

    // Scatter some inner walls randomly
    int numberOfWalls = (MAP_WIDTH - 2) * (MAP_HEIGHT - 2) / 4; // Adjust density here
    while (numberOfWalls > 0) {
        int x = rand() % (MAP_WIDTH - 2) + 1; // Random x inside the map (excluding borders)
        int y = rand() % (MAP_HEIGHT - 2) + 1; // Random y inside the map (excluding borders)

        if (map[y][x] == 0) { // Only place a wall if the space is empty
            map[y][x] = 1;
            numberOfWalls--;
        }
    }
}

void convertMapToArray(int map[MAP_HEIGHT][MAP_WIDTH], int mapW[]) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            mapW[y * MAP_WIDTH + x] = map[y][x];
        }
    }
}

void printMap(int map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%d ", map[y][x]);
        }
        printf("\n");
    }
}

void initMap() {
    srand(time(NULL)); // Seed the random number generator

    int map[MAP_HEIGHT][MAP_WIDTH];

    generateMap(map);
    convertMapToArray(map, mapW);

    return 0;
}


int mapF[] =          // floors
{
 1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,
};

int mapC[] =          // ceiling
{
 2,2,2,2,2,2,2,2,2,2,
 2,2,2,2,2,2,2,2,2,2,
 2,2,2,2,2,2,2,2,2,2,
 2,2,2,2,2,2,2,2,2,2,
 2,2,2,2,2,2,2,2,2,2,
 2,2,2,2,2,2,2,2,2,2,
 2,2,2,2,2,2,2,2,2,2,
 2,2,2,2,2,2,2,2,2,2,
 2,2,2,2,2,2,2,2,2,2,
 2,2,2,2,2,2,2,2,2,2,
};