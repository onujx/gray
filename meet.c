#include <stdio.h>				// ȭ�� ��¿� �ʿ���
greeting(char *temp1, char *temp2){		// hello�� ����ϴ� greeting �Լ�
	char name[400];				// �̸��� �����ϴ� ���ڿ� ����
	strcpy(name, temp2);			// name�� �Լ� �μ��� ���� 
	printf("Hello %s %s\n", temp1, name);	// ���
}
main(int argc, char * argv[]){			// �μ��� ���� ���� ����
	greeting(argv[1], argv[2]);		// �Լ� ȣ��, ����� �̸� ����
	printf("Bye %s %s\n", argv[1], argv[2]);// "Bye" ���
} // ���α׷� ������
