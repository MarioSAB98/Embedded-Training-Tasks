#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int DebugMode;

typedef struct stackStruct
{
    char* darr;         //pointer to dynamic array
    int allocated;      //amount of space allocated
    int inUse;          //top of stack indicator
} Stack;

void init(Stack* s)
{
    s->allocated = 2;
    s->darr = (char*) malloc (sizeof (char) * s->allocated);
    s->inUse = 0;
}

int isEmpty(Stack* s)
{
    if(s->inUse == 0)
        return TRUE;
    else
        return FALSE;
}

void grow(Stack* s)
{
    if(DebugMode==TRUE)
    {
        printf("\nGrowing stack from size %d to size %d", s->allocated, s->allocated + 2);
        printf("\nValues copied to new array: %d", s->inUse);
    }
    char *temp = s->darr;
    s->darr = (char *) malloc ( (s->allocated + 2) * sizeof(char) );
    int i;
    for ( i = 0 ; i < s->allocated ; i++)
        s->darr[i] = temp[i];
    free (temp);
    s->allocated = s->allocated + 2;
}

void push(Stack* s, char val)
{
    if(DebugMode==TRUE)
        printf("\nPushing %c to stack ", val);

    if(s->inUse >= s->allocated)
        grow(s);

    s->darr[s->inUse] = val;
    s->inUse = s->inUse + 1;
}

char top(Stack* s)
{
    return ( s->darr[s->inUse - 1] );
}

void pop(Stack* s)
{
    if(DebugMode==TRUE)
        printf("\nPopping %c from stack ", top(s));

    s->inUse = s->inUse - 1;
}

void clear(Stack* s)
{
    free(s->darr);
    init(s);
}

int check(Stack* s, char *input, int *index)
{
    char comp = '\0';
    char temp;
    int error = 0;
    int i = 0;

    while(input[i] != '\0')
    {
        comp = input[i];

        //if input is an opening symbol, push it to stack
        if(comp=='(' || comp=='{' || comp=='[' || comp=='<')
            push(s, comp);

            //check if input is a closing symbol
        else if(comp==')' || comp=='}' || comp==']' || comp=='>')
        {
            //if stack is empty, then there's a missing opening symbol (error #2)
            if(isEmpty(s))
            {
                error = 2;
                break;
            }
            temp = top(s);
            //if closing symbol matches opening symbol at top, pop the opening symbol
            if((temp=='(' && comp==')') || (temp=='{' && comp=='}') ||
               (temp=='[' && comp==']') || (temp=='<' && comp=='>'))
            {pop(s);}
            //if closing symbol doesn't match, then a different closing symbol was expected (error #1)
            if(!((temp=='(' && comp==')') || (temp=='{' && comp=='}') ||
                 (temp=='[' && comp==']') || (temp=='<' && comp=='>')))
            {
                error = 1;
                break;
            }
        }
        i++;
    }
    if(error==0 && isEmpty(s)==FALSE)
        error = 3;

    if(error!=0 && index!=NULL)
        *index = i + 1;
    return error;
}

char error1or3(Stack *s)
{
    char hold = ' ';
    char comp = top(s);
    if(comp == '(')
        hold = ')';
    else if(comp == '{')
        hold = '}';
    else if(comp == '[')
        hold = ']';
    else if(comp == '<')
        hold = '>';

    return hold;
}

char error2(Stack *s, char *input, int index){
    char hold = ' ';
    char comp = input[index-1];
    if(comp == ')')
        hold = '(';
    else if(comp == '}')
        hold = '{';
    else if(comp == ']')
        hold = '[';
    else if(comp == '>')
        hold = '<';

    return hold;
}

int main (int argc, char** argv)
{
    Stack s;
    init(&s);
    char input[301];
    DebugMode = FALSE;
    int error;
    int index;
    int i;

    for(i=0; i<argc; i++)
        if(strcmp(argv[i], "-d") == 0) {
            DebugMode = TRUE;
            printf("Debugging Information\n");
        }

    while (1)
    {
        printf ("\nEnter expression to check balance or enter Q to quit\n");
        fgets(input, 300, stdin);

        i = 0;
        while (input[i] != '\n' && input[i] != '\0')
        {
            i++;
        }
        input[i] = '\0';

        if ( (strcmp (input, "q") == 0) || (strcmp (input, "Q") == 0) ) {
            printf ("\nApplication is exiting...\n");
            exit(0);
        }


        error = check(&s, input, &index);
        char hold;

        if(DebugMode==TRUE)
            printf("\n\n%s\n", input);

        if(error == 0)
        {
            printf("Expression is balanced\n");
        }

        else
        {
            int j;
            for(j=1; j<index; j++)
                printf(" ");

            if(error == 1)
            {
                hold = error1or3(&s);
                printf("expecting %c\n", hold);
            }
            else if(error == 2)
            {
                hold = error2(&s, input, index);
                printf("missing %c\n", hold);
            }
            else
            {
                hold = error1or3(&s);
                printf("missing %c\n", hold);
            }
        }
        clear(&s);
    }

    printf ("\nApplication is exiting...\n");
    return 0;
}