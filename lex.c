#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    skipsym = 1 , // Skip / ignore token
    identsym , // Identifier
    numbersym , // Number
    plussym , // +
    minussym , // -
    multsym , // *
    slashsym , // /
    eqsym , // =
    neqsym , // <>
    lessym , // <
    leqsym , // <=
    gtrsym , // >
    geqsym , // >=
    lparentsym , // (
    rparentsym , // )
    commasym , // ,
    semicolonsym , // ;
    periodsym , // .
    becomessym , // :=
    beginsym , // begin
    endsym , // end
    ifsym , // if
    fisym , // fi
    thensym , // then
    whilesym , // while
    dosym , // do
    callsym , // call
    constsym , // const
    varsym , // var
    procsym , // procedure
    writesym , // write
    readsym , // read
    elsesym , // else
    evensym // even
} TokenType ;

int main(int argc, char* argv[]) {
    /*
    Pseudocode for Lexical Analyzer
    Step 1. Initialize keywords, operators, and delimiters
    Step 2. Read the source code file
        a. Skip comments
            i. Skip single-line comments (//)
            ii. Skip multi-line comments (/*)
        b. Skip whitespace
            i. Spaces
            ii. Tabs
            iii. Newlines
    Step 3. Tokenize the source code's keywords, operators, and delimiters
    Step 4. Identify and classify tokens
    Step 5. Handle errors
        a. Identifier too long (> 11 chars) Error
        b. Number too long (> 5 digits) Error
        c. Invalid Symbol Error
    Step 6. Output the tokens
        Step 6.1. Print Lexeme Table to console
        Step 6.2. Print Token List to console
    Step 7. Terminate
    */
    FILE *inputFile = fopen(argv[1], "r");

    // Check if input file opened successfully
    if (!inputFile) {
        printf("Error opening file.\n");
        return 1;
    }

    char info[100];
    int i = 0;
    int j = 0;

    // Print header

    printf("Source Program:\n");

    // Print input file contents
    while (fgets(info, sizeof(info), inputFile)) {
        printf("%s", info);
    }

    fseek(inputFile, 0, SEEK_SET);

    // Print Lexeme Table header

    printf("\nLexeme Table:\n");
    printf("\nlexeme\ttoken type\n");

    // Scan input file character by character excluding whitespace
    while ((j = fgetc(inputFile)) != EOF && i < sizeof(info) - 1) {
        if ((char) j == ' ' || (char) j == '\t' || (char) j == '\n') {
            continue; // Skip whitespace
            i++;
        }
        info[i++] = (char) j;
    }

    info[i] = '\0'; // Null-terminate the string

    char lexemes[100][20]; // Assuming max 100 lexemes, each up to 19 chars + null terminator
    char tokens[100];
    int t = 0;
    char message[20];
    for (int k=0; k<i; k++) {
        switch (info[k]) {
            case '+':
                tokens[t] = plussym;
                strcpy(lexemes[t], "+");
                t++;
                break;
            case '-':
                tokens[t] = minussym;
                strcpy(lexemes[t], "-");
                t++;
                break;
            case '*':
                tokens[t] = multsym;
                strcpy(lexemes[t], "*");
                t++;
                break;
            case '/':
                tokens[t] = slashsym;
                strcpy(lexemes[t], "/");
                t++;
                break;
            case '<':
                switch (info[k+1]) {
                    case '=':
                        tokens[t] = leqsym;
                        strcpy(lexemes[t], "<=");
                        t++;
                        k++; // Skip the next character as it's part of the token
                        break;
                    case '>':
                        tokens[t] = neqsym;
                        strcpy(lexemes[t], "<>");
                        t++;
                        k++; // Skip the next character as it's part of the token
                        break;
                    default:
                        tokens[t] = lessym;
                        strcpy(lexemes[t], "<");
                        t++;
                        break;
                }
                break;
            case '>':
                if (info[k+1] == '=') {
                    tokens[t] = geqsym;
                    strcpy(lexemes[t], ">=");
                    t++;
                    k++; // Skip the next character as it's part of the token
                } else {
                    tokens[t] = gtrsym;
                    strcpy(lexemes[t], ">");
                    t++;
                }
                break;
            case '(':
                tokens[t] = lparentsym;
                strcpy(lexemes[t], "(");
                t++;
                break;
            case ')':
                tokens[t] = rparentsym;
                strcpy(lexemes[t], ")");
                t++;
                break;
            case ',':
                tokens[t] = commasym;
                strcpy(lexemes[t], ",");
                t++;
                break;
            case ';':
                tokens[t] = semicolonsym;
                strcpy(lexemes[t], ";");
                t++;
                break;
            case '.':
                tokens[t] = periodsym;
                strcpy(lexemes[t], ".");
                t++;
                break;
            case ':':
                if (info[k+1] == '=') {
                    tokens[t] = becomessym;
                    strcpy(lexemes[t], ":=");
                    t++;
                    k++; // Skip the next character as it's part of the token
                } else {
                    tokens[t] = skipsym;
                    strcpy(lexemes[t], ":");
                    strcpy(message, "Invalid symbol");
                    t++;

                }
                break;
            case '=':
                tokens[t] = eqsym;
                strcpy(lexemes[t], "=");
                t++;
                break;
            case 'b':
                if (info[k+1] == 'e' && info[k+2] == 'g' && info[k+3] == 'i' && info[k+4] == 'n') {
                    tokens[t] = beginsym;
                    strcpy(lexemes[t], "begin");
                    t++;
                    k += 4; // Skip the next characters as they're part of the token
                } else {
                    tokens[t] = identsym; // Assume it's an identifier
                    strcpy(lexemes[t], "b");
                    t++;
                }
                break;
            case 'e':
                if (info[k+1] == 'n' && info[k+2] == 'd') {
                    tokens[t] = endsym;
                    strcpy(lexemes[t], "end");
                    t++;
                    k += 2; // Skip the next characters as they're part of the token
                } else if (info[k+1] == 'l' && info[k+2] == 's' && info[k+3] == 'e') {
                    tokens[t] = elsesym;
                    strcpy(lexemes[t], "else");
                    t++;
                    k += 3; // Skip the next characters as they're part of the token
                } else if (info[k+1] == 'v' && info[k+2] == 'e' && info[k+3] == 'n') {
                    tokens[t] = evensym;
                    strcpy(lexemes[t], "even");
                    t++;
                    k += 3; // Skip the next characters as they're part of the token
                } else {
                    tokens[t] = identsym; // Assume it's an identifier
                    strcpy(lexemes[t], "e");
                    t++;
                }
                break;
            case 'i':
                if (info[k+1] == 'f') {
                    tokens[t] = ifsym;
                    strcpy(lexemes[t], "if");
                    t++;
                    k += 1; // Skip the next character as it's part of the token
                } else {
                    tokens[t] = identsym; // Assume it's an identifier
                    strcpy(lexemes[t], "i");
                    t++;
                }
                break;
            case 'f':
                if (info[k+1] == 'i') {
                    tokens[t] = fisym;
                    strcpy(lexemes[t], "fi");
                    t++;
                    k += 1; // Skip the next character as it's part of the token
                } else {
                    tokens[t] = identsym; // Assume it's an identifier
                    strcpy(lexemes[t], "f");
                    t++;
                }
                break;
            case 't':
                if (info[k+1] == 'h' && info[k+2] == 'e' && info[k+3] == 'n') {
                    tokens[t] = thensym;
                    strcpy(lexemes[t], "then");
                    t++;
                    k += 3; // Skip the next characters as they're part of the token
                } else {
                    tokens[t] = identsym; // Assume it's an identifier
                    strcpy(lexemes[t], "t");
                    t++;
                }
                break;
            case 'w':
                if (info[k+1] == 'h' && info[k+2] == 'i' && info[k+3] == 'l' && info[k+4] == 'e') {
                    tokens[t] = whilesym;
                    strcpy(lexemes[t], "while");
                    t++;
                    k += 4; // Skip the next characters as they're part of the token
                } else if (info[k+1] == 'r' && info[k+2] == 'i' && info[k+3] == 't' && info[k+4] == 'e') {
                    tokens[t] = writesym;
                    strcpy(lexemes[t], "write");
                    t++;
                    k += 4; // Skip the next characters as they're part of the token
                } else {
                    tokens[t] = identsym; // Assume it's an identifier
                    strcpy(lexemes[t], "w");
                    t++;
                }
                break;
            case 'd':
                if (info[k+1] == 'o') {
                    tokens[t] = dosym;
                    strcpy(lexemes[t], "do");
                    t++;
                    k += 1; // Skip the next character as it's part of the token
                } else {
                    tokens[t] = identsym; // Assume it's an identifier
                    strcpy(lexemes[t], "d");
                    t++;
                }
                break;
            case 'c':
                if (info[k+1] == 'a' && info[k+2] == 'l' && info[k+3] == 'l') {
                    tokens[t] = callsym;
                    strcpy(lexemes[t], "call");
                    t++;
                    k += 3; // Skip the next characters as they're part of the token
                } else if (info[k+1] == 'o' && info[k+2] == 'n' && info[k+3] == 's' && info[k+4] == 't') {
                    tokens[t] = constsym;
                    strcpy(lexemes[t], "const");
                    t++;
                    k += 4; // Skip the next characters as they're part of the token
                } else {
                    tokens[t] = identsym; // Assume it's an identifier
                    strcpy(lexemes[t], "c");
                    t++;
                }
                break;
            case 'v':
                if (info[k+1] == 'a' && info[k+2] == 'r') {
                    tokens[t] = varsym;
                    strcpy(lexemes[t], "var");
                    t++;
                    k += 2; // Skip the next characters as they're part of the token
                } else {
                    tokens[t] = identsym; // Assume it's an identifier
                    strcpy(lexemes[t], "v");
                    t++;
                }
                break;
            case 'p':
                if (info[k+1] == 'r' && info[k+2] == 'o' && info[k+3] == 'c' && info[k+4] == 'e' && info[k+5] == 'd' && info[k+6] == 'u' && info[k+7] == 'r' && info[k+8] == 'e') {
                    tokens[t] = procsym;
                    strcpy(lexemes[t], "procedure");
                    t++;
                    k += 8; // Skip the next characters as they're part of the token
                } else {
                    tokens[t] = identsym; // Assume it's an identifier
                    strcpy(lexemes[t], "p");
                    t++;
                }
                break;
            case 'r':
                if (info[k+1] == 'e' && info[k+2] == 'a' && info[k+3] == 'd') {
                    tokens[t] = readsym;
                    strcpy(lexemes[t], "read");
                    t++;
                    k += 3; // Skip the next characters as they're part of the token
                } else {
                    tokens[t] = identsym; // Assume it's an identifier
                    strcpy(lexemes[t], "r");
                    t++;
                }
                break;
            default:
                if (isdigit(info[k])) {
                    int start = k;
                    int len = 0;
                    while (isdigit(info[k]) && len < 6) { // Max 5 digits
                        strncat(lexemes[t], &info[k], 1);
                        k++;
                        len++;
                    }
                    strncpy(lexemes[t], &info[start], len);
                    lexemes[t][len] = '\0'; // Null-terminate the string
                    if (len > 5) {
                        strcpy(message, "Number too long");
                        tokens[t] = skipsym;
                        t++;
                    }   else {
                        tokens[t] = numbersym;
                        t++;
                    }
                    k--; // Adjust for the outer loop increment
                } else if (isalpha(info[k])) {
                    int start = k;
                    int len = 0;
                    while (isalnum(info[k]) && len < 12) { // Max 5 digits
                        strncat(lexemes[t], &info[k], len);
                        k++;
                        len++;
                    }
                    strncpy(lexemes[t], &info[start], len);
                    lexemes[t][len] = '\0'; // Null-terminate the string
                    if (len > 11) {
                        strcpy(message, "Identifier too long");
                        tokens[t] = skipsym;
                        t++;
                    }   else {
                        tokens[t] = identsym;
                        t++;
                    }
                } else {
                    strcpy(lexemes[t], &info[k]);
                    strcpy(message, "Invalid symbols");
                    lexemes[t][1] = '\0';
                    tokens[t] = skipsym;
                    t++;
                }
                break;
        }
        
        if (tokens[t-1] == skipsym) {
            printf("%-7s %-10s\n", lexemes[t-1], message);
        } else {
            // Print lexeme and token type
            printf("%-7s %-10d\n", lexemes[t-1], tokens[t-1]);
        }
    }

    printf("\nToken List:\n\n");

    for (int l = 0; l < t; l++) {
        printf("%d ", tokens[l]);
        if (tokens[l] == 2 || tokens[l] == 3) {
            printf("%s ", lexemes[l]);
        }
    }

    fclose(inputFile);

    return 0;
}
