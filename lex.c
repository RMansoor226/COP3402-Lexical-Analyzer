#include <stdio.h>

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

    if (!inputFile) {
        printf("Error opening file.\n");
        return 1;
    }

    char info[100];
    int i = 0;
    int j = 0;
    while ((j = fgetc(inputFile)) != EOF && i < sizeof(info) - 1) {
        if ((char) j == ' ' || (char) j == '\t' || (char) j == '\n') {
            continue; // Skip whitespace
            i++;
        }

        info[i++] = (char) j;
    }


    info[i] = '\0'; // Null-terminate the string

    char tokens[100];
    int t = 0;
    for (int k=0; k<i; k++) {
        printf("Index %d: %c \n", k,  info[k]);

        switch (info[k]) {
            case '+':
                tokens[t] = plussym;
                t++;
                break;
            case '-':
                tokens[t] = minussym;
                t++;
                break;
            case '*':
                tokens[t] = multsym;
                t++;
                break;
            case '/':
                tokens[t] = slashsym;
                t++;
                break;
            case '=':
                tokens[t] = eqsym;
                t++;
                break;
            case '<':
                tokens[t] = lessym;
                t++;
                break;
            case '>':
                tokens[t] = gtrsym;
                t++;
                break;
            case '(':
                tokens[t] = lparentsym;
                t++;
                break;
            case ')':
                tokens[t] = rparentsym;
                t++;
                break;
            case ',':
                tokens[t] = commasym;
                t++;
                break;
            case ';':
                tokens[t] = semicolonsym;
                t++;
                break;
            case '.':
                tokens[t] = periodsym;
                t++;
                break;
        }
    }

    fclose(inputFile);

    return 0;
}
