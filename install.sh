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


# ------------ build and install c programs ------------#
mkdir -p $HOME/local/bin
mkdir -p $HOME/local/lib
mkdir -p $HOME/local/include

mkdir -p $HOME/research/douki
cd $HOME/research/douki

git clone https://github.com/kudolab/douki_c_programs.git

cd $HOME/research/douki/douki_c_programs
mkdir -p $HOME/research/douki/douki_c_programs/build
cd $HOME/research/douki/douki_c_programs/build

cmake ..
make
make install
# ------------ build and install c programs ------------#


# ------------ make path and configure useful aliases ------------#
echo export PATH=$PATH:$HOME/research/local/bin >> $HOME/.bash_profile

echo alias ls='ls -GC' >> $HOME/.bash_profile
echo alias ll="ls -alF" >> $HOME/.bash_profile
echo alias la='ls -A' >> $HOME/.bash_profile
echo alias l='ls -CF' >> $HOME/.bash_profile
echo alias c='clear' >> $HOME/.bash_profile

echo set completion-ignore-case on > $HOME/.inputrc
# ------------ make path and configure useful aliases ------------#


# ------------ end notification ------------#
cd $HOME
clear

echo \n installation completed!! \n
# ------------ end notification ------------#
