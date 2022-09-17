/**
 * @file dataObject.hpp
 * @author iijima-robot
 * @brief Floatクラスを宣言するヘッダファイル
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef COMMON_DATAOBJECT_FLOAT_H
#define COMMON_DATAOBJECT_FLOAT_H

#include <dataObject/core.hpp>

namespace dataObject
{
    /**
     * @brief float型に相当するクラス
     * 
     */
    class Float : public None
    {
    private:
        float _data;

        void _init();

    public:
        /**
         * @brief Floatクラスのコンストラクタ
         * 
         */
        Float();
        Float(const float &data);
        /**
         * @brief Floatクラスのデコンストラクタ
         * 
         */
        ~Float();
        /**
         * @brief 本クラスをfloat型へ明示的に変換する関数
         * 
         * @return [float] 本クラスが保持するデータ 
         */
        float getFloat() const;
        const char *getLog() const;
        int getSize() const;
        const char *getType() const;
        /**
         * @brief 本クラスをfloat型へ暗黙的に変換する関数
         * 
         * @return [float] 本クラスが保持するデータ 
         */
        operator float() const { return _data; }
        /**
         * @brief Floatクラスの代入演算子(=)
         * @param data float型を代入可能
         * 
         * @return 本クラスに代入した結果を出力。
         */
        Float operator=(const float &data);
        /**
         * @brief Floatクラスの代入演算子(=)
         * @param data Float型を代入可能
         * 
         * @return 本クラスに代入した結果を出力。
         */
        Float operator=(const Float &data);
        /**
         * @brief Floatクラスの比較演算子(==)
         * @param data float型を比較可能
         * 
         * @return 値が等しければtrueを出力。
         */
        bool operator==(const float &data) const;
        /**
         * @brief Floatクラスの比較演算子(==)
         * @param data Float型を比較可能
         * 
         * @return 値が等しければtrueを出力。
         */
        bool operator==(const Float &data) const;
        /**
         * @brief Floatクラスの比較演算子(==)
         * @param data float型を比較可能
         * 
         * @return 値が異なればtrueを出力。
         */
        bool operator!=(const float &data) const;
        /**
         * @brief Floatクラスの比較演算子(==)
         * @param data Float型を比較可能
         * 
         * @return 値が異なればtrueを出力。
         */
        bool operator!=(const Float &data) const;
        /**
         * @brief Floatクラスの比較演算子(<)
         * @param data float型を比較可能
         * 
         * @return 比較した値のほうが大きければtrueを出力。
         */
        bool operator<(const float &data) const;
        /**
         * @brief Floatクラスの比較演算子(<)
         * @param data Float型を比較可能
         * 
         * @return 比較した値のほうが大きければtrueを出力。
         */
        bool operator<(const Float &data) const;
        /**
         * @brief Floatクラスの比較演算子(<=)
         * @param data float型を比較可能
         * 
         * @return 比較した値のほうが大きければtrueを出力。
         */
        bool operator<=(const float &data) const;
        /**
         * @brief Floatクラスの比較演算子(<=)
         * @param data Float型を比較可能
         * 
         * @return 比較した値のほうが大きければtrueを出力。
         */
        bool operator<=(const Float &data) const;
        /**
         * @brief Floatクラスの比較演算子(>)
         * @param data float型を比較可能
         * @return 比較した値のほうが小さければtrueを出力。
         */
        bool operator>(const float &data) const;
        /**
         * @brief Floatクラスの比較演算子(>)
         * @param data Float型を比較可能
         * @return 比較した値のほうが小さければtrueを出力。
         */
        bool operator>(const Float &data) const;
        /**
         * @brief Floatクラスの比較演算子(>=)
         * @param data float型を比較可能
         * @return 比較した値のほうが小さい、もしくは等しければtrueを出力。
         */
        bool operator>=(const float &data) const;
        /**
         * @brief Floatクラスの比較演算子(>=)
         * @param data Float型を比較可能
         * @return 比較した値のほうが小さい、もしくは等しければtrueを出力。
         */
        bool operator>=(const Float &data) const;
        /**
         * @brief Floatクラスの複合代入演算子(+=)
         * @param data float型を代入可能
         * @return 引数の値だけ加える。
         */
        Float &operator+=(const float &data);
        /**
         * @brief Floatクラスの複合代入演算子(+=)
         * @param data Float型を代入可能
         * @return 引数の値だけ加える。
         */
        Float &operator+=(const Float &data);
        /**
         * @brief Floatクラスの複合代入演算子(-=)
         * @param data float型を代入可能
         * @return 引数の値だけ減らす。
         */
        Float &operator-=(const float &data);
        /**
         * @brief Floatクラスの複合代入演算子(-=)
         * @param data Float型を代入可能
         * @return 引数の値だけ減らす。
         */
        Float &operator-=(const Float &data);
        /**
         * @brief Floatクラスの複合代入演算子(*=)
         * @param data float型を代入可能
         * @return 引数の値だけかける。
         */
        Float &operator*=(const float &data);
        /**
         * @brief Floatクラスの複合代入演算子(*=)
         * @param data Float型を代入可能
         * @return 引数の値だけかける。
         */
        Float &operator*=(const Float &data);
        /**
         * @brief Floatクラスの複合代入演算子(/=)
         * @param data float型を代入可能
         * @return 引数の値だけ割る。
         */
        Float &operator/=(const float &data);
        /**
         * @brief Floatクラスの複合代入演算子(/=)
         * @param data Float型を代入可能
         * @return 引数の値だけ割る。
         */
        Float &operator/=(const Float &data);
        /**
         * @brief Floatクラスのインクリメント演算子
         * @return 1.0増やす。
         */
        Float operator++();
        Float operator++(int);
        /**
         * @brief Floatクラスのデクリメント演算子
         * @return 1.0減らす。
         */
        Float operator--();
        Float operator--(int);
    };
}

#endif