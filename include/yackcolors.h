#ifndef YACKCOLORS_H
#define YACKCOLORS_H

#define COLOR_RESET "\x1b[0m"
#define COLOR_BRIGHT "\x1b[1m"
#define COLOR_UNDERSCORE "\x1b[4m"
#define COLOR_REVERSE "\x1b[7m"
#define COLOR_HIDDEN "\x1b[8m"
#define COLOR_FGBLACK "\x1b[30m"
#define COLOR_FGRED "\x1b[31m"
#define COLOR_FGGREEN "\x1b[32m"
#define COLOR_FGYELLOW "\x1b[33m"
#define COLOR_FGBLUE "\x1b[34m"
#define COLOR_FGCYAN "\x1b[36m"
#define COLOR_FGWHITE "\x1b[37m"
#define COLOR_BGBLACK "\x1b[40m"
#define COLOR_BGRED "\x1b[41m"
#define COLOR_BGGREEN "\x1b[42m"
#define COLOR_BGYELLOW "\x1b[43m"
#define COLOR_BGBLUE "\x1b[44m"
#define COLOR_BGCYAN "\x1b[46m"
#define COLOR_BGWHITE "\x1b[47m"

enum Color
{
  RESET,
  BRIGHT,
  UNDERSCORE,
  REVERSE,
  HIDDEN,
  FGBLACK,
  FGRED,
  FGGREEN,
  FGYELLOW,
  FGBLUE,
  FGCYAN,
  FGWHITE,
  BGBLACK,
  BGRED,
  BGGREEN,
  BGYELLOW,
  BGBLUE,
  BGCYAN,
  BGWHITE,
};

#endif