#include "global.h"

Global::Global()
{

}
/*
__int64 GetFileSize(LPCTSTR sPath)
{
    HANDLE hFile = ::CreateFile(sPath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        return 0;
    }
    __int64 fileSize = 0;
    ::GetFileSizeEx(hFile, (PLARGE_INTEGER)&fileSize);
    ::CloseHandle(hFile);
    return fileSize;
}
*/
