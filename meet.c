#include <stdio.h>				// 화면 출력에 필요함
greeting(char *temp1, char *temp2){		// hello를 출력하는 greeting 함수
	char name[400];				// 이름을 저장하는 문자열 변수
	strcpy(name, temp2);			// name에 함수 인수를 복사 
	printf("Hello %s %s\n", temp1, name);	// 출력
}
main(int argc, char * argv[]){			// 인수에 대핸 형식 지정
	greeting(argv[1], argv[2]);		// 함수 호출, 제목과 이름 전달
	printf("Bye %s %s\n", argv[1], argv[2]);// "Bye" 출력
} // 프로그램 나가기
