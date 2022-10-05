/**
 * @file float.hpp
 * @author iijima-robot
 * @brief Floatクラスを宣言するヘッダファイル
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef COMMON_DATAOBJECT_FLOAT_H
#define COMMON_DATAOBJECT_FLOAT_H

#include <dataObject/arithmetic.hpp>

namespace dataObject
{
    /// @brief float型に相当するクラス
    class Float : public ArithmeticObject<float>
    {

    public:
        /**
         * @brief Floatクラスのコンストラクタ
         * 
         */
        Float();
        Float(const NoneType &data);
        Float(const float &data);
        template <class T>
        Float(const ArithmeticObject<T> &data):ArithmeticObject<float>(data.getData()) {}
        /// @brief デコンストラクタ
        ~Float();
        const char *getType() const;
        /**
         * @brief 本クラスをfloat型へ暗黙的に変換する関数
         * 
         * @return [float] 本クラスが保持するデータ 
         */
        operator float() const { return _data; }
    };
}

#endif