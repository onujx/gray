#include <windows.h>
#include <stdio.h>

main() {
      HANDLE hFile;
      char inBuffer[1000];
      int nBytesToRead = 999;
      int nBytesRead = 0;

      hFile = CreateFile(TEXT("C:\\temp\\secret.txt"),	// �� ����
                  FILE_READ_DATA,						// ���� ����ũ
                  FILE_SHARE_READ,						// �б� ����
                  NULL,									// �⺻ ����
                  OPEN_EXISTING,						// �����ϴ� ���ϸ�
                  FILE_ATTRIBUTE_NORMAL,				// ���� ����
                  NULL);								// �Ӽ� ���ø� ����

      if (hFile == INVALID_HANDLE_VALUE)
      {
            printf("Could not open file (error %d)\n", GetLastError());
            return 0;
      }

      ReadFile(hFile, inBuffer, nBytesToRead, (LPDWORD)&nBytesRead, NULL);

      printf("Contents: %s",inBuffer);
}
