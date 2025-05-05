/*
P -> program D_1;B$;
D_1 -> var D{,D}
D -> I{,I}:[int|bool]
B -> begin S {;S} end
S -> I:= E | if E then S else S | while E do S | B | read(I) | write(E)
E -> E_1 [= | < | > | !=]E_1 | E_1
E_1 -> T{[+ | - | or]T]}
T -> F{* | / | and]F}
F -> I | N | L | not F | (E)
L ->  true | false
I -> C | IC | IR
N -> R | NR
C -> a | b | ... | z | A | B | ... | Z
R -> 0 | 1 | 2 | ... | 9
*/

enum type_of_lex
{
    LEX_NULL,//0,无效或空的词法单元
    LEX_AND,LEX_BEGIN,...LEX_WRITE,//18，关键字
    LEX_FIN,//19，程序结束标记
    LEX_SEMICOLON,LEX_COMMA,...LEX_GEQ,//35，符号
    LEX_NUM,//36，数字
    LEX_ID,//37，标识符
    POLIZ_LABEL,//38，波兰表达式中的标签（跳转目标）
    POLIZ_ADDRESS,//39，波兰表达式中的内存地址，或符号表中的位置索引
    POLIZ_GO,//40，波兰表达式的无条件跳转
    POLIZ_FGO//41，波兰表达式的有条件跳转（false go）
};

class Lex
{
    type_of_lex t_lex;
    int v_lex;
};

class Ident{

};

class tabl_ident
{

};

class Scanner
{

};

char * Scanner::TW[] = {

};

char * Scanner::TD[] = {

};

tabl_ident TID(100);

type_of_lex Scanner::words[] =
{

};

type_of_lex Scanner::dlms[]=
{

};
