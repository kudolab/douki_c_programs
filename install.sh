xcode-select --install
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

brew install cmake
brew install git
brew install fftw
brew install portaudio

mkdir -p $HOME/research/douki
cd $HOME/research/douki

git clone https://github.com/kudolab/douki_c_programs.git

cd douki_c_programs
mkdir -p $HOME/research/douki/douki_c_programs/build
cd $HOME/research/douki/douki_c_programs/build

cmake ..
make

mkdir -p $HOME/bin
mkdir -p $HOME/lib

rsync -av $HOME/research/douki/douki_c_programs/build/* $HOME/bin/ --exclude "CMakeFiles" --exclude "Makefile" --exclude "*.txt" --exclude "*.cmake" --exclude "*.a"
cp $HOME/research/douki/douki_c_programs/build/*.a $HOME/lib

cd $HOME

{ echo alias ll="ls -alF"
alias la='ls -A'
alias l='ls -CF'
export PATH=$PATH:/usr/local/include
} >> $HOME/.bash_profile

echo set completion-ignore-case on > $HOME/.inputrc

clear

echo "\n\n end!! \n\n"
