# douki
Clang programs for research.

# Table of contents

- 日本語ドキュメント
- Documents in English
- 

# 日本語ドキュメント

## 依存ライブラリ

以下のライブラリがインストールされているか確認してください。

- cmake 3.14
- portaudio (brewでインストール)
- fftw


## インストール

`CMakeLists.txt` と同じディレクトリディレクトリで次のコマンドを実行してください。

生成された実行ファイルは`~/local/bin`にインストールされます。  
`~/local/bin`にパスを通すことを推奨します。

```shell script
mkdir -p ~/local/bin
mkdir -p ~/local/lib
mkdir -p ~/local/include

mkdir build
cd build

cmake ..
make
make install
```

- サブディレクトリで実行すると、そのディレクトリ以下のソースファイルがコンパイルされます。


## インストール (初期設定)

Macの初期設定をするときに実行すると便利です。 

Macの設定を含めて一括で実行できます。

### <重要> 

インストールの前に下記を確認してください。

- githubに登録してください。メールアドレスは個人のもので大丈夫です。
- プロキシとrouterのメディアアクセス制御の設定を行い、googleなどにアクセスできることを確認してください。

### 実行

以下をターミナルで実行してください。

```shell script
sh install.sh
```

# Documents in English

## Requirements

- cmake 3.14
- portaudio
- fftw


## Install

Please run this in the same directory as `CMakeLists.txt`.

Executable files will be installed to `~/local/bin`. You should make a paht to `~/local/bin`.


```shell script
mkdir -p ~/local/bin
mkdir -p ~/local/lib
mkdir -p ~/local/include

mkdir build
cd build

cmake ..
make
make install
```


## Install (First setup)

### **Important**
Before installment, ensure below.

- You must to resister to github. Use your own e-mail address.
- Set up proxy and Media Access Control.

### Run

Please run this
```shell script
sh install.sh
```
``

# Programs included in this repo.

- common
    - FC_deviation
    - FC_deviation_alter
    - IMPmcode
    - LE_1
    - WAVtoDSB_osx
    - biascut
    - cosine_windowing
    - cutout_anyfile
    - cutout_anyfile2
    - douki_new
    - dv
    - equ_schroeder1
    - equ_schroeder2
    - equ_schroeder3
    - equ_schroeder4
    - equ_schroeder5
    - fatchdb
    - fff
    - find_cutpoint
    - henkan
    - imp_add
    - imp_add_by10
    - inverse
    - linear_inpo_hrir_using_ATD
    - mono2LR
    - peaking_filter
    - print_siglen
    - random
    - scaling_max_instant_amp
    - sepach
    - sinwave
    - timeconvo
    - zeropad_anyfile

- fftw
    - fftout2
    - fftout3
    - fftout4
    - make_whitenoise
    
- portaudio
    - 2chplay
    - 2chplay2
    - closed_loop_new
    - monoplay
    - monoplay2
    - monoplay_48k
    - monoplay_8kHz
    - monoplay_alter
    - monorecord
    - playrec_2ch_inPath
    - playrec_2ch_new_kai
    - playrec_mono
    - playrec_mono_inPath

