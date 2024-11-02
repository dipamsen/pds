// Reverse Homomorphism
// Problem from Lab Test 2, Autumn 2019 session.
// See LT2-EVEN-A2019.pdf for problem.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LEN 50

typedef struct
{
    char input;
    char *output;
} Rule;

typedef struct
{
    char name;
    Rule *rules;
    int numRules;
} Function;

typedef struct
{
    char name;
    int num;
} FunctionApplication;

typedef struct
{
    int len;
    int top;
    FunctionApplication *arr;
} FAStack;

typedef struct
{
    char *input;
    FAStack stack;
} Query;

Function init_function(char name, int k)
{
    Function f;
    f.name = name;
    f.rules = (Rule *)malloc(k * sizeof(Rule));
    f.numRules = k;
    return f;
}

FAStack init_stack(int m)
{
    FAStack stack;
    stack.len = m;
    stack.top = -1;
    stack.arr = (FunctionApplication *)malloc(m * sizeof(FunctionApplication));
    return stack;
}

void push_stack(FAStack *stack, char name, int num)
{
    FunctionApplication fa = {name, num};
    stack->arr[++stack->top] = fa;
}

FunctionApplication pop_stack(FAStack *stack)
{
    return stack->arr[stack->top--];
}

Function find_function(Function *all, int n, char name)
{
    for (int i = 0; i < n; i++)
        if (all[i].name == name)
            return all[i];
    printf("Function '%c' Does Not Exist! (ERROR)\n", name);
    exit(1);
}

int match_start(char *string, char *pre)
{
    // matches `pre` at the start of `string`
    // returns length of pre if matches
    // returns -1 if it doesn't

    int i = 0;
    while (pre[i] != '\0' && pre[i] == string[i])
        i++;
    if (pre[i] == '\0')
        return i;
    return -1;
}

int main()
{
    int n; // number of functions
    scanf("%d", &n);

    Function *funcs = malloc(n * sizeof(Function)); // array of all function definitions

    for (int i = 0; i < n; i++)
    {
        char c; // function name
        int k;  // number of homomorphisms
        scanf(" %c %d", &c, &k);

        Function f = init_function(c, k);

        for (int j = 0; j < k; j++)
        {
            char h[STR_LEN]; // homomorphism rule
            scanf("%s", h);
            char input = h[0];
            char *output = (char *)malloc(STR_LEN * sizeof(char));
            strcpy(output, h + 3);

            f.rules[j].input = input;
            f.rules[j].output = output;
        }

        funcs[i] = f;
    }

    int q; // number of queries
    scanf("%d", &q);

    // only required to store queries
    // alternative way would be to immediately parse and solve each query as it is read.
    Query *queries = (Query *)malloc(q * sizeof(Query));

    for (int i = 0; i < q; i++)
    {
        int m; // number of elementary functions composited
        scanf("%d", &m);

        FAStack stack = init_stack(m);

        for (int j = 0; j < m; j++)
        {
            char c; // function name
            int p;  // applied number of times
            scanf(" %c %d", &c, &p);

            push_stack(&stack, c, p);
        }
        char *input = (char *)malloc(STR_LEN * sizeof(char)); // input to composite function
        scanf("%s", input);

        queries[i] = (Query){input, stack};
    }

    printf("\n++ Applied Inverse-Homomorphism Results ++\n");

    for (int i = 0; i < q; i++)
    {
        Query curr = queries[i];
        for (int j = 0; j < curr.stack.len; j++) // violating stack access restrictions for printing
        {
            printf("%c^%d ", curr.stack.arr[j].name, curr.stack.arr[j].num);
        }
        printf("(%s) = ", curr.input);

        char *old = (char *)malloc(STR_LEN * sizeof(char));
        strcpy(old, curr.input);
        char *new = (char *)malloc(STR_LEN * sizeof(char));
        while (curr.stack.top >= 0)
        {
            FunctionApplication fa = pop_stack(&curr.stack);
            Function f = find_function(funcs, n, fa.name);
            int num = -fa.num;
            Rule *rules = f.rules;
            for (int a = 0; a < num; a++)
            {
                int match = 0; // index to old
                int p = 0;     // index to new
                while (old[match] != '\0')
                {
                    int found = 0;
                    for (int w = 0; w < f.numRules; w++) // running out of single letter variable names...
                    {
                        int l = match_start(old + match, rules[w].output);
                        if (l > 0)
                        {
                            match += l;
                            new[p++] = rules[w].input;
                            found = 1;
                            break;
                        }
                    }
                    if (!found)
                    {
                        printf("Inverse-Homomorphism for '%s' in Function '%c' is Undefined! (ERROR)\n", old + match, f.name);
                        exit(2);
                    }
                }
                new[p] = '\0';
                free(old);
                old = new;
                new = (char *)malloc(STR_LEN * sizeof(char));
                match = 0;
                p = 0;
            }
        }
        printf("%s\n", old);
    }
}