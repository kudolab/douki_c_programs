# ==================================================================================================================
#  Contents     : Initial setting for research.
#                 This shellscript installs clang programs for common research in Kudo lab.
#                 Please see the README.md for details.
#  Author       : Tetsu Takizawa
#  E-mail       : tt15219@tomakomai.kosen-ac.jp
#  LastUpdate   : 2019/10/27
#  DateCreated  : 2019/10/27
# ==================================================================================================================

# ------------ install xcode and homebrew ------------#
xcode-select --install
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
# ------------ install xcode and homebrew ------------#


# ------------ install dependency libraries ------------#
brew install git
brew install cmake
brew install fftw
brew install portaudio
# ------------ install dependency libraries ------------#


# ------------ build c programs ------------#
mkdir -p $HOME/research/douki
cd $HOME/research/douki

git clone https://github.com/kudolab/douki_c_programs.git

cd douki_c_programs
mkdir -p $HOME/research/douki/douki_c_programs/build
cd $HOME/research/douki/douki_c_programs/build

cmake ..
make
# ------------ build c programs ------------#

mkdir -p $HOME/bin
mkdir -p $HOME/lib
mkdir -p $HOME/include

rsync -av $HOME/research/douki/douki_c_programs/build/* $HOME/bin/ --exclude "CMakeFiles" --exclude "Makefile" --exclude "*.txt" --exclude "*.cmake" --exclude "*.a"
cp $HOME/research/douki/douki_c_programs/build/*.a $HOME/lib

cd $HOME

{ echo alias ll="ls -alF"
alias la='ls -A'
alias l='ls -CF'
export PATH=$PATH:$HOME/bin
} >> $HOME/.bash_profile

echo set completion-ignore-case on > $HOME/.inputrc

clear

echo "\n\n end!! \n\n"
