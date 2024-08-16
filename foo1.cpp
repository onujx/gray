#include "stdafx.h"
#include "stdio.h"
#include "windows.h"

extern "C" __declspec(dllimport)void test();

void GetInput(char* str, char* out)
{
    long lSize;
    char buffer[500];
      char * temp;
      FILE * hFile;
    size_t result;
    try {
         hFile = fopen(str, "rb");  //����Ʈ�� �а��� ������ ����
         if (hFile==NULL) {printf("No such file"); exit(1);} //���� üũ
         //���� ũ�� Ȯ��
         fseek(hFile, 0, SEEK_END);
         lSize = ftell(hFile);
         rewind (hFile);
         temp = (char*) malloc (sizeof(char)*lSize);
         result = fread(temp,1,lSize,hFile);
         memcpy(buffer, temp, result);  //�����
         memcpy(out,buffer,strlen(buffer));  // /GS ���� SHE Ʈ����
         printf("Input received : %s\n",buffer);
      }
      catch (char * strErr)
      {
            printf("No valid input received ! \n");
            printf("Exception : %s\n",strErr);
      }
      test();  // DLL ȣ��, XOR, POP, POP, RETN ������ ���̱�
}

int main(int argc, char* argv[])
{
      char foo[2048];
    char buf2[500];
    GetInput(argv[1],buf2);
    return 0;
}
