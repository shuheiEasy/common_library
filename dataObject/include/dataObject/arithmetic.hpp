/**
 * @file int.hpp
 * @author iijima-robot
 * @brief 算術クラスを宣言するヘッダファイル
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef COMMON_ARITHMETIC_CORE_H
#define COMMON_ARITHMETIC_CORE_H

#include <dataObject/core.hpp>

namespace dataObject
{
    template <class T>
    class ArithmeticObject : public DataObject
    {
    protected:
        T _data;

        void _init();

    public:
        const char *getLog() const;
        int getSize() const;
        const char *getType() const;

        ArithmeticObject();
        ArithmeticObject(const NoneType &data);
        ArithmeticObject(const T &data);
        ArithmeticObject(const ArithmeticObject<T> &data);

        /// @brief 格納した値を取得する関数
        /// @return 格納している値
        T getData() const;
        /// @brief 算術クラスの代入演算子(=)
        /// @param data 代入するデータ
        /// @return [ArithmeticObject<T>] 本クラス
        ArithmeticObject<T> operator=(const NoneType &data);
        ArithmeticObject<T> operator=(const T &data);
        ArithmeticObject<T> operator=(const ArithmeticObject<T> &data);
        /// @brief 算術クラスの比較演算子(==)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータと本クラスのデータが等しければtrue
        bool operator==(const NoneType &data) const;
        bool operator==(const T &data) const;
        bool operator==(const ArithmeticObject<T> &data) const;
        /// @brief 算術クラスの比較演算子(!=)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータと本クラスのデータが異なればtrue
        bool operator!=(const NoneType &data) const;
        bool operator!=(const T &data) const;
        bool operator!=(const ArithmeticObject<T> &data) const;
        /// @brief 算術クラスの比較演算子(<)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータが本クラスのデータより大きければtrue
        bool operator<(const NoneType &data) const;
        bool operator<(const T &data) const;
        bool operator<(const ArithmeticObject<T> &data) const;
        /// @brief 算術クラスの比較演算子(<=)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータが本クラスのデータより大きければtrue
        bool operator<=(const NoneType &data) const;
        bool operator<=(const T &data) const;
        bool operator<=(const ArithmeticObject<T> &data) const;
        /// @brief 算術クラスの比較演算子(>)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータが本クラスのデータより大きければtrue
        bool operator>(const NoneType &data) const;
        bool operator>(const T &data) const;
        bool operator>(const ArithmeticObject<T> &data) const;
        /// @brief 算術クラスの比較演算子(>=)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータが本クラスのデータより大きければtrue
        bool operator>=(const NoneType &data) const;
        bool operator>=(const T &data) const;
        bool operator>=(const ArithmeticObject<T> &data) const;
        /// @brief 算術クラスの複合代入演算子(+=)
        /// @param data 加えるデータ
        /// @return [ArithmeticObject<T>] 本クラス
        ArithmeticObject<T> &operator+=(const NoneType &data);
        ArithmeticObject<T> &operator+=(const T &data);
        ArithmeticObject<T> &operator+=(const ArithmeticObject<T> &data);
        /// @brief 算術クラスの複合代入演算子(-=)
        /// @param data 減らすデータ
        /// @return [ArithmeticObject<T>] 本クラス
        ArithmeticObject<T> &operator-=(const NoneType &data);
        ArithmeticObject<T> &operator-=(const T &data);
        ArithmeticObject<T> &operator-=(const ArithmeticObject<T> &data);
        /// @brief 算術クラスの複合代入演算子(*=)
        /// @param data かけられるデータ
        /// @return [ArithmeticObject<T>] 本クラス
        ArithmeticObject<T> &operator*=(const NoneType &data);
        ArithmeticObject<T> &operator*=(const T &data);
        ArithmeticObject<T> &operator*=(const ArithmeticObject<T> &data);
        /// @brief 算術クラスの複合代入演算子(/=)
        /// @param data 割られるデータ
        /// @return [ArithmeticObject<T>] 本クラス
        ArithmeticObject<T> &operator/=(const T &data);
        ArithmeticObject<T> &operator/=(const ArithmeticObject<T> &data);
        /// @brief 算術クラスのインクリメント演算子
        /// @return 1増やす。
        ArithmeticObject<T> operator++();
        ArithmeticObject<T> operator++(int);
        /// @brief 算術クラスのデインクリメント演算子
        /// @return 1減らす。
        ArithmeticObject<T> operator--();
        ArithmeticObject<T> operator--(int);
    };

}
#endif