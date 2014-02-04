#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAX_ROW 5
#define MAX_COL 5

struct point {
  int x, y;
} stack[215];

int top=0;

void push(struct point p){
  stack[top++]=p;
}

struct point pop(){
  return stack[--top];
}

int is_empty(){
  return top==0;
}

int maze[MAX_ROW][MAX_COL] = {
  0, 1, 0, 0, 0,
  0, 1, 0, 1, 0,
  0, 0, 0, 0, 0,
  0, 1, 1, 1, 0,
  0, 0, 0, 1, 0,
};
/* ��¼ÿ���ڵ��ǰ�����ĸ��ڵ㣬�����ĸ��ڵ������˽ڵ�� */
struct point predecessor[MAX_ROW][MAX_COL]={
  {  {-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}  },
  {  {-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}, },
  {  {-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}, },
  {  {-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}, },
  {  {-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}, }
};

void visit(int row,int col,struct point pre){
  struct point cur ={row,col};
  maze[row][col]=2;             /* 2 ��ʾ����ڵ㱻���ʹ� */
  if(!(row==0&&col==0)){        /* 0,0û��ǰ���ڵ㣬�޴Ӽ��� */
    predecessor[row][col]=pre;
  }
  push(cur);
}

void print_maze(){
  int i,j;
  for ( i = 0; i < MAX_ROW; ++i) {
    for ( j = 0; j< MAX_COL; ++j) {
      printf ("%d, ",maze[i][j]);
    }
    printf ("\n");
  }
  printf ("\n");
}
int main(int argc, char *argv[]){
  struct point p={0,0};
  visit(0,0,p);
  /* push(p); */

  while(!is_empty()){
    p=pop();
    printf ("current=%d,%d\n",p.x,p.y);
    if (p.x==MAX_ROW-1&&p.y==MAX_COL-1){
      break;
    }
    if(p.y<MAX_COL-1 && maze[p.x][p.y+1]==0){        /* right */
      visit(p.x,p.y+1,p);
    }
    if(p.x<MAX_ROW-1 && maze[p.x+1][p.y]==0){        /* down */
      visit(p.x+1,p.y,p);
    }
    if(p.y>0 && maze[p.x][p.y-1]==0){        /* left */
      visit(p.x,p.y-1,p);
    }
    if(p.x>0 && maze[p.x-1][p.y]==0){        /* up */
      visit(p.x-1,p.y,p);
    }
    print_maze();
  }
  if (p.x==MAX_ROW-1 && p.y==MAX_COL-1){ /* ����������յ㣬��ӡ��· */
    printf ("%d,%d\n",p.x,p.y);
    while(predecessor[p.x][p.y].x!=-1){
      p=predecessor[p.x][p.y];
      printf ("%d,%d\n",p.x,p.y);
    }
  }
  return 0;
}
