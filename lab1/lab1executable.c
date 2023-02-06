//Using Lex 
/*the input file for lex is  yyin and defaults to stdin
example that prepends line nos to each line in afile
%{
    int yylineno;
%}
%%
^(.*)\n  printf("4d\t%s", ++yylineno, yytext);
%%
int main(int argc, char *argv[]){
    yyin = fopen(argv[1], "r");
    yylex();
    fclose(yyin);
}
*/ 
/*
the def section is composed of  substitutions, code and start states
code in def sec is copied to the top of the generated C file
must be bracketed inside %{ ,,,,,,, %}
substitution simplify the pattern matching rules 
Example:
We may define digits and letters

digit [0-9]
letter [A-Za-z]

%{
int count;    
%}
%%
/* matching identifiers
{letter} ({letter} | {digit})* count++;
%%
int main(void){
    yylex();
    printf("number of identifiers = %d\n", count);
    return 0;
}

NOTE
whitespaces mus separate the defining term and the associated exp

*/
/*
A scanner that  counts the number of  characters, words and lines in a file
%{
int nchar, nword, nline;
%}
\n   {nline++; nchar++; }
[^ \t\n]+  {nword++, nchar += yyleng; }
.  {nchar++ };
%%
 int main(void){
    yylex();
    printf("%d\t%d\t%d\n", nchar, nword,nline);
    return 0;
 }
*/

//YACC practice
/*
INPUTS are divided to three sections
,,,,definitions,,,,
%%
,,,,rules,,,,
%%
,,,,subroutines,,,,

definitions - consists of token declarations and C code
inside%{,,,,,,%}
rules - BNF grammar placed inside this section
subroutines - user subroutines are added in the section

//creating a claculator that  adds and subtracts numbers
//definition - declares a token integer
//yacc generates a parser in file y.tab.c and an include file
//y.tab.h

%token INTEGER 

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#define INTEGER 258
extern YYSTYPE yyval;

//lex then inludes thos file and utilizes the definitios for token value
//to obtain the tokens, YACC calls yylex return type int
vals associated with token are returned by LEX in variable
yyval

[0-9]+  {
            yyval = atoi(yytext);
            return INTEGER;
        }

this fun will store the value of integer in yyval and return token INTEGER

the type of  yyval is determined by YYSTPE defaults to int

*/

/*download file add into folder lab1
yyleng - counts the length of the matched identifiers
increments the lengths everytime
yylex by default calls yywrap

*/