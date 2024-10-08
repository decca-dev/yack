#ifndef YACKSTRING_H
#define YACKSTRING_H

#define TRUE 1
#define FALSE 0

#define ASCII_a 97
#define ASCII_b 98
#define ASCII_c 99
#define ASCII_d 100
#define ASCII_e 101
#define ASCII_f 102
#define ASCII_g 103
#define ASCII_h 104
#define ASCII_i 105
#define ASCII_j 106
#define ASCII_k 107
#define ASCII_l 108
#define ASCII_m 109
#define ASCII_n 110
#define ASCII_o 111
#define ASCII_p 112
#define ASCII_q 113
#define ASCII_r 114
#define ASCII_s 115
#define ASCII_t 116
#define ASCII_u 117
#define ASCII_v 118
#define ASCII_w 119
#define ASCII_x 120
#define ASCII_y 121
#define ASCII_z 122

#define ASCII_A 65
#define ASCII_B 66
#define ASCII_C 67
#define ASCII_D 68
#define ASCII_E 69
#define ASCII_F 70
#define ASCII_G 71
#define ASCII_H 72
#define ASCII_I 73
#define ASCII_J 74
#define ASCII_K 75
#define ASCII_L 76
#define ASCII_M 77
#define ASCII_N 78
#define ASCII_O 79
#define ASCII_P 80
#define ASCII_Q 81
#define ASCII_R 82
#define ASCII_S 83
#define ASCII_T 84
#define ASCII_U 85
#define ASCII_V 86
#define ASCII_W 87
#define ASCII_X 88
#define ASCII_Y 89
#define ASCII_Z 90

#define ASCII_0 48
#define ASCII_1 49
#define ASCII_2 50
#define ASCII_3 51
#define ASCII_4 52
#define ASCII_5 53
#define ASCII_6 54
#define ASCII_7 55
#define ASCII_8 56
#define ASCII_9 57

// The difference between lower and upper case ascii characters
#define LUD 32

typedef int bool;

bool ys_isAlpha(char ch);

bool ys_isCharNumber(char ch);

bool ys_isStrNumber(char *string);

int ys_ctoi(char ch);

int ys_charCode(char ch);

char *ys_slice(const char *source, int start, int end);

char *ys_toUpperCase(const char *string);

char *ys_toLowerCase(const char *string);

int ys_find(const char *source, const char *query);

bool ys_endsWith(const char *string, const char *query);

bool ys_startsWith(const char *string, const char *query);

char *ys_reverse(const char *string);

char *ys_trimStart(char *string);

char *ys_trimEnd(char *string);

char *ys_trim(char *string);

char *ys_repeat(const char *string, int count);

char *ys_padStart(char *string, int maxLength, char *fill);

char *ys_padEnd(char *string, int maxLength, char *fill);

char *ys_replace(char *source, const char *toReplace, const char *replaceWith);

#endif