//5
#include<iostream>
#include<queue>

int main(){
    std::queue<int>Q;
    int num, interval;
    int count = 0;
    printf("총인원 간격 : ");
    scanf("%d %d", &num, &interval);
    for(int i = 1 ; i <= num ; i++){
        Q.push(i);
    }
    printf("<");
    while(1){
        if(Q.size() == 1){
            printf("%d", Q.front());
            break;
        }
        if(interval != 1){
            if(count != 0 && count%interval == interval-1){
                printf("%d, ", Q.front());
                Q.pop();
            }
            else{
                int temp = Q.front();
                Q.pop();
                Q.push(temp);
            }
        }
        else{
            printf("%d, ",Q.front());
            Q.pop();
        }
        count++;
    }
    printf(">");
}
