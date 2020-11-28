#include<stdio.h>

int main(){
  
  int a;
  
  scanf("%d",&a);
    
  a = a % 1000;
  
  if(a == 0){
    printf("%d",0);
  
  }else{
    printf("%d",1000 - a);
    
  }
  
  return 0;
}
