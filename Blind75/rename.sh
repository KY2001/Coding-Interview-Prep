#!/bin/bash

# ディレクトリ名を指定
dir=/home/ky2001/Daily-Algorithm/Blind75

# 指定したディレクトリ内の各ファイルに対してループ処理
for oldname in $dir/*; do
    # ファイル名からディレクトリ部分を削除
    file=$(basename "$oldname")

    # ファイル名を3部分に分割（桁番、単語部分、拡張子）
    number=$(echo "$file" | cut -d'_' -f1)
    words=$(echo "$file" | cut -d'_' -f2- | rev | cut -d'.' -f2- | rev)
    ext=$(echo "$file" | rev | cut -d'.' -f1 | rev)

    # 単語部分をUpperCamelCaseに変換
    new_words=$(echo "$words" | tr '_' ' ' | sed -r 's/(^| )(.)/\1\u\2/g' | tr -d ' ')

    # 新しいファイル名を作成
    newname="$dir/$number""_""$new_words.$ext"

    # ファイル名を変更
    mv "$oldname" "$newname"
done
