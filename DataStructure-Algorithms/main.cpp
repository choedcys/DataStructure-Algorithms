#include<iostream>
#include<stack>

int main(){
    std::stack<int> enQ;
    std::stack<int> DQ;
    int cursor = 0;
    while(cursor != 4){
        printf("1. 인큐\n2. 디큐\n3. 피크\n4. 종료\n==>");
        scanf("%d", &cursor);
        if(cursor == 1){
            int data;
            scanf("%d", &data);
            enQ.push(data);
        }
        else if(cursor == 2){
            if(DQ.empty()){
                printf("DQ큐 비어있음\n");
                while(!enQ.empty()){
                    DQ.push(enQ.top());
                    enQ.pop();
                }
            }
            printf("%d\n", DQ.top());
            DQ.pop();
        }
        else if(cursor == 3){
            printf("%d ", DQ.top());
        }
        else if(cursor == 4){
            break;
        }
    }
}
