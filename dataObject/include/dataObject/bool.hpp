/**
 * @file bool.hpp
 * @author iijima-robot
 * @brief Boolクラスの宣言
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef COMMON_DATAOBJECT_BOOLEAN_H
#define COMMON_DATAOBJECT_BOOLEAN_H

#include <dataObject/string.hpp>

namespace dataObject
{
    /**
     * @brief 真偽値(Bool)クラス
     * @details bool型と互換性をもつクラス。None型の継承クラス。
     *
     */
    class Bool : public None
    {
    private:
        bool _data;

        void _init();
        void _fromInt(const int &data);
        void _fromString(const String &data);

    public:
        /**
         * @brief Boolクラスのコンストラクタ。
         * @details Falseにする。
         */
        Bool();
        /**
         * @brief Boolクラスのコンストラクタ。
         * @details bool型引数の真偽値をコピー。
         */
        Bool(const bool &data);
        /**
         * @brief Boolクラスのコンストラクタ。
         * @details Bool型引数の真偽値をコピー。
         */
        Bool(const Bool &data);
        /**
         * @brief Boolクラスのコンストラクタ。
         * @details 0以下をFalse,1以上をTrueにする。
         */
        Bool(const int &data);
        /**
         * @brief Boolクラスのコンストラクタ。
         * @details"True"が入力された場合はTrueにし、それ以外をFalseにする。
         */
        Bool(const String &data);
        ~Bool();

        /**
         * @brief bool型へ変換する関数
         *
         * @return bool型 Bool型が保持する真偽値
         */
        bool getBool() const;
        const char *getType() const;
        const char *getLog() const;
        int getSize() const;
        /**
         * @brief bool型への自動変換関数
         * 
         * @return Boolクラスの保持する値を出力。
         */
        operator bool() { return _data; };
        /**
         * @brief Boolクラスの比較演算子(==)
         * 
         * @return 値が等しければtrueを出力。
         */
        Bool operator==(const bool &data) const;
        Bool operator==(const Bool &data) const;
        Bool operator==(const int &data) const;
        Bool operator==(const String &data) const;
        /**
         * @brief Boolクラスの比較演算子(!=)
         * 
         * @return 値が異なればtrueを出力。
         */
        Bool operator!=(const bool &data) const;
        Bool operator!=(const Bool &data) const;
        Bool operator!=(const int &data) const;
        Bool operator!=(const String &data) const;
        /**
         * @brief Boolクラスの代入演算子(=)
         * 
         * @return 値が異なればtrueを出力。
         */
        Bool operator=(const bool &data);
        Bool operator=(const Bool &data);
        Bool operator=(const int &data);
        Bool operator=(const String &data);
        /**
         * @brief Boolクラスの算術演算子(+)
         * 
         * @return このクラスの値と足される変数がすべてfalseに相当するときfalseを出力。
         */
        Bool operator+(const bool &data) const;
        Bool operator+(const Bool &data) const;
        Bool operator+(const int &data) const;
        Bool operator+(const String &data) const;
        /**
         * @brief Boolクラスの算術演算子(-)
         * 
         * @return bool同士の引き算と同様。
         */
        Bool operator-(const bool &data) const;
        Bool operator-(const Bool &data) const;
        Bool operator-(const int &data) const;
        Bool operator-(const String &data) const;
        /**
         * @brief Boolクラスの複合代入演算子(+=)
         * 
         * @return 算術演算子(+)を参照。
         */
        Bool &operator+=(const bool &data);
        Bool &operator+=(const Bool &data);
        Bool &operator+=(const int &data);
        Bool &operator+=(const String &data);
    };
}

#endif