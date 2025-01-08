# CNoCurseWords
CNoCurseWords is a clang plugin that well bans curse word anywhere in the code
any inclustion of curse is most welcome

How to use:
## Clone the repo
`git clone https://github.com/iurjscsi1101500/CNoCurseWords && cd CNoCurseWords`
## Compile the plugin
`make`
## Usage of plugin
`clang -std=c++20 -fplugin="YOUR-REPO-FULL-PATH"/libCNoCurseWords.dylib examples/example.c`
