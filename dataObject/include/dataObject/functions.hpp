/**
 * @file dataObject.hpp
 * @author iijima-robot
 * @brief dataObjectライブラリの関数を宣言するヘッダファイル
 * @date 2022-09-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef COMMON_DATAOBJECT_FUNCTIONS_H
#define COMMON_DATAOBJECT_FUNCTIONS_H

#include <dataObject/int.hpp>
#include <dataObject/string.hpp>

namespace dataObject
{
    /**
     * @brief 型クラスの要素数を取得する関数
     * 
     * @param data dataObjectライブラリの型クラス
     * @return [Int] 要素数
     */
    Int len(DataObject &data);
    /**
     * @brief 型名取得関数
     * 
     * @param data dataObjectライブラリの型クラス
     * @return [String] 型名
     */
    String type(DataObject &data);
    /**
     * @brief 環境変数を取得する関数
     * 
     * @param data 環境変数名
     * @return [String] 環境変数の値
     */
    String getEnv(const String &data);
    /**
     * @brief 外部コマンド
     * 
     * @param cmd コマンド名
     * @return [String] 出力結果
     */
    String command(const char* cmd);
}

#endif
