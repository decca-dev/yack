#include "../include/yackstring.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// Get ASCII code of character
int ys_charCode(char ch)
{
  // Store the converted character in a 5 byte buffer
  char buffer[3];
  // Store the formatted ascii code in buffer
  sprintf(buffer, "%d", ch);
  // Convert buffer to int
  int code = atoi(buffer);
  // Flush stdin cuz' C is just like that :D
  fflush(stdin);
  return code;
}

// Check if character is an alphanumeric
bool ys_isAlpha(char ch)
{
  if ((ys_charCode(ch) >= ASCII_a && ys_charCode(ch) <= ASCII_z) ||
      (ys_charCode(ch) >= ASCII_A && ys_charCode(ch) <= ASCII_Z) ||
      TRUE == ys_isCharNumber(ch))
    return TRUE;
  return FALSE;
}

// Check if character is a number
bool ys_isCharNumber(char ch)
{
  if (ys_charCode(ch) >= ASCII_0 && ys_charCode(ch) <= ASCII_9)
    return TRUE;
  return FALSE;
}

// Check if string is a number
bool ys_isStrNumber(char *string)
{
  for (int i = 0; i < (int)strlen(string); i++)
  {
    if (TRUE == ys_isCharNumber(string[i]))
      continue;
    else
    {
      break;
      return FALSE;
    }
  }
  return TRUE;
}

// Convert character to integer
int ys_ctoi(char ch)
{
  // Check if the character is an actual number
  if (0 == ys_isCharNumber(ch))
    return ch - '0';
  return FALSE;
}

// Get a section of a string
char *ys_slice(const char *source, int start, int end)
{
  if (end <= start)
  {
    fprintf(stderr, "YACK > 'end' cannot be less or equal to 'start'.");
    exit(EXIT_FAILURE);
  }
  // Get the length for the ys_sliced string
  int len = end - start;
  char *result = (char *)malloc(sizeof(char) * len);
  for (int i = 0; i < len; i++)
  {
    result[i] = source[start + i];
  };
  // Can't forget the '\0' :>
  result[len] = '\0';
  return result;
}

// Convert string characters to upper case form
char *ys_toUpperCase(const char *string)
{
  int len = strlen(string);
  char *result = (char *)malloc(sizeof(char) * len);
  for (int i = 0; i < len; i++)
  {
    // Only convert to upper case if the character is lower cased
    if (ys_charCode(string[i]) >= ASCII_a && ys_charCode(string[i]) <= ASCII_z)
      result[i] = string[i] - LUD;
    else
      result[i] = string[i];
  }
  result[len] = '\0';
  return result;
}

// Convert string characters to lower case form
char *ys_toLowerCase(const char *string)
{
  int len = strlen(string);
  char *result = (char *)malloc(sizeof(char) * len);
  for (int i = 0; i < len; i++)
  {
    // Only convert to lower case if the character is upper cased
    if (ys_charCode(string[i]) >= ASCII_A && ys_charCode(string[i]) <= ASCII_Z)
      result[i] = string[i] + LUD;
    else
      result[i] = string[i];
  }
  result[len] = '\0';
  return result;
}

// Get the index of the occurrence of the query string in the source
int ys_find(const char *source, const char *query)
{
  char *occurrence = strstr(source, query);
  // Query doesn't exist in source
  if (NULL == occurrence)
  {
    return FALSE;
  }
  // Return the index
  return occurrence - source;
}

// Check if given string ends with a specific string
bool ys_endsWith(const char *string, const char *query)
{
  int string_len = strlen(string), query_len = strlen(query);
  if (string_len <= query_len)
  {
    fprintf(stderr, "YACKSTRING > Cannot execute ys_endsWith on a string smaller than the query string!");
    exit(EXIT_FAILURE);
  }
  // Compare the ys_sliced source string to the query;
  int comp = strcmp(ys_slice(string, string_len - query_len, string_len), query);
  if (0 == comp)
    return TRUE;
  else
    return FALSE;
}

// Check if given string starts with a specific string
bool ys_startsWith(const char *string, const char *query)
{
  int string_len = strlen(string), query_len = strlen(query);
  if (string_len <= query_len)
  {
    fprintf(stderr, "YACKSTRING > Cannot execute ys_startsWith on a string smaller than the query string!");
    exit(EXIT_FAILURE);
  }
  // Compare the ys_sliced source string to the query;
  int comp = strcmp(ys_slice(string, 0, query_len - 1), query);
  if (0 == comp)
    return TRUE;
  else
    return FALSE;
}

// ys_reverse given string
char *ys_reverse(const char *string)
{
  int string_len = strlen(string);
  char *result = (char *)malloc(sizeof(char) * string_len + 1);
  for (int i = 0; i < string_len; i++)
  {
    result[i] = string[string_len - (i + 1)];
  }
  result[string_len] = '\0';
  return result;
}

// Remove whitespace and tabs and other stuff at the start of the string
char *ys_trimStart(char *string)
{
  while (isspace(*string))
    string++;
  return string;
}

// Remove whitespace and tabs and other stuff at the end of the string
char *ys_trimEnd(char *string)
{
  return ys_reverse(ys_trimStart(ys_reverse(string)));
}

// Remove whitespace and tabs and other stuff from string
char *ys_trim(char *string)
{
  return ys_trimEnd(ys_trimStart(string));
}

// ys_repeat string
char *ys_repeat(const char *string, int count)
{
  if (count <= 0)
  {
    return "";
  }
  int len = strlen(string) * count + 1;
  char *result = (char *)malloc(sizeof(char) * len);
  strcpy(result, string);
  for (int i = 1; i < count; i++)
  {
    strcat(result, string);
  }
  result[len] = '\0';
  return result;
}

// Pad string from start
char *ys_padStart(char *string, int maxLength, char *fill)
{
  // If the string is longer than the maxLength, return the original string
  if (maxLength <= (int)strlen(string))
  {
    return string;
  }
  int fill_len = strlen(fill);
  char *result = (char *)malloc(sizeof(char) * maxLength);
  int to_append = maxLength - strlen(string);
  /*
   * If the string to fill with is 1 character, ys_repeat that character
   * If the string to fill with is longer or equal to the appending length, append the fill string characters respectively
   * If the string to fill with is small, append the characters and ys_repeat some of them or all of them
   */
  for (int i = 0; i < to_append; i++)
  {
    result[i] = fill_len == 1 ? *fill : fill_len >= to_append ? fill[i]
                                                              : fill[i % fill_len];
  }
  // Add the original string at the end
  strcat(result, string);
  result[maxLength] = '\0';
  return result;
}

// Pad string from end
char *ys_padEnd(char *string, int maxLength, char *fill)
{
  // If the string is longer than the maxLength, return the original string
  if (maxLength <= (int)strlen(string))
  {
    return string;
  }
  int fill_len = strlen(fill);
  char *result = (char *)malloc(sizeof(char) * maxLength);
  int to_append = maxLength - strlen(string);
  // Add the original string at the start
  strcpy(result, string);
  /*
   * If the string to fill with is 1 character, ys_repeat that character
   * If the string to fill with is longer or equal to the appending length, append the fill string characters respectively
   * If the string to fill with is small, append the characters and repeat some of them or all of them
   */
  for (int i = 0; i < to_append; i++)
  {
    result[(int)strlen(string) + i] = fill_len == 1 ? *fill : fill_len >= to_append ? fill[i]
                                                                                    : fill[i % fill_len];
  }
  result[maxLength] = '\0';
  return result;
}

// Replace portion of string with another string
char *ys_replace(char *source, const char *toReplace, const char *replaceWith)
{
  if (0 == strcmp(toReplace, replaceWith) || FALSE == ys_find(source, toReplace))
  {
    return source;
  }
  int len = strlen(source) - (strlen(toReplace) - strlen(replaceWith)) + 1;
  printf("len: %d\n", len);
  char *result = (char *)malloc(sizeof(char) * len);
  int append_position = ys_find(source, toReplace);
  strcpy(result, "");
  for (int i = 0; i < len; i++)
  {
    if (i == append_position)
    {
      strcat(result, replaceWith);
    }
    else
    {
    }
    printf("%c\n", result[i]);
  }
  result[len] = '\0';
  return result;
}