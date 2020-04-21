#define MAX_ARGS 3
#define CMD_ARG_PARAMETER 1
#define CMD_ARG_FILE_PATH 2
#define PARAMETER_INDICATOR '-'
#define LINE_PARAMETER 'l' 
#define CHAR_PARAMETER 'c' 
#define WORD_PARAMETER 'w'
#define ALL_PARAMETER 'a'
#define HELP_PARAMETER 'h'

#define MSG_OK "OK."
#define MSG_ERR_NULL_POINTER "Null Pointer."
#define MSG_ERR_INVALID_PARAMETER "Invalid parameter."
#define MSG_ERR_INVALID_NUM_OF_ARGS "Invalid number of arguments."
#define MSG_ERR_READING_FILE "Unable to open file."
#define MSG_ERR_CLOSING_FILE "Unable to close file."
#define MSG_HELP_CALL "The program must be called as follows: ./count -<parameter> -<relative file path>"
