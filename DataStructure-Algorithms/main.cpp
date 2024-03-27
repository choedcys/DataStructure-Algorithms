//4
#include<iostream>
#include<queue>

int main(){
    std::queue<int> Q;
    int N;
    int temp;
    scanf("%d", &N);
    for(int i = 1 ; i <= N ; i++){
        Q.push(i);
    }
    for(int i = 0 ; i < N-1 ; i++){
        printf("%d ",Q.front());
        Q.pop();//버리기
        temp = Q.front();//카드를 빼서
        Q.pop();//일단 버리고,
        Q.push(temp);//아래에 있는 카드 밑으로 옮기기
    }
    printf("\n");
    printf("%d", Q.front());
}
