#include <stdio.h>

int main() {
	   int hp = 30;
	   int damage;
	         
	   printf("주인공의 공격력을 입력하세요 : ");
	   scanf("%d", &damage);
	   printf("주인공의 공격력은 %d입니다.",damage);	       
	   hp -= damage;
	   	

	  if (damage < 30) {  // 데미지가 30을 초과하지 않는 경우
			    printf("적의 잔여 HP :%d\n");
			    printf("적이 주인공을 공격하여 주인공이 뒤졌습니다.\n");
			    printf("Game Over");
	  }else{
		            printf("적의 잔여 HP :0\n");
			    printf("적을 물리쳤습니다!\n");
			    printf("Happy End");

		}
					         
          return 0;  
	  }
