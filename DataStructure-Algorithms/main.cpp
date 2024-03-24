#include<stdio.h>
#include<string.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100
//스택 생성
typedef struct {
    char symbol;
}element1;

typedef struct {
    element1 stack[MAX_STACK_SIZE];
    int top;
}StackType1;

void init(StackType1 *s){
    s->top = -1;
}

int is_empty(StackType1 *s){
    return s->top == -1;
}
int is_full(StackType1 *s){
    return s->top == MAX_STACK_SIZE - 1;
}
void push(StackType1 *s, element1 item){
    if(!is_full(s)){
        s->stack[++s->top] = item;
    }
    else{
        printf("XXXXX");
    }
}
element1 pop(StackType1 *s){
    if(!is_empty(s)){
        return s->stack[s->top--];
    }
    element1 n;
    n.symbol = '^';
    return n;
}
element1 peek(StackType1 *s){
    if(!is_empty(s)){
        return s->stack[s->top];
    }
    element1 n;
    n.symbol = '^';
    return n;
}

typedef struct{
    double num;
}element2;

typedef struct{
    element2 stack[MAX_STACK_SIZE];
    int top;
}StackType2;

void init(StackType2 *s){
    s->top = -1;
}

int is_empty(StackType2 *s){
    return s->top == -1;
}
int is_full(StackType2 *s){
    return s->top == MAX_STACK_SIZE - 1;
}
void push(StackType2 *s, element2 item){
    if(!is_full(s)){
        s->stack[++s->top] = item;
    }
    else{
        printf("XXXXX");
    }
}
element2 pop(StackType2 *s){
    if(!is_empty(s)){
        return s->stack[s->top--];
    }
    element2 n;
    n.num = -10000000;
    return n;
}
element2 peek(StackType2 *s){
    if(!is_empty(s)){
        return s->stack[s->top];
    }
    element2 n;
    n.num = -10000000;
    return n;
}


//계산기 알고리즘
int prec(char op){
    switch (op) {
        case '(': case ')':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
        default:
            break;
    }
    return -1;
}
bool ValidBrack(char *str){
    StackType1 t;
    element1 d;
    init(&t);
    while(*str != NULL){
        if(*str == '{' || *str == '(' || *str == '[' || *str == '}' || *str == ')' || *str == ']'){
            if(*str == '{' || *str == '(' || *str == '['){//push할 조건
                d.symbol = *str;
                push(&t, d);
            }
            else{//pop할 조건
                char sample = pop(&t).symbol;
                if((*str == ']' && sample == '[') || (*str == '}' && sample == '{') || (*str == ')' && sample == '(')){//pop해서 오류가 안날 경우

                }
                else{//pop해서 오류가 날 경우
                    return false;
                }
            }
        }
        str++;
    }
    if(!is_empty(&t))
        return false;
    else
        return true;
}
bool Converter(char *str, char *postfix){//input=>str, output=>postfix
    StackType1 t;
    element1 d;
    init(&t);//스택 만들었다
    int len = strlen(str);
    int str_index = 0, postfix_index = 0;
    while(len - str_index){
        if(str[str_index] >= 48 && str[str_index] <= 57){//숫자이면 postfix에 집어넣고
            postfix[postfix_index++] = str[str_index];
        }
        else{//str[str_index]가 연산자나 괄호이면 이 동작을 수행한다.
            if(str[str_index] == ')'){//일단 '('이면 ')'까지 pop한다.
                while(peek(&t).symbol != '('){
                    postfix[postfix_index++] = pop(&t).symbol;
                }
                pop(&t);
            }
            else{//')' 가 아니면
                if(str[str_index] == '('){
                    d.symbol = '(';
                    push(&t, d);
                }
                else{
                    while(prec(str[str_index]) <= prec(peek(&t).symbol)){//중위식 <= peek값
                        postfix[postfix_index++] = pop(&t).symbol;
                    }
                    d.symbol = str[str_index];
                    push(&t, d);
                }

            }
        }
        str_index++;
    }
    if(!is_empty(&t)){//남은 스택 전부 pop
        while(!is_empty(&t))
            postfix[postfix_index++] = pop(&t).symbol;
    }
    return true;
}
double Calculate(char *postfix){
    StackType2 t;
    element2 d;
    double one, two;
    init(&t);//스택 만들었다
    int len = strlen(postfix);
    for(int i = 0 ; i < len ; i++){
        if(postfix[i] >= 48 && postfix[i] <= 57){
            d.num = postfix[i]-48;
            push(&t, d);
        }
        else{
            switch (postfix[i]) {
                case '+':
                    two = pop(&t).num;
                    one = pop(&t).num;
                    d.num = one+two;
                    push(&t, d);
                    break;
                case '-':
                    two = pop(&t).num;
                    one = pop(&t).num;
                    d.num = one-two;
                    push(&t, d);
                    break;
                case '*':
                    two = pop(&t).num;
                    one = pop(&t).num;
                    d.num = one*two;
                    push(&t, d);
                    break;
                case '/':
                    two = pop(&t).num;
                    one = pop(&t).num;
                    d.num = one/two;
                    push(&t, d);
                    break;
                default:
                    break;
            }
        }
    }
    return pop(&t).num;
}
int main(){
    char str[101];
    char postfix[101];
    scanf("%[^\n]s",str);
    if(!ValidBrack(str)){
        printf("유효하지 않은 식");
        return 0;
    }
    if(!Converter(str, postfix)){
        printf("유효하지 않은 변환");
        return 0;
    }
    printf("%s\n", postfix);
    printf("%lf", Calculate(postfix));
}
