#include <fileSystem.hpp>

using namespace dataObject;
using namespace FileSystem;

File::File()
{
    String buf = "";
    _init(buf);
}
File::File(String &path)
{
    _init(path);
}
File::~File() {}

/////////////////////////////////////////////////
//
// private
//
/////////////////////////////////////////////////

void File::_init(String path)
{
    // 絶対パス取得
    _path=getAbsolutePath(path);
}