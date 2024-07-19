#include <stdlib.h>
int main(int argc, char *argv[]){
      static int canary=0;	// canary 값을 .data 섹션에 저장
      char temp[2048];		// 큰 임시 문자열 저장
      strcpy(temp, argv[1]);	// argv1 입력을 받아 temp에 넣기
      printf(temp);		// temp 값 출력
      printf("\n"); 		// 캐리지 리턴 출력
      printf("Canary at 0x%08x = 0x%08x\n", &canary, canary); // canary 출력
}
