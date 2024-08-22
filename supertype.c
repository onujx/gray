#include <windows.h>
#include <stdio.h>

main() {
      HANDLE hFile;
      char inBuffer[1000];
      int nBytesToRead = 999;
      int nBytesRead = 0;

      hFile = CreateFile(TEXT("C:\\temp\\secret.txt"),	// 열 파일
                  FILE_READ_DATA,						// 접근 마스크
                  FILE_SHARE_READ,						// 읽기 공유
                  NULL,									// 기본 보안
                  OPEN_EXISTING,						// 존재하는 파일만
                  FILE_ATTRIBUTE_NORMAL,				// 보통 파일
                  NULL);								// 속성 템플릿 없음

      if (hFile == INVALID_HANDLE_VALUE)
      {
            printf("Could not open file (error %d)\n", GetLastError());
            return 0;
      }

      ReadFile(hFile, inBuffer, nBytesToRead, (LPDWORD)&nBytesRead, NULL);

      printf("Contents: %s",inBuffer);
}
