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

#include <dataObject/core.hpp>

namespace dataObject
{
    /**
     * @brief double型に相当するクラス
     * 
     */
    class Double : public None
    {
    private:
        double _data;

        void _init();

    public:
        /**
         * @brief Doubleクラスのコンストラクタ
         * 
         */
        Double();
        /**
         * @brief Doubleクラスのコンストラクタ
         * @param data 代入するdouble型
         * 
         */
        Double(const double &data);
        /**
         * @brief Doubleクラスのデコンストラクタ
         * 
         */
        ~Double();
        /**
         * @brief 本クラスをdouble型へ明示的に変換する関数
         * 
         * @return [double] 本クラスが保持するデータ 
         */
        double getDouble() const;
        const char *getLog() const;
        int getSize() const;
        const char *getType() const;
        /**
         * @brief 本クラスをdouble型へ自動変換する関数
         * 
         * @return [double] 本クラスが保持するデータ 
         */
        operator double() const { return _data; }
        /**
         * @brief Doubleクラスの代入演算子(=)
         * @param data double型もしくはDouble型を代入可能
         * 
         * @return 本クラスに代入した結果を出力。
         */
        Double operator=(const double &data);
        Double operator=(const Double &data);
        /**
         * @brief Doubleクラスの比較演算子(==)
         * @param data double型もしくはDouble型を比較可能
         * @return 値が等しければtrueを出力。
         */
        bool operator==(const double &data) const;
        bool operator==(const Double &data) const;
        /**
         * @brief Doubleクラスの比較演算子(!=)
         * @param data double型もしくはDouble型を比較可能
         * @return 値が異なればtrueを出力。
         */
        bool operator!=(const double &data) const;
        bool operator!=(const Double &data) const;
        /**
         * @brief Doubleクラスの比較演算子(<)
         * @param data double型もしくはDouble型を比較可能
         * @return 比較した値のほうが大きければtrueを出力。
         */
        bool operator<(const double &data) const;
        bool operator<(const Double &data) const;
        /**
         * @brief Doubleクラスの比較演算子(<=)
         * @param data double型もしくはDouble型を比較可能
         * @return 比較した値のほうが大きい、もしくは等しければtrueを出力。
         */
        bool operator<=(const double &data) const;
        bool operator<=(const Double &data) const;
        /**
         * @brief Doubleクラスの比較演算子(>)
         * @param data double型もしくはDouble型を比較可能
         * @return 比較した値のほうが小さければtrueを出力。
         */
        bool operator>(const double &data) const;
        bool operator>(const Double &data) const;
        /**
         * @brief Doubleクラスの比較演算子(>=)
         * @param data double型もしくはDouble型を比較可能
         * @return 比較した値のほうが小さい、もしくは等しければtrueを出力。
         */
        bool operator>=(const double &data) const;
        bool operator>=(const Double &data) const;
        /**
         * @brief Doubleクラスの複合代入演算子(+=)
         * @param data double型もしくはDouble型を代入可能
         * @return 引数の値だけ加える。
         */
        Double &operator+=(const double &data);
        Double &operator+=(const Double &data);
        /**
         * @brief Doubleクラスの複合代入演算子(-=)
         * @param data double型もしくはDouble型を代入可能
         * @return 引数の値だけ減らす。
         */
        Double &operator-=(const double &data);
        Double &operator-=(const Double &data);
        /**
         * @brief Doubleクラスの複合代入演算子(*=)
         * @param data double型もしくはDouble型を代入可能
         * @return 引数の値だけかける。
         */
        Double &operator*=(const double &data);
        Double &operator*=(const Double &data);
        /**
         * @brief Doubleクラスの複合代入演算子(/=)
         * @param data double型もしくはDouble型を代入可能
         * @return 引数の値だけ割る。
         */
        Double &operator/=(const double &data);
        Double &operator/=(const Double &data);
        /**
         * @brief Doubleクラスのインクリメント演算子
         * @return 1.0増やす。
         */
        Double operator++();
        Double operator++(int);
        /**
         * @brief Doubleクラスのデクリメント演算子
         * @return 1.0減らす。
         */
        Double operator--();
        Double operator--(int);
    };
}

#endif