/**
 * @file double.hpp
 * @author iijima-robot
 * @brief Doubleクラスを宣言するヘッダファイル
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef COMMON_DATAOBJECT_DOUBLE_H
#define COMMON_DATAOBJECT_DOUBLE_H

#include <dataObject/arithmetic.hpp>

namespace dataObject
{
    /// @brief double型に相当するクラス
    class Double : public ArithmeticObject<double>
    {
    public:
        /// @brief Doubleクラスのコンストラクタ
        /// @details 引数なしの場合、データは0となる。
        Double();
        Double(const NoneType &data);
        Double(const double &data);
        template <class T>
        Double(const  ArithmeticObject<T> &data):ArithmeticObject<double>(data.getData()) {}
        /// @brief Doubleクラスのデコンストラクタ
        ~Double();
        const char *getType() const;
        /**
         * @brief 本クラスをdouble型へ自動変換する関数
         * 
         * @return [double] 本クラスが保持するデータ 
         */
        operator double() const { return _data; }
    };
}

#endif