#include<iostream>
#include<stack>

typedef struct{
    int x, y;
}pos;

char mirror[10][10] = {
    {'1','1','1','1','1','1','1','1','1','1'},
    {'i','0','0','0','1','0','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','0','1'},
    {'1','0','1','1','1','0','0','1','0','1'},
    {'1','0','0','0','1','0','0','1','0','1'},
    {'1','0','1','0','1','0','0','1','0','1'},
    {'1','0','1','0','1','0','0','1','0','1'},
    {'1','0','1','0','1','0','0','1','0','1'},
    {'1','0','1','0','0','0','0','1','0','x'},
    {'1','1','1','1','1','1','1','1','1','1'}
};
//char mirror[6][6] = {
//    {'1', '1', '1', '1', '1', '1'},
//    {'i', '0', '0', '0', '1', '1'},
//    {'1', '1', '0', '1', '1', '1'},
//    {'1', '1', '0', '1', '1', '1'},
//    {'1', '0', '0', '0', '0', 'x'},
//    {'1', '1', '1', '1', '1', '1'}
//};
void mirrorprn(){
    for(int i = 0 ; i < 6 ; i++){
        for(int ii = 0 ; ii < 6 ; ii++){
            printf("%c", mirror[i][ii]);
        }
        printf("\n");
    }
    printf("\n\n");
}
bool ValidPos(int x, int y){//해당 좌표가 유효한 죄표인가
    return ((x>=0 && x<10) && (y>=0 && y<10));
}
pos ret(int x, int y){//시계방향으로 가능한 방향으로 이동하게 만들기
    pos result;
    if(ValidPos(x-1, y) == true && mirror[x-1][y] == 'x'){
        result.x = x-1;
        result.y = y;
    }
    else if(ValidPos(x, y+1) == true && mirror[x][y+1] == 'x'){
        result.x = x;
        result.y = y+1;
    }
    else if(ValidPos(x+1, y) == true && mirror[x+1][y] == 'x'){
        result.x = x+1;
        result.y = y;
    }
    else if(ValidPos(x, y-1) == true && mirror[x][y-1] == 'x'){
        result.x = x;
        result.y = y-1;
    }
    else if(ValidPos(x-1, y) == true && mirror[x-1][y] == '0'){
        result.x = x-1;
        result.y = y;
    }
    else if(ValidPos(x, y+1) == true && mirror[x][y+1] == '0'){
        result.x = x;
        result.y = y+1;
    }
    else if(ValidPos(x+1, y) == true && mirror[x+1][y] == '0'){
        result.x = x+1;
        result.y = y;
    }
    else if(ValidPos(x, y-1) == true && mirror[x][y-1] == '0'){
        result.x = x;
        result.y = y-1;
    }
    else{//이동할 좌표가 없으면(-1,-1)반환
        result.x = -1;
        result.y = -1;
    }
    return result;
}
int main(){
    std::stack<pos> st;
    pos cursor;
    cursor.x = 1;
    cursor.y = 0;
    st.push(cursor);
    while(1){
        //printf("%d %d\n",cursor.x, cursor.x);
        cursor = ret(cursor.x, cursor.y);//시계방향으로 이동. 없으면 cursor가 (-1,-1)
        if(mirror[cursor.x][cursor.y] == 'x'){
            printf("(%d, %d) 출구를 찾았다\n", cursor.x, cursor.y);
            break;
        }
        else{
            if(cursor.x==-1 && cursor.y==-1){//cursor가 (-1,-1)이면,
                if(st.empty()){
                    printf("올바르지 않은 미로\n");
                    break;
                }
                cursor = st.top();//stack에 저장된 최근 저장지점으로 이동
                st.pop();
                printf("pop한다 (%d, %d)\n",cursor.x, cursor.y);
            }
            else{//cursor가 유효한 곳이라면,
                printf("(%d, %d)\n",cursor.x, cursor.y);
                st.push(cursor);//stack에 그 위치를 push
                mirror[cursor.x][cursor.y] = '2';
                mirrorprn();
            }
        }
        //getchar();
    }
}
