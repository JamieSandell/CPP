#if !WIN32

namespace EnumFileStatus
{
    public
#elif WIN32
    namespace EnumFileStatus
    {
#endif

        // shared enum for both C++ and C#
enum FileStatus {
        PATCHED_FILE = 0,
        OPEN_COULD_NOT_OPEN_FILE,
        NO_FILE_SELECTED,
        OPEN_COULD_NOT_FIND_THE_BYTES
};

//#if !WIN32
}
//#endif
