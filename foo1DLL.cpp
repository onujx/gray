#include "stdafx.h"

extern "C" int __declspec(dllexport) test(){
      __asm
            {
                  xor eax, eax
                  pop esi
                  pop ebp
                  retn
            }
}