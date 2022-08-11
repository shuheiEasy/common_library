#include <split.hpp>

std::vector<std::string> string_tool::text_spliter(std::string text, char moji)
{
    // 宣言
    std::vector<std::string> ret;
    std::string buffer;

    for (int i = 0; i < text.size(); i++)
    {
        char t = text[i];
        if (t == moji)
        {
            if(!buffer.empty()){
                ret.push_back(buffer);
                buffer.clear();
            }
        }else{
            buffer.push_back(t);
        }
    }
    
    if(!buffer.empty()){
        ret.push_back(buffer);
        buffer.clear();
    }

    return ret;
}