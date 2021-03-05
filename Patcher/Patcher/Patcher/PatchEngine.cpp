#include <string>
#include <windows.h>
#include "PatchEngine.h"

using std::string;
using EnumFileStatus::FileStatus;

PatchEngine::PatchEngine(void)
{
}

PatchEngine::~PatchEngine(void)
{
}

extern "C" __declspec(dllexport)
PatchEngine* __stdcall CreateClass(void){
	return new PatchEngine();
}

extern "C" __declspec(dllexport)
void __stdcall DisposeClass(PatchEngine* pObject){
	if (pObject != NULL)
	{
		delete pObject;
		pObject = NULL;
	}
}

extern "C" __declspec(dllexport)
void __stdcall CallClearPatch(PatchEngine* pObject){
	pObject->ClearPatch();
}

extern "C" __declspec(dllexport)
FileStatus __stdcall CallPatchFile(const PatchEngine* pObject){
	return pObject->PatchFile();
}

extern "C" __declspec(dllexport)
void __stdcall CallSetFilePath(PatchEngine* pObject, const char* filePath){
	string pPath(filePath);
	pObject->SetFilePath(pPath);
}

extern "C" __declspec(dllexport)
void __stdcall CallSetFileName(PatchEngine* pObject, const char* fileName){
	string fName(fileName);
	pObject->SetFileName(fName);
}

extern "C" __declspec(dllexport)
void __stdcall CallAddNewBytePattern(PatchEngine* pObject, const unsigned char newBytes[], const unsigned char originalBytes[],
						   unsigned int bytePatternSize){
							   pObject->AddNewBytePattern(originalBytes, newBytes, bytePatternSize);
}

void PatchEngine::ClearPatch(void){
	_patchInfo.bytesNew.clear();
	_patchInfo.bytesOriginal.clear();
	_patchInfo.fileNameToPatch = "";
	_patchInfo.filePath = "";
	_patchInfo.patternSize.clear();
}

FileStatus PatchEngine::PatchFile(void) const{
	HANDLE fHandle, sHandle;
	BYTE *mHandle, *current;
	current  = new BYTE;
	DWORD fSize;


	fHandle = CreateFileA((_patchInfo.filePath+_patchInfo.fileNameToPatch).c_str(), GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ, 0, OPEN_EXISTING, 0,0);
	if (fHandle == INVALID_HANDLE_VALUE)
		return EnumFileStatus::OPEN_COULD_NOT_OPEN_FILE;

	sHandle = CreateFileMapping(fHandle, 0, PAGE_READWRITE, 0, 0, 0);
	if (!sHandle)
	{
		CloseHandle(fHandle);
		return EnumFileStatus::OPEN_COULD_NOT_OPEN_FILE;
	}

	mHandle = (BYTE *)MapViewOfFile(sHandle, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if (!mHandle)
	{
		CloseHandle(sHandle);
		CloseHandle(fHandle);
		return EnumFileStatus::OPEN_COULD_NOT_OPEN_FILE;
	}

	fSize = GetFileSize(fHandle, 0);
	FileStatus returnValue;
	for (unsigned int i = 0; i < _patchInfo.bytesOriginal.size(); i++)
	{
		current = mHandle;
		while (current < (mHandle + fSize))
		{
			try //sometimes memcmp will throw an access violation exception
			{
				if (memcmp(current, _patchInfo.bytesOriginal[i], _patchInfo.patternSize[i])==0)
				{
					memcpy(current, _patchInfo.bytesNew[i], _patchInfo.patternSize[i]);
					current+=_patchInfo.patternSize[i];
					returnValue = EnumFileStatus::PATCHED_FILE;
					break;
				}
				else{
					returnValue = EnumFileStatus::OPEN_COULD_NOT_FIND_THE_BYTES;
				}
			}
			catch(...){
				returnValue = EnumFileStatus::OPEN_COULD_NOT_FIND_THE_BYTES;
			}
			current++;
		}
	}

	UnmapViewOfFile((PVOID)mHandle);
	CloseHandle(sHandle);
	CloseHandle(fHandle);

	return returnValue;
}