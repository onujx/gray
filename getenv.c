#include <stdlib.h>
int main(int argc, char *argv[]){
  char * addr;			// bss ���ǿ� �Է��� �����ϱ� ���� ������ ���ڿ� 
  addr = getenv(argv[1]);	// �Է����� addr ���� �ʱ�ȭ
  printf("%s is located at %p\n", argv[1], addr);// ��ġ ǥ��
}
