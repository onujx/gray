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
         hFile = fopen(str, "rb");  //바이트를 읽고자 파일을 연다
         if (hFile==NULL) {printf("No such file"); exit(1);} //오류 체크
         //파일 크기 확인
         fseek(hFile, 0, SEEK_END);
         lSize = ftell(hFile);
         rewind (hFile);
         temp = (char*) malloc (sizeof(char)*lSize);
         result = fread(temp,1,lSize,hFile);
         memcpy(buffer, temp, result);  //취약점
         memcpy(out,buffer,strlen(buffer));  // /GS 전에 SHE 트리거
         printf("Input received : %s\n",buffer);
      }
      catch (char * strErr)
      {
            printf("No valid input received ! \n");
            printf("Exception : %s\n",strErr);
      }
      test();  // DLL 호출, XOR, POP, POP, RETN 시퀀스 보이기
}

int main(int argc, char* argv[])
{
      char foo[2048];
    char buf2[500];
    GetInput(argv[1],buf2);
    return 0;
}
