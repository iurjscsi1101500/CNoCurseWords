# CNoCurseWords
CNoCurseWords is a clang plugin that well bans curse word anywhere in the code
any inclustion of curse is most welcome

# WARNING: THIS PLUGIN IS CURRENTLY BROKEN AND WE WILL GET IT FIXED AS SOON AS POSSIBLE
# WARNING: THIS PLUGIN CURRENTLY SUPPORTS ONLY MACOS

How to use:
## Clone the repo
`git clone https://github.com/iurjscsi1101500/CNoCurseWords && cd CNoCurseWords`
## Compile the plugin
`make`
## Usage of plugin
`clang -std=c++20 -fplugin="YOUR-REPO-FULL-PATH"/libCNoCurseWords.dylib examples/example.c`
