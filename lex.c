#include <stdio.h>



int main(void) {
    /*
    Pseudocode for Lexical Analyzer
    Step 1. Initialize keywords, operators, and delimiters
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
    return 0;
}
