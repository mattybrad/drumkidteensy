#ifndef tommid_H_
#define tommid_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <avr/pgmspace.h>
 
#define tommid_NUM_CELLS 7951
#define tommid_SAMPLERATE 16384
 
const int8_t __attribute__((section(".progmem.data"))) tommid_DATA [] = {0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 42,
105, 124, 127, 118, 110, 98, 89, 79, 69, 59, 50, 40, 31, 21, 11, -2, -16, -27,
-37, -46, -55, -62, -70, -76, -82, -88, -93, -97, -100, -103, -105, -106, -107,
-106, -105, -104, -102, -100, -97, -93, -90, -85, -81, -76, -71, -66, -61, -55,
-50, -44, -38, -32, -26, -19, -12, -6, 0, 7, 14, 22, 29, 36, 44, 51, 58, 65, 71,
78, 84, 89, 94, 99, 103, 106, 109, 111, 111, 111, 110, 108, 107, 106, 104, 101,
99, 95, 92, 88, 83, 79, 74, 69, 64, 59, 54, 48, 42, 37, 31, 25, 19, 12, 6, 0,
-6, -13, -20, -26, -33, -40, -46, -53, -59, -65, -71, -76, -81, -85, -89, -93,
-96, -99, -100, -102, -103, -103, -102, -102, -100, -99, -96, -94, -91, -88,
-84, -80, -76, -72, -68, -63, -58, -53, -48, -43, -38, -32, -27, -21, -16, -10,
-4, 1, 8, 14, 20, 26, 33, 39, 45, 51, 56, 62, 67, 71, 76, 80, 83, 86, 89, 91,
92, 93, 94, 94, 93, 93, 91, 89, 87, 85, 82, 79, 76, 72, 69, 65, 61, 56, 52, 47,
43, 38, 33, 28, 22, 17, 11, 6, 0, -5, -10, -16, -22, -28, -33, -39, -44, -50,
-55, -60, -64, -68, -72, -75, -78, -81, -83, -85, -86, -87, -87, -87, -87, -86,
-85, -83, -81, -79, -76, -73, -70, -67, -63, -60, -56, -52, -48, -44, -39, -35,
-30, -25, -21, -16, -11, -6, -1, 4, 9, 14, 19, 25, 30, 35, 40, 45, 49, 54, 58,
62, 66, 69, 72, 75, 77, 79, 80, 81, 82, 82, 82, 82, 81, 79, 78, 76, 74, 71, 68,
65, 62, 59, 55, 52, 48, 44, 40, 36, 32, 27, 23, 18, 14, 9, 4, 0, -5, -10, -15,
-20, -25, -30, -35, -41, -46, -51, -55, -60, -64, -68, -72, -76, -79, -81, -84,
-86, -88, -89, -90, -90, -90, -89, -89, -87, -86, -84, -81, -79, -76, -72, -69,
-65, -61, -57, -53, -48, -43, -38, -33, -28, -23, -17, -11, -5, 0, 6, 12, 19,
25, 31, 38, 44, 51, 57, 63, 69, 74, 80, 85, 89, 94, 98, 101, 104, 107, 109, 110,
111, 112, 112, 111, 110, 109, 107, 104, 101, 98, 95, 91, 86, 82, 77, 72, 66, 61,
55, 49, 43, 37, 30, 24, 17, 11, 4, -2, -9, -15, -22, -29, -36, -43, -50, -56,
-62, -68, -74, -80, -85, -89, -93, -97, -100, -103, -106, -107, -109, -110,
-110, -110, -109, -108, -107, -105, -102, -100, -97, -93, -89, -85, -81, -77,
-72, -67, -62, -56, -51, -45, -39, -34, -28, -22, -16, -9, -3, 2, 8, 14, 21, 27,
33, 40, 46, 52, 58, 63, 68, 73, 78, 82, 86, 90, 93, 96, 98, 99, 101, 102, 102,
102, 101, 100, 99, 97, 95, 93, 90, 87, 84, 80, 76, 72, 68, 64, 59, 54, 49, 44,
39, 34, 29, 23, 17, 12, 6, 0, -5, -11, -17, -22, -28, -34, -39, -45, -50, -55,
-60, -65, -70, -74, -78, -81, -84, -87, -89, -91, -93, -94, -95, -95, -95, -95,
-94, -92, -91, -89, -87, -84, -81, -78, -75, -71, -67, -63, -59, -55, -50, -46,
-41, -36, -31, -25, -20, -15, -9, -4, 0, 6, 11, 17, 22, 27, 33, 38, 43, 47, 52,
57, 61, 65, 69, 73, 76, 79, 82, 84, 86, 87, 88, 89, 89, 89, 89, 88, 87, 85, 83,
81, 79, 76, 73, 70, 67, 63, 59, 55, 51, 47, 43, 38, 34, 29, 24, 19, 14, 9, 4, 0,
-5, -10, -15, -20, -24, -29, -34, -39, -43, -48, -52, -56, -60, -64, -67, -70,
-73, -76, -78, -80, -81, -82, -83, -84, -84, -84, -83, -82, -81, -80, -78, -76,
-73, -71, -68, -65, -62, -58, -54, -51, -47, -42, -38, -34, -29, -25, -20, -16,
-11, -6, -1, 2, 7, 12, 16, 21, 26, 30, 34, 39, 43, 47, 50, 54, 57, 61, 64, 66,
69, 71, 73, 75, 76, 77, 78, 78, 78, 78, 77, 76, 75, 74, 72, 70, 68, 65, 63, 60,
57, 53, 50, 47, 43, 39, 35, 31, 27, 23, 19, 15, 10, 6, 1, -2, -6, -11, -15, -20,
-24, -28, -32, -36, -40, -44, -47, -51, -54, -57, -60, -63, -65, -67, -69, -70,
-71, -72, -73, -73, -73, -73, -72, -71, -70, -69, -68, -66, -64, -62, -60, -57,
-54, -51, -48, -45, -42, -38, -34, -31, -27, -23, -19, -15, -11, -6, -2, 1, 5,
10, 14, 18, 22, 26, 30, 34, 38, 41, 45, 48, 52, 54, 57, 60, 62, 64, 65, 67, 68,
69, 69, 70, 70, 70, 69, 68, 67, 66, 64, 63, 61, 58, 56, 54, 51, 48, 45, 42, 39,
36, 32, 29, 25, 21, 18, 14, 10, 6, 2, -1, -5, -9, -13, -17, -20, -24, -28, -31,
-34, -38, -41, -44, -46, -49, -52, -54, -56, -58, -60, -61, -62, -63, -64, -64,
-65, -65, -64, -64, -63, -62, -61, -60, -58, -56, -54, -52, -50, -47, -45, -42,
-39, -36, -33, -30, -26, -23, -19, -16, -12, -8, -5, -1, 2, 6, 9, 13, 17, 20,
24, 27, 30, 34, 37, 40, 43, 45, 48, 50, 52, 54, 56, 57, 59, 60, 61, 61, 62, 62,
62, 61, 61, 60, 59, 58, 57, 55, 53, 51, 49, 47, 44, 42, 39, 36, 33, 30, 27, 23,
20, 16, 13, 10, 6, 3, 0, -3, -7, -10, -13, -17, -20, -23, -26, -29, -32, -35,
-37, -40, -42, -44, -47, -48, -50, -52, -53, -54, -55, -56, -56, -57, -57, -57,
-57, -56, -56, -55, -54, -53, -51, -50, -48, -46, -44, -42, -40, -37, -35, -32,
-29, -26, -23, -20, -17, -13, -10, -7, -4, 0, 2, 5, 8, 12, 15, 18, 21, 24, 26,
29, 32, 34, 37, 39, 41, 43, 45, 47, 49, 50, 51, 52, 53, 53, 54, 54, 54, 54, 53,
53, 52, 51, 50, 49, 47, 46, 44, 42, 40, 38, 35, 33, 30, 28, 25, 22, 19, 16, 13,
10, 7, 4, 1, -1, -4, -8, -11, -14, -17, -20, -23, -25, -28, -31, -33, -36, -38,
-40, -42, -43, -45, -46, -47, -48, -49, -50, -50, -51, -51, -51, -51, -50, -50,
-49, -48, -47, -46, -45, -43, -42, -40, -38, -36, -34, -31, -29, -27, -24, -21,
-19, -16, -13, -10, -7, -4, -1, 0, 3, 6, 9, 12, 15, 18, 21, 23, 26, 29, 31, 34,
36, 38, 40, 42, 43, 45, 46, 47, 48, 48, 49, 49, 49, 49, 49, 48, 48, 47, 46, 45,
44, 43, 41, 40, 38, 36, 34, 32, 30, 28, 25, 23, 20, 18, 15, 13, 10, 7, 5, 2, 0,
-3, -6, -8, -11, -14, -16, -19, -21, -24, -26, -28, -30, -32, -34, -36, -38,
-39, -41, -42, -44, -45, -45, -46, -47, -47, -47, -47, -47, -46, -46, -45, -44,
-43, -42, -41, -39, -38, -36, -34, -32, -30, -28, -26, -23, -21, -18, -16, -13,
-11, -8, -6, -3, 0, 2, 4, 7, 10, 12, 15, 18, 20, 22, 25, 27, 29, 31, 33, 35, 37,
38, 40, 41, 42, 43, 44, 44, 45, 45, 45, 45, 44, 44, 43, 42, 41, 40, 39, 38, 36,
35, 33, 32, 30, 28, 26, 24, 22, 19, 17, 15, 12, 10, 7, 5, 3, 0, -1, -4, -6, -9,
-11, -13, -15, -18, -20, -22, -24, -25, -27, -29, -31, -32, -34, -35, -36, -37,
-38, -39, -40, -40, -41, -41, -41, -40, -40, -40, -39, -39, -38, -37, -36, -34,
-33, -32, -30, -29, -27, -25, -24, -22, -20, -18, -15, -13, -11, -9, -7, -5, -3,
0, 1, 3, 5, 7, 10, 12, 14, 16, 18, 20, 22, 23, 25, 27, 29, 30, 32, 33, 34, 35,
36, 37, 38, 38, 39, 39, 39, 39, 38, 38, 37, 37, 36, 35, 34, 33, 32, 31, 29, 28,
26, 24, 23, 21, 19, 17, 15, 13, 11, 9, 6, 4, 2, 0, -2, -4, -6, -8, -10, -13,
-15, -17, -19, -20, -22, -24, -26, -27, -29, -30, -31, -32, -33, -34, -34, -35,
-35, -35, -35, -35, -35, -35, -35, -35, -34, -33, -33, -32, -31, -30, -29, -27,
-26, -25, -23, -21, -20, -18, -16, -14, -12, -10, -8, -6, -5, -3, -1, 0, 2, 4,
6, 8, 10, 12, 14, 15, 17, 19, 20, 22, 23, 25, 26, 27, 28, 29, 30, 31, 32, 32,
33, 33, 32, 33, 33, 34, 33, 33, 32, 32, 31, 30, 29, 28, 27, 26, 24, 23, 21, 20,
18, 16, 15, 13, 11, 9, 7, 5, 3, 1, 0, -2, -4, -5, -7, -9, -11, -13, -14, -16,
-17, -19, -20, -22, -23, -24, -25, -26, -27, -28, -29, -30, -30, -31, -31, -31,
-31, -31, -31, -31, -31, -30, -29, -29, -28, -27, -26, -25, -24, -23, -22, -20,
-19, -18, -16, -15, -13, -11, -10, -8, -6, -4, -3, -1, 0, 1, 3, 5, 6, 8, 10, 11,
13, 14, 16, 17, 19, 20, 21, 22, 23, 24, 25, 26, 26, 27, 28, 28, 28, 29, 29, 29,
29, 29, 29, 29, 28, 28, 27, 26, 26, 25, 24, 23, 22, 21, 19, 18, 16, 15, 13, 12,
10, 8, 7, 5, 3, 1, 0, -1, -3, -4, -6, -7, -9, -11, -12, -13, -15, -16, -18, -19,
-20, -21, -22, -23, -24, -25, -26, -27, -27, -28, -28, -28, -28, -28, -28, -28,
-28, -27, -27, -26, -26, -25, -24, -23, -22, -21, -20, -19, -17, -16, -15, -13,
-12, -10, -9, -7, -5, -4, -2, 0, 0, 2, 3, 5, 7, 8, 10, 11, 12, 14, 15, 16, 17,
18, 19, 20, 21, 22, 23, 24, 24, 25, 25, 25, 26, 26, 26, 26, 26, 25, 25, 25, 24,
24, 23, 22, 22, 21, 20, 19, 18, 17, 16, 14, 13, 12, 10, 9, 8, 6, 5, 3, 2, 0, 0,
-1, -3, -4, -6, -7, -8, -10, -11, -12, -13, -15, -16, -17, -18, -19, -20, -21,
-21, -22, -22, -23, -23, -24, -24, -24, -24, -24, -24, -24, -24, -24, -23, -23,
-22, -22, -21, -20, -19, -18, -17, -16, -15, -14, -13, -12, -10, -9, -8, -6, -5,
-3, -2, 0, 0, 2, 3, 5, 6, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 19, 20, 21,
21, 22, 22, 23, 23, 23, 23, 23, 23, 22, 22, 22, 21, 21, 20, 20, 19, 18, 18, 17,
16, 15, 14, 13, 12, 11, 10, 9, 8, 6, 5, 4, 3, 1, 0, 0, -2, -3, -4, -5, -7, -8,
-9, -10, -11, -13, -14, -14, -15, -16, -17, -17, -18, -19, -19, -19, -20, -20,
-20, -21, -21, -21, -21, -21, -21, -20, -20, -20, -19, -19, -18, -17, -17, -16,
-15, -14, -14, -13, -12, -11, -10, -8, -7, -6, -5, -4, -3, -1, 0, 0, 1, 3, 4, 5,
6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 16, 17, 17, 18, 18, 19, 19, 19, 19, 20,
20, 20, 20, 19, 19, 19, 19, 18, 18, 17, 17, 16, 15, 15, 14, 13, 12, 11, 10, 9,
8, 7, 6, 5, 4, 2, 1, 0, 0, -1, -2, -3, -4, -5, -7, -8, -9, -10, -11, -12, -13,
-14, -14, -15, -16, -16, -17, -17, -18, -18, -18, -19, -19, -19, -19, -19, -19,
-18, -18, -18, -18, -17, -17, -16, -15, -15, -14, -13, -12, -11, -11, -10, -9,
-8, -7, -6, -5, -4, -3, -2, -1, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
13, 14, 15, 15, 16, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 17, 17, 17, 16,
16, 15, 15, 14, 13, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, -1, -2, -3,
-4, -5, -6, -6, -7, -8, -9, -10, -10, -11, -12, -12, -13, -13, -14, -14, -15,
-15, -15, -16, -16, -16, -16, -16, -16, -16, -16, -16, -15, -15, -15, -14, -14,
-13, -13, -12, -12, -11, -11, -10, -9, -8, -8, -7, -6, -5, -4, -3, -2, -1, 0, 0,
1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 10, 10, 11, 11, 12, 13, 13, 14, 14, 14, 15, 15,
15, 15, 15, 15, 15, 15, 15, 14, 14, 14, 14, 13, 13, 12, 12, 11, 11, 10, 10, 9,
8, 8, 7, 6, 5, 5, 4, 3, 2, 1, 0, 0, 0, -1, -2, -3, -4, -5, -5, -6, -7, -8, -8,
-9, -10, -10, -11, -11, -12, -12, -13, -13, -13, -13, -13, -14, -14, -14, -14,
-14, -14, -14, -13, -13, -13, -13, -12, -12, -11, -11, -10, -10, -9, -9, -8, -7,
-7, -6, -5, -4, -4, -3, -2, -1, 0, 0, 0, 1, 2, 3, 3, 4, 5, 5, 6, 7, 7, 8, 9, 9,
10, 10, 11, 11, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 12,
12, 12, 11, 11, 10, 10, 9, 8, 8, 7, 6, 5, 5, 4, 3, 2, 2, 1, 0, 0, -1, -1, -2,
-3, -4, -5, -5, -6, -7, -7, -8, -8, -9, -9, -10, -10, -11, -11, -11, -12, -12,
-12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -11, -10, -10, -9,
-9, -9, -8, -8, -7, -6, -6, -5, -5, -4, -3, -3, -2, -1, 0, 0, 0, 1, 1, 2, 3, 3,
4, 4, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12,
12, 12, 12, 11, 11, 11, 10, 10, 9, 9, 8, 7, 7, 6, 6, 5, 5, 4, 3, 3, 2, 1, 1, 0,
0, 0, -1, -2, -2, -3, -3, -4, -5, -5, -6, -6, -7, -7, -8, -8, -8, -9, -9, -9,
-9, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -9,
-9, -9, -9, -8, -8, -8, -7, -7, -6, -6, -5, -5, -4, -4, -3, -3, -2, -2, -1, 0,
0, 0, 1, 1, 2, 3, 3, 4, 5, 5, 6, 7, 7, 8, 8, 9, 9, 10, 10, 10, 10, 11, 11, 11,
11, 11, 11, 11, 10, 10, 10, 10, 9, 9, 9, 8, 8, 8, 7, 7, 6, 6, 6, 5, 5, 4, 4, 3,
3, 2, 1, 1, 0, 0, 0, -1, -1, -2, -2, -3, -3, -4, -4, -5, -5, -6, -6, -7, -7, -8,
-8, -8, -9, -9, -9, -9, -10, -10, -10, -10, -10, -10, -10, -9, -9, -9, -9, -9,
-8, -8, -8, -8, -7, -7, -6, -6, -6, -5, -5, -4, -4, -3, -3, -2, -2, -1, 0, 0, 0,
0, 1, 2, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9,
9, 9, 8, 8, 8, 8, 8, 7, 7, 7, 6, 6, 6, 5, 5, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0, 0, 0,
-1, -1, -2, -2, -3, -3, -4, -4, -4, -5, -5, -6, -6, -6, -6, -7, -7, -7, -7, -8,
-8, -8, -8, -8, -8, -8, -8, -7, -7, -7, -7, -7, -7, -7, -6, -6, -6, -6, -5, -5,
-5, -4, -4, -4, -3, -3, -2, -2, -2, -1, -1, 0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4,
4, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 6, 6,
6, 5, 5, 5, 4, 4, 4, 3, 3, 2, 2, 1, 1, 1, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3,
-4, -4, -4, -4, -5, -5, -5, -6, -6, -6, -6, -6, -7, -7, -7, -7, -7, -7, -7, -7,
-7, -7, -7, -7, -7, -7, -6, -6, -6, -5, -5, -4, -4, -4, -3, -3, -2, -2, -2, -1,
-1, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5, 5,
5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 4, 4, 4, 3, 3, 3,
2, 2, 2, 1, 1, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -5, -5,
-5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -5,
-5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -2, -2, -2, -1, -1, -1, 0, 0, 0, 0,
0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
6, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 0,
0, -1, -1, -1, -1, -2, -2, -2, -3, -3, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5,
-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -4, -4, -4, -3,
-3, -3, -3, -2, -2, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3,
3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4,
3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2,
-2, -3, -3, -3, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -5, -4, -4, -4, -4,
-4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -1, -1, -1, -1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4,
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1,
0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -2, -2, -2, -2, -3, -3, -3, -3, -3, -4,
-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -3, -3,
-3, -3, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3,
3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1,
-1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -1, -1, -1,
-1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2,
1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -2, -2, -2, -2, -2,
-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
-3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1,
-1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2,
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2,
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1,
-1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };

#endif /* tommid_H_ */