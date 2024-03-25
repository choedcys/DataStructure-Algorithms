#include<iostream>
#include<stack>
//탑을 스택으로 받아서,
typedef struct{
    int num;
    int height;
}Info_Tower;

int available(std::stack<Info_Tower> line){
    int target = line.top().height;
    int res = 0;
    line.pop();
    while(!line.empty()){
        if(line.top().height >= target){
            res = line.top().num;
            break;
        }
        line.pop();
    }
    return res;
}

int main(){
    int num, height;
    Info_Tower temp;
    std::stack<Info_Tower> line;
    printf("탑의 개수 : ");
    scanf("%d", &num);
    for(int i = 0 ; i < num ; i++){
        temp.num = i+1;
        printf("%d 번째 탑의 높이 : ", i+1);
        scanf("%d", &temp.height);
        line.push(temp);
        printf("==>수신가능한 탑 %d번\n",available(line));
    }
}

