//3
#include<iostream>
#include<queue>

typedef struct{
    int priority;
    int number;
}Priority_Target;

Priority_Target searching(std::queue<Priority_Target> work, int location){
    for(int i = 0 ; i < location ; i++){
        work.pop();
    }
    return work.front();
}
int main(){
    std::queue<Priority_Target> work;
    int num, location, temp;
    int ans = 1;
    printf("문서의 개수 / 몇번째 문서: ");
    scanf("%d %d", &num, &location);
    printf("문서의 중요도: ");
    for(int i = 0 ; i < num ; i++){//중요도 입력
        scanf("%d", &temp);
        Priority_Target obj;
        obj.priority = temp;
        obj.number = i;
        work.push(obj);
    }
    Priority_Target target = searching(work, location);//원하는 문서의 정보
    while(!work.empty()){
        if(work.front().priority < target.priority)
            num--;
        else if(work.front().priority == target.priority){
            if(work.front().number > target.number)
                num--;
        }
        work.pop();
    }
    printf("%d번째 인쇄\n", num);

}
