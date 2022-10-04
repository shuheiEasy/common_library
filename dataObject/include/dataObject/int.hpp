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

#include <dataObject/core.hpp>

namespace dataObject
{
    /// @brief int型に相当するクラス
    class Int : public DataObject
    {
    private:
        int _data;

        void _init();

    public:
        /// @brief コンストラクタ
        /// @details データは0となる。
        Int();
        /// @brief コンストラクタ
        /// @param data 代入するデータ
        Int(const int &data);
        /// @brief デコンストラクタ
        ~Int();
        /// @brief 本クラスをint型へ明示的に変換する関数
        /// @return [int] 本クラスが保持するデータ 
        int getInt() const;
        const char *getLog() const;
        int getSize() const;
        const char *getType() const;
        /// @brief 本クラスをint型へ暗黙的に変換する関数
        /// @return [int] 本クラスが保持するデータ 
        operator int() const { return _data; }
        /// @brief Intクラスの代入演算子(=)
        /// @param data 代入するデータ
        /// @return [Int] 本クラス
        Int operator=(const int &data);
        /// @brief Intクラスの代入演算子(=)
        /// @param data 代入するデータ
        /// @return [Int] 本クラス
        Int operator=(const Int &data);
        /// @brief Intクラスの比較演算子(==)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータと本クラスのデータが等しければtrue
        bool operator==(const int &data) const;
        /// @brief Intクラスの比較演算子(==)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータと本クラスのデータが等しければtrue
        bool operator==(const Int &data) const;
        /// @brief Intクラスの比較演算子(!=)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータと本クラスのデータが異なればtrue
        bool operator!=(const int &data) const;
        /// @brief Intクラスの比較演算子(!=)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータと本クラスのデータが異なればtrue
        bool operator!=(const Int &data) const;
        /// @brief Intクラスの比較演算子(<)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータが本クラスのデータより大きければtrue
        bool operator<(const int &data) const;
        /// @brief Intクラスの比較演算子(<)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータが本クラスのデータより大きければtrue
        bool operator<(const Int &data) const;
        /// @brief Intクラスの比較演算子(<=)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータが本クラスのデータ以上であればtrue
        bool operator<=(const int &data) const;
        /// @brief Intクラスの比較演算子(<=)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータが本クラスのデータ以上であればtrue
        bool operator<=(const Int &data) const;
        /// @brief Intクラスの比較演算子(>)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータが本クラスのデータ未満であればtrue
        bool operator>(const int &data) const;
        /// @brief Intクラスの比較演算子(>)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータが本クラスのデータ未満であればtrue
        bool operator>(const Int &data) const;
        /// @brief Intクラスの比較演算子(>=)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータが本クラスのデータ以下であればtrue
        bool operator>=(const int &data) const;
        /// @brief Intクラスの比較演算子(>=)
        /// @param data 比較するデータ
        /// @return [bool] 比較するデータが本クラスのデータ以下であればtrue
        bool operator>=(const Int &data) const;
        /// @brief Intクラスの複合代入演算子(+=)
        /// @param data 加えるデータ
        /// @return [Int] 本クラス
        Int &operator+=(const int &data);
        /// @brief Intクラスの複合代入演算子(+=)
        /// @param data 加えるデータ
        /// @return [Int] 本クラス
        Int &operator+=(const Int &data);
        /// @brief Intクラスの複合代入演算子(-=)
        /// @param data 減らすデータ
        /// @return [Int] 本クラス
        Int &operator-=(const int &data);
        /// @brief Intクラスの複合代入演算子(-=)
        /// @param data 減らすデータ
        /// @return [Int] 本クラス
        Int &operator-=(const Int &data);
        /// @brief Intクラスの複合代入演算子(*=)
        /// @param data かけられるデータ
        /// @return [Int] 本クラス
        Int &operator*=(const int &data);
        /// @brief Intクラスの複合代入演算子(*=)
        /// @param data かけられるデータ
        /// @return [Int] 本クラス
        Int &operator*=(const Int &data);
        /// @brief Intクラスの複合代入演算子(/=)
        /// @param data 割られるデータ
        /// @return [Int] 本クラス
        Int &operator/=(const int &data);
        /// @brief Intクラスの複合代入演算子(/=)
        /// @param data 割られるデータ
        /// @return [Int] 本クラス
        Int &operator/=(const Int &data);
        /// @brief Intクラスのインクリメント演算子
        /// @return 1増やす。
        Int operator++();
        Int operator++(int);
        /// @brief Intクラスのデインクリメント演算子
        /// @return 1減らす。
        Int operator--();
        Int operator--(int);
    };
}

#endif