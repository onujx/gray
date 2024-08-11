#include <stdlib.h>
int main(int argc, char *argv[]){
  char * addr;			// bss 섹션에 입력을 저장하기 위한 간단한 문자열 
  addr = getenv(argv[1]);	// 입력으로 addr 변수 초기화
  printf("%s is located at %p\n", argv[1], addr);// 위치 표시
}
