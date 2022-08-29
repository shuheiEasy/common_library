#include <fileSystem.hpp>
#include <split.hpp>

using namespace FileSystem;

File::File() {_path="";}
File::File(dataObject::String path) {_path=path;}
File::~File() {}
