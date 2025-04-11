echo "Interpreting your code..."
./compiler/main main.cpp .sonolus
# clang-format .sonolus/main.cpp -style=file > .sonolus/main_formatted.cpp 
echo "Compiling with g++..."
g++ .sonolus/main.cpp -omain -g -w -fpermissive -ljsoncpp -lz -lpng -lzip