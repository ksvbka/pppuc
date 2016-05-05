class Token
{
public:
    char kind;
    double value;
};



Token get_token(); // Read and evaluate an Expression
double expression(); // Deal with + and -
double term(); // Deal with * / %
double primary(); // Deal with number and parentheses

// Expression implement;
/*First try*/
double expression(){
    double left = expression(); // Read and evaluate an Expression
    Token t = get_token(); // Get next token;
    switch(i.kind){
        case '+':
            return left + term(); // Read and evaluate a term then add
        case '-':
            return left - term();
        default:
            return left;
    }
}
/* Analysis:
        Almost a trivial transcription the grammar.
        This function will loop forever because the programmer cannot peek ahead
        to see if + or - is comming => alway call expression.
 => second try:
        Note: Every Term is Expression but not every expression is term.
        => We will start looking for a Term and look for a full Expression only
        if we found a + or -.
*/

double expression(){
    double left = term();
    Token t = get_token();
    switch(t.kind){
        case "+":
            return left + expression();
        case "-":
            return left - expression();
        default:
            return left;
    }
}
/*
    Analysis:
        Can work with + but when use for - (requre sequence) => failt
        eg: 1 - 2 - 3, the program will parse 1 - (2 - 3).
*/

/* Third try */
double expression(){
    double lef = term();
    Token t = get_token();
    while(t.kind == '+' || t.kind == '-'){
        if(t.kind == '+')
            left += term();
        else
            left -= term();
        t = get_token();
    }
    return left;
}
/* Analysis: check + and - twice => use flag for remove repetitive */

double expression(){
    double left = term();
    Token t = get_token();
    while(true){
        switch(t.kind){
            case '+':
                left += term();
                t = get_token();
                break;
            case '-':
                left -= term();
                t = get_token();
                break;
            default:
                return left;
        }
    }
}
/*-------------------------------------------
 *  TERM
 *-------------------------------------------
 */

 double term(){
    double left = primary();
    Token t = get_token();
    while(true){
        switch(t.kind){
            case '*':
                left *= primary();
                t = get_token();
                break;
            case '-':
            {/*must use {} becase if you want to initialize variable inside switch
                you must place them inside a block */
                double d = primary();
                if(d == 0) error("Device by rezo");
                left /= d;
                t = get_token();
                break;
            }
            /* Remove % because it require check input is a int*/
            // case '%':
            //     left %= primary();
            //     t = get_token();
            //     break;
            default:
                return left;
        }
    }
 }

/*-------------------------------------------
 *  Primary
 *      Number
 *      '(' Expression ')'
 *-------------------------------------------
 */
doube primary(){
    Token t = get_token();
    switch(t.kind){
        case '(':
        {
            double = expression();
            t = get_token();
            if(t.kind != ')') error("'') expected");
            return d;
        }
        case '8':
            return t.value;
        default:
            error("primary expected");
    }
}

/*-------------------------------------------
    Main function
 *-------------------------------------------
 */

 /* First try */

 int main(int argc, char const *argv[])
 {
     try{
        while(cin)
            cout << expression() << endl;
     } catch(exception &e){
        cout << e.what() << endl;
        return 1;
     } catch (...){
        cout << "Exception " << endl;
        return 2;
     }
     return 0;
 }

