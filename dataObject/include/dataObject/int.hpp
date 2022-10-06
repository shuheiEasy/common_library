/**
 * @file int.hpp
 * @author iijima-robot
 * @brief intクラスを宣言するヘッダファイル
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef COMMON_DATAOBJECT_INT_H
#define COMMON_DATAOBJECT_INT_H

#include <dataObject/arithmetic.hpp>

namespace dataObject
{
    /// @brief int型に相当するクラス
    class Int : public ArithmeticObject<int>
    {
    public:
        /// @brief コンストラクタ
        /// @details 引数なしの場合、データは0となる。
        Int();
        /// @brief コンストラクタ
        /// @param data 代入するデータ
        Int(const NoneType &none);
        Int(const int &data);
        template <class T>
        Int(const ArithmeticObject<T> &data):ArithmeticObject<int>(data.getData()) {}
        /// @brief デコンストラクタ
        ~Int();
        const char *getType() const;
        /// @brief 本クラスをint型へ暗黙的に変換する関数
        /// @return [int] 本クラスが保持するデータ
        operator int() const { return _data; }
    };
}

#endif