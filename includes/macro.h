/*
** EPITECH PROJECT, 2022
** macro.h
** File description:
** .h file that contains macro
*/

#ifndef MACRO_H_
    #define MACRO_H_

    #define ERROR_ARG 84
    #define ERROR_NO_ENV 84

    #define FAILURE 1
    #define SUCCESS 0

    #define TOO_MANY_ARG "%s: Too many arguments.\n"
    #define MISSING_ARG "%s: Too few arguments.\n"

    #define CD_NOT_DIR "%s: Not a directory.\n"
    #define CD_NOT_FOUND "%s: No such file or directory.\n"

    #define ENV_UNCORRECT_FORMAT "%s: Variable name must contain" \
    " alphanumeric characters.\n"

    #define CMD_NOT_FND "%s: Command not found.\n"

    #define NULL_CMD "Invalid null command.\n"
#endif /* !MACRO_H_ */
