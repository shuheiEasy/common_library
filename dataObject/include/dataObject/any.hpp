/**
 * @file dataObject.hpp
 * @author iijima-robot
 * @brief Anyクラスを宣言するヘッダファイル
 * @date 2022-09-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef COMMON_DATAOBJECT_ANY_H
#define COMMON_DATAOBJECT_ANY_H

#include <dataObject/dataObject.hpp>

namespace dataObject
{
    /// @brief 任意の型を取れるクラス
    /// @details dataObject型を入力する。
    class Any : public DataObject
    {
    private:
        DataObject *_data;
        String _type;

    public:
        Any();
        template <class T>
        Any(const T &data, typename std::enable_if<std::is_base_of<DataObject, T>::value>::type * = nullptr)
        {
            _data = new T(data);
            _type = _data->getType();
        }
        ~Any()
        {
            if (_type != "")
            {
                delete _data;
            }
        }
        template <class T>
        T *getData()
        {
            return (T *)_data;
        }
        const char *getLog() const { return _data->getLog(); }
        int getSize() const { return _data->getSize(); }
         const char *getType() const { return _type.getChar(); }
    };
}

#endif