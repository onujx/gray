#include <stdlib.h>
int main(int argc, char *argv[]){
      static int canary=0;	// canary ���� .data ���ǿ� ����
      char temp[2048];		// ū �ӽ� ���ڿ� ����
      strcpy(temp, argv[1]);	// argv1 �Է��� �޾� temp�� �ֱ�
      printf(temp);		// temp �� ���
      printf("\n"); 		// ĳ���� ���� ���
      printf("Canary at 0x%08x = 0x%08x\n", &canary, canary); // canary ���
}
