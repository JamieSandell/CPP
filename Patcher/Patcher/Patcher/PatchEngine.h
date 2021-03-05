#pragma once

#include <string>
#include <vector>
#include "Enums.cs"

class PatchEngine
{
public:
	PatchEngine(void);
	~PatchEngine(void);

	inline void AddNewBytePattern(const unsigned char originalBytes[], const unsigned char newBytes[],
		unsigned int bytePatternSize){
			_patchInfo.bytesOriginal.push_back(originalBytes);
			_patchInfo.bytesNew.push_back(newBytes);
			_patchInfo.patternSize.push_back(bytePatternSize);
	};
	void ClearPatch(void);
	EnumFileStatus::FileStatus PatchFile(void) const;
	inline void SetFilePath(const std::string &filePath){_patchInfo.filePath = filePath;};
	inline void SetFileName(const std::string &fileName){_patchInfo.fileNameToPatch = fileName;};

private:
	struct PatchInfo{
		std::string fileNameToPatch;
		std::string filePath;
		std::vector<const unsigned char*> bytesOriginal;
		std::vector<const unsigned char*> bytesNew;
		std::vector<unsigned int> patternSize;
	};
	PatchInfo _patchInfo;
};
